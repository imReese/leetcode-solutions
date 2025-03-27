// Link: https://leetcode-cn.com/problems/distinct-prime-factors-of-product-of-array/
// Level: Medium
// Date: 2025-02-17

class Solution {
    public:
        int distinctPrimeFactors(vector<int>& nums) {
            unordered_set<int> primeFactors;
            for (int num : nums) {
                for (int i = 2; i * i <= num; ++i) {
                    if (num % i == 0) {
                        primeFactors.insert(i);
                        while (num % i == 0) {
                            num /= i;
                        }
                    }
                }
                if (num > 1) {
                    primeFactors.insert(num);
                }
            }
            return primeFactors.size();
        }
};