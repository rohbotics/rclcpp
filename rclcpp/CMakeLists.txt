cmake_minimum_required(VERSION 2.8.3)

project(rclcpp)

find_package(ament_cmake REQUIRED)
find_package(rcl_interfaces REQUIRED)
find_package(rmw REQUIRED)
find_package(rmw_implementation REQUIRED)

get_default_rmw_implementation(default_middleware_impl)
find_package(${default_middleware_impl} REQUIRED)

if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")
endif()

include_directories(include)

set(${PROJECT_NAME}_SRCS
  src/rclcpp/executor.cpp
  src/rclcpp/executors/multi_threaded_executor.cpp
  src/rclcpp/executors/single_threaded_executor.cpp
  src/rclcpp/memory_strategy.cpp
  src/rclcpp/node.cpp
  src/rclcpp/utilities.cpp
)
add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SRCS})
ament_target_dependencies(${PROJECT_NAME} "rmw" "${default_middleware_impl}" "rcl_interfaces")
if(APPLE)
  # Since the rmw_* symbols are external, tell the linker on OS X to
  # dynamically look them up at runtime.
  # set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
endif()

ament_export_dependencies(rmw)
ament_export_dependencies(rcl_interfaces)

ament_export_include_directories(include)

ament_export_libraries(${PROJECT_NAME})

# if(AMENT_ENABLE_TESTING)
#   find_package(ament_lint_auto REQUIRED)
#   ament_lint_auto_find_test_dependencies()

#   ament_add_gtest(test_mapped_ring_buffer test/test_mapped_ring_buffer.cpp)
#   ament_add_gtest(test_intra_process_manager test/test_intra_process_manager.cpp)
#   if(TARGET test_intra_process_manager)
#     target_include_directories(test_intra_process_manager PUBLIC
#       "${rcl_interfaces_INCLUDE_DIRS}"
#       "${rmw_INCLUDE_DIRS}")
#   endif()
# endif()

ament_package(
  CONFIG_EXTRAS rclcpp-extras.cmake
)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(
  DIRECTORY src/
  DESTINATION src/rclcpp
)
