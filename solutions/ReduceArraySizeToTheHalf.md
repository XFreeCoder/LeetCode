# Reduce Array Size to The Half

LeetCode [source](https://leetcode.com/problems/reduce-array-size-to-the-half/)

## Solution

### Intuition

Build a frequency hash map, then sort using counting sort. Keep adding the integer with the max frequency until you remove at least half of the integers.

### Algorithm

1. Count the frequency of each integer in the array using a hash map.

2. Sort the frequencies by counting sort.

3. Keep remove the maximum frequency from the sorted frequencies until **removed >= half**.

### Complexity Analysis

In worst case, the maximum value in frequencies array is **1**, this happens when all numbers in array are the uniq.

- Time Complexity: preprocessing **O(n)**, where build frequency map need **O(n)** and counting sort need **O(n)**.

- Space Complexity: **O(n)**. We only used additional **n** extra space for the hash map and counting vector.

## AC Result

| Status   | Runtime | Memory  | Language                                                 |
| -------- | ------- | ------- | -------------------------------------------------------- |
| Accepted | 278 ms  | 77.7 MB | [cpp](../src/cpp/ReduceArraySizeToTheHalf/Solution.cpp)  |
| Accepted | 19 ms   | 5 MB    | [rust](../src/rust/src/reduce_array_size_to_the_half.rs) |
