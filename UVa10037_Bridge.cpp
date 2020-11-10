#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int cases;
    cin >> cases;

    for (int t = 0; t < cases; t++) {

        // record the time people cross the bridge
        int numOfPeople;
        cin >> numOfPeople;
        int time[numOfPeople];
        for (int i = 0; i < numOfPeople; i++) {
            cin >> time[i];
        }

        // calculate
        if (numOfPeople == 1){
            cout << time[0] << endl;
            cout << time[0] << endl;
        } else {
            sort(time, time + numOfPeople);
            int result = 0;
            int greedPoint = 0;
            int greedCondi = time[1] - time[0];
            for (int i = numOfPeople - 1; i > 1; i = i - 2) {
                if (time[i - 1] - time[1] >= greedCondi) {
                    result += time[i];
                } else {
                    greedPoint = i;
                    break;
                }
            }

            for(int i = 1; i <= greedPoint; i++){
                result += time[i];
            }
            // variable group if the number of groups that use the special method to cross the river
            int group;
            if (greedPoint != 0) {
                group = (numOfPeople - greedPoint) / 2;
            } else {
                group = (numOfPeople / 2) - 1;
            }
            result += 2*group*time[1] + group*time[0];

            if (greedPoint != 0) {
                result += (greedPoint - 1)*time[0];
            } else if (numOfPeople % 2 != 0){
                result += time[0] + time [1];
            } else {
                result += time[1];
            }
            cout << result << endl;

            // print the detail
            numOfPeople--;  // in order to fit the index of array
            for (int i = 0; i < group; i++) {
                cout << time[0] << " " << time[1] << endl;
                cout << time[0] << endl;
                cout << time[numOfPeople--] << " " << time[numOfPeople--] << endl;
                cout << time[1] << endl;
            }

            if (greedPoint != 0) {
                 for(int i = 1; i < greedPoint; i++){
                    cout << time[0] << " " << time[i] << endl;
                    cout << time[0] << endl;
                 }
                 cout << time[0] << " " << time[greedPoint] << endl;
            } else if (numOfPeople % 2 != 0) {
                cout << time[0] << " " << time[1] << endl;
            } else {
                cout << time[0] << " " << time[1] << endl;
                cout << time[0] << endl;
                cout << time[0] << " " << time[numOfPeople] << endl;
            }
        }
        if (t != cases - 1){
            cout << endl;
        }
    }
    return 0;
}
