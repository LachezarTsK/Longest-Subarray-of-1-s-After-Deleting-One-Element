
/**
 * @param {number[]} input
 * @return {number}
 */
var longestSubarray = function (input) {
    let tail = 0;
    let head = 0;
    let numberOfZeros = 0;
    let longestSubarray = 0;
    let indexPreviousZero = -1;

    while (head < input.length) {
        if (input[head] === 0) {
            tail = (++numberOfZeros === 2) ? (indexPreviousZero + 1) : tail;
            numberOfZeros = 1;
            indexPreviousZero = head;
        }
        longestSubarray = Math.max(longestSubarray, head - tail);
        ++head;
    }

    return longestSubarray;
};
