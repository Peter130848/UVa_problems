#include<iostream>
using namespace std;

int main(){
    int nPiles;
    while (cin >> nPiles && nPiles) {
        // 0 跟任何數字做 XOR = 原本的數字
        int result = 0;
        while (nPiles--){
            int tmp;
            cin >> tmp;
            result ^= tmp;
        }
        cout << (result ? "Yes" : "No") << endl;
    }
    return 0;
}
