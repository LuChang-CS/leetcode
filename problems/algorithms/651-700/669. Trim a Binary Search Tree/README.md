# [Trim a Binary Search Tree](https://leetcode.com/problems/trim-a-binary-search-tree/)

## Difficulty

Easy

## Tags

Binary Tree, Recursive Algorithm

## Description

Given a binary search tree and the lowest and highest boundaries as `L` and `R`, trim the tree so that all its elements lies in `[L, R]` (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

**Example 1:**

<pre style="font-family: consolas">
<b>Input:</b>
    1
   / \
  0   2

  L = 1
  R = 2
<b>Output:</b>
    1
      \
       2
</pre>

**Example 2:**

<pre style="font-family: consolas">
<b>Input:</b>
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3
<b>Output:</b>
      3
     / 
   2   
  /
 1
</pre>

## Analysis

This is a basic Recursive Problem. In this problem, we should first consider whether the value of the node itself needs to be trimmed, then the left and right child. If the value of the node is less than `L`, we need to use the right child to replace it because the right child might be greater than `L`. And the same procedure is applied to the cases where the value is greater than `R`. After comparing this node itself, we next need to traverse to it left and right child.

Assuming that the number of nodes is `n`, we have
- Time Complexity: `O(n)`
- Space Complexity: `O(1)`
