# 1287. 有序数组中出现次数超过25%的元素 (Element Appearing More Than 25% In Sorted Array)

[LeetCode 原题链接](https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/) | 难度: **简单** | 标签: `数组`

## 题目描述

给你一个非递减的 **有序  **整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。

请你找到并返回这个整数

 

**示例：**
[code] 
    **输入：** arr = [1,2,2,6,6,6,6,7,10]
    **输出：** 6
    
[/code]

 

**提示：**

  * `1 <= arr.length <= 10^4`
  * `0 <= arr[i] <= 10^5`

## 解法思路

```cpp
class Solution {
    public:
        int findSpecialInteger(vector<int>& arr) {
            int len = arr.size();
            int target = arr[0], count = 1;
            for (int i = 1; i < len; ++i) {
                if (arr[i] == target) {
                    ++count;
                    if (count * 4 > len) {
                        return target;
                    }
                } else {
                    target = arr[i];
                    count = 1;
                }
            }
            return target;
        }
};
```
