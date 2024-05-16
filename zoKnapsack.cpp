// 0/1 knapsack
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int zoKnapsack(int S, int sr[], int v[], int n)
{
    int V[n + 1][S + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            if (i == 0 || j == 0)
                V[i][j] = 0;
            else if (sr[i - 1] <= j)
                V[i][j] = max(v[i - 1] + V[i - 1][j - sr[i - 1]], V[i - 1][j]);
            else
                V[i][j] = V[i - 1][j];
        }
    }
    return V[n][S];
}

int main()
{

    int items, S;
    cout << "Enter how many items and knapsack capacity: ";
    cin >> items >> S;

    int sr[items], v[items];
    for (int i = 0; i < items; i++)
    {
        cout << "Enter item" << i + 1 << " weight and value: ";
        cin >> sr[i] >> v[i];
    }

    int prf = zoKnapsack(S, sr, v, items);
    cout << prf << endl;

    return 0;
}