# Install script for directory: /home/odroid/Documents/Thesis/semi-autonomous-FPV/PWM/RapaPololuMaestro-master

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/odroid/Documents/Thesis/semi-autonomous-FPV/PWM/RapaPololuMaestro-master/_output_")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/odroid/Documents/Thesis/semi-autonomous-FPV/PWM/RapaPololuMaestro-master/_build_/libRapaPololuMaestro.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/odroid/Documents/Thesis/semi-autonomous-FPV/PWM/RapaPololuMaestro-master/include/RPMSerialInterface.h"
    "/home/odroid/Documents/Thesis/semi-autonomous-FPV/PWM/RapaPololuMaestro-master/include/RPMSerialInterfacePOSIX.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/RapaPololuMaestro/RapaPololuMaestroTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/RapaPololuMaestro/RapaPololuMaestroTargets.cmake"
         "/home/odroid/Documents/Thesis/semi-autonomous-FPV/PWM/RapaPololuMaestro-master/_build_/CMakeFiles/Export/lib/cmake/RapaPololuMaestro/RapaPololuMaestroTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/RapaPololuMaestro/RapaPololuMaestroTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/RapaPololuMaestro/RapaPololuMaestroTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/RapaPololuMaestro" TYPE FILE FILES "/home/odroid/Documents/Thesis/semi-autonomous-FPV/PWM/RapaPololuMaestro-master/_build_/CMakeFiles/Export/lib/cmake/RapaPololuMaestro/RapaPololuMaestroTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/RapaPololuMaestro" TYPE FILE FILES "/home/odroid/Documents/Thesis/semi-autonomous-FPV/PWM/RapaPololuMaestro-master/_build_/CMakeFiles/Export/lib/cmake/RapaPololuMaestro/RapaPololuMaestroTargets-noconfig.cmake")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/RapaPololuMaestro" TYPE FILE FILES "/home/odroid/Documents/Thesis/semi-autonomous-FPV/PWM/RapaPololuMaestro-master/_build_/RapaPololuMaestro/RapaPololuMaestroConfig.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/odroid/Documents/Thesis/semi-autonomous-FPV/PWM/RapaPololuMaestro-master/_build_/samples/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

file(WRITE "/home/odroid/Documents/Thesis/semi-autonomous-FPV/PWM/RapaPololuMaestro-master/_build_/${CMAKE_INSTALL_MANIFEST}" "")
foreach(file ${CMAKE_INSTALL_MANIFEST_FILES})
  file(APPEND "/home/odroid/Documents/Thesis/semi-autonomous-FPV/PWM/RapaPololuMaestro-master/_build_/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
endforeach()
