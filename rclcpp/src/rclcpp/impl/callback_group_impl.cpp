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

#include "callback_group_impl.hpp"

using namespace rclcpp::callback_group;

CallbackGroup_Impl::CallbackGroup_Impl(CallbackGroupType group_type)
: type_(group_type), can_be_taken_from_(true)
{}

bool
CallbackGroup_Impl::can_be_taken_from()
{
  return can_be_taken_from_.load();
}

CallbackGroupType
CallbackGroup_Impl::get_callback_group_type()
{
  return type_;
}

void
CallbackGroup_Impl::add_subscription(
  const subscription::SubscriptionBase::SharedPtr subscription_ptr)
{
  subscription_ptrs_.push_back(subscription_ptr);
}

void
CallbackGroup_Impl::add_timer(const timer::TimerBase::SharedPtr timer_ptr)
{
  timer_ptrs_.push_back(timer_ptr);
}

void
CallbackGroup_Impl::add_service(const service::ServiceBase::SharedPtr service_ptr)
{
  service_ptrs_.push_back(service_ptr);
}

void
CallbackGroup_Impl::add_client(const client::ClientBase::SharedPtr client_ptr)
{
  client_ptrs_.push_back(client_ptr);
}
