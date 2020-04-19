/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
   public:
    static vector<string> data;
    auto countAndSay(int n) -> string {
        if (n <= data.size()) {
            return data[n - 1];
        }

        while (data.size() < n) {
            auto s = data.back();

            auto count = 1;

            stringstream str;

            for (auto i = 0; i < s.length(); ++i) {
                if (s[i] == s[i + 1]) {
                    ++count;
                } else {
                    str << count << s[i];
                    count = 1;
                }
            }

            data.push_back(str.str());
        }

        return data.back();
    }
};

vector<string> Solution::data = {"1", "11", "21", "1211", "111221"};
// @lc code=end

int main(int argc, char const* argv[]) {
    auto a = new Solution();

    for (size_t i = 1; i <= 30; i++) {
        cout << a->countAndSay(i) << endl;
    }

    return 0;
}
