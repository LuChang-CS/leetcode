# [Battleships in a Board](https://leetcode.com/problems/battleships-in-a-board/)

## Difficulty

Easy

## Tags

String & Array

## Description

Given an 2D board, count how many battleships are in it. The battleships are represented with `'X'`s, empty slots are represented with `'.'`s. You may assume the following rules:
- You receive a valid board, made of only battleships or empty slots.
- Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape `1xN` (1 row, N columns) or `Nx1` (N rows, 1 column), where N can be of any size.
- At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

**Example:**
```
X..X
...X
...X
```
In the above board there are 2 battleships.

**Invalid Example:**
```
...X
XXXX
...X
```
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.

**Follow up:**
Could you do it in **one-pass**, using only **O(1) extra memory** and **without modifying** the value of the board?

## Analysis

This is a [Battleship](https://en.wikipedia.org/wiki/Battleship_(game)) problem. I like playing Battleship, and there are some algorithms helping you improve the possibility of hitting the enemy's ships.

We need to detect the count of ships. You may think that we can iterate the board. If we find an `X`, then we can check the vertical and horizontal line to detect a ship. After validate a ship, we can modify the value of board to another value or use an extra board to record our visits. Or you can use two passes to iterate the row and column respectively to detect the ships. However, these method will consume extra resources.

We should notice that the ships can only be placed horizontally or vertically, which means giving a direction and a start or point, i.e. the head and tail of a ship, a ship can be determined. Therefore, the problem transforms to how to detect the head or tail of a ship. In our solution, we use the head to detect the ship. `board[m][n] = X` is the head only if it's previous point is not an `X`, i.e. `border[m - 1][n] != 'X'` and `board[m][n - 1] != X` or it is the first element in a row or column, otherwise it is in the middle of the ship.

We assume the row number is `m` and column number is `n`, then
- Time Complexity: `O(mn)`
- Space Complexity: `O(1)`
