#include<iostream>
using namespace std;

int main(){
    int nPiles;
    while (cin >> nPiles && nPiles) {
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