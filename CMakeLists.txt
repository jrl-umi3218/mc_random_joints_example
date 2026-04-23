cmake_minimum_required(VERSION 3.10)

set(CXX_DISABLE_WERROR 1)
set(CMAKE_CXX_STANDARD 11)

set(PROJECT_NAME RandomJointsExample)
set(PROJECT_DESCRIPTION "RandomJointsExample")
set(PROJECT_URL "")

project(${PROJECT_NAME} CXX)

# Check if the project is built inside mc_rtc
if(NOT TARGET mc_rtc::mc_control)
  find_package(mc_rtc REQUIRED)
endif()

add_subdirectory(src)

set(AROBASE "@")
configure_file(etc/RandomJointsExample.in.yaml "${CMAKE_CURRENT_BINARY_DIR}/etc/RandomJointsExample.yaml")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/etc/RandomJointsExample.yaml" DESTINATION "${MC_CONTROLLER_RUNTIME_INSTALL_PREFIX}/etc")

