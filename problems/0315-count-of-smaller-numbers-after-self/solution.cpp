// Link: https://leetcode.cn/problems/count-of-smaller-numbers-after-self/
// Level: Hard
// Date: 2025-04-15

class Solution {
    private:
        vector<int> c; // Fenwick Tree
        vector<int> a; // Discretization

        void Init(int length) {
            c.resize(length, 0);
        }

        int LowBit(int x) {
            return x & (-x);
        }
        
        void Update(int pos) {
            while (pos < c.size()) {
                c[pos]++;
                pos += LowBit(pos);
            }
        }
        
        int Query(int pos) {
            int ret = 0;
            while (pos > 0) {
                ret += c[pos];
                pos -= LowBit(pos);
            }
            return ret;
        }
        
        void Discretization(vector<int>& nums) {
            a.assign(nums.begin(), nums.end()); // 复制nums到a
            sort(a.begin(), a.end()); // 升序排序
            a.erase(unique(a.begin(), a.end()), a.end()); // 去重
        }
        
        int GetId(int x) {
            return lower_bound(a.begin(), a.end(), x) - a.begin() + 1; // 获取离散化后的索引
        }

        public:
        vector<int> countSmaller(vector<int>& nums) {
            vector<int> resultList;
            int n = nums.size();
            Discretization(nums);
            Init(n);

            for (int i = n - 1; i >= 0; i--) {
                int id = GetId(nums[i]);
                resultList.push_back(Query(id - 1));
                Update(id);
            }

            reverse(resultList.begin(), resultList.end());
            return resultList;
        }
};
