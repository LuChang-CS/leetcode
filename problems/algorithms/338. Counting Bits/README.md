# [Counting Bits](https://leetcode.com/problems/counting-bits/)

## Difficulty

Medium

## Tags

Bitwise Operation

## Description

Given a non negative integer number **num**. For every numbers **i** in the range **0 ≤ i ≤ num** calculate the number of 1's in their binary representation and return them as an array.

**Example:**
For `num = 5` you should return `[0, 1, 1, 2, 1, 2]`.

**Follow up:**
- It is very easy to come up with a solution with run time **O(n*sizeof(integer))**. But can you do it in linear time **O(n)** /possibly in a single pass?
- Space complexity should be `O(n)`.
- Can you do it like a boss? Do it without using any builtin function like `__builtin_popcount` in c++ or in any other language.

**Credits:**
Special thanks to [@syedee](https://leetcode.com/discuss/user/syedee) for adding this problem and creating all test cases.

## Analysis

For a single number, if we want to count the number of bit 1, we have to fetch each bit. But as the description said, we can design an algorithm that requires a linear time, which means the previous result is required. Take `13 = 1101` and `14 = 1110` as examples, `1101` can be seen as `110` concatenated with `1`, and `1110` is `111` concatenated with `0`. You may have noticed that a number is composed of its previous `n - 1` bits and the last one bit, assuming the length of the binary number is `n`. And the previous `n - 1` bits are exactly this number's right shift by one bit, while the last bit can be calculated by `and` operation with `1`. Therefore, the count can be calculated by the count of right shift and the last bit.
