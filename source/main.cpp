#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "core.h"
#include "ui.hpp"


void snakeMovement(GameObject *self)
{
  (void)self;
}

void apple(GameObject *self)
{
    static sf::Vector2f position = {(float)(rand() % 1870), (float)(rand() % 1030)};

    (static_cast<DisplayableObject *>(self))->setPosition(position);
}


int main()
{
    App app = App();    

    srand (time(NULL));
    app.addScene("Menu");
    app.setCurrentScene("Menu");
    app.addObject(new DisplayableObject("img/green.png", &snakeMovement));
    app.addObject(new DisplayableObject("img/red.png", &apple));
    app.run();
    return 0;
}