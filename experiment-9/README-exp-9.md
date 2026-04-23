# 📘 Experiment 9: Minimum Sum Partition

## 🔹 Problem Statement
Given an array of n positive integers, partition it into two subsets such that the absolute difference between their sums is minimized.

---

## 🧠 Algorithm

1. Take input array and calculate total sum of elements.
2. Create a DP table of size `dp[n+1][sum+1]`.
3. Initialize:
   - `dp[i][0] = true` (sum 0 is always possible).
4. Fill the DP table:
   - If current element is less than or equal to target sum:
     → `dp[i][j] = dp[i-1][j] OR dp[i-1][j-arr[i-1]]`
   - Else:
     → `dp[i][j] = dp[i-1][j]`
5. Find the largest value `j` such that:
   - `j ≤ sum/2` and `dp[n][j] = true`
6. Calculate minimum difference:
   - `difference = sum - 2*j`
7. Return the difference.

---

## ⏱️ Time and Space Complexity

- **Time Complexity:** `O(n × sum)`
- **Space Complexity:** `O(n × sum)`

Where:
- `n` = number of elements  
- `sum` = total sum of array  

---

## 🔍 Dry Run

### Input:
n = 4  
arr = [1, 6, 11, 5]

### Step 1:
Total sum = 23

### Step 2:
Target = sum/2 = 11

### Step 3:
Possible subsets:
- Subset 1: {6, 5} → sum = 11  
- Subset 2: {1, 11} → sum = 12  

### Step 4:
Difference = |12 - 11| = 1  

### ✅ Output:
1

---

## 📌 Approach Used
Dynamic Programming (Subset Sum)

