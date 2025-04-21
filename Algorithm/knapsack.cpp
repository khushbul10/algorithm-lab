#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

int matOrder(int array[], int n) {
// Create a 2D array to store the minimum number of scalar multiplications needed
    int minMul[n][n];

// Initialize the diagonal elements to 0
    for (int i = 1; i < n; i++) {
// Multiplying one matrix costs 0 scalar multiplications
        minMul[i][i] = 0; 
    }

// Chain length starts from 2 and increases up to n-1
    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
// Initialize to a very high value (infinity)
            minMul[i][j] = INT_MAX; 
// Find the minimum cost by splitting at different positions
            for (int k = i; k <= j - 1; k++) {
// Calculate cost for splitting at position k
                int q = minMul[i][k] + minMul[k + 1][j] + array[i - 1] * array[k] * array[j];
                if (q < minMul[i][j]) {
                    minMul[i][j] = q; // Update minimum cost
                }
            }
        }
    }

// Return the minimum cost for the full chain (1 to n-1)
    return minMul[1][n - 1];
}

int main() {
    int arr[] = {1, 2, 3, 4}; // Dimensions of matrices: 1x2, 2x3, 3x4
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of matrix multiplications: " << matOrder(arr, size) << endl;

    return 0;
}
