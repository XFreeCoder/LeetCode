# Palindrome Number

LeetCode [source](https://leetcode.com/problems/palindrome-number/)

## Solution

### Intuition

The challenge with this problem is that you're not allowed to use any string. You have to take the integer and come up with a solution that doesn't employ string or any of its methods. From the first glance, what was apparent is that we'll need a data structure to hold the individual integers for comparison.

### Algorithm
Details of the the algorithm for the solution is as follows:
1. If it's a single digit, then it's a Palindrome Number. 
2. Ignore any negative integers.
3. For all other types of integers, pop each digit and store them in a vector in order.
4. Compare the `(n + i)th` integer with `(vector.size() - 1 - i)th integer. 
5. If this comparisos fails (i.e. `comparison == false`) return false. 
6. Else continue the comparisons until `i` reaches the middle of the vector. If no `false` was return before, it means all the comparisons were `true` and therefore, the integer is a palindrome.

### Complexity Analysis
* Time Complexity: `// TODO`
* Space Complexity: `// TODO`

### AC Result

`11509 / 11509 test cases passed`

| Status | Runtime | Memory |
|--------|---------|--------|
| Accepted | 36 ms | 11.7 MB |