#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[]) {
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
    bubbleSort(arr);
    return 0;
}