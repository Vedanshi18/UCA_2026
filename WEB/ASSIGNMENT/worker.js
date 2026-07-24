self.onmessage = function() {

    var xhr = new XMLHttpRequest(); //Creates an AJAX request
    xhr.open("GET", "https://dummyapi.com/users", true); //true means asynchronous

    //After server sends a response
    xhr.onload = function() {
        if (xhr.status == 200) { //Successful
            var users = JSON.parse(xhr.responseText);
            if (users.length == 0)
                self.postMessage([]);
            else
                self.postMessage(users);
        }
        else {
            self.postMessage([]); //Failure
        }
    };

    xhr.send(); //Actually sends req to server
};