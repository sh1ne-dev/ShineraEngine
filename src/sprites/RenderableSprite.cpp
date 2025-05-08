//
// Created by Shine on 3/23/2025.
//

#include <Shinera/sprites/RenderableSprite.h>

const char* vertexShaderSource = R"(
#version 460 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    TexCoord = aTexCoord;
}
)";

// Fragment Shader
const char* fragmentShaderSource = R"(
#version 460 core
out vec4 FragColor;
in vec2 TexCoord;
uniform sampler2D texture1;
void main()
{
    FragColor = texture(texture1, TexCoord);
}
)";

RenderableSprite* RenderableSprite::createSprite(const std::string &path, SpriteType type) {
    auto ret = new RenderableSprite();
    if (!ret->init(path, type) || !ret->initRender()) {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool RenderableSprite::init(const std::string &path, SpriteType type) {
    auto store = SpriteStore::getInstance();
    auto sprite = store.loadSprite(path, type);
    if (!sprite->success)
        return false;

    m_spriteType = sprite->type;
    m_width = sprite->width;
    m_height = sprite->height;
    m_atlasCoords = sprite->atlasCoords;
    m_texture = sprite->texture;
    return true;
}

bool RenderableSprite::initRender() {
    auto shaderStore = CompiledShaderStore::getInstance();
    auto programStore = ShaderProgramStore::getInstance();

    m_renderProgram = programStore.getShaderProgram("generalSprite");
    if (!m_renderProgram) {
        auto vertShader = shaderStore.getShader("generalSpriteVert");
        if (!vertShader) {
            vertShader = shaderStore.loadShader(vertexShaderSource, GL_VERTEX_SHADER, "generalSpriteVert");
        }
        auto fragShader = shaderStore.getShader("generalSpriteFrag");
        if (!fragShader) {
            fragShader = shaderStore.loadShader(fragmentShaderSource, GL_FRAGMENT_SHADER, "generalSpriteFrag");
        }
        m_renderProgram = programStore.createShaderProgram("generalSprite", vertShader, fragShader);
    }

    GLfloat vertices[] = {
        // positions         // texture coords
        -0.5f,  -0.5f, 0.0f,  0.0f, 1.0f,
        -0.5f, 0.5f, 0.0f,  0.0f, 0.0f,
         0.5f, 0.5f, 0.0f,  1.0f, 0.0f,
         0.5f,  -0.5f, 0.0f,  1.0f, 1.0f
    };
    GLuint indices[] = { 0, 1, 2, 0, 2, 3 };

    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ebo);

    glBindVertexArray(m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    return true;
}

void RenderableSprite::render() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    glUseProgram(m_renderProgram);
    glUniform1i(glGetUniformLocation(m_renderProgram, "texture1"), 0);

    glBindVertexArray(m_vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

int RenderableSprite::getHeight() const {
    return m_height;
}

int RenderableSprite::getWidth() const {
    return m_width;
}