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
CMAKE_COMMAND = /cygdrive/c/Users/arina/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/arina/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/arina/CLionProjects/Sorts

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/arina/CLionProjects/Sorts/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Sorts.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sorts.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sorts.dir/flags.make

CMakeFiles/Sorts.dir/main.cpp.o: CMakeFiles/Sorts.dir/flags.make
CMakeFiles/Sorts.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/arina/CLionProjects/Sorts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sorts.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sorts.dir/main.cpp.o -c /cygdrive/c/Users/arina/CLionProjects/Sorts/main.cpp

CMakeFiles/Sorts.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sorts.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/arina/CLionProjects/Sorts/main.cpp > CMakeFiles/Sorts.dir/main.cpp.i

CMakeFiles/Sorts.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sorts.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/arina/CLionProjects/Sorts/main.cpp -o CMakeFiles/Sorts.dir/main.cpp.s

CMakeFiles/Sorts.dir/DynamicArray.cpp.o: CMakeFiles/Sorts.dir/flags.make
CMakeFiles/Sorts.dir/DynamicArray.cpp.o: ../DynamicArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/arina/CLionProjects/Sorts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Sorts.dir/DynamicArray.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sorts.dir/DynamicArray.cpp.o -c /cygdrive/c/Users/arina/CLionProjects/Sorts/DynamicArray.cpp

CMakeFiles/Sorts.dir/DynamicArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sorts.dir/DynamicArray.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/arina/CLionProjects/Sorts/DynamicArray.cpp > CMakeFiles/Sorts.dir/DynamicArray.cpp.i

CMakeFiles/Sorts.dir/DynamicArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sorts.dir/DynamicArray.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/arina/CLionProjects/Sorts/DynamicArray.cpp -o CMakeFiles/Sorts.dir/DynamicArray.cpp.s

CMakeFiles/Sorts.dir/LinkedList.cpp.o: CMakeFiles/Sorts.dir/flags.make
CMakeFiles/Sorts.dir/LinkedList.cpp.o: ../LinkedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/arina/CLionProjects/Sorts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Sorts.dir/LinkedList.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sorts.dir/LinkedList.cpp.o -c /cygdrive/c/Users/arina/CLionProjects/Sorts/LinkedList.cpp

CMakeFiles/Sorts.dir/LinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sorts.dir/LinkedList.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/arina/CLionProjects/Sorts/LinkedList.cpp > CMakeFiles/Sorts.dir/LinkedList.cpp.i

CMakeFiles/Sorts.dir/LinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sorts.dir/LinkedList.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/arina/CLionProjects/Sorts/LinkedList.cpp -o CMakeFiles/Sorts.dir/LinkedList.cpp.s

CMakeFiles/Sorts.dir/Sorts.cpp.o: CMakeFiles/Sorts.dir/flags.make
CMakeFiles/Sorts.dir/Sorts.cpp.o: ../Sorts.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/arina/CLionProjects/Sorts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Sorts.dir/Sorts.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sorts.dir/Sorts.cpp.o -c /cygdrive/c/Users/arina/CLionProjects/Sorts/Sorts.cpp

CMakeFiles/Sorts.dir/Sorts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sorts.dir/Sorts.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/arina/CLionProjects/Sorts/Sorts.cpp > CMakeFiles/Sorts.dir/Sorts.cpp.i

CMakeFiles/Sorts.dir/Sorts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sorts.dir/Sorts.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/arina/CLionProjects/Sorts/Sorts.cpp -o CMakeFiles/Sorts.dir/Sorts.cpp.s

# Object files for target Sorts
Sorts_OBJECTS = \
"CMakeFiles/Sorts.dir/main.cpp.o" \
"CMakeFiles/Sorts.dir/DynamicArray.cpp.o" \
"CMakeFiles/Sorts.dir/LinkedList.cpp.o" \
"CMakeFiles/Sorts.dir/Sorts.cpp.o"

# External object files for target Sorts
Sorts_EXTERNAL_OBJECTS =

Sorts.exe: CMakeFiles/Sorts.dir/main.cpp.o
Sorts.exe: CMakeFiles/Sorts.dir/DynamicArray.cpp.o
Sorts.exe: CMakeFiles/Sorts.dir/LinkedList.cpp.o
Sorts.exe: CMakeFiles/Sorts.dir/Sorts.cpp.o
Sorts.exe: CMakeFiles/Sorts.dir/build.make
Sorts.exe: CMakeFiles/Sorts.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/arina/CLionProjects/Sorts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Sorts.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sorts.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sorts.dir/build: Sorts.exe

.PHONY : CMakeFiles/Sorts.dir/build

CMakeFiles/Sorts.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Sorts.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Sorts.dir/clean

CMakeFiles/Sorts.dir/depend:
	cd /cygdrive/c/Users/arina/CLionProjects/Sorts/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/arina/CLionProjects/Sorts /cygdrive/c/Users/arina/CLionProjects/Sorts /cygdrive/c/Users/arina/CLionProjects/Sorts/cmake-build-debug /cygdrive/c/Users/arina/CLionProjects/Sorts/cmake-build-debug /cygdrive/c/Users/arina/CLionProjects/Sorts/cmake-build-debug/CMakeFiles/Sorts.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sorts.dir/depend

