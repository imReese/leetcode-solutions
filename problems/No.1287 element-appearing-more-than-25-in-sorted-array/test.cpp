#include <gtest/gtest.h>
#include <vector>

using namespace std;

extern int findSpecialInteger(vector<int>& arr);

// 定义测试数据结构
struct TestCase {
    vector<int> arr;
    int expected;
};

// 定义测试用例
TestCase testCases[] = {
    {{1,2,2,6,6,6,6,7,10}, 6},
    {{1,1,2,2,3,3,3,3}, 3},
    {{1,1,1,2,2,2,2,3,3,3,3,4,4,4,4}, 4},
    {{1}, 1},
    {{1,2,3,4,5,6,7,8,9,10}, 1},
};

// 定义测试函数
TEST(FindSpecialInteger, TestCases) {
    for (const auto& testCase : testCases) {
        ASSERT_EQ(findSpecialInteger(testCase.arr), testCase.expected);
    }
}
