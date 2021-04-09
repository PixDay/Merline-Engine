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
       ~TextObject() = default;

        /* SETTERS */
        void setText(std::string const &text);

        /* GETTERS */
        std::string getText(void)   const;

    private:
        std::string _text;
};