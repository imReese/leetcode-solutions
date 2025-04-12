# 2227. 加密解密字符串 (Encrypt and Decrypt Strings)

[LeetCode 原题链接](https://leetcode.cn/problems/encrypt-and-decrypt-strings/) | 难度: **困难** | 标签: `设计`、`字典树`、`数组`、`哈希表`、`字符串`

## 题目描述

给你一个字符数组 `keys`, 由若干 **互不相同** 的字符组成. 还有一个字符串数组 `values`, 内含若干长度为 2 的字符串. 另给你一个字符串数组 `dictionary`, 包含解密后所有允许的原字符串. 请你设计并实现一个支持加密及解密下标从 **0** 开始字符串的数据结构.

字符串 **加密** 按下述步骤进行:

  1. 对字符串中的每个字符 `c`, 先从 `keys` 中找出满足 `keys[i] == c` 的下标 `i`.
  2. 在字符串中, 用 `values[i]` 替换字符 `c`.

请注意, 如果 `keys` 中不存在字符串中的字符, 则无法执行加密过程, 返回空字符串 `""`.

字符串 **解密** 按下述步骤进行:

  1. 将字符串每相邻 2 个字符划分为一个子字符串, 对于每个子字符串 `s`, 找出满足 `values[i] == s` 的一个下标 `i`. 如果存在多个有效的 `i`, 从中选择 **任意** 一个. 这意味着一个字符串解密可能得到多个解密字符串.
  2. 在字符串中, 用 `keys[i]` 替换 `s`.

实现 `Encrypter` 类：

- `Encrypter(char[] keys, String[] values, String[] dictionary)` 用 `keys`、`values` 和 `dictionary` 初始化 `Encrypter` 类.
- `String encrypt(String word1)` 按上述加密过程完成对 `word1` 的加密, 并返回加密后的字符串.
- `int decrypt(String word2)` 统计并返回可以由 `word2` 解密得到且出现在 `dictionary` 中的字符串数目.

示例:

```plaintext
输入:
    ["Encrypter", "encrypt", "decrypt"]
    [[['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], ["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]], ["abcd"], ["eizfeiam"]]
输出:
    [null, "eizfeiam", 2]
    
解释:
    Encrypter encrypter = new Encrypter([['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], ["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]);
    encrypter.encrypt("abcd"); // 返回 "eizfeiam"。 
                               // 'a' 映射为 "ei"，'b' 映射为 "zf"，'c' 映射为 "ei"，'d' 映射为 "am"。
    encrypter.decrypt("eizfeiam"); // return 2. 
                                  // "ei" 可以映射为 'a' 或 'c'，"zf" 映射为 'b'，"am" 映射为 'd'。 
                                  // 因此，解密后可以得到的字符串是 "abad"，"cbad"，"abcd" 和 "cbcd"。 
                                  // 其中 2 个字符串，"abad" 和 "abcd"，在 dictionary 中出现，所以答案是 2 。
```

## 解法思路

### 直接加密+预处理解密

- 核心思想: 初始化即生成key:value的映射关系 并 预处理dictionary中所有单词加密后的结果, 记录在enc_cnt中
  - 加密: 遍历word1, 找到对应的key, 拼接value
  - 解密: 直接返回enc_cnt中对应value的个数
- 时间复杂度:
  - 初始化: O(k + d * l) k为keys数组长度 d为values数组长度 l为dictionary中单词的平均长度
  - encrypt: O(n) n为word长度
  - decrypt: O(n) n为word长度
- 空间复杂度: O(k + d * l) 即哈希表所需要的空间

```cpp
class Encrypter {
    private:
        unordered_map<char, string> enc;
        unordered_map<string, int> dec_cnt;
    public:
        Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
            int n = keys.size();
            for (int i = 0; i < n; ++i) {
                enc[keys[i]] = values[i];
            }
            for (const string& word: dictionary) {
                string result = encrypt(word);
                if (result != "") {
                    ++dec_cnt[result];
                }
            }
        }
        string encrypt(string word1) {
            string result;
            for (char ch : word1) {
                if (enc.count(ch)) {
                    result += enc[ch];
                } else {
                    return "";
                }
            }
            return result;
        }
        int decrypt(string word2) {
            return dec_count.count(word2) ? dec_count[word2] : 0;
        }
};
```

## 相似题目

- [208. 实现 Trie (前缀树)](https://leetcode.cn/problems/implement-trie-prefix-tree/)

## Tags

[数组](/tags/array.md) | [哈希表](/tags/hash-table.md) | [字符串](/tags/string.md)
