#include <iostream>
using namespace std;
int main()
{
    int amount, cost1, cost2, capacity1, capacity2;

    while (cin >> amount)
    {
        if (!amount)
        {
            break;
        }

        cin >> cost1 >> capacity1 >> cost2 >> capacity2;
        int minCost = 0;
        int box1Amount, box2Amount;

        for (int i = 0; i < (amount / capacity1) + 1; i++)
        {
            // if box1Amount = i is a solution
            if ((amount - capacity1 * i) % capacity2 == 0)
            {
                int j = (amount - capacity1 * i) / capacity2;
                int newCost = cost1 * i + cost2 * j;
                // if minCost = 0, this is the first solution found
                if (newCost < minCost || minCost == 0)
                {
                    minCost = newCost;
                    box1Amount = i;
                    box2Amount = j;
                }
            }
        }

        if (minCost)
        {
            cout << box1Amount << " " << box2Amount << endl;
        }
        else
        {
            cout << "failed" << endl;
        }
    }
}
