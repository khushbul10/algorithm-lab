#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]], // include item
                    dp[i - 1][w]                           // exclude item
                );
            } else {
                dp[i][w] = dp[i - 1][w]; // can't include item
            }
        }
    }

    return dp[n][W]; // Max value that can be achieved with capacity W
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50; // max capacity of knapsack
    int n = values.size();

    int maxVal = knapsack(W, weights, values, n);
    cout << "Maximum value in Knapsack = " << maxVal << endl;

    return 0;
}


// Step 1: Start
// Step 2: Initialize a 2D array dp of size (n+1) x (W+1) with all values as 0
// Step 3: For i = 1 to n:
//   a. For w = 1 to W:
//     i. If wt[i-1] <= w, then
//       Set dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w])
//     ii. Else, set dp[i][w] = dp[i-1][w]
// Step 4: Return dp[n][W] as the maximum value that can be achieved with capacity W
