# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /home/ale/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/ale/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ale/Downloads/Projeto_FTGaming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ale/Downloads/Projeto_FTGaming/build

# Include any dependencies generated for this target.
include CMakeFiles/Projeto_FTGaming.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Projeto_FTGaming.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projeto_FTGaming.dir/flags.make

CMakeFiles/Projeto_FTGaming.dir/cliente.c.o: CMakeFiles/Projeto_FTGaming.dir/flags.make
CMakeFiles/Projeto_FTGaming.dir/cliente.c.o: ../cliente.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ale/Downloads/Projeto_FTGaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Projeto_FTGaming.dir/cliente.c.o"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Projeto_FTGaming.dir/cliente.c.o -c /home/ale/Downloads/Projeto_FTGaming/cliente.c

CMakeFiles/Projeto_FTGaming.dir/cliente.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projeto_FTGaming.dir/cliente.c.i"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ale/Downloads/Projeto_FTGaming/cliente.c > CMakeFiles/Projeto_FTGaming.dir/cliente.c.i

CMakeFiles/Projeto_FTGaming.dir/cliente.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projeto_FTGaming.dir/cliente.c.s"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ale/Downloads/Projeto_FTGaming/cliente.c -o CMakeFiles/Projeto_FTGaming.dir/cliente.c.s

CMakeFiles/Projeto_FTGaming.dir/interface.c.o: CMakeFiles/Projeto_FTGaming.dir/flags.make
CMakeFiles/Projeto_FTGaming.dir/interface.c.o: ../interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ale/Downloads/Projeto_FTGaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Projeto_FTGaming.dir/interface.c.o"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Projeto_FTGaming.dir/interface.c.o -c /home/ale/Downloads/Projeto_FTGaming/interface.c

CMakeFiles/Projeto_FTGaming.dir/interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projeto_FTGaming.dir/interface.c.i"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ale/Downloads/Projeto_FTGaming/interface.c > CMakeFiles/Projeto_FTGaming.dir/interface.c.i

CMakeFiles/Projeto_FTGaming.dir/interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projeto_FTGaming.dir/interface.c.s"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ale/Downloads/Projeto_FTGaming/interface.c -o CMakeFiles/Projeto_FTGaming.dir/interface.c.s

CMakeFiles/Projeto_FTGaming.dir/main.c.o: CMakeFiles/Projeto_FTGaming.dir/flags.make
CMakeFiles/Projeto_FTGaming.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ale/Downloads/Projeto_FTGaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Projeto_FTGaming.dir/main.c.o"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Projeto_FTGaming.dir/main.c.o -c /home/ale/Downloads/Projeto_FTGaming/main.c

CMakeFiles/Projeto_FTGaming.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projeto_FTGaming.dir/main.c.i"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ale/Downloads/Projeto_FTGaming/main.c > CMakeFiles/Projeto_FTGaming.dir/main.c.i

CMakeFiles/Projeto_FTGaming.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projeto_FTGaming.dir/main.c.s"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ale/Downloads/Projeto_FTGaming/main.c -o CMakeFiles/Projeto_FTGaming.dir/main.c.s

CMakeFiles/Projeto_FTGaming.dir/produto.c.o: CMakeFiles/Projeto_FTGaming.dir/flags.make
CMakeFiles/Projeto_FTGaming.dir/produto.c.o: ../produto.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ale/Downloads/Projeto_FTGaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Projeto_FTGaming.dir/produto.c.o"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Projeto_FTGaming.dir/produto.c.o -c /home/ale/Downloads/Projeto_FTGaming/produto.c

CMakeFiles/Projeto_FTGaming.dir/produto.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projeto_FTGaming.dir/produto.c.i"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ale/Downloads/Projeto_FTGaming/produto.c > CMakeFiles/Projeto_FTGaming.dir/produto.c.i

CMakeFiles/Projeto_FTGaming.dir/produto.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projeto_FTGaming.dir/produto.c.s"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ale/Downloads/Projeto_FTGaming/produto.c -o CMakeFiles/Projeto_FTGaming.dir/produto.c.s

CMakeFiles/Projeto_FTGaming.dir/venda.c.o: CMakeFiles/Projeto_FTGaming.dir/flags.make
CMakeFiles/Projeto_FTGaming.dir/venda.c.o: ../venda.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ale/Downloads/Projeto_FTGaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Projeto_FTGaming.dir/venda.c.o"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Projeto_FTGaming.dir/venda.c.o -c /home/ale/Downloads/Projeto_FTGaming/venda.c

CMakeFiles/Projeto_FTGaming.dir/venda.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Projeto_FTGaming.dir/venda.c.i"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ale/Downloads/Projeto_FTGaming/venda.c > CMakeFiles/Projeto_FTGaming.dir/venda.c.i

CMakeFiles/Projeto_FTGaming.dir/venda.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Projeto_FTGaming.dir/venda.c.s"
	/bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ale/Downloads/Projeto_FTGaming/venda.c -o CMakeFiles/Projeto_FTGaming.dir/venda.c.s

# Object files for target Projeto_FTGaming
Projeto_FTGaming_OBJECTS = \
"CMakeFiles/Projeto_FTGaming.dir/cliente.c.o" \
"CMakeFiles/Projeto_FTGaming.dir/interface.c.o" \
"CMakeFiles/Projeto_FTGaming.dir/main.c.o" \
"CMakeFiles/Projeto_FTGaming.dir/produto.c.o" \
"CMakeFiles/Projeto_FTGaming.dir/venda.c.o"

# External object files for target Projeto_FTGaming
Projeto_FTGaming_EXTERNAL_OBJECTS =

Projeto_FTGaming: CMakeFiles/Projeto_FTGaming.dir/cliente.c.o
Projeto_FTGaming: CMakeFiles/Projeto_FTGaming.dir/interface.c.o
Projeto_FTGaming: CMakeFiles/Projeto_FTGaming.dir/main.c.o
Projeto_FTGaming: CMakeFiles/Projeto_FTGaming.dir/produto.c.o
Projeto_FTGaming: CMakeFiles/Projeto_FTGaming.dir/venda.c.o
Projeto_FTGaming: CMakeFiles/Projeto_FTGaming.dir/build.make
Projeto_FTGaming: CMakeFiles/Projeto_FTGaming.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ale/Downloads/Projeto_FTGaming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable Projeto_FTGaming"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Projeto_FTGaming.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projeto_FTGaming.dir/build: Projeto_FTGaming

.PHONY : CMakeFiles/Projeto_FTGaming.dir/build

CMakeFiles/Projeto_FTGaming.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Projeto_FTGaming.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Projeto_FTGaming.dir/clean

CMakeFiles/Projeto_FTGaming.dir/depend:
	cd /home/ale/Downloads/Projeto_FTGaming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ale/Downloads/Projeto_FTGaming /home/ale/Downloads/Projeto_FTGaming /home/ale/Downloads/Projeto_FTGaming/build /home/ale/Downloads/Projeto_FTGaming/build /home/ale/Downloads/Projeto_FTGaming/build/CMakeFiles/Projeto_FTGaming.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Projeto_FTGaming.dir/depend

