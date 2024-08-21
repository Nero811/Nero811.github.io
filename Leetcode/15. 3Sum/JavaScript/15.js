var threeSum = function(nums) {
    let map = new Map();
    for (num of nums) {
        if (map.get(num)) {
            map.set(num, map.get(num) + 1);
        } else {
            map.set(num, 1);
        }
    }

    let set = new Set();
    for (let i = 0 ; i < nums.length ; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        for (let j = i + 1 ; j < nums.length ; j++) {
            let sum = 0 - (nums[i] + nums[j]);
            if (map.get(sum)) {
                let cnt = 1;
                if (sum == nums[i]) cnt++;
                if (sum == nums[j]) cnt++;
                if (map.get(sum) >= cnt) {
                    let arr = [];
                    arr.push(nums[i]);
                    arr.push(nums[j]);
                    arr.push(sum)
                    arr = arr.sort();
                    set.add(arr.toString());
                }
            }
        }
    }

    return Array.from(set).map(str => str.split(',').map(Number));
};

nums = [-1,0,1,2,-1,-4];
console.log(threeSum(nums));