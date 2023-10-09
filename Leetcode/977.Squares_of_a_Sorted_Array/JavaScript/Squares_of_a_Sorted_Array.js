/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function (nums) {
  let result = Array(nums.length).fill(0);
  let left = 0;
  let right = nums.length - 1;
  let index = result.length - 1;
  while (left <= right) {
    if (nums[left] * nums[left] > nums[right] * nums[right]) {
      result[index--] = nums[left] * nums[left];
      left++;
    } else {
      result[index--] = nums[right] * nums[right];
      right--;
    }
  }
  return result;
};

let nums = [-7, -3, 2, 3, 11];
console.log(sortedSquares(nums));
