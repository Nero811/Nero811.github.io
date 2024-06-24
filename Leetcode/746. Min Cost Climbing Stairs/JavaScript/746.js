var minCostClimbingStairs = function(cost) {
    let dp = [0, 0];
    for (let i = 2 ; i <= cost.length ; i++) {
        dp[i] = Math.min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
    }

    return dp[cost.length];
};


let cost = [10,15,20];
console.log(minCostClimbingStairs(cost));