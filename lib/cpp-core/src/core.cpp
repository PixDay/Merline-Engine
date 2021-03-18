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
        // draw system
        _window->display();
    }
}