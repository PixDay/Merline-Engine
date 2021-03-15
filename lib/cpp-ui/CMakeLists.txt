project(cpp-ui VERSION 1.0.0.0 LANGUAGES CXX)

set(LIB_NAME cpp-ui)

add_library(${LIB_NAME} STATIC 
    ui.cpp
)

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIB_NAME} PUBLIC sfml-system sfml-graphics sfml-window)