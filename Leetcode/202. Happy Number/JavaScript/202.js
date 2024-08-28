var isHappy = function(n) {
    let count = function(n) {
        let sum = 0;
        while (n > 0) {
            let digit = n % 10;
            sum += digit * digit;
            n = Math.floor(n / 10);
        }
        return sum;
    }
    let map = new Map();

    while (true) {
        n = count(n);
        if (n === 1) {
            return true;
        }
        if (map.has(n)) {
            return false;
        }
        map.set(n, 1);
    }
};

n = 78;
console.log(isHappy(n));