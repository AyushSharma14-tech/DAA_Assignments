//Find min & max using least comparison
#include<bits/stdc++.h>
using namespace std;
vector<int> sol(vector<int>A,int n, vector<int>&ans){
    int mini=A[0];
    int maxi=A[0];
   for(int i=1;i<A.size();i++){
    mini=min(mini,A[i]);
    maxi=max(maxi,A[i]);
   }
   ans.push_back(mini);
   ans.push_back(maxi);
   return ans;
}
int main(){
    vector<int>A={10,5,2,45,56};
    int n=A.size();
    vector<int>ans;
    sol(A,n,ans);
    cout<<"min and max elements are:"<<endl;
    for(int i=0;i<ans.size();i++){
       cout<<ans[i]<<endl;
    }
}