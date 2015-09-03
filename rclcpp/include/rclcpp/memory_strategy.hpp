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

#ifndef RCLCPP_RCLCPP_MEMORY_STRATEGY_HPP_
#define RCLCPP_RCLCPP_MEMORY_STRATEGY_HPP_

#include <rclcpp/any_executable.hpp>

namespace rclcpp
{

// TODO move HandleType somewhere where it makes sense
enum class HandleType {subscription_handle, service_handle, client_handle, guard_condition_handle};

namespace memory_strategy
{

/// Delegate for handling memory allocations while the Executor is executing.
/**
 * By default, the memory strategy dynamically allocates memory for structures that come in from
 * the rmw implementation after the executor waits for work, based on the number of entities that
 * come through.
 */
class MemoryStrategy
{
public:
  RCLCPP_SMART_PTR_DEFINITIONS(MemoryStrategy);

  /// Borrow memory for storing data for subscriptions, services, clients, or guard conditions.
  /**
   * The default implementation ignores the handle type and dynamically allocates the memory.
   * \param[in] The type of entity that this function is requesting for.
   * \param[in] The number of handles to borrow.
   * \return Pointer to the allocated handles.
   */
  virtual void **
  borrow_handles(HandleType type, size_t number_of_handles);

  /// Return the memory borrowed in borrow_handles.
  /**
   * return_handles should always mirror the way memory was borrowed in borrow_handles.
   * \param[in] The type of entity that this function is returning.
   * \param[in] Pointer to the handles returned.
   */
  virtual void
  return_handles(HandleType type, void ** handles);

  /// Provide a newly initialized AnyExecutable object.
  // \return Shared pointer to the fresh executable.
  virtual executor::AnyExecutable::SharedPtr
  instantiate_next_executable();

  /// Implementation of a general-purpose allocation function.
  /**
   * \param[in] size Number of bytes to allocate.
   * \return Pointer to the allocated chunk of memory.
   */
  virtual void *
  alloc(size_t size);

  /// Implementation of a general-purpose free.
  /**
   * \param[in] Pointer to deallocate.
   */
  virtual void
  free(void * ptr);
};


MemoryStrategy::SharedPtr
create_default_strategy();

}  /* memory_strategy */

}  /* rclcpp */

#endif
