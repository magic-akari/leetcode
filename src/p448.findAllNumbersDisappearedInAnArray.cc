#include <iostream>
#include <vector>
#include "vectorfmt.hh"

using namespace std;

/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
   public:
    auto findDisappearedNumbers(vector<int>& nums) -> vector<int> {
        for (auto const& i : nums) {
            auto target = (size_t)(abs(i) - 1);
            nums[target] = -abs(nums[target]);
        }

        vector<int> result;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result.push_back((int)(i + 1));
            }
        }

        return result;
    }
};
// @lc code=end

auto main() -> int {
    Solution s;

    vector<int> a{4, 3, 2, 7, 8, 2, 3, 1};

    cout << s.findDisappearedNumbers(a) << endl;

    return 0;
}
