#include <iostream>
#include <map>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s))
    {
        int testCases, sLen = s.length();
        // treat upper case and lower case as the same
        for (int i = 0; i < sLen; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 32;
            }
        }
        cin >> testCases;
        while (testCases--)
        {
            int nGramLen;
            cin >> nGramLen;
            string ansString = "";
            int ansFrequency = 0;
            map<string, int> m;
            for (int subStrStart = 0; subStrStart <= sLen - nGramLen; subStrStart++)
            {
                string subStr = s.substr(subStrStart, nGramLen);
                int newFrequence = ++m[subStr];
                if (newFrequence > ansFrequency)
                {
                    ansFrequency = newFrequence;
                    ansString = subStr;
                }
                else if (newFrequence == ansFrequency)
                {
                    ansString = min(ansString, subStr);
                }
            }

            cout << ansFrequency << " " << ansString << endl;
        }
        // read \n
        getline(cin, s);
    }
    return 0;
}