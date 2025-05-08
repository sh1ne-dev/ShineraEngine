//
// Created by Shine on 3/22/2025.
//

#include <Shinera/shaders/ShaderProgramStore.h>

GLuint ShaderProgramStore::getShaderProgram(const std::string& name) {
    if (shaderPrograms.contains(name)) {
        return shaderPrograms[name];
    }

    return 0;
}

GLuint ShaderProgramStore::createShaderProgram(const std::string &name, const GLuint vertexShader, const GLuint fragmentShader) {
    if (shaderPrograms.contains(name)) {
       return shaderPrograms[name];
    }

    const auto program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    shaderPrograms[name] = program;
    return program;
}

