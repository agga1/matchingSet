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
include CMakeFiles\hopcroft.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\hopcroft.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\hopcroft.dir\flags.make

CMakeFiles\hopcroft.dir\hopcroft.cpp.obj: CMakeFiles\hopcroft.dir\flags.make
CMakeFiles\hopcroft.dir\hopcroft.cpp.obj: ..\hopcroft.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hopcroft.dir/hopcroft.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\hopcroft.dir\hopcroft.cpp.obj /FdCMakeFiles\hopcroft.dir\ /FS -c C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\hopcroft.cpp
<<

CMakeFiles\hopcroft.dir\hopcroft.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hopcroft.dir/hopcroft.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\hopcroft.dir\hopcroft.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\hopcroft.cpp
<<

CMakeFiles\hopcroft.dir\hopcroft.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hopcroft.dir/hopcroft.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\hopcroft.dir\hopcroft.cpp.s /c C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\hopcroft.cpp
<<

# Object files for target hopcroft
hopcroft_OBJECTS = \
"CMakeFiles\hopcroft.dir\hopcroft.cpp.obj"

# External object files for target hopcroft
hopcroft_EXTERNAL_OBJECTS =

hopcroft.exe: CMakeFiles\hopcroft.dir\hopcroft.cpp.obj
hopcroft.exe: CMakeFiles\hopcroft.dir\build.make
hopcroft.exe: CMakeFiles\hopcroft.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hopcroft.exe"
	"D:\ProgramFilesD\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\hopcroft.dir --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\hopcroft.dir\objects1.rsp @<<
 /out:hopcroft.exe /implib:hopcroft.lib /pdb:C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\hopcroft.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\hopcroft.dir\build: hopcroft.exe

.PHONY : CMakeFiles\hopcroft.dir\build

CMakeFiles\hopcroft.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hopcroft.dir\cmake_clean.cmake
.PHONY : CMakeFiles\hopcroft.dir\clean

CMakeFiles\hopcroft.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2 C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2 C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\CMakeFiles\hopcroft.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\hopcroft.dir\depend

