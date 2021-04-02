#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board
{
private:
    // The ship array. Four pointers to ships
    Ship *ships[4];
    
    // A PointCollection to store shots fired and missed
    PointCollection misses;
    
    // A helper method that dynamically allocates a ship object
    // with the given length, and a random origin and orientation.
    // The ship is placed such that it fits on the board,
    // i.e. a HORIZONTAL ship at origin (9,1) and length 4
    // cannot be placed on the board.  Additionally, the
    // ship is placed such that it does not collide with
    // any other ships on the board.
    Ship* generateShipWithLength(int l);
public:
    // A constructor which creates four randomly placed and
    // oriented ships and stores pointers to them into the
    // ships array. The ships have the following lengths:
    // 5, 4, 3, 2
    Board();
    
    // A destructor which deallocates ships which were allocated
    // using generateShipWithLength(), i.e. the ships which
    // are pointed at by the ships array
    ~Board();
    
    // Updates state to account for a shot at (x, y), i.e.
    // if there is a ship at (x, y) the ship now knows it
    // is hit at (x, y).  If there is no ship at (x, y) then
    // the board has recorded this in its misses PointCollection
    bool fireShot(int x, int y);
    
    // Returns the number of ships that have not yet been sunk
    int unsunkShipCount();
    
    // Draws a grid display showing hits, misses and empty
    // squares
    void display();
};

#endif
