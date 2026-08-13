// ===============================
// JavaScript Loops Demo
// ===============================

// Array
let numsArray = [9, 8, 7, 6, 5];

console.log("Original Array:", numsArray);


// ====================================
// 1. Simple for loop
// ====================================

console.log("\n----- Simple For Loop -----");

for (let i = 0; i < numsArray.length; i++) {
    console.log(`Index: ${i}, Value: ${numsArray[i]}`);
}


// ====================================
// 2. for loop with break
// Stops when value becomes less than 7
// ====================================

console.log("\n----- For Loop with Break -----");

for (let i = 0; i < numsArray.length; i++) {

    if (numsArray[i] < 7)
        break;

    console.log(numsArray[i]);
}


// ====================================
// 3. for loop with continue
// Skip value 7
// ====================================

console.log("\n----- For Loop with Continue -----");

for (let i = 0; i < numsArray.length; i++) {

    if (numsArray[i] === 7)
        continue;

    console.log(numsArray[i]);
}


// ====================================
// 4. for...in with Array
// Iterates over indexes
// ====================================

console.log("\n----- For...in (Array) -----");

for (let index in numsArray) {
    console.log(`Index: ${index}, Value: ${numsArray[index]}`);
}


// ====================================
// 5. Object Example
// ====================================

let student = {
    name: "John Doe",
    age: 30,
    email: "john.doe@example.com",
    city: "Delhi"
};


// ====================================
// 6. for...in with Object
// Iterates over keys
// ====================================

console.log("\n----- For...in (Object) -----");

for (let key in student) {
    console.log(`${key} : ${student[key]}`);
}


// ====================================
// 7. for...of with Array
// Iterates over values
// ====================================

console.log("\n----- For...of (Array) -----");

for (let value of numsArray) {
    console.log(value);
}


// ====================================
// 8. for...of with String
// ====================================

let language = "JavaScript";

console.log("\n----- For...of (String) -----");

for (let ch of language) {
    console.log(ch);
}

// Callback
let numsArray1 = [9,8,7,6,5];

numsArray1.forEach(multiplyBy2CallbackFn);

function multiplyBy2CallbackFn(value){
    console.log("The evaluated value is:", value * 2);
}
numsArray1.forEach((value, index, array) => {
    console.log("The evaluated value is:", value * 2);
});

//Array.some
//Array.every
let x = numsArray1.some((item) => {
    return item % 2 == 0;
});
console.log(x);
let y = numsArray1.every((item) => {
    return item % 2 == 0; // can omit return also if only 1 statement in arrow fn
});
console.log(y);

//Find
let z = numsArray1.find((item) => {
    return item % 2 == 0; //First value that satisfies, else undefined
});
console.log(z);

let a = numsArray1.findIndex((item) => {
    return item % 2 == 0; //First index that satisfies, else -1
});
console.log(a);

//Filter
let w = numsArray1.filter((item) => {
    return item % 2 == 0;
});
console.log(w);

// break and continue cant be used in for each loop, rest can be used 