# [Subdomain Visit Count](https://leetcode.com/problems/subdomain-visit-count/)

## Difficulty

Easy

## Tags

Hash Table

## Analysis

A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.

Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".

We are given a list `cpdomains` of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.

<pre style="font-family: consolas">
<b>Example:</b>
<b>Input:</b>
["9001 discuss.leetcode.com"]
<b>Output:</b>
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
<b>Explanation:</b> 
We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.
</pre>

<pre style="font-family: consolas">
<b>Example:</b>
<b>Input:</b>
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
<b>Output:</b>
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
<b>Explanation:</b> 
We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.
</pre>

**Notes:**
- The length of `cpdomains` will not exceed `100`.
- The length of each domain name will not exceed `100`.
- Each address will have either 1 or 2 "." characters.
- The input count in any count-paired domain will not exceed `10000`.
- The answer output can be returned in any order.

## Analysis

This is an another Hash Table problem. With in a domain, we need to extract each level of it. First of all, we need to iterate the cpdomain to find space, and chars before space is the count. And then we will find each dot to separate each level. And finally, we use a hash table to store and count.

Assuming the length of `cpdomains` is `m`, and the max length of each domain is `n`, then we have
- Time Complexity: `O(mn)`
- Space Complexity: `O(m)`
