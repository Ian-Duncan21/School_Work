# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /s/bach/c/under/iandunc/CS253/hw5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /s/bach/c/under/iandunc/CS253/hw5

# Utility rule file for hw5.tar.

# Include any custom commands dependencies for this target.
include CMakeFiles/hw5.tar.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hw5.tar.dir/progress.make

CMakeFiles/hw5.tar:
	tar -cf hw5.tar *.cc CMakeLists.txt

hw5.tar: CMakeFiles/hw5.tar
hw5.tar: CMakeFiles/hw5.tar.dir/build.make
.PHONY : hw5.tar

# Rule to build all files generated by this target.
CMakeFiles/hw5.tar.dir/build: hw5.tar
.PHONY : CMakeFiles/hw5.tar.dir/build

CMakeFiles/hw5.tar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw5.tar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw5.tar.dir/clean

CMakeFiles/hw5.tar.dir/depend:
	cd /s/bach/c/under/iandunc/CS253/hw5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /s/bach/c/under/iandunc/CS253/hw5 /s/bach/c/under/iandunc/CS253/hw5 /s/bach/c/under/iandunc/CS253/hw5 /s/bach/c/under/iandunc/CS253/hw5 /s/bach/c/under/iandunc/CS253/hw5/CMakeFiles/hw5.tar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw5.tar.dir/depend

