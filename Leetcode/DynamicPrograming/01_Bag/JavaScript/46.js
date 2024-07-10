const readline = require("readline");
const rl = readline.createInterface({
    input:process.stdin,
    output:process.stdout,
});
let lineCount = 0
let m,n
let space = []
let value = []
rl.on("line",function(line){
    lineCount++;
    if(lineCount===1){
        let input = line.split(" ").map(Number)
        m = input[0]
        n =input[1]
    }
    if(lineCount===2){
        space = line.split(" ").map(Number)
    }
    if(lineCount===3){
        value = line.split(" ").map(Number)
        const dp = new Array(m).fill(0).map(()=>new Array(n+1).fill(0));
        for (let j = 1 ; j < (n + 1) ; j++) {
            dp[0][j] = j >= space[0] ? value[0] : 0;
        }
         for (let i = 1 ; i < m ; i++) {
            for (let j = 0 ; j < n + 1 ; j++) {
                if (j >= space[i]) {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - space[i]] + value[i]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        console.log(dp[m-1][n])
        rl.close();
    }
})
