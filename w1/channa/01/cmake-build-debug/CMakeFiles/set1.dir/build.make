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
CMAKE_SOURCE_DIR = /mnt/c/Users/cdper/repos/cpp3/w1/channa/01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/set1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/set1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/set1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/set1.dir/flags.make

CMakeFiles/set1.dir/main.cc.o: CMakeFiles/set1.dir/flags.make
CMakeFiles/set1.dir/main.cc.o: ../main.cc
CMakeFiles/set1.dir/main.cc.o: CMakeFiles/set1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cdper/repos/cpp3/w1/channa/01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/set1.dir/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/set1.dir/main.cc.o -MF CMakeFiles/set1.dir/main.cc.o.d -o CMakeFiles/set1.dir/main.cc.o -c /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/main.cc

CMakeFiles/set1.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/set1.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/main.cc > CMakeFiles/set1.dir/main.cc.i

CMakeFiles/set1.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/set1.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/main.cc -o CMakeFiles/set1.dir/main.cc.s

CMakeFiles/set1.dir/sourceFun1.cc.o: CMakeFiles/set1.dir/flags.make
CMakeFiles/set1.dir/sourceFun1.cc.o: ../sourceFun1.cc
CMakeFiles/set1.dir/sourceFun1.cc.o: CMakeFiles/set1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cdper/repos/cpp3/w1/channa/01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/set1.dir/sourceFun1.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/set1.dir/sourceFun1.cc.o -MF CMakeFiles/set1.dir/sourceFun1.cc.o.d -o CMakeFiles/set1.dir/sourceFun1.cc.o -c /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/sourceFun1.cc

CMakeFiles/set1.dir/sourceFun1.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/set1.dir/sourceFun1.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/sourceFun1.cc > CMakeFiles/set1.dir/sourceFun1.cc.i

CMakeFiles/set1.dir/sourceFun1.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/set1.dir/sourceFun1.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/sourceFun1.cc -o CMakeFiles/set1.dir/sourceFun1.cc.s

CMakeFiles/set1.dir/sourceFun2.cc.o: CMakeFiles/set1.dir/flags.make
CMakeFiles/set1.dir/sourceFun2.cc.o: ../sourceFun2.cc
CMakeFiles/set1.dir/sourceFun2.cc.o: CMakeFiles/set1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/cdper/repos/cpp3/w1/channa/01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/set1.dir/sourceFun2.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/set1.dir/sourceFun2.cc.o -MF CMakeFiles/set1.dir/sourceFun2.cc.o.d -o CMakeFiles/set1.dir/sourceFun2.cc.o -c /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/sourceFun2.cc

CMakeFiles/set1.dir/sourceFun2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/set1.dir/sourceFun2.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/sourceFun2.cc > CMakeFiles/set1.dir/sourceFun2.cc.i

CMakeFiles/set1.dir/sourceFun2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/set1.dir/sourceFun2.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/sourceFun2.cc -o CMakeFiles/set1.dir/sourceFun2.cc.s

# Object files for target set1
set1_OBJECTS = \
"CMakeFiles/set1.dir/main.cc.o" \
"CMakeFiles/set1.dir/sourceFun1.cc.o" \
"CMakeFiles/set1.dir/sourceFun2.cc.o"

# External object files for target set1
set1_EXTERNAL_OBJECTS =

set1: CMakeFiles/set1.dir/main.cc.o
set1: CMakeFiles/set1.dir/sourceFun1.cc.o
set1: CMakeFiles/set1.dir/sourceFun2.cc.o
set1: CMakeFiles/set1.dir/build.make
set1: CMakeFiles/set1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/cdper/repos/cpp3/w1/channa/01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable set1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/set1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/set1.dir/build: set1
.PHONY : CMakeFiles/set1.dir/build

CMakeFiles/set1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/set1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/set1.dir/clean

CMakeFiles/set1.dir/depend:
	cd /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/cdper/repos/cpp3/w1/channa/01 /mnt/c/Users/cdper/repos/cpp3/w1/channa/01 /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/cmake-build-debug /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/cmake-build-debug /mnt/c/Users/cdper/repos/cpp3/w1/channa/01/cmake-build-debug/CMakeFiles/set1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/set1.dir/depend
