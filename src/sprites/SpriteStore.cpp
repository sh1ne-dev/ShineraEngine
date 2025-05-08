//
// Created by Shine on 3/7/2025.
//

#include <Shinera/sprites/SpriteStore.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <fstream>

using json = nlohmann::json;

SpriteStore& SpriteStore::getInstance() {
    static SpriteStore instance;
    return instance;
};

std::shared_ptr<SpriteStoreItem> SpriteStore::loadSprite(const std::string &fileName, SpriteType type) {
    if (!sprites.contains(fileName)) {
        auto sprite = std::make_shared<SpriteStoreItem>();
        auto path = resourcesDir + fileName;
        int width, height, channels;
        unsigned char *data = stbi_load(path.c_str(), &width, &height, &channels, 4);

        if (data) {
            GLuint textureID;
            glGenTextures(1, &textureID);
            glBindTexture(GL_TEXTURE_2D, textureID);

            // Set texture parameters
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

            // Use GL_RGBA for formats with an alpha channel (transparency)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

            glGenerateMipmap(GL_TEXTURE_2D);

            stbi_image_free(data);

            sprite->texture = textureID;
            sprite->type = type;
            sprite->width = width;
            sprite->height = height;

            if (type == ATLAS) {
                auto jsonPath = std::filesystem::path(path).replace_extension(".json");
                std::ifstream file(jsonPath);
                json config;
                file >> config;

                for (auto it = config["sprites"].begin(); it != config["sprites"].end(); ++it) {
                    sprite->atlasCoords->operator[](it->at("fileName").get<std::string>()) =
                        Vec4(it->at("x").get<int>(), it->at("y").get<int>(), it->at("width").get<int>(), it->at("height").get<int>());
                }
            }
        }
        sprite->success = true;
        sprites[fileName] = sprite;
    }
    return sprites[fileName];
}


