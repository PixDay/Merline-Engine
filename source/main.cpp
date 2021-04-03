#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "core.h"
#include "ui.hpp"


void secondPlayer(GameObject *self)
{
  sf::Vector2f position = self->getPosition();
  sf::Vector2f ballPosition = static_cast<DisplayableObject *>(self)->getObjects()[0]->getPosition();

  if (position.y > ballPosition.y - 75.0f)
    position.y -= self->getSpeed();
  if (position.y < ballPosition.y - 75.0f)
    position.y += self->getSpeed();
  position.y = (position.y < 0.0f) ? 0.0f : (position.y > 1030.0f) ? 1030.0f : position.y;
  static_cast<DisplayableObject *>(self)->setPosition(position);
}

void player(GameObject *self)
{
  sf::Vector2f position = self->getPosition();

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    position.y -= self->getSpeed();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    position.y += self->getSpeed();
  position.y = (position.y < 0.0f) ? 0.0f : (position.y > 1030.0f) ? 1030.0f : position.y;
  static_cast<DisplayableObject *>(self)->setPosition(position);
}

void ballMovement(GameObject *self)
{
  sf::Vector2f direction = self->getDirection();
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
  self->setDirection(direction);
  static_cast<DisplayableObject *>(self)->setPosition(position);
}

void ballCollision(GameObject *self)
{
    sf::Vector2f direction = self->getDirection();
    direction.x = -(self->getSpeed());
    self->setSpeed(self->getSpeed() + 0.1f);
    self->setDirection(direction);
}

int main()
{
    App app = App();
    DisplayableObject *player1 = new DisplayableObject("img/player.png", &player);
    DisplayableObject *player2 = new DisplayableObject("img/player.png", &secondPlayer);
    DisplayableObject *ball = new DisplayableObject("img/ball.png", &ballMovement);
    sf::Vector2f position = {50.0f, 500.0f};

    ball->setTag("Ball");
    ball->setSpeed(5.0f);
    player1->setTag("Player");
    player2->setTag("Bot");
    player1->setPosition(position);
    position.x = 1820.0f;
    player2->setPosition(position);
    player2->setSpeed(10.0f);
    srand (time(NULL));
    app.addScene("Game");
    app.setCurrentScene("Game");
    app.addObject(new DisplayableObject("img/background.png"));
    app.addObject(ball);
    app.addObject(player1);
    app.addObject(player2);
    player2->addObject(ball);
    app.addCollisionPair("Ball", "Player");
    app.addCollisionPair("Ball", "Bot");
    ball->setOnCollide(&ballCollision);
    app.run();
    return 0;
}