#include <iostream>
using namespace std;

// Function to solve 0-1 Knapsack Problem
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Base case: no items or capacity is 0
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            // If weight of current item is less than or equal to capacity
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // The maximum value that can be put in the knapsack
    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120}; 
    int wt[]={10,20,30};   
    int W = 50;                    
    int n = sizeof(val) / sizeof(val[0]);

    int result = knapsack(W, wt, val, n);
    cout << "Maximum value in Knapsack = " << result << endl;

    return 0;
}
