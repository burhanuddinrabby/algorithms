#include <bits/stdc++.h>

using namespace std;
int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
    while(i < j){
        while(pivot >= arr[i])
            i++;
        while(pivot < arr[j])
            j--;
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(int arr[], int l, int h){
    if(l < h){
        int pivLocation = partition(arr, l, h);
        quickSort(arr, l, pivLocation - 1);
        quickSort(arr, pivLocation + 1, h);
    }
}

void printArray(int arr[], int h)
{
    for(int i = 0; i < h; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    //int arr[] = {9, 4, 6, 35, 45, 7, 89, 2, 6, 2};
    //int h = sizeof(arr)/sizeof(arr[0]);
    int h;
    cout << "Enter array size: ";
    cin >> h;
    int arr[h];

    cout << "Enter array elements: ";
    for(int i = 0; i<h; i++)
        cin >> arr[i];

    cout << "Before sorting: " << endl;
    printArray(arr, h);

    quickSort(arr, 0, h-1);

    cout << "After sorting: " << endl;
    printArray(arr, h);

    return 0;
}
