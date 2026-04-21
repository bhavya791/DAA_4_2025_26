1. Why does Binary Search consistently demonstrate efficient performance across large input sizes?

Binary Search is efficient because it reduces the search space by half at every step. Instead of checking each element one by one, it directly jumps to the middle and decides which half to continue searching in. Because of this repeated halving, the number of steps grows very slowly even if the input size becomes very large. This is why its time complexity is O(log n), making it very fast and scalable.

---

2. Explain why Subset Sum is computationally difficult to solve but relatively easy to verify.

The Subset Sum problem is difficult to solve because we need to check all possible subsets of the given set to find if any subset adds up to the target. The number of subsets is 2^n, which grows very quickly as n increases. However, if someone already gives us a subset, verifying it is simple — we just add the numbers and check if the sum matches the target. This only takes linear time O(n). So, solving is hard, but verifying is easy.

---

3. Identify the input size at which the Traveling Salesman Problem becomes infeasible and justify the reason.

The Traveling Salesman Problem becomes infeasible when the number of cities increases to around 10–12 or more. This is because the number of possible routes grows factorially (n!), which increases extremely fast. For example, with 10 cities there are already millions of possible paths. As the input grows, the time required becomes too large, leading to very slow execution or even timeout.

---

4. Differentiate between solving a problem and verifying a given solution with appropriate examples.

Solving a problem means finding the answer from scratch, which can be computationally expensive. Verifying a solution means checking whether a given answer is correct, which is usually much easier.

For example, in the Subset Sum problem:
- Solving: Finding a subset that adds up to the target (hard, exponential time)
- Verifying: Checking if a given subset sums to the target (easy, linear time)

This shows that verification generally requires less computation than solving.

---

5. Discuss why NP-Complete problems are considered the most challenging class within NP.

NP-Complete problems are considered the hardest problems in the NP class because they are both difficult to solve and represent all problems in NP. If we find an efficient (polynomial-time) solution for even one NP-Complete problem, then all NP problems can be solved efficiently. However, no such solution has been found yet. Because of this, NP-Complete problems like Subset Sum and Traveling Salesman are considered highly complex and important in computer science.
