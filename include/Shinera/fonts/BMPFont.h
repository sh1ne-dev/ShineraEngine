//
// Created by Shine on 3/7/2025.
//

#ifndef BMPFONT_H
#define BMPFONT_H

#include <Shinera/sprites/SpriteStore.h>
#include <Shinera/utils/Vectors.h>

class BMPFont {
    std::shared_ptr<SpriteStoreItem> m_fontSprite;
    float m_scaleX = 1.0f;
    float m_scaleY = 1.0f;
    float m_spacing = 30.0f;
    float m_padding = 0.0f;
    float m_transparency = 0.5f;
    std::string m_string;
    //std::vector<SDL_Vertex> m_vertices;
    std::vector<std::tuple<int, int>> m_originalSize;
    std::vector<int> m_indices;
    float m_x = 0;
    float m_y = 0;
    bool m_needsUpdate = false;

public:
    static BMPFont* create(const std::string& fileName, const std::string& text, const float spacing, const float padding = 0.f);
    void init(const std::string& fileName, const std::string& text, const float spacing, const float padding);
    void render() const;
    void setScaleX(float scaleX);
    void setScaleY(float scaleY);
    [[nodiscard]] Vec2 getScale();
    [[nodiscard]] std::shared_ptr<SpriteStoreItem> getFontSprite();
    void setText(const std::string& text);
    [[nodiscard]] std::string& getText();
    void setPosY(float posY);
    void setPosX(float posX);
    [[nodiscard]] Vec2 getPos();
    [[nodiscard]] Vec2 getContentSize();
    void update();

};



#endif //BMPFONT_H
