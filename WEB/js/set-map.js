// Set - Equivalent to an array but with unique values
// Map - Equivalent to an object but with key-value pairs
let array1 = [1, 2, 3, 4, 4, 2, 3];

let set1 = new Set([1, 2, 3, 4, 4, 2, 3]);
set1.add(5);

// Set is a collection of unique elements
// Set data structure is in Entries
// [[key1, value1], [key2, value2], [key3, value3], [key4, value4], [key5, value5]]

// [key1, value1]

var map1 = new Map([
    ["key1", "value1"],
    ["key2", "value2"]
]);

//Map returns a new array
//For each doesnt return anything

let map1 = new Map([["name", "John"]]);
map1.set("age", 30); //Adding a new key-value pair to the map