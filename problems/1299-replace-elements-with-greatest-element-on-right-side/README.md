# 1299. 将每个元素替换为右侧最大元素 (Replace Elements with Greatest Element on Right Side)

[LeetCode 原题链接](https://leetcode.cn/problems/replace-elements-with-greatest-element-on-right-side/) | 难度: **简单** | 标签: `数组`

## 题目描述

给你一个数组 `arr` ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 `-1` 替换。

完成所有替换操作后，请你返回这个数组。

**示例 1：**
[code] 
    **输入：** arr = [17,18,5,4,6,1]
    **输出：**[18,6,6,6,1,-1]
    **解释：**
    - 下标 0 的元素 --> 右侧最大元素是下标 1 的元素 (18)
    - 下标 1 的元素 --> 右侧最大元素是下标 4 的元素 (6)
    - 下标 2 的元素 --> 右侧最大元素是下标 4 的元素 (6)
    - 下标 3 的元素 --> 右侧最大元素是下标 4 的元素 (6)
    - 下标 4 的元素 --> 右侧最大元素是下标 5 的元素 (1)
    - 下标 5 的元素 --> 右侧没有其他元素，替换为 -1
    
[/code]

**示例 2：**
[code] 
    **输入：** arr = [400]
    **输出：**[-1]
    **解释：** 下标**** 0 的元素右侧没有其他元素。
    
[/code]

**提示：**

  * `1 <= arr.length <= 104`
  * `1 <= arr[i] <= 105`

## 解法思路

```cpp
class Solution {
    public:
        vector<int> replaceElements(vector<int>& arr) {
            int n = arr.size();
            vector<int> ans(n);
            ans[n - 1] = -1;
            for (int i = n - 2; i >= 0; i--) {
                ans[i] = max(ans[i + 1], arr[i + 1]);
            }
            return ans;
        }
};
```
