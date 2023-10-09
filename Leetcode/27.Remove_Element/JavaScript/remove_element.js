/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
  let result = 0;
  for (let slowIdx = 0, fastIdx = 0; fastIdx < nums.length; fastIdx++) {
    if (nums[fastIdx] != val) {
      nums[slowIdx++] = nums[fastIdx];
      result++;
    }
  }
  return result;
};

let nums = [0, 1, 2, 2, 3, 0, 4, 2];
let val = 2;
console.log(removeElement(nums, val));
console.log(nums);
