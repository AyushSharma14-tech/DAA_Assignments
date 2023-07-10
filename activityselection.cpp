//Implement Activity selection problem using greedy approach
#include<bits/stdc++.h>
using namespace std;

bool activityCompare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int maxActivities(vector<vector<int>>& activities) {
    int n = activities.size();
    int count = 1;
    int lastEnd = activities[0][1];

    sort(activities.begin(), activities.end(), activityCompare);

    for (int i = 1; i < n; i++) {
        if (activities[i][0] >= lastEnd) {
            count++;
            lastEnd = activities[i][1];
        }
    }

    return count;
}

int main() {
    vector<vector<int>> activities = {{1, 3}, {2, 5}, {3, 7}, {4, 9}, {5, 11}, {6, 13}, {7, 15}};
    int maxCount = maxActivities(activities);
    cout << "Maximum number of non-overlapping activities: " << maxCount << endl;
    return 0;
}