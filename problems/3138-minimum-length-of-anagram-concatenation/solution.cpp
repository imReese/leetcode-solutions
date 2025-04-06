// Link: https://leetcode.cn/problems/minimum-length-of-anagram-concatenation/
// Level: Medium
// Date: 2025-04-06

class Solution {
    public:
        int minAnagramLength(string s) {
            int n = s.size();
            unordered_map<char, int> freq;
            for (char c : s) {
                freq[c]++;
            }
            
            // 收集所有可能的因数，从小到大
            vector<int> factors;
            for (int i = 1; i <= n; ++i) {
                if (n % i == 0) {
                    factors.push_back(i);
                }
            }
            
            for (int k : factors) {
                int m = n / k;
                bool valid = true;
                for (const auto& pair : freq) {
                    if (pair.second % m != 0) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) continue;
                
                string first = s.substr(0, k);
                sort(first.begin(), first.end());
                bool ok = true;
                for (int i = 1; i < m; ++i) {
                    string current = s.substr(i * k, k);
                    sort(current.begin(), current.end());
                    if (current != first) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    return k;
                }
            }
            
            return n;
        }
};