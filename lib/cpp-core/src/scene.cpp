/*
** File name :
** scene.cpp
** File creator :
** Adrien Colombier
*/

#include "scene.hpp"
#include <algorithm>

Scene::Scene(std::string const &name):
_name(name)
{
}

/* ADDERS */
void Scene::addObject(GameObject * const gameObject)
{
    _gameObjects.push_back(gameObject);
    std::sort(_gameObjects.begin(), _gameObjects.end(), [](const GameObject* lhs, const GameObject* rhs) {
        return lhs->getLayout() < rhs->getLayout();
    });
}

/* DELETERS */
void Scene::deleteObject(std::string const &tag)
{
    size_t iterator = 0;

    for (auto gameObject : _gameObjects) {
        if (gameObject->getTag() == tag) {
            delete _gameObjects[iterator];
            _gameObjects.erase(_gameObjects.begin() + iterator);
            break;
        }
        iterator++;
    }
}

void Scene::deleteObject(size_t const &index)
{
    delete _gameObjects[index];
    _gameObjects.erase(_gameObjects.begin() + index);
}

void Scene::eraseObject(std::string const &tag)
{
    size_t iterator = 0;

    for (auto gameObject : _gameObjects) {
        if (gameObject->getTag() == tag) {
            _gameObjects.erase(_gameObjects.begin() + iterator);
            break;
        }
        iterator++;
    }
}

/* SETTERS */

void Scene::setName(std::string const &name)
{
    _name = name;
}

/* GETTERS */

std::vector<GameObject *> Scene::getGameObjects() const
{
    return _gameObjects;
}

std::string Scene::getName() const
{
    return _name;
}

bool Scene::isExisting(std::string const &tag) const
{
    for (auto gameObject : _gameObjects) {
        if (gameObject->getTag() == tag)
            return true;
    }
    return false;
}