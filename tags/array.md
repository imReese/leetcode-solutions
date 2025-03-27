# Array 数组类题目索引

> 标签特性：连续内存、下标操作、双指针、滑动窗口等

| 题号 | 题目名称 | 难度 | 关键解法 | 题解链接 |
|-----|-----|-----|-----|-----|
| 0001 | [Two Sum](https://leetcode.com/problems/two-sum/) | Easy | 哈希表快速查询 | [Python](../problems/0001-Two-Sum/solution.py) |
| 0011 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | Medium | 双指针向内收敛 | [Python](../problems/0011-Container-With-Most-Water/solution.py) |
| 0238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | Medium | 前缀积+后缀积 | [Java](../problems/0238-Product-of-Array-Except-Self/solution.java) |

---

## 经典题型模板

### 双指针

```python
def two_pointers(nums):
    left, right = 0, len(nums)-1
    while left < right:
        # 根据题意处理逻辑
        if condition:
            left += 1
        else:
            right -= 1
    return result
