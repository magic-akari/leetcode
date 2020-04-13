/*
 * @lc app=leetcode id=14 lang=rust
 *
 * [14] Longest Common Prefix
 */
use super::Solution;

// @lc code=start
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        if strs.len() == 0 {
            return "".to_string();
        }

        return strs[1..]
            .iter()
            .map(|s| &s[..])
            .fold(&strs[0][..], Self::find_prefix)
            .to_owned();
    }

    fn find_prefix<'a>(s1: &'a str, s2: &'a str) -> &'a str {
        for (index, (i, j)) in s1.bytes().zip(s2.bytes()).enumerate() {
            if i != j {
                return &s1[..index];
            }
        }

        if s1.len() <= s2.len() {
            s1
        } else {
            s2
        }
    }
}
// @lc code=end

#[test]
fn test() {
    assert_eq!(
        Solution::longest_common_prefix(vec![
            "flower".to_owned(),
            "flow".to_owned(),
            "flight".to_owned()
        ]),
        "fl".to_owned()
    );

    assert_eq!(
        Solution::longest_common_prefix(vec![
            "dog".to_owned(),
            "racecar".to_owned(),
            "car".to_owned()
        ]),
        "".to_owned()
    );

    assert_eq!(
        Solution::longest_common_prefix(vec!["flower".to_owned(),]),
        "flower".to_owned()
    );

    assert_eq!(Solution::longest_common_prefix(vec![]), "".to_owned());
}
