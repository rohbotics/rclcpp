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

#ifndef RCLCPP_RCLCPP_IMPL_CALLBACK_GROUP_IMPL_HPP_
#define RCLCPP_RCLCPP_IMPL_CALLBACK_GROUP_IMPL_HPP_

#include <atomic>
#include <vector>

#include <rclcpp/callback_group.hpp>
#include <rclcpp/client.hpp>
#include <rclcpp/service.hpp>
#include <rclcpp/subscription.hpp>
#include <rclcpp/timer.hpp>

namespace rclcpp
{

namespace callback_group
{

class CallbackGroup_Impl
{
public:
  CallbackGroup_Impl(CallbackGroupType group_type);

  bool
  can_be_taken_from();

  CallbackGroupType
  get_callback_group_type();

  void
  add_subscription(const subscription::SubscriptionBase::SharedPtr subscription_ptr);

  void
  add_timer(const timer::TimerBase::SharedPtr timer_ptr);

  void
  add_service(const service::ServiceBase::SharedPtr service_ptr);

  void
  add_client(const client::ClientBase::SharedPtr client_ptr);

private:
  CallbackGroupType type_;
  std::atomic_bool can_be_taken_from_;

  std::vector<subscription::SubscriptionBase::WeakPtr> subscription_ptrs_;
  std::vector<timer::TimerBase::WeakPtr> timer_ptrs_;
  std::vector<service::ServiceBase::SharedPtr> service_ptrs_;
  std::vector<client::ClientBase::SharedPtr> client_ptrs_;
};

} /* namespace callback_group */
} /* namespace rclcpp */

#endif /* RCLCPP_RCLCPP_IMPL_CALLBACK_GROUP_IMPL_HPP_ */
