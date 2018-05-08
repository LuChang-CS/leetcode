# [Complex Number Multiplication](https://leetcode.com/problems/complex-number-multiplication/)

## Difficulty

Easy

## Tags

Math, String

## Description

Given two strings representing two [complex numbers](https://en.wikipedia.org/wiki/Complex_number).

You need to return a string representing their multiplication. Note i<sup>2</sup> = -1 according to the definition.

**Example 1:**

<pre style="font-family: consolas">
<b>Input:</b> "1+1i", "1+1i"
<b>Output:</b> "0+2i"
<b>Explanation:</b> (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
</pre>

**Example 2:**

<pre style="font-family: consolas">
<b>Input:</b> "1+-1i", "1+-1i"
<b>Output:</b> "0+-2i"
<b>Explanation:</b> (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
</pre>

**Note:**
- The input strings will not have extra blank.
- The input strings will be given in the form of **a+bi**, where the integer a and b will both belong to the range of [-100, 100]. And **the output should be also in this form**.

## Analysis

This is an easy complex multiplication problem with many details. First you should parse the string to a complex number. Secondly you should compute the multiplication, and finally you need to transform it to a string in the required form. To parse the complex number, we can easily think up that the part before `+` is the real and the part between `+` and `i` is the image. And to transform the complex to string, we only need to call `sprintf`. However, if we first find the position of `+` and `i` and call `atoi` to transform string to integers, we will get extra iterations. Therefore, we can implement the transform function by ourselves.

We assume the max length of complex strings is `n`, then
- Time Complexity: `O(n)`
- Space Complexity: `O(1)`
