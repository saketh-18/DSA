/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    let ans = 0;
    for(num in args){
        ans++;
    }
    return ans;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */