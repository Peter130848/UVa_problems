#include<iostream>
using namespace std;


int main(){
    int numbers;
    while (cin >> numbers) {
        int first, second;
        int result[numbers];
        for(int i = 0; i < numbers; i++) result[i] = 0;
        bool jolly = true;
        cin >> first;
        for (int i = 0; i < numbers - 1; i++){

            cin >> second;
            if(jolly){
                int tmp = abs(second - first);
                if (tmp >= numbers || tmp == 0) {
                    jolly = false;
                } else if (result[tmp] == 1) {
                    jolly = false;
                } else {
                    result[tmp] = 1;
                }
                first = second;
            }

        }
        if (jolly) {
            cout << "Jolly" << endl;
        }
        else {
            cout << "Not jolly" << endl;
        }
    }
}
