/**********|**********|**********|
Program: Upgrades.cpp
Course: Data Structures and Algorithms
Trimester: 2510
Name: Rosham Danish Haikal
ID: 243UC245TC
Lecture Section: TC3L
Tutorial Section: T10L
Email: ROSHAM.DANISH.HAIKAL@student.mmu.edu.my
Phone: 010-3650212
**********|**********|**********/

#include "Upgrades.h"
#include "GenericRobot.h"
#include <iostream>
#include <memory>
#include <string>
#include <random>
#include <vector>

// Random hit chance
bool randomChance(double probability) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen) < probability;
}

// Upgrade Randomizer
unique_ptr<IMovement> getRandomMovement(mt19937& gen) {
    uniform_int_distribution<> dis(0, 1);
    return dis(gen) ? make_unique<HideBot>() : make_unique<JumpBot>();
}

unique_ptr<IShooting> getRandomShooting(mt19937& gen) {
    uniform_int_distribution<> dis(0, 2);
    switch (dis(gen)) {
        case 0: return make_unique<LongShotBot>();
        case 1: return make_unique<SemiAutoBot>();
        default: return make_unique<ThirtyShotBot>();
    }
}

unique_ptr<ISeeing> getRandomSeeing(mt19937& gen) {
    uniform_int_distribution<> dis(0, 1);
    return dis(gen) ? make_unique<ScoutBot>() : make_unique<TrackBot>();
}
