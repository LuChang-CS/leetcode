# [Jewels and Stones](https://leetcode.com/problems/jewels-and-stones/)

## Difficulty

Easy

## Tags

Hash Table

## Description

You're given strings `J` representing the types of stones that are jewels, and `S` representing the stones you have. Each character in `S` is a type of stone you have. You want to know how many of the stones you have are also jewels.

The letters in `J` are guaranteed distinct, and all characters in `J` and `S` are letters. Letters are case sensitive, so `"a"` is considered a different type of stone from `"A"`.

**Example 1:**

<pre style="font-family: consolas">
<b>Input:</b> J = "aA", S = "aAAbbbb"
<b>Output:</b> 3
</pre>

**Example 2:**

<pre style="font-family: consolas">
<b>Input:</b> J = "z", S = "ZZ"
<b>Output:</b> 0
</pre>

Note:

- `S` and `J` will consist of letters and have length at most 50.
- The characters in `J` are distinct.

## Analysis

This is an easy problem. All we need to do is to verify wether each letter in `S` exists in `J`.

Therefore, we can use a hash set to store `J`. Specifically, `J` is composed of letters (lower or upper) only, so we can use an array of `char` to store each letter in `J`. After that, we only need to iterate `S` to calculate the number of jewels.

We assume the length of `J` is `m`, the length of `S` is `n`, then

- Time complexity: `O(m + n)`
- Space complexity: `O(1)` (256 ASCII chars)
