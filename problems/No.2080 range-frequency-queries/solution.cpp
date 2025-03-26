// Link: https://www.leetcode.cn/problems/range-frequency-queries/
// Level： Medium
// Date: 2025-02-18

class RangeFreqQuery {
    private:
        vector<vector<int>> index;

    public:
        RangeFreqQuery(vector<int>& arr) {
            index.resize(100001);  // 根据题目约束，值的范围是 [1, 10^4]
            for (int i = 0; i < arr.size(); i++) {
                index[arr[i]].push_back(i);
            }
        }
        
        int query(int left, int right, int value) {
            auto& positions = index[value];
            auto l = lower_bound(positions.begin(), positions.end(), left);
            auto r = upper_bound(positions.begin(), positions.end(), right);
            return r - l;
        }
};
    
/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */