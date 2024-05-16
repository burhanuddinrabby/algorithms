#include <bits/stdc++.h>
using namespace std;


void traceBack(int coins[], int c[], int total)
{
    if(c[total] == -1)
    {
        cout << "No solution\n";
        return;
    }

    while(total != 0)
    {
        cout << coins[c[total]] << " ";
        total -= coins[c[total]];
    }
    cout << endl;
}

void coinChange(int coins[], int total, int n)
{
    int t[total + 1], c[total + 1];
    t[0] = 0;
    c[0] = -1;

    for(int i = 1; i <= total; i++)
    {
        t[i] = 1e9;
        c[i] = -1;
    }

    for(int j = 0; j < n; j++)
    {
        for(int i = coins[j]; i <= total; i++){
            int tmp = min(t[i], 1 + t[i - coins[j]]);
            if(tmp != t[i]){
                t[i] = tmp;
                c[i] = j;
            }
        }
    }
    traceBack(coins, c, total);
}


int main()
{
    int total, n;
    cin >> total >> n;
    int coins[n];
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    coinChange(coins, total, n);

    return 0;
}

/*
int main()
{
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                if (dp[i - coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[amount] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dp[amount] << endl;

    return 0;
}*/

/*
void coinChange(int coins[], int total, int n)
{
    int table[total + 1][n];
    for (int i = 0; i < n; i++)
        table[0][i] = 1;

    for (int i = 1; i < total + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = (i - coins[j] >= 0) ? table[i - coins[j]][j] : 0;
            int y = (j >= 1) ? table[i][j - 1] : 0;

            table[i][j] = x + y;
        }
    }

    cout << table[total][n - 1] << endl;

}

int main()
{
    int coins[] = {1, 2, 3};
    int total = 4;
    int n = sizeof(coins) / sizeof(coins[0]);

    coinChange(coins, total, n);

    return 0;
}
*/
