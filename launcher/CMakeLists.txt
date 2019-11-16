set(SRC
	launcher.cpp
)

add_executable(launcher ${SRC})
target_include_directories(launcher PUBLIC ${CMAKE_SOURCE_DIR}/public)
common_bin(launcher)