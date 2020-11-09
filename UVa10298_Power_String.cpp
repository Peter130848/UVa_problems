#include <iostream>
using namespace std;
int main()
{
    string str;
    int strLen;
    bool hasSolution;
    while (cin >> str)
    {
        if (str == ".")
        {
            break;
        }
        strLen = str.length();
        hasSolution = false;

        for (int repeatLen = 1; repeatLen <= strLen; repeatLen++)
        {
            if (strLen % repeatLen)
            {
                continue;
            }
            hasSolution = true;
            string repeatStr = str.substr(0, repeatLen);
            // 每一個都確認
            for (int cmpStart = repeatLen; cmpStart < strLen; cmpStart += repeatLen)
            {
                if (str.substr(cmpStart, repeatLen) != repeatStr)
                {
                    hasSolution = false;
                    break;
                }
            }

            if (hasSolution)
            {
                cout << strLen / repeatLen << endl;
                break;
            }
        }
    }
    return 0;
}