#include <iostream>
using namespace std;

/// merge function to divide and compare
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int Left[n1], Right[n2];

    ///  divide the array to right and left arr
    for (int i = 0; i < n1; i++)
        Left[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];

    /// index to left and right and the merged array
    int i = 0, j = 0, k = left;

    /// compare and merge
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j])
            arr[k++] = Left[i++];
        else
            arr[k++] = Right[j++];
    }

    /// remaning element in each arr
    while (i < n1)
        arr[k++] = Left[i++];
    while (j < n2)
        arr[k++] = Right[j++];
}

/// function to check if the arr still have more than one element and if have more than one element will divide it till each divided arr be one element
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        /// recursive
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        /// call the main merge function
        merge(arr, left, mid, right);
    }
}


int main() {
    int arr[] = {6, 3, 8, 5, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";

    return 0;
}
