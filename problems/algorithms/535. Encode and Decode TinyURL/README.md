# [Encode and Decode TinyURL](https://leetcode.com/problems/encode-and-decode-tinyurl/)

# Difficulty

Medium

# Description

TinyURL is a URL shortening service where you enter a URL such as `https://leetcode.com/problems/design-tinyurl` and it returns a short URL such as `http://tinyurl.com/4e9iAk`.

Design the `encode` and `decode` methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

# Analysis

This is an open problem where numerous solutions can be applied. We can even keep the original url as encode and decode, although it is meaningless.

We should to pay attention to these limitations:
- Correctness: We must make sure that the decoded url is the same as the original url.
- Uniqueness: Each url must have an unique encoded url, and an encoded url must be decoded to a single url.
- Simplicity: The aim to encode a url is to make it easy to share or write, so we need to make the encoded url as simple as possible.

We can use current popular encode/decode algorithms such as `AES`, `DES`, but in this problem, we just design a simpler algorithm to encode and decode a url.

We use a hash table to maintain the map between the original url and encoded url. And we use the hex notation of current size of this hash table to be the encodede url, therefore,
```
function encode(url)
    return hex(current size of hash table)
end

function decode(encoded_url)
    return hash table.find(encoded_url)
end
```
