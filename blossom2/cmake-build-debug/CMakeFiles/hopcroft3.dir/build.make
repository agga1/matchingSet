# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\ProgramFilesD\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\ProgramFilesD\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\hopcroft3.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\hopcroft3.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\hopcroft3.dir\flags.make

CMakeFiles\hopcroft3.dir\hopcroft3.cpp.obj: CMakeFiles\hopcroft3.dir\flags.make
CMakeFiles\hopcroft3.dir\hopcroft3.cpp.obj: ..\hopcroft3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hopcroft3.dir/hopcroft3.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\hopcroft3.dir\hopcroft3.cpp.obj /FdCMakeFiles\hopcroft3.dir\ /FS -c C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\hopcroft3.cpp
<<

CMakeFiles\hopcroft3.dir\hopcroft3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hopcroft3.dir/hopcroft3.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\hopcroft3.dir\hopcroft3.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\hopcroft3.cpp
<<

CMakeFiles\hopcroft3.dir\hopcroft3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hopcroft3.dir/hopcroft3.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\hopcroft3.dir\hopcroft3.cpp.s /c C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\hopcroft3.cpp
<<

# Object files for target hopcroft3
hopcroft3_OBJECTS = \
"CMakeFiles\hopcroft3.dir\hopcroft3.cpp.obj"

# External object files for target hopcroft3
hopcroft3_EXTERNAL_OBJECTS =

hopcroft3.exe: CMakeFiles\hopcroft3.dir\hopcroft3.cpp.obj
hopcroft3.exe: CMakeFiles\hopcroft3.dir\build.make
hopcroft3.exe: CMakeFiles\hopcroft3.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hopcroft3.exe"
	"D:\ProgramFilesD\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\hopcroft3.dir --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\hopcroft3.dir\objects1.rsp @<<
 /out:hopcroft3.exe /implib:hopcroft3.lib /pdb:C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\hopcroft3.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\hopcroft3.dir\build: hopcroft3.exe

.PHONY : CMakeFiles\hopcroft3.dir\build

CMakeFiles\hopcroft3.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hopcroft3.dir\cmake_clean.cmake
.PHONY : CMakeFiles\hopcroft3.dir\clean

CMakeFiles\hopcroft3.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2 C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2 C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\CMakeFiles\hopcroft3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\hopcroft3.dir\depend

