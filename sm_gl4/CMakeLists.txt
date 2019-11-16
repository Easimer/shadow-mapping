set(SRC
	gfx_init.cpp
)

add_library(sm SHARED ${SRC})
target_include_directories(sm PRIVATE ${CMAKE_SOURCE_DIR}/public)
target_link_libraries(sm SDL2)
common_bin(sm)

# Link SDL2
list(FILTER SDL2_LIBRARIES EXCLUDE REGEX SDL2main)
set(LIBS ${SDL2_LIBRARIES})
if(UNIX AND NOT APPLE)
	set(LIBS ${LIBS} dl rt)
endif()
target_link_libraries(sm ${LIBS})
target_include_directories(sm PRIVATE ${SDL2_INCLUDE_DIRS})