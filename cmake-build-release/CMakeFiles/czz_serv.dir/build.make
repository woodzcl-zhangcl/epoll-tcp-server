# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/zhangcl/Clion/clion-2018.2.6/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zhangcl/Clion/clion-2018.2.6/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhangcl/czz_serv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhangcl/czz_serv/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/czz_serv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/czz_serv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/czz_serv.dir/flags.make

CMakeFiles/czz_serv.dir/main.cpp.o: CMakeFiles/czz_serv.dir/flags.make
CMakeFiles/czz_serv.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangcl/czz_serv/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/czz_serv.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/czz_serv.dir/main.cpp.o -c /home/zhangcl/czz_serv/main.cpp

CMakeFiles/czz_serv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/czz_serv.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangcl/czz_serv/main.cpp > CMakeFiles/czz_serv.dir/main.cpp.i

CMakeFiles/czz_serv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/czz_serv.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangcl/czz_serv/main.cpp -o CMakeFiles/czz_serv.dir/main.cpp.s

CMakeFiles/czz_serv.dir/prxml.cpp.o: CMakeFiles/czz_serv.dir/flags.make
CMakeFiles/czz_serv.dir/prxml.cpp.o: ../prxml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangcl/czz_serv/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/czz_serv.dir/prxml.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/czz_serv.dir/prxml.cpp.o -c /home/zhangcl/czz_serv/prxml.cpp

CMakeFiles/czz_serv.dir/prxml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/czz_serv.dir/prxml.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangcl/czz_serv/prxml.cpp > CMakeFiles/czz_serv.dir/prxml.cpp.i

CMakeFiles/czz_serv.dir/prxml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/czz_serv.dir/prxml.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangcl/czz_serv/prxml.cpp -o CMakeFiles/czz_serv.dir/prxml.cpp.s

CMakeFiles/czz_serv.dir/thpool.cpp.o: CMakeFiles/czz_serv.dir/flags.make
CMakeFiles/czz_serv.dir/thpool.cpp.o: ../thpool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangcl/czz_serv/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/czz_serv.dir/thpool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/czz_serv.dir/thpool.cpp.o -c /home/zhangcl/czz_serv/thpool.cpp

CMakeFiles/czz_serv.dir/thpool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/czz_serv.dir/thpool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangcl/czz_serv/thpool.cpp > CMakeFiles/czz_serv.dir/thpool.cpp.i

CMakeFiles/czz_serv.dir/thpool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/czz_serv.dir/thpool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangcl/czz_serv/thpool.cpp -o CMakeFiles/czz_serv.dir/thpool.cpp.s

CMakeFiles/czz_serv.dir/tcpserv.cpp.o: CMakeFiles/czz_serv.dir/flags.make
CMakeFiles/czz_serv.dir/tcpserv.cpp.o: ../tcpserv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangcl/czz_serv/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/czz_serv.dir/tcpserv.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/czz_serv.dir/tcpserv.cpp.o -c /home/zhangcl/czz_serv/tcpserv.cpp

CMakeFiles/czz_serv.dir/tcpserv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/czz_serv.dir/tcpserv.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangcl/czz_serv/tcpserv.cpp > CMakeFiles/czz_serv.dir/tcpserv.cpp.i

CMakeFiles/czz_serv.dir/tcpserv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/czz_serv.dir/tcpserv.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangcl/czz_serv/tcpserv.cpp -o CMakeFiles/czz_serv.dir/tcpserv.cpp.s

CMakeFiles/czz_serv.dir/userdeal.cpp.o: CMakeFiles/czz_serv.dir/flags.make
CMakeFiles/czz_serv.dir/userdeal.cpp.o: ../userdeal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangcl/czz_serv/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/czz_serv.dir/userdeal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/czz_serv.dir/userdeal.cpp.o -c /home/zhangcl/czz_serv/userdeal.cpp

CMakeFiles/czz_serv.dir/userdeal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/czz_serv.dir/userdeal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangcl/czz_serv/userdeal.cpp > CMakeFiles/czz_serv.dir/userdeal.cpp.i

CMakeFiles/czz_serv.dir/userdeal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/czz_serv.dir/userdeal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangcl/czz_serv/userdeal.cpp -o CMakeFiles/czz_serv.dir/userdeal.cpp.s

CMakeFiles/czz_serv.dir/protocol.cpp.o: CMakeFiles/czz_serv.dir/flags.make
CMakeFiles/czz_serv.dir/protocol.cpp.o: ../protocol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangcl/czz_serv/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/czz_serv.dir/protocol.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/czz_serv.dir/protocol.cpp.o -c /home/zhangcl/czz_serv/protocol.cpp

CMakeFiles/czz_serv.dir/protocol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/czz_serv.dir/protocol.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangcl/czz_serv/protocol.cpp > CMakeFiles/czz_serv.dir/protocol.cpp.i

CMakeFiles/czz_serv.dir/protocol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/czz_serv.dir/protocol.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangcl/czz_serv/protocol.cpp -o CMakeFiles/czz_serv.dir/protocol.cpp.s

CMakeFiles/czz_serv.dir/prmysql.cpp.o: CMakeFiles/czz_serv.dir/flags.make
CMakeFiles/czz_serv.dir/prmysql.cpp.o: ../prmysql.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangcl/czz_serv/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/czz_serv.dir/prmysql.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/czz_serv.dir/prmysql.cpp.o -c /home/zhangcl/czz_serv/prmysql.cpp

CMakeFiles/czz_serv.dir/prmysql.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/czz_serv.dir/prmysql.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangcl/czz_serv/prmysql.cpp > CMakeFiles/czz_serv.dir/prmysql.cpp.i

CMakeFiles/czz_serv.dir/prmysql.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/czz_serv.dir/prmysql.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangcl/czz_serv/prmysql.cpp -o CMakeFiles/czz_serv.dir/prmysql.cpp.s

# Object files for target czz_serv
czz_serv_OBJECTS = \
"CMakeFiles/czz_serv.dir/main.cpp.o" \
"CMakeFiles/czz_serv.dir/prxml.cpp.o" \
"CMakeFiles/czz_serv.dir/thpool.cpp.o" \
"CMakeFiles/czz_serv.dir/tcpserv.cpp.o" \
"CMakeFiles/czz_serv.dir/userdeal.cpp.o" \
"CMakeFiles/czz_serv.dir/protocol.cpp.o" \
"CMakeFiles/czz_serv.dir/prmysql.cpp.o"

# External object files for target czz_serv
czz_serv_EXTERNAL_OBJECTS =

czz_serv: CMakeFiles/czz_serv.dir/main.cpp.o
czz_serv: CMakeFiles/czz_serv.dir/prxml.cpp.o
czz_serv: CMakeFiles/czz_serv.dir/thpool.cpp.o
czz_serv: CMakeFiles/czz_serv.dir/tcpserv.cpp.o
czz_serv: CMakeFiles/czz_serv.dir/userdeal.cpp.o
czz_serv: CMakeFiles/czz_serv.dir/protocol.cpp.o
czz_serv: CMakeFiles/czz_serv.dir/prmysql.cpp.o
czz_serv: CMakeFiles/czz_serv.dir/build.make
czz_serv: CMakeFiles/czz_serv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhangcl/czz_serv/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable czz_serv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/czz_serv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/czz_serv.dir/build: czz_serv

.PHONY : CMakeFiles/czz_serv.dir/build

CMakeFiles/czz_serv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/czz_serv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/czz_serv.dir/clean

CMakeFiles/czz_serv.dir/depend:
	cd /home/zhangcl/czz_serv/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhangcl/czz_serv /home/zhangcl/czz_serv /home/zhangcl/czz_serv/cmake-build-release /home/zhangcl/czz_serv/cmake-build-release /home/zhangcl/czz_serv/cmake-build-release/CMakeFiles/czz_serv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/czz_serv.dir/depend

