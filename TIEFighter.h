//
// Created by ipekg on 22.05.2025.
//
/* İpek Gültekin 2526390
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */

#ifndef ASSIGNMENT3_2025_TIEFIGHTER_H
#define ASSIGNMENT3_2025_TIEFIGHTER_H

#include "Battle_Ship.h"

//size:1, hits to destroy:1
//subclass of Battle_Ship
class TIEFighter : public Battle_Ship {
public:
    TIEFighter(); //default constructor
    int shoot() const override; //function indicating the ship's power
};



#endif //ASSIGNMENT3_2025_TIEFIGHTER_H
