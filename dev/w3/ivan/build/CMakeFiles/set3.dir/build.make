# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /snap/cmake/1216/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1216/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan/build

# Include any dependencies generated for this target.
include CMakeFiles/set3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/set3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/set3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/set3.dir/flags.make

CMakeFiles/set3.dir/src/main.cc.o: CMakeFiles/set3.dir/flags.make
CMakeFiles/set3.dir/src/main.cc.o: /home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan/src/main.cc
CMakeFiles/set3.dir/src/main.cc.o: CMakeFiles/set3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/set3.dir/src/main.cc.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/set3.dir/src/main.cc.o -MF CMakeFiles/set3.dir/src/main.cc.o.d -o CMakeFiles/set3.dir/src/main.cc.o -c /home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan/src/main.cc

CMakeFiles/set3.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/set3.dir/src/main.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan/src/main.cc > CMakeFiles/set3.dir/src/main.cc.i

CMakeFiles/set3.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/set3.dir/src/main.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan/src/main.cc -o CMakeFiles/set3.dir/src/main.cc.s

# Object files for target set3
set3_OBJECTS = \
"CMakeFiles/set3.dir/src/main.cc.o"

# External object files for target set3
set3_EXTERNAL_OBJECTS =

set3: CMakeFiles/set3.dir/src/main.cc.o
set3: CMakeFiles/set3.dir/build.make
set3: CMakeFiles/set3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable set3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/set3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/set3.dir/build: set3
.PHONY : CMakeFiles/set3.dir/build

CMakeFiles/set3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/set3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/set3.dir/clean

CMakeFiles/set3.dir/depend:
	cd /home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan /home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan /home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan/build /home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan/build /home/ivanyanakiev1/Desktop/Uni2022/CPP_Part3/dev/w3/ivan/build/CMakeFiles/set3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/set3.dir/depend
