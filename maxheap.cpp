//Max-Heap Implementation
#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
void Max_heapify(vector<int>& arr,int i){
    int n=arr.size();
     int l=2*i+1;
     int r=2*i+2;
     int smallest=i;
        if(l<n&&arr[l]>arr[smallest]) {
            smallest=l;
        }
        if(r<n&&arr[r]>arr[smallest]) smallest=r;
        if (smallest != i) {
          swap(arr[smallest], arr[i]);
          Max_heapify(arr, smallest);
        }
}
int buildMinHeap(vector<int> &arr)
{
    int n=arr.size();
   for(int i=(n/2)-1;i>=0;i--){
       Max_heapify(arr,i);
   }
   
}
int main(){
  vector<int>arr={34,65,92,2,54,78};
    buildMinHeap(arr);
    for(int i=0;i<6;i++){
    cout<<arr[i]<<" ";
    }
}