//
// Created by Shine on 3/5/2025.
//

#ifndef SEGASCENE_H
#define SEGASCENE_H

#include <Shinera/scenes/Scene.h>
#include <Shinera/sprites/RenderableSprite.h>


class ShineraScene : public Scene {
private:
    RenderableSprite* sprite = nullptr;
public:
    void init() override;
    void update(float deltaTime) override;
    void render() override;
    void cleanup() override;
};


#endif //SEGASCENE_H
