#include <bits/stdc++.h>
using namespace std;
#include <chrono>

long operations = 0;
int maxDepth = 0;

void complexRec(int n, int depth) {
    maxDepth = max(maxDepth, depth);
    if (n <= 2) {
        operations++;
        return;
    }

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
        }
        p >>= 1;
        operations++;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operations += n;
    }

    if (n % 3 == 0) {
        reverse(small.begin(), small.end());
        operations++;
    } else {
        reverse(small.begin(), small.end());
        operations += n;
    }

    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {
    int n;
    cin >> n;

    auto start = chrono::high_resolution_clock::now();
    complexRec(n, 1);
    auto end = chrono::high_resolution_clock::now();

    double duration = chrono::duration<double, milli>(end - start).count();

    cout << "Operations: " << operations << "\n";
    cout << "Max Recursion Depth: " << maxDepth << "\n";
    cout << "Time Taken: " << duration << " ms\n";

    return 0;
}

/*
TIME COMPLEXITY ANALYSIS:

In each function call:
1. The while loop runs log n times and does n work each time → O(n log n)
2. The for loop and reverse together take O(n)

So, total work in one call = O(n log n)

The function makes 3 recursive calls with input size n/2.

Recurrence Relation:
T(n) = 3T(n/2) + O(n log n)

Using Master Theorem:
a = 3, b = 2
n^(log₂3) ≈ n^1.585

this is Case 1 of Master Theorem.

Final Time Complexity:
T(n) = O(n^1.585)
*/

