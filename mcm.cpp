//Implement optimal parenthesization of a matrix-chain product for given
//sequence of dimensio
#include<bits/stdc++.h>
using namespace std;

void printParentheses(vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printParentheses(s, i, s[i][j]);
        printParentheses(s, s[i][j]+1, j);
        cout << ")";
    }
}

int mcm(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> m(n+1, vector<int>(n+1, 0)); 
    vector<vector<int>> s(n+1, vector<int>(n+1, 0)); 
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n-l+1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j-1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Optimal Parenthesization: ";
    printParentheses(s, 1, n);
    cout << endl;

    return m[1][n];
}

int main() {
    vector<int> p = {30, 35, 15, 5, 10, 20, 25};
    int minCost = mcm(p);
    cout << "Minimum Cost: " << minCost << endl;
    return 0;
}