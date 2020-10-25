#include<iostream>
using namespace std;
int main(){
    int number;
    while (cin >> number) {
        int remain = (number == 1) ? 0 : 1;
        int now, answer;
        for (answer = 1; remain; answer++) {
            now = remain * 10 + 1;
            remain = now % number;
        }
        cout << answer << endl;
    }
    return 0;
}