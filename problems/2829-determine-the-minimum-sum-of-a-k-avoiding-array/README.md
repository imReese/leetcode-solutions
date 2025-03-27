# 2829. k-avoiding 数组的最小总和 (Determine the Minimum Sum of a K-avoiding Array)

[LeetCode 原题链接](https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/) | 难度: **中等** | 标签: `贪心`、`数学`

## 题目描述

给你两个整数 n 和 k.

对于一个由 不同 正整数组成的数组, 如果其中不存在任何求和等于 k 的不同元素对, 则称其为 k-avoiding 数组.

返回长度为 n 的 k-avoiding 数组的可能的最小总和.

示例:

```plaintext
输入: n = 5, k = 4
输出: 18
解释: 设若 k-avoiding 数组为 [1, 2, 4, 5, 6], 其元素总和为 18.
可以证明不存在总和小于 18 的 k-avoiding 数组.
```

## 解法思路

### 方法一: 贪心 + 哈希表

- 核心思想: 从小到大依次选择数值最小的元素, 并通过哈希表避免选中与已有元素相加等于 `k` 的值.
- 时间复杂度: 平均O(n), 最坏O(k)
- 空间复杂度: O(n)

``` c++
// solution.cpp
class Solution {
    public:
        int minimumSum(int n, int k) {
            int res = 0;
            unordered_set<int> nums;
            int num = 1;
            while (nums.size() < n) {
                if (nums.find(k - num) == nums.end()) {
                    nums.insert(num);
                    res += num;
                }
                num++;
            }
            return res;
        }
};
```

### 方法二: 贪心 + 等差数列求和

- 核心思想: 从1开始挑选数字放入数组, 直到⌈k / 2​⌉, 从k开始, 再挑选连续的k − ⌈k / 2​⌉个数字加入数组
- 时间复杂度: O(1)
- 空间复杂度: O(1)

``` c++
// solution.cpp
class Solution {
    public:
        int minimumSum(int n, int k) {
            if (n <= k / 2) {
                return arithmeticSeriesSum(1, 1, n);
            } else {
                return arithmeticSeriesSum(1, 1, k / 2) + arithmeticSeriesSum(k, 1, n - k / 2);
            }
        }

    private:
        int arithmeticSeriesSum(int a1, int d, int n) {
            return (a1 + a1 + (n - 1) * d) * n / 2;
        }
};
```

### 复杂度对比

| 方法 | 时间复杂度 | 空间复杂度 |
| ----- | ----- | ----- | ----- |
| 贪心+哈希表 | O(n) | O(n) |
| 贪心+等差数列求和 | O(1) | O(1) |
