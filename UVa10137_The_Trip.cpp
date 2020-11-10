#include <iostream>
#include <cstdio>
using namespace std;

int main()
{

    int menbers;
    while (cin >> menbers)
    {
        if (menbers == 0)
            break;
        double sum = 0;
        double costs[menbers];
        for (int i = 0; i < menbers; i++)
        {
            cin >> costs[i];
            sum += costs[i] * 100;
        }
        int remain = ((int)sum) % menbers;
        double average = ((sum - remain) / menbers) * 0.01;

        double result = 0;
        int big = 0;
        for (int i = 0; i < menbers; i++)
        {
            if (costs[i] > average)
            {
                result += costs[i] - average;
                big++;
            }
        }

        if (big < remain)
        {
            result -= big * 0.01;
        }
        else
        {
            result -= remain * 0.01;
        }
        printf("$%.2f\n", result);
    }
    return 0;
}
