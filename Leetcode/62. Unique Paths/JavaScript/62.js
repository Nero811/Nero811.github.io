var uniquePaths = function(m, n) {
    let dp = new Array(m);
    for (let i = 0 ; i < m ; i++) {
        dp[i] = new Array(n);
        dp[i][0] = 1;
    }
    for (let j = 0 ; j < n ; j++) {
        dp[0][j] = 1;
    }

    for (let i = 1 ; i < m ; i++) {
        for (let j = 1 ; j < n ; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
};

let m = 3;
let n = 7;
console.log(uniquePaths(m, n));