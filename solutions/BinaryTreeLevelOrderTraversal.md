# Binary Tree Level Order Traversal

LeetCode [source](https://leetcode.com/problems/binary-tree-level-order-traversal/)

## Solution

### Intuition

DFS with a level parameters.

### Algorithm

1. Create a `Vec`
2. Traversal tree by DFS with level
3. If `level === ans.length`, create a nest `Vec` to `ans`
4. `ans[level].push(node)`

### Complexity Analysis

- Time Complexity: Traversal the tree use **O(n)**.

- Space Complexity: **O(n)**. We only used additional **n** extra space for the `Vec`.

## AC Result

| Status   | Runtime | Memory | Language                                                     |
| -------- | ------- | ------ | ------------------------------------------------------------ |
| Accepted | 0 ms    | 2.4 MB | [rust](../src/rust/src/binary_tree_level_order_traversal.rs) |
