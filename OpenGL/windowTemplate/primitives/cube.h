#include "Vertex.h"

Vertex cube_vertices[] {
    // Top vertexes
    {-0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f},
    {-0.5f, 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f},
    { 0.5f, 0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f},
    { 0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f},

    // Bottom vertexes
    {-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f},
    {-0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f},
    { 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f},
    { 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f},
};

unsigned int cube_indexes[] = {0, 1, 2, 1, 2, 3};
