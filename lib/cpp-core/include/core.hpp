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
        void addScene(std::string const &name);
        void addObject(GameObject *object);
        void addObjectTo(GameObject *object, std::string const &name);

        /* SETTERS */
        void setCurrentScene(size_t const &scene);
        void setCurrentScene(std::string const &name);
        
        /* GETTERS */
        SceneManager getSceneManager(void)  const;
        
    private:
        void draw(void);
        sf::RenderWindow *      _window;
        sf::Keyboard::Key       _leaveKey;
        SceneManager            _sceneManager;
};