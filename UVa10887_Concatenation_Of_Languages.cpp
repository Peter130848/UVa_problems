#include<iostream>
#include<set>

using namespace std;
int main(){
    int cases;
    cin >> cases;
    for (int a = 1; a <= cases; a++) {
        int lanOneSize, lanTwoSize;
        cin >> lanOneSize >> lanTwoSize;
        string lan1[lanOneSize];
        string lan2[lanTwoSize];
        getline(cin, lan1[0]);
        for (int i = 0; i < lanOneSize; i++)
            getline(cin, lan1[i]);
        for (int i = 0; i < lanTwoSize; i++)
            getline(cin, lan2[i]);

        set<string> newWord;

        for (int i = 0; i < lanOneSize; i++) {
            for (int j = 0; j < lanTwoSize; j++) {
                newWord.insert(lan1[i] + lan2[j]);
            }
        }
        cout << "Case " << a << ": " << newWord.size() << endl;

    }
}
