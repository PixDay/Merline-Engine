/*
** File name :
** displayableObject.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include "gameObject.hpp"

class DisplayableObject : public GameObject
{
  public:
    DisplayableObject(std::string const &texture);
    DisplayableObject(std::string const &texture, std::function<void(GameObject *)>);
   ~DisplayableObject();

    void update();
    
    /* ADDERS */
    void addObject(DisplayableObject *object);

    /* DELETERS */
    void deleteObject(std::string const &tag);

    /* SETTERS */
    void setTexture(std::string const &texture);
    void setTexture(sf::Texture const &texture);
    void setOrigin(sf::Vector2f const &origin);
    void setScale(sf::Vector2f const &scale);
    void setHitbox(sf::Vector2f const &hitbox);
    void setHitbox(float const &x, float const &y);
    void setAngle(float const &angle);
    void setAngleByCenter(float const &angle);
    void setVisibleTime(float time);

    /* GETTERS */
    sf::Sprite *                        getSprite(void)     const;
    sf::Texture                         getTexture(void)    const;
    sf::Vector2f                        getDimension(void)  const;
    float                               getAngle(void)      const;
    std::vector<DisplayableObject *>    getObjects()        const;

private:
    sf::Sprite *                        _sprite;
    sf::Texture                         _texture;
    sf::Clock                           _clock;
    float                               _angle;
    float                               _visibleTime;
    std::vector<DisplayableObject *>    _objects;
};