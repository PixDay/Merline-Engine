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
  position.y = (position.y < 0.0f) ? 0.0f : (position.y > 930.0f) ? 930.0f : position.y;
  static_cast<DisplayableObject *>(self)->setPosition(position);
}

void player(GameObject *self)
{
  sf::Vector2f position = self->getPosition();

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    position.y -= self->getSpeed();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    position.y += self->getSpeed();
  position.y = (position.y < 0.0f) ? 0.0f : (position.y > 930.0f) ? 930.0f : position.y;
  static_cast<DisplayableObject *>(self)->setPosition(position);
}

void ballMovement(GameObject *self)
{
  sf::Vector2f direction = self->getDirection();
  sf::Vector2f position = self->getPosition();

  if (position.x > 1870.0f)
    direction.x = -(self->getDirection().x);
  if (position.x < 0.0f) 
    direction.x = -(self->getDirection().x);
  if (position.y > 1030.0f)
    direction.y = -(self->getDirection().y);
  if (position.y < 0.0f)
    direction.y = -(self->getDirection().y);
  position.x = position.x + (direction.x * self->getSpeed());
  position.y = position.y + (direction.y * self->getSpeed());
  self->setDirection(direction);
  static_cast<DisplayableObject *>(self)->setPosition(position);
}

void ballCollision(GameObject *self, GameObject *collided)
{
    sf::Vector2f direction = self->getDirection();
    sf::Vector2f position = {1920.0f / 2.0f, 1080.0f / 2.0f};

    direction.x = -(self->getDirection().x);
    self->setSpeed(self->getSpeed() + 0.1f);
    if (collided->getTag() == "Line") {
      static_cast<DisplayableObject *>(self)->setPosition(position);
      self->setSpeed(4.0f);
    }
    self->setDirection(direction);
}

int main()
{
    App app = App();
    DisplayableObject *player1 = new DisplayableObject("img/player.png", &player);
    DisplayableObject *player2 = new DisplayableObject("img/player.png", &secondPlayer);
    DisplayableObject *line1 = new DisplayableObject("img/line.png");
    DisplayableObject *line2 = new DisplayableObject("img/line.png");
    DisplayableObject *ball = new DisplayableObject("img/ball.png", &ballMovement);
    sf::Vector2f position = {50.0f, 500.0f};

    ball->setTag("Ball");
    ball->setSpeed(5.0f);
    player1->setTag("Player");
    player2->setTag("Bot");
    line1->setTag("Line");
    line2->setTag("Line");
    player1->setPosition(position);
    position.x = 1820.0f;
    player2->setPosition(position);
    player2->setSpeed(7.0f);
    position.x = 73.0f;
    position.y = 0.0f;
    line1->setPosition(position);
    position.x = 1843.0f;
    line2->setPosition(position);
    srand (time(NULL));
    app.addScene("Game");
    app.setCurrentScene("Game");
    app.addObject(new DisplayableObject("img/background.png"));
    app.addObject(ball);
    app.addObject(line1);
    app.addObject(line2);
    app.addObject(player1);
    app.addObject(player2);
    player2->addObject(ball);
    app.addCollisionPair("Ball", "Player");
    app.addCollisionPair("Ball", "Bot");
    app.addCollisionPair("Ball", "Line");
    ball->setOnCollide(&ballCollision);
    app.run();
    return 0;
}