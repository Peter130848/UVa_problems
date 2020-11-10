#include<iostream>
using namespace std;
int main(){
    int cases;
    cin >> cases;
    for (int t = 0; t < cases; t++) {
        int days;
        cin >> days;
        int partys;
        cin >> partys;
        int party[partys];
        for (int i = 0; i < partys; i++){
            cin >> party[i];
        }
        int rest = 0;
        for (int i = 1; i < days + 1; i++) {
            for (int j = 0; j < partys; j++){
                if (i % 7 != 6 && i % 7 != 0 && i % party[j] == 0) {
                    rest++;
                    break;
                }
            }

        }
        cout << rest << endl;
    }
}
