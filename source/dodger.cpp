#include "dodger.h"

int main(void)
{
    App app = App();
    DisplayableObject *player = new DisplayableObject("img/green.png");

    srand(time(NULL));
    playerSetting(app, player);
    gameTimer(app);
    createEnnemies(app);
    createCollisionList(app);
    app.run();
}