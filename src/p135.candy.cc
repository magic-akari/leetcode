#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
   public:
    auto candy(vector<int> const& ratings) -> int {
        vector box(ratings.size(), 1);

        int size = ratings.size();

        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1] && box[i] <= box[i - 1]) {
                box[i] = box[i - 1] + 1;
            }
        }

        for (int i = size - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && box[i] <= box[i + 1]) {
                box[i] = box[i + 1] + 1;
            }
        }

        return reduce(begin(box), end(box));
    }
};
// @lc code=end

auto main() -> int {
    Solution s;
    cout << s.candy({1, 0, 2}) << endl;
    cout << s.candy({1, 2, 2}) << endl;
    return 0;
}
