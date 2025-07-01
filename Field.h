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