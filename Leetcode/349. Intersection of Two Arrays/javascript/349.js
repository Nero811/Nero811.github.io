var intersection = function(nums1, nums2) {
    let set = new Set();
    let result = new Set();
    for (num of nums1) {
        set.add(num);
    }

    nums2.forEach(num => {
        if (set.has(num)) {
            result.add(num);
        }
    });

    return Array.from(result);
};

let nums1 = [4,9,5];
let nums2 = [9,4,9,8,4];
console.log(intersection(nums1, nums2));