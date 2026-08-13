// Object literal  (earlier we saw string literals, template literals, array literals)
var obj1 = {
    name: "John",
    age: 30,
    email: "abc@gmail.com",
};

// Objects using create
// object.create() method creates a new object, using an existing object as the prototype of the newly created object
// Object is a function using which we can create objects or without using them 
var obj = Object.create(obj1);
var obj = Object.create({ name: "Amit" });