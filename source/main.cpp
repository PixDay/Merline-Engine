#include "shooter.h"

int main()
{
    App app = App();
    GameObject *camera = app.getCamera();

    initScenes(app);
    //initPlayer(app);
    //initEnemy(app);
    app.addObject(camera);
    app.run();
    return 0;
}