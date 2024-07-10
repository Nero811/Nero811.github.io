var canPartition = function(nums) {
    if (nums.length === 1) {
        return false;
    }

  let sum = 0;
  nums.forEach(num => {
    sum += num;
  });
  if(sum % 2 == 1)
    return false;
  let target = sum / 2;
  let dp = Array(nums.length).fill(0).map(() => Array(target + 1).fill(0));

  for (let j = nums[0] ; j <= nums.target ; j++) {
    dp[0][j] = nums[0];
  }
  for (let i = 1 ; i < nums.length ; i++) {
    for (let j = 0 ; j <= target ; j++) {
        if (j < nums[i]) 
            dp[i][j] = dp[i - 1][j];
        else 
            dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
    }
  }

  if (dp[nums.length - 1][target] == target) {
    return true;
  }
  return false;
};

let nums = [1,5,11,5];
console.log(canPartition(nums));