# [Reverse String](https://leetcode.com/problems/reverse-string/)

## Difficulty

Medium

## Tags

String & Array

## Description

Given a collection of **distinct** integers, return all possible permutations.

**Example:**
<pre style="font-family: consolas">
<b>Input:</b> [1,2,3]
<b>Output:</b>
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
</pre>

## Analysis

Let's see the above example first. From `[1, 2, 3]` to `[1, 3, 2]`, the last two elements are swapped. Then, from `[1, 3, 2]` to `[2, 1, 3]`, it is swapped back to `[1, 2, 3]`, then the first two elements are swapped. Finally, from `[2, 3, 1]` to `[3, 1, 2]`, it is first swapped to `[2, 1, 3]`, then `[1, 2, 3]`, and `[3, 1, 2]`. We can see that the generation of each line is the swap of every two elements. We swap the first element to every other element, then consider the remaining array and continue swapping the first.

We assume the length of the array is `n`, then
- Time Complexity: `O(n!)`
- Space Complexity: `O(n*n!)`
