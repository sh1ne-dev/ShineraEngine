//
// Created by Shine on 3/22/2025.
//

#include <Shinera/shaders/CompiledShaderStore.h>
#include <vector>
#include <iostream>

GLuint CompiledShaderStore::compileShader(const std::string& shaderSource, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);
    const char* source = shaderSource.c_str();
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLint logLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<GLchar> infoLog(logLength);
        glGetShaderInfoLog(shader, logLength, &logLength, infoLog.data());
        std::cerr << "Shader compile failed: " << infoLog.data() << std::endl;
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

GLuint CompiledShaderStore::getShader(const std::string &shaderName) {
    if (compiledShaders.contains(shaderName)) {
        return compiledShaders[shaderName];
    }

    return 0;
}

GLuint CompiledShaderStore::loadShader(const std::string &shaderSource, const GLenum shaderType, const std::string &shaderName) {
    if (compiledShaders.contains(shaderName)) {
        return compiledShaders[shaderName];
    }

    const auto shader = compileShader(shaderSource, shaderType);
    compiledShaders[shaderName] = shader;
    return shader;
}



