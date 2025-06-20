//
// Created by ipekg on 22.05.2025.
//
/* İpek Gültekin 2526390
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */

#include "TIEFighter.h"
#include <iostream>
using namespace std;

TIEFighter::TIEFighter() : Battle_Ship(1, 1, 1) {
    symbol = '1'; //the symbol to be displayed on the grid will be 1
}

int TIEFighter::shoot() const {
    cout << "TIE Fighter firing " << laser_bursts << " shots!" << endl;
    return laser_bursts;
}
