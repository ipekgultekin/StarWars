//
// Created by ipekg on 22.05.2025.
//
/* İpek Gültekin 2526390
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */

#include "StarDestroyer.h"
#include <iostream>
using namespace std;

StarDestroyer::StarDestroyer() : Battle_Ship(5, 4, 3) {
    symbol = '5'; //the symbol to be displayed on the grid will be 5
}

int StarDestroyer::shoot() const {
    cout << "Star Destroyer firing " << laser_bursts << " shots!" << endl;
    return laser_bursts;
}