CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT("find_linker_issues")

SET(CMAKE_BUILD_TYPE Debug)

### *** Qt stuff ***

# find include files in corresponding build directories (MOC outputs, mainly)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)

### *** end Qt stuff ***

### build a list of DLLs to be copied over for runtime use
set(RunTimeFiles)

add_library( test_lib1 STATIC
			 TestLibrary1.cpp
			 )
qt5_use_modules(test_lib1 Core)

### set up the main application
add_executable(test_app main.cpp)
target_link_libraries(test_app test_lib1)
qt5_use_modules(test_app Core)

get_target_property(QtCore_location Qt5::Core LOCATION)
list(APPEND RunTimeFiles ${QtCore_location})

### copy over the runtime files
### Note:  This lets me run the app directly in the Debug folder created by VS
foreach(var_ ${RunTimeFiles})
    file( COPY ${var_} DESTINATION ${CMAKE_BINARY_DIR}/Debug )
endforeach()
