# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/dark_knight/ImageProcessing/TrafficSign_ADAS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dark_knight/ImageProcessing/TrafficSign_ADAS/build

# Include any dependencies generated for this target.
include CMakeFiles/tsr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tsr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tsr.dir/flags.make

CMakeFiles/tsr.dir/src/traffic_sign.cpp.o: CMakeFiles/tsr.dir/flags.make
CMakeFiles/tsr.dir/src/traffic_sign.cpp.o: ../src/traffic_sign.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dark_knight/ImageProcessing/TrafficSign_ADAS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tsr.dir/src/traffic_sign.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tsr.dir/src/traffic_sign.cpp.o -c /home/dark_knight/ImageProcessing/TrafficSign_ADAS/src/traffic_sign.cpp

CMakeFiles/tsr.dir/src/traffic_sign.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tsr.dir/src/traffic_sign.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dark_knight/ImageProcessing/TrafficSign_ADAS/src/traffic_sign.cpp > CMakeFiles/tsr.dir/src/traffic_sign.cpp.i

CMakeFiles/tsr.dir/src/traffic_sign.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tsr.dir/src/traffic_sign.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dark_knight/ImageProcessing/TrafficSign_ADAS/src/traffic_sign.cpp -o CMakeFiles/tsr.dir/src/traffic_sign.cpp.s

CMakeFiles/tsr.dir/src/traffic_sign.cpp.o.requires:

.PHONY : CMakeFiles/tsr.dir/src/traffic_sign.cpp.o.requires

CMakeFiles/tsr.dir/src/traffic_sign.cpp.o.provides: CMakeFiles/tsr.dir/src/traffic_sign.cpp.o.requires
	$(MAKE) -f CMakeFiles/tsr.dir/build.make CMakeFiles/tsr.dir/src/traffic_sign.cpp.o.provides.build
.PHONY : CMakeFiles/tsr.dir/src/traffic_sign.cpp.o.provides

CMakeFiles/tsr.dir/src/traffic_sign.cpp.o.provides.build: CMakeFiles/tsr.dir/src/traffic_sign.cpp.o


CMakeFiles/tsr.dir/src/main.cpp.o: CMakeFiles/tsr.dir/flags.make
CMakeFiles/tsr.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dark_knight/ImageProcessing/TrafficSign_ADAS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tsr.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tsr.dir/src/main.cpp.o -c /home/dark_knight/ImageProcessing/TrafficSign_ADAS/src/main.cpp

CMakeFiles/tsr.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tsr.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dark_knight/ImageProcessing/TrafficSign_ADAS/src/main.cpp > CMakeFiles/tsr.dir/src/main.cpp.i

CMakeFiles/tsr.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tsr.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dark_knight/ImageProcessing/TrafficSign_ADAS/src/main.cpp -o CMakeFiles/tsr.dir/src/main.cpp.s

CMakeFiles/tsr.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/tsr.dir/src/main.cpp.o.requires

CMakeFiles/tsr.dir/src/main.cpp.o.provides: CMakeFiles/tsr.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/tsr.dir/build.make CMakeFiles/tsr.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/tsr.dir/src/main.cpp.o.provides

CMakeFiles/tsr.dir/src/main.cpp.o.provides.build: CMakeFiles/tsr.dir/src/main.cpp.o


# Object files for target tsr
tsr_OBJECTS = \
"CMakeFiles/tsr.dir/src/traffic_sign.cpp.o" \
"CMakeFiles/tsr.dir/src/main.cpp.o"

# External object files for target tsr
tsr_EXTERNAL_OBJECTS =

libtsr.a: CMakeFiles/tsr.dir/src/traffic_sign.cpp.o
libtsr.a: CMakeFiles/tsr.dir/src/main.cpp.o
libtsr.a: CMakeFiles/tsr.dir/build.make
libtsr.a: CMakeFiles/tsr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dark_knight/ImageProcessing/TrafficSign_ADAS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libtsr.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tsr.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tsr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tsr.dir/build: libtsr.a

.PHONY : CMakeFiles/tsr.dir/build

CMakeFiles/tsr.dir/requires: CMakeFiles/tsr.dir/src/traffic_sign.cpp.o.requires
CMakeFiles/tsr.dir/requires: CMakeFiles/tsr.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/tsr.dir/requires

CMakeFiles/tsr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tsr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tsr.dir/clean

CMakeFiles/tsr.dir/depend:
	cd /home/dark_knight/ImageProcessing/TrafficSign_ADAS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dark_knight/ImageProcessing/TrafficSign_ADAS /home/dark_knight/ImageProcessing/TrafficSign_ADAS /home/dark_knight/ImageProcessing/TrafficSign_ADAS/build /home/dark_knight/ImageProcessing/TrafficSign_ADAS/build /home/dark_knight/ImageProcessing/TrafficSign_ADAS/build/CMakeFiles/tsr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tsr.dir/depend

