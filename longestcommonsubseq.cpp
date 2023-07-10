//Implement to find Longest common subsequence (given two strings) using dynamic
//programming.

#include <iostream>
#include <cstring>
using namespace std;

string lcs_string(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int c[m+1][n+1];

    for(int i = 0; i <= m; i++) {
        c[i][0] = 0;
    }
    for(int j = 0; j <= n; j++) {
        c[0][j] = 0;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {
                c[i][j] = 1 + c[i-1][j-1];
            }
            else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }

    string lcs = "";
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            lcs = s1[i-1] + lcs;
            i--;
            j--;
        }
        else if(c[i-1][j] > c[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string s1 ;  //"AGGTAB"
    string s2 ; //"GXTXAYB"
cout<<"Enter first string"<<endl;
cin>>s1;
cout<<"Enter second string"<<endl;
cin>>s2;
    string lcs = lcs_string(s1, s2);
    cout << "Length of LCS is " << lcs.length() << endl;
    cout << "LCS is " << lcs << endl;

    return 0;
}