#ifndef ASSIGNMENT3_2025_PLAYER_H
#define ASSIGNMENT3_2025_PLAYER_H

#include "Battle_Ship.h"
#include <iostream>
/* İpek Gültekin 2526390
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */

using namespace std;
// since Wrath of Titans has the maximum size, I set the max points by referencing its size (12x12)
const int MAX_ROWS = 12;
const int MAX_COLS = 12;


class Player {
private:
    char* name;
    int shipCount=0; //assumed that at the beginning there is no ship
    Battle_Ship* fleet[12]; //player's fleet is a maximum of 12 ships
    char attack_grid[MAX_ROWS][MAX_COLS];
    char player_grid[MAX_ROWS][MAX_COLS];

    //for gift system, I defined for these variables
    int reducedShotsNextRound = 0;
    bool forceSingleShotNextRound = false;
    bool shootAgainFlag = false;

    //for the printStatistics function, I declared these integers to track some values
    int totalShots = 0;
    int totalHits = 0;
    int totalMisses = 0;
    int lostCells = 0;
    int lostStarDestroyer = 0;
    int lostMonCalamari = 0;
    int lostXWing = 0;
    int lostTIE = 0;

public:
    Player(char*);
    ~Player();
    void initializeGridTable(); //show the grid table at the beginning with "."
    void displayGrid(); //it displays player and attacker's grid
    void addShip(Battle_Ship*); //to add a new ship
    char* getName(); //getter
    bool allShipsSunk(); //to check the all ships (are they all sunk? if they are, the game will be ends)
    Battle_Ship** getFleet(); //return fleet array
    int getShipCount() const; //return num of ships

    void deploy_player(int);
    void takeTurn(Player& enemy);

    // Bonus sistemi
    void applyGift(Player& enemy, int giftId);
    void bonusAddShip(Battle_Ship* ship);

    // Stats
    void printStats();
    bool getShootAgainFlag() const;
    void resetShootAgainFlag();
    void placeShipOnGrid(Battle_Ship *ship);//take coordinates from user and place ship
};

#endif //ASSIGNMENT3_2025_PLAYER_H
