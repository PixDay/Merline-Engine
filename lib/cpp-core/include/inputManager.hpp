/*
** File name :
** inputManager.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include "input.hpp"

class InputManager
{
    public:
        InputManager();
       ~InputManager() = default;

       void addInput(Input &input);
       void deleteInput(std::string const &keyName);
       
    private:
        std::vector<Input &>    _inputs; 
};