# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/build

# Include any dependencies generated for this target.
include SignalProcessing/CMakeFiles/SignalProcessinglib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include SignalProcessing/CMakeFiles/SignalProcessinglib.dir/compiler_depend.make

# Include the progress variables for this target.
include SignalProcessing/CMakeFiles/SignalProcessinglib.dir/progress.make

# Include the compile flags for this target's objects.
include SignalProcessing/CMakeFiles/SignalProcessinglib.dir/flags.make

SignalProcessing/CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.o: SignalProcessing/CMakeFiles/SignalProcessinglib.dir/flags.make
SignalProcessing/CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.o: ../SignalProcessing/SignalProcessing.cpp
SignalProcessing/CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.o: SignalProcessing/CMakeFiles/SignalProcessinglib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object SignalProcessing/CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.o"
	cd /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/build/SignalProcessing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT SignalProcessing/CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.o -MF CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.o.d -o CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.o -c /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/SignalProcessing/SignalProcessing.cpp

SignalProcessing/CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.i"
	cd /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/build/SignalProcessing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/SignalProcessing/SignalProcessing.cpp > CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.i

SignalProcessing/CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.s"
	cd /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/build/SignalProcessing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/SignalProcessing/SignalProcessing.cpp -o CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.s

# Object files for target SignalProcessinglib
SignalProcessinglib_OBJECTS = \
"CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.o"

# External object files for target SignalProcessinglib
SignalProcessinglib_EXTERNAL_OBJECTS =

SignalProcessing/libSignalProcessinglib.so: SignalProcessing/CMakeFiles/SignalProcessinglib.dir/SignalProcessing.cpp.o
SignalProcessing/libSignalProcessinglib.so: SignalProcessing/CMakeFiles/SignalProcessinglib.dir/build.make
SignalProcessing/libSignalProcessinglib.so: SignalProcessing/CMakeFiles/SignalProcessinglib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libSignalProcessinglib.so"
	cd /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/build/SignalProcessing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SignalProcessinglib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
SignalProcessing/CMakeFiles/SignalProcessinglib.dir/build: SignalProcessing/libSignalProcessinglib.so
.PHONY : SignalProcessing/CMakeFiles/SignalProcessinglib.dir/build

SignalProcessing/CMakeFiles/SignalProcessinglib.dir/clean:
	cd /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/build/SignalProcessing && $(CMAKE_COMMAND) -P CMakeFiles/SignalProcessinglib.dir/cmake_clean.cmake
.PHONY : SignalProcessing/CMakeFiles/SignalProcessinglib.dir/clean

SignalProcessing/CMakeFiles/SignalProcessinglib.dir/depend:
	cd /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1 /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/SignalProcessing /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/build /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/build/SignalProcessing /home/wow/Desktop/rtl_sdr_1/rtl_sdr_p1/build/SignalProcessing/CMakeFiles/SignalProcessinglib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : SignalProcessing/CMakeFiles/SignalProcessinglib.dir/depend

