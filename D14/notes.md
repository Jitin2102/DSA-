# Dynamic Programming (DP)

Dynamic Programming is an **optimization technique** used to solve complex problems by breaking them into smaller subproblems, storing their results, and reusing those results instead of solving the same subproblems repeatedly.

### Core Idea

1. **Break down:** Divide a complex problem into smaller subproblems.
2. **Store results:** Save the answers of previously solved subproblems.
3. **Reuse results:** Use stored answers whenever the same subproblem occurs again.

### Analogy: Fibonacci Numbers

Imagine calculating Fibonacci numbers using a notebook.

- Without DP, you repeatedly calculate the same Fibonacci values.
- With DP, you write down each calculated value and reuse it whenever needed.

This avoids unnecessary calculations and improves efficiency.

### Fibonacci Formula

\[
F(n) = F(n-1) + F(n-2)
\]

Where:

- \(F(0) = 0\)
- \(F(1) = 1\)

### Three Approaches to Solve Fibonacci

**1. Recursion (Brute Force)**

- Solves the problem by repeatedly calling smaller subproblems.
- Recalculates the same values multiple times.
- Time Complexity: **O(2ⁿ)**
- Space Complexity: **O(n)** (recursion stack).

**2. Memoization (Top-Down DP)**

- Uses recursion along with a storage structure (array/map).
- Stores previously calculated results.
- Reuses stored results whenever needed.
- Time Complexity: **O(n)**
- Space Complexity: **O(n)**.

**3. Tabulation (Bottom-Up DP)**

- Solves smaller subproblems first.
- Stores their results in a DP table.
- Builds the final answer iteratively without recursion.
- Time Complexity: **O(n)**
- Space Complexity: **O(n)**.

### Comparison of Three Approaches

| Approach | Technique | Time Complexity | Space Complexity |
|---|---|---|---|
| Recursion | Repeated function calls | O(2ⁿ) | O(n) |
| Memoization | Top-Down | O(n) | O(n) |
| Tabulation | Bottom-Up | O(n) | O(n) |

---

## Two Essential Properties of Dynamic Programming

DP is applicable when a problem satisfies these two properties:

### 1. Overlapping Subproblems

**Meaning:** The same smaller subproblems occur repeatedly while solving a larger problem.

**Example:** While calculating Fibonacci numbers, F(3) may be calculated multiple times.

DP stores the result of F(3) so that it does not need to be calculated again.

### 2. Optimal Substructure

**Meaning:** The optimal solution to a problem can be constructed using the optimal solutions of its smaller subproblems.

**Example:** In the shortest path problem, an optimal path from A to C through B contains an optimal path from A to B.

### Quick Revision

| Property | Key Idea |
|---|---|
| Overlapping Subproblems | Same subproblems are solved repeatedly. |
| Optimal Substructure | Optimal solutions are built from smaller optimal solutions. |

**Remember:**

- Overlapping Subproblems → Avoid repeated calculations.
- Optimal Substructure → Build the final solution from smaller solutions.

These two properties are the foundation for recognizing Dynamic Programming problems.
