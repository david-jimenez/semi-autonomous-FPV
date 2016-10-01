cmake_minimum_required(VERSION 3.0.2)
set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
project(LibMaestro)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/")

find_package(libusb-1.0 REQUIRED)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/" ${LIBUSB_1_INCLUDE_DIRS})

add_library(maestro STATIC source/maestro.cpp)
target_link_libraries(maestro ${LIBUSB_1_LIBRARIES})

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

add_executable(run source/main.cpp source/testThread.cpp source/server.cpp source/multiwii.cpp source/msp.cpp source/mspdata.cpp source/serial.cpp source/maestro.cpp source/PWM.cpp source/autopilot_interface.cpp source/mavlink_control.cpp source/serial_port.cpp source/kalman.cpp source/lqr.cpp)
target_link_libraries(run maestro)
TARGET_LINK_LIBRARIES(run pthread)

find_package(PythonLibs 2.7 REQUIRED)
message(${PYTHON_INCLUDE_DIRS})
message(${PYTHON_LIBRARIES})
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(run ${PYTHON_LIBRARIES})

target_link_libraries(run ${ARMADILLO_LIBRARIES})

install(TARGETS maestro DESTINATION lib)
install(FILES include/maestro.h DESTINATION include)
