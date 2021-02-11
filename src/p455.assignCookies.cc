#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));

        auto pg = begin(g);

        for (auto ps = begin(s); pg < end(g) && ps < end(s); ++ps) {
            if (*pg > *ps) {
                continue;
            }
            ++pg;
        }

        return pg - begin(g);
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector g{1, 2, 3};
    vector s{1, 1};
    cout << sol.findContentChildren(g, s);
    return 0;
}
