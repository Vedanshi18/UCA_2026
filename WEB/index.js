//document.getElementById("header").innerHTML = "Dynamic Name Now";     //Failed as it showed company name because we linked script file in the head section of the html file. That means before body is loaded , js was executed & header was not found then. So we have 2 modes asyn & defer  

// async when html to be created , when js does not have to modify html
// defer when js has to affect html
// both download immediately , asynchronously , never block for download
// defer exceutes file only after html file is parsed (at end)

//same as above
//can pause fn calling line using (red dot) debug point on sources in console after searching this file to see Company Name
function foo() {
    document.getElementById("header").innerHTML = "Dynamic Name Now";
}
//Method to delay something till end of exec cycle
    // 2 parameters - method , time in ms(optional)
setTimeout(foo, 3000);
//foo();


//runtime environments for js : Browser, NodeJs
//Parsing : Line by line 
//Rendering : Parse HTML, then logical boxes, then body div data then CSS finds html tags 
//CSS cant be rendered except browser