// Rest operator - ... (Expand elements of an array or object into multiple elements) 
// Spread operator - ... (Combine multiple values into a single data structure)
const arr1 = [1, 2, 3];
const arr2 = [4, 5, 6];
const arr3 = [...arr1, ...arr2]; // Spread operator to combine arrays
console.log("Combined Array using Spread Operator:", arr3);

const studentDetails = {
    name: "John Doe",
    age: 20,
    major: "Computer Science"
};
const studentDetails2 = {
    college: "XYZ University",
    age : 21 // This will overwrite the age property from studentDetails
};
const combinedStudentDetails = { ...studentDetails, ...studentDetails2 };
console.log("Combined Student Details using Spread Operator:", combinedStudentDetails);

const studentDetails = { 
    ...studentPersonalDetails, 
    ...studentAcademicDetails 
};

const studentDetails = { 
    studentPersonalDetails, 
    studentAcademicDetails 
};

// JS internally interprets this as following:
const studentDetails = {
    studentPersonalDetails: studentPersonalDetails,
    studentAcademicDetails: studentAcademicDetails,
};

// Rest operator
// Rest operator

const studentDetails = {
    name: "John Doe",
    age: 30,
    email: "john.doe@example.com",
    college: "ABC University",
};

const { college } = studentDetails;

sum(1, 2);
sum(1, 2, 3);
sum(1, 2, 3, 4);

//any number of arguments can be passed to the function using rest operator
function sum(...numbers) {
    let sum = 0;

    for (let number of numbers) {
        sum = sum + number;
    }

    return sum;
}