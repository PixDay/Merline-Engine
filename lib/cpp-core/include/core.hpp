/*
** File name :
** core.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include "SFML/Graphics.hpp"
#include "displayableObject.hpp"
#include "sceneManager.hpp"

class App 
{
    public:
        App();
       ~App() = default;

        void run(void);

        /* GETTERS */
        SceneManager getSceneManager(void)  const;
        
    private:
        void draw(void);
        sf::RenderWindow *      _window;
        sf::Keyboard::Key       _leaveKey;
        SceneManager            _sceneManager;
};