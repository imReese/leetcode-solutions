// Link: https://leetcode-cn.com/problems/remove-digit-from-number-to-maximize-result/
// Level: Easy
// Date: 2025-02-18

class Solution {
    public:
        string removeDigit(string number, char digit) {
            string result = "";
            int n = number.length();
            
            for (int i = 0; i < n; i++) {
                if (number[i] == digit) {
                    string candidate = number.substr(0, i) + number.substr(i + 1);
                    if (candidate > result) {
                        result = candidate;
                    }
                }
            }
            
            return result;
        }
};

class Solution {
    public:
        string removeDigit(string number, char digit) {
            int n = number.length();
            int lastIndex = -1;
            
            for (int i = 0; i < n - 1; i++) {
                if (number[i] == digit) {
                    if (number[i] < number[i + 1]) {
                        // 如果当前数字小于下一个数字，直接移除当前数字
                        return number.substr(0, i) + number.substr(i + 1);
                    }
                    lastIndex = i;
                }
            }
            
            // 如果最后一个字符是目标数字，或者没有找到更好的位置
            if (number[n - 1] == digit || lastIndex == -1) {
                return number.substr(0, n - 1);
            }
            
            // 移除最后找到的目标数字
            return number.substr(0, lastIndex) + number.substr(lastIndex + 1);
        }
};
