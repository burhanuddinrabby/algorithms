#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int r, int q)
{
    int a = q - l + 1;
    int b = r - q;
    int i, j, k;
    int leftArray[a], rightArray[b];

    for(i = 0; i < a; i++)
        leftArray[i] = arr[l + i];
    for(j = 0; j < b; j++)
        rightArray[j] = arr[q + 1 + j];

    i = 0, j = 0, k = l;
    // both array compare kore sorted akare rakhbe
    while(i < a && j < b){
        if(leftArray[i] <= rightArray[j]){
            arr[k] = leftArray[i];
            i++;
        }else{
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    // right array furay gele left er baki element gula main array te add korbe
    // karon ager looper condition to sesh hye jabe jodi ekta array furay jay
    while(i < a){
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    // left array furay gele right er baki element gula main array te add korbe
    while(j < b){
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if(l < r){
        int q = (l + r) / 2;
        mergeSort(arr, l, q);
        mergeSort(arr, q + 1, r);

        merge(arr, l, r, q);
    }
}
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int n, i;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter" << n << "array elements" << endl;
    for(i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Before sorting: " << endl;
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "After sorting: " << endl;
    printArray(arr, n);

    return 0;
}
