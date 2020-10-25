#include<iostream>
using namespace std;
int main(){
    int number;
    while (cin >> number) {
        // the result of first modulo is one except the number is 1
        int remain = (number == 1) ? 0 : 1;
        int now, answer;
        // 取餘數直到%結果是零
        for (answer = 1; remain; answer++) {
            now = remain * 10 + 1;
            remain = now % number;
        }
        cout << answer << endl;
    }
    return 0;
}
