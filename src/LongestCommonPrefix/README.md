# Longest Common Prefix

LeetCode [source](https://leetcode.com/problems/longest-common-prefix/)

## Solution

### Intuition

Let's take a look at a slightly different problem:

> Given a set of keys S = [S1,S2,…,Sn], find the longest common prefix among a string **q** and **S**. This LCP query will be called frequently.

We could optimize LCP queries by storing the set of keys **S** in a Trie. For more information about Trie, please see this article [Implement a trie (Prefix trie)](https://leetcode.com/articles/implement-trie-prefix-tree/). In a Trie, each node descending from the root represents a common prefix of some keys. But we need to find the longest common prefix of a string q and all key strings. This means that we have to find the deepest path from the root, which satisfies the following conditions:

* it is prefix of query string **q**
* each node along the path must contain only one child element. Otherwise the found path will not be a common prefix among all strings.
* the path doesn't comprise of nodes which are marked as end of key. Otherwise the path couldn't be a prefix a of key which is shorter than itself.

### Algorithm

The only question left, is how to find the deepest path in the Trie, that fulfills the requirements above. The most effective way is to build a trie from **[S1…Sn]** strings. Then find the prefix of query string **q** in the Trie. We traverse the Trie from the root, till it is impossible to continue the path in the Trie because one of the conditions above is not satisfied.

### Complexity Analysis

In the worst case query **q** has length **m** and it is equal to all **n** strings of the array.

* Time Complexity: preprocessing **O(S)**, where **S** is the number of all characters in the array, LCP query **O(m)**.

    Trie build has **O(S)** time complexity. To find the common prefix of **q** in the Trie takes in the worst case **O(m)**.

* Space Complexity: **O(S)**. We only used additional **S** extra space for the Trie.

## AC Result

| Status | Runtime | Memory |
|--------|---------|--------|
| Accepted | 4 ms | 9.6 MB |
