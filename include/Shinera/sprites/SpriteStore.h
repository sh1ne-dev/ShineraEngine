//
// Created by Shine on 3/7/2025.
//

#ifndef SPRITESTORE_H
#define SPRITESTORE_H

#include <unordered_map>
#include <string>
#include <GL/glew.h>
#include <nlohmann/json.hpp>
#include <Shinera/utils/Vectors.h>


enum SpriteType {
    SPRITE,
    ATLAS
};

struct SpriteStoreItem {
    GLuint texture;
    int width, height;
    SpriteType type;
    std::shared_ptr<std::unordered_map<std::string, Vec4>> atlasCoords;
    bool success = false;

};

class SpriteStore {
    std::string resourcesDir = "res/";
    std::unordered_map<std::string, std::shared_ptr<SpriteStoreItem>> sprites;
public:
    static SpriteStore& getInstance();
    std::shared_ptr<SpriteStoreItem> loadSprite(const std::string& fileName, SpriteType type);

};



#endif //SPRITESTORE_H
