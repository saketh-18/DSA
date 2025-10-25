/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function(n) {
    let ans = [];
    
    for(let el = 1; el <= n; el++){
        if(el%3 == 0 && el%5 == 0) ans.push("FizzBuzz");
        else if(el%3 == 0) ans.push("Fizz");
        else if(el%5 == 0) ans.push("Buzz");
        else ans.push(el.toString());
    }

    return ans;
};