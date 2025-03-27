# 15. 三数之和 (3Sum)

[LeetCode 原题链接](https://leetcode.cn/problems/3sum/) | 难度: **中等** | 标签: `数组`、`双指针`、`排序`

## 题目描述

给你一个整数数组 nums , 判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k , 同时还满足 nums[i] + nums[j] + nums[k] == 0 . 请你返回所有和为 0 且不重复的三元组.

示例:

```plaintext
输入: nums = [-1, 0, 1, 2, -1, -4]
输出: [[-1, -1, 2], [-1, 0, 1]]
解释: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
不同的三元组是 [-1, 0, 1] 和 [-1, -1, 2].
注意, 输出的顺序和三元组的顺序并不重要.
```

## 解法思路

### 排序 + 双指针法

- 核心思想:
    1. 排序数组: 预处理使相同元素相邻，便于去重
    2. 固定一个数: 遍历数组，将当前元素作为第一个数
    3. 双指针搜索: 在剩余区间使用左右指针寻找满足条件的组合
    4. 去重优化: 跳过重复元素避免重复解
- 时间复杂度: O(n²)
    排序 O(nlogn) + 双层遍历 O(n²)
- 空间复杂度: O(1) (忽略排序栈空间)

```cpp
// solution.cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        if (nums.size() < 3) return triplets;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n-2; ++i) {
            // 去重: 跳过相同基准值
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            // 提前终止条件
            if (nums[i] + nums[i+1] + nums[i+2] > 0) break;
            if (nums[i] + nums[n-2] + nums[n-1] < 0) continue;
            
            int left = i+1, right = n-1;
            while (left < right) {
                long sum = (long)nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    // 跳过左侧重复
                    while (left < right && nums[left] == nums[left+1]) ++left;
                    // 跳过右侧重复
                    while (left < right && nums[right] == nums[right-1]) --right;
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return triplets;
    }
};
```

### 关键点

1. 排序预处理: 排序后可以利用有序特性进行高效搜索和去重
2. 三重去重机制:
    外层循环跳过相同基准值 (i > 0 && nums[i] == nums[i-1])
    找到解后跳过左侧重复值 (nums[left] == nums[left+1])
    找到解后跳过右侧重复值 (nums[right] == nums[right-1])
3. 提前终止优化:
    当最小三数之和 > 0 时终止 (nums[i]+nums[i+1]+nums[i+2] > 0)
    当最大三数之和 < 0 时跳过 (nums[i]+nums[n-2]+nums[n-1] < 0)

#### 边界案例

- 输入数组长度小于3: 直接返回空
- 全零数组: [[0, 0, 0]]
- 无解数组: 如 [1, 2, -1] → 返回空

## 相似题目

- [16. 最接近的三数之和](https://leetcode.cn/problems/3sum-closest/)

## Tags

[数组](/tags/array.md) | [双指针](/tags/two-pointers.md) | [排序](/tags/sorting.md)
