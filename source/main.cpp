#include <iostream>
#include "core.hpp"
#include "ui.hpp"

int main()
{
    App app = App();
    UI ui = UI();

    std::cout << ui.getTag() << std::endl;
    app.run();
    return 0;
}