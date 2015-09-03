project("SeanEngine" CXX C)
cmake_minimum_required(VERSION 3.1.0)
cmake_policy(VERSION 3.1.0)

# Name of the executable
set(EXENAME ${CMAKE_PROJECT_NAME})
# Name of the directory
set(DIRNAME "SeanEngine")


# Avoid source tree pollution
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
	message(FATAL_ERROR "In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files already created:\nrm -rf CMakeCache.txt CMakeFiles")
endif()

# Add a sensible build type default and warning because empty means no optimization and no debug info.
if (NOT CMAKE_BUILD_TYPE)
	message("WARNING: CMAKE_BUILD_TYPE is not defined!\n         Defaulting to CMAKE_BUILD_TYPE=RelWithDebInfo.\n         Use ccmake to set a proper value.")
	SET(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

if (WIN32)
	set(SHARE_INSTALL "." CACHE STRING "Data file install path. Must be a relative path (from CMAKE_INSTALL_PREFIX), with no trailing slash.")
else (WIN32)
	if(NOT SHARE_INSTALL)
		set(SHARE_INSTALL "share/games/${DIRNAME}" CACHE STRING "Data file install path. Must be a relative path (from CMAKE_INSTALL_PREFIX), with no trailing slash.")
	endif(NOT SHARE_INSTALL)
endif (WIN32)
mark_as_advanced(SHARE_INSTALL)

# Set default compile flags for GCC
if (CMAKE_COMPILER_IS_GNUCXX)
	message(STATUS "GCC detected, adding compile flags")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Find all the libs that don't require extra parameters
foreach(lib Box2D SDL2 SOIL OpenGL GLEW)
	find_package(${lib} REQUIRED)
	include_directories(${${lib}_INCLUDE_DIRS})
	list(APPEND LIBS ${${lib}_LIBRARIES})
	add_definitions(${${lib}_DEFINITIONS})
endforeach(lib)

# Gather sources
file(GLOB SOURCE_FILES "src/*.cpp")
file(GLOB HEADER_FILES "src/*.h")

set(SOURCES ${SOURCE_FILES} ${HEADER_FILES})

# Executable
add_executable(${EXENAME} ${SOURCES})
target_link_libraries(${EXENAME} ${LIBS})
target_link_libraries(${EXENAME} glew32s.lib)

#File management
file(COPY testAssets DESTINATION ${CMAKE_BINARY_DIR})

if (WIN32)
	file(GLOB DLL_FILES "bin/*.dll")
	file(GLOB SCRIPT_FILES "bin/*.bat")
	install(FILES ${DLL_FILES} ${SCRIPT_FILES} DESTINATION bin)
endif(WIN32)

