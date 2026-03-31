# Experiment 7: Cheapest Flights Within K Stops

## Problem Statement
There are n cities connected by flights. Each flight is represented as:
[from, to, price]

Find the cheapest price from source (src) to destination (dst) with at most k stops.
If no such route exists, return -1.

---

## Algorithm (Step-by-Step)

Step 1: Create an adjacency list from the given flights array.

Step 2: Initialize a queue to store (current_city, total_cost, stops).

Step 3: Create a distance array and initialize all values to infinity.

Step 4: Set distance[src] = 0 and push (src, 0, 0) into the queue.

Step 5: While the queue is not empty:
- Remove the front element (node, cost, stops).
- If stops > k, skip this path.
- For each neighbor of the current node:
  - Calculate new cost = cost + price.
  - If new cost < distance[neighbor]:
    - Update distance[neighbor].
    - Push (neighbor, new cost, stops + 1) into queue.

Step 6: After traversal:
- If distance[dst] is still infinity, return -1.
- Otherwise, return distance[dst].

---

## Dry Run

Input:
n = 4  
flights = [[0,1,100],[1,2,100],[2,3,100],[0,3,500]]  
src = 0, dst = 3, k = 1  

Output:
500

---

## Time Complexity
O(E + V)

---

## Space Complexity
O(V + E)

---
