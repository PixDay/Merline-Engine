#pragma once

#include "core.h"

/* FUNCTIONS */

// Function : main.cpp
void initScenes             (App &app);
void initPlayer             (App &app);
void initEnemy              (App &app);
void initOptions            (App &app);
void initMenu               (App &app);

// Function : initScene.cpp
void createScenes           (App &app);

// Function : menu.cpp
void instantiateMenu        (App &app);
void playButtonFunction     (GameObject *self);
void optionsButtonFunction  (GameObject *self);
void exitButtonFunction     (GameObject *self);

// Function : game.cpp
void instantiateGame        (App &app);
void instantiateGameOver    (App &app);
void QSpellFunction         (App &app);
void WSpellFunction         (App &app);
void ESpellFunction         (App &app);
void RSpellFunction         (App &app);
void DSpellFunction         (App &app);
void FSpellFunction         (App &app);

// Function : options.cpp
void instantiateOptions     (App &app);
