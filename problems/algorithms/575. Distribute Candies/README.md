# [Distribute Candies](https://leetcode.com/problems/distribute-candies/)

## Difficulty

Easy

## Tags

Hash Table, String & Array

## Description

Given an integer array with **even** length, where different numbers in this array represent different **kinds** of candies. Each number means one candy of the corresponding kind. You need to distribute these candies **equally** in number to brother and sister. Return the maximum number of **kinds** of candies the sister could gain.

**Example 1:**

<pre style="font-family: consolas">
<b>Input:</b> candies = [1,1,2,2,3,3]
<b>Output:</b> 3
<b>Explanation:</b>
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too.
The sister has three different kinds of candies.
</pre>

<pre style="font-family: consolas">
<b>Input:</b> candies = [1,1,2,3]
<b>Output:</b> 2
<b>Explanation:</b>
For example, the sister has candies [2,3] and the brother has candies [1,1].
The sister has two different kinds of candies, the brother has only one kind of candies.
</pre>

**Note:**
1. The length of the given array is in range [2, 10,000], and will be even.
2. The number in given array is in range [-100,000, 100,000].

## Analysis

Obviously, we only need to count the number of all categories, assuming it is `N`. If `N` is larger than the max number of candies the sister can get, the max categories are the cases where one candy corresponds to one category, otherwise the max category number is the total category number, i.e. all categories are given to the sister.

Assuming the number of candies is `n`, then
- Time Complexity: `O(n)`
- Space Complexity: `O(n)`
