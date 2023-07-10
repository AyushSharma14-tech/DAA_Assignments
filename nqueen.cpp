#include<bits/stdc++.h>
using namespace std;

    bool issafe(int row,int col,vector<string>&board,int n){
        int tempr=row;
        int tempc=col;
       while(col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
       }
       col=tempc;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }
    row=tempr;
    col=tempc;
    while(row<n && col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row++;
        col--;
    }
        return true;
    }
   
    void solve(int col,int n, vector<string>&board,vector<vector<string>>&ans){
        if(col==n) {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(issafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n, vector<vector<string>>&ans) {
       vector<string>board(n);
       string s(n,'.');
       for(int i=0;i<n;i++){
           board[i]=s;
       }
       solve(0,n,board,ans);
       return ans;
    }
    int main(){
        vector<vector<string>>ans;
        int n;
        cout<<"Enter the value of n"<<endl;
        cin>>n;
        if(n>=4){
        solveNQueens(n,ans);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        }
        else{
            cout<<"Solution does not exist"<<endl;
        }
    }