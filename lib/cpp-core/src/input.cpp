/*
** File name :
** input.cpp
** File creator :
** Adrien Colombier
*/

#include "input.hpp"

Input::Input(std::string const &keyName, sf::Keyboard const key):
_keyName(keyName),
_key(key)
{};

/* SETTERS */
void Input::setKeyName(std::string const &keyName)
{
    _keyName = keyName;
}

void Input::setKey(sf::Keyboard const &key)
{
    _key = key;
}

/* GETTERS */
std::string Input::getKeyName(void) const
{
    return _keyName;
}

sf::Keyboard Input::getKey(void) const
{
    return _key;
}