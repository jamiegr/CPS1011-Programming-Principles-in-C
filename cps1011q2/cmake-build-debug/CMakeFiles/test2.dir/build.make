# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011q2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011q2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/test2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test2.dir/flags.make

CMakeFiles/test2.dir/test.c.obj: CMakeFiles/test2.dir/flags.make
CMakeFiles/test2.dir/test.c.obj: ../test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011q2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test2.dir/test.c.obj"
	G:\WinBuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test2.dir\test.c.obj   -c "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011q2\test.c"

CMakeFiles/test2.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test2.dir/test.c.i"
	G:\WinBuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011q2\test.c" > CMakeFiles\test2.dir\test.c.i

CMakeFiles/test2.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test2.dir/test.c.s"
	G:\WinBuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011q2\test.c" -o CMakeFiles\test2.dir\test.c.s

CMakeFiles/test2.dir/test.c.obj.requires:

.PHONY : CMakeFiles/test2.dir/test.c.obj.requires

CMakeFiles/test2.dir/test.c.obj.provides: CMakeFiles/test2.dir/test.c.obj.requires
	$(MAKE) -f CMakeFiles\test2.dir\build.make CMakeFiles/test2.dir/test.c.obj.provides.build
.PHONY : CMakeFiles/test2.dir/test.c.obj.provides

CMakeFiles/test2.dir/test.c.obj.provides.build: CMakeFiles/test2.dir/test.c.obj


# Object files for target test2
test2_OBJECTS = \
"CMakeFiles/test2.dir/test.c.obj"

# External object files for target test2
test2_EXTERNAL_OBJECTS =

test2.exe: CMakeFiles/test2.dir/test.c.obj
test2.exe: CMakeFiles/test2.dir/build.make
test2.exe: libhashtable2.dll.a
test2.exe: CMakeFiles/test2.dir/linklibs.rsp
test2.exe: CMakeFiles/test2.dir/objects1.rsp
test2.exe: CMakeFiles/test2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011q2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test2.dir/build: test2.exe

.PHONY : CMakeFiles/test2.dir/build

CMakeFiles/test2.dir/requires: CMakeFiles/test2.dir/test.c.obj.requires

.PHONY : CMakeFiles/test2.dir/requires

CMakeFiles/test2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test2.dir/clean

CMakeFiles/test2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011q2" "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011q2" "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011q2\cmake-build-debug" "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011q2\cmake-build-debug" "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011q2\cmake-build-debug\CMakeFiles\test2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test2.dir/depend
