#include "Ship.h"
#include "Board.h"
#include <iostream>
using namespace std;

Ship* Board::generateShipWithLength(int l) {
    // handle the ship so it doesn't collide with other ships
    Ship *newShip;
    bool shipIsValid;
    do {
        // create random orientation
        direction randomDirection;
        int randomNum = rand() % 2;
        if (randomNum == 0) {
            randomDirection = HORIZONTAL;
        }
        else {
            randomDirection = VERTICAL;
        }
        // create random point
        int randomX;
        int randomY;
        if (randomDirection == VERTICAL) {
            randomX = rand() % 10;
            randomY = (rand() % (10-l));
        }
        else if (randomDirection == HORIZONTAL) {
            randomX = (rand() % (10-l));
            randomY = rand() % 10;
        }
        point randomPoint(randomX, randomY);
        
        // try to create a ship object
        shipIsValid = true;
        newShip = new Ship(randomPoint,randomDirection,l);
        for (int i = 0; i < l-2; i++) {
            if (newShip->collidesWith(*ships[i])) {
                shipIsValid = false;
                delete newShip;
            }
        }
    } while(shipIsValid == false);
    
    
    return newShip;
}

Board::Board() {
    // create four ships with length 2,3,4,5.
    for (int i = 0; i < 4; i++) {
        Ship *ship = generateShipWithLength(i+2);
        ships[i] = ship;
        
//        // *** Show Ships ***
//        cout << "***" << endl;
//        for (int j = 0; j < i+2; j++) {
//            cout << "Ship" << i+1 << " X:" << (ships[i]->points.get(j).getX());
//            cout << ",Y:" << (ships[i]->points.get(j).getY()) << endl;
//        }
//        cout << "***" << endl;
//        // ******************
        
    }
}

Board::~Board() {
    for (int i = 0; i < 4; i++) {
        delete ships[i];
        ships[i] = NULL;
    }
}

bool Board::fireShot(int x, int y) {
    point shot(x,y);
    bool hitAship = false;
    for (int i = 0; i < 4; i++) {
        ships[i]->shotFiredAtPoint(shot);
        if (ships[i]->isHitAtPoint(shot)) {
            hitAship = true;
        }
    }
    if (!hitAship) {
        misses.add(shot);
    }
    
    return hitAship;
}

int Board::unsunkShipCount() {
    int unsunkShip = 0;
    for (int i = 0; i < 4; i++) {
        if (ships[i]->isSunk()) {
            unsunkShip += 1;
            cout << "You sank a ship with length " << ships[i]->hitCount() << endl;
        }
    }

    return unsunkShip;
}

void Board::display() {
    bool hit;
    for (int y = 9; y != -1; y--) {
        cout << y << " ";
        for (int x = 0; x < 10; x++) {
            point p(x,y);
            // check if the point is in the misses or hit a ship
            if (misses.contains(p)) {
                cout << ". ";
            }
            else {
                hit = false;
                for (int i = 0; i < 4; i++) {
                    if(ships[i]->isHitAtPoint(p)) {
                        cout << "x ";
                        hit = true;
                    }
                }
                if (hit == false) {
                    cout << "~ ";
                }
            }
        }
        cout << endl;
    }
    cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
}
