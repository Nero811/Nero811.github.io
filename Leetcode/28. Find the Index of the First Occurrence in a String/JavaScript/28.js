var strStr = function(haystack, needle) {
    function makeNextTable(needle) {
        let j = 0;
        let next = [j];
        for (let i = 1 ; i < needle.length ; i++) {
            while (j > 0 && needle[j] != needle[i]) {
                j = next[j - 1];
            }

            if (needle[j] == needle[i]) {
                j++;
            }

            next[i] = j;
        }
        return next;
    } 
    let next = makeNextTable(needle);
    let j = 0;
    for (let i = 0 ; i < haystack.length ; i++) {
        while (j > 0 && needle[j] != haystack[i]) {
            j = next[j - 1];
        }

        if (needle[j] == haystack[i]) {
            if (j == needle.length - 1) {
                return i - needle.length + 1;
            }
            j++;
        }
    }
    return -1;
};

let haystack = "absadbutsad";
let needle = "sad";
console.log(strStr(haystack, needle));