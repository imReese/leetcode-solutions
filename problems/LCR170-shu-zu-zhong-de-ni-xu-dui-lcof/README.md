# LCR 170. 交易逆序对的总数 (交易逆序对的总数)

[LeetCode 原题链接](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/) | 难度: **困难** | 标签: `树状数组`、`线段树`、`数组`、`二分查找`、`分治`、`有序集合`、`归并排序`

## 题目描述

在股票交易中, 如果前一天的股价高于后一天的股价, 则可以认为存在一个「交易逆序对」. 请设计一个程序, 输入一段时间内的股票交易记录 `record`, 返回其中存在的「交易逆序对」总数.

示例:

```plaintext
输入: record = [9, 7, 5, 4, 6]
输出: 8
解释: 交易中的逆序对为 (9, 7), (9, 5), (9, 4), (9, 6), (7, 5), (7, 4), (7, 6), (5, 4). 
```

## 解法思路

### 归并排序

- 核心思想:

  - 对于已经有序的两个序列, 逆序对存在与当L[lPtr] > R[rPtr]时, 此时序列R中rPtr之前的数均小于L[lPtr]

    ```plaintext
        L = [8, 12, 16, 22, 100]   R = [9, 26, 55, 64, 91]  M = []
                |                       |
                lPtr                    rPtr
    ```

- 时间复杂度: O(nlogn)
- 空间复杂度: O(n)

```cpp
class Solution {
    public:
        int mergeSort(vector<int>& record, vector<int>& tmp, int l, int r) {
            if (l >= r) {
                return 0;
            }
            int mid = (l + r) / 2;
            int inv_count = mergeSort(record, tmp, l, mid) + mergeSort(record, tmp, mid + 1, r);
            int i = l, j = mid + 1, pos = l;
            while (i <= mid && j <= r) {
                if (record[i] <= record[j]) {
                    tmp[pos] = record[i];
                    i++;
                    inv_count += (j - (mid + 1));
                } else {
                    tmp[pos] = record[j];
                    j++;
                }
                pos++;
            }
            for (int k = i; k <= mid; k++) {
                tmp[pos++] = record[k];
                inv_count += (j - (mid + 1));
            }
            for (int k = j; k <= r; k++) {
                tmp[pos++] = record[k];
            }
            copy(tmp.begin() + l, tmp.begin() + r + 1, record.begin() + l);
            return inv_count;
        }
        int reversePairs(vector<int>& record) {
            int n = record.size();
            vector<int> tmp(n);
            return mergeSort(record, tmp, 0, n - 1);
        }
};
```

## Tags

[数组](/tags/array.md) | [二分查找](/tags/binary-search.md)
