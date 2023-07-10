//Implemention of Bucket Sort
#include<bits/stdc++.h>
using namespace std;

void bucketSort(vector<float>& arr,int n) {
    vector<vector<float>> buckets(n);
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < buckets.size(); i++)
        for(int k=1;k<buckets[i].size();k++){
            float key=buckets[i][k];
            int j=k-1;
            while(j>=0&&buckets[i][j]>key){
            buckets[i][j+1]=buckets[i][j];
            j--;
        }
        buckets[i][j+1]=key;
   }

    int index = 0;
    for (int i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    vector<float> arr;
    int t;
    float a;
    cout<<"Enter the total number of elements you want to enter"<<endl;
    cin>>t;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<t;i++){
        cin>>a;      
        arr.push_back(a);
    }
    bucketSort(arr,t);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;
    return 0;
}