/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let current = n;
    return function() {
        return current++;
    };
};

const counter1 = createCounter(10);
console.log(counter1()); 
console.log(counter1()); 
console.log(counter1()); 

const counter2 = createCounter(-2);
console.log(counter2());
console.log(counter2());
console.log(counter2());
console.log(counter2());
console.log(counter2()); 