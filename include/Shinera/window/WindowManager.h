#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Shinera/utils/Vectors.h>


enum WindowMode {
    FULLSCREEN,
    BORDERLESS,
    WINDOWED
};

class WindowManager {
    GLFWwindow* m_window = nullptr;
    WindowMode m_mode = WINDOWED;
    Vec2 m_winSize = {1280, 720};
    std::string m_title = "";

public:
    WindowManager();
    void setWindowMode(WindowMode mode);
    WindowMode getWindowMode();
    void applyWindowMode();
    void setWindowSize(Vec2 size);
    Vec2 getWindowSize();
    void applyWindowSize();
    void createWindow();
    GLFWwindow* getWindow();
    void destroyWindow();
    void setWindowTitle(const std::string& title);
    std::string& getWindowTitle();
};