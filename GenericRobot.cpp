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

#include "GenericRobot.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

GenericRobot::GenericRobot(std::string name, int x, int y, Field* fieldPtr): name(name), posX(x), posY(y), field(fieldPtr), shells(10), lives(3), alive(true), respawnsRemaining(3) 
{
    upgrades = { false, false, false };
    srand(time(0));
}

void GenericRobot::move()
{
    auto nearbyCoordinates = field->getNearbyCoordinates(posX, posY);
    auto robotsNearby = field->checkGridTilesForRobots(nearbyCoordinates);

    std::vector<std::pair<int, int>> emptyGridCoordinates;

    for(const auto& coord : nearbyCoordinates)
    {
        bool isOccupied = std::any_of(
            robotsNearby.begin(), robotsNearby.end(),[&](const auto& robot)
            {
                int robotX = std::stoi(robot.second[1]);
                int robotY = std::stoi(robot.second[2]);
                return robotX == coord.first && robotY == coord.second;
            }
        );
        if (!isOccupied)
        {
            emptyGridCoordinates.push_back(coord);
        }
    }

    if(!emptyGridCoordinates.empty())
    {
        int randIndex = rand() % emptyGridCoordinates.size();
        int newX = emptyGridCoordinates[randIndex].first;
        int newY = emptyGridCoordinates[randIndex].second;
        field->moveRobotTo(this, newX, newY);
        posX = newX;
        posY = newY;
    }
}

void GenericRobot::fire(int dx, int dy)
{
    if(shells<=0 || (dx == 0 && dy == 0)) return;
    int targetX = posX + dx;
    int targetY = posY + dy;
    if(field->isValidPosition(targetX, targetY))
    {
        if(rand() % 100 < 70)
        {
            field->destroyRobotAt(targetX, targetY);
        }
        shells--;
        if(shells==0)
        {
            std::cout << getName() << " has no shells left and will self-destruct.\n"
            field->selfDestruct(this);
        }
    }
}

std::vector<std::vector<double>> GenericRobot::look()
{
    return field->get3x3View(posX, posY);
}

void GenericRobot::think()
{
    if(shells > 0) fire(1,0);
    else move();
}


void GenericRobot::performTurn()
{
    if(!alive) 
        return;  
    think();
    look();
    move();
}

std::string GenericRobot::getName() const 
{
    return name;
}

int GenericRobot::getX() const 
{ 
    return posX; 
}
int GenericRobot::getY() const 
{ 
    return posY; 
}
bool GenericRobot::isAlive() const
{ 
    return alive; 
}
void GenericRobot::markAsDead() 
{ 
    alive = false; 
}
int GenericRobot::getRespawnsRemaining() const 
{ 
    return respawnsRemaining; 
}
void GenericRobot::decrementRespawn() 
{ 
    if (respawnsRemaining > 0) respawnsRemaining--; 
}
void GenericRobot::setPosition(int x, int y)
{ 
    posX = x; 
    posY = y; 
    alive = true; 

    shells = 10;
    killCount = 0;

    hasMovementUpgrade = false;
    hasShootingUpgrade = false;
    hasSeeingUpgrade = false;

    movement = nullptr;
    shooting = nullptr;
    seeing = nullptr;
}

void GenericRobot::chooseUpgrade(std::mt19937& gen)
{
    std::vector<std::string> available;
    if(!hasMovementUpgrade) available.push_back("movement");
    if(!hasShootingUpgrade) available.push_back("shooting");
    if(!hasSeeingUpgrade) available.push_back("seeing");

    if(available.empty())
        return;

    std::uniform_int_distribution<> dist(0, available.size() - 1);
    std::string upgrade = available[dist(gen)];

    if(upgrade == "movement")
    {
        setMovement(getRandomMovement(gen));
        hasMovementUpgrade = true;
        std::cout << getName() << " received movement upgrade!\n";
    }
    else if(upgrade == "shooting")
    {
        setShooting(getRandomShooting(gen));
        hasShootingUpgrade = true;
        std::cout << getName() << " received shooting upgrade!\n";
    }
    else 
    {
        setSeeing(getRandomSeeing(gen));
        hasSeeingUpgrade = true;
        std::cout << getName() << " received seeing upgrade!\n";
    } 
}