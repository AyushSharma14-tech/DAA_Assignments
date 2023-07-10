#include<bits/stdc++.h>
using namespace std;
void Sumofsubset(int s,int k,int r,vector<vector<int>>&ans,int a[],int target){
    vector<int>temp;
    temp[k]=1;
    if(s+a[k]==target){
        ans.push_back(temp);
    }
    else if(s+a[k]<target){
        Sumofsubset(s+a[k],k+1,r-a[k],ans,a,target);    
    }
    if(s+r-a[k]>=target && s+a[k+1]<=target){
        temp[k]=0;
        Sumofsubset(s,k+1,r-a[k],ans,a,target);
    }
}
int main(){
    vector<vector<int>>ans;
    int n;
    int r=0,target;
    cout<<"Enter total no of elements in array"<<endl;
    cin>>n;
    int a[n];
    cout<<endl<<"Enter the value of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the target value"<<endl;
    cin>>target;
    for(int i=0;i<n;i++){
        r+=a[i];
    }
    Sumofsubset(0,0,r,ans,a,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<",";
        }
        cout<<endl;
    }

}