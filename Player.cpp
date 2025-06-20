//
// Created by ipekg on 22.05.2025.
//
/* İpek Gültekin 2526390
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */

#include "Player.h"
#include <iostream>
#include <cstring>

#include "MonCalamariCruiser.h"
#include "StarDestroyer.h"
#include "TIEFighter.h"
#include "XWingSquadron.h"
using namespace std;

Player::Player(char *name) { //parametrized constructor
    this->name = new char[strlen(name) + 1];
    strcpy(this->name,name);
    shipCount = 0;
    initializeGridTable(); //create the grid table at the constructor
}

Player::~Player() { //destructor
    delete[] this->name;
    for (int i=0; i < shipCount; i++) {
        delete fleet[i]; //for each fleet clean the memory
    }
}

void Player::initializeGridTable() {
    for (int i=0; i < MAX_ROWS; i++) {
        for (int j=0; j < MAX_COLS; j++) {
            player_grid[i][j] = '*';
            attack_grid[i][j] = '*';
        }
    }
}

void Player::displayGrid() {
    cout << "\nPlayer: " << name << "\n\n";
    cout << "Your Fleet\t\t\t\tAttack Board\n";
    cout << "  ";
    for (int j = 0; j < MAX_COLS; j++) { //for your fleet's grid
        if (j + 1 < 10) //since numbers 10 and above are two digits, I used if to avoid alignment issues
            cout << j + 1 << " ";
        else
            cout << j + 1;
    }

    cout << "\t  ";
    for (int j = 0; j < MAX_COLS; j++) { //for enemy's grid
        if (j + 1 < 10)
            cout << j + 1 << " ";
        else
            cout << j + 1;
    }

    cout << endl;
    for (int i = 0; i < MAX_ROWS; i++) {
        char row_label = 'a' + i; //increases the ASCII value of a by i each time
        cout << row_label << " ";
        for (int j = 0; j < MAX_COLS; j++) {
            cout << player_grid[i][j] << " "; //places the player's grid
        }
        cout << "\t" << row_label << " ";
        for (int j = 0; j < MAX_COLS; j++) {
            cout << attack_grid[i][j] << " "; //places the attacker's grid
        }
        cout << endl;
    }
    cout << endl;
}

void Player::addShip(Battle_Ship *ship) {
    if (shipCount<12) { //the max ship count is 12 so if there is no full, then add new ship
        fleet[shipCount++] = ship;
    }
    else
        cout<<"Hey! Ship count is full!"<<endl;
}

char* Player::getName() {
    return name;
}

bool Player::allShipsSunk() {
    for (int i=0; i < shipCount; i++) { //check all the ships whether they are sunk or not
        if (!fleet[i]->isSunk()) { //if still there are ships then return false
            return false;
        }
    }
    return true;
}

Battle_Ship **Player::getFleet() { //return ship list
    return fleet;
}

int Player::getShipCount() const {
    return shipCount;
}

void Player::deploy_player(int mode) {
    if (mode == 1) { // if the mode is Swiftstrike (5x8), create ship objects
        Battle_Ship* s1 = new StarDestroyer();
        placeShipOnGrid(s1);
        addShip(s1);

        Battle_Ship* s2 = new MonCalamariCruiser();
        placeShipOnGrid(s2);
        addShip(s2);

        Battle_Ship* s3 = new XWingSquadron();
        placeShipOnGrid(s3);
        addShip(s3);

        for (int i = 0; i < 2; i++) { //for tie fighter, I need to create two object (according to assignment)
            Battle_Ship* tie = new TIEFighter();
            placeShipOnGrid(tie);
            addShip(tie);
        }
    }

    else if (mode == 2) { // if the mode is Starlight Clash (8x10)
        for (int i = 0; i < 2; i++) { //for star destroyer in this mode, I need to create two object (according to assignment)
            Battle_Ship* sd = new StarDestroyer();
            placeShipOnGrid(sd);
            addShip(sd);
        }

        for (int i = 0; i < 2; i++) { //for mon calamari cruiser in this mode, I need to create two object (according to assignment)
            Battle_Ship* mc = new MonCalamariCruiser();
            placeShipOnGrid(mc);
            addShip(mc);
        }

        for (int i = 0; i < 2; i++) { //for x wing squadron in this mode, I need to create two object (according to assignment)
            Battle_Ship* xw = new XWingSquadron();
            placeShipOnGrid(xw);
            addShip(xw);
        }

        for (int i = 0; i < 4; i++) { //for tie fighter in this mode , I need to create four object (according to assignment)
            Battle_Ship* tf = new TIEFighter();
            placeShipOnGrid(tf);
            addShip(tf);
        }
    }

    else if (mode == 3) { // if the mode is Wrath of Titans (10x12)
        for (int i = 0; i < 4; i++) { //for star destroyer in this mode , I need to create four object (according to assignment)
            Battle_Ship* sd = new StarDestroyer();
            placeShipOnGrid(sd);
            addShip(sd);
        }

        for (int i = 0; i < 3; i++) { //for mon calamari cruiser in this mode , I need to create three object (according to assignment)
            Battle_Ship* mc = new MonCalamariCruiser();
            placeShipOnGrid(mc);
            addShip(mc);
        }

        for (int i = 0; i < 2; i++) { //for x wing squadron in this mode , I need to create two object (according to assignment)
            Battle_Ship* xw = new XWingSquadron();
            placeShipOnGrid(xw);
            addShip(xw);
        }

        for (int i = 0; i < 4; i++) { //for tie fighter in this mode , I need to create four object (according to assignment)
            Battle_Ship* tf = new TIEFighter();
            placeShipOnGrid(tf);
            addShip(tf);
        }
    }
}


void Player::placeShipOnGrid(Battle_Ship* ship) {
    bool valid = false;
    displayGrid();
    while (!valid) { //loop continues until the ship is positioned correctly
        string startCoord, endCoord;
        cout << "You are placing a ship of size: " << ship->getSize() << endl;
        cout << "Enter start coordinate: ";
        cin >> startCoord;
        cout << "Enter end coordinate: ";
        cin >> endCoord;

        //I wanted to separate the start and end coordinates into rows and columns (e.g. a1= rowchar a, col 1)
        char startRowChar = startCoord[0]; //displays the first character (such as 'a' in the example above)
        int startCol = stoi(startCoord.substr(1)); //I used stoi to convert the second character to a number
        //I did the same for the end coordinates
        char endRowChar = endCoord[0];
        int endCol = stoi(endCoord.substr(1));

        //converts letters to index (ascii rule)
        int startRow = startRowChar - 'a';
        int endRow = endRowChar - 'a';
        //-1 because the starting address of the arrays is 0
        int startColIndex = startCol - 1;
        int endColIndex = endCol - 1;

        if (startRow < 0 || startRow >= MAX_ROWS || endRow < 0 || endRow >= MAX_ROWS ||
            startColIndex < 0 || startColIndex >= MAX_COLS || endColIndex < 0 || endColIndex >= MAX_COLS) { //if an invalid coordinate is entered, an error is returned
            cout << "Error! Coordinates out of bounds! Try again.\n";
            continue;
        }

        //calculates the start and end points of the ship
        int rowDiff = endRow - startRow;
        int colDiff = endColIndex - startColIndex;

        bool isHorizontal = (startRow == endRow);
        bool isVertical = (startColIndex == endColIndex);
        bool isDiagonal = (rowDiff == colDiff) || (rowDiff == -colDiff); //if the placement is diagonal, the difference between columns and rows are equal in absolute value, but since I cannot show this with absolute, I checked whether the differences are equal or have a negative sign

        if (!(isHorizontal || isVertical || isDiagonal)) { //if invalid placement
            cout << "Error! You can only horizontal, vertical or diagonal placement is allowed.\n";
            continue;
        }

        int distance = max((rowDiff>=0 ? rowDiff : -rowDiff), (colDiff>=0 ? colDiff : -colDiff)) + 1; // to calculate the distance between the coordinates entered by the user, take the largest of the directions and add 1 to get the total distance
        if (distance != ship->getSize()) { //if the coordinates are not matched with ship size give error message
            cout << "Error! Your entered coordinates do not match with ship size (" << ship->getSize() << "). Try again.\n";
            continue;
        }

        // stepRow and stepCol determine the direction in which the ship moves. To determine the direction, check whether the difference is positive, negative or zero
        //0:no progress(same row/column), >0:to forward(or diagonal), <0:go back(or diagonal)
        int stepRow = (rowDiff == 0) ? 0 : (rowDiff > 0 ? 1 : -1);
        int stepCol = (colDiff == 0) ? 0 : (colDiff > 0 ? 1 : -1);

        //check if there are any other ships in the coordinates
        bool overlap = false;
        int r = startRow, c = startColIndex;
        for (int i = 0; i < ship->getSize(); i++) {
            if (player_grid[r][c] != '*') { //if it is not empty, then overlap
                overlap = true;
                break;
            }
            r += stepRow;
            c += stepCol;
        }

        if (overlap) { //if there is an overlap, it gives error message
            cout << "Ship overlaps with another. Try different coordinates.\n";
            continue;
        }

        // if there is no overlap, displace the ship
        r = startRow;
        c = startColIndex;
        for (int i = 0; i < ship->getSize(); i++) {
            player_grid[r][c] = ship->getSymbol(); //write to grid the ship's symbol (I define each symbol of ship types other .cpp files)
            ship->setPosition(i, r + 'a', c + 1); //it arranges the position of ship in the shipPosition method
            r += stepRow;
            c += stepCol;
        }

        valid = true; //successful displacement recorded
    }
}

void Player::takeTurn(Player& enemy) {
    int maxShots = 0; //at the beginning it is 0
    if (forceSingleShotNextRound) { //if only 1 shot was given as a gift, allow 1 shot and return to the previous state
        maxShots = 1;
        forceSingleShotNextRound = false;
    } else {
        for (int i = 0; i < shipCount; i++) {
            if (!fleet[i]->isSunk()) { //find as many not sunk ships as there are ships
                maxShots = max(maxShots, fleet[i]->getLaserBursts()); //give max
            }
        }
        if (reducedShotsNextRound > 0 && maxShots > 1) {  // if there is a penalty of ‘one shot reduction’ and there are at least 2 shots remaining, reduce by 1
            maxShots--;
            reducedShotsNextRound--;
        }
    }

    //player is informed how many times they can shoot
    cout << "\n" << name << ", it's your turn. You can shoot " << maxShots << " time(s).\n";

    int shotsDone = 0; //num of shots
    int hitsThisTurn = 0; //num of hits

    while (shotsDone < maxShots) { //player do shots as much as player can
        string coord;
        cout << "Enter coordinate to shoot (e.g., b4): ";
        cin >> coord;

        if (coord.length() < 2) { //if length is less than two, it becomes unvalid format
            cout << "Invalid format! Try again.\n";
            continue;
        }

        char rowChar = coord[0]; //take first character entered coordinate

        // if player enter upper case characters give error message
        if (rowChar < 'a' || rowChar > 'z') {
            cout << "Invalid char!! You can only use lower case characters!\n";
            continue;
        }

        int row = rowChar - 'a';  //converts the entered letter to a line index starting from zero (ascii idea)

        // same thing like at the beginning
        int col = stoi(coord.substr(1)); //takes the number after the char (a for ex.) and return to the integer ( col=int )
        int colIndex = col - 1; //same (starting index is 0 so -1 required)


        if (row < 0 || row >= MAX_ROWS || colIndex < 0 || colIndex >= MAX_COLS) { //check the coordinates whether it is valid or not
            cout << "Invalid coordinate! Out of bounds.\n";
            continue;
        }

        if (attack_grid[row][colIndex] != '*') { //if player already shot this coordinate give error
            cout << "You've already shot here! Try a different coordinate.\n";
            continue;
        }

        char target = enemy.player_grid[row][colIndex]; // record the cell targeted from the other side's grid

        if (target != '*') {
            cout << "Lucky You!!! HIT!\n";
            attack_grid[row][colIndex] = target;
            hitsThisTurn++;

            Battle_Ship** enemyFleet = enemy.getFleet(); //check the enemy's ships to find which ship hit
            for (int i = 0; i < enemy.getShipCount(); i++) {
                if (enemyFleet[i]->occupiesCell(rowChar, col)) {
                    enemyFleet[i]->markHit(); //marked
                    if (enemyFleet[i]->isSunk()) {
                        int size = enemyFleet[i]->getSize();
                        lostCells += size;
                        switch (size) { //the counters of the ship types are updated according to the sunken ship (whichever one is sunk increases by 1)
                            case 5: lostStarDestroyer++; break;
                            case 4: lostMonCalamari++; break;
                            case 3: lostXWing++; break;
                            case 1: lostTIE++; break;
                        }
                        for (int j = 0; j < enemyFleet[i]->getSize(); j++) { // to make all positions of the sunken ship visible
                            shipPosition pos = enemyFleet[i]->getPosition(j);
                            int r = pos.row - 'a';
                            int c = pos.col - 1;
                            enemy.player_grid[r][c] = target;
                        }
                        cout << ">> You sank a ship! Full body revealed!\n";
                    }
                    break;
                }
            }
        } else { //if missed the ship
            cout << "MISS.\n";
            attack_grid[row][colIndex] = '0';
            enemy.player_grid[row][colIndex] = '0';
        }

        shotsDone++; //increment the shots num
    }

    // update the statistics
    totalShots += maxShots;
    totalHits += hitsThisTurn;
    totalMisses += (maxShots - hitsThisTurn);

    if (hitsThisTurn >= 2) { //if there is 2 or more hit, then player take bonus
        cout << "\nCongrats!! Your Bonus gift is coming...\n";
        int dice = rand() % 100 + 1;
        //according to the percentages in the gifts assignment guidelines
        if (dice <= 10)
            applyGift(enemy, 1);
        else if (dice <= 40)
            applyGift(enemy, 2);
        else if (dice <= 60)
            applyGift(enemy, 3);
        else if (dice <= 80)
            applyGift(enemy, 4);
        else
            applyGift(enemy, 5);
    }

    cout << "\n" << name << "'s updated grid:\n";
    displayGrid();
    cout << "\n" << enemy.getName() << "'s updated grid:\n";
    enemy.displayGrid();
}

void Player::applyGift(Player& enemy, int giftId) { //gives the player a gift according to the number of ships hit by the player
    if (giftId == 1) {
        cout << "Gift 1 is applied to you!! Random battleship added to your fleet!\n";
        int r = rand() % 100 + 1;

        Battle_Ship* newShip = nullptr; //initially I assumed it didn't show anything because it could be garbage variable

        if (r <= 10) { // 10% chance of a Star Destroyer
            newShip = new StarDestroyer();
            cout << "You are awarded a Star Destroyer!\n";
        } else if (r <= 30) { // 20% chance off Mon Calamari Cruiser (until %30)
            newShip = new MonCalamariCruiser();
            cout << "You are awarded a Mon Calamari Cruiser!\n";
        } else if (r <= 60) { // 30% chance off X Wing Squadron (until %60)
            newShip = new XWingSquadron();
            cout << "You are awarded an X-Wing Squadron!\n";
        } else { // 40% chance off Mon Calamari Cruiser (until %40)
            newShip = new TIEFighter();
            cout << "You are awarded a TIE Fighter!\n";
        }

        bonusAddShip(newShip); //take player coordinates and placed to ship grid
        addShip(newShip); //add new ship to player
    }

    else if (giftId == 2) { //if the player is awarded an extra shot
        cout << "Gift 2 is applied to you!! You get only ONE extra shot for this round!\n";
    }

    else if (giftId == 3) { //the enemy player's shooting in the next round is reduced by 1
        cout << "Gift 3 is applied to you!! Your enemy will have one less shot next round!\n";
        enemy.reducedShotsNextRound++;
    }

    else if (giftId == 4) {
        cout << "Gift 4 is applied to you!! Your enemy can only shoot ONCE next round!\n";
        enemy.forceSingleShotNextRound = true; //only one shot is allowed
    }

    else if (giftId == 5) { //the player is given a right to play again
        cout << "Gift 5 is applied to you!! You will take another turn right away!\n";
        shootAgainFlag = true;
    }
}


void Player::bonusAddShip(Battle_Ship* ship) { //placement of gift ships
    cout << "Enter coordinates for your bonus ship: ";
    string startCoord, endCoord;
    cin >> startCoord >> endCoord;

    // updated version of placeShipOnGrid
    placeShipOnGrid(ship);
}

void Player::printStats() { //print all the statistics
    cout << "\n=== Player Stats for: " << name << " ===\n";
    cout << "Total Shoots: " << totalShots << endl;
    cout << "Hits: " << totalHits << endl;
    cout << "Misses: " << totalMisses << endl;
    cout << "Lost: " << lostCells << " cells\n";
    cout << "Lost Star Destroyer (5): " << lostStarDestroyer << endl;
    cout << "Lost Mon Calamari Cruiser (4): " << lostMonCalamari << endl;
    cout << "Lost X-Wing Squadron (3): " << lostXWing << endl;
    cout << "Lost TIE Fighter (1): " << lostTIE << endl;

    cout << "\n-- Ship Statuses --\n";
    for (int i = 0; i < shipCount; i++) {
        Battle_Ship* ship = fleet[i];
        cout << "Ship " << (i + 1) << " [" << ship->getSymbol() << "] - ";

        ShipStatus status = ship->getStatus();
        if (status == ShipStatus::SUNK) {
            cout << "SUNK";
        } else if (status == ShipStatus::DAMAGED) {
            cout << "DAMAGED (" << ship->getRemainingHits() << " hit(s) left)";
        } else if (status == ShipStatus::OPERATIVE) {
            cout << "OPERATIVE";
        }

        cout << endl;
    }

    cout << "---------------------------\n";
}


bool Player::getShootAgainFlag() const {
    return shootAgainFlag;
}

void Player::resetShootAgainFlag() { //it resets to false
    shootAgainFlag = false;
}
