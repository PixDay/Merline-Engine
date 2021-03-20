/*
** File name :
** core.cpp
** File creator :
** Adrien Colombier
*/

#include "core.hpp"

App::App():
    _window(new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML Engine", sf::Style::Fullscreen)),
    _leaveKey(sf::Keyboard::Key::Escape)
{
};

void App::run(void)
{
    sf::Event event;

    while (_window->isOpen()) {
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(_leaveKey))
                _window->close();
        }
        _window->clear(sf::Color::Black);
        draw();
        _window->display();
    }
}

void App::draw(void)
{
    for (auto displayableElement : _sceneManager.getScenes()[_sceneManager.getCurrentScene()]->getGameObjects()) {
        displayableElement->update();
        if (displayableElement->getType() == "DisplayableObject" && (static_cast<DisplayableObject *>(displayableElement)->getActive())) {
            static_cast<DisplayableObject *>(displayableElement)->update();
            _window->draw(*(static_cast<DisplayableObject *>(displayableElement)->getSprite()));
        }
    }
}

void App::addScene(std::string const &name)
{
    _sceneManager.addScene(name);
}

void App::addObject(GameObject *object)
{
    _sceneManager.addObject(object);
}

void App::addObjectTo(GameObject *object, std::string const &name)
{
    _sceneManager.addObjectTo(object, name);
}

/* SETTERS */

void App::setCurrentScene(size_t const &scene)
{
    _sceneManager.setCurrentScene(scene);
}

void App::setCurrentScene(std::string const &name)
{
    _sceneManager.setCurrentScene(name);
}

/* GETTERS */

SceneManager App::getSceneManager(void)  const
{
    return _sceneManager;
}