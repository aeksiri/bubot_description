cmake_minimum_required(VERSION 2.8.3)

project(bubot_description)

find_package(catkin REQUIRED)

catkin_package()

find_package(roslaunch)

foreach(dir config launch meshes urdf)
	install(DIRECTORY ${dir}/
		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)


find_package(catkin REQUIRED COMPONENTS
  roscpp
)

include_directories(
  include ${catkin_INCLUDE_DIRS}
)


add_executable(test_axis_sub
  src/test_axis_sub.cpp
)
add_dependencies(test_axis_sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(test_axis_sub
  ${catkin_LIBRARIES}
)