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
include CMakeFiles\blossom2.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\blossom2.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\blossom2.dir\flags.make

CMakeFiles\blossom2.dir\main.cpp.obj: CMakeFiles\blossom2.dir\flags.make
CMakeFiles\blossom2.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/blossom2.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\blossom2.dir\main.cpp.obj /FdCMakeFiles\blossom2.dir\ /FS -c C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\main.cpp
<<

CMakeFiles\blossom2.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blossom2.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\blossom2.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\main.cpp
<<

CMakeFiles\blossom2.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blossom2.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\blossom2.dir\main.cpp.s /c C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\main.cpp
<<

CMakeFiles\blossom2.dir\hopcroft.cpp.obj: CMakeFiles\blossom2.dir\flags.make
CMakeFiles\blossom2.dir\hopcroft.cpp.obj: ..\hopcroft.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/blossom2.dir/hopcroft.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\blossom2.dir\hopcroft.cpp.obj /FdCMakeFiles\blossom2.dir\ /FS -c C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\hopcroft.cpp
<<

CMakeFiles\blossom2.dir\hopcroft.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blossom2.dir/hopcroft.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\blossom2.dir\hopcroft.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\hopcroft.cpp
<<

CMakeFiles\blossom2.dir\hopcroft.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blossom2.dir/hopcroft.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\blossom2.dir\hopcroft.cpp.s /c C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\hopcroft.cpp
<<

CMakeFiles\blossom2.dir\blossom.cpp.obj: CMakeFiles\blossom2.dir\flags.make
CMakeFiles\blossom2.dir\blossom.cpp.obj: ..\blossom.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/blossom2.dir/blossom.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\blossom2.dir\blossom.cpp.obj /FdCMakeFiles\blossom2.dir\ /FS -c C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\blossom.cpp
<<

CMakeFiles\blossom2.dir\blossom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blossom2.dir/blossom.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\blossom2.dir\blossom.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\blossom.cpp
<<

CMakeFiles\blossom2.dir\blossom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blossom2.dir/blossom.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\blossom2.dir\blossom.cpp.s /c C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\blossom.cpp
<<

# Object files for target blossom2
blossom2_OBJECTS = \
"CMakeFiles\blossom2.dir\main.cpp.obj" \
"CMakeFiles\blossom2.dir\hopcroft.cpp.obj" \
"CMakeFiles\blossom2.dir\blossom.cpp.obj"

# External object files for target blossom2
blossom2_EXTERNAL_OBJECTS =

blossom2.exe: CMakeFiles\blossom2.dir\main.cpp.obj
blossom2.exe: CMakeFiles\blossom2.dir\hopcroft.cpp.obj
blossom2.exe: CMakeFiles\blossom2.dir\blossom.cpp.obj
blossom2.exe: CMakeFiles\blossom2.dir\build.make
blossom2.exe: CMakeFiles\blossom2.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable blossom2.exe"
	"D:\ProgramFilesD\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\blossom2.dir --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\blossom2.dir\objects1.rsp @<<
 /out:blossom2.exe /implib:blossom2.lib /pdb:C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\blossom2.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\blossom2.dir\build: blossom2.exe

.PHONY : CMakeFiles\blossom2.dir\build

CMakeFiles\blossom2.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\blossom2.dir\cmake_clean.cmake
.PHONY : CMakeFiles\blossom2.dir\clean

CMakeFiles\blossom2.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2 C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2 C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug C:\Users\Agnieszka\Studia\AG\MatchingSetProject\blossom2\cmake-build-debug\CMakeFiles\blossom2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\blossom2.dir\depend

