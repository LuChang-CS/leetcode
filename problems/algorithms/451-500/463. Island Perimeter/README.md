# [Island Perimeter](https://leetcode.com/problems/island-perimeter/)

## Difficulty

Easy

## Tags

String & Array

## Description

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

**Example 1:**

<pre style="font-family: consolas">
<b>Input:</b>
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
<b>Output:</b> 16

<b>Explanation:</b>
The perimeter is the 16 yellow stripes in the image below:
<image src="../../../../solutions/figs/algo_463_1.png" />
</pre>

## Analysis

Maybe we used to meet such problem in primary schools, counting the edge of joint rectangular. We can see from the figure that each land has four edges. And if two land are joint, they will lose two edges. The land in the edge of matrix can't be joint with outer lands. Therefor, we can iterate from top to bottom and left to right, to count the lands and the joint number.

We assume there are `n` rows and `m` columns, then,
- Time Complexity: `O(mn)`
- Space Complexity: `O(1)`
