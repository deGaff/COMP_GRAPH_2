# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "E:\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/COMP_GRAPHICS_2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/COMP_GRAPHICS_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/COMP_GRAPHICS_2.dir/flags.make

CMakeFiles/COMP_GRAPHICS_2.dir/main.cpp.obj: CMakeFiles/COMP_GRAPHICS_2.dir/flags.make
CMakeFiles/COMP_GRAPHICS_2.dir/main.cpp.obj: CMakeFiles/COMP_GRAPHICS_2.dir/includes_CXX.rsp
CMakeFiles/COMP_GRAPHICS_2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/COMP_GRAPHICS_2.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\COMP_GRAPHICS_2.dir\main.cpp.obj -c "E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2\main.cpp"

CMakeFiles/COMP_GRAPHICS_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/COMP_GRAPHICS_2.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2\main.cpp" > CMakeFiles\COMP_GRAPHICS_2.dir\main.cpp.i

CMakeFiles/COMP_GRAPHICS_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/COMP_GRAPHICS_2.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2\main.cpp" -o CMakeFiles\COMP_GRAPHICS_2.dir\main.cpp.s

CMakeFiles/COMP_GRAPHICS_2.dir/b_spline.cpp.obj: CMakeFiles/COMP_GRAPHICS_2.dir/flags.make
CMakeFiles/COMP_GRAPHICS_2.dir/b_spline.cpp.obj: CMakeFiles/COMP_GRAPHICS_2.dir/includes_CXX.rsp
CMakeFiles/COMP_GRAPHICS_2.dir/b_spline.cpp.obj: ../b_spline.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/COMP_GRAPHICS_2.dir/b_spline.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\COMP_GRAPHICS_2.dir\b_spline.cpp.obj -c "E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2\b_spline.cpp"

CMakeFiles/COMP_GRAPHICS_2.dir/b_spline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/COMP_GRAPHICS_2.dir/b_spline.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2\b_spline.cpp" > CMakeFiles\COMP_GRAPHICS_2.dir\b_spline.cpp.i

CMakeFiles/COMP_GRAPHICS_2.dir/b_spline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/COMP_GRAPHICS_2.dir/b_spline.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2\b_spline.cpp" -o CMakeFiles\COMP_GRAPHICS_2.dir\b_spline.cpp.s

# Object files for target COMP_GRAPHICS_2
COMP_GRAPHICS_2_OBJECTS = \
"CMakeFiles/COMP_GRAPHICS_2.dir/main.cpp.obj" \
"CMakeFiles/COMP_GRAPHICS_2.dir/b_spline.cpp.obj"

# External object files for target COMP_GRAPHICS_2
COMP_GRAPHICS_2_EXTERNAL_OBJECTS =

COMP_GRAPHICS_2.exe: CMakeFiles/COMP_GRAPHICS_2.dir/main.cpp.obj
COMP_GRAPHICS_2.exe: CMakeFiles/COMP_GRAPHICS_2.dir/b_spline.cpp.obj
COMP_GRAPHICS_2.exe: CMakeFiles/COMP_GRAPHICS_2.dir/build.make
COMP_GRAPHICS_2.exe: C:/SFML/lib/libsfml-system-d.a
COMP_GRAPHICS_2.exe: C:/SFML/lib/libsfml-window-d.a
COMP_GRAPHICS_2.exe: C:/SFML/lib/libsfml-graphics-d.a
COMP_GRAPHICS_2.exe: CMakeFiles/COMP_GRAPHICS_2.dir/linklibs.rsp
COMP_GRAPHICS_2.exe: CMakeFiles/COMP_GRAPHICS_2.dir/objects1.rsp
COMP_GRAPHICS_2.exe: CMakeFiles/COMP_GRAPHICS_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable COMP_GRAPHICS_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\COMP_GRAPHICS_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/COMP_GRAPHICS_2.dir/build: COMP_GRAPHICS_2.exe
.PHONY : CMakeFiles/COMP_GRAPHICS_2.dir/build

CMakeFiles/COMP_GRAPHICS_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\COMP_GRAPHICS_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/COMP_GRAPHICS_2.dir/clean

CMakeFiles/COMP_GRAPHICS_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2" "E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2" "E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2\cmake-build-debug" "E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2\cmake-build-debug" "E:\Stud\6 sem\Comp Graphics\COMP_GRAPHICS_2\cmake-build-debug\CMakeFiles\COMP_GRAPHICS_2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/COMP_GRAPHICS_2.dir/depend

