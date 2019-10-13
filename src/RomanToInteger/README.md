# Roman to Integer

LeetCode [source](https://leetcode.com/problems/roman-to-integer/)

## Solution

### Intuition

We can traverse from the back to the front, because under normal circumstances, the reverse order of strings is arranged from small to large, so if we can find a relationship, know whether this character should be added or subtracted. Obviously, if the current sum is greater than or equal to 5, then it should be reduced.

### Algorithm

| Expression | Operate | Description |
|------------|---------|-------------|
| ???I[sum] | sum -= 1 | when sum >= 5 |
| ???X[sum] | sum -= 10 | when sum >= 50 |
| ???C[sum] | sum -= 100 | when sum >= 500 |

### Complexity Analysis

* Time Complexity: **O(n)**. There are **n** characters in a roman numeral.
* Space Complexity: **O(1)**.

## AC Result

| Status | Runtime | Memory |
|--------|---------|--------|
| Accepted | 12 ms | 8.3 MB |
