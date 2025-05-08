//
// Created by Shine on 3/5/2025.
//

#ifndef SCENE_H
#define SCENE_H

class Scene {
public:
    virtual void init() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;
    virtual void cleanup() = 0;

    virtual ~Scene() = default;
};

#endif //SCENE_H
