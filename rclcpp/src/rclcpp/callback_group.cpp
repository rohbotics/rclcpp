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

#include <rclcpp/callback_group.hpp>

#include "impl/callback_group_impl.hpp"

using namespace rclcpp::callback_group;

CallbackGroup::CallbackGroup(CallbackGroupType group_type)
: impl_(new CallbackGroup_Impl(group_type))
{}

bool
CallbackGroup::can_be_taken_from()
{
  return impl_->can_be_taken_from();
}

CallbackGroupType
CallbackGroup::get_callback_group_type()
{
  return impl_->get_callback_group_type();
}

CallbackGroup_Impl *
CallbackGroup::get_implementation()
{
  return impl_;
}
