#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <Shinera/scenes/Scene.h>
#include <iostream>

class SceneManager {
    Scene* m_currentScene = nullptr;

public:
    void changeScene(Scene* scene) {
        if (m_currentScene) m_currentScene->cleanup();

        m_currentScene = scene;
        std::cout << "hey\n";
        m_currentScene->init();
    }

    void update(float dt) {
        if (m_currentScene) m_currentScene->update(dt);
    }

    void render() {
        if (m_currentScene) m_currentScene->render();
        //std::cout << "test: " << (m_currentScene == nullptr) << "\n";
    }

    Scene* getCurrentScene() {
        return m_currentScene;
    }
};


#endif //SCENEMANAGER_H
