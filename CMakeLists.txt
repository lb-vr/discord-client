######################################################
# discord-client
# : CMakeLists.txt
# : Author: lb-vr (Shirao Shotaro)
# : MIT-LICENSE
######################################################
cmake_minimum_required(VERSION 3.8)

# Project
project("discord-client")

### Project Settings
if(UNIX) # for Linux
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

elseif(WIN32) # for Windows
    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

endif(UNIX)

### Filter Settings for Visual Studio
# Build the visual studio filter same as source directories form.
function(assign_source_group)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            file(RELATIVE_PATH _source_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source}")
        else()
            set(_source_rel "${_source}")
        endif()
        get_filename_component(_source_path "${_source_rel}" PATH)
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
        source_group("${_source_path_msvc}" FILES "${_source}")
        message(STATUS "add source : ${_source}")
    endforeach()
endfunction(assign_source_group)

# add include
include_directories(include)

# add library
## Source Files
file(GLOB_RECURSE discord_client_sources src/discord-client/*.cpp)
file(GLOB_RECURSE discord_client_headers include/discord-client/*.hpp)
add_library(discord-client STATIC ${discord_client_sources} ${discord_client_headers})
assign_source_group(${discord_client_sources})
assign_source_group(${discord_client_headers})

# add subdirectory
message(STATUS "add subdirectory : src/discord-client-test")
add_subdirectory(src/discord-client-test)

# For Multi Platform
if(UNIX) # for Linux

elseif(WIN32) # for Windows
	
    # Source code are treated as UTF-8 (Must to use UTF-8 BOM)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /source-charset:utf-8")

endif(UNIX)

