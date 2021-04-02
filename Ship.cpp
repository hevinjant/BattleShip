#include "Ship.h"

#include<iostream>
using namespace std;

Ship::Ship(point originPoint, direction o, int l) 
{
    origin = originPoint;
    orientation = o;
    length = l;
    
    // add the points
    points.add(originPoint);
    if (orientation == HORIZONTAL) {
        for (int i = 0; i < length-1; i++) {
            point newPoint(origin.getX()+i+1,origin.getY());
            points.add(newPoint);
            //cout << "H: " << newPoint.getX() << "," << newPoint.getY() << endl;
        }
    }
    else if (orientation == VERTICAL) {
        for (int i = 0; i < length-1; i++) {
            point newPoint(origin.getX(),origin.getY()+i+1);
            points.add(newPoint);
            //cout << "V: " << newPoint.getX() << "," << newPoint.getY() << endl;
        }
    }
    /*
     points << "somepoint";
     */
}

Ship::Ship(const Ship& s) 
{
    *this = s;
}

// Check if a point is in the ship's point collection
bool Ship::containsPoint(const point& p) const
{
    for (int i = 0; i < points.getSize(); i++) {
        if (p == points.get(i)) {
            return true;
        }
    }
    return false;
}

// Check if a ship collides with other ship
bool Ship::collidesWith(const Ship& s) const
{
    for (int i = 0; i < length; i++) {
        for (int j  = 0; j < s.length; j++) {
            if (points.get(i) == s.points.get(j)) {
                return true;
            }
        }
    }
	return false;
}

// Shoot a ship at the given point
void Ship::shotFiredAtPoint(const point& p)
{
    for (int i = 0; i < length; i++) {
        if (p == points.get(i)) {
            hits.add(p);
        }
    }
}

// Check is a ship has been hit in a given point
bool Ship::isHitAtPoint(const point& p)
{
    for (int i = 0; i < hits.getSize(); i++) {
        if (p == hits.get(i)) {
            return true;
        }
    }
    return false;
}

// Count the total hits of a ship
int Ship::hitCount()
{
    //cout << "HIT: " << hits.getSize() << endl;
    return hits.getSize();
}

const Ship& Ship::operator=(const Ship& s)
{
    length = s.length;
    orientation = s.orientation;
    origin = s.origin;
    points = s.points;
    hits = s.hits;
    
	return *this;
}


//*******************************************************************************************
//  Is Sunk
//*******************************************************************************************

bool Ship::isSunk() 
{
    if (length == hitCount()) { //} hits.getSize()) {
        return true;
    }
	return false;	
}










