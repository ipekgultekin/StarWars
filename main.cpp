/* İpek Gültekin 2526390
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by me only */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"

using namespace std;

int main() {
    srand(time(0)); // I used srand to randomise the gift system and the starting player

    char player1Name[50], player2Name[50];
    int mode;

    cout << "Welcome to Galactic Battle NCC!\n";
    cout << "Enter Player 1 name: ";
    cin >> player1Name;
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "\nSelect Battle Mode:\n";
    cout << "1.The Swiftstrike (5x8)\n";
    cout << "2.The Starlight Clash (8x10)\n";
    cout << "3.Wrath of Titans (10x12)\n";
    cout << "Enter mode: ";
    cin >> mode;

    //create player objects
    Player p1(player1Name);
    Player p2(player2Name);

    cout << "\n--- " << player1Name << "'s turn to place ships ---\n";
    p1.deploy_player(mode);

    cout << "\n--- " << player2Name << "'s turn to place ships ---\n";
    p2.deploy_player(mode);

    cout << "\nAll ships deployed. Lets begin!\n";

    bool isP1Turn;
    int first = rand() % 2;
    if (first == 0) {
        isP1Turn = true;
        cout << "\nRandomizing first player... " << player1Name << " will start!\n";
    } else {
        isP1Turn = false;
        cout << "\nRandomizing first player... " << player2Name << " will start!\n";
    }

    int round = 1;

    while (true) {
        cout << "\n========== ROUND " << round << " ==========\n";

        if (isP1Turn) {
            cout << p1.getName() << "'s turn:\n";
            p1.takeTurn(p2);

            if (p2.allShipsSunk()) {
                cout << p1.getName() << " WINS THE BATTLE!\n";
                break;
            }

            if (p1.getShootAgainFlag()) {
                cout << "Gift 5 Activated → " << p1.getName() << " gets another turn immediately!\n";
                p1.resetShootAgainFlag();
                continue;
            }
        } else {
            cout << p2.getName() << "'s turn:\n";
            p2.takeTurn(p1);

            if (p1.allShipsSunk()) {
                cout << p2.getName() << " WINS THE BATTLE!\n";
                break;
            }

            if (p2.getShootAgainFlag()) {
                cout << "You earned Gift 5!!!" << p2.getName() << " gets another turn immediately!\n";
                p2.resetShootAgainFlag();
                continue;
            }
        }

        cout << "\nROUND " << round << " STATS:\n";
        p1.printStats();
        p2.printStats();

        if (isP1Turn) {
            isP1Turn = false;
        } else {
            isP1Turn = true;
        }

        round++;
    }

    // when all ships are sunk, the final grids and endgame message are printed
    cout << "\nFINAL GRIDS:\n";
    p1.displayGrid();
    p2.displayGrid();

    cout << "\nBattle Complete!!!\n";

    return 0;
}
