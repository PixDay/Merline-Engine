/*
** File name :
** gameObject.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include "SFML/Graphics.hpp"

class GameObject
{
    public:
        GameObject();
        ~GameObject() = default;

         /* SETTERS */
        void setTag(std::string const &tag);
        void setType(std::string const &type);
        void setPosition(sf::Vector2f const &position);
        void setScale(sf::Vector2f const &scale);
        void setOrigin(sf::Vector2f const &origin);
        void setLayout(size_t const &layout);
        void setIndex(size_t const &index);
        void setActive(bool const &active);
        
        /* GETTERS */
        std::string     getTag(void)        const;
        std::string     getType(void)       const;
        sf::Vector2f    getPosition(void)   const;
        sf::Vector2f    getScale(void)      const;
        size_t          getLayout(void)     const;
        size_t          getIndex(void)      const;
        bool            getActive(void)     const;

     private:
        std::string     _tag;
        std::string     _type;
        sf::Vector2f    _position;
        sf::Vector2f    _scale;
        sf::Vector2f    _origin;
        size_t          _layout;
        size_t          _index;
        bool            _active;
};
