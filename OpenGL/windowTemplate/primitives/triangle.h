#include "Vertex.h"

Vertex triangle_vertices[] {
    {-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, -0.5f, -0.5f},
    { 0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  0.5f, -0.5f},
    { 0.0f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  0.0f,  0.5f},


    { 0.7f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, -0.5f, -0.5f},
    { 0.0f, -0.7f, 0.0f, 1.0f, 0.0f, 0.0f,  0.5f, -0.5f},
    {-0.7f, -0.7f, 0.0f, 1.0f, 0.0f, 0.0f,  0.0f,  0.5f}
};

unsigned int triangle_indexes[] = {0, 1, 2, 3, 4, 5};