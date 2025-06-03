# 538. 把二叉搜索树转换为累加树 (Convert BST to Greater Tree)

[LeetCode 原题链接](https://leetcode.cn/problems/convert-bst-to-greater-tree/) | 难度: **中等** | 标签: `树`、`深度优先搜索`、`二叉搜索树`、`二叉树`

## 题目描述

给出二叉 **搜索** 树的根节点, 该树的节点值各不相同, 请你将其转换为累加树 (Greater Sum Tree), 使每个节点 `node` 的新值等于原树中大于或等于 `node.val` 的值之和.

提醒一下, 二叉搜索树满足下列约束条件:

- 节点的左子树仅包含键 **小于** 节点键的节点.
- 节点的右子树仅包含键 **大于** 节点键的节点.
- 左右子树也必须是二叉搜索树.

示例:

![538. 把二叉搜索树转换为累加树 - 示例](/problems/0538-convert-bst-to-greater-tree/ex.png)

```plaintext
输入: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
```

## 解法思路

### 反向中序遍历

- 核心思想: 使用反向中序遍历 (右 -> 根 -> 左) 来累加节点值, 这样可以确保每个节点的值都被更新为大于或等于它的所有节点值之和.
- 时间复杂度: O(n)
- 空间复杂度: O(n)

```cpp
class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root != nullptr) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};
```

## Tags

[树](/tags/tree.md) | [深度优先搜索](/tags/depth-first-search.md) | [二叉搜索树](/tags/binary-search-tree.md) | [二叉树](/tags/binary-tree.md)
