#include <gtest/gtest.h>

struct TestCase {
    vector<int> arr;
    vector<tuple<int, int, int>> queries;
    vector<int> expected;
};

TestCase testCases[] = {
    {
        {1, 1, 2, 2, 2, 3, 3, 3, 3},
        {{0, 8, 1}, {0, 8, 2}, {0, 8, 3}, {4, 8, 3}},
        {2, 3, 4, 3}
    },
    {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {{0, 9, 1}, {0, 9, 5}, {0, 9, 10}, {4, 8, 5}},
        {1, 1, 1, 1}
    },
    {
        {},
        {{0, 0, 1}},
        {0}
    }
};

TEST(RangeFreqQueryTest, TestRangeFreqQuery) {
    for (const auto& tc : testCases) {
        RangeFreqQuery* obj = new RangeFreqQuery(tc.arr);
        for (int i = 0; i < tc.queries.size(); i++) {
            int left, right, value;
            tie(left, right, value) = tc.queries[i];
            int result = obj->query(left, right, value);
            ASSERT_EQ(result, tc.expected[i]);
        }
        delete obj;
    }
}
