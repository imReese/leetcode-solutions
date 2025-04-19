// Link: https://leetcode.cn/problems/count-of-range-sum/
// Level: Hard
// Date: 2025-04-19

class FenwickTree {
    private:
        vector<int> tree;
        int n;
    public:
        FenwickTree(int size) : n(size), tree(size + 1) {}

        void update(int index, int delta) {
            while (index <= n) {
                tree[index] += delta;
                index += index & -index;
            }
        }

        int query(int index) {
            int res = 0;
            while (index > 0) {
                res += tree[index];
                index -= index & -index;
            }
            return res;
        }
};

class Solution {
    public:
        int countRangeSum(vector<int>& nums, int lower, int upper) {
            long long sum = 0;
            vector<long long> preSum = {0};
            for (int num : nums) {
                sum += num;
                preSum.push_back(sum);
            }

            vector<long long> allNumbers;
            for (long long x : preSum) {
                allNumbers.push_back(x);
                allNumbers.push_back(x - lower);
                allNumbers.push_back(x - upper);
            }
            sort(allNumbers.begin(), allNumbers.end());
            auto last = unique(allNumbers.begin(), allNumbers.end());
            allNumbers.erase(last, allNumbers.end());

            FenwickTree ft(allNumbers.size());
            int res = 0;
            for (long long s_val : preSum) {
                int left_idx = lower_bound(allNumbers.begin(), allNumbers.end(), s_val - upper) - allNumbers.begin() + 1;
                int right_idx = lower_bound(allNumbers.begin(), allNumbers.end(), s_val - lower) - allNumbers.begin() + 1;

                if (right_idx > 0 && left_idx <= right_idx) {
                    res += ft.query(right_idx) - (left_idx > 1 ? ft.query(left_idx - 1) : 0);
                }
                int s_pos = lower_bound(allNumbers.begin(), allNumbers.end(), s_val) - allNumbers.begin() + 1;
                ft.update(s_pos, 1);
            }
            return res;
        }
};
