# [Number of Lines To Write String](https://leetcode.com/problems/number-of-lines-to-write-string/)

## Difficulty

Easy

## Tags

String & Array

## Description

We are to write the letters of a given string `S`, from left to right into lines. Each line has maximum width 100 units, and if writing a letter would cause the width of the line to exceed 100 units, it is written on the next line. We are given an array `widths`, an array where `widths[0]` is the width of `'a'`, `widths[1]` is the width of `'b'`, ..., and `widths[25]` is the width of `'z'`.

Now answer two questions: how many lines have at least one character from S, and what is the width used by the last such line? Return your answer as an integer list of length 2.

<pre style="font-family: consolas">
<b>Example:</b>
<b>Input:</b>
widths = [10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10]
S = "abcdefghijklmnopqrstuvwxyz"
<b>Output:</b> [3, 60]
<b>Explanation:</b> 
All letters have the same length of 10. To write all 26 letters,
we need two full lines and one line with 60 units.
</pre>

<pre style="font-family: consolas">
<b>Example:</b>
<b>Input:</b>
widths = [4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10]
S = "bbbcccdddaaa"
<b>Output:</b> [2, 4]
<b>Explanation:</b> 
All letters except 'a' have the same length of 10, and 
"bbbcccdddaa" will cover 9 * 10 + 2 * 4 = 98 units.
For the last 'a', it is written on the second line because
there is only 2 units left in the first line.
So the answer is 2 lines, plus 4 units in the second line.
</pre>

**Note:**
- The length of `S` will be in the range `[1, 1000]`.
- `S` will only contain lowercase letters.
- `widths` is an array of length `26`.
- `widths[i]` will be in the range of `[2, 10]`.

## Analysis

This is a simple and classic typesetting problem, while the description and explanation may be unclear. Each line has a capacity of max character number, and if writing a new word causes the overflow, we need to break line, which means put the this word to a new line. This problem requires us to count the line number and the line width of the last line. Therefore, we just need to iterate the characters, calculating the current line width, and breaking line if needed.

We assume the length of `S` is `n`, then
- Time Complexity: `O(n)`
- Space Complexity: `O(1)`
