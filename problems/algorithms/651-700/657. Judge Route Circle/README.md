# [Judge Route Circle](https://leetcode.com/problems/judge-route-circle/)

## Difficulty

Easy

## Tags

Entertainment

## Description

Initially, there is a Robot at position `(0, 0)`. Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are `R` (Right), `L` (Left), `U` (Up) and `D` (down). The output should be true or false representing whether the robot makes a circle.

**Example 1:**
<pre style="font-family: consolas">
<b>Input:</b> "UD"
<b>Output:</b> true
</pre>

**Example 2:**
<pre style="font-family: consolas">
<b>Input:</b> "LL"
<b>Output:</b> false
</pre>

## Analysis

I don't know how to classify this problem, so I just tag it as an entertainment.

Obviously, each point has a coordinate `(x, y)`. `R` means `x + 1`, `L` means `x - 1`, `U` means `y + 1` and `D` means `y - 1`. Therefore, the robot's moving back to the original place means the coordinate is still `(0, 0)` after all moves, assuming original coordinate is `(0, 0)`.

Assuming that the length of moves is `n`, then
- Time Complexity: `O(n)`
- Space Complexity: `O(1)`
