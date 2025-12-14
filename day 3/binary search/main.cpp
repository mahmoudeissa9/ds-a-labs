#include <iostream>
using namespace std;

int binarysearch_iter(int arr[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (target == arr[mid]) return mid;

        if (target > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarysearch_rec(int arr[], int low , int high , int target )
{
    if (low > high) return -1;

    int mid = (low + high) / 2 ;

    if (target == arr[mid]) return mid ;

    if (target > arr[mid])
        return binarysearch_rec(arr, mid+1 , high , target);

    return binarysearch_rec(arr, low , mid-1 , target);
}

int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    int t1 = binarysearch_iter(arr, 0, n-1, 6);
    cout << "Iter: found at index = " << t1 << endl;

    int t2 = binarysearch_rec(arr, 0, n-1, 6);
    cout << "Rec : found at index = " << t2 << endl;

    return 0;
}
