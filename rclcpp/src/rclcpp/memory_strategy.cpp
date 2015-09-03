// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <rclcpp/memory_strategy.hpp>

using namespace memory_strategy;

void **
MemoryStrategy::borrow_handles(HandleType type, size_t number_of_handles)
{
  (void)type;
  return static_cast<void **>(alloc(sizeof(void *) * number_of_handles));
}

void
MemoryStrategy::return_handles(HandleType type, void ** handles)
{
  (void)type;
  this->free(handles);
}

executor::AnyExecutable::SharedPtr
MemoryStrategy::instantiate_next_executable()
{
  return std::make_shared<executor::AnyExecutable>();
}

void *
MemoryStrategy::alloc(size_t size)
{
  if (size == 0) {
    return NULL;
  }
  return std::malloc(size);
}

void
MemoryStrategy::free(void * ptr)
{
  return std::free(ptr);
}

MemoryStrategy::SharedPtr
create_default_strategy()
{
  return std::make_shared<MemoryStrategy>(MemoryStrategy());
}
