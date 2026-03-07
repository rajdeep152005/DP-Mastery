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

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {

            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {

    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;

    int n = wt.size();

    cout << "Maximum value = " << knapsack(W, wt, val, n) << endl;

    return 0;
}
```

## Complexity

```
Time Complexity  : O(N × W)
Space Complexity : O(N × W)
```

---

Recurrence (Knapsack → Subset Sum)

##Knapsack
```
dp[i][j] = max(
value[i-1] + dp[i-1][j-weight[i-1]],
dp[i-1][j]
)
```
##Subset Sum
```
dp[i][j] =
dp[i-1][j-arr[i-1]] || dp[i-1][j]
```
##Equal Sum Partition
```
if(arr[i-1] <= j)
    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
else
    dp[i][j] = dp[i-1][j];
Only Extra Step (Equal Partition)
int sum = total array sum;

if(sum % 2 != 0)
    return false;

target = sum / 2;
```
