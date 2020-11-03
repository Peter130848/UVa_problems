#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 檢查測試的答案對不對
vector<int> checkAnswer(vector<int> sum, int a)
{
    vector<int> answer;
    answer.push_back(a);
    while (sum.size())
    {
        int next = sum[0] - answer[0];
        for (int i = 0; i < answer.size(); i++)
        {
            vector<int>::iterator it = find(sum.begin(), sum.end(), answer[i] + next);
            if (it != sum.end())
            {
                sum.erase(it);
            }
            else
            {
                answer.clear();
                return answer;
            }
        }
        answer.push_back(next);
    }
    return answer;
}

// 找所有可能的答案，print結果
void findAnswer(vector<int> sum, int numberAmount)
{
    sort(sum.begin(), sum.end());
    bool noAnswer = true;
    int abac = sum[0] + sum[1];

    for (int i = 2; i < numberAmount; i++)
    {
        int aa = abac - sum[i];

        if (aa % 2 == 1)
            continue;

        vector<int> result;
        result = checkAnswer(sum, aa / 2);

        if (result.size())
        {
            for (int j = 0; j < numberAmount; j++)
            {
                cout << result[j];
                if (j < numberAmount - 1){
                    cout << " ";
                }
            }
            cout << endl;
            noAnswer = false;
            break;
        }
    }

    if (noAnswer)
    {
        cout << "Impossible" << endl;
    }
}

int main()
{

    int numberAmount;
    vector<int> sum;

    while (cin >> numberAmount)
    {
        int capacity = (numberAmount * (numberAmount - 1) / 2);
        sum.clear();

        int tmp;

        for (int i = 0; i < capacity; i++)
        {
            cin >> tmp;
            sum.push_back(tmp);
        }

        findAnswer(sum, numberAmount);
    }

    return 0;
}
