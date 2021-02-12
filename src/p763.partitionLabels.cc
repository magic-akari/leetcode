#include <array>
#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
   public:
    auto partitionLabels(const string& S) -> vector<int> {
        array<Span, 26> record;

        short const size = S.size();
        for (short i = 0; i < size; ++i) {
            auto c = S[i] - 'a';

            if (i < record.at(c).start) {
                record.at(c).start = i;
            }
            record.at(c).end = i;
        }

        sort(begin(record), end(record), [](auto const& a, auto const& b) { return a.start < b.start; });

        vector<int> result{};

        auto prev_start = record[0].start;
        auto prev_end = record[0].end;

        for (short i = 1; i < 26 && record.at(i).end != -1; ++i) {
            auto const span = record.at(i);
            if (span.start < prev_end) {
                if (span.end > prev_end) {
                    prev_end = span.end;
                }
            } else {
                result.push_back(prev_end - prev_start + 1);
                prev_start = span.start;
                prev_end = span.end;
            }
        }

        result.push_back(prev_end - prev_start + 1);

        return result;
    }

   private:
    struct Span {
        short start{501};
        short end{-1};
    };
};
// @lc code=end

#include "vectorfmt.hh"

auto main() -> int {
    Solution s;

    cout << s.partitionLabels("ababcbacadefegdehijhklij") << endl;
    cout << s.partitionLabels("caedbdedda") << endl;

    return 0;
}
