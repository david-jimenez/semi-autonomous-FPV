# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread

# Include any dependencies generated for this target.
include CMakeFiles/run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run.dir/flags.make

CMakeFiles/run.dir/source/main.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/source/main.cpp.o: source/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/source/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/source/main.cpp.o -c /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/main.cpp

CMakeFiles/run.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/source/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/main.cpp > CMakeFiles/run.dir/source/main.cpp.i

CMakeFiles/run.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/source/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/main.cpp -o CMakeFiles/run.dir/source/main.cpp.s

CMakeFiles/run.dir/source/main.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/source/main.cpp.o.requires

CMakeFiles/run.dir/source/main.cpp.o.provides: CMakeFiles/run.dir/source/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/source/main.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/source/main.cpp.o.provides

CMakeFiles/run.dir/source/main.cpp.o.provides.build: CMakeFiles/run.dir/source/main.cpp.o

CMakeFiles/run.dir/source/testThread.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/source/testThread.cpp.o: source/testThread.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/source/testThread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/source/testThread.cpp.o -c /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/testThread.cpp

CMakeFiles/run.dir/source/testThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/source/testThread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/testThread.cpp > CMakeFiles/run.dir/source/testThread.cpp.i

CMakeFiles/run.dir/source/testThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/source/testThread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/testThread.cpp -o CMakeFiles/run.dir/source/testThread.cpp.s

CMakeFiles/run.dir/source/testThread.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/source/testThread.cpp.o.requires

CMakeFiles/run.dir/source/testThread.cpp.o.provides: CMakeFiles/run.dir/source/testThread.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/source/testThread.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/source/testThread.cpp.o.provides

CMakeFiles/run.dir/source/testThread.cpp.o.provides.build: CMakeFiles/run.dir/source/testThread.cpp.o

CMakeFiles/run.dir/source/server.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/source/server.cpp.o: source/server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/source/server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/source/server.cpp.o -c /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/server.cpp

CMakeFiles/run.dir/source/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/source/server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/server.cpp > CMakeFiles/run.dir/source/server.cpp.i

CMakeFiles/run.dir/source/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/source/server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/server.cpp -o CMakeFiles/run.dir/source/server.cpp.s

CMakeFiles/run.dir/source/server.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/source/server.cpp.o.requires

CMakeFiles/run.dir/source/server.cpp.o.provides: CMakeFiles/run.dir/source/server.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/source/server.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/source/server.cpp.o.provides

CMakeFiles/run.dir/source/server.cpp.o.provides.build: CMakeFiles/run.dir/source/server.cpp.o

CMakeFiles/run.dir/source/multiwii.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/source/multiwii.cpp.o: source/multiwii.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/source/multiwii.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/source/multiwii.cpp.o -c /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/multiwii.cpp

CMakeFiles/run.dir/source/multiwii.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/source/multiwii.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/multiwii.cpp > CMakeFiles/run.dir/source/multiwii.cpp.i

CMakeFiles/run.dir/source/multiwii.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/source/multiwii.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/multiwii.cpp -o CMakeFiles/run.dir/source/multiwii.cpp.s

CMakeFiles/run.dir/source/multiwii.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/source/multiwii.cpp.o.requires

CMakeFiles/run.dir/source/multiwii.cpp.o.provides: CMakeFiles/run.dir/source/multiwii.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/source/multiwii.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/source/multiwii.cpp.o.provides

CMakeFiles/run.dir/source/multiwii.cpp.o.provides.build: CMakeFiles/run.dir/source/multiwii.cpp.o

CMakeFiles/run.dir/source/msp.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/source/msp.cpp.o: source/msp.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/source/msp.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/source/msp.cpp.o -c /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/msp.cpp

CMakeFiles/run.dir/source/msp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/source/msp.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/msp.cpp > CMakeFiles/run.dir/source/msp.cpp.i

CMakeFiles/run.dir/source/msp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/source/msp.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/msp.cpp -o CMakeFiles/run.dir/source/msp.cpp.s

CMakeFiles/run.dir/source/msp.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/source/msp.cpp.o.requires

CMakeFiles/run.dir/source/msp.cpp.o.provides: CMakeFiles/run.dir/source/msp.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/source/msp.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/source/msp.cpp.o.provides

CMakeFiles/run.dir/source/msp.cpp.o.provides.build: CMakeFiles/run.dir/source/msp.cpp.o

CMakeFiles/run.dir/source/mspdata.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/source/mspdata.cpp.o: source/mspdata.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/source/mspdata.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/source/mspdata.cpp.o -c /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/mspdata.cpp

CMakeFiles/run.dir/source/mspdata.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/source/mspdata.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/mspdata.cpp > CMakeFiles/run.dir/source/mspdata.cpp.i

CMakeFiles/run.dir/source/mspdata.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/source/mspdata.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/mspdata.cpp -o CMakeFiles/run.dir/source/mspdata.cpp.s

CMakeFiles/run.dir/source/mspdata.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/source/mspdata.cpp.o.requires

CMakeFiles/run.dir/source/mspdata.cpp.o.provides: CMakeFiles/run.dir/source/mspdata.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/source/mspdata.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/source/mspdata.cpp.o.provides

CMakeFiles/run.dir/source/mspdata.cpp.o.provides.build: CMakeFiles/run.dir/source/mspdata.cpp.o

CMakeFiles/run.dir/source/serial.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/source/serial.cpp.o: source/serial.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/source/serial.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/source/serial.cpp.o -c /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/serial.cpp

CMakeFiles/run.dir/source/serial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/source/serial.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/serial.cpp > CMakeFiles/run.dir/source/serial.cpp.i

CMakeFiles/run.dir/source/serial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/source/serial.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/serial.cpp -o CMakeFiles/run.dir/source/serial.cpp.s

CMakeFiles/run.dir/source/serial.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/source/serial.cpp.o.requires

CMakeFiles/run.dir/source/serial.cpp.o.provides: CMakeFiles/run.dir/source/serial.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/source/serial.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/source/serial.cpp.o.provides

CMakeFiles/run.dir/source/serial.cpp.o.provides.build: CMakeFiles/run.dir/source/serial.cpp.o

CMakeFiles/run.dir/source/maestro.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/source/maestro.cpp.o: source/maestro.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/source/maestro.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/source/maestro.cpp.o -c /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/maestro.cpp

CMakeFiles/run.dir/source/maestro.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/source/maestro.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/maestro.cpp > CMakeFiles/run.dir/source/maestro.cpp.i

CMakeFiles/run.dir/source/maestro.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/source/maestro.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/maestro.cpp -o CMakeFiles/run.dir/source/maestro.cpp.s

CMakeFiles/run.dir/source/maestro.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/source/maestro.cpp.o.requires

CMakeFiles/run.dir/source/maestro.cpp.o.provides: CMakeFiles/run.dir/source/maestro.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/source/maestro.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/source/maestro.cpp.o.provides

CMakeFiles/run.dir/source/maestro.cpp.o.provides.build: CMakeFiles/run.dir/source/maestro.cpp.o

CMakeFiles/run.dir/source/PWM.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/source/PWM.cpp.o: source/PWM.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/source/PWM.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/source/PWM.cpp.o -c /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/PWM.cpp

CMakeFiles/run.dir/source/PWM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/source/PWM.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/PWM.cpp > CMakeFiles/run.dir/source/PWM.cpp.i

CMakeFiles/run.dir/source/PWM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/source/PWM.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/PWM.cpp -o CMakeFiles/run.dir/source/PWM.cpp.s

CMakeFiles/run.dir/source/PWM.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/source/PWM.cpp.o.requires

CMakeFiles/run.dir/source/PWM.cpp.o.provides: CMakeFiles/run.dir/source/PWM.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/source/PWM.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/source/PWM.cpp.o.provides

CMakeFiles/run.dir/source/PWM.cpp.o.provides.build: CMakeFiles/run.dir/source/PWM.cpp.o

CMakeFiles/run.dir/source/autopilot_interface.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/source/autopilot_interface.cpp.o: source/autopilot_interface.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/source/autopilot_interface.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/source/autopilot_interface.cpp.o -c /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/autopilot_interface.cpp

CMakeFiles/run.dir/source/autopilot_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/source/autopilot_interface.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/autopilot_interface.cpp > CMakeFiles/run.dir/source/autopilot_interface.cpp.i

CMakeFiles/run.dir/source/autopilot_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/source/autopilot_interface.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/autopilot_interface.cpp -o CMakeFiles/run.dir/source/autopilot_interface.cpp.s

CMakeFiles/run.dir/source/autopilot_interface.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/source/autopilot_interface.cpp.o.requires

CMakeFiles/run.dir/source/autopilot_interface.cpp.o.provides: CMakeFiles/run.dir/source/autopilot_interface.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/source/autopilot_interface.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/source/autopilot_interface.cpp.o.provides

CMakeFiles/run.dir/source/autopilot_interface.cpp.o.provides.build: CMakeFiles/run.dir/source/autopilot_interface.cpp.o

CMakeFiles/run.dir/source/mavlink_control.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/source/mavlink_control.cpp.o: source/mavlink_control.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/source/mavlink_control.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/source/mavlink_control.cpp.o -c /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/mavlink_control.cpp

CMakeFiles/run.dir/source/mavlink_control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/source/mavlink_control.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/mavlink_control.cpp > CMakeFiles/run.dir/source/mavlink_control.cpp.i

CMakeFiles/run.dir/source/mavlink_control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/source/mavlink_control.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/mavlink_control.cpp -o CMakeFiles/run.dir/source/mavlink_control.cpp.s

CMakeFiles/run.dir/source/mavlink_control.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/source/mavlink_control.cpp.o.requires

CMakeFiles/run.dir/source/mavlink_control.cpp.o.provides: CMakeFiles/run.dir/source/mavlink_control.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/source/mavlink_control.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/source/mavlink_control.cpp.o.provides

CMakeFiles/run.dir/source/mavlink_control.cpp.o.provides.build: CMakeFiles/run.dir/source/mavlink_control.cpp.o

CMakeFiles/run.dir/source/serial_port.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/source/serial_port.cpp.o: source/serial_port.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run.dir/source/serial_port.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run.dir/source/serial_port.cpp.o -c /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/serial_port.cpp

CMakeFiles/run.dir/source/serial_port.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/source/serial_port.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/serial_port.cpp > CMakeFiles/run.dir/source/serial_port.cpp.i

CMakeFiles/run.dir/source/serial_port.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/source/serial_port.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/source/serial_port.cpp -o CMakeFiles/run.dir/source/serial_port.cpp.s

CMakeFiles/run.dir/source/serial_port.cpp.o.requires:
.PHONY : CMakeFiles/run.dir/source/serial_port.cpp.o.requires

CMakeFiles/run.dir/source/serial_port.cpp.o.provides: CMakeFiles/run.dir/source/serial_port.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/source/serial_port.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/source/serial_port.cpp.o.provides

CMakeFiles/run.dir/source/serial_port.cpp.o.provides.build: CMakeFiles/run.dir/source/serial_port.cpp.o

# Object files for target run
run_OBJECTS = \
"CMakeFiles/run.dir/source/main.cpp.o" \
"CMakeFiles/run.dir/source/testThread.cpp.o" \
"CMakeFiles/run.dir/source/server.cpp.o" \
"CMakeFiles/run.dir/source/multiwii.cpp.o" \
"CMakeFiles/run.dir/source/msp.cpp.o" \
"CMakeFiles/run.dir/source/mspdata.cpp.o" \
"CMakeFiles/run.dir/source/serial.cpp.o" \
"CMakeFiles/run.dir/source/maestro.cpp.o" \
"CMakeFiles/run.dir/source/PWM.cpp.o" \
"CMakeFiles/run.dir/source/autopilot_interface.cpp.o" \
"CMakeFiles/run.dir/source/mavlink_control.cpp.o" \
"CMakeFiles/run.dir/source/serial_port.cpp.o"

# External object files for target run
run_EXTERNAL_OBJECTS =

run: CMakeFiles/run.dir/source/main.cpp.o
run: CMakeFiles/run.dir/source/testThread.cpp.o
run: CMakeFiles/run.dir/source/server.cpp.o
run: CMakeFiles/run.dir/source/multiwii.cpp.o
run: CMakeFiles/run.dir/source/msp.cpp.o
run: CMakeFiles/run.dir/source/mspdata.cpp.o
run: CMakeFiles/run.dir/source/serial.cpp.o
run: CMakeFiles/run.dir/source/maestro.cpp.o
run: CMakeFiles/run.dir/source/PWM.cpp.o
run: CMakeFiles/run.dir/source/autopilot_interface.cpp.o
run: CMakeFiles/run.dir/source/mavlink_control.cpp.o
run: CMakeFiles/run.dir/source/serial_port.cpp.o
run: CMakeFiles/run.dir/build.make
run: libmaestro.a
run: /usr/lib/arm-linux-gnueabihf/libusb-1.0.so
run: CMakeFiles/run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run.dir/build: run
.PHONY : CMakeFiles/run.dir/build

CMakeFiles/run.dir/requires: CMakeFiles/run.dir/source/main.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/source/testThread.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/source/server.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/source/multiwii.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/source/msp.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/source/mspdata.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/source/serial.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/source/maestro.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/source/PWM.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/source/autopilot_interface.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/source/mavlink_control.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/source/serial_port.cpp.o.requires
.PHONY : CMakeFiles/run.dir/requires

CMakeFiles/run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run.dir/clean

CMakeFiles/run.dir/depend:
	cd /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread /home/odroid/Documents/Thesis/semi-autonomous-FPV/Multi-thread/CMakeFiles/run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run.dir/depend
