var repeatedSubstringPattern = function(s) {
  // 建立 next table
  function makeNextTable(s) {
    let j = 0;
    let next = [j];
    for (let i = 1 ; i < s.length ; i++) {
        while (j > 0 && s[j] != s[i]) {
            j = next[j - 1];
        }

        if (s[j] == s[i]) {
            j++;
        }

        next[i] = j;
    }

    return next;
  }  

  let next = makeNextTable(s);
  // next table index 的意義表示最長前後綴，
  // 當next table的最後一個值 > 0 表示最後一個值有最長前後綴，
  // 且當字串總長 - next table的最後一個值，表示可能重複的substring，
  // 因此當 next table的最後一個值 和 (字串總長 - next table的最後一個值) 的餘數 = 0，表示有連續重複substring
  return (next[s.length - 1] > 0 && (next[s.length - 1] % (s.length - next[s.length - 1]) == 0)) ? 1 : 0;
};

let s = "abcabcabcabc";
console.log(repeatedSubstringPattern(s));