#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
        for(int k=0; k<n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    return 0;
}

// Step 1: Start
// Step 2: Repeat the following steps for i = 0 to n - 2:
//   a. For j = 0 to n - i - 2:
//     i. If A[j] > A[j + 1], then
//       Swap A[j] and A[j + 1]
// Step 3: End

