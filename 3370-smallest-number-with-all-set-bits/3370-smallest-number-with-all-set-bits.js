/**
 * @param {number} n
 * @return {number}
 */
var smallestNumber = function(n) {
    let binary = "";

    while(n > 0){
        binary = (n%2) + binary;
        n = Math.floor(n/2);
    }

    binary = Array(binary.length).fill('1').join("");
    let decimal = parseInt(binary,2);
    return decimal;
};