#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

// @lc code=start
class Solution {
   public:
    auto checkPossibility(vector<int>& nums) -> bool {
        auto const size = nums.size();

        bool flag = true;

        for (size_t i = 0; i < size - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                if (!flag) {
                    return false;
                }
                flag = false;

                if (i > 0 && i + 1 < size && nums[i - 1] > nums[i + 1]) {
                    nums[i + 1] = nums[i];
                }
            }
        }

        return true;
    }
};
// @lc code=end

auto main() -> int {
    Solution s;
    vector<int> a{4, 2, 3};     // true
    vector<int> b{4, 2, 1};     // false
    vector<int> c{5, 7, 1, 8};  // true
    vector<int> d{1, 2, 1, 2};  // true
    vector<int> e{3, 3, 3};     // true
    vector<int> f{3, 4, 2, 3};  // false

    cout << s.checkPossibility(a) << endl;
    cout << s.checkPossibility(b) << endl;
    cout << s.checkPossibility(c) << endl;
    cout << s.checkPossibility(d) << endl;
    cout << s.checkPossibility(e) << endl;
    cout << s.checkPossibility(f) << endl;
    return 0;
}
