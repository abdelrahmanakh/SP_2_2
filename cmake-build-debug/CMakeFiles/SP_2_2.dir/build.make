# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /snap/clion/265/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/265/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/media/pg_mazen/Programming/Github Projects/SP_2_2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/pg_mazen/Programming/Github Projects/SP_2_2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/SP_2_2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SP_2_2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SP_2_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SP_2_2.dir/flags.make

CMakeFiles/SP_2_2.dir/main.cpp.o: CMakeFiles/SP_2_2.dir/flags.make
CMakeFiles/SP_2_2.dir/main.cpp.o: /media/pg_mazen/Programming/Github\ Projects/SP_2_2/main.cpp
CMakeFiles/SP_2_2.dir/main.cpp.o: CMakeFiles/SP_2_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/media/pg_mazen/Programming/Github Projects/SP_2_2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SP_2_2.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SP_2_2.dir/main.cpp.o -MF CMakeFiles/SP_2_2.dir/main.cpp.o.d -o CMakeFiles/SP_2_2.dir/main.cpp.o -c "/media/pg_mazen/Programming/Github Projects/SP_2_2/main.cpp"

CMakeFiles/SP_2_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SP_2_2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/pg_mazen/Programming/Github Projects/SP_2_2/main.cpp" > CMakeFiles/SP_2_2.dir/main.cpp.i

CMakeFiles/SP_2_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SP_2_2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/pg_mazen/Programming/Github Projects/SP_2_2/main.cpp" -o CMakeFiles/SP_2_2.dir/main.cpp.s

# Object files for target SP_2_2
SP_2_2_OBJECTS = \
"CMakeFiles/SP_2_2.dir/main.cpp.o"

# External object files for target SP_2_2
SP_2_2_EXTERNAL_OBJECTS =

SP_2_2: CMakeFiles/SP_2_2.dir/main.cpp.o
SP_2_2: CMakeFiles/SP_2_2.dir/build.make
SP_2_2: CMakeFiles/SP_2_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/media/pg_mazen/Programming/Github Projects/SP_2_2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SP_2_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SP_2_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SP_2_2.dir/build: SP_2_2
.PHONY : CMakeFiles/SP_2_2.dir/build

CMakeFiles/SP_2_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SP_2_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SP_2_2.dir/clean

CMakeFiles/SP_2_2.dir/depend:
	cd "/media/pg_mazen/Programming/Github Projects/SP_2_2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/pg_mazen/Programming/Github Projects/SP_2_2" "/media/pg_mazen/Programming/Github Projects/SP_2_2" "/media/pg_mazen/Programming/Github Projects/SP_2_2/cmake-build-debug" "/media/pg_mazen/Programming/Github Projects/SP_2_2/cmake-build-debug" "/media/pg_mazen/Programming/Github Projects/SP_2_2/cmake-build-debug/CMakeFiles/SP_2_2.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/SP_2_2.dir/depend

