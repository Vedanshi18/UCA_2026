// function clickMe() {
//     alert("Button clicked");
// }
// //event on mouse click travels form html then body then div then button
// //as soon as 'released' alert is shown, event travels back to body
// //event is implemented when we release not on click
// //First event from body to button is called capturing phase and then event from button to body is called bubbling phase
// //React optimises this

//Next class
//Transfer JS file created to React components
//No HTML in frameworks, managed by JS

document.getElementById("appcontent").innerHTML = "Content from JS";

//Template literals - Multi line strings in JS denoted by ``
// document.getElementById("appcontent").innerHTML = `
// <div>
//     <h1>Heading of multiline content</h1>
//     <h2> Dynamic content ${7+18}</h2>  //JS added using &{}
//     <p>Paragraph of multiline content</p>
//     </div>
// `;

//Make the table dynamic

//This data will come from server
let productList = [];
let productListFromServer = [];
loadDataFromServer();
renderProducts(productList);
function loadDataFromServer() {
  setTimeout(() => {
    productListFromServer = [
      {
        name: "Product 1",
        price: "$10.00",
        description: "This is a great product.",
      },
      {
        name: "Product 2",
        price: "$20.00",
        description: "This is a great product.",
      },
      {
        name: "Product 3",
        price: "$30.00",
        description: "This is a great product.",
      },
    ];
    console.log("data from server ", productListFromServer);
  }, 5000);
}

function renderProducts(productListFromServer) {
  // === checks value as well as datatype
  // 0 == "0" true
  // 0 === "0" false
  if (productList.length === 0) {
    document.getElementById("appcontent").innerHTML = `
        <h3> Loading data from server </h3>
        `;
    return;
  }

document.getElementById("content").innerHTML = `
    <table>
        <thead>
            <tr>
                <th>Serial No.</th>
                <th>Product Name</th>
                <th>Price</th>
            </tr>
        </thead>
        <tbody>
            ${productList.map((item) => {
              return `
                <tr>
                    <td>${item.name}</td>
                    <td>${item.price}</td>
                    <td>${item.description}</td>
                </tr>                
                `;
            })}
        </tbody>
    </table>
`;
}
// document.getElementById("appcontent").innerHTML = `
//     <table>
//         <thead>
//             <tr>
//             <th>Serial No.</th>
//             <th>Product Name</th>
//             <th>Price</th>
//             </tr>
//         </thead>
//         <tbody>
//             <tr>
//                 <td>1</td>
//                 <td>Mobile</td>
//                 <td>10000</td>
//             </tr>
//             <tr>
//                 <td>2</td>
//                 <td>Laptop</td>
//                 <td>50000</td>
//             </tr>
//         </tbody>
//     </table>
// `;
