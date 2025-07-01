/**********|**********|**********|
Program: Upgrades.h
Course: Data Structures and Algorithms
Trimester: 2510
Name: Rosham Danish Haikal
ID: 243UC245TC
Lecture Section: TC3L
Tutorial Section: T10L
Email: ROSHAM.DANISH.HAIKAL@student.mmu.edu.my
Phone: 010-3650212
**********|**********|**********/

#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <random>
#include <vector>
using namespace std;




bool randomChance(double probability);

// Movement Interface
class IMovement {
    public:
        virtual void move() = 0;
        virtual ~IMovement() {}
};

class HideBot : public IMovement {
    int hidesLeft = 3;
    
    public:
        void move() override {
            if (hidesLeft > 0)
                cout << "HideBot: Hiding from enemies. (" << hidesLeft-- << " hides left)\n";
            else
                cout << "HideBot: No hides left.\n";
    }
};

class JumpBot : public IMovement {
    int jumpsLeft = 3;
    
    public:
        void move() override {
            if (jumpsLeft > 0)
                cout << "JumpBot: Jumping to a new location. (" << jumpsLeft-- << " jumps left)\n";
            else
                cout << "JumpBot: No jumps left.\n";
    }
};

// Shooting Interface
class IShooting {
    public:
        virtual void shoot(int x, int y) = 0;
        virtual ~IShooting() {}
};

class LongShotBot : public IShooting {
    public:
        void shoot(int x, int y) override {
            if (x + y <= 3)
                cout << "LongShotBot: Shooting at (" << x << ", " << y << ").\n";
            else
                cout << "LongShotBot: Target too far! Must be within 3-unit range.\n";
    }
};

class SemiAutoBot : public IShooting {
    public:
        void shoot(int x, int y) override {
            cout << "SemiAutoBot: Firing 3 rapid shots at (" << x << ", " << y << ").\n";
            
            for (int i = 0; i < 3; ++i)
                cout << " Shot " << i + 1 << ": " << (randomChance(0.7) ? "Hit!" : "Miss") << "\n";
    }
};

class ThirtyShotBot : public IShooting {
    int shells = 30;
    
    public:
        void shoot(int x, int y) override {
            if (shells > 0)
                cout << "ThirtyShotBot: Shooting at (" << x << ", " << y << "). Shells left: " << --shells << "\n";
            else
                cout << "ThirtyShotBot: Out of ammo!\n";
    }
};

// Seeing Interface
class ISeeing {
    public:
        virtual void see() = 0;
        virtual ~ISeeing() {}
};

class ScoutBot : public ISeeing {
    int scansLeft = 3;

    public:
        void see() override {
            if (scansLeft > 0)
                cout << "ScoutBot: Scanning the whole battlefield. (" << scansLeft-- << " scans left)\n";
            else
                cout << "ScoutBot: No more scans left.\n";
    }
};

class TrackBot : public ISeeing {
    int trackersLeft = 3;
    
    public:
        void see() override {
            if (trackersLeft > 0)
                cout << "TrackBot: Tracker planted on enemy! (" << trackersLeft-- << " trackers left)\n";
            else
                cout << "TrackBot: No trackers left!\n";
    }
};