# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mo/CLionProjects/algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mo/CLionProjects/algorithms/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/segtree_max_sub.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/segtree_max_sub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/segtree_max_sub.dir/flags.make

CMakeFiles/segtree_max_sub.dir/segment_tree_max_subarray.cpp.o: CMakeFiles/segtree_max_sub.dir/flags.make
CMakeFiles/segtree_max_sub.dir/segment_tree_max_subarray.cpp.o: ../segment_tree_max_subarray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mo/CLionProjects/algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/segtree_max_sub.dir/segment_tree_max_subarray.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/segtree_max_sub.dir/segment_tree_max_subarray.cpp.o -c /Users/mo/CLionProjects/algorithms/segment_tree_max_subarray.cpp

CMakeFiles/segtree_max_sub.dir/segment_tree_max_subarray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/segtree_max_sub.dir/segment_tree_max_subarray.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mo/CLionProjects/algorithms/segment_tree_max_subarray.cpp > CMakeFiles/segtree_max_sub.dir/segment_tree_max_subarray.cpp.i

CMakeFiles/segtree_max_sub.dir/segment_tree_max_subarray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/segtree_max_sub.dir/segment_tree_max_subarray.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mo/CLionProjects/algorithms/segment_tree_max_subarray.cpp -o CMakeFiles/segtree_max_sub.dir/segment_tree_max_subarray.cpp.s

CMakeFiles/segtree_max_sub.dir/segtree_max_sum.cpp.o: CMakeFiles/segtree_max_sub.dir/flags.make
CMakeFiles/segtree_max_sub.dir/segtree_max_sum.cpp.o: ../segtree_max_sum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mo/CLionProjects/algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/segtree_max_sub.dir/segtree_max_sum.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/segtree_max_sub.dir/segtree_max_sum.cpp.o -c /Users/mo/CLionProjects/algorithms/segtree_max_sum.cpp

CMakeFiles/segtree_max_sub.dir/segtree_max_sum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/segtree_max_sub.dir/segtree_max_sum.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mo/CLionProjects/algorithms/segtree_max_sum.cpp > CMakeFiles/segtree_max_sub.dir/segtree_max_sum.cpp.i

CMakeFiles/segtree_max_sub.dir/segtree_max_sum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/segtree_max_sub.dir/segtree_max_sum.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mo/CLionProjects/algorithms/segtree_max_sum.cpp -o CMakeFiles/segtree_max_sub.dir/segtree_max_sum.cpp.s

# Object files for target segtree_max_sub
segtree_max_sub_OBJECTS = \
"CMakeFiles/segtree_max_sub.dir/segment_tree_max_subarray.cpp.o" \
"CMakeFiles/segtree_max_sub.dir/segtree_max_sum.cpp.o"

# External object files for target segtree_max_sub
segtree_max_sub_EXTERNAL_OBJECTS =

segtree_max_sub: CMakeFiles/segtree_max_sub.dir/segment_tree_max_subarray.cpp.o
segtree_max_sub: CMakeFiles/segtree_max_sub.dir/segtree_max_sum.cpp.o
segtree_max_sub: CMakeFiles/segtree_max_sub.dir/build.make
segtree_max_sub: CMakeFiles/segtree_max_sub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mo/CLionProjects/algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable segtree_max_sub"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/segtree_max_sub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/segtree_max_sub.dir/build: segtree_max_sub

.PHONY : CMakeFiles/segtree_max_sub.dir/build

CMakeFiles/segtree_max_sub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/segtree_max_sub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/segtree_max_sub.dir/clean

CMakeFiles/segtree_max_sub.dir/depend:
	cd /Users/mo/CLionProjects/algorithms/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mo/CLionProjects/algorithms /Users/mo/CLionProjects/algorithms /Users/mo/CLionProjects/algorithms/cmake-build-debug /Users/mo/CLionProjects/algorithms/cmake-build-debug /Users/mo/CLionProjects/algorithms/cmake-build-debug/CMakeFiles/segtree_max_sub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/segtree_max_sub.dir/depend

