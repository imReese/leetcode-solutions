# 18. 四数之和 (4Sum)

[LeetCode 原题链接](https://leetcode.cn/problems/4sum/) | 难度: **中等** | 标签: `数组`、`双指针`、`排序`

## 题目描述

给定一个包含 `n` 个整数的数组 `nums` 和一个目标值 `target`, 判断 `nums` 中是否存在四个元素 `a`, `b`, `c` 和 `d`, 使得 `a + b + c + d = target`? 找出所有满足条件且**不重复**的四元组.

示例:

```plaintext
输入: nums = [1, 0, -1, 0, -2, 2], target = 0
输出: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
```

## 解法思路

### 排序 + 多指针法

- 核心思想:
  1. 数组排序: 预处理使相同元素相邻，便于去重
  2. 双层循环: 外层固定前两个数 (`i` 和 `j`)
  3. 双指针搜索: 内层使用左右指针寻找后两个数 (`left` 和 `right`)
  4. 去重优化: 通过跳过重复值避免重复解

- 时间复杂度: O(n³)
    排序 O(nlogn) + 三层遍历 O(n³)
- 空间复杂度: O(1) (忽略排序栈空间)

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        if (nums.size() < 4) return quadruplets;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n-3; ++i) {
            // 外层去重
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            // 提前终止条件
            if ((long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if ((long)nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;
            
            for (int j = i+1; j < n-2; ++j) {
                // 中层去重
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                
                // 中层提前终止
                if ((long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if ((long)nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;
                
                int left = j+1, right = n-1;
                while (left < right) {
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // 跳过重复值
                        while (left < right && nums[left] == nums[left+1]) ++left;
                        while (left < right && nums[right] == nums[right-1]) --right;
                        ++left;
                        --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return quadruplets;
    }
};
```

### 关键点

1. 四重去重机制:
   - 外层循环去重 (`nums[i] == nums[i-1]`)
   - 中层循环去重 (`nums[j] == nums[j-1]`)
   - 内层双指针去重 (`nums[left] == nums[left+1]` 和 `nums[right] == nums[right-1]`)

2. 提前终止优化:

   ```cpp
   // 最小四数之和 > target 时终止
   if ((long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
   
   // 最大四数之和 < target 时跳过
   if ((long)nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;
   ```

3. 大数溢出处理:

   ```cpp
   long sum = (long)nums[i] + nums[j] + nums[left] + nums[right]; // 防止int溢出
   ```

### 边界案例

- 输入数组长度小于4: 直接返回空
- 目标值极大/极小: 通过提前终止条件优化
- 全零数组: `target=0` 时返回 `[[0,0,0,0]]`

## 相似题目

- [454. 四数相加 II](https://leetcode.cn/problems/4sum-ii/)

## Tags

[数组](/tags/array.md) | [双指针](/tags/two-pointers.md) | [排序](/tags/sorting.md)
