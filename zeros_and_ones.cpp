#include<iostream>
#include<string>
using namespace std;

int main(){
    string lineToBeChecked;
    int cases = 1;
    getline(cin, lineToBeChecked);
    while (!lineToBeChecked.empty()) {
        int judge;
        cin >> judge;
        int startIndex, endIndex;

        int processedline[lineToBeChecked.size()];
        processedline[0] = 0;
        for (int i = 1; i < lineToBeChecked.size(); i++) {
            if (lineToBeChecked[i - 1] == lineToBeChecked[i]){
                processedline[i] = processedline[i - 1];
            } else {
                processedline[i] = processedline[i - 1] + 1;
            }
        }

        cout << "Case " << cases << ":" << endl;
        for (int i = 0; i < judge; i++) {

            cin >> startIndex >> endIndex;
            if (processedline[startIndex] == processedline[endIndex]) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }

        getline(cin, lineToBeChecked);
        getline(cin, lineToBeChecked);
        cases++;
    }
    return 0;
}
