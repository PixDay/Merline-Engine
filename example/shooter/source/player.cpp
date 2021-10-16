#include "core.h"

void initPlayer(App &app, GameObject *camera)
{
    sf::Vector2f position = {1920.0f, 1080.0f};

    DisplayableObject *player = new DisplayableObject("img/player.png");
    player->setTag("Player");
    player->setPosition(position);
    player->setSpeed(450.0f);
    player->setFunction(&playerController);
    static_cast<Camera *>(camera)->setObjectToFollow(player);
    camera->setFunction(&cameraController);
    app.addObject(player);
    app.addObject(camera);
}

void playerController(GameObject *self)
{
    sf::Vector2f position = self->getPosition();
    float elaspedTime = static_cast<DisplayableObject *>(self)->getTime();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        position.y -= (self->getSpeed() * elaspedTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        position.y += (self->getSpeed() * elaspedTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        position.x += (self->getSpeed() * elaspedTime);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        position.x -= (self->getSpeed() * elaspedTime);
    static_cast<DisplayableObject *>(self)->setPosition(position);
    static_cast<DisplayableObject *>(self)->resetTimer();
}

void cameraController(GameObject *self)
{
    sf::Vector2f toFollowPosition = static_cast<Camera *>(self)->getToFollow()->getPosition();
    sf::Vector2f currentPosition = static_cast<Camera *>(self)->getPosition();
    
    toFollowPosition.x = toFollowPosition.x - currentPosition.x;
    toFollowPosition.y = toFollowPosition.y - currentPosition.y;
    static_cast<Camera *>(self)->move(toFollowPosition);
}