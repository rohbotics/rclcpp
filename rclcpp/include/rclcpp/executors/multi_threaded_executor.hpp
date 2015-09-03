// Copyright 2014 Open Source Robotics Foundation, Inc.
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

#ifndef RCLCPP_RCLCPP_EXECUTORS_MULTI_THREADED_EXECUTOR_HPP_
#define RCLCPP_RCLCPP_EXECUTORS_MULTI_THREADED_EXECUTOR_HPP_

#include <rclcpp/executor.hpp>

namespace rclcpp
{
namespace executors
{
namespace multi_threaded_executor
{

class MultiThreadedExecutor : public executor::Executor
{
public:
  RCLCPP_SMART_PTR_DEFINITIONS(MultiThreadedExecutor);

  MultiThreadedExecutor(
    memory_strategy::MemoryStrategy::SharedPtr ms = memory_strategy::create_default_strategy());

  virtual ~MultiThreadedExecutor();

  void
  spin();

  size_t
  get_number_of_threads();

private:
  void run(size_t this_thread_number);

  RCLCPP_DISABLE_COPY(MultiThreadedExecutor);

  std::mutex wait_mutex_;
  size_t number_of_threads_;
  std::unordered_map<std::thread::id, size_t> thread_number_by_thread_id_;

};

} /* namespace multi_threaded_executor */
} /* namespace executors */
} /* namespace rclcpp */

#endif /* RCLCPP_RCLCPP_EXECUTORS_MULTI_THREADED_EXECUTOR_HPP_ */
