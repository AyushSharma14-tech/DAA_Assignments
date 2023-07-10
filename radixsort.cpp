//Implementation of Radix sort
#include<bits/stdc++.h>
using namespace std;

void radixSort(vector<int>& arr,int n) {
    int maxVal=arr[0];
   for(int i=1;i<arr.size();i++){
    maxVal=max(maxVal,arr[i]);
   }

    for (int exp = 1; maxVal/exp > 0; exp *= 10) {
        vector<int> output(n);
        vector<int> count(10, 0);

        for (int i = 0; i < n; i++)
            count[(arr[i]/exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i-1];

        for (int i = n-1; i >= 0; i--) {
            output[--count[(arr[i]/exp) % 10] ] = arr[i];
           
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }
}

int main() {
    vector<int> arr;
    int n;
    int a;
    cout<<"Enter the total number of elements which you want to sort"<<endl;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }
    radixSort(arr,n);
    for (auto num : arr)
        cout << num << " ";
    cout << endl;
    return 0;
}