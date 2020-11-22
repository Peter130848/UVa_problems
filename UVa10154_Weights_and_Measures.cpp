#include <iostream>
#include <algorithm>
using namespace std;

struct turtle
{
    int weight;
    int strength;
};

bool cmp(turtle a, turtle b)
{
    return a.strength < b.strength;
}

turtle turtles[5608];
int dp[5608];

int main()
{

    int tmpWeight, tmpStrength, count = 0;
    while (cin >> tmpWeight >> tmpStrength)
    {
        turtles[count].weight = tmpWeight;
        turtles[count++].strength = tmpStrength;
    }

    sort(turtles, turtles + count, cmp);
    dp[0] = 0;
    for (int i = 1; i <= count; i++)
    {
        dp[i] = 0x7fffffff;
    }

    int max = 0;

    for (int i = 0; i < count; i++)
    {
        for (int j = max + 1; j > 0; j--)
        {
            if (dp[j] > dp[j - 1] + turtles[i].weight && turtles[i].strength >= dp[j - 1] + turtles[i].weight)
            {
                dp[j] = dp[j - 1] + turtles[i].weight;
                if (j > max)
                {
                    max = j;
                }
            }
        }
    }

    cout << max << endl;
    return 0;
}