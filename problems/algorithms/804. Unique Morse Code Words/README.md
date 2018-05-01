# Unique Morse Code Words

## Difficulty

Easy

# Description

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: `"a"` maps to `".-"`, `"b"` maps to `"-..."`, `"c"` maps to `"-.-."`, and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

```js
[".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."]
```

Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, `"cab"` can be written as `"-.-.-....-"`, (which is the concatenation `"-.-."` + `"-..."` + `".-"`). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

<pre style="font-family: consolas">
<b>Example:</b>
<b>Input:</b> words = ["gin", "zen", "gig", "msg"]
<b>Output:</b> 2
<b>Explanation:</b> 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
</pre>

Note:

- The length of `words` will be at most `100`.
- Each `words[i]` will have length in range `[1, 12]`.
- `words[i]` will only consist of lowercase letters.

## Analysis

This problem is the conbination of Morse Code and a hash store. In this problem, we need to check repitition count of the Morse Code for each word in `words`. Therefore we can simply use a hash set to store appeared Morse Codes and check the exsistence of next.

We assume the size of `words` is `m`, and we have already knowed that each `words[i]` will have length in range `[1, 12]`, we assume the max length of a word is n, then

- Time complexity: `O(mn)` (We need to iterate all `m` word in `words` and calculate the hash of this word, while checking the existence is `O(1)`)
- Space complexity: `O(m)` (We assume that each hash is stores as Integer)
