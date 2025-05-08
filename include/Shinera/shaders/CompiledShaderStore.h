//
// Created by Shine on 3/22/2025.
//

#ifndef COMPILEDSHADERSTORE_H
#define COMPILEDSHADERSTORE_H

#include <unordered_map>
#include <string>
#include <GL/glew.h>

class CompiledShaderStore {
    std::unordered_map<std::string, GLuint> compiledShaders;
    public:

    static CompiledShaderStore& getInstance() {
        static CompiledShaderStore instance;
        return instance;
    };

    static GLuint compileShader(const std::string& shaderSource, GLenum shaderType);
    GLuint getShader(const std::string& shaderName);
    GLuint loadShader(const std::string& shaderSource, GLenum shaderType, const std::string& shaderName);
};



#endif //COMPILEDSHADERSTORE_H
