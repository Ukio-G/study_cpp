cmake_minimum_required(VERSION 3.16)
project(imgui_sfml_application)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package (Threads)
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()


set(SFML_LIBS sfml-graphics sfml-window sfml-system)
include_directories(. ${OPENGL_INCLUDE_DIRS})

add_executable(imgui_sfml_application Shader.cpp main.cpp imgui/imgui_draw.cpp imgui/imgui.cpp imgui/imgui_widgets.cpp imgui/imgui-SFML.cpp)

target_link_libraries(imgui_sfml_application ${OPENGL_LIBRARY} ${SFML_LIBS} ${GLEW_LIBRARIES} Threads::Threads)
