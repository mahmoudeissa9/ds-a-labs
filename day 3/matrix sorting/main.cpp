#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int mat[3][3] = {
        {5, 4, 7},
        {1, 3, 8},
        {2, 9, 6}
    };

    int m = 3, n = 3;
    int total = m * n;

   /// 1d array to store the values of the matrix
    int arr[9];
    int k = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            arr[k++] = mat[i][j];
        }
    }

    /// built in function that take the start and the end of the array and sort it
    sort(arr, arr + total);

    /// the matrix take the array element again but sorted
    k = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = arr[k++];
        }
    }


    cout << "Sorted Matrix:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
