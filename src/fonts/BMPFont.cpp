//
// Created by Shine on 3/7/2025.
//

#include <Shinera/fonts/BMPFont.h>


BMPFont *BMPFont::create(const std::string& fileName, const std::string& text, const float spacing, const float padding) {
    auto ret = new BMPFont();
    ret->init(fileName, text, spacing, padding);
    return ret;
}

void BMPFont::init(const std::string& fileName, const std::string& text, const float spacing, const float padding) {
    m_fontSprite = SpriteStore::getInstance().loadSprite(fileName, ATLAS);
    m_spacing = spacing;
    m_padding = padding;
    setText(text);
}

void BMPFont::render() const {

}

void BMPFont::setText(const std::string &text) {
    if (text == m_string) return;

    m_string = text;
    int vertIndex = 0;
    float bufferX = 0;
    float padding = 0;
    size_t letterCount = 0;

    for (const auto& c : m_string) {
        if (c != '\n' && c != ' ') {
            ++letterCount;
        }
    }
    //m_vertices.clear();
    m_indices.clear();
    m_originalSize.clear();

    //m_vertices.reserve(letterCount * 4);
    m_indices.reserve(letterCount * 6);
    m_originalSize.reserve(letterCount);

    for (auto &c : m_string) {
        if (c != '\n' && c != ' ') {
            auto atlasCoords = m_fontSprite->atlasCoords.get()->operator[](std::string(1, c));
            float u = atlasCoords.x / m_fontSprite->width;
            float v = atlasCoords.y / m_fontSprite->height;
            float u2 = (atlasCoords.x + atlasCoords.z) / m_fontSprite->width;
            float v2 = (atlasCoords.y + atlasCoords.w) / m_fontSprite->height;

            auto xLeftSide = m_x + bufferX + padding;
            auto charWidth = atlasCoords.z;
            auto charHeight = atlasCoords.w;


            // m_vertices.push_back({{xLeftSide, m_y}, {255,255,255,255}, {u,v}});
            // m_vertices.push_back({{xLeftSide + charWidth * m_scaleX, m_y}, {1.0, 1.0, 1.0, m_transparency}, {u2,v}});
            // m_vertices.push_back({{xLeftSide + charWidth * m_scaleX, m_y + charHeight * m_scaleY}, {1.0, 1.0, 1.0, m_transparency}, {u2,v2}});
            // m_vertices.push_back({{xLeftSide, m_y + charHeight * m_scaleY}, {1.0, 1.0, 1.0, m_transparency}, {u,v2}});

            m_indices.push_back(vertIndex * 4);
            m_indices.push_back(vertIndex * 4 + 1);
            m_indices.push_back(vertIndex * 4 + 2);
            m_indices.push_back(vertIndex * 4 + 2);
            m_indices.push_back(vertIndex * 4 + 3);
            m_indices.push_back(vertIndex * 4);

            m_originalSize.emplace_back(atlasCoords.z, atlasCoords.w);

            bufferX += atlasCoords.z + padding * m_scaleX;

            padding = m_padding;
            vertIndex++;
        }
        if (c == ' ') {
            bufferX += m_spacing * m_scaleX;
            padding = 0;
        }
    }
}

void BMPFont::setPosY(const float posY) {
    if (posY == m_y) return;
    m_y = posY;
    m_needsUpdate = true;
}

void BMPFont::setPosX(const float posX) {
    if (posX == m_x) return;
    m_x = posX;
    m_needsUpdate = true;
}

Vec2 BMPFont::getPos() {
    return Vec2(m_x, m_y);
}

Vec2 BMPFont::getScale() {
    return Vec2(m_scaleX, m_scaleY);
}

void BMPFont::setScaleX(float scaleX) {
    if (m_scaleX == scaleX) return;
    m_scaleX = scaleX;
    m_needsUpdate = true;
}

void BMPFont::setScaleY(float scaleY) {
    if (scaleY == m_scaleY) return;
    m_scaleY = scaleY;
    m_needsUpdate = true;
}

std::shared_ptr<SpriteStoreItem> BMPFont::getFontSprite() {
    return m_fontSprite;
}

std::string& BMPFont::getText() {
    return m_string;
}

Vec2 BMPFont::getContentSize() {
    // float width = m_vertices[m_vertices.size() - 2].position.x - m_vertices[0].position.x;
    // float height = 0;
    //
    // auto maxYIt = std::max_element(m_vertices.begin(), m_vertices.end(),
    // [](const SDL_Vertex& a, const SDL_Vertex& b) {
    //     return a.position.y < b.position.y; // Compare by second element (float)
    // });
    //
    // if (maxYIt == m_vertices.end()) {
    //     return std::make_tuple(width, 0);
    // }
    //
    // return std::make_tuple(width, maxYIt->position.y - m_vertices[0].position.y);
    return Vec2();
}

void BMPFont::update() {
    // if (!m_needsUpdate) return;
    //
    // auto* vertexData = m_vertices.data();
    // float padding = 0;
    // int charIndex = 0;
    // float bufferX = 0;
    //
    // for (auto &c : m_string) {
    //     if (c != '\n' && c != ' ') {
    //         const auto scaledCharWidth = (float)get<0>(m_originalSize[charIndex]) * m_scaleX;
    //         const auto rightSide = m_x + padding + bufferX + scaledCharWidth;
    //         const auto leftSide = m_x + padding + bufferX;
    //         auto charHeigth = (float)get<1>(m_originalSize[charIndex]);
    //         auto charHeightOnScreen = m_y + charHeigth * m_scaleY;
    //
    //         vertexData[charIndex * 4].position.x = leftSide;
    //         vertexData[charIndex * 4 + 1].position.x = rightSide;
    //         vertexData[charIndex * 4 + 2].position.x = rightSide;
    //         vertexData[charIndex * 4 + 3].position.x = leftSide;
    //
    //         vertexData[charIndex * 4].position.y = m_y;
    //         vertexData[charIndex * 4 + 1].position.y = m_y;
    //         vertexData[charIndex * 4 + 2].position.y = charHeightOnScreen;
    //         vertexData[charIndex * 4 + 3].position.y = charHeightOnScreen;
    //
    //         bufferX += scaledCharWidth + padding;
    //         padding = m_padding;
    //         charIndex++;
    //     }
    //     if (c == ' ') {
    //         bufferX += m_spacing;// * m_scaleX;
    //         padding = 0;
    //     }
    // }
    //
    // m_needsUpdate = false;
}
