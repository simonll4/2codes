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

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/simonll4/programs/CLion-2022.2.1/clion-2022.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/simonll4/programs/CLion-2022.2.1/clion-2022.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/simonll4/CLionProjects/2codes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/simonll4/CLionProjects/2codes/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Segmentaria.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Segmentaria.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Segmentaria.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Segmentaria.dir/flags.make

CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.o: CMakeFiles/Segmentaria.dir/flags.make
CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.o: ../metodos_numericos/interpolacion/segmentaria.cpp
CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.o: CMakeFiles/Segmentaria.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/simonll4/CLionProjects/2codes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.o -MF CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.o.d -o CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.o -c /home/simonll4/CLionProjects/2codes/metodos_numericos/interpolacion/segmentaria.cpp

CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/simonll4/CLionProjects/2codes/metodos_numericos/interpolacion/segmentaria.cpp > CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.i

CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/simonll4/CLionProjects/2codes/metodos_numericos/interpolacion/segmentaria.cpp -o CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.s

# Object files for target Segmentaria
Segmentaria_OBJECTS = \
"CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.o"

# External object files for target Segmentaria
Segmentaria_EXTERNAL_OBJECTS =

Segmentaria: CMakeFiles/Segmentaria.dir/metodos_numericos/interpolacion/segmentaria.cpp.o
Segmentaria: CMakeFiles/Segmentaria.dir/build.make
Segmentaria: CMakeFiles/Segmentaria.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/simonll4/CLionProjects/2codes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Segmentaria"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Segmentaria.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Segmentaria.dir/build: Segmentaria
.PHONY : CMakeFiles/Segmentaria.dir/build

CMakeFiles/Segmentaria.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Segmentaria.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Segmentaria.dir/clean

CMakeFiles/Segmentaria.dir/depend:
	cd /home/simonll4/CLionProjects/2codes/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/simonll4/CLionProjects/2codes /home/simonll4/CLionProjects/2codes /home/simonll4/CLionProjects/2codes/cmake-build-debug /home/simonll4/CLionProjects/2codes/cmake-build-debug /home/simonll4/CLionProjects/2codes/cmake-build-debug/CMakeFiles/Segmentaria.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Segmentaria.dir/depend
