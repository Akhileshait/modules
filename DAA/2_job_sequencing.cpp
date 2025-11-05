#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    return a[1] > b[1];
}

int job_seq(vector<vector<int>> job, int n, int md)
{
    int profit = 0;
    sort(job.begin(), job.end(), comp);
    vector<int> slot(md, 0);

    for (int i = 0; i < n; ++i)
    {
        if (slot[job[i][0]] == 0)
        {
            profit += job[i][1];
            job[i][0] = 1;
        }
    }

    return profit;
}

int main()
{
}