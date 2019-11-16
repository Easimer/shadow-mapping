cmake_minimum_required(VERSION 3.10)
project(shadow_mapping)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(UNIX)
	set(CMAKE_C_FLAGS "-fPIC -fvisibility=hidden")
	set(CMAKE_CXX_FLAGS "-fPIC -fvisibility=hidden")
endif(UNIX)

macro(common_bin target)
	set_target_properties(${target}
		PROPERTIES
		LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/"
		LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/"
		LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/RelWithDebInfo/"
		LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_BINARY_DIR}/MinSizeRel/"
		RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/Debug/"
		RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/Release/"
		RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}/RelWithDebInfo/"
		RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_BINARY_DIR}/MinSizeRel/"
	)
endmacro()

# Enable all warnings
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall")
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic -mrdrnd -mfma -maes")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
if(WIN32)
	set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/third_party/SDL2-2.0.8/include")
	set(SDL2_DIR "${CMAKE_SOURCE_DIR}/third_party/SDL2-2.0.8/lib/x64")
	link_directories(${SDL2_DIR})
endif(WIN32)
find_package(SDL2 REQUIRED)

add_subdirectory(launcher)
add_subdirectory(sm_gl4)
