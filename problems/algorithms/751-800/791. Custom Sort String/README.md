# [Custom Sort String](https://leetcode.com/problems/custom-sort-string/)

## Difficulty

Medium

## Tags

Hash Table, Sort, String & Array

## Description

`S` and `T` are strings composed of lowercase letters. In `S`, no letter occurs more than once.

`S` was sorted in some custom order previously. We want to permute the characters of `T` so that they match the order that `S` was sorted. More specifically, if `x` occurs before `y` in `S`, then `x` should occur before `y` in the returned string.

Return any permutation of `T` (as a string) that satisfies this property.

**Example:**

<pre style="font-family: consolas">
<b>Input:</b>
S = "cba"
T = "abcd"
<b>Output:</b>
"cbad"
<b>Explanation:</b>
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.
</pre>

**Note:**
- `S` has length at most `26`, and no character is repeated in `S`.
- `T` has length at most `200`.
- `S` and `T` consist of lowercase letters only.

## Analysis

You could easily think up that you can customize the compare function of quick sort according to `S`. However, the time complexity will be `O(nlogn)` assuming the length of `T` is `n`.

We can use a linear method to calculate the count of each letter in `T` and reconstruct `T` according the appearance order of letters in `S`. By the way, we can use another array to store letters which are not appear in `S`.

- Time Complexity: `O(n)` (because the length of `S` will not exceed 26)
- Space Complexity `O(n)`
