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

#ifndef RCLCPP_RCLCPP_CALLBACK_GROUP_HPP_
#define RCLCPP_RCLCPP_CALLBACK_GROUP_HPP_

#include <memory>

#include <rclcpp/macros.hpp>

namespace rclcpp
{

namespace callback_group
{

enum class CallbackGroupType
{
  MutuallyExclusive,
  Reentrant
};

class CallbackGroup_Impl;

class CallbackGroup
{
public:
  RCLCPP_SMART_PTR_DEFINITIONS(CallbackGroup);

  CallbackGroup(CallbackGroupType group_type);

  bool
  can_be_taken_from();

  CallbackGroupType
  get_callback_group_type();

  CallbackGroup_Impl *
  get_implementation();

private:
  CallbackGroup_Impl * impl_;

};

} /* namespace callback_group */
} /* namespace rclcpp */

#endif /* RCLCPP_RCLCPP_CALLBACK_GROUP_HPP_ */
