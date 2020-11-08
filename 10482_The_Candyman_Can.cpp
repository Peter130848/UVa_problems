#include <iostream>
using namespace std;
bool dp[641][641];

int findBadness(int a, int b, int c)
{
    return max(max(a, b), c) - min(min(a, b), c);
}

int main()
{
    int cases;
    cin >> cases;
    for (int t = 1; t <= cases; t++)
    {
        int sum = 0, candyAmount;
        cin >> candyAmount;
        int candies[candyAmount];
        for (int i = 0; i < candyAmount; i++)
        {
            cin >> candies[i];
            sum += candies[i];
        }

        // dp
        dp[0][0] = true;
        for (int i = 0; i < candyAmount; i++)
        {
            for (int j = sum - candies[i]; j >= 0; j--)
            {
                for (int k = sum - candies[i]; k >= 0; k--)
                {
                    if (dp[j][k])
                    {
                        dp[j + candies[i]][k] = true;
                        dp[j][k + candies[i]] = true;
                    }
                }
            }
        }

        // find smallest badness
        int badness = sum;
        for (int j = 0; j <= sum; j++)
        {
            for (int k = 0; k <= sum; k++)
            {
                if (dp[j][k])
                {
                    badness = min(badness, findBadness(j, k, sum - j - k));
                }
            }
        }

        // print result
        cout << "Case " << t << ": " << badness << endl;

        // if this is the last test case, you don't need to do this
        if (t != cases)
        {
            // reset dp
            for (int j = 0; j <= sum; j++)
            {
                for (int k = 0; k <= sum; k++)
                {
                    dp[j][k] = false;
                }
            }
        }
    }
    return 0;
}