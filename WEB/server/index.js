import * as http from "http"; //shows error , we need to ser type : module in package.json to use import syntax
// const http = require("http");

let value = "Hello world";
console.log("Node js first program ->", value);

// http is a module/object, createServer is its method which creates a server and returns an object of type server
// Takes request n generates response

const server = http.createServer((req, res) => {
  res.writeHead(200, { "Content-Type": "application/json" }); // to make browser know which format of data is being sent over the network
  res.end(JSON.stringify({ 
        response: "Hello from Node JS server",
        description : "Hello world!"
   }));  //Data sent only as String, so we need to convert JSON Object it into string using JSON.stringify before sending data over the network
});

const hostname = "127.0.0.1";
const port = 5000; //as on one machine we can have multiple servers running on different ports
// server.listen(port, hostname, () => {
//   console.log(`Server running at http://${hostname}:${port}/`);
// });
server.listen(port, hostname); //Now server has started which is continuously running 
//Process also running in background nodejs runtime, so we need to stop it manually by ctrl+c