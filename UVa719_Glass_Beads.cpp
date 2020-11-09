#include <iostream>
using namespace std;
int main()
{
    int cases;
    string necklace;
    cin >> cases;

    while (cases--)
    {
        cin >> necklace;
        int necklaceLen = necklace.length();
        int p = 0, q = 1;
        while (p < necklaceLen && q < necklaceLen)
        {
            int k = 0;
            for (; k < necklaceLen; k++)
            {
                if (necklace[(p + k) % necklaceLen] != necklace[(q + k) % necklaceLen])
                {
                    break;
                }
            }

            if (k == necklaceLen)
            {
                break;
            }

            // 其中不可能有解
            if (necklace[(p + k) % necklaceLen] > necklace[(q + k) % necklaceLen])
            {
                p += k + 1;
            }
            else
            {
                q += k + 1;
            }

            if (p == q)
            {
                q++;
            }
        }
        cout << min(p, q) + 1 << endl;
    }
    return 0;
}