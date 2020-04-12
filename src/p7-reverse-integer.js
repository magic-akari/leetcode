/*
 * @lc app=leetcode id=7 lang=javascript
 *
 * [7] Reverse Integer
 */

// @lc code=start
const LEFT_EDGE = -Math.pow(2, 31);
const RIGHT_EDGE = Math.pow(2, 31) - 1;

/**
 * @param {number} x
 * @return {number}
 */

const reverse = (x) => {
    let y = x < 0 ? -x : x;
    let result = 0;
    while (y > 0) {
        result = result * 10 + (y % 10);
        y = (y / 10) >> 0;
    }
    result = x < 0 ? -result : result;
    if (result < LEFT_EDGE || result > RIGHT_EDGE) {
        return 0;
    }

    return result;
};
// @lc code=end

[reverse(123), reverse(-123), reverse(120)].forEach((v) => console.log(v));
