//Implement BFS
#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    void addedge(unordered_map<int,set<int>>&adj,int u,int v,bool dir){
        adj[u].insert(v);
        if(dir==0) adj[v].insert(u);
    }
    void printadjlist(unordered_map<int,set<int>>&adj){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
            cout<<j<<",";
            }
            cout<<endl;
        }
    }
    void bfs(unordered_map<int,set<int>>&adj,unordered_map<int,bool>&visited,vector<int>&ans,int node){
        queue<int>q;
        q.push(node);
        visited[node]=1;
        while(!q.empty()){
            int frontnode=q.front();
            q.pop();
            ans.push_back(frontnode);
            for(auto i:adj[frontnode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
    }
};
int main(){
int n,e;
 unordered_map<int,bool>visited;
  unordered_map<int,set<int>>adj;
 vector<int>ans;
 int node;
cout<<"Enter the total number of nodes"<<endl;
cin>>n;
cout<<"Enter the total number of edges"<<endl;
cin>>e;
graph g;
cout<<"Enter the edges between the vertices"<<endl;  //for eg. if there is a edge between 0 to 1 then insert 0 1 like this put all edges
for(int i=0;i<e;i++){
int u,v;
cin>>u >>v;
g.addedge(adj,u,v,0);
}
g.printadjlist(adj);
for(int i=0;i<n;i++){
    if(!visited[i]){
        g.bfs(adj,visited,ans,i);
    }
}
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
}
return 0;
}