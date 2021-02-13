#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
   public:
    auto maxProfit(vector<int> const& prices) -> int {
        auto const size = prices.size();

        auto profit = 0;

        for (size_t i = 0; i < size - 1; ++i) {
            auto const diff = prices[i + 1] - prices[i];
            if (diff > 0) {
                profit += diff;
            }
        }

        return profit;
    }
};
// @lc code=end

auto main() -> int {
    Solution s;
    cout << s.maxProfit({7, 1, 5, 3, 6, 4}) << endl;
    cout << s.maxProfit({1, 2, 3, 4, 5}) << endl;
    cout << s.maxProfit({7, 6, 4, 3, 1}) << endl;
    cout << s.maxProfit({7, 6, 4}) << endl;
    cout << s.maxProfit({6, 7}) << endl;
    cout << s.maxProfit({7}) << endl;
    return 0;
}
