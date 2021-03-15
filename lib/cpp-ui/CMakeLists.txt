project(cpp-ui VERSION 1.0.0.0 LANGUAGES CXX)

add_library(cpp-ui STATIC "")

target_sources(cpp-ui 
    PUBLIC
    ui.hpp

    PRIVATE
    ui.cpp
)

target_include_directories(cpp-ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(cpp-ui PUBLIC sfml-system sfml-graphics sfml-window sfml-audio)