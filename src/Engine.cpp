#include <Shinera/Engine.h>

void Engine::init() {
    m_ctx.getWindowManager().createWindow();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0.f, 0.0f, 0.0f, 1.f);
}

void Engine::run() {
    auto window = m_ctx.getWindowManager().getWindow();
    auto smanager = m_ctx.getSceneManager();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        //smanager.update(0);
        smanager.render();

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll for events
        glfwPollEvents();
    }

    m_ctx.getWindowManager().destroyWindow();
    glfwTerminate();
}