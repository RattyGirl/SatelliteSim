# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Programming\Cpp\SatelliteSimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Programming\Cpp\SatelliteSimulator\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SatelliteSimulator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SatelliteSimulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SatelliteSimulator.dir/flags.make

CMakeFiles/SatelliteSimulator.dir/src/main.cpp.obj: CMakeFiles/SatelliteSimulator.dir/flags.make
CMakeFiles/SatelliteSimulator.dir/src/main.cpp.obj: CMakeFiles/SatelliteSimulator.dir/includes_CXX.rsp
CMakeFiles/SatelliteSimulator.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Programming\Cpp\SatelliteSimulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SatelliteSimulator.dir/src/main.cpp.obj"
	"E:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SatelliteSimulator.dir\src\main.cpp.obj -c F:\Programming\Cpp\SatelliteSimulator\src\main.cpp

CMakeFiles/SatelliteSimulator.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SatelliteSimulator.dir/src/main.cpp.i"
	"E:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Programming\Cpp\SatelliteSimulator\src\main.cpp > CMakeFiles\SatelliteSimulator.dir\src\main.cpp.i

CMakeFiles/SatelliteSimulator.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SatelliteSimulator.dir/src/main.cpp.s"
	"E:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Programming\Cpp\SatelliteSimulator\src\main.cpp -o CMakeFiles\SatelliteSimulator.dir\src\main.cpp.s

CMakeFiles/SatelliteSimulator.dir/src/Game.cpp.obj: CMakeFiles/SatelliteSimulator.dir/flags.make
CMakeFiles/SatelliteSimulator.dir/src/Game.cpp.obj: CMakeFiles/SatelliteSimulator.dir/includes_CXX.rsp
CMakeFiles/SatelliteSimulator.dir/src/Game.cpp.obj: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Programming\Cpp\SatelliteSimulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SatelliteSimulator.dir/src/Game.cpp.obj"
	"E:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SatelliteSimulator.dir\src\Game.cpp.obj -c F:\Programming\Cpp\SatelliteSimulator\src\Game.cpp

CMakeFiles/SatelliteSimulator.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SatelliteSimulator.dir/src/Game.cpp.i"
	"E:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Programming\Cpp\SatelliteSimulator\src\Game.cpp > CMakeFiles\SatelliteSimulator.dir\src\Game.cpp.i

CMakeFiles/SatelliteSimulator.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SatelliteSimulator.dir/src/Game.cpp.s"
	"E:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Programming\Cpp\SatelliteSimulator\src\Game.cpp -o CMakeFiles\SatelliteSimulator.dir\src\Game.cpp.s

CMakeFiles/SatelliteSimulator.dir/libs/glad/src/gl.c.obj: CMakeFiles/SatelliteSimulator.dir/flags.make
CMakeFiles/SatelliteSimulator.dir/libs/glad/src/gl.c.obj: CMakeFiles/SatelliteSimulator.dir/includes_C.rsp
CMakeFiles/SatelliteSimulator.dir/libs/glad/src/gl.c.obj: ../libs/glad/src/gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Programming\Cpp\SatelliteSimulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/SatelliteSimulator.dir/libs/glad/src/gl.c.obj"
	"E:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SatelliteSimulator.dir\libs\glad\src\gl.c.obj   -c F:\Programming\Cpp\SatelliteSimulator\libs\glad\src\gl.c

CMakeFiles/SatelliteSimulator.dir/libs/glad/src/gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SatelliteSimulator.dir/libs/glad/src/gl.c.i"
	"E:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Programming\Cpp\SatelliteSimulator\libs\glad\src\gl.c > CMakeFiles\SatelliteSimulator.dir\libs\glad\src\gl.c.i

CMakeFiles/SatelliteSimulator.dir/libs/glad/src/gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SatelliteSimulator.dir/libs/glad/src/gl.c.s"
	"E:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Programming\Cpp\SatelliteSimulator\libs\glad\src\gl.c -o CMakeFiles\SatelliteSimulator.dir\libs\glad\src\gl.c.s

CMakeFiles/SatelliteSimulator.dir/src/utils/ShaderProgram.cpp.obj: CMakeFiles/SatelliteSimulator.dir/flags.make
CMakeFiles/SatelliteSimulator.dir/src/utils/ShaderProgram.cpp.obj: CMakeFiles/SatelliteSimulator.dir/includes_CXX.rsp
CMakeFiles/SatelliteSimulator.dir/src/utils/ShaderProgram.cpp.obj: ../src/utils/ShaderProgram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Programming\Cpp\SatelliteSimulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SatelliteSimulator.dir/src/utils/ShaderProgram.cpp.obj"
	"E:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SatelliteSimulator.dir\src\utils\ShaderProgram.cpp.obj -c F:\Programming\Cpp\SatelliteSimulator\src\utils\ShaderProgram.cpp

CMakeFiles/SatelliteSimulator.dir/src/utils/ShaderProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SatelliteSimulator.dir/src/utils/ShaderProgram.cpp.i"
	"E:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Programming\Cpp\SatelliteSimulator\src\utils\ShaderProgram.cpp > CMakeFiles\SatelliteSimulator.dir\src\utils\ShaderProgram.cpp.i

CMakeFiles/SatelliteSimulator.dir/src/utils/ShaderProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SatelliteSimulator.dir/src/utils/ShaderProgram.cpp.s"
	"E:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Programming\Cpp\SatelliteSimulator\src\utils\ShaderProgram.cpp -o CMakeFiles\SatelliteSimulator.dir\src\utils\ShaderProgram.cpp.s

# Object files for target SatelliteSimulator
SatelliteSimulator_OBJECTS = \
"CMakeFiles/SatelliteSimulator.dir/src/main.cpp.obj" \
"CMakeFiles/SatelliteSimulator.dir/src/Game.cpp.obj" \
"CMakeFiles/SatelliteSimulator.dir/libs/glad/src/gl.c.obj" \
"CMakeFiles/SatelliteSimulator.dir/src/utils/ShaderProgram.cpp.obj"

# External object files for target SatelliteSimulator
SatelliteSimulator_EXTERNAL_OBJECTS =

../build/SatelliteSimulator.exe: CMakeFiles/SatelliteSimulator.dir/src/main.cpp.obj
../build/SatelliteSimulator.exe: CMakeFiles/SatelliteSimulator.dir/src/Game.cpp.obj
../build/SatelliteSimulator.exe: CMakeFiles/SatelliteSimulator.dir/libs/glad/src/gl.c.obj
../build/SatelliteSimulator.exe: CMakeFiles/SatelliteSimulator.dir/src/utils/ShaderProgram.cpp.obj
../build/SatelliteSimulator.exe: CMakeFiles/SatelliteSimulator.dir/build.make
../build/SatelliteSimulator.exe: libs/glfw-3.3.4/src/libglfw3.a
../build/SatelliteSimulator.exe: CMakeFiles/SatelliteSimulator.dir/linklibs.rsp
../build/SatelliteSimulator.exe: CMakeFiles/SatelliteSimulator.dir/objects1.rsp
../build/SatelliteSimulator.exe: CMakeFiles/SatelliteSimulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Programming\Cpp\SatelliteSimulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ..\build\SatelliteSimulator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SatelliteSimulator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SatelliteSimulator.dir/build: ../build/SatelliteSimulator.exe

.PHONY : CMakeFiles/SatelliteSimulator.dir/build

CMakeFiles/SatelliteSimulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SatelliteSimulator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SatelliteSimulator.dir/clean

CMakeFiles/SatelliteSimulator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Programming\Cpp\SatelliteSimulator F:\Programming\Cpp\SatelliteSimulator F:\Programming\Cpp\SatelliteSimulator\cmake-build-debug F:\Programming\Cpp\SatelliteSimulator\cmake-build-debug F:\Programming\Cpp\SatelliteSimulator\cmake-build-debug\CMakeFiles\SatelliteSimulator.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SatelliteSimulator.dir/depend
