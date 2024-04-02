#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i, j, temp, minIndex;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if(minIndex != i){
            swap(arr[i], arr[minIndex]);
            // temp = arr[i];
            // arr[i] = arr[minIndex];
            // arr[minIndex] = temp;
        }
    }
}

int main()
{
    int n, i, j, temp;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: " << endl;
    for (i = 0; i < n; i++)
        cin >> arr[i];
    
    selectionSort(arr, n);

    cout << "Sorted array: " << endl;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";


    return 0;
}