//
// Created by ipekg on 22.05.2025.
//
/* İpek Gültekin 2526390
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */

#include "XWingSquadron.h"
#include <iostream>
using namespace std;

XWingSquadron::XWingSquadron() : Battle_Ship(3, 2, 2) {
    symbol = '3'; //the symbol to be displayed on the grid will be 3
}

int XWingSquadron::shoot() const {
    cout << "X-Wing Squadron firing " << laser_bursts << " shots!" << endl;
    return laser_bursts;
}

