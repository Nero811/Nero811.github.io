var numSquares = function(n) {
    let dp = new Array(n + 1);
    for (let i = 0 ; i <= n ; i++) {
        dp[i] = i;
        for (let j = i - 1 ; j >= 0 ; j--) {
            if (i - j * j >= 0) {
                dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
            }
        }
    }
    return dp[n];
};

let n = 12;
console.log(numSquares(n));