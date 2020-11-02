#include <iostream>
using namespace std;

void findMaxMin(int[], int, int, int);

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int numbers[n + m];
        int sum = 0;
        for (int i = 0; i < n + m; i++)
        {
            cin >> numbers[i];
            sum += numbers[i];
        }
        findMaxMin(numbers, n, m, sum);
    }
}

void findMaxMin(int numbers[], int n, int m, int sum)
{
    bool avaliable[n + 1][5001] = {};
    avaliable[0][2500] = true;
    // find all the possible sum in the first parenthesis
    for (int t = 0; t < n + m; t++)
    {
        // if t + 1 < n, avaliable[n][?] can't be ture
        for (int i = (t + 1 >= n) ? n - 1 : t; i >= 0; i--)
        {
            if (numbers[t] > 0)
            {
                int max = 5000 - numbers[t];
                for (int j = 0; j <= max; j++)
                {
                    if (avaliable[i][j])
                    {
                        avaliable[i + 1][j + numbers[t]] = true;
                    }
                }
            }
            else
            {
                for (int j = -numbers[t]; j <= 5000; j++)
                {
                    if (avaliable[i][j])
                    {
                        avaliable[i + 1][j + numbers[t]] = true;
                    }
                }
            }
        }
    }

    // find answer
    int max = -2500 * 2500, min = 2500 * 2500;
    for (int i = 0; i <= 5000; i++)
    {
        if (avaliable[n][i])
        {
            int product = (i - 2500) * (sum - i + 2500);
            if (product > max)
            {
                max = product;
            }
            if (product < min)
            {
                min = product;
            }
        }
    }
    cout << max << " " << min << endl;
}
