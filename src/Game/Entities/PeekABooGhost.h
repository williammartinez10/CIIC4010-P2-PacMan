#pragma once

#include "Ghost.h"

class PeekABooGhost : public Ghost {
    public:
        PeekABooGhost(int x, int y, int width, int height, ofImage sprite, EntityManager* em, string color);

};
