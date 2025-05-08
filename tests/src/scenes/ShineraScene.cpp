#include <scenes/ShineraScene.h>

void ShineraScene::init() {
    sprite = RenderableSprite::createSprite("shinera-logo.png", SPRITE);
}

void ShineraScene::update(float deltaTime) {
    
}

void ShineraScene::render() {
    if (sprite) {
        sprite->render();
    }
}

void ShineraScene::cleanup() {

}