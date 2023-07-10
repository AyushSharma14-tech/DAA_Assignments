// C++ program for Naive Pattern
// Searching algorithm
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void search(string pat,string txt)
{
	int M = pat.length();
	int N = txt.length();
	for (int i = 0; i <= N - M; i++) {
		int j;
		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;

		if (j== M) 
			cout << "Pattern found at index " << i << endl;
	}
}

int main()
{
	/*char txt[] = "AABAACAADAABAAABAA";
	char pat[] = "AABA";*/
	string txt;
	string pat;
	cout<<"Enter the text"<<endl;
	cin>>txt;
	cout<<"Enter the pattern"<<endl;
	cin>>pat;
	search(pat, txt);
	return 0;
}

