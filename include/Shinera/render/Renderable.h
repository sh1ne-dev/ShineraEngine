//
// Created by Shine on 3/22/2025.
//

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <GL/glew.h>

class Renderable {
protected:
    GLuint m_renderProgram = 0;
    GLuint m_vao = 0;
    GLuint m_vbo = 0;
    GLuint m_ebo = 0;

public:
    virtual ~Renderable() = default;

    void virtual render() = 0;
    bool virtual initRender() = 0;
};

#endif //RENDERABLE_H
