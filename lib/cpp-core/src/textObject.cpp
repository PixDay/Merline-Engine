/*
** File name :
** textObject.cpp
** File creator :
** Adrien Colombier
*/

#include "textObject.hpp"

TextObject::TextObject(std::string const &text):
_text(text)
{};

TextObject::TextObject(std::string const &text, std::string const &fontPath):
_text(text)
{
    _font.loadFromFile(fontPath);
}

TextObject::TextObject(std::string const &text, std::string const &fontPath, size_t color):
_text(text),
_color(sf::Color(color))
{
    _font.loadFromFile(fontPath);
}

/* SETTERS */
void TextObject::setText(std::string const &text)
{
    _text = text;
}

void TextObject::setFont(std::string const &fontPath)
{
    _font.loadFromFile(fontPath);
}

void TextObject::setColor(size_t color)
{
    _color = sf::Color(color);
}

/* GETTERS */
std::string TextObject::getText(void) const
{
    return _text;
}

sf::Font TextObject::getFont(void) const
{
    return _font;
}

sf::Color TextObject::getColor(void) const
{
    return _color;
}