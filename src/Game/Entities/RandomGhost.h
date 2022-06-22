#pragma once
#include "EntityManager.h"
#include "Animation.h"
#include "Ghost.h"

class RandomGhost: public Ghost
{
    public:
        RandomGhost(int, int, int, int, ofImage, EntityManager*, string);
};