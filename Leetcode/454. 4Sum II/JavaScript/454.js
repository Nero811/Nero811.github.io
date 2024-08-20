var fourSumCount = function(nums1, nums2, nums3, nums4) {
    let map = new Map();
    let result = 0;

    for (num1 of nums1) {
        for (num2 of nums2) {
            if (!map.get((num1 + num2))) {
                map.set((num1 + num2), 1);
            } else {
                map.set((num1 + num2), map.get((num1 + num2)) + 1);
            }
        }
    }

    for (num3 of nums3) {
        for (num4 of nums4) {
            if (map.get(0-(num3 + num4))) {
                result += map.get(-(num3 + num4));
            }
        }
    }

    return result;
};

nums1 = [1,2];
nums2 = [-2,-1];
nums3 = [-1,2];
nums4 = [0,2];

console.log(fourSumCount(nums1, nums2, nums3, nums4));