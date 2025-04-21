#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n, vector<pair<int, int>>& includedItems) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtrack to find which items were included
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            includedItems.push_back({val[i - 1], wt[i - 1]});
            w -= wt[i - 1];
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;
    int n = values.size();

    vector<pair<int, int>> includedItems; // each pair is {value, weight}

    int maxVal = knapsack(W, weights, values, n, includedItems);

    cout << "Maximum value in Knapsack = " << maxVal << endl;
    cout << "Items included (value, weight):" << endl;
    for (auto item : includedItems) {
        cout << "(" << item.first << ", " << item.second << ")" << endl;
    }

    return 0;
}
