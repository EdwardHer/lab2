# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/edward/ludwin/lab2/teblero2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/edward/ludwin/lab2/teblero2/build

# Include any dependencies generated for this target.
include CMakeFiles/tablero.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tablero.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tablero.dir/flags.make

CMakeFiles/tablero.dir/main.cpp.o: CMakeFiles/tablero.dir/flags.make
CMakeFiles/tablero.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/edward/ludwin/lab2/teblero2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/tablero.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tablero.dir/main.cpp.o -c /home/edward/ludwin/lab2/teblero2/main.cpp

CMakeFiles/tablero.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tablero.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/edward/ludwin/lab2/teblero2/main.cpp > CMakeFiles/tablero.dir/main.cpp.i

CMakeFiles/tablero.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tablero.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/edward/ludwin/lab2/teblero2/main.cpp -o CMakeFiles/tablero.dir/main.cpp.s

CMakeFiles/tablero.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/tablero.dir/main.cpp.o.requires

CMakeFiles/tablero.dir/main.cpp.o.provides: CMakeFiles/tablero.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/tablero.dir/build.make CMakeFiles/tablero.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/tablero.dir/main.cpp.o.provides

CMakeFiles/tablero.dir/main.cpp.o.provides.build: CMakeFiles/tablero.dir/main.cpp.o

# Object files for target tablero
tablero_OBJECTS = \
"CMakeFiles/tablero.dir/main.cpp.o"

# External object files for target tablero
tablero_EXTERNAL_OBJECTS =

tablero: CMakeFiles/tablero.dir/main.cpp.o
tablero: CMakeFiles/tablero.dir/build.make
tablero: /usr/lib/x86_64-linux-gnu/libGLU.so
tablero: /usr/lib/x86_64-linux-gnu/libGL.so
tablero: /usr/lib/x86_64-linux-gnu/libSM.so
tablero: /usr/lib/x86_64-linux-gnu/libICE.so
tablero: /usr/lib/x86_64-linux-gnu/libX11.so
tablero: /usr/lib/x86_64-linux-gnu/libXext.so
tablero: /usr/lib/x86_64-linux-gnu/libglut.so
tablero: /usr/lib/x86_64-linux-gnu/libXmu.so
tablero: /usr/lib/x86_64-linux-gnu/libXi.so
tablero: CMakeFiles/tablero.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable tablero"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tablero.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tablero.dir/build: tablero
.PHONY : CMakeFiles/tablero.dir/build

CMakeFiles/tablero.dir/requires: CMakeFiles/tablero.dir/main.cpp.o.requires
.PHONY : CMakeFiles/tablero.dir/requires

CMakeFiles/tablero.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tablero.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tablero.dir/clean

CMakeFiles/tablero.dir/depend:
	cd /home/edward/ludwin/lab2/teblero2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/edward/ludwin/lab2/teblero2 /home/edward/ludwin/lab2/teblero2 /home/edward/ludwin/lab2/teblero2/build /home/edward/ludwin/lab2/teblero2/build /home/edward/ludwin/lab2/teblero2/build/CMakeFiles/tablero.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tablero.dir/depend

