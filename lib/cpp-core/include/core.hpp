/*
** File name :
** core.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include "SFML/Graphics.hpp"

class App 
{
    public:
        App();
       ~App() = default;

        void run(void);
        
    private:
        sf::RenderWindow *      _window;
        sf::Keyboard::Key       _leaveKey;

};