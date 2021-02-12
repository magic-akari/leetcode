#include <iostream>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
   public:
    auto eraseOverlapIntervals(vector<vector<int>>& intervals) -> int {
        if (intervals.empty()) {
            return 0;
        }

        sort(begin(intervals), end(intervals), [](auto const& a, auto const& b) { return a[1] < b[1]; });

        auto const size = intervals.size();
        auto erase = 0;
        auto prev_end = intervals[0][1];

        for (int i = 1; i < size; ++i) {
            if (intervals[i][0] < prev_end) {
                ++erase;
            } else {
                prev_end = intervals[i][1];
            }
        }

        return erase;
    }
};
// @lc code=end

auto main(int argc, char const* argv[]) -> int {
    Solution s;

    using SpanList = vector<vector<int>>;

    SpanList a{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    SpanList b{{1, 2}, {1, 2}, {1, 2}};
    SpanList c{{1, 2}, {2, 3}};

    cout << s.eraseOverlapIntervals(a) << endl;
    cout << s.eraseOverlapIntervals(b) << endl;
    cout << s.eraseOverlapIntervals(c) << endl;
    return 0;
}
