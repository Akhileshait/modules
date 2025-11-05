#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value, weight;
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    int currentWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currentWeight + arr[i].weight <= W)
        {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = W - currentWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main()
{
    int W = 50; // Capacity
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum value: " << fractionalKnapsack(W, arr, n);
    return 0;
}
