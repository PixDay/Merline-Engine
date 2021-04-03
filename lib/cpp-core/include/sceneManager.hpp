/*
** File name :
** sceneManager.hpp
** File creator :
** Adrien Colombier
*/

#pragma once

#include "scene.hpp"
#include "displayableObject.hpp"

class SceneManager
{
    public:
        SceneManager();
       ~SceneManager() = default;

        /* ADDERS */
        void addScene(std::string const &name);
        void addObject(GameObject *object);
        void addObjectTo(GameObject *object, std::string const &name);

        /* DELETERS */
        void deleteScene(std::string const &name);

        /* SETTERS */
        void setCurrentScene(size_t const &scene);
        void setCurrentScene(std::string const &name);

        /* GETTERS */
        std::vector<Scene *>    getScenes()                                                 const;
        size_t                  getCurrentScene()                                           const;
        size_t                  getScene(std::string const &name)                           const;
        bool                    collide(std::string const &tag1, std::string const &tag2)   const;

    private:
        size_t                  _currentScene;
        std::vector<Scene *>    _scenes;
};