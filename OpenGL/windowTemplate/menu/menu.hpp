#ifndef MENU_HPP
#define MENU_HPP 

#include "imgui/imgui.h"
#include "glm/glm.hpp"
#include "include/Vertex.h"
#include <vector>

void translationWindow(glm::fvec3 & translateVector);
void rotationWindow(glm::fvec3 & rotateAxis);
void showMatrix(const glm::mat4 &mat, const char * matrixLabel);
void vertexW_Window(float & vertex_w);
void projectionUsage(bool &useProjectionGLM, bool &useProjectionMyOwn,  bool &always_fixed_w);
void vertexMatrixCalculation(Vertex * vertexes, glm::mat4 &model_matrix, glm::mat4 &proj_matrix, const float & vertex_w);

#endif