/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    for(let i = 0; i < nums.length; i++){
        let temp = nums[i].toString();
        nums[i] = temp;
    }

    

nums.sort((a, b) => (b + a).localeCompare(a + b));


    // for (el of nums){
    //     console.log(el);
    // }
    let ans = nums.join("");

    if(ans == 0) return (0).toString();
    return ans;
};