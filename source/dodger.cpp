#include "dodger.h"
#include <iostream>
int main(void)
{
    App app = App();
    DisplayableObject *player = new DisplayableObject("img/green.png");

    srand(time(NULL));
    app.addScene("Game");
    app.setCurrentScene("Game");
    while (true) {
        playerSetting(app, player);
        gameTimer(app);
        createEnnemies(app);
        createCollisionList(app);
        app.run();
        app.getSceneManager().clearSceneContent("Game");
        player = new DisplayableObject("img/green.png");
    }
}