#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <fstream>
#include <GL/glew.h>

class Shader {
public:

    // Source code of the shader
    char * shaderSource = nullptr;
    GLuint shaderID;
    GLuint shaderType;
    void loadFromFile(const char * path, GLuint shaderType);
    Shader(const char * path, GLuint shaderType) : shaderType(shaderType) {
        loadFromFile(path, shaderType);
    }
    ~Shader() {
        glDeleteShader(shaderID);
        delete shaderSource;
    }
};

class  ShaderProgram {
public:
    GLuint shaderProgram;
    ShaderProgram(Shader * vertex, Shader * fragment);

    void use() {
        glUseProgram(shaderProgram);
    }

    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;
    void setFloat4d(const std::string &name, const float (&value) [4]) const;
};


#endif //LIVE_SHADER_H
