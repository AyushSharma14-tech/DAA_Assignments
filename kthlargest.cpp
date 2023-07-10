//Kth min and kth max using partition
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (nums[j] >= pivot) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[right]);
    return i;
}

int findKthLargest(vector<int>& nums, int k) {
    int left = 0;
    int right = nums.size() - 1;
    while (true) {
        int pos = partition(nums, left, right);
        if (pos == k - 1) {
            return nums[pos];
        } else if (pos > k - 1) {
            right = pos - 1;
        } else {
            left = pos + 1;
        }
    }
}

int main() {
    vector<int> nums;
    int a,n,k;
    cout<<"Enter the total number of elements you want to enter"<<endl;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>a;
        nums.push_back(a);
    }
    cout<<"Enter which largest element you want to find out"<<endl;
    cin>>k;
    if(k>=1&&k<=n){
    int kthLargest = findKthLargest(nums, k);
    cout << "The " << k << "th largest element is " << kthLargest << endl;
    }
    else{
        cout<<"Please enter right value of k"<<endl;
    }
    return 0;
}