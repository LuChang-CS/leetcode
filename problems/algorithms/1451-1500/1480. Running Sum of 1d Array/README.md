# [Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)

## Difficulty

Easy

## Tags

String & Array

## Description

Given an array `nums`. We define a running sum of an array as `runningSum[i] = sum(nums[0]...nums[i])`.

Return the running sum of `nums`.

<b>Example 1:</b>
<pre style="font-family: consolas">
<b>Input:</b> nums = [1, 2, 3, 4]
<b>Output:</b> [1, 3, 6, 10]
<b>Explanation:</b> 
Running sum is obtained as follows: [1, 1 + 2, 1 + 2 + 3, 1 + 2 + 3 + 4].
</pre>

<b>Example 2:</b>
<pre style="font-family: consolas">
<b>Input:</b> nums = [1, 1, 1, 1, 1]
<b>Output:</b> [1, 2, 3, 4, 5]
<b>Explanation:</b> Running sum is obtained as follows: [1, 1 + 1, 1 + 1 + 1, 1 + 1 + 1 + 1, 1 + 1 + 1 + 1 + 1].
</pre>

<b>Example 3:</b>
<pre style="font-family: consolas">
<b>Input:</b> nums = [3, 1, 2, 10, 1]
<b>Output:</b> [3, 4, 6, 16, 17]
</pre>

**Constraints:**

- `1 <= nums.length <= 1000`
- `-10^6 <= nums[i] <= 10^6`

## Analysis

This is a simple math problem. We just iterate the array and add the element. Here are some tricks:
- We can operate in place.
- For c, we can operate using pointer to accelerate.

We assume the length of `nums` is `n`:
- Time Complexity: `O(n)`
- Space Complexity: `O(1)`
