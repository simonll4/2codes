# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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

# a target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/simonll4/programs/CLion-2022.2.1/clion-2022.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/simonll4/programs/CLion-2022.2.1/clion-2022.2.1/bin/cmake/linux/bin/cmake -E rm -function

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/simonll4/CLionProjects/2codes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/simonll4/CLionProjects/2codes/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pelado.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pelado.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pelado.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pelado.dir/flags.make

CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.o: CMakeFiles/pelado.dir/flags.make
CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.o: ../metodos_numericos/interpolacion/pelado.c
CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.o: CMakeFiles/pelado.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simonll4/CLionProjects/2codes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.o -MF CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.o.d -o CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.o -c /home/simonll4/CLionProjects/2codes/metodos_numericos/interpolacion/pelado.c

CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/simonll4/CLionProjects/2codes/metodos_numericos/interpolacion/pelado.c > CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.i

CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/simonll4/CLionProjects/2codes/metodos_numericos/interpolacion/pelado.c -o CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.s

# Object files for target pelado
pelado_OBJECTS = \
"CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.o"

# External object files for target pelado
pelado_EXTERNAL_OBJECTS =

pelado: CMakeFiles/pelado.dir/metodos_numericos/interpolacion/pelado.c.o
pelado: CMakeFiles/pelado.dir/build.make
pelado: CMakeFiles/pelado.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/simonll4/CLionProjects/2codes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pelado"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pelado.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pelado.dir/build: pelado
.PHONY : CMakeFiles/pelado.dir/build

CMakeFiles/pelado.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pelado.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pelado.dir/clean

CMakeFiles/pelado.dir/depend:
	cd /home/simonll4/CLionProjects/2codes/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/simonll4/CLionProjects/2codes /home/simonll4/CLionProjects/2codes /home/simonll4/CLionProjects/2codes/cmake-build-debug /home/simonll4/CLionProjects/2codes/cmake-build-debug /home/simonll4/CLionProjects/2codes/cmake-build-debug/CMakeFiles/pelado.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pelado.dir/depend

