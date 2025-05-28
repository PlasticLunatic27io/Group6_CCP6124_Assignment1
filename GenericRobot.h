/**********|**********|**********|
Program: GenericRobot.h
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

#include "AbstractCapability.h"
#include "Upgrades.h"
#include <memory>
#include "Field.h" 
#include <cstdlib>
#include <ctime>
#include <map>

class GenericRobot : public Robot, public MovingRobot, public ShootingRobot, public SeeingRobot, public ThinkingRobot 
{
private:


    bool alive = true;
    string name;
    int posX=0, posY=0;
    int respawnsRemaining = 3;
    int killCount = 0;
    int shells = 10;
    Field* field;
    vector<bool> upgrades; // 0 = move, 1 = shoot, 2 = see

    std::unique_ptr<IMovement> movement;
    std::unique_ptr<IShooting> shooting;
    std::unique_ptr<ISeeing> seeing;

    bool hasMovementUpgrade = false;
    bool hasShootingUpgrade = false;
    bool hasSeeingUpgrade = false;
public:
    GenericRobot(string name, int x, int y, Field* fieldPtr): name(name), posX(x), posY(y), field(fieldPtr), shells(10), lives(3) 
    {
        upgrades = { false, false, false }; // move, shoot, see
        srand(time(0));
    }

    bool hasMovement() const
    {
        return hasMovementUpgrade;
    }

    bool hasShooting() const
    {
        return hasShootingUpgrade;
    }

    bool hasSeeing() const
    {
        return hasSeeingUpgrade;
    }

    bool isAlive() const override;
    void markAsDead() override;

    int getKillCount() const
    {
        return killCount;
    }

    void incrementKill() 
    {
        ++killCount;
    }

    void resetKillCount() 
    {
        killCount=0;
    }


    void move() override 
    {
        vector<pair<int, int>> nearbyCoordinates = field->getNearbyCoordinates(posX, posY);
        map<string, vector<string>> robotsNearby = field->checkGridTilesForRobots(nearbyCoordinates);

        vector<pair<int, int>> emptyGridCoordinates;

        for(const auto& coord : nearbyCoordinates) 
        {
            bool isOccupied = any_of(
                robotsNearby.begin(), robotsNearby.end(),
                [&](const auto& robot) {
                    int robotX = stoi(robot.second[1]);
                    int robotY = stoi(robot.second[2]);
                    return robotX == coord.first && robotY == coord.second;
                }
            );
            if (!isOccupied) {
                emptyGridCoordinates.push_back(coord);
            }
        }

        if (!emptyGridCoordinates.empty()) 
        {
            int randIndex = rand() % emptyGridCoordinates.size();
            int newX = emptyGridCoordinates[randIndex].first;
            int newY = emptyGridCoordinates[randIndex].second;
            field->moveRobotTo(this, newX, newY);
            posX = newX;
            posY = newY;
        }
    }

    void fire(int dx, int dy) override 
    {
        if (shells <= 0 || (dx == 0 && dy == 0)) return;
        int targetX = posX + dx;
        int targetY = posY + dy;
        if (field->isValidPosition(targetX, targetY)) {
            if (rand() % 100 < 70) {
                field->destroyRobotAt(targetX, targetY);
            }
            shells--;
            if (shells == 0) {
                field->selfDestruct(this);
            }
        }
    }

    vector<vector<double>> look() override 
    {
        return field->get3x3View(posX, posY);
    }

    void think() override 
    {
        // Simple decision logic (can be replaced with AI):
        if (shells > 0) fire(1, 0);
        else move();
    }

    void performTurn() override 
    {
        think();
        look();
        move();
    }

    void decrementRespawn() override;

    void setPosition(int x, int y) override;

    void chooseUpgrade(std::mt19937& gen);
    
    int getRespawnsRemaining() const override;


    string getName() const override 
    { 
        return name; 
    }
    int getX() const override 
    { 
        return posX; 
    }
    int getY() const override 
    { 
        return posY; 
    }


};

