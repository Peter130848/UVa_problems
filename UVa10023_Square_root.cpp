#include<iostream>
using namespace std;
int main(){
    int cases;
    cin >> cases;
    while (cases--) {
        string number;
        cin >> number;
        int length = number.size();
        // 每次下來都下兩位數，因為10^2 = 100
        // 如果不是偶數，補一個零
        if (length % 2) {
            number = "0" + number;            
            length++;
        }
        // (A+B+C+…)^2 = A^2+B(2A+B)+C(2A+2B+C)+…
        //  answer            devide
        int answer = 0, remain = 0, devide = 0;
        for (int i = 0; i < length; i += 2) {
            // 每次下來都下兩位數，因為10^2 = 100
            remain = remain*100 + (number[i] - 48) * 10 + (number[i+1] - 48);
            devide *= 10;
            // 找答案的下一位數
            int newDigit = 0;
            for (; (devide + newDigit) * newDigit <= remain; newDigit++) {};
            // 不要大於的
            newDigit--;
            remain -= (devide + newDigit) * newDigit;
            devide += 2 * newDigit;
            answer = answer*10 + newDigit;
        }
        cout << answer << endl;
    }
}