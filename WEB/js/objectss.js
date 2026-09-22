// Object literals
// const student1 = {
//   name: "john doe",
//   age: 30,
//   email: "abc@gmail.com",
// };

// const student2 = {
//   name: "johan das",
//   age: 69,
//   email: "sabji@gmail.com",
// };

// we will declare const in object as well as in function so it cant be changed , we can only modify the value of keys in it.

// -------------------------empty object-------------------

// no two empty objects are equal they have a seperate memory reference.

// -------------------------Factory Function--------

// it is like returning a factory, simply returning a factory of objects.

// we can create a function to make multiple objects with the same keys just by giving the values.

// there is no relation in bw the objects made by these function, also it is the biggest challange if function modified later than objects cant be modified again itself as it has no relation with fucntion.

// they are extremely usefull in angular js as we want to create many objects with different types of object, it is very useful.

function createStudent(name, age, email, marks) {
  let maxMarks = 100;
  return {
    name: name,
    age: age,
    email: email,
    percentage: function () {
      return (marks / maxMarks) * 100;
    },
  };
}

const student3 = createStudent("saatvik", 20, "saatvik23@gmail.com", 96);
const student4 = createStudent("ujjwal", 20, "ujjwal16@gmail.com", 95);

// ----------------------create Object-----------------

// Object.create(obj) creates a new empty object whose prototype is obj.

const obj = Object.create(student4);

const person1 = Object.create({ 
  name: "bob",
  age: 20,
});

// --------Constructor Function-----------------------

// mimicking the function of class
// it has a behaviour of the classes

// when we create a object means define a state: like name, collage, age etc, so there can be multiple objects

// constuctor function is the classes of javascript
// it is solving the problem that now we dont have to make functions in object itself.

// it solves the relation problem, now objects have relation with the parent function.

// it uses this keyword
// it also uses Prototype inheritence - Prototype inheritance is the mechanism by which an object can access properties and methods from another object through its prototype.

function constructStudent(name, age, email, marks) {
  this.name = name;
  this.age = age;
  this.email = email;
  this.marks = marks;

  // this === student1 or student2 or ... .
}

const student1 = new constructStudent("saatvik", 20, "saatvik23@gmail.com", 98);
const student2 = new constructStudent("ujjwal", 20, "ujjwal16@gmail.com", 96);
const student5 = new constructStudent("upander",20,"upander01@gmail.com",100);

// whenever we use new keyword, it created a new instant with a reference and it refers to the left hand side operator of the new

// -------------------------prototype in object----

// In JavaScript, prototype is a mechanism through which objects can inherit properties and methods from another object or constructor function.

// we use prototype in function and and __proto__ in object.

constructStudent.prototype.percentage = function () {
  let maxMarks = 100;
  return (this.marks / maxMarks) * 100 + "%";
};

// console.log(constructStudent.prototype);
// console.log(student1.__proto__);
// console.log(student1.__proto__ == student2.__proto__);  //true
// console.log(student1.name + " " + student1.percentage());
// console.log(student2.name + " " + student2.percentage());
// console.log(student5.name + " " + student5.percentage());

// prototype chains and prototype inheritance.

// also this is not the very best method for the problem,

// ------Object using assign-------------------

// object using assign is used to assign a existing object content into another existing content or if we want to return or create a object with new values + values from existing object without changing anything in existing object.

// object using assign is used for merging two objects into one object

// let obj3 = Object.assign(sourceObj, targetObj);

// let obj1 = { name: "ujjwal" };
// let obj2 = { age: 20 };

// Object.assign(obj1, obj2);
// console.log(obj1); {name: "ujjwal", age: "20"}

// // to return or create a new object using assign
// Object.assign({}, obj2);

// // obj3 and obj1 are exaclty same;
// var obj3 = Object.assign(obj1, obj2);

// let obj4 = Object.assign({ collage: "chitkara" }, obj1);



// Thursday--------------------------

// ==================================================
// OBJECT CREATION
// ==================================================

const obj9 = { name: "name1" };

const obj10 = new Object({
  name_0: "name_0"
});


// ==================================================
// hasOwnProperty()
// ==================================================

// Checks whether a property belongs directly to the object
// and is not inherited from its prototype.

console.log(obj9.hasOwnProperty === obj10.hasOwnProperty);

// true

// Both inherit hasOwnProperty() from Object.prototype.


// ==================================================
// typeof
// ==================================================

console.log(typeof constructStudent);
console.log(typeof Object);

// Object is a built-in constructor function.


// ==================================================
// OBJECT ACCESS
// ==================================================

console.log(student1);
console.log(student1.name);


// ==================================================
// Object.create() vs Object.assign()
// ==================================================

const objAsPrototype = {
  name: "ujjwal"
};

// Object.assign() → copies properties into a new object
const targetUsingAssign = Object.assign({}, objAsPrototype);

// Object.create() → creates an object with the given
// object as its prototype
const targetUsingCreate = Object.create(objAsPrototype);

console.log(targetUsingAssign);
console.log(targetUsingCreate);


// ==================================================
// PROTOTYPE
// ==================================================

console.log(targetUsingAssign.__proto__);
console.log(targetUsingCreate.__proto__);

// Object.assign() → prototype is Object.prototype
// Object.create() → prototype is objAsPrototype


// ==================================================
// PROPERTY INHERITANCE
// ==================================================

objAsPrototype.age = 20;

console.log(targetUsingAssign.age);  // undefined
console.log(targetUsingCreate.age);  // 20

// assign → property was copied earlier
// create → property is accessed through the prototype