#include<bits/stdc++.h>
using namespace std;

int dp[3][3][5][4][4][7];
string best[3][3][5][4][4][7];

int main()
{
    int problemAmount;
    while (cin >> problemAmount && problemAmount)
    {
        vector<tuple<string, char, char, int> > problems(problemAmount + 1);
        for (int i = 1; i <= problemAmount; i++)
        {
            string title;
            auto &[id, level, type, favor] = problems[i];
            cin >> id >> title >> level >> type >> favor;
        }

        sort(problems.begin() + 1, problems.end());
        memset(dp, -1, sizeof(dp));
        dp[0][0][0][0][0][0] = 0;
        for (int i = 1; i <= problemAmount; i++) {
            auto &[id, level, type, favor] = problems[i];
            for (int e = 2; e >= (level == 'E'); e--)
            {
                for (int h = 2; h >= (level == 'H'); h--)
                {
                    for (int d = 4; d >= (type == 'D'); d--)
                    {
                        for (int m = 3; m >= (type == 'M'); m--)
                        {
                            for (int g = 3; g >= (type == 'G'); g--)
                            {
                                for (int a = 6; a >= 1; a--)
                                {
                                    int &prev = dp[e - (level == 'E')][h - (level == 'H')][d - (type == 'D')][m - (type == 'M')][g - (type == 'G')][a - 1];
                                    if (prev == -1) {
                                        continue;
                                    }
                                    if (prev + favor > dp[e][h][d][m][g][a]) {
                                        dp[e][h][d][m][g][a] = prev + favor;
                                        best[e][h][d][m][g][a] = best[e - (level == 'E')][h - (level == 'H')][d - (type == 'D')][m - (type == 'M')][g - (type == 'G')][a - 1] + " " + id;

                                    } else if (prev + favor == dp[e][h][d][m][g][a]) {
                                        best[e][h][d][m][g][a] = min(best[e][h][d][m][g][a], best[e - (level == 'E')][h - (level == 'H')][d - (type == 'D')][m - (type == 'M')][g - (type == 'G')][a - 1] + " " + id);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        int maxFavor = -1;
        string answer = "";
        for (int d = 2; d < 5; d++) {
            for (int m = 1; m < 4; m++) {
                for (int g = 1; g < 4; g++) {
                    if (dp[2][2][d][m][g][6] > maxFavor) {
                        maxFavor = dp[2][2][d][m][g][6];
                        answer = best[2][2][d][m][g][6];
                    } else if (dp[2][2][d][m][g][6] == maxFavor) {
                        answer = min(answer, best[2][2][d][m][g][6]);
                    }
                }
            }
        }

        if (maxFavor == -1) {
            cout << "No solution." << endl;
        } else {
            cout << answer.substr(1, answer.length() - 1) << endl;
        }
    }
}
