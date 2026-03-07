# 0/1 Knapsack Problem

## Problem Statement
The **0/1 Knapsack Problem** is a classic Dynamic Programming problem.

Given **N items**, each item has:
- Weight
- Value

We also have a **knapsack with capacity W**.  
The goal is to find the **maximum total value** that can be obtained without exceeding the knapsack capacity.

Each item can be **taken only once (0 or 1 choice)**.

---

## Example

Input:
```
Weights = [1, 3, 4, 5]
Values  = [1, 4, 5, 7]
Capacity = 7
```

Output:
```
Maximum Value = 9
```

---

## Dynamic Programming Approach

We create a **DP table** where:

```
dp[i][w]
```

represents the **maximum value using first i items with capacity w**.

### Recurrence Relation

```
if (wt[i-1] <= w)
    dp[i][w] = max(
        val[i-1] + dp[i-1][w-wt[i-1]],
        dp[i-1][w]
    )
else
    dp[i][w] = dp[i-1][w]
```

---

## Java Implementation

```java
public class Knapsack01 {

    static int knapsack(int W, int wt[], int val[], int n) {

        int dp[][] = new int[n + 1][W + 1];

        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= W; w++) {

                if (i == 0 || w == 0)
                    dp[i][w] = 0;

                else if (wt[i - 1] <= w)
                    dp[i][w] = Math.max(
                            val[i - 1] + dp[i - 1][w - wt[i - 1]],
                            dp[i - 1][w]
                    );

                else
                    dp[i][w] = dp[i - 1][w];
            }
        }

        return dp[n][W];
    }

    public static void main(String[] args) {

        int val[] = {1, 4, 5, 7};
        int wt[] = {1, 3, 4, 5};
        int W = 7;

        System.out.println("Maximum value = " + knapsack(W, wt, val, val.length));
    }
}
```

---

## Complexity

```
Time Complexity  : O(N × W)
Space Complexity : O(N × W)
```

---

## Topics
- Dynamic Programming
- Knapsack Pattern
- Optimization Problem
