// 使用 Dynamic Programing 算法
var canJump = function(nums) {
    let dp = new Array(nums.length).fill(false);
    // 下標的意義表示index是否可以走到，因此初始化第0步為true
    dp[0] = true;
    for (let i = 0 ; i < nums.length ; i++) {
        for (let j = 0 ; j < i ; j++) {
            if (dp[j] && j + nums[j] >= i) { // 判斷前一步是否能走到，且前一步加上nums[前一步]是否能大過當前這步
                dp[i] = true;
                break;
            }
        }
    }
    return dp[nums.length - 1];
};

let nums = [5,9,3,2,1,0,2,3,3,1,0,0];
console.log(canJump(nums));