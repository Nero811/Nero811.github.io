/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
  let i = 0;
  let j = nums.length - 1;
  while (i <= j) {
    let mid = Math.floor((i + j) / 2);
    if (target > nums[mid]) {
      i = mid + 1;
    } else if (target < nums[mid]) {
      j = mid - 1;
    } else if (target === nums[mid]) {
      return mid;
    }
  }
  return -1;
};

let nums = [-1, 0, 3, 5, 9, 12];
let target = 9;
console.log(search(nums, target));
