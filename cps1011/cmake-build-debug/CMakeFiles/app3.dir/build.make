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
CMAKE_SOURCE_DIR = "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/app3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/app3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app3.dir/flags.make

CMakeFiles/app3.dir/main3.c.obj: CMakeFiles/app3.dir/flags.make
CMakeFiles/app3.dir/main3.c.obj: ../main3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/app3.dir/main3.c.obj"
	G:\WinBuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\app3.dir\main3.c.obj   -c "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011\main3.c"

CMakeFiles/app3.dir/main3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app3.dir/main3.c.i"
	G:\WinBuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011\main3.c" > CMakeFiles\app3.dir\main3.c.i

CMakeFiles/app3.dir/main3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app3.dir/main3.c.s"
	G:\WinBuilds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011\main3.c" -o CMakeFiles\app3.dir\main3.c.s

CMakeFiles/app3.dir/main3.c.obj.requires:

.PHONY : CMakeFiles/app3.dir/main3.c.obj.requires

CMakeFiles/app3.dir/main3.c.obj.provides: CMakeFiles/app3.dir/main3.c.obj.requires
	$(MAKE) -f CMakeFiles\app3.dir\build.make CMakeFiles/app3.dir/main3.c.obj.provides.build
.PHONY : CMakeFiles/app3.dir/main3.c.obj.provides

CMakeFiles/app3.dir/main3.c.obj.provides.build: CMakeFiles/app3.dir/main3.c.obj


# Object files for target app3
app3_OBJECTS = \
"CMakeFiles/app3.dir/main3.c.obj"

# External object files for target app3
app3_EXTERNAL_OBJECTS =

app3.exe: CMakeFiles/app3.dir/main3.c.obj
app3.exe: CMakeFiles/app3.dir/build.make
app3.exe: CMakeFiles/app3.dir/linklibs.rsp
app3.exe: CMakeFiles/app3.dir/objects1.rsp
app3.exe: CMakeFiles/app3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable app3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\app3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app3.dir/build: app3.exe

.PHONY : CMakeFiles/app3.dir/build

CMakeFiles/app3.dir/requires: CMakeFiles/app3.dir/main3.c.obj.requires

.PHONY : CMakeFiles/app3.dir/requires

CMakeFiles/app3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\app3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/app3.dir/clean

CMakeFiles/app3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011" "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011" "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011\cmake-build-debug" "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011\cmake-build-debug" "C:\Users\Jamie\Desktop\Uni\CPS1011 - Programming Principles in C\cps1011\cmake-build-debug\CMakeFiles\app3.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/app3.dir/depend

