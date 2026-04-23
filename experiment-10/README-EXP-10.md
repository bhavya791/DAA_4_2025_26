# 📘 Experiment 10: Distinct Subsequences

## 🔹 Problem Statement
Given two strings `s` and `t`, return the number of distinct subsequences of `s` which equals `t`.

A subsequence is formed by deleting characters without changing the relative order of remaining characters.

---

## 🔹 Algorithm (Dynamic Programming)

### Idea:
We use a DP table where:

- `dp[i][j]` = number of ways to form first `j` characters of `t` using first `i` characters of `s`.

---

### Steps:

1. Let:
   - `n = length of s`
   - `m = length of t`

2. Create a DP table of size `(n+1) x (m+1)`

3. Initialize base cases:
   - `dp[i][0] = 1` → empty `t` can always be formed
   - `dp[0][j] = 0` → non-empty `t` cannot be formed from empty `s`

4. Fill the DP table:
   - If `s[i-1] == t[j-1]`  
     → `dp[i][j] = dp[i-1][j-1] + dp[i-1][j]`
   - Else  
     → `dp[i][j] = dp[i-1][j]`

5. Final Answer:
   - `dp[n][m]`

---

## 🔹 Time Complexity

- **O(n × m)**  
We fill a DP table of size `n × m`

---

## 🔹 Space Complexity

- **O(n × m)** for DP table  
- Can be optimized to **O(m)** using 1D DP

---

## 🔹 Dry Run

### Example 1:
s = "rabbbit"  
t = "rabbit"

#### Explanation:
- There are multiple `'b'` characters in `s`
- We can remove one `'b'` in 3 different ways to form `"rabbit"`

#### Output:
3

---

### Example 2:
s = "babgbag"  
t = "bag"

#### Possible subsequences:
1. b → a → g  
2. b → a → g  
3. b → a → g  
4. b → a → g  
5. b → a → g  

#### Output:
5

---

