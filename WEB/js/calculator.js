//Generator Fn 
function* calculator(initial) {
    let result = initial;
    while (true) {
        const input = yield result; // yield =-> stop here & return this value to the caller, wait for the next input
        //Paused
        if (typeof input.value !== 'number') {
            yield "Invalid input";
            continue; //Go back to while loop, wait for the next input
        }
        switch (input.operation) {
            case "add":
                result += input.value;
                break;
            case "subtract":
                result -= input.value;
                break;
            case "multiply":
                result *= input.value;
                break;
            case "divide":
                if (input.value === 0) {
                    yield "Cannot divide by zero";
                    continue;
                }
                result /= input.value;
                break;
            default:
                yield "Invalid operation";
                continue;
        }
    }
}
const calc = calculator(50);
console.log(calc.next().value); // 50, now gen is paused at the first yield statement, waiting for input
console.log(calc.next({ operation: "add", value: 30 }).value); // 80
console.log(calc.next({ operation: "multiply", value: 2 }).value); // 160
console.log(calc.next({ operation: "add", value: "30" }).value); // Invalid input
calc.next(); // Resume after invalid input
console.log(calc.next({ operation: "multiply", value: 0 }).value); // 0
console.log(calc.next({ operation: "divide", value: 0 }).value); // Cannot divide by zero