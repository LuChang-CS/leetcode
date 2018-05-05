# [Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/)

## Difficulty

Easy

## Tags

Binary Tree, Recursive Algorithm

## Description

Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

**Example 1:**
<pre style="font-family: consolas">
<b>Input:</b>
        Tree 1                    Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
<b>Output:</b>
Merged tree:
         3
        / \
       4   5
      / \   \ 
     5   4   7
</pre>

**Note:** The merging process must start from the root nodes of both trees.

## Analysis

This is a problem about how to traverse two trees in the same time. If two nodes in each tree are both not null, we can simply add the value of Tree 2 to Tree 1. If the left child of node in Tree 1 is null while Tree 2 not, we can let the left child point to Tree 2's left child, which means move Tree 2's left child to Tree 1, and the same as right child. In this way, we don't need to malloc new node. Then we can use a recursive manner to traverse two trees and merge each node.

We assume the size of each tree is `m` and `n` respectively, then
- Time Complexity: `O(min(m, n))`
- Space Complexity: `O(1)`
