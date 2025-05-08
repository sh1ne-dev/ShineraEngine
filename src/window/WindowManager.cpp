#include <Shinera/window/WindowManager.h>
#include <iostream>

WindowManager::WindowManager() {
    if (!glfwInit()) {
        std::cerr << "GLFW initialization failed!" << std::endl;
        throw std::exception();
    }
}

void WindowManager::setWindowMode(WindowMode mode) {
    m_mode = mode;
}

WindowMode WindowManager::getWindowMode() {
    return m_mode;
}

void WindowManager::setWindowSize(Vec2 size) {
    m_winSize = size;
}

Vec2 WindowManager::getWindowSize() {
    return m_winSize;
}

void WindowManager::applyWindowMode() {
    switch (m_mode) {
        case FULLSCREEN: {
            const auto monitor = glfwGetPrimaryMonitor();
            const auto mode = glfwGetVideoMode(monitor);

            glfwSetWindowAttrib(m_window, GLFW_RESIZABLE, GLFW_FALSE);
            glfwSetWindowAttrib(m_window, GLFW_DECORATED, GLFW_FALSE);
            glfwSetWindowMonitor(m_window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
            break;
        }
        case BORDERLESS: {
            const auto monitor = glfwGetPrimaryMonitor();
            const auto mode = glfwGetVideoMode(monitor);
            glfwSetWindowAttrib(m_window, GLFW_RESIZABLE, GLFW_FALSE);
            glfwSetWindowAttrib(m_window, GLFW_DECORATED, GLFW_FALSE);
            glfwSetWindowMonitor(m_window, nullptr, 0, 0, mode->width, mode->height, mode->refreshRate);
            break;
        }
        case WINDOWED: {
            const auto monitor = glfwGetPrimaryMonitor();
            const auto mode = glfwGetVideoMode(monitor);
            const auto posX = (mode->width - m_winSize.x) / 2;
            const auto posY = (mode->height - m_winSize.y) / 2;

            glfwSetWindowAttrib(m_window, GLFW_RESIZABLE, GLFW_TRUE);
            glfwSetWindowAttrib(m_window, GLFW_DECORATED, GLFW_TRUE);
            glfwSetWindowMonitor(m_window, nullptr, posX, posY, m_winSize.x, m_winSize.y, mode->refreshRate);
            break;
        }
    }

}

void WindowManager::applyWindowSize() {
    switch (m_mode) {
        case FULLSCREEN: {
            auto monitor = glfwGetPrimaryMonitor();
            auto mode = glfwGetVideoMode(monitor);

            glfwSetWindowSize(m_window, mode->width, mode->height);
            break;
        }
        case BORDERLESS: {
            auto monitor = glfwGetPrimaryMonitor();
            auto mode = glfwGetVideoMode(monitor);

            glfwSetWindowSize(m_window, mode->width, mode->height);
            break;
        }
        case WINDOWED: {
            glfwSetWindowSize(m_window, m_winSize.x, m_winSize.y);
            break;
        }
    }
}

void WindowManager::createWindow() {
    if(m_window) return;

    m_window = (glfwCreateWindow(m_winSize.x, m_winSize.y, "Sonic 1", nullptr, nullptr));
    if (!m_window) {
        std::cerr << "GLFW window creation failed!" << std::endl;
        glfwTerminate();
        throw std::exception();
    }

    glfwMakeContextCurrent(m_window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize Glad\n";
        throw std::exception();
    }

    applyWindowMode();
    applyWindowSize();
}

GLFWwindow* WindowManager::getWindow() {
    return m_window;
}

void WindowManager::destroyWindow() {
    glfwDestroyWindow(m_window);
}

void WindowManager::setWindowTitle(const std::string& title) {
    m_title = title;
    glfwSetWindowTitle(m_window, m_title.c_str());
}

std::string& WindowManager::getWindowTitle() {
    return m_title;
}