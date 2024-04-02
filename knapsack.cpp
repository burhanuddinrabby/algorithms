#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum profit
float knapsack(float knp, float perObj[], int w[], float arrX[], int p[], int n)
{
    float profit = 0;
    int i, size = n, index;
    //array size obdi
    while (size-- && knp > 0.0)
    {
        if (knp <= 0)
            break;
        float max = -1;
        //to find the maximum number in profit per unit
        for (i = 0; i < n; i++)
        {
            if (perObj[i] > max)
            {
                max = perObj[i];
                index = i;
            }
        }
        
        //when remaining storage is less than object weight
        if (w[index] > knp)
        {
            // arrX will be decimal and weight will be (actual weight * remaining/weight)
            // (weight * remaining/weight) -> remaining
            arrX[index] = (float)knp / w[index];
            knp -= w[index] * arrX[index];
            // knp -= knp;
        }
        else
        {
            // this will take full obj so arrX element is 1 and actual weight will be sub from knp
            arrX[index] = 1;
            knp -= w[index];
        }
        perObj[index] = 0;
    }
    for (i = 0; i < n; i++)
    {
        profit += p[i] * arrX[i];
    }

    return profit;
}
int main()
{
    int n, i;
    float knp;
    cout << "Enter how many objects: " ;
    cin >> n;
    cout << endl << "Enter Knapsack size: ";
    cin >> knp;
    int p[n], w[n];
    cout << endl << "Enter each objects price: " << endl;
    for (i = 0; i < n; i++)
        cin >> p[i];

    cout << "Enter each objects weight: " << endl;
    for (i = 0; i < n; i++)
        cin >> w[i];

    // array to store the profit per unit weight
    float perObj[n];
    for (i = 0; i < n; i++)
        perObj[i] = (float)p[i] / w[i];

    // 0 <= Xi <= 1
    //1 means full obj, 0 means element won't be taken, decimal means fraction of obj
    float arrX[n] = {0};
    
    float profit = knapsack(knp, perObj, w, arrX, p, n);

    cout
        << "Maximum profit is: " << fixed << setprecision(2) << profit << " ";
    return 0;
}