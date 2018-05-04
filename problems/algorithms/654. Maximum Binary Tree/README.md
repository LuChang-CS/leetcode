# [Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/)

## Difficulty

Medium

## Tags

Binary Tree

## Description

Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

1. The root is the maximum number in the array.
2. The left subtree is the maximum tree constructed from left part sub-array divided by the maximum number.
3. The right subtree is the maximum tree constructed from right part sub-array divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

**Example 1:**
<pre style="font-family: consolas">
<b>Input:</b> [3, 2, 1, 6, 0, 5]
<b>Output:</b> return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
</pre>

**Note**
1. The size of the given array will be in the range [1, 1000].

## Analysis
At first sight, we can easily know that we can design a recursive algorithm to find the maximum value, take it as root, and do the same step on the left and right array. But in this way, we get the time complexity of `O(n * n)` assuming that the number of array is `n`, because we need to find the maximum value for each sub-array.

We can directly build this maximum binary tree in the following steps:
1. Choose the first value as the root;
2. For each successive value, if it is larger that the root, take it as root, and the previous root and its subtree as the left subtree of root (because previous root is the left array). Otherwise go to step 3;
3. If the successive value is less than the root, then compare it with the right node of root (because this value is at the right array). If right node is null, take this value as right node. Otherwise go to step 2.

- Time Complexity: Average is `O(nlogn)` because we need to insert each value to a tree. Worst case is `O(n * n)`, when original array is descending. In this case, this algorithm degenerates to the insertion sort.
- Space Complexity: `O(1)` (We don't need extra space).