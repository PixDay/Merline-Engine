/*
** File name :
** sceneManager.cpp
** File creator :
** Adrien Colombier
*/

#include "sceneManager.hpp"

SceneManager::SceneManager():
_currentScene(0)
{
    this->addScene("SFML-Engine-default");
    //_window->setVerticalSyncEnabled(true);
}

/* ADDERS */
 
void SceneManager::addScene(std::string const &name)
{
    Scene *scene = new Scene(name);

    _scenes.emplace_back(scene);
   // _scenes[this->getScene(name)]->addObject(
   //     dynamic_cast<GameObject *>(
   //     dynamic_cast<DisplayableObject *>(_cursor)
   //     )
   // );
}

void SceneManager::addObject(GameObject *object)
{
    _scenes[_currentScene]->addObject(object);
}

void SceneManager::addObjectTo(GameObject *object, std::string const &name)
{
    _scenes[this->getScene(name)]->addObject(object);
}

/* DELETERS */

void SceneManager::deleteScene(std::string const &name)
{
    size_t iterator = 0;

    for (auto scene : _scenes) {
        if (scene->getName() == name) {
            _scenes.erase(_scenes.begin() + iterator);
            delete scene;
            break;
        }
        iterator++;
    }
}

/* SETTERS */

void SceneManager::setCurrentScene(size_t const &scene)
{
    _currentScene = scene;
}

void SceneManager::setCurrentScene(std::string const &name)
{
    size_t iterator = 0;

    for (auto scene : _scenes) {
        if (scene->getName() == name) {
            _currentScene = iterator;
            break;
        }
        iterator++;
    }
}

/* GETTERS */

std::vector<Scene *>    SceneManager::getScenes()                                                   const
{
    return _scenes;
}

size_t                  SceneManager::getCurrentScene()                                             const
{
    return _currentScene;
}

size_t                  SceneManager::getScene(std::string const &name)                             const
{
    size_t iterator = 0;

    for (auto scene : _scenes) {
        if (scene->getName() == name)
            return iterator;
        iterator++;
    }
    return _currentScene;
}

bool                    SceneManager::collide(std::string const &tag1, std::string const &tag2)     const
{
  (void)tag1, tag2;
    /*DisplayableObject *object1 = nullptr;
    DisplayableObject *object2 = nullptr;
    
    for (auto object : _scenes[_currentScene]->getGameObjects()) {
        if (object->getTag() == tag1)
            object1 = static_cast<DisplayableObject *>(object);
        if (object->getTag() == tag2)
            object2 = static_cast<DisplayableObject *>(object);
    }
    if (object1 == nullptr || object2 == nullptr)
        return false;
    sf::Rect<float> obj1(
        object1->getPosition(), 
        {(float)object1->getSprite()->getTexture()->getSize().x, 
         (float)object1->getSprite()->getTexture()->getSize().y}
    );
    sf::Rect<float> obj2(
        object2->getPosition(), 
        {(float)object2->getSprite()->getTexture()->getSize().x, 
         (float)object2->getSprite()->getTexture()->getSize().y}
    );
    return obj1.intersects(obj2);*/
    return false;
}