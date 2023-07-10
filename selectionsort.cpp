//Implementation of selection sort
#include<iostream>
using namespace std;

void selectionsort(int A[],int n){
    int k;
   for(int i=0;i<n-1;i++){
    for(int j=k=i;j<n;j++){
        if(A[j]<A[k]){
            k=j;
        }
    }
    swap(A[i],A[k]);
   }
}
int main(){
    int A[]={3,7,9,10,6,5,2,4,11,2};
    int n=10;
    selectionsort(A,10);
    for(int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }
    return 0;
}