# [Self Dividing Numbers](https://leetcode.com/problems/self-dividing-numbers/)

## Difficulty

Easy

## Tags

Math

## Description

A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because `128 % 1 == 0`, `128 % 2 == 0`, and `128 % 8 == 0`.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

**Example 1:**

<pre style="font-family: consolas">
<b>Input:</b> left = 1, right = 22
<b>Output:</b> [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
</pre>

**Note**
- The boundaries of each input argument are `1 <= left <= right <= 10000`.

## Analysis

This key problem is to fetch each digit of an integer and check whether this integer can divide each digit. In addition, as long as this integer contains `0`, it is not a self-dividing number.

- Time Complexity: `O(right - left)`
- Space Complexity: `O(1)`
