#include "core.h"

int main()
{
    App app = App();
    TextObject HelloWorld = TextObject("Hello World");
    GameObject camera = app.getCamera();
    sf::Vector2f position;

    position.x = 500.0f;
    position.y = 450.0f;
    HelloWorld.setPosition(position);
    HelloWorld.setSize(50);
    app.addScene("Game");
    app.setCurrentScene("Game");
    app.addObject(HelloWorld);
    app.addObject(camera);
    app.run();
    return 0;
}