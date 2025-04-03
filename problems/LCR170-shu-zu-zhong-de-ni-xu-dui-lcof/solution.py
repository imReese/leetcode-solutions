# Link: https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
# Level: Hard
# Date: 2025-04-03

class Solution:
    def mergeSort(self, record: List[int], tmp: List[int], l: int, r: int) -> int:
        if l >= r:
            return 0
        
        mid = (l + r) // 2
        inv_count = self.mergeSort(record, tmp, l, mid) + self.mergeSort(record, tmp, mid + 1, r)
        i = l
        j = mid + 1
        pos = l
        while i <= mid and j <= r:
            if record[i] <= record[j]:
                tmp[pos] = record[i]
                i += 1
                inv_count += (j - (mid + 1))
            else:
                tmp[pos] = record[j]
                j += 1
            pos += 1
        for k in range(i, mid + 1):
            tmp[pos] = record[k]
            inv_count += (j - (mid + 1))
            pos += 1
        for k in range(j, r + 1):
            tmp[pos] = record[k]
            pos += 1
        record[l: r + 1] = tmp[l: r + 1]
        return inv_count

    def reversePairs(self, record: List[int]) -> int:
        n = len(record)
        tmp = [0] * n
        return self.mergeSort(record, tmp, 0, n - 1)