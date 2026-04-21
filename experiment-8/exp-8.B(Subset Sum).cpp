#include <iostream>
using namespace std;

bool subsetSum(int arr[], int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;
    if (arr[n - 1] > sum)
        return subsetSum(arr, n - 1, sum);
    return subsetSum(arr, n - 1, sum) || subsetSum(arr, n - 1, sum - arr[n - 1]);
}

bool verifySubset(int subset[], int size, int target) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += subset[i];
    return sum == target;
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    if (subsetSum(arr, n, target))
        cout << "Subset exists\n";
    else
        cout << "No subset exists\n";

    int subset[] = {4, 5};
    int size = sizeof(subset) / sizeof(subset[0]);

    if (verifySubset(subset, size, target))
        cout << "Valid subset\n";
    else
        cout << "Invalid subset\n";

    return 0;
}
