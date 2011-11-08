#!/usr/bin/env python
#
# Copyright 2007 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
import cStringIO

from google.appengine.ext import webapp
from google.appengine.ext.webapp import util
from google.appengine.ext.webapp import template

import sysex

TEMPLATE_PATH = os.path.join(os.path.dirname(__file__), 'templates')


class MainHandler(webapp.RequestHandler):

  def get(self):
    self.response.headers['Content-Type'] = 'text/html'
    template_path = os.path.join(TEMPLATE_PATH, 'index.html')

    template_data = {
      'title': 'MIDIpal programmer'
    }
    self.response.out.write(template.render(template_path, template_data))

  def post(self):
    sysex_options = sysex.SysExOptions()
    self.response.headers['Content-Type'] = 'application/octet-stream'
    self.response.headers['Content-disposition'] = \
        'attachment; filename=user_program.syx'
    self.response.out.write(sysex.CreateSysEx('xx', sysex_options))


def main():
  application = webapp.WSGIApplication([('/', MainHandler)], debug=True)
  util.run_wsgi_app(application)


if __name__ == '__main__':
  main()
