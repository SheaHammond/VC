cmake_minimum_required(VERSION 3.0.2)
project(xiros)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

set(OpenCV_INCLUDE_DIRS /usr/local/include)
## set(OpenCV_LIB /usr/local/lib/)
set(XIMEA_INCLUDE_DIR /package/include)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  cv_bridge
)

###################################
## catkin specific configuration ##
###################################

catkin_package(
  INCLUDE_DIRS include 
  LIBRARIES xiros xiAPIplusCameraOcv
  CATKIN_DEPENDS cv_bridge roscpp rospy std_msgs
  DEPENDS 
)

###########
## Build ##
###########

 include_directories(
    include
      ${xiros_INCLUDE_DIRS}
      ${catkin_INCLUDE_DIRS}
      ${OpenCV_INCLUDE_DIRS} 
      ${XIMEA_INCLUDE_DIR}
      ##/home/nvidia/package/samples/_libs/_cmake
      ##/home/nvidia/catkin_ws/src/xiros/include/xiros
      ##/home/nvidia/catkin_ws/src/xiros/src
      ##/home/nvidia/package/include
      ##/usr/local/include
      ##/opt/XIMEA/include 
)


## Declare a C++ executable
add_executable(GetXiWorking src/xiWorking.cpp)

## Add cmake target dependencies of the executable
add_dependencies(GetXiWorking ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS} )

add_executable(talker src/talker.cpp)
add_dependencies(talker ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(talker ${catkin_LIBRARIES})


add_executable(listener src/listener.cpp)
add_dependencies(listener ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(listener ${catkin_LIBRARIES})


 ## Declare a C++ library
  add_library(xiAPIplusCameraOcv
    ~/package/examples/xiApiPlusOpenCV/xiApiPlusOcv.cpp
)
 
## Specify libraries to link a library or executable target against
target_link_libraries(GetXiWorking
  ${catkin_LIBRARIES}
  ##${OpenCV_LIB}
  xiAPIplusCameraOcv
  ~/package/api/Xarm64/libm3api.so.2
  /usr/local/lib/libopencv_core.so.3.4
  /usr/local/lib/libopencv_highgui.so.3.4
  /usr/local/lib/libopencv_imgcodecs.so.3.4
)


#############
## Install ##
#############

install(
    TARGETS xiAPIplusCameraOcv
    ARCHIVE DESTINATION
    ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION
    ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION
    ${CATKIN_GLOBAL_BIN_DESTINATION}
)

install(
    DIRECTORY include/${PROJECT_NAME}/
    DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}
)

