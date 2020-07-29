# [Binary Gap](https://leetcode.com/problems/binary-gap/)

## Difficulty

Easy

## Tags

Hash Table

## Description

Given a positive integer `N`, find and return the longest distance between two consecutive 1's in the binary representation of `N`.

If there aren't two consecutive 1's, return 0.

**Example 1:**
<pre style="font-family: consolas">
<b>Input: 22</b>
<b>Output:</b> 2
<b>Explanation:</b>
22 in binary is 0b10110.
In the binary representation of 22, there are three ones, and two consecutive pairs of 1's.
The first consecutive pair of 1's have distance 2.
The second consecutive pair of 1's have distance 1.
The answer is the largest of these two distances, which is 2.
</pre>

**Example 2:**
<pre style="font-family: consolas">
<b>Input: 5</b>
<b>Output:</b> 2
<b>Explanation:</b>
5 in binary is 0b101.
</pre>

**Example 3:**
<pre style="font-family: consolas">
<b>Input: 6</b>
<b>Output:</b> 1
<b>Explanation:</b>
6 in binary is 0b110.
</pre>

**Example 3:**
<pre style="font-family: consolas">
<b>Input: 8</b>
<b>Output:</b> 0
<b>Explanation:</b>
8 in binary is 0b1000.
There aren't any consecutive pairs of 1's in the binary representation of 8, so we return 0.
</pre>

Note:

- `1 <= N <= 10^9`

## Analysis

Using bitwise operation, we first find the first 1 from the right to left. Then we record the length of right shifting from the last 1.

- Time Complexity: `O(log(N))` (The length of `N`'s bits)
- Space Complexity: `O(1)`
