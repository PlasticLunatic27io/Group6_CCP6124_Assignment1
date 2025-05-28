/**********|**********|**********|
Program: AbstractCapability.h
Course: Data Structures and Algorithms
Trimester: 2510
Name: Danish Bin Dzulkarnain
ID: 242UC244QJ
Lecture Section: TC3L
Tutorial Section: T10L
Email: DANISH.DZULKARNAIN@student.mmu.edu.my
Phone: 010-3650212
**********|**********|**********/
#pragma once



#include <vector>
#include <string>
using namespace std;

// Abstract Robot Interface
class Robot {
public:
    virtual void performTurn() = 0;
    virtual string getName() const = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;

    virtual bool isAlive() const = 0;
    virtual void markAsDead() = 0;
    virtual int getRespawnsRemaining() const = 0;
    virtual void decrementRespawn() = 0;
    virtual void setPosition(int x, int y) = 0;
    virtual ~Robot() {}
};

// Capability: Moving
class MovingRobot {
    public:
        virtual void move() = 0;
        virtual ~MovingRobot() {}
};

// Capability: Shooting
class ShootingRobot {
    public:
        virtual void fire(int dx, int dy) = 0;
        virtual ~ShootingRobot() {}
};

// Capability: Seeing
class SeeingRobot {
    public:
       virtual vector<vector<double>> look() = 0;
       virtual ~SeeingRobot() {}
};

// Capability: Thinking
class ThinkingRobot {
    public:
       virtual void think() = 0;
       virtual ~ThinkingRobot() {}
};
