# 📘 DAA Assignment  
## Problems Covered:
1. N-Queens Problem  
2. Hamiltonian Cycle  

---

# 🔷 1. N-Queens Problem

## 📌 Problem Statement
Place N queens on an N × N chessboard such that no two queens attack each other.

## ✅ Approach
- Use **Backtracking**
- Place queens row by row
- Use **hashing optimization**:
  - `col[]` → track columns
  - `diag1[]` → track (row - col)
  - `diag2[]` → track (row + col)

## ⏱ Complexity
- Time: **O(N!)**
- Space: **O(N²)**

---

## 💻 Code: NQueens.cpp

```cpp
#include <bits/stdc++.h>
using namespace std;

class NQueens {
public:
    int n;
    vector<vector<string>> solutions;

    void solveNQueens(int n) {
        this->n = n;

        vector<string> board(n, string(n, '.'));
        vector<int> col(n, 0), diag1(2*n, 0), diag2(2*n, 0);

        solve(0, board, col, diag1, diag2);

        cout << "Total Solutions: " << solutions.size() << "\n\n";

        for (auto &sol : solutions) {
            for (auto &row : sol) {
                cout << row << "\n";
            }
            cout << "----------------\n";
        }
    }

private:
    void solve(int r, vector<string>& board,
               vector<int>& col,
               vector<int>& diag1,
               vector<int>& diag2) {

        if (r == n) {
            solutions.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (!col[c] && !diag1[r - c + n] && !diag2[r + c]) {

                board[r][c] = 'Q';
                col[c] = diag1[r - c + n] = diag2[r + c] = 1;

                solve(r + 1, board, col, diag1, diag2);

                board[r][c] = '.';
                col[c] = diag1[r - c + n] = diag2[r + c] = 0;
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    NQueens obj;
    obj.solveNQueens(n);

    return 0;
}


```
---
# 🔷 2. Hamiltonian Cycle Problem

## 📌 Problem Statement
Given an undirected graph, determine whether a Hamiltonian cycle exists.  
A Hamiltonian cycle is a cycle that visits every vertex exactly once and returns to the starting vertex.

---

## 🎯 Objectives
- Print one valid Hamiltonian cycle if it exists  
- Return/print false if no cycle exists  
- Use adjacency matrix representation  

---

## 🧠 Approach (Backtracking)
- Start from vertex `0`
- Try to add vertices to the path one by one
- Check:
  - Vertex is adjacent to previous vertex
  - Vertex is not already included in the path
- If all vertices are included:
  - Check if last vertex connects back to first

---

## ⏱ Complexity
- Time: **O(N!)**
- Space: **O(N)**

---

## 💻 Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class HamiltonianCycle {
    int V;
    vector<vector<int>> graph;

public:
    HamiltonianCycle(vector<vector<int>> g) {
        graph = g;
        V = g.size();
    }

    bool isSafe(int v, vector<int>& path, int pos) {
        // Check adjacency
        if (graph[path[pos - 1]][v] == 0)
            return false;

        // Check if already visited
        for (int i = 0; i < pos; i++)
            if (path[i] == v)
                return false;

        return true;
    }

    bool solveUtil(vector<int>& path, int pos) {
        // Base case: all vertices included
        if (pos == V) {
            return graph[path[pos - 1]][path[0]] == 1;
        }

        // Try different vertices
        for (int v = 1; v < V; v++) {
            if (isSafe(v, path, pos)) {
                path[pos] = v;

                if (solveUtil(path, pos + 1))
                    return true;

                // Backtrack
                path[pos] = -1;
            }
        }
        return false;
    }

    void findCycle() {
        vector<int> path(V, -1);
        path[0] = 0;

        if (solveUtil(path, 1)) {
            cout << "Hamiltonian Cycle Exists:\n";
            for (int i = 0; i < V; i++)
                cout << path[i] << " ";
            cout << path[0] << "\n";
        } else {
            cout << "No Hamiltonian Cycle exists\n";
        }
    }
};

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    HamiltonianCycle obj(graph);
    obj.findCycle();

    return 0;
}
