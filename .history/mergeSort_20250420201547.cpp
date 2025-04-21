#include <bits/stdc++.h>
using namespace std;

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for(int i=0; i<n1; i++) {
            L[i] = arr[left + i];
        }
        for(int j=0; j<n2; j++) {
            R[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while(i < n1 && j < n2) {
            if(L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        while(i < n1) {
            arr[k++] = L[i++];
        }
        while(j < n2) {
            arr[k++] = R[j++];
        }

        delete[] L;
        delete[] R;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// Step 1: Start
// Step 2: If left < right, then
//   a. Set mid = left + (right - left) / 2
//   b. Call mergeSort(arr, left, mid)
//   c. Call mergeSort(arr, mid + 1, right)
//   d. Set n1 = mid - left + 1
//   e. Set n2 = right - mid
//   f. Create arrays L[n1] and R[n2]
//   g. Copy elements from arr[left..mid] to L
//   h. Copy elements from arr[mid + 1..right] to R
