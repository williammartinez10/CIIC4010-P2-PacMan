#pragma once

#include "Player.h"

class Powerup {
    protected:
        int powerupCounter = 0;
    public:
        virtual bool activate() = 0;
};