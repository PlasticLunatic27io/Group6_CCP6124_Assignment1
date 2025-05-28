#include "Field.h"
#include "GenericRobot.h"
#include <iostream>
#include <queue>
#include <random>

int main()
{

    std::random_device rd;
    std::mt19937 gen(rd());

    Field field(10, 10);
    queue<GenericRobot*> respawnQueue;
    vector<Robot*> robots;

    GenericRobot* a = new GenericRobot("PrrPrrPatapim", 1, 1, &field);
    GenericRobot* b = new GenericRobot("TungTungTungSahur", 2, 2, &field);
    GenericRobot* c = new GenericRobot("BalarinaCapuchino", 3, 3, &field);

    field.addRobot(a);
    field.addRobot(b);
    field.addRobot(c);

    robots.push_back(a);
    robots.push_back(b);
    robots.push_back(c);

    int steps = 30;
    for(int t = 0; t < steps; ++t)
    {
        cout << "\nTurn: " << t << "\n";

        if(!respawnQueue.empty())
        {
            GenericRobot* r = respawnQueue.front();
            respawnQueue.pop();
            if(r->getRespawnsRemaining() > 0)
            {
                r->decrementRespawn();
                auto pos = field.getRandomEmptyPosition();
                r->setPosition(pos.first, pos.second);
                field.addRobot(r);
                cout << r->getName() << " has respawned!\n";
            }
        }

        for(Robot* r : robots)
        {
            if(r->isAlive())
            {
                r->performTurn();
            }
            else
            {
                GenericRobot* g = dynamic_cast<GenericRobot*>(r);
                if(g && g->getRespawnsRemaining() > 0)
                    respawnQueue.push(g);
            }
        }

        for(Robot* r : robots)
        {
            GenericRobot* gurt = dynamic_cast<GenericRobot*>(r);
            if(gurt && gurt->getKillCount() > 0)
            {
                for(int i = 0; i < gurt->getKillCount(); i++)
                    gurt->chooseUpgrade(gen);
                gurt->resetKillCount();
            }
        }

        field.display();
    }

    

    return 0;

}