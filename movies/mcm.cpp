#include <bits/stdc++.h>
using namespace std;

void printTable(int m[100][100], int n) {
    cout << "\nDP Table (Minimum Multiplications):\n";
    cout << "     ";
    for (int j = 1; j < n; j++)
        cout << setw(5) << "A" + to_string(j);
    cout << endl;

    for (int i = 1; i < n; i++) {
        cout << "A" << i << " ";
        for (int j = 1; j < n; j++) {
            if (i > j)
                cout << setw(5) << "-";
            else
                cout << setw(5) << m[i][j]<<" ";
        }
        cout << endl;
    }
}

int matrixChainOrder(int p[], int n) {
    int m[100][100];  // Increase size for larger matrices

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    printTable(m, n);
    return m[1][n - 1];
}

int main() {
    int p[] = {40, 20, 30, 10, 30};  // Dimensions
    int n = sizeof(p) / sizeof(p[0]);

    int result = matrixChainOrder(p, n);
    cout << "\nMinimum number of multiplications is: " << result << endl;

    return 0;
}
