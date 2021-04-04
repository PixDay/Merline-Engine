/*
** File name :
** core.cpp
** File creator :
** Adrien Colombier
*/

#include "core.hpp"

App::App():
    _window(new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML Engine", sf::Style::Fullscreen)),
    _leaveKey(sf::Keyboard::Key::Escape),
    _fps(144)
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
        if (fpsPassed()) {
            _window->clear(sf::Color::Black);
            _sceneManager.onCollideTrigger();
            draw();
            _window->display();
        }
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

/* ADDERS */

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

void App::addInput(Input *input)
{
    _inputManager.addInput(input);
}

void App::addInput(std::string const &keyName, sf::Keyboard::Key key)
{
    _inputManager.addInput(keyName, key);
}

void App::addCollisionPair(std::string const &tag1, std::string const &tag2)
{
    _sceneManager.addCollisionPair(tag1, tag2);
}

/* DELETERS */

void App::deleteCollisionPair(std::string const &tag1, std::string const &tag2)
{
    _sceneManager.deleteCollisionPair(tag1, tag2);
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

float App::getTick(void)
{
    float res = _clock.getElapsedTime().asSeconds();

    return res;
}

bool App::fpsPassed(void)
{
    float res = _clock.getElapsedTime().asSeconds();

    if (res >= 1.0f / _fps) {
        _clock.restart();
        return true;
    }
    return false;
}