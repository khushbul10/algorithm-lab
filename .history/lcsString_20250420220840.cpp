#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

void lcs(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Reconstruct the LCS string
    int i = m, j = n;
    string lcs_str;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str += X[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs_str.begin(), lcs_str.end());

    // Output
    cout << "Length of LCS: " << dp[m][n] << endl;
    cout << "LCS string: " << lcs_str << endl;
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    lcs(X, Y);
    return 0;
}
//
// Step 1: Start
// Step 2: Initialize a 2D array dp of size (m+1) x (n+1) with all values as 0
// Step 3: For i = 1 to m:
