# 301. 删除无效的括号 (Remove Invalid Parentheses)

[LeetCode 原题链接](https://leetcode.cn/problems/remove-invalid-parentheses/) | 难度: **困难** | 标签: `广度优先搜索`、`字符串`、`回溯`

## 题目描述

给你一个由若干括号和字母组成的字符串 `s`, 删除最小数量的无效括号, 使得输入的字符串有效.

返回所有可能的结果. 答案可以按 **任意顺序** 返回.

示例:

```plaintext
输入: s = "()())()"
输出：["(())()","()()()"]
```

## 解法思路

### 队列+广度优先搜索

- 核心思想: 使用队列从输入字符串开始判断是否有效, 如果有效视为已找到 如果无效则删除一个括号判断删除后的字符串是否有效
- 时间复杂度: O(n * 2^n)
- 空间复杂度: O(n * 2^n)

```cpp
class Solution {
private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                if (count == 0) {
                    return false;
                }
                count--;
            }
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q;
        unordered_set<string> visited;
        q.push(s);
        visited.insert(s);
        bool found = false;
        while (!q.empty()) {
            int levelSize = q.size();
            unordered_set<string> currentLevel;
            for (int i = 0; i < levelSize; i++) {
                string current = q.front();
                q.pop();
                if (isValid(current)) {
                    res.push_back(current);
                    found = true;
                }
                if (!found) {
                    for (int j = 0; j < current.size(); j++) {
                        if (current[j] != '(' && current[j] != ')') {
                            continue;
                        }
                        string newStr = current.substr(0, j) + current.substr(j + 1);
                        if (visited.find(newStr) == visited.end()) {
                            currentLevel.insert(newStr);
                            visited.insert(newStr);
                        }
                    }
                }
            }
            if (found) {
                break;
            }
            for (const string& str : currentLevel) {
                q.push(str);
            }
        }
        return res;
    }
};
```

## 相似题目

- [20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/)

## Tags

[广度优先搜索](/tags/breadth-first-search.md) | [字符串](/tags/string.md) | [回溯](/tags/backtracking.md)
