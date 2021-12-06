#include "shooter.h"

void instantiateMenu(App &app) {
    DisplayableObject *background   = new DisplayableObject("img/background.png");
    DisplayableObject *playButton   = new DisplayableObject("img/playButton.png");
    DisplayableObject *optionButton = new DisplayableObject("img/optionButton.png");
    DisplayableObject *exitButton   = new DisplayableObject("img/exitButton.png");
    TextObject        *title        = new TextObject("Merline Shooter");
    
    background->setOrigin({1920/2, 1080/2});
    background->setPosition({1920/2, 1080/2});
    title->setSize(50);
    title->setPosition({1600/2, 300});
    title->setColor(0x000000FF);
    playButton->setFunction(playButtonFunction);
    optionButton->setFunction(optionsButtonFunction);
    exitButton->setFunction(exitButtonFunction);
    app.addObjectTo(background, "menu");
    app.addObjectTo(playButton, "menu");
    app.addObjectTo(optionButton, "menu");
    app.addObjectTo(exitButton, "menu");
    app.addObjectTo(title, "menu");
}

void playButtonFunction(GameObject *self)
{
    (void)self;
    // Implement buttons and stuff to change scene easily
}

void optionsButtonFunction(GameObject *self)
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