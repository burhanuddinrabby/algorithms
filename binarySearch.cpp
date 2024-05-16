#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    
    int arr[10] = {4, 7, 2, 8, 1, 6, 3, 9, 5, 10};
    int n = 10;
    int target = 6;
    
    cout << "Element found at index " << binarySearch(arr, n, target) << endl;
    return 0;
}