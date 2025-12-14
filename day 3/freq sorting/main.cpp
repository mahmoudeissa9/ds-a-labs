#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int,int> freq;

bool compare(int a, int b) {
    if(freq[a] != freq[b])
        return freq[a] > freq[b];
    return a < b;
}

int main() {
    int arr[] = {5, 5, 4, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; i++)
        freq[arr[i]]++;

    sort(arr, arr + n, compare);

    cout << "Sorted by frequency: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
