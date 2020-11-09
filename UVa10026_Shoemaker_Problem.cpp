#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    double tf;
    int order;
};

bool cmp(Node a, Node b)
{
    if (a.tf > b.tf)
    {
        return true;
    }
    else if (a.tf == b.tf)
    {
        if (a.order < b.order)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int jobAmount;
        cin >> jobAmount;
        Node jobs[jobAmount];
        for (int i = 0; i < jobAmount; i++)
        {
            double takeTime, fine;
            cin >> takeTime >> fine;
            jobs[i].tf = fine / takeTime;
            jobs[i].order = i + 1;
        }

        sort(jobs, jobs + jobAmount, cmp);
        for (int i = 0; i < jobAmount - 1; i++)
        {
            cout << jobs[i].order << " ";
        }
        cout << jobs[jobAmount - 1].order << endl;

        if (cases)
        {
            cout << endl;
        }
    }
    return 0;
}
