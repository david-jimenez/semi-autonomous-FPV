cmake_minimum_required(VERSION 3.0.2)
set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
project(LibMaestro)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/")

find_package(libusb-1.0 REQUIRED)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/" ${LIBUSB_1_INCLUDE_DIRS})

add_library(maestro STATIC source/maestro.cpp)
target_link_libraries(maestro ${LIBUSB_1_LIBRARIES})

add_executable(maestro-app source/main.cpp source/testThread.cpp source/server.cpp source/multiwii.cpp source/msp.cpp source/mspdata.cpp source/serial.cpp source/maestro.cpp source/PWM.cpp)
target_link_libraries(maestro-app maestro)
TARGET_LINK_LIBRARIES(maestro-app pthread)

install(TARGETS maestro DESTINATION lib)
install(FILES include/maestro.h DESTINATION include)
