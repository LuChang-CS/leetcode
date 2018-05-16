# [Number Complement](https://leetcode.com/problems/number-complement/)

## Difficulty

Easy

## Tags

Bitwise Operation

## Description

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

**Note:**
1. The given integer is guaranteed to fit within the range of a 32-bit signed integer.
2. You could assume no leading zero bit in the integer's binary representation.

**Example 1:**
<pre style="font-family: consolas">
<b>Input:</b> 5
<b>Output:</b> 2

<b>Explanation:</b> The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
</pre>

**Example 2:**
<pre style="font-family: consolas">
<b>Input:</b> 1
<b>Output:</b> 0

<b>Explanation:</b> The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
</pre>

## Analysis
There are many method to solve this problem. For example, you can fetch each bit of this num and calculate its complementary bit. In our solution, we use a different way to calculate. The key point in this problem is how to ignore the leading zero of a number. For example, `~5 = 1...11010` and `~5 & 7 = 2 = 010`. So, what we need to do is find the smallest `2^n - 1` that larger than this number. Then we can calculate the complementary number without leading zeros by `~num & (2^n - 1)`, where `n = floor(log2(num))`. Therefore, this problem transforms to how to fast calculate `floor(log2(num))`. In [http://www.graphics.stanford.edu/~seander/bithacks.html](http://www.graphics.stanford.edu/~seander/bithacks.html), we can find a way with `O(log(N))` time complexity, in which `N` is the bit length of this number.

- Time Complexity: `O(log(N))`
- Space Complexity: `O(1)`
