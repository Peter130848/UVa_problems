#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int cases;
    cin >> cases;

    for (int t = 0; t < cases; t++) {

        int numOfRelatives;
        cin >> numOfRelatives;
        int address[numOfRelatives];

        for (int i = 0; i < numOfRelatives; i++){
            cin >> address[i];
        }

        sort(address, address + numOfRelatives);

        //the middle of all the addresses
        int vitoHouse = numOfRelatives / 2;
        int sum = 0;
        for (int i = 0; i < numOfRelatives; i++) {
            if (i == vitoHouse){
                continue;
            } else if (i < vitoHouse) {
                sum += address[vitoHouse] - address[i];
            } else {
                sum += address[i] - address[vitoHouse];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
