#include <Shinera/Engine.h>
#include <scenes/ShineraScene.h>


int main() {
    Engine engine;
    engine.init();

    auto wmanager = engine.getContext().getWindowManager();

    //wmanager.setWindowMode(BORDERLESS);
    //wmanager.applyWindowMode();
    wmanager.setWindowTitle("Shinera Example");

    auto smanager = engine.getContext().getSceneManager();

    smanager.changeScene(new ShineraScene());

    engine.run();

    return 0;
}