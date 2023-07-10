#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

// Function to compare items based on their value-to-weight ratio
bool compareItems(const Item& item1, const Item& item2) {
    double ratio1 = static_cast<double>(item1.value) / item1.weight;
    double ratio2 = static_cast<double>(item2.value) / item2.weight;
    return ratio1 > ratio2;
}

// Function to calculate the upper bound of the maximum possible value
// that can be obtained by including items partially
double calculateBound(int capacity, int currentWeight, int currentValue, const vector<Item>& items, int index) {
    double bound = currentValue;
    int remainingWeight = capacity - currentWeight;

    while (index < items.size() && items[index].weight <= remainingWeight) {
        remainingWeight -= items[index].weight;
        bound += items[index].value;
        index++;
    }

    if (index < items.size())
        bound += static_cast<double>(remainingWeight) / items[index].weight * items[index].value;

    return bound;
}

// Recursive function to solve the 0/1 Knapsack problem using Branch and Bound
void knapsackBranchAndBound(int capacity, int currentWeight, int currentValue, const vector<Item>& items,
                            vector<bool>& included, vector<bool>& bestSolution, int& bestValue, int index) {
    if (index == items.size()) {
        if (currentValue > bestValue) {
            bestValue = currentValue;
            bestSolution = included;
        }
        return;
    }

    // Check if the item can be included
    if (currentWeight + items[index].weight <= capacity) {
        included[index] = true;
        knapsackBranchAndBound(capacity, currentWeight + items[index].weight,
                               currentValue + items[index].value, items, included, bestSolution, bestValue, index + 1);
        included[index] = false;
    }

    // Calculate the upper bound and prune the branch if it is not promising
    double bound = calculateBound(capacity, currentWeight, currentValue, items, index + 1);
    if (bound > bestValue) {
        knapsackBranchAndBound(capacity, currentWeight, currentValue, items, included, bestSolution, bestValue, index + 1);
    }
}

// Function to solve the 0/1 Knapsack problem using Branch and Bound
vector<bool> solveKnapsack(int capacity, const vector<Item>& items) {
    vector<bool> included(items.size(), false);
    vector<bool> bestSolution(items.size(), false);
    int bestValue = 0;

    // Sort items based on their value-to-weight ratio
    sort(items.begin(), items.end(), compareItems);

    knapsackBranchAndBound(capacity, 0, 0, items, included, bestSolution, bestValue, 0);

    return bestSolution;
}

int main() {
    int capacity = 10;
    vector<Item> items = {{2, 10}, {3, 5}, {5, 15}, {7, 7}, {1, 6}, {4, 18}, {1, 3}};

    vector<bool> solution = solveKnapsack(capacity, items);

    cout << "Selected items: ";
    for (int i = 0; i < solution.size(); ++i) {
        if (solution[i])
            cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}
