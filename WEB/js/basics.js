
// function foo(input) {
//     console.log("Input parameters", input)
// }

// //Self invoking fn
// (function foo(input) {
    // console.log (input);
// })("Hello");

// //Arrow fn
const foo = (input) => {
    console.log(input);
}
foo("Hello");  //GO to console in browser to check

//Array
let arr1 = [1, 2, 3, 4];

// Map function : 
// Accepts a callback fn as an argument
// Executed on each element of array 
// Return val becomes elements of New array
// const arr1mul = arr1.map((item) => {
//     return item * 2;
// })

//Callback function (Passed as an arg to another)
function multiply(item) {
    return item * 2;
}
const arr1mul = arr1.map(multiply);

console.log("New array : ", arr1mul);

