#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
   public:
    auto canPlaceFlowers(vector<int>& flowerbed, int n) -> bool {
        auto const size = flowerbed.size();
        auto placed = 0;

        for (int i = 0; i < size; ++i) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                ++placed;
            }
        }

        return placed >= n;
    }
};
// @lc code=end

auto main(int argc, char const* argv[]) -> int {
    Solution s;

    vector<int> a{1, 0, 0, 0, 1};
    cout << s.canPlaceFlowers(a, 1) << endl;

    vector<int> b{1, 0, 0, 0, 1};
    cout << s.canPlaceFlowers(b, 2) << endl;

    return 0;
}
