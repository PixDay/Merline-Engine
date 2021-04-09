/*
** File name :
** textObject.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include "displayableObject.hpp"

class TextObject : public DisplayableObject
{
    public:
        TextObject(std::string const &text);
        TextObject(std::string const &text, std::string const &fontPath);
        TextObject(std::string const &text, std::string const &fontPath, size_t color);
       ~TextObject() = default;

        /* SETTERS */
        void setText(std::string const &text);
        void setFont(std::string const &fontPath);
        void setColor(size_t color);

        /* GETTERS */
        std::string getText(void)   const;
        sf::Font    getFont(void)   const;
        sf::Color   getColor(void)  const;

    private:
        std::string _text;
        sf::Font    _font;
        sf::Color   _color;
        sf::Text    _render;
};