#include <GL/glew.h>

#include <Shinera/window/WindowManager.h>
#include <Shinera/scenes/SceneManager.h>

class EngineCtx {
    WindowManager m_wmanager;
    SceneManager m_scenemgr;

public:

    WindowManager& getWindowManager() {
        return m_wmanager;
    }
    
    SceneManager& getSceneManager() {
        return m_scenemgr;
    }
};