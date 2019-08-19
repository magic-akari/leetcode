/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
   public:
    auto twoSum(vector<int>& nums, int target) const -> vector<int> {
        unordered_map<int, int> record;
        const auto size = nums.size();

        for (int i = 0; i < size; ++i) {
            const auto num = nums[i];
            if (record.find(num) != record.end()) {
                return vector{record[num], i};
            }
            record[target - num] = i;
        }

        return vector<int>{};
    }
};
// @lc code=end

auto main(int argc, char const* argv[]) -> int {
    vector nums = {2, 7, 11, 15};
    Solution s;
    auto result = s.twoSum(nums, 9);

    for (auto const& i : result) {
        std::cout << i << ", ";
    }

    return 0;
}
