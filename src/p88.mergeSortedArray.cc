#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto target = rbegin(nums1);
        auto p1 = rbegin(nums1) + nums1.size() - m;
        auto p2 = rbegin(nums2);

        while (p1 != rend(nums1) && p2 != rend(nums2)) {
            if (*p1 < *p2) {
                *(target++) = *(p2++);
            } else {
                *(target++) = *(p1++);
            }
        }

        while (p2 != rend(nums2)) {
            *(target++) = *(p2++);
        }
    }
};
// @lc code=end

#include "vectorfmt.hh"

auto main() -> int {
    Solution s;
    vector<int> n1{1, 2, 3, 0, 0, 0};
    vector<int> n2{2, 5, 6};
    s.merge(n1, 3, n2, 3);

    cout << n1 << endl;

    return 0;
}
