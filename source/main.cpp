#include <iostream>
#include "core.hpp"
#include "gameObject.hpp"
#include "ui.hpp"
#include "scene.hpp"
#include "sceneManager.hpp"

int main()
{
    App app = App();    
    GameObject object = GameObject();
    Scene scene = Scene("Gaming");

    std::cout << object.getType() << std::endl;
    std::cout << scene.getName() << std::endl;
    app.run();
    return 0;
}