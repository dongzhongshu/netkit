# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\mywork\netkit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\mywork\netkit\cmake-build-debug

# Include any dependencies generated for this target.
include threadpool/CMakeFiles/netkit.dir/depend.make

# Include the progress variables for this target.
include threadpool/CMakeFiles/netkit.dir/progress.make

# Include the compile flags for this target's objects.
include threadpool/CMakeFiles/netkit.dir/flags.make

threadpool/CMakeFiles/netkit.dir/queue.c.obj: threadpool/CMakeFiles/netkit.dir/flags.make
threadpool/CMakeFiles/netkit.dir/queue.c.obj: ../threadpool/queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\mywork\netkit\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object threadpool/CMakeFiles/netkit.dir/queue.c.obj"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\netkit.dir\queue.c.obj   -c G:\mywork\netkit\threadpool\queue.c

threadpool/CMakeFiles/netkit.dir/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/netkit.dir/queue.c.i"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E G:\mywork\netkit\threadpool\queue.c > CMakeFiles\netkit.dir\queue.c.i

threadpool/CMakeFiles/netkit.dir/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/netkit.dir/queue.c.s"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S G:\mywork\netkit\threadpool\queue.c -o CMakeFiles\netkit.dir\queue.c.s

threadpool/CMakeFiles/netkit.dir/async_queue_cond.c.obj: threadpool/CMakeFiles/netkit.dir/flags.make
threadpool/CMakeFiles/netkit.dir/async_queue_cond.c.obj: ../threadpool/async_queue_cond.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\mywork\netkit\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object threadpool/CMakeFiles/netkit.dir/async_queue_cond.c.obj"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\netkit.dir\async_queue_cond.c.obj   -c G:\mywork\netkit\threadpool\async_queue_cond.c

threadpool/CMakeFiles/netkit.dir/async_queue_cond.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/netkit.dir/async_queue_cond.c.i"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E G:\mywork\netkit\threadpool\async_queue_cond.c > CMakeFiles\netkit.dir\async_queue_cond.c.i

threadpool/CMakeFiles/netkit.dir/async_queue_cond.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/netkit.dir/async_queue_cond.c.s"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S G:\mywork\netkit\threadpool\async_queue_cond.c -o CMakeFiles\netkit.dir\async_queue_cond.c.s

threadpool/CMakeFiles/netkit.dir/threadpool.c.obj: threadpool/CMakeFiles/netkit.dir/flags.make
threadpool/CMakeFiles/netkit.dir/threadpool.c.obj: ../threadpool/threadpool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\mywork\netkit\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object threadpool/CMakeFiles/netkit.dir/threadpool.c.obj"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\netkit.dir\threadpool.c.obj   -c G:\mywork\netkit\threadpool\threadpool.c

threadpool/CMakeFiles/netkit.dir/threadpool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/netkit.dir/threadpool.c.i"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E G:\mywork\netkit\threadpool\threadpool.c > CMakeFiles\netkit.dir\threadpool.c.i

threadpool/CMakeFiles/netkit.dir/threadpool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/netkit.dir/threadpool.c.s"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S G:\mywork\netkit\threadpool\threadpool.c -o CMakeFiles\netkit.dir\threadpool.c.s

threadpool/CMakeFiles/netkit.dir/main.c.obj: threadpool/CMakeFiles/netkit.dir/flags.make
threadpool/CMakeFiles/netkit.dir/main.c.obj: ../threadpool/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\mywork\netkit\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object threadpool/CMakeFiles/netkit.dir/main.c.obj"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\netkit.dir\main.c.obj   -c G:\mywork\netkit\threadpool\main.c

threadpool/CMakeFiles/netkit.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/netkit.dir/main.c.i"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E G:\mywork\netkit\threadpool\main.c > CMakeFiles\netkit.dir\main.c.i

threadpool/CMakeFiles/netkit.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/netkit.dir/main.c.s"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S G:\mywork\netkit\threadpool\main.c -o CMakeFiles\netkit.dir\main.c.s

threadpool/CMakeFiles/netkit.dir/async_queue_event.c.obj: threadpool/CMakeFiles/netkit.dir/flags.make
threadpool/CMakeFiles/netkit.dir/async_queue_event.c.obj: ../threadpool/async_queue_event.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\mywork\netkit\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object threadpool/CMakeFiles/netkit.dir/async_queue_event.c.obj"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\netkit.dir\async_queue_event.c.obj   -c G:\mywork\netkit\threadpool\async_queue_event.c

threadpool/CMakeFiles/netkit.dir/async_queue_event.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/netkit.dir/async_queue_event.c.i"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E G:\mywork\netkit\threadpool\async_queue_event.c > CMakeFiles\netkit.dir\async_queue_event.c.i

threadpool/CMakeFiles/netkit.dir/async_queue_event.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/netkit.dir/async_queue_event.c.s"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S G:\mywork\netkit\threadpool\async_queue_event.c -o CMakeFiles\netkit.dir\async_queue_event.c.s

# Object files for target netkit
netkit_OBJECTS = \
"CMakeFiles/netkit.dir/queue.c.obj" \
"CMakeFiles/netkit.dir/async_queue_cond.c.obj" \
"CMakeFiles/netkit.dir/threadpool.c.obj" \
"CMakeFiles/netkit.dir/main.c.obj" \
"CMakeFiles/netkit.dir/async_queue_event.c.obj"

# External object files for target netkit
netkit_EXTERNAL_OBJECTS =

threadpool/netkit.exe: threadpool/CMakeFiles/netkit.dir/queue.c.obj
threadpool/netkit.exe: threadpool/CMakeFiles/netkit.dir/async_queue_cond.c.obj
threadpool/netkit.exe: threadpool/CMakeFiles/netkit.dir/threadpool.c.obj
threadpool/netkit.exe: threadpool/CMakeFiles/netkit.dir/main.c.obj
threadpool/netkit.exe: threadpool/CMakeFiles/netkit.dir/async_queue_event.c.obj
threadpool/netkit.exe: threadpool/CMakeFiles/netkit.dir/build.make
threadpool/netkit.exe: threadpool/CMakeFiles/netkit.dir/linklibs.rsp
threadpool/netkit.exe: threadpool/CMakeFiles/netkit.dir/objects1.rsp
threadpool/netkit.exe: threadpool/CMakeFiles/netkit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\mywork\netkit\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable netkit.exe"
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\netkit.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
threadpool/CMakeFiles/netkit.dir/build: threadpool/netkit.exe

.PHONY : threadpool/CMakeFiles/netkit.dir/build

threadpool/CMakeFiles/netkit.dir/clean:
	cd /d G:\mywork\netkit\cmake-build-debug\threadpool && $(CMAKE_COMMAND) -P CMakeFiles\netkit.dir\cmake_clean.cmake
.PHONY : threadpool/CMakeFiles/netkit.dir/clean

threadpool/CMakeFiles/netkit.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\mywork\netkit G:\mywork\netkit\threadpool G:\mywork\netkit\cmake-build-debug G:\mywork\netkit\cmake-build-debug\threadpool G:\mywork\netkit\cmake-build-debug\threadpool\CMakeFiles\netkit.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : threadpool/CMakeFiles/netkit.dir/depend

