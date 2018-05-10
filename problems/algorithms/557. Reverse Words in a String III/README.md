# [Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/)

## Difficulty

Easy

## Tags

String & Array

## Description

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

**Example 1:**

<pre style="font-family: consolas">
<b>Input:</b> "Let's take LeetCode contest"
<b>Output:</b> "s'teL ekat edoCteeL tsetnoc"
</pre>

**Note:** In the string, each word is separated by single space and there will not be any extra space in the string.

## Analysis

The steps in this problems are very clear. We need to find the spaces, and reverse the words between two spaces.

We assume the length of the string is `n`, then
- Time Complexity: `O(n)`
- Space Complexity: `O(1)`
