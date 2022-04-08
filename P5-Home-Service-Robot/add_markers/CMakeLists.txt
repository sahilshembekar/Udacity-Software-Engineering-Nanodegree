cmake_minimum_required(VERSION 2.8.3)
project(add_markers)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  visualization_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES add_markers
#  CATKIN_DEPENDS roscpp visualization_msgs
#  DEPENDS system_lib
)


include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(add_markers src/add_markers.cpp)
target_link_libraries(add_markers ${catkin_LIBRARIES})
add_dependencies(add_markers add_markers_generate_messages_cpp)

add_executable(add_markers_static src/add_markers_static.cpp)
target_link_libraries(add_markers_static ${catkin_LIBRARIES})
