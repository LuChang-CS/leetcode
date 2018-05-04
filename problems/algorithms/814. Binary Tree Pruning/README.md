# [Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning/)

## Difficulty

Medium

## Tags

Binary Tree, Recursive Algorithm

## Description

We are given the head node `root` of a binary tree, where additionally every node's value is either a 0 or a 1.

Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

<pre style="font-family: consolas">
<b>Example 1:</b>
<b>Input:</b> [1, null, 0, 0, 1]
<b>Output:</b> [1, null, 0, null, 1]

<b>Explanation:</b> 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png" style="width:450px" />
</pre>

<pre style="font-family: consolas">
<b>Example 2:</b>
<b>Input:</b> [1, 0, 1, 0, 0, 0, 1]
<b>Output:</b> [1, null, 1, null, 1]

<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png" style="width:450px" />
</pre>

<pre style="font-family: consolas">
<b>Example 3:</b>
<b>Input:</b> [1, 1, 0, 1, 1, 0, 1, 0]
<b>Output:</b> [1, 1, 0, 1, 1, null, 1]

<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028.png" style="width:450px" />
</pre>

Note:

- The binary tree will have at most `100 nodes`.
- The value of each node will only be `0` or `1`.

## Analysis

This is a problem about the binary tree. However, it is not a complicated problem because we only need a preorder traversal and count the number of 1 in the subtree of a node. Then if the count is `0` of the subtree for a node, we just need to make the pointer to `null`.

We assume that the nodes number is `n`, then
- Time Complexity: `O(n)`
- Space Complexity: `O(n)` (We need to maintain a count for each node)
