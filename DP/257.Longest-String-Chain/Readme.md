#### Description
给出一个单词列表，其中每个单词都由小写英文字母组成。

如果我们可以在 word1 的任何地方添加一个字母使其变成 word2，那么我们认为 word1 是 word2 的前身。例如，"abc" 是 "abac" 的前身。
词链是单词 [word_1, word_2, ..., word_k] 组成的序列，k >= 1，其中 word_1 是 word_2 的前身，word_2 是 word_3 的前身，依此类推。
从给定单词列表 words 中选择单词组成词链，返回词链的最长可能长度。

#### 分析：

LeetCode 1048. Longest String Chain

很明显的“传递”的线索：word_1是word_2的前身，那么word_2的词链长度就是word_1的词链长度+1 , 即 dp[word_2] = dp[word_1] + 1 if word_1 + ?  = word_2

为了构造DP要求的“无后效性”，我们将所有单词按照长度排序。这样，单词j的前身一定是在i<j的范围中。
```cpp
for i = 0 : n
    for j = 0 : i
        if words[j] 是 words[i] 的前身
            dp[i] = max(dp[i], dp[j] + 1)
```
小改进：只查看words[j].size() == words[i].size()-1 的那部分单词     

time complexity: o(N^2)
