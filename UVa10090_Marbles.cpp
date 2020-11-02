#include <iostream>
using namespace std;
int main()
{
    int amount, capacity1, capacity2, box1Amount, box2Amount;
    int *highCPCap, *lowCPCap, *highCPAmount, *lowCPAmount;
    double cost1, cost2;
    double *highCPCost, *lowCPCost;

    while (cin >> amount)
    {
        if (!amount)
        {
            break;
        }

        cin >> cost1 >> capacity1 >> cost2 >> capacity2;
        bool hasSolution = false;

        if (cost1 / capacity1 < cost2 / capacity2)
        {
            highCPCost = &cost1;
            highCPCap = &capacity1;
            highCPAmount = &box1Amount;
            lowCPCost = &cost2;
            lowCPCap = &capacity2;
            lowCPAmount = &box2Amount;
        }
        else
        {
            highCPCost = &cost2;
            highCPCap = &capacity2;
            highCPAmount = &box2Amount;
            lowCPCost = &cost1;
            lowCPCap = &capacity1;
            lowCPAmount = &box1Amount;
        }

        for (int i = 0; i < (amount / *lowCPCap) + 1; i++)
        {
            if ((amount - *lowCPCap * i) % *highCPCap == 0)
            {
                *lowCPAmount = i;
                *highCPAmount = (amount - *lowCPCap * i) / *highCPCap;
                hasSolution = true;
                break;
            }
        }

        if (hasSolution)
        {
            cout << box1Amount << " " << box2Amount << endl;
        }
        else
        {
            cout << "failed" << endl;
        }
    }
}
