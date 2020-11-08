#include <iostream>
using namespace std;
bool dp[215][10001];
int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int length, tmp, carAmount = 1;
        int carlength[201];
        cin >> length;
        length *= 100;
        while (cin >> tmp && tmp)
        {
            carlength[carAmount++] = tmp;
        }

        dp[0][0] = true;
        // 用來確認還能不能放
        int onFerryLength = 0;
        // 用來找結果
        int amountMax = 0, lengthMax = 0;

        for (int n = 1; n < carAmount; n++)
        {
            onFerryLength += carlength[n];
            for (int l = 0; l <= length; l++)
            {
                if (onFerryLength - l <= length && dp[n - 1][l])
                {
                    amountMax = n;
                    lengthMax = l;
                    dp[n][l] = true;
                }
                if ((l + carlength[n]) <= length && dp[n - 1][l])
                {
                    amountMax = n;
                    lengthMax = l + carlength[n];
                    dp[n][lengthMax] = true;
                }
            }
        }

        bool result[amountMax + 1];
        int clearLength = lengthMax;
        cout << amountMax << endl;
        for (int i = amountMax; i > 0; i--)
        {
            if (dp[i - 1][lengthMax])
            {
                result[i] = false;
            }
            else
            {
                result[i] = true;
                lengthMax -= carlength[i];
            }
        }

        for (int i = 1; i <= amountMax; i++)
        {
            if (result[i])
            {
                cout << "port" << endl;
            }
            else
            {
                cout << "starboard" << endl;
            }
        }
        if (cases)
        {
            // 前面代表停幾輛，後面則是長度
            for (int i = 0; i <= amountMax; i++)
            {
                for (int j = 0; j <= clearLength; j++)
                {
                    dp[i][j] = false;
                }
            }
            cout << endl;
        }
    }
    return 0;
}