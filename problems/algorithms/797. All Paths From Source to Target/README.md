# [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/)

## Difficulty

Medium

## Tags

Graph

## Description

Given a directed, acyclic graph of `N` nodes.  Find all possible paths from node `0` to node `N - 1`, and return them in any order.

The graph is given as follows:  the nodes are `0, 1, ..., graph.length - 1`.  `graph[i]` is a list of all nodes `j` for which the edge `(i, j)` exists.

**Example 1:** 
<pre style="font-family: consolas">
<b>Input:</b> [[1, 2], [3], [3], []]
<b>Output:</b> [[0, 1, 3], [0, 2, 3]]

<b>Explanation:</b> The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
</pre>

**Note**
- The number of nodes in the graph will be in the range `[2, 15]`.
- You can print different paths in any order, but you should keep the order of nodes inside one path.

## Analysis

This is a classic DFS or BFS algorithm. We can easily use recursive method to generate paths.

Let me explain the example first. We first assume that the node number in the graph is `n`, and the node is `0, 1, ..., n - 1`. The input is `[[1, 2], [3], [3], []]`, which means node `0` is connected to `1` and `2` and so forth. In a recursive manner, we first fetch `1` and find `1` is connected to `3`, then these two nodes forms a path. And we next fetch `2`, and find `2` is also connected to `3`, hence, there are two paths. In this manner, we call is Depth-First-Search (DFS), and DFS can be intuitively implemented in a recursive manner.

As for Breadth-First-Search (BFS), BFS is more appropriate to be implemented in a loop manner with a queue. It fetch all nodes in a layer to this queue, dequeue each node, and put successive nodes in queue. In this example, we first fetch `1` and `2`. Then we fetch `3` and `3` as successive nodes of `1` and `2`. Finally we also find there are two paths.

In our solution, we use DFS in a non-recursive manner, just to try more method. We use stack to replace recursion. Similar to BFS, It first fetch all nodes in a layer to the stack, pop from stack and push its successive nodes.

- Time Complexity: worst case of `O(n * n)`, when the graph is a complete graph, because node `i` have `n - i` successive nodes.
- Space Complexity: worst case of `O(n * n)`, also when it is a complete graph.
