/*
** File name :
** input.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include "SFML/Graphics.hpp"

class Input
{
    public:
        Input(std::string const &keyName, sf::Keyboard const key);
       ~Input() = default;

        /* SETTERS */
        void setKeyName(std::string const &keyName);
        void setKey(sf::Keyboard const &key);

        /* GETTERS */
        std::string     getKeyName(void)    const;
        sf::Keyboard    getKey(void)        const;

    private:
        std::string     _keyName;
        sf::Keyboard    _key;
};