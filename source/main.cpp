#include "core.h"

int main()
{
    App app = App();
    TextObject *HelloWorld = new TextObject("Hello World");
    GameObject *camera = app.getCamera();

    initScene(app);
    initPlayer(app);
    initEnemy(app);
    initOptions(app);
    initMenu(app);
    app.addObject(camera);
    app.run();
    return 0;
}