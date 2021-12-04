#include "shooter.h"

void instantiateMenu(App &app) {
    DisplayableObject *background   = new DisplayableObject("img/menuBackground.png");
    DisplayableObject *playButton   = new DisplayableObject("img/playButton.png");
    DisplayableObject *optionButton = new DisplayableObject("img/optionButton.png");
    DisplayableObject *exitButton   = new DisplayableObject("img/exitButton.png");
    
    playButton->setFunction(playButtonFunction);
    optionButton->setFunction(optionButtonFunction);
    exitButton->setFunction(exitButtonFunction);
    app.addObject(background);
    app.addObject(playButton);
    app.addObject(optionButton);
    app.addObject(exitButton);
}

void playButtonFunction(GameObject *self)
{
    (void)self;
    // Implement buttons and stuff to change scene easily
}

void optionButtonFunction(GameObject *self)
{
    (void)self;
    // Implement buttons and stuff to change scene easily
}

void exitButtonFunction(GameObject *self)
{
    (void)self;
    // Implement buttons and stuff to change scene easily
    // Onclick simply set the tag to STOP_RUN to stop the game loop
}