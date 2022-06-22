#pragma once

#include "Powerup.h"


class InvisiblePowerup : public Powerup {
    public:
        InvisiblePowerup(int, int, int, int, ofImage, EntityManager*, string);
        ~InvisiblePowerup();
        void activate();
};