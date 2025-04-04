# 1123. 最深叶节点的最近公共祖先 (Lowest Common Ancestor of Deepest Leaves)

[LeetCode 原题链接](https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/) | 难度: **中等** | 标签: `树`、`深度优先搜索`、`广度优先搜索`、`哈希表`、`二叉树`

## 题目描述

给你一个有根节点 `root` 的二叉树, 返回它 _最深的叶节点的最近公共祖先_ .

回想一下

- **叶节点** 是二叉树中没有子节点的节点
- 树的根节点的 **深度** 为 `0`, 如果某一节点的深度为 `d`, 那它的子节点的深度就是 `d+1`
- 如果我们假定 `A` 是一组节点 `S` 的 **最近公共祖先** , `S` 中的每个节点都在以 `A` 为根节点的子树中, 且 `A` 的深度达到此条件下可能的最大值.

示例:

![1123. 最深叶节点的最近公共祖先 - 示例](https://github.com/imReese/leetcode-solutions/blob/main/problems/1123-lowest-common-ancestor-of-deepest-leaves/ex.png)

```plaintext
输入: root = [3,5,1,6,2,0,8,null,null,7,4]
输出: [2,7,4]
解释: 我们返回值为 2 的节点, 在图中用黄色标记.
      在图中用蓝色标记的是树的最深的节点.
      注意, 节点 6、0 和 8 也是叶节点, 但是它们的深度是 2 , 而节点 7 和 4 的深度是 3 .
```

## 解法思路

### 递归

- 核心思想: 用递归的方式, 进行深度优先搜索, 对树中的每个节点进行递归, 返回当前子树的最大深度 d 和 lca 节点
  - 如果当前节点的左右子树深度相同, 则当前节点为 lca 节点, 深度为 d+1
  - 如果当前节点的左右子树深度不同, 则 lca 节点为左右子树中 lca 节点深度更大的那个, 深度为左右子树深度的较大值
  - 如果当前节点为空, 则返回空节点和深度 0
- 时间复杂度: O(n)
- 空间复杂度: O(d)

```cpp
class Solution {
    public:
        pair<TreeNode*, int> f(TreeNode* root) {
            if (!root)
                return {nullptr, 0};
            auto [left, l] = f(root->left);
            auto [right, r] = f(root->right);
            if (l == r)
                return {root, l + 1};
            return l > r ? pair{left, l + 1} : pair{right, r + 1};
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return f(root).first;
        }
};
```

## 相似题目

- [1676. 二叉树的最近公共祖先 IV](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree-iv/)

## Tags

[深度优先搜索](/tags/depth-first-search.md) | [广度优先搜索](/tags/breadth-first-search.md) | [哈希表](/tags/hash-table.md) | [二叉树](/tags/binary-tree.md)
