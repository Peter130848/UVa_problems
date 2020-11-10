#include<iostream>
#include<sstream>
using namespace std;
int main(){
    string input;
    getline(cin, input);
    stringstream ss;
    while(input != ""){
        long long int dp[51][51] = {};
        dp[0][0] = 1;
        int n, k, m;
        ss << input;
        ss >> n >> k >> m;
        ss.str("");
        ss.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int p = 1; p <= m && p <= i; p++) {
                    dp[i][j] += dp[i - p][j - 1]; 
                }
            }
        }
        cout << dp[n][k] << endl;
        getline(cin, input);
    }    
}