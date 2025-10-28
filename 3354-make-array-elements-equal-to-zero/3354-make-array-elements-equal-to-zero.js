/**
 * @param {number[]} nums
 * @return {number}
 */
var countValidSelections = function(vec) {
    let zeroes = [];

    for(let i = 0; i < vec.length; i++){
        if(vec[i] === 0){
            zeroes.push(i);
        }
    }

    let ans = 0;

    for(let cur of zeroes){
        for(let i = 0; i < 2; i++){
            let side = i;
            let curr = cur;
            let nums = [...vec];
            while(curr < nums.length && curr >= 0){
                if(nums[curr] === 0){
                    if(side == 1) curr++;
                    else curr--;
                }

                else if(nums[curr] > 0){
                    nums[curr]--;
                    side = 1 - side;
                    if(side == 0) curr--;
                    else curr++;
                }
            }

            let isZero = true;
            for(let el of nums){
                if(el != 0) {
                    isZero = false;
                    break;
                } 
            }

            if(isZero) ans++;
        }
    }

    return ans;

};