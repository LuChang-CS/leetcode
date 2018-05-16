# [Hamming Distance](https://leetcode.com/problems/hamming-distance/)

## Difficulty

Easy

## Tags

Bitwise Operation

## Description

The [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance) between two integers is the number of positions at which the corresponding bits are different.

Given two integers `x` and `y`, calculate the Hamming distance.

**Note**

0 ≤ `x`, `y` < 2<sup>31</sup>.

**Example 1:**
<pre style="font-family: consolas">
<b>Input:</b> x = 1, y = 4
<b>Output:</b>2

<b>Explanation:</b>
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
</pre>

## Analysis

This is an easy problem about Hamming distance and bitwise operation. We can see from the example above that the Hamming distance is the sum of different bits. Therefore, we may easily associate with `xor` operation that detect different bits.
```
1 xor 4 = 0001 xor 0100 = 0101 = 5
```
Then we can just count the bit of value `1` in `5`, i.e. `x xor y`. To perform this operation, we can fetch the last bit of 5 by `and` with `1`, and following shift operation.

