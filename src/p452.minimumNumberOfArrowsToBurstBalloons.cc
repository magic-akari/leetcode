#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
   public:
    auto findMinArrowShots(vector<vector<int>>& points) -> int {
        if (points.empty()) {
            return 0;
        }

        sort(begin(points), end(points), [](auto const& a, auto const& b) { return a[1] < b[1]; });

        auto const size = points.size();
        auto prev_end = points[0][1];
        auto shots = 1;

        for (auto i = 0; i < size; ++i) {
            if (points[i][0] <= prev_end) {
                continue;
            }
            prev_end = points[i][1];
            ++shots;
        }

        return shots;
    }
};
// @lc code=end

auto main(int argc, char const* argv[]) -> int {
    Solution s;

    using SpanList = vector<vector<int>>;

    SpanList a{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    SpanList b{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    SpanList c{{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    SpanList d{{1, 2}};
    SpanList e{{2, 3}, {2, 3}};
    SpanList f{{-2147483648, 2147483647}};

    cout << s.findMinArrowShots(a) << endl;
    cout << s.findMinArrowShots(b) << endl;
    cout << s.findMinArrowShots(c) << endl;
    cout << s.findMinArrowShots(d) << endl;
    cout << s.findMinArrowShots(e) << endl;
    return 0;
}
