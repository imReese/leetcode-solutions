# 1840. 最高建筑高度 (Maximum Building Height)

[LeetCode 原题链接](https://leetcode.cn/problems/maximum-building-height/) | 难度: **困难** | 标签: `数组`、`数学`、`排序`

## 题目描述

在一座城市里, 你需要建 `n` 栋新的建筑. 这些新的建筑会从 `1` 到 `n` 编号排成一列.

这座城市对这些新建筑有一些规定:

- 每栋建筑的高度必须是一个非负整数.
- 第一栋建筑的高度 必须 是 `0`.
- 任意两栋相邻建筑的高度差 不能超过 `1`.

除此以外, 某些建筑还有额外的最高高度限制. 这些限制会以二维整数数组 `restrictions` 的形式给出, 其中 `restrictions[i] = [idi, maxHeighti]`, 表示建筑 `idi` 的高度 不能超过 `maxHeighti`.

题目保证每栋建筑在 `restrictions` 中 至多出现一次, 同时建筑 `1` 不会 出现在 `restrictions` 中.

请你返回 最高 建筑能达到的 最高高度.

示例:

![1840. 最高建筑高度 - 示例](https://github.com/imReese/leetcode-solutions/blob/main/problems/1840-maximum-building-height/ex.png)

```plaintext
输入: n = 5, restrictions = [[2,1],[4,1]]
输出：2
解释: 上图中的绿色区域为每栋建筑被允许的最高高度.
    我们可以使建筑高度分别为 [0,1,2,1,2], 最高建筑的高度为 2.
```

## 解法思路

### 左右遍历更新限制

- 核心思想: 先将限制排序, 然后从左往右遍历, 从右往左遍历, 取左右遍历的最小值, 再取左右遍历的最大值, 就是当前建筑的最高限制.
- 时间复杂度: O(mlogm) m为restrictions长度
- 空间复杂度: O(m)

```cpp
class Solution {
    public:
        int maxBuilding(int n, vector<vector<int>>& restrictions) {
            int res = 0;
            auto&& r = restrictions;
            r.push_back({1, 0});
            sort(r.begin(), r.end());
            if (r.back()[0] != n) {
                r.push_back({n, n - 1});
            }
            int m = r.size();
            for (int i = 1; i < m; i++) {
                r[i][1] = min(r[i][1], r[i - 1][1] + (r[i][0] - r[i - 1][0]));
            }
            for (int j = m - 2; j >= 0; j--) {
                r[j][1] = min(r[j][1], r[j + 1][1] + (r[j + 1][0] - r[j][0]));
            }
            for (int i = 0; i < m - 1; i++) {
                int best = ((r[i + 1][0] - r[i][0]) + r[i][1] + r[i + 1][1]) / 2;
                res = max(res, best);
            }
            return res;
        }
};
```

## Tags

[数组](/tags/array.md) | [数学](/tags/math.md) | [排序](/tags/sorting.md)
