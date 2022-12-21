cmake_minimum_required(VERSION 3.6)
project(opengl-glfw-glew-cmake)

set(CMAKE_CXX_STANDARD 17)
set(OpenGL_GL_PREFERENCE LEGACY)

set(APP_TARGET opengl-sample)

# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# glfw
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

# glew
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

include_directories(. include)

add_executable(opengl-sample Shader.cpp main.cpp 
        imgui/imgui_impl_glfw.cpp 
        imgui/imgui_impl_opengl3.cpp 
        imgui/imgui.cpp 
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_draw.cpp
        menu/menu.cpp
        )

target_link_libraries(
        ${APP_TARGET}
        glfw
        ${OPENGL_LIBRARY}
        ${GLEW_LIBRARIES}
)
