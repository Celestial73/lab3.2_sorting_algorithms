# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1\build

# Include any dependencies generated for this target.
include CMakeFiles/lab2_sorting_algorithms.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab2_sorting_algorithms.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab2_sorting_algorithms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab2_sorting_algorithms.dir/flags.make

CMakeFiles/lab2_sorting_algorithms.dir/main.cpp.obj: CMakeFiles/lab2_sorting_algorithms.dir/flags.make
CMakeFiles/lab2_sorting_algorithms.dir/main.cpp.obj: C:/Users/Michael/ROOT/MEPHI/sem3/labs/lab2_1/main.cpp
CMakeFiles/lab2_sorting_algorithms.dir/main.cpp.obj: CMakeFiles/lab2_sorting_algorithms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab2_sorting_algorithms.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab2_sorting_algorithms.dir/main.cpp.obj -MF CMakeFiles\lab2_sorting_algorithms.dir\main.cpp.obj.d -o CMakeFiles\lab2_sorting_algorithms.dir\main.cpp.obj -c C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1\main.cpp

CMakeFiles/lab2_sorting_algorithms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab2_sorting_algorithms.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1\main.cpp > CMakeFiles\lab2_sorting_algorithms.dir\main.cpp.i

CMakeFiles/lab2_sorting_algorithms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab2_sorting_algorithms.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1\main.cpp -o CMakeFiles\lab2_sorting_algorithms.dir\main.cpp.s

CMakeFiles/lab2_sorting_algorithms.dir/data/DataGenerator.cpp.obj: CMakeFiles/lab2_sorting_algorithms.dir/flags.make
CMakeFiles/lab2_sorting_algorithms.dir/data/DataGenerator.cpp.obj: C:/Users/Michael/ROOT/MEPHI/sem3/labs/lab2_1/data/DataGenerator.cpp
CMakeFiles/lab2_sorting_algorithms.dir/data/DataGenerator.cpp.obj: CMakeFiles/lab2_sorting_algorithms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab2_sorting_algorithms.dir/data/DataGenerator.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab2_sorting_algorithms.dir/data/DataGenerator.cpp.obj -MF CMakeFiles\lab2_sorting_algorithms.dir\data\DataGenerator.cpp.obj.d -o CMakeFiles\lab2_sorting_algorithms.dir\data\DataGenerator.cpp.obj -c C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1\data\DataGenerator.cpp

CMakeFiles/lab2_sorting_algorithms.dir/data/DataGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab2_sorting_algorithms.dir/data/DataGenerator.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1\data\DataGenerator.cpp > CMakeFiles\lab2_sorting_algorithms.dir\data\DataGenerator.cpp.i

CMakeFiles/lab2_sorting_algorithms.dir/data/DataGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab2_sorting_algorithms.dir/data/DataGenerator.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1\data\DataGenerator.cpp -o CMakeFiles\lab2_sorting_algorithms.dir\data\DataGenerator.cpp.s

# Object files for target lab2_sorting_algorithms
lab2_sorting_algorithms_OBJECTS = \
"CMakeFiles/lab2_sorting_algorithms.dir/main.cpp.obj" \
"CMakeFiles/lab2_sorting_algorithms.dir/data/DataGenerator.cpp.obj"

# External object files for target lab2_sorting_algorithms
lab2_sorting_algorithms_EXTERNAL_OBJECTS =

lab2_sorting_algorithms.exe: CMakeFiles/lab2_sorting_algorithms.dir/main.cpp.obj
lab2_sorting_algorithms.exe: CMakeFiles/lab2_sorting_algorithms.dir/data/DataGenerator.cpp.obj
lab2_sorting_algorithms.exe: CMakeFiles/lab2_sorting_algorithms.dir/build.make
lab2_sorting_algorithms.exe: CMakeFiles/lab2_sorting_algorithms.dir/linkLibs.rsp
lab2_sorting_algorithms.exe: CMakeFiles/lab2_sorting_algorithms.dir/objects1.rsp
lab2_sorting_algorithms.exe: CMakeFiles/lab2_sorting_algorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab2_sorting_algorithms.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab2_sorting_algorithms.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab2_sorting_algorithms.dir/build: lab2_sorting_algorithms.exe
.PHONY : CMakeFiles/lab2_sorting_algorithms.dir/build

CMakeFiles/lab2_sorting_algorithms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab2_sorting_algorithms.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab2_sorting_algorithms.dir/clean

CMakeFiles/lab2_sorting_algorithms.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1 C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1 C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1\build C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1\build C:\Users\Michael\ROOT\MEPHI\sem3\labs\lab2_1\build\CMakeFiles\lab2_sorting_algorithms.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab2_sorting_algorithms.dir/depend

