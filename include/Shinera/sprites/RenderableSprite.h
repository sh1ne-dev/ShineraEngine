//
// Created by Shine on 3/23/2025.
//

#ifndef RENDERABLESPRITE_H
#define RENDERABLESPRITE_H

#include <Shinera/shaders/CompiledShaderStore.h>
#include <Shinera/shaders/ShaderProgramStore.h>
#include <Shinera/sprites/SpriteStore.h>
#include <Shinera/render/Renderable.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class RenderableSprite : public Renderable {
    SpriteType m_spriteType = SPRITE;
    std::shared_ptr<std::unordered_map<std::string, Vec4>> m_atlasCoords;
    int m_width = 0;
    int m_height = 0;
    GLuint m_texture = 0;
public:
    static RenderableSprite* createSprite(const std::string& path, SpriteType type);
    bool init(const std::string& path, SpriteType type);
    bool initRender() override;
    void render() override;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
};



#endif //RENDERABLESPRITE_H
