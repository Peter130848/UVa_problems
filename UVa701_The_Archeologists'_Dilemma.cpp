#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int leftHandPart;
    while (cin >> leftHandPart){
        int digit = 1;
        // 計算到後半部最少需要的digit
        for (int k = 1; k <= leftHandPart; k*=10) {
            digit++;
        }
        double upper = log(leftHandPart + 1) / log(2);
        double low = log(leftHandPart) / log(2);
        double log10 = log(10) / log(2);
        while (true) {
            int top = upper + digit * log10;
            int button = low + digit * log10;
            if (top != button) {
                cout << button + 1 << endl;
                break;
            }
            digit++;
        }   
    }
}