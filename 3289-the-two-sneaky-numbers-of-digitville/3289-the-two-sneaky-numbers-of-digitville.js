/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getSneakyNumbers = function(nums) {
    let hash = new Map();

    let arr = [];
    for(let i = 0 ; i < nums.length; i++){
        if(hash.has(nums[i])) arr.push(nums[i]);
        hash.set(nums[i], 1);
    }

    return arr;
};