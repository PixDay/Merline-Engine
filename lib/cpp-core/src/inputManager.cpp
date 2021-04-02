/*
** File name :
** inputManager.cpp
** File creator :
** Adrien Colombier
*/

#include "inputManager.hpp"

InputManager::InputManager()
{}

void InputManager::addInput(Input *input)
{
    _inputs.push_back(input);
}

void InputManager::addInput(std::string const &keyName, sf::Keyboard &key)
{
    Input *input = new Input(keyName, key);

    _inputs.push_back(input);
}

void InputManager::deleteInput(std::string const &keyName)
{
    size_t iterator = 0;

    for (auto input : _inputs) {
        if (input->getKeyName() == keyName) {
            _inputs.erase(_inputs.begin() + iterator);
            delete input;
            break;
        }
        iterator++;
    }
}