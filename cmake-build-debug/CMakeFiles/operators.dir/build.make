# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/usr/prog/C_C++/operators

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/usr/prog/C_C++/operators/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/operators.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/operators.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/operators.dir/flags.make

CMakeFiles/operators.dir/main.cpp.o: CMakeFiles/operators.dir/flags.make
CMakeFiles/operators.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/usr/prog/C_C++/operators/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/operators.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/operators.dir/main.cpp.o -c /Users/usr/prog/C_C++/operators/main.cpp

CMakeFiles/operators.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/operators.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/usr/prog/C_C++/operators/main.cpp > CMakeFiles/operators.dir/main.cpp.i

CMakeFiles/operators.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/operators.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/usr/prog/C_C++/operators/main.cpp -o CMakeFiles/operators.dir/main.cpp.s

CMakeFiles/operators.dir/src/file_io.cpp.o: CMakeFiles/operators.dir/flags.make
CMakeFiles/operators.dir/src/file_io.cpp.o: ../src/file_io.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/usr/prog/C_C++/operators/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/operators.dir/src/file_io.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/operators.dir/src/file_io.cpp.o -c /Users/usr/prog/C_C++/operators/src/file_io.cpp

CMakeFiles/operators.dir/src/file_io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/operators.dir/src/file_io.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/usr/prog/C_C++/operators/src/file_io.cpp > CMakeFiles/operators.dir/src/file_io.cpp.i

CMakeFiles/operators.dir/src/file_io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/operators.dir/src/file_io.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/usr/prog/C_C++/operators/src/file_io.cpp -o CMakeFiles/operators.dir/src/file_io.cpp.s

# Object files for target operators
operators_OBJECTS = \
"CMakeFiles/operators.dir/main.cpp.o" \
"CMakeFiles/operators.dir/src/file_io.cpp.o"

# External object files for target operators
operators_EXTERNAL_OBJECTS =

operators: CMakeFiles/operators.dir/main.cpp.o
operators: CMakeFiles/operators.dir/src/file_io.cpp.o
operators: CMakeFiles/operators.dir/build.make
operators: /opt/homebrew/Cellar/jsoncpp/1.9.4_1/lib/libjsoncpp.24.dylib
operators: /opt/homebrew/Cellar/jsoncpp/1.9.4_1/lib/libjsoncpp.dylib
operators: /usr/local/lib/libyaml-cpp.a
operators: CMakeFiles/operators.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/usr/prog/C_C++/operators/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable operators"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/operators.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/operators.dir/build: operators

.PHONY : CMakeFiles/operators.dir/build

CMakeFiles/operators.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/operators.dir/cmake_clean.cmake
.PHONY : CMakeFiles/operators.dir/clean

CMakeFiles/operators.dir/depend:
	cd /Users/usr/prog/C_C++/operators/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/usr/prog/C_C++/operators /Users/usr/prog/C_C++/operators /Users/usr/prog/C_C++/operators/cmake-build-debug /Users/usr/prog/C_C++/operators/cmake-build-debug /Users/usr/prog/C_C++/operators/cmake-build-debug/CMakeFiles/operators.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/operators.dir/depend

