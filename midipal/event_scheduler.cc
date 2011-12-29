// Copyright 2011 Olivier Gillet.
//
// Author: Olivier Gillet (ol.gillet@gmail.com)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// -----------------------------------------------------------------------------
//
// Event scheduler.

#include "midipal/event_scheduler.h"

#include <string.h>

namespace midipal {
  
/* static */
uint8_t EventScheduler::size_;

/* static */
SchedulerEntry EventScheduler::entries_[kEventSchedulerSize];

/* static */
uint8_t EventScheduler::root_ptr_;

/* static */
void EventScheduler::Init() {
  memset(entries_, kFreeSlot, kEventSchedulerSize * sizeof(SchedulerEntry));
  root_ptr_ = 0;
  size_ = 0;
}

/* static */
void EventScheduler::Tick() {
  while (!entries_[root_ptr_].when && root_ptr_) {
    entries_[root_ptr_].note = kFreeSlot;
    root_ptr_ = entries_[root_ptr_].next;
    --size_;
  }
  
  uint8_t current = root_ptr_;
  while (current) {
    --entries_[current].when;
    current = entries_[current].next;
  }
}

/* static */
uint8_t EventScheduler::Remove(uint8_t note, uint8_t velocity) {
  uint8_t current = root_ptr_;
  uint8_t found = 0;
  while (current) {
    if (entries_[current].note == note &&
        entries_[current].velocity == velocity) {
          entries_[current].note = kZombieSlot;
      ++found;
    }
    current = entries_[current].next;
  }
  return found;
}

/* static */
void EventScheduler::Schedule(
    uint8_t note,
    uint8_t velocity,
    uint8_t when,
    uint8_t tag) {
  // Locate a free entry in the list.
  uint8_t free_slot = 0;
  for (uint8_t i = 1; i < kEventSchedulerSize; ++i) {
    if (entries_[i].note == kFreeSlot) {
      free_slot = i;
      break;
    }
  }
  
  if (!free_slot) {
    return;  // Queue is full!
  }
  ++size_;
  entries_[free_slot].note = note;
  entries_[free_slot].velocity = velocity;
  entries_[free_slot].when = when;
  entries_[free_slot].tag = tag;
  
  if (!root_ptr_ || when < entries_[root_ptr_].when) {
    entries_[free_slot].next = root_ptr_;
    root_ptr_ = free_slot;
  } else {
    uint8_t insert_position = root_ptr_;
    while (entries_[insert_position].next &&
           when >= entries_[entries_[insert_position].next].when) {
      insert_position = entries_[insert_position].next;
    }
    entries_[free_slot].next = entries_[insert_position].next;
    entries_[insert_position].next = free_slot;
  }
}

/* extern */
EventScheduler event_scheduler;

}  // namespace midipal
