# 2360. 图中的最长环 (Longest Cycle in a Graph)

[LeetCode 原题链接](https://leetcode.cn/problems/longest-cycle-in-a-graph/) | 难度: **困难** | 标签: `深度优先搜索`、`广度优先搜索`、`图`、`拓扑排序`

## 题目描述

给你一个 n 个节点的 有向图 , 节点编号为 0 到 n - 1 , 其中每个节点 至多 有一条出边.

图用一个大小为 n 下标从 0 开始的数组 edges 表示, 节点 i 到节点 edges[i] 之间有一条有向边. 如果节点 i 没有出边, 那么 edges[i] == -1.

请你返回图中的 最长 环, 如果没有任何环, 请返回 -1.

一个环指的是起点和终点是 同一个 节点的路径.

示例:

![2360. 图中的最长环 - 示例](https://github.com/imReese/leetcode-solutions/blob/main/problems/2360-longest-cycle-in-a-graph/ex.png)

```plaintext
输入: edges = [3, 3, 4, 2, 3]
输出去: 3
解释: 图中的最长环是: 2 -> 4 -> 3 -> 2.
这个环的长度为 3, 所以返回 3.
```


## 解法思路

### 从每个节点开始进行遍历

- 核心思想:
    1. 使用visited数组记录每个节点是否被处理过, 确保每个节点只被访问一次
    2. 使用pos哈希表记录当前路径中各节点的步数
    3. 在循环结束后, 检查当前节点是否在路径中, 确保正确计算环长
    4. 在遇到edges[cur] = -1时终止循环, 避免数组越界
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        int longestCycle(vector<int>& edges) {
            int n = edges.size();
            vector<bool> visited(n, false);
            int max_len = -1;

            for (int i = 0; i < n; i++) {
                if (visited[i])
                    continue;

                unordered_map<int, int> pos;
                int cur = i;
                int step = 0;

                while (cur != -1 && !visited[cur]) {
                    if (pos.find(cur) != pos.end()) {
                        max_len = max(max_len, step - pos[cur]);
                        break;
                    }
                    pos[cur] = step++;
                    visited[cur] = true;
                    cur = edges[cur];
                }

                if (cur != -1 && pos.count(cur)) {
                    max_len = max(max_len, step - pos[cur]);
                }
            }
            return max_len > 0 ? max_len : -1;
        }
};
```

## 相似题目

- [1591. 奇怪的打印机 II](https://leetcode.cn/problems/strange-printer-ii/)

## Tags

[深度优先搜索](/tags/depth-first-search.md) | [广度优先搜索](/tags/breadth-first-search.md) | [图](/tags/graph.md) | [拓扑排序](/tags/topological-sort.md)