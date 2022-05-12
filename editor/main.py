# Copyright 2022 Emilie Gillet.
#
# Author: Emilie Gillet (emilie.o.gillet@gmail.com)
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# -----------------------------------------------------------------------------
#
# MIDIPal editor app.

# [START gae_python38_app]
# [START gae_python3_app]
from flask import Flask, render_template, request, Response

from sysex import SysExEvent, Nibblize
from midipal_data import Modifier

# If `entrypoint` is not defined in app.yaml, App Engine will look for an app
# called `app` in `main.py`.
app = Flask(__name__)



def midipal_data_to_template_data(modifiers):
  modifiers_dicts = []
  for i, m in enumerate(modifiers):
    d = m.get_template_dict()
    d['index'] = i
    d['index_base_one'] = i + 1
    d['checked'] = 'checked' if m.enabled else ''
    modifiers_dicts.append(d)
  template_data = {
    'title': 'MIDIpal programmer',
    'filters': modifiers_dicts,
    'extra_body_tags': 'onLoad=hideControls();'
  }
  return template_data



MIDIPAL_BLOCK_SIZE = 32
MUTABLE_INSTRUMENTS_MFR_ID = '\x00\x21\x02'
DEVICE_ID = '\x00\x03'
MIDIPAL_BASE_SCRATCH_ADDRESS = 896

def midipal_data_to_syx(modifiers):
  data = ''.join([m.get_bytestream() for m in modifiers])
  syx = []
  for i in range(0, len(data), MIDIPAL_BLOCK_SIZE):
    address = MIDIPAL_BASE_SCRATCH_ADDRESS + i
    block = data[i:i+MIDIPAL_BLOCK_SIZE]
    block += '\x00' * (MIDIPAL_BLOCK_SIZE - len(block))
    block = chr(address & 0xff) + chr(address >> 8) + block
    event = SysExEvent(
        MUTABLE_INSTRUMENTS_MFR_ID,
        DEVICE_ID,
        '\x01\x20' + Nibblize(block))
    syx.append(event.raw_message)
    
  # Add a comment to notify the MIDIpal that the block received in the
  # scratch area has to be copied to the current custom program area.
  event = SysExEvent(
      MUTABLE_INSTRUMENTS_MFR_ID,
      DEVICE_ID,
      '\x73\x00' + Nibblize(''))
  syx.append(event.raw_message)
  return ''.join(syx).encode('latin-1')
  
  

def request_to_midipal_data(args):
  modifiers = []
  for i in range(4):
    m = Modifier()
    prefix = 'filter_%d_' % i
    if args.get(prefix + 'enabled'):
      m.set_from_request(lambda x: args.get(prefix + x))
    modifiers.append(m)
  return modifiers
    


def syx_to_midipal_data(data):
  # Strip 0xf0 and 0xf7
  blocks = [x.strip('\xf7') for x in data.split('\xf0') if x]
  # Strip manufacturer id and 2 command bytes + 4 nibbles of address
  # + 2 nibbles of checksum
  data = ''.join([x[11:-2] for x in blocks])
  # Renibblize
  data = [ord(x) for x in data]
  data = [x * 16 + y for (x, y) in zip(data[::2], data[1::2])]
  modifiers = []
  for i in range(4):
    m = Modifier()
    default_bytestream = m.get_bytestream()
    filter_data, data = data[:16], data[16:]
    m.enabled = ''.join(map(chr, filter_data)) != default_bytestream
    m.from_bytestream(filter_data)
    modifiers.append(m)
  return modifiers



def blank_midipal_data():
  modifiers = [Modifier() for i in range(4)]
  modifiers[0].enabled = True
  return modifiers



@app.route('/', methods=['GET', 'POST'])
def editor():
  modifiers = blank_midipal_data()

  if request.method == 'POST':
    if 'syx' in request.files:
      data = request.files['syx'].stream.read().decode('latin-1')
      modifiers = syx_to_midipal_data(data)
    else:
      # Generate the .syx file from the uploaded data.
      modifiers = request_to_midipal_data(request.form)
      syx = midipal_data_to_syx(modifiers)
      response = Response(syx, mimetype="application/octet-stream")
      response.headers['Content-disposition'] = \
            'attachment; filename=user_program.syx'
      return response
  template_data = midipal_data_to_template_data(modifiers)
  return render_template('index.html', **template_data)



@app.route('/retrieve')
def show_upload_form():
  return render_template('retrieve.html')



if __name__ == '__main__':
  # This is used when running locally only. When deploying to Google App
  # Engine, a webserver process such as Gunicorn will serve the app. You
  # can configure startup instructions by adding `entrypoint` to app.yaml.
  app.run(host='127.0.0.1', port=8080, debug=True)
# [END gae_python3_app]
# [END gae_python38_app]
