// Link: https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
// Level: Hard
// Date: 2025-04-03

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