/*
** File name :
** gameObject.cpp
** File creator :
** Adrien Colombier
*/

#include "gameObject.hpp"

GameObject::GameObject():
_tag("default"),
_type("GameObject"),
_position({0.0f, 0.0f}),
_scale({1.0f, 1.0f}),
_active(true)
{
}


/* SETTERS */

void GameObject::setTag(std::string const &tag)
{
    _tag = tag;
}

void GameObject::setType(std::string const &type)
{
    _type = type;
}

void GameObject::setPosition(sf::Vector2f const &position)
{
    _position = position;
}

void GameObject::setScale(sf::Vector2f const &scale)
{
    _scale = scale;    
}

void GameObject::setOrigin(sf::Vector2f const &origin)
{
    _origin = origin;
}

void GameObject::setLayout(size_t const &layout)
{
    _layout = layout;
}

void GameObject::setIndex(size_t const &index)
{
    _index = index;
}

void GameObject::setActive(bool const &active)
{
    _active = active;
}


/* GETTERS */

std::string GameObject::getTag(void) const
{
    return _tag;
}

std::string GameObject::getType(void) const
{
    return _type;
}

sf::Vector2f GameObject::getPosition(void) const
{
    return _position;
}

sf::Vector2f GameObject::getScale(void) const
{
    return _scale;
}

size_t GameObject::getLayout(void) const
{
    return _layout;
}

size_t GameObject::getIndex(void) const
{
    return _index;
}

bool GameObject::getActive(void) const
{
    return _active;
}
