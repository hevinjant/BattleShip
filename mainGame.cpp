// Hevin Jant @00303635
// CS110B Extra Credit BattleShip

#include "PointCollection.h"
#include "Ship.h"
#include "Board.h"
#include <iostream>
#include <ctime>

using namespace std;


// Notes:
// To display all the ships and its points,
// go to Ship.h and change the 'points' to public,
// go to Board.cpp -> Board::Board() and uncomment 'Show Ships'.

void play(PointCollection &usersCoordinate, Board &game);
int isDigit(int n);

int main() {
    srand(time(0));
    
    char option;
    
    do {
//        Board game;
//        Board *gamePtr = &game;
        Board *gamePtr = new Board;
        
//        PointCollection coordinates;
//        PointCollection *coordinatesPtr = &coordinates;
        PointCollection *coordinatesPtr = new PointCollection;
        
        
        cout << "__/o\\__                           __/o\\__" << endl;
        cout << "\\_o_o_/ ! Welcome to Battleship ! \\_o_o_/" << endl;
        cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
        cout << endl;
        
        do {
            gamePtr->display();
            play(*coordinatesPtr,*gamePtr);
        } while(gamePtr->unsunkShipCount() != 4);
        
        gamePtr->display();
        cout << "You just shot all the ships !" << endl;
        
        delete gamePtr;
        gamePtr = NULL;
        
        delete coordinatesPtr;
        coordinatesPtr = NULL;
        
        cout << "Battle again ? (y/n) ";
        cin >> option;
    } while(option == tolower('y'));
    
    return 0;
}

void play(PointCollection &usersCoordinate, Board &game) {
    string input_x, input_y;
    int x,y;
    point *input;

    do {
        cout << "Enter a coordinate 'x' and 'y' with a space: ";
        cin >> input_x >> input_y;

        x = atoi(input_x.c_str());
        y = atoi(input_y.c_str());

        input = new point(x, y);
 
    } while(usersCoordinate.contains(*input) || x < 0 || y < 0 || x > 9 || y > 9);
    
    usersCoordinate.add(*input);
    if (game.fireShot(x,y)) {
        cout << "HIT !" << endl;
    }
    else {
        cout << "MISS." << endl;
    }
    
    delete input;
    input = NULL;
}

int isDigit(int n) {
    if (n >= '0' && n <= '9') {
        return 1;
    }
    return 0;
}

/* Output:
 
 __/o\__                           __/o\__
 \_o_o_/ ! Welcome to Battleship ! \_o_o_/
 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 
 9 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 8 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 7 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 6 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 5 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 4 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 3 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 2 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 1 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 0 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 0 1 2 3 4 5 6 7 8 9
 Enter a coordinate 'x' and 'y' with a space: 5 2
 MISS.
 9 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 8 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 7 ~ . ~ ~ ~ ~ ~ ~ ~ ~
 6 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 5 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 4 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 3 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 2 ~ ~ ~ ~ ~ . ~ ~ ~ ~
 1 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 0 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 0 1 2 3 4 5 6 7 8 9
 Enter a coordinate 'x' and 'y' with a space: 7 7
 HIT !
 You sank a ship with length 2
 9 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 8 ~ ~ ~ ~ ~ ~ ~ x ~ ~
 7 ~ . ~ ~ ~ ~ ~ x ~ ~
 6 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 5 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 4 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 3 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 2 ~ ~ ~ ~ ~ . ~ ~ ~ ~
 1 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 0 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 0 1 2 3 4 5 6 7 8 9
 Enter a coordinate 'x' and 'y' with a space: 6 1
 HIT !
 You sank a ship with length 2
 You sank a ship with length 3
 You sank a ship with length 4
 You sank a ship with length 5
 9 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 8 ~ ~ ~ ~ ~ ~ ~ x ~ ~
 7 ~ . ~ ~ ~ ~ ~ x ~ ~
 6 ~ ~ ~ ~ ~ . ~ ~ ~ ~
 5 ~ ~ ~ ~ x x x ~ ~ ~
 4 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 3 ~ x x x x ~ ~ ~ ~ ~
 2 ~ ~ ~ ~ ~ . ~ ~ ~ ~
 1 ~ ~ x x x x x ~ ~ ~
 0 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 0 1 2 3 4 5 6 7 8 9
 You just shot all the ships !
 Battle again ? (y/n)
 
 */
