# [500. Keyboard Row](https://leetcode.com/problems/keyboard-row/)

## Difficulty

Easy

## Tags

String & Array

## Description

Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

![keyboard](../../../solutions/figs/algo_500_1.png)

**Example 1:**

<pre style="font-family: consolas">
<b>Input:</b> ["Hello", "Alaska", "Dad", "Peace"]
<b>Output:</b> ["Alaska", "Dad"]
</pre>

**Note:**
- You may use one character in the keyboard more than once.
- You may assume the input string will only contain letters of alphabet.

## Analysis

Maybe this is a somewhat boring problem. We just need to check whether all letters of a word appear in one row of the keyboard. Therefore, we can pre-calculate the row table of the alphabet, and find in this table when iterate the words.

We assume that the number of words is `m` and the max length of a words is `n`, then
- Time Complexity: `O(mn)`
- Space Complexity: `O(1)`
