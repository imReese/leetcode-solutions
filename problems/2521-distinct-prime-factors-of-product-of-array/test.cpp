#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;

// 目标函数
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

// 表驱动风格的单元测试
void testDistinctPrimeFactors() {
    struct TestCase {
        vector<int> input; // 输入数据
        int expected;      // 期望结果
    };

    // 测试用例表
    vector<TestCase> testCases = {
        {{2, 3, 5}, 3},                  // 每个数字都是不同的质数
        {{4, 6, 8}, 2},                  // 4=2^2, 6=2*3, 8=2^3，质因数为2和3
        {{15, 25, 35}, 3},               // 15=3*5, 25=5^2, 35=5*7，质因数为3, 5, 7
        {{1, 1, 1}, 0},                  // 没有质因数
        {{2, 4, 8, 16}, 1},              // 所有数字只有质因数2
        {{7, 11, 13}, 3},                // 每个数字都是不同的质数
        {{30, 42, 70}, 4},               // 30=2*3*5, 42=2*3*7, 70=2*5*7，质因数为2, 3, 5, 7
        {{100, 200, 300}, 3},            // 100=2^2*5^2, 200=2^3*5^2, 300=2^2*3*5^2，质因数为2, 3, 5
        {{17, 19, 23}, 3},               // 每个数字都是不同的质数
        {{9, 27, 81}, 1},                // 所有数字只有质因数3
    };

    // 遍历测试用例表并验证
    for (const auto& testCase : testCases) {
        int result = distinctPrimeFactors(const_cast<vector<int>&>(testCase.input));
        assert(result == testCase.expected && "Test case failed!");
    }

    cout << "所有测试用例通过！" << endl;
}

int main() {
    testDistinctPrimeFactors();
    return 0;
}
