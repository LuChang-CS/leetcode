# [Shortest Distance to a Character](https://leetcode.com/problems/shortest-distance-to-a-character/)

## Difficulty

Easy

## Tags

String & Array

## Description

Given a string `S` and a character `C`, return an array of integers representing the shortest distance from the character `C` in the string.

**Example 1:** 
<pre style="font-family: consolas">
<b>Input:</b> S = "loveleetcode", C = 'e'
<b>Output:</b> [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
</pre>

**Note:**
- `S` string length is in `[1, 10000]`.
- `C` is a single character, and guaranteed to be in string `S`.
- All letters in `S` and `C` are lowercase.

## Analysis

We can use the figure below to explain this algorithm:

![example](../../../solutions/figs/algo_821_1.png)

The dark color is the specified characters, and we use different dark color to represent different positions. We can easily see that the light-color dots are closest to the same dark color. Therefore, the shortest distance should be calculated according to the dark-color dots. And obviously, the boundary of two dark-color dots is their middle element. So we can first find all positions of the specified character, and directly calculated the shortest distance of each character from the last middle boundary to the next middle boundary.

We assume the length of `S` is `n`, the number of the specified character is `m`, then
- Time Complexity: `O(n)`
- Space Complexity: `O(m)`
