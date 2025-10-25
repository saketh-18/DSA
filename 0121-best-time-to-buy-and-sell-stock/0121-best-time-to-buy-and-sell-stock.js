/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let mini = prices[0];
    let ans = 0;
    
    for(let el of prices){
        let cost = el - mini;
        ans = Math.max(ans,cost);
        mini = Math.min(el,mini);
    }

    return ans;
};