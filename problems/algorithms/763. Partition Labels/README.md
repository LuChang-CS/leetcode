# [Partition Labels](https://leetcode.com/problems/partition-labels/)

## Difficulty

Medium

## Tags

Array

## Description

A string `S` of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

**Example 1:**

<pre style="font-family: consolas">
<b>Input:</b> S = "ababcbacadefegdehijhklij"
<b>Output:</b> [9, 7, 8]

<b>Explanation:</b>
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
</pre>

**Note:**
- `S` will have length in range `[1, 500]`.
- `S` will consist of lowercase letters (`'a'` to `'z'`) only.

## Analysis

This is an interesting array problem, and maybe you will read several more times to comprehend it. In this problem we need to separate `S` into some parts, and each letter have to appear in at most one part, which means the last letter will never appear in successive parts. Therefore, we can naturally have an idea that we need to record the last appearance position of each letter.

In the example above, The last appearance position of `a` is `9`, and letters between `1` and `9` do not appear after `a`, so we can find the first part of `1` to `9`. Then, we know the second part starts at `d` of position `10`, and its last appearance position is `15`. But `e` appears after `15` at `16`, then we have to move the end of second part to `16`. And we find that `16` is exactly the end of the second part.

In conclusion, the basic idea is find the end of each part, which is the maximum position of last appearance in this part.

Assuming the length of `S` is `n`, we have
- Time Complexity: `O(n)`
- Space Complexity: `O(1)` (We only need to store the last position of each letter, and the return size is obviously at worst 26, because each letter appears in only one part.)
