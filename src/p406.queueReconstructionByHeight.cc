#include <iostream>
#include <vector>
#include "vectorfmt.hh"

using namespace std;

/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
   public:
    auto reconstructQueue(vector<vector<int>>& people) -> vector<vector<int>> {
        sort(begin(people), end(people), [](auto const& a, auto const& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }

            return a[0] > b[0];
        });

        vector<vector<int>> result;

        for (auto const& i : people) {
            result.insert(begin(result) + i[1], i);
        }

        return result;
    }
};
// @lc code=end

auto main() -> int {
    Solution s;
    vector<vector<int>> p1{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> p2{{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};

    cout << s.reconstructQueue(p1) << endl;
    cout << s.reconstructQueue(p2) << endl;

    return 0;
}
