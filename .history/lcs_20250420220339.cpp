#include <iostream>
#include <vector>
using namespace std;

// Function to find length of LCS
int lcs(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    // Create a 2D array to store lengths of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    cout << "Length of LCS: " << lcs(X, Y) << endl;

    return 0;
}


// Step 1: Start
// Step 2: Initialize a 2D array dp of size (m+1) x (n+1) with all values as 0
// Step 3: For i = 1 to m:
//   a. For j = 1 to n:
//     i. If X[i-1] == Y[j-1], then
//       Set dp[i][j] = 1 + dp[i-1][j-1]
//     ii. Else, set dp[i][j] = max(dp[i-1][j], dp[i][j-1])
// Step 4: Return dp[m][n] as the length of LCS
// Step 5: End
//
// Time Complexity: O(m * n)
// Space Complexity: O(m * n) for the dp array