# 825. 适龄的朋友 (Friends Of Appropriate Ages)

[LeetCode 原题链接](https://leetcode.cn/problems/friends-of-appropriate-ages/) | 难度: **中等** | 标签: `数组`、`双指针`、`二分查找`、`排序`

## 题目描述

在社交媒体网站上有 `n` 个用户. 给你一个整数数组 `ages`, 其中 `ages[i]` 是第 `i` 个用户的年龄.

如果下述任意一个条件为真, 那么用户 `x` 将不会向用户 `y`（`x != y`）发送好友请求:

- `ages[y] <= 0.5 * ages[x] + 7`
- `ages[y] > ages[x]`
- `ages[y] > 100 && ages[x] < 100`

否则, `x` 将会向 `y` 发送一条好友请求.

注意, 如果 `x` 向 `y` 发送一条好友请求, `y` 不必也向 `x` 发送一条好友请求. 另外, 用户不会向自己发送好友请求.

返回在该社交媒体网站上产生的好友请求总数.

示例:

```plaintext
输入: ages = [16,16]
输出: 2
解释: 2 人互发好友请求。
```

## 解法思路

### 排序+双指针

- 核心思想: 当ages[x]<=14时不存在符合条件的ages[y], 可以跳过. 排序后, 用双指针维护一个区间, 这个区间内的所有数都满足条件, 然后把这个区间内的数都加起来即可.
- 时间复杂度: O(nlogn)
- 空间复杂度: O(1)

```cpp
class Solution {
    public:
        int numFriendRequests(vector<int>& ages) {
            int n = ages.size();
            sort(ages.begin(), ages.end());
            int left = 0, right = 0, ans = 0;
            for (int age : ages) {
                if (age < 15) {
                    continue;
                }
                while (ages[left] <= 0.5 * age + 7) {
                    ++left;
                }
                while (right + 1 < n && ages[right + 1] <= age) {
                    ++right;
                }
                ans += right - left;
            }
            return ans;
        }
};
```

## Tags

[数组](/tags/array.md) | [双指针](/tags/two-pointers.md) | [二分查找](/tags/binary-search.md) | [排序](/tags/sorting.md)
