#include <iostream>
#include "core.h"
#include "ui.hpp"


void printer(DisplayableObject *self)
{
  (void)self;
  std::cout << "Coucou" << std::endl;
}


int main()
{
    App app = App();    

    app.getSceneManager().addScene("Menu");
    app.getSceneManager().setCurrentScene("Menu");
    app.getSceneManager().addObject(new DisplayableObject("source/background.jpg", &printer));
    app.run();
    return 0;
}