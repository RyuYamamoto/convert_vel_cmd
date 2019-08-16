cmake_minimum_required(VERSION 2.8.3)
project(convert_vel_cmd)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  autoware_msgs
  roscpp
  sensor_msgs
)

catkin_package(
  CATKIN_DEPENDS autoware_msgs roscpp geometry_msgs
)

include_directories(
	include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/convert_vel_cmd_node.cpp src/convert_vel_cmd.cpp)
target_link_libraries(${PROJECT_NAME}_node
   ${catkin_LIBRARIES}
)
add_dependencies(${PROJECT_NAME}_node ${catkin_EXPORTED_TARGETS})
install(TARGETS
	${PROJECT_NAME}_node
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
        )
