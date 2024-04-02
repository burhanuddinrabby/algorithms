#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n + range)
// Space complexity: O(n + range)
void countSort(int n, int arr[]){
    int i;
    int range;
    cout << endl << "Enter the range 0 to ? : ";
    cin >> range;
    int count[range + 1] = {0};

    // creating frequency array
    for (i = 0; i < n; i++)
        count[arr[i]]++;

    // updating count array
    for (i = 1; i <= range; i++)
        count[i] += count[i - 1];

    int output[n];
    // creating output array by using count array as index of output array
    // and decrementing the count array value by 1 after each element is placed in output array
    // so that next element can be placed at the previous index of the current element
    // this is done to maintain the order of the elements
    for (i = n - 1; i >= 0; i--)
    {
        // output[count[arr[i]] - 1] = arr[i];
        // count[arr[i]]--;
        output[--count[arr[i]]] = arr[i];
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// More time consuming
/*
void countSort(int n, int arr[]){
    int range;
    cout << endl << "Enter the range 0 to ? : ";
    cin >> range;
    int count[range + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    int j = 0;
    for(int i = 0; i<=range; i++){
        int x = count[i];
        while(x--){
            arr[j++] = i;
        }
    }
}*/

void printArray(int n, int arr[]){
    cout << endl << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n, range;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << endl << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    countSort(n, arr);
    printArray(n, arr);

    return 0;
}