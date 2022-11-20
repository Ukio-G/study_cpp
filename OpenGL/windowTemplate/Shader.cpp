#include "Shader.h"

void Shader::loadFromFile(const char *path, GLuint shaderType) {
    std::ifstream src(path, std::ifstream::binary);
    if(src){
        src.seekg (0, src.end);
        int length = src.tellg();
        src.seekg (0, src.beg);

        shaderSource = new char [length];
        src.read (shaderSource ,length);
        src.close();

        shaderID = glCreateShader(shaderType);
        glShaderSource(shaderID, 1, &shaderSource, NULL);
        glCompileShader(shaderID);

        // Compilation log on error
        int  success;
        char infoLog[512];
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
            std::cout << "Shader compilation failed! Shader type: " 
            << ((shaderType == GL_VERTEX_SHADER) ? "Vertex" : "Fragment") << "\n"  << infoLog << std::endl;
        }
    }
}

ShaderProgram::ShaderProgram(Shader *vertex, Shader *fragment) {
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertex->shaderID);
    glAttachShader(shaderProgram, fragment->shaderID);

    glLinkProgram(shaderProgram);

    // Linkage log on error
    int  success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "Shader linkage failed!\n"  << infoLog << std::endl;
    }
}

void ShaderProgram::setBool(const std::string &name, bool value) const {         
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), (int)value); 
}

void ShaderProgram::setInt(const std::string &name, int value) const { 
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value); 
}

void ShaderProgram::setFloat(const std::string &name, float value) const { 
    glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value); 
} 

void ShaderProgram::setFloat4d(const std::string &name, const float (&value)[4] ) const { 
    glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), value[0], value[1], value[2], value[3]); 
} 