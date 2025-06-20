//
// Created by ipekg on 22.05.2025.
//
/* İpek Gültekin 2526390
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */

#include "MonCalamariCruiser.h"
#include <iostream>
using namespace std;

MonCalamariCruiser::MonCalamariCruiser() : Battle_Ship(4, 3, 4) {
    symbol = '4'; //the symbol to be displayed on the grid will be 4
}

int MonCalamariCruiser::shoot() const {
    cout << "Mon Calamari Cruiser firing " << laser_bursts << " shots!" << endl;
    return laser_bursts;
}