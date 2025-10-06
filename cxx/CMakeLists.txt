project(scrave)
add_library(scrave_glyph src/glyph.c)
target_include_directories(scrave_glyph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)