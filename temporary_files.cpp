#include <iostream>
using namespace std;

class Battlefield
{
    private:
        int x;
        int y;
    public:
        void tiles(int x, int y)
        {
            for (int h = 0; h < x + 2; h++)
            {
                cout << "#";
            }
            cout << endl;
            for (int i = 0; i < y; i++)
            {
                cout << "#";
                for (int j = 0; j < x; j++)
                {
                    cout << "_";
                }
                cout << "#";
                cout << endl;
            }
            for (int k = 0; k < x + 2; k++)
            {
                cout << "#";
            }
        };
};

class Robot
{
    private:
    public:
};

class MovingRobot
{
    private:
    public:
};

class ShootingRobot
{
    private:
    public:
};

class SeeingRobot
{
    private:
    public:
};

class ThinkingRobot
{
    private:
    public:
};

class HideBot
{
    private:
    public:
};

class JumpBot
{
    private:
    public:
};

class LongShotBot
{
    private:
    public:
};

class SemiAutoBot
{
    private:
    public:
};

class ThirtyShotBot
{
    private:
    public:
};

class ScoutBot
{
    private:
    public:
};

class TrackBot
{
    private:
    public:
};

main()
{
    Battlefield field1;
    int x;
    int y;

    cout << "Insert how many columns (x) does a battlefield need: ";
    cin >> x;
    cout << "\nInsert how many rows (y) does a battlefield need: ";
    cin >> y;

    field1.tiles(x, y);
    
    return 0;
}