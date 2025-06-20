#ifndef ASSIGNMENT3_2025_BATTLE_SHIP_H
#define ASSIGNMENT3_2025_BATTLE_SHIP_H
/* İpek Gültekin 2526390
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */

struct shipPosition { // I defined struct to hold the position (as a row and column) of each ship cell
    char row;
    int col;
};

enum class ShipStatus { // I defined struct to track the ship's status
    OPERATIVE,
    DAMAGED,
    SUNK
};

class Battle_Ship {
protected:
    int size;
    int hits_to_destroy;
    int laser_bursts;
    ShipStatus status;
    shipPosition positions[5];
    char symbol;
public:
    virtual ~Battle_Ship();
    Battle_Ship(int size, int hits_to_destroy, int laser_bursts);
    virtual int shoot() const = 0; //abstract class
    int getSize() const;
    int getLaserBursts() const;
    char getSymbol() const;
    ShipStatus getStatus() const;
    bool isSunk() const;
    int getRemainingHits() const;
    void markHit();
    bool occupiesCell(char row, int col) const;
    void setPosition(int index, char row, int col);
    shipPosition getPosition(int index) const;
};

#endif //ASSIGNMENT3_2025_BATTLE_SHIP_H
