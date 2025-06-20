/* İpek Gültekin 2526390
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */

#include "Battle_Ship.h"
#include <iostream>
using namespace std;

Battle_Ship::Battle_Ship(int size, int hits_to_destroy, int laser_bursts){
    this->size = size;
    this->hits_to_destroy = hits_to_destroy;
    this->laser_bursts = laser_bursts;
    status = ShipStatus::OPERATIVE; //initially the ship is operational
}

Battle_Ship::~Battle_Ship() { //Destructor
    cout << "Deleting Battle_Ship" << endl;
}

void Battle_Ship::markHit() {
    if (status == ShipStatus::SUNK) //if the ship has already sunk, return
        return ;
    hits_to_destroy--; //reduce the ship's hit area (I think that it as its life)
    if (hits_to_destroy <= 0) { //if it is died, ship will be sunk
        status = ShipStatus::SUNK;
    } else { //if only get damaged, ship will be damaged status
        status = ShipStatus::DAMAGED;
    }
}

bool Battle_Ship::occupiesCell(char row, int col) const { //when hit at a coordinate, it checks whether there is a ship at that coordinate or not
    for (int i = 0; i < size; i++) {
        if (positions[i].row == row && positions[i].col == col) { //if there is a ship return true
            return true;
        }
    }
    return false; //if there is no ship, return false
}

void Battle_Ship::setPosition(int index, char row, int col) { //it records the coordinates of the ship one by one down to its size
    if (index >= 0 && index < size) {
        positions[index].row = row;
        positions[index].col = col;
    }
}

shipPosition Battle_Ship::getPosition(int index) const { //it returns the ship position
    return positions[index];
}


int Battle_Ship::getSize() const {
    return size;
}

int Battle_Ship::getLaserBursts() const {
    return laser_bursts;
}

char Battle_Ship::getSymbol() const {
    return symbol;
}

ShipStatus Battle_Ship::getStatus() const {
    return status;
}

bool Battle_Ship::isSunk() const { //it checks the ship's sunk status
    return status == ShipStatus::SUNK;
}

int Battle_Ship::getRemainingHits() const {
    return hits_to_destroy;
}
