#include <gtest/gtest.h>

struct TestCase {
    vector<vector<int>> tasks;
    vector<int> expected;
};

TEST(GetOrderTest, HandleGetOrder) {
    // 定义测试用例
    vector<TestCase> testCases = {
        {
            {{1, 2}, {2, 4}, {3, 2}, {4, 1}},
            {0, 2, 3, 1}
        },
        {
            {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}},
            {4, 3, 2, 0, 1}
        },
        {
            {{19, 13}, {16, 9}, {21, 10}, {32, 25}, {30, 10}, {27, 22}, {35, 15}, {29, 13}, {40, 20}},
            {1, 2, 4, 7, 6, 5, 3, 0, 8}
        },
        {
            {{35, 15}, {19, 27}, {17, 22}, {11, 13}, {2, 9}, {5, 22}, {29, 22}, {33, 7}, {16, 10}},
            {4, 3, 8, 0, 7, 1, 2, 5, 6}
        }
    };

    for (const auto& testCase : testCases) {
        vector<vector<int>> tasks = testCase.tasks;
        vector<int> expected = testCase.expected;
        vector<int> result = getOrder(tasks);
        ASSERT_EQ(result, expected);
    }
}
