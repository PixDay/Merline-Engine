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
{};