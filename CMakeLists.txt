cmake_minimum_required(VERSION 3.22)

project(gcore LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-save-temps)
add_compile_options(-Wall -Wextra -Werror)

add_definitions(-DGLEW_STATIC)

if(CMAKE_BUILD_TYPE MATCHES Release)
    add_compile_options(-O2)
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_options(-g)
endif()

add_library(${PROJECT_NAME}
    STATIC

    ${CMAKE_CURRENT_SOURCE_DIR}/src/gl/vertex_buffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gl/shader_program.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gl/render_state.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gl/element_buffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gl/gl_error.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/render_target.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/color.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/transformable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/camera.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/window/window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/window/glfw/glfw_window_impl.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/linalg/transform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/linalg/linalg.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/window
    ${CMAKE_CURRENT_SOURCE_DIR}/src/linalg
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    GL
    GLU
    glfw3
    X11
    Xxf86vm
    Xrandr
    pthread
    Xi
    dl
    Xinerama
    Xcursor
    GLEW
)