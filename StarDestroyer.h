//
// Created by ipekg on 22.05.2025.
//
/* İpek Gültekin 2526390
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */

#ifndef ASSIGNMENT3_2025_STARDESTROYER_H
#define ASSIGNMENT3_2025_STARDESTROYER_H


#include "Battle_Ship.h"

//size:5, hits to destroy:4
//subclass of Battle_Ship
class StarDestroyer : public Battle_Ship{
public:
    StarDestroyer();//default constructor
    int shoot() const override;//function indicating the ship's power

};


#endif //ASSIGNMENT3_2025_STARDESTROYER_H
