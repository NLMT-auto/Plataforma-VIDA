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
CMAKE_COMMAND = /snap/cmake/1088/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1088/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lmt/Documentos/Plataforma-VIDA/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lmt/Documentos/Plataforma-VIDA/build

# Include any dependencies generated for this target.
include CMakeFiles/vida.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/vida.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/vida.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vida.dir/flags.make

CMakeFiles/vida.dir/Containers/Control/Control.cpp.o: CMakeFiles/vida.dir/flags.make
CMakeFiles/vida.dir/Containers/Control/Control.cpp.o: /home/lmt/Documentos/Plataforma-VIDA/src/Containers/Control/Control.cpp
CMakeFiles/vida.dir/Containers/Control/Control.cpp.o: CMakeFiles/vida.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lmt/Documentos/Plataforma-VIDA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vida.dir/Containers/Control/Control.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vida.dir/Containers/Control/Control.cpp.o -MF CMakeFiles/vida.dir/Containers/Control/Control.cpp.o.d -o CMakeFiles/vida.dir/Containers/Control/Control.cpp.o -c /home/lmt/Documentos/Plataforma-VIDA/src/Containers/Control/Control.cpp

CMakeFiles/vida.dir/Containers/Control/Control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vida.dir/Containers/Control/Control.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lmt/Documentos/Plataforma-VIDA/src/Containers/Control/Control.cpp > CMakeFiles/vida.dir/Containers/Control/Control.cpp.i

CMakeFiles/vida.dir/Containers/Control/Control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vida.dir/Containers/Control/Control.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lmt/Documentos/Plataforma-VIDA/src/Containers/Control/Control.cpp -o CMakeFiles/vida.dir/Containers/Control/Control.cpp.s

CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.o: CMakeFiles/vida.dir/flags.make
CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.o: /home/lmt/Documentos/Plataforma-VIDA/src/Utils/PosixShMem/PosixShMem.cpp
CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.o: CMakeFiles/vida.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lmt/Documentos/Plataforma-VIDA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.o -MF CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.o.d -o CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.o -c /home/lmt/Documentos/Plataforma-VIDA/src/Utils/PosixShMem/PosixShMem.cpp

CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lmt/Documentos/Plataforma-VIDA/src/Utils/PosixShMem/PosixShMem.cpp > CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.i

CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lmt/Documentos/Plataforma-VIDA/src/Utils/PosixShMem/PosixShMem.cpp -o CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.s

CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.o: CMakeFiles/vida.dir/flags.make
CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.o: /home/lmt/Documentos/Plataforma-VIDA/src/Utils/ThreadBase/ThreadBase.cpp
CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.o: CMakeFiles/vida.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lmt/Documentos/Plataforma-VIDA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.o -MF CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.o.d -o CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.o -c /home/lmt/Documentos/Plataforma-VIDA/src/Utils/ThreadBase/ThreadBase.cpp

CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lmt/Documentos/Plataforma-VIDA/src/Utils/ThreadBase/ThreadBase.cpp > CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.i

CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lmt/Documentos/Plataforma-VIDA/src/Utils/ThreadBase/ThreadBase.cpp -o CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.s

CMakeFiles/vida.dir/main.cpp.o: CMakeFiles/vida.dir/flags.make
CMakeFiles/vida.dir/main.cpp.o: /home/lmt/Documentos/Plataforma-VIDA/src/main.cpp
CMakeFiles/vida.dir/main.cpp.o: CMakeFiles/vida.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lmt/Documentos/Plataforma-VIDA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/vida.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/vida.dir/main.cpp.o -MF CMakeFiles/vida.dir/main.cpp.o.d -o CMakeFiles/vida.dir/main.cpp.o -c /home/lmt/Documentos/Plataforma-VIDA/src/main.cpp

CMakeFiles/vida.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vida.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lmt/Documentos/Plataforma-VIDA/src/main.cpp > CMakeFiles/vida.dir/main.cpp.i

CMakeFiles/vida.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vida.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lmt/Documentos/Plataforma-VIDA/src/main.cpp -o CMakeFiles/vida.dir/main.cpp.s

# Object files for target vida
vida_OBJECTS = \
"CMakeFiles/vida.dir/Containers/Control/Control.cpp.o" \
"CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.o" \
"CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.o" \
"CMakeFiles/vida.dir/main.cpp.o"

# External object files for target vida
vida_EXTERNAL_OBJECTS =

vida: CMakeFiles/vida.dir/Containers/Control/Control.cpp.o
vida: CMakeFiles/vida.dir/Utils/PosixShMem/PosixShMem.cpp.o
vida: CMakeFiles/vida.dir/Utils/ThreadBase/ThreadBase.cpp.o
vida: CMakeFiles/vida.dir/main.cpp.o
vida: CMakeFiles/vida.dir/build.make
vida: CMakeFiles/vida.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lmt/Documentos/Plataforma-VIDA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable vida"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vida.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vida.dir/build: vida
.PHONY : CMakeFiles/vida.dir/build

CMakeFiles/vida.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vida.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vida.dir/clean

CMakeFiles/vida.dir/depend:
	cd /home/lmt/Documentos/Plataforma-VIDA/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lmt/Documentos/Plataforma-VIDA/src /home/lmt/Documentos/Plataforma-VIDA/src /home/lmt/Documentos/Plataforma-VIDA/build /home/lmt/Documentos/Plataforma-VIDA/build /home/lmt/Documentos/Plataforma-VIDA/build/CMakeFiles/vida.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vida.dir/depend

