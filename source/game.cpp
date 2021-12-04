#include "shooter.h"

void instantiateGame(App &app) {
    DisplayableObject *background       = new DisplayableObject("img/gameBackground.png");
    DisplayableObject *bottomDecoration = new DisplayableObject("img/bottomDecoration.png");
    DisplayableObject *QSpell           = new DisplayableObject("img/QSpell.png", QSpellFunction);
    DisplayableObject *WSpell           = new DisplayableObject("img/WSpell.png", WSpellFunction);
    DisplayableObject *ESpell           = new DisplayableObject("img/ESpell.png", ESpellFunction);
    DisplayableObject *RSpell           = new DisplayableObject("img/RSpell.png", RSpellFunction);
    DisplayableObject *DSpell           = new DisplayableObject("img/DSpell.png", DSpellFunction);
    DisplayableObject *FSpell           = new DisplayableObject("img/FSpell.png", FSpellFunction);

    app.addObjectTo(background, "game");
    app.addObjectTo(bottomDecoration, "game");
    app.addObjectTo(QSpell, "game");
    app.addObjectTo(WSpell, "game");
    app.addObjectTo(ESpell, "game");
    app.addObjectTo(RSpell, "game");
    app.addObjectTo(DSpell, "game");
    app.addObjectTo(FSpell, "game");
}

void QSpellFunction(GameObject *self)
{

}

void WSpellFunction(GameObject *self)
{

}

void ESpellFunction(GameObject *self)
{

}

void RSpellFunction(GameObject *self)
{

}

void DSpellFunction(GameObject *self)
{

}

void FSpellFunction(GameObject *self)
{

}