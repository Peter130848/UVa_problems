#include <iostream>
#include <math.h>
using namespace std;

void exgcd(long long a, long long b,
           long long &r, long long &x, long long &y)
{
    if (!b)
    {
        r = a;
        x = 1;
        y = 0;
    }
    else
    {
        exgcd(b, a % b, r, y, x);
        y -= (a / b) * x;
    }
}

int main()
{
    long long n, c1, n1, c2, n2, r, x, y;
    while (cin >> n && n)
    {
        cin >> c1 >> n1 >> c2 >> n2;
        exgcd(n1, n2, r, x, y);
        cout << x << " " << y << endl;
        // 最少要多少 n2 / r 讓 x 變成正的
        long long lower = ceil(-1.0 * n * x / n2);
        // y 最多可以減多少 n1 / r 還不是負的
        long long upper = floor(1.0 * n * y / n1);
        
        // 無法讓兩個都是正的
        if (n % r || lower > upper)
        {
            cout << "failed" << endl;
        }
        else if (c1 * n2 >= c2 * n1)
        {
            // 讓 x 最小
            x = x * n / r + n2 / r * lower;
            y = y * n / r - n1 / r * lower;
            cout << x << " " << y << endl;
        }
        else
        {
            // 讓 y 最小
            x = x * n / r + n2 / r * upper;
            y = y * n / r - n1 / r * upper;
            cout << x << " " << y << endl;
        }
    }
    return 0;
}





/*    TOO SLOW 
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
*/
