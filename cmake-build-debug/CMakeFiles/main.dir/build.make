# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/billyin/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/203.7717.62/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/billyin/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/203.7717.62/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/main.cxx.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cxx.o: ../src/main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/main.cxx.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/main.cxx.o -c "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/main.cxx"

CMakeFiles/main.dir/src/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cxx.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/main.cxx" > CMakeFiles/main.dir/src/main.cxx.i

CMakeFiles/main.dir/src/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cxx.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/main.cxx" -o CMakeFiles/main.dir/src/main.cxx.s

CMakeFiles/main.dir/src/view.cxx.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/view.cxx.o: ../src/view.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/view.cxx.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/view.cxx.o -c "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/view.cxx"

CMakeFiles/main.dir/src/view.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/view.cxx.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/view.cxx" > CMakeFiles/main.dir/src/view.cxx.i

CMakeFiles/main.dir/src/view.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/view.cxx.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/view.cxx" -o CMakeFiles/main.dir/src/view.cxx.s

CMakeFiles/main.dir/src/controller.cxx.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/controller.cxx.o: ../src/controller.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/controller.cxx.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/controller.cxx.o -c "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/controller.cxx"

CMakeFiles/main.dir/src/controller.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/controller.cxx.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/controller.cxx" > CMakeFiles/main.dir/src/controller.cxx.i

CMakeFiles/main.dir/src/controller.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/controller.cxx.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/controller.cxx" -o CMakeFiles/main.dir/src/controller.cxx.s

CMakeFiles/main.dir/src/model.cxx.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/model.cxx.o: ../src/model.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/model.cxx.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/model.cxx.o -c "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/model.cxx"

CMakeFiles/main.dir/src/model.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/model.cxx.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/model.cxx" > CMakeFiles/main.dir/src/model.cxx.i

CMakeFiles/main.dir/src/model.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/model.cxx.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/model.cxx" -o CMakeFiles/main.dir/src/model.cxx.s

CMakeFiles/main.dir/src/bird.cxx.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/bird.cxx.o: ../src/bird.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/bird.cxx.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/bird.cxx.o -c "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/bird.cxx"

CMakeFiles/main.dir/src/bird.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/bird.cxx.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/bird.cxx" > CMakeFiles/main.dir/src/bird.cxx.i

CMakeFiles/main.dir/src/bird.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/bird.cxx.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/bird.cxx" -o CMakeFiles/main.dir/src/bird.cxx.s

CMakeFiles/main.dir/src/pipe.cxx.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/pipe.cxx.o: ../src/pipe.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/src/pipe.cxx.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/pipe.cxx.o -c "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/pipe.cxx"

CMakeFiles/main.dir/src/pipe.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/pipe.cxx.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/pipe.cxx" > CMakeFiles/main.dir/src/pipe.cxx.i

CMakeFiles/main.dir/src/pipe.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/pipe.cxx.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/pipe.cxx" -o CMakeFiles/main.dir/src/pipe.cxx.s

CMakeFiles/main.dir/src/powerups.cxx.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/powerups.cxx.o: ../src/powerups.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/src/powerups.cxx.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/powerups.cxx.o -c "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/powerups.cxx"

CMakeFiles/main.dir/src/powerups.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/powerups.cxx.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/powerups.cxx" > CMakeFiles/main.dir/src/powerups.cxx.i

CMakeFiles/main.dir/src/powerups.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/powerups.cxx.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/powerups.cxx" -o CMakeFiles/main.dir/src/powerups.cxx.s

CMakeFiles/main.dir/src/game_config.cxx.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/game_config.cxx.o: ../src/game_config.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/src/game_config.cxx.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/game_config.cxx.o -c "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/game_config.cxx"

CMakeFiles/main.dir/src/game_config.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/game_config.cxx.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/game_config.cxx" > CMakeFiles/main.dir/src/game_config.cxx.i

CMakeFiles/main.dir/src/game_config.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/game_config.cxx.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/src/game_config.cxx" -o CMakeFiles/main.dir/src/game_config.cxx.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.cxx.o" \
"CMakeFiles/main.dir/src/view.cxx.o" \
"CMakeFiles/main.dir/src/controller.cxx.o" \
"CMakeFiles/main.dir/src/model.cxx.o" \
"CMakeFiles/main.dir/src/bird.cxx.o" \
"CMakeFiles/main.dir/src/pipe.cxx.o" \
"CMakeFiles/main.dir/src/powerups.cxx.o" \
"CMakeFiles/main.dir/src/game_config.cxx.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/main.cxx.o
main: CMakeFiles/main.dir/src/view.cxx.o
main: CMakeFiles/main.dir/src/controller.cxx.o
main: CMakeFiles/main.dir/src/model.cxx.o
main: CMakeFiles/main.dir/src/bird.cxx.o
main: CMakeFiles/main.dir/src/pipe.cxx.o
main: CMakeFiles/main.dir/src/powerups.cxx.o
main: CMakeFiles/main.dir/src/game_config.cxx.o
main: CMakeFiles/main.dir/build.make
main: .cs211/lib/ge211/src/libge211.a
main: /usr/local/lib/libSDL2.dylib
main: /usr/local/lib/libSDL2_image.dylib
main: /usr/local/lib/libSDL2_mixer.dylib
main: /usr/local/lib/libSDL2_ttf.dylib
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project" "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project" "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug" "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug" "/Users/billyin/Documents/College/Courses/Freshmen/2021 Q3 Spring/CS 211/Final Project/final_project/cmake-build-debug/CMakeFiles/main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

