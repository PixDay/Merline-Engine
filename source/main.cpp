#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "core.h"
#include "ui.hpp"


void snakeMovement(GameObject *self)
{
  sf::Vector2f position = self->getPosition();

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    position.x += self->getSpeed();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    position.x -= self->getSpeed();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    position.y -= self->getSpeed();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    position.y += self->getSpeed();
  position.x = (position.x < 0.0f) ? 0.0f : (position.x > 1920.0f) ? 1920.0f : position.x;
  position.y = (position.y < 0.0f) ? 0.0f : (position.y > 1030.0f) ? 1030.0f : position.y;
  static_cast<DisplayableObject *>(self)->setPosition(position);
}

void ballMovement(GameObject *self)
{
  static sf::Vector2f direction = {5.0f, 5.0f};
  sf::Vector2f position = self->getPosition();

  if (position.x > 1870.0f)
    direction.x = -(self->getSpeed());
  if (position.x < 0.0f)
    direction.x = self->getSpeed();
  if (position.y > 1030.0f)
    direction.y = -(self->getSpeed());
  if (position.y < 0.0f)
    direction.y = self->getSpeed();
  position.x += direction.x;
  position.y += direction.y;
  static_cast<DisplayableObject *>(self)->setPosition(position);
}

int main()
{
    App app = App();    

    srand (time(NULL));
    app.addScene("Menu");
    app.setCurrentScene("Menu");
    app.addObject(new DisplayableObject("img/green.png", &snakeMovement));
    app.addObject(new DisplayableObject("img/red.png", &ballMovement));
    app.run();
    return 0;
}