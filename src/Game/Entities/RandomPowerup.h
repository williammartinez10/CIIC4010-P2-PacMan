#pragma once

#include "Powerup.h"


class RandomPowerup : public Powerup {
    public:
        RandomPowerup(int, int, int, int, ofImage, EntityManager*, string);
        ~RandomPowerup();
        void activate();
};