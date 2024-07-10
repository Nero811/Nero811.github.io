var canPartitionKSubsets = function(nums, k) {
    let sum = 0;
    nums.forEach(num => {
        sum += num;
    });
    if (sum % k != 0) {
        return false;
    } 
    let target = sum / k;
    let arr = Array(k).fill(target);
    function solution (endIdx, arr, nums) {
        if (endIdx < 0) {
            return true;
        } 

        for (let i = 0 ; i < arr.length ; i++) {
            if (arr[i] == nums[endIdx] || (endIdx > 0 && arr[i] - nums[endIdx] >= nums[0])) {
                arr[i] -= nums[endIdx];
                if (solution(endIdx - 1, arr, nums)) {
                    return true;
                }
                arr[i] += nums[endIdx];
            }
            if (arr[i] == 0) break;
        }
        return false;
    }    

    return solution(nums.length - 1, arr, nums.sort((a, b) => a - b));
};

let nums = [4,4,6,2,3,8,10,2,10,7];
let k = 4;
console.log(canPartitionKSubsets(nums, k));