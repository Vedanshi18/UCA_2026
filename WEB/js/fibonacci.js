function* fibonacci() {
    let a = 0, b = 1;
    while (true) {
        yield a;
        let next = a + b;
        a = b;
        b = next;
        // [a, b] = [b, a + b]; // Destructuring assignment to swap values and calculate the next Fibonacci number
    }
}
const fibGen = fibonacci();

console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);
console.log(fibGen.next().value);