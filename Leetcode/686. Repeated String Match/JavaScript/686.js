var repeatedStringMatch = function(a, b) {
    // 建立 next table
    const makeNextTable = b => {
        let j = 0;
        let next = [j];
        for (let i = 1 ; i < b.length ; i++) {
            while (j > 0 && b[j] != b[i]) {
                j = next[j - 1];
            }

            if (b[j] == b[i]) {
                j++;
            }

            next[i] = j;
        }

        return next;
    }

    let next = makeNextTable(b);
    // 如果有substring的話repeat = 2一定找得到
    let repeat = 2;
    // 若b比a字串長度長則重新計算repeat
    if (b.length > a.length) {
        repeat = Math.ceil((b.length + (b.length % a.length)) / a.length) + 1;
    }

    let newString = a.repeat(repeat);
    // 使用kmp演算法找尋SubString
    for(let i = 0, j = 0 ; i < newString.length ; i++) {
        while(j > 0 && b[j] != newString[i]) {
            j = next[j - 1];
        }

        if (b[j] == newString[i]) {
            j++
        }
        // 若j == next.length表示找到SubString，如果i + 1 < 原本字串長度，表示不用repeat
        if (j == next.length && ((i + 1) < a.length)) {
            return 1;
            // 若j == next.length表示找到SubString，且 i <= a.length * (repeat - 1)長度，表示在repeat - 1內就找到了
        } else if (j == next.length && a.length * (repeat - 1) != newString.length && ((i + 1) <= a.length * (repeat - 1))) {
            return repeat - 1;
            // 若j == next.length表示找到SubString，且(i + 1) <= newString.length長度，表示在repeat內找到
        } else if (j == next.length && ((i + 1) <= newString.length)) {
            return repeat;
        } 
    }
    return -1;
};

let a = "abcbc";
let b = "cabcbca";
console.log(repeatedStringMatch(a, b));