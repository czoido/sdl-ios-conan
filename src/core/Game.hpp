#pragma once

#include <box2d/box2d.h>

namespace Game {

    extern int SCREEN_WIDTH;
    extern int SCREEN_HEIGHT;
    extern float WORLD_WIDTH;
    extern float WORLD_HEIGHT;
    extern float SCALEX;
    extern float SCALEY;

    const b2Vec2& screen2world(const b2Vec2&);
    const b2Vec2& world2screen(const b2Vec2&);
};
