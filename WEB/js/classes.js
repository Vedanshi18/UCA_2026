// there is no type as class in JavaScript and there is no core changes by making a class , internally a class is also a contructor function.


class constructStudent {
  constructor(name, age, email, marks) {
    this.name = name;
    this.age = age;
    this.email = email;
    this.marks = marks;
  }

  percentage() {
    let maxMarks = 100;
    return (this.marks / maxMarks) * 100 + "%";
  }

//   whenever we are creating a function in a class it is added in prototype by default.
}

const student1 = new constructStudent("saatvik", 20, "saatvik23@gmail.com", 98);
const student2 = new constructStudent("ujjwal", 20, "ujjwal16@gmail.com", 96);


// Question: How is everything in JavaScript an object?

// Answer: 
// 1) Not everything in JavaScript is an object.
// JavaScript has primitive values and objects.
//
// 2) Objects inherit properties and methods 
// through the Prototype chain.

// 3) This is called prototype inheritance.
//
// Example:
// 1) "hello".toUpperCase() works because JavaScript temporarily wraps the primitive string with a String object.


const arr1 = [1, 2];
const arr2 = new Array(1, 2);
const arr3 = new Array(1, 2, 3, 4);

// this Array is a constructor function, it has many properties in its prototype
console.log(arr1.__proto__);