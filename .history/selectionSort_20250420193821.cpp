#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        for(int k=0; k<n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    return 0;
}
// Step 1: Start
// Step 2: Repeat the following steps for i = 0 to n - 2:
//   a. Set minIndex = i
//   b. For j = i + 1 to n - 1:
//     i. If A[j] < A[minIndex], then
//       Set minIndex = j
//   c. Swap A[i] and A[minIndex]
// Step 3: End
// Time Complexity: O(n^2) in all cases (best, average, worst)
