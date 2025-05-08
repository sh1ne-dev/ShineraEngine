//
// Created by Shine on 3/22/2025.
//

#ifndef SHADERPROGRAMSTORE_H
#define SHADERPROGRAMSTORE_H

#include <unordered_map>
#include <string>
#include <GL/glew.h>

class ShaderProgramStore {
    std::unordered_map<std::string, GLuint> shaderPrograms;
    public:
    static ShaderProgramStore& getInstance() {
        static ShaderProgramStore instance;
        return instance;
    }

    GLuint getShaderProgram(const std::string& name);
    GLuint createShaderProgram(const std::string& name, GLuint vertexShader, GLuint fragmentShader);
};



#endif //SHADERPROGRAMSTORE_H
