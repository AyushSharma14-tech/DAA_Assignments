//MIN-HEAP implementation
#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
void heapify(vector<int>& arr,int i){
    int n=arr.size();
     int l=2*i+1;
     int r=2*i+2;
     int largest=i;
        if(l<n&&arr[l]>arr[largest]) {
            largest=l;
        }
        if(r<n&&arr[r]>arr[largest]) largest=r;
        if (largest != i) {
          swap(arr[largest], arr[i]);
          heapify(arr, largest);
        }
}
void heapsort(vector<int> &arr)
{
    int n=arr.size();
   for(int i=(n/2)-1;i>=0;i--){
       heapify(arr,i);
   }
   for(int i=arr.size()-1;i>0;i--){
    int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,0);
   }
}
int main(){
  vector<int>arr={34,65,92,2,54,78};
   heapsort(arr);
    for(int i=0;i<6;i++){
    cout<<arr[i]<<" ";
    }
}