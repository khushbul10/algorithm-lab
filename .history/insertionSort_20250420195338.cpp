#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        for(int k=0; k<n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    return 0;
}
//
// Step 1: Start
// Step 2: Repeat the following steps for i = 1 to n - 1:
//   a. Set key = A[i]
//   b. Set j = i - 1
    