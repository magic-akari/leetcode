/*
 * @lc app=leetcode id=13 lang=javascript
 *
 * [13] Roman to Integer
 */

// @lc code=start

/**
 * @type {Record<string, number>}
 */
const symbols = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
};

/**
 * @param {string} s
 * @return {number}
 */

const romanToInt = (s) => {
    let result = 0;
    let p = 0;
    for (const c of s) {
        const sc = symbols[c];
        if (p < sc) {
            result -= 2 * p;
        }
        result += sc;
        p = sc;
    }
    return result;
};
// @lc code=end

console.log(romanToInt("III"));
console.log(romanToInt("IV"));
console.log(romanToInt("IX"));
console.log(romanToInt("LVIII"));
console.log(romanToInt("MCMXCIV"));
