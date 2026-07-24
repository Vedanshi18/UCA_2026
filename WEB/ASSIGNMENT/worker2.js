self.onmessage = function () {
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "https://dummyapi.com/users", true);

  xhr.onload = function () {
    if (xhr.status == 200) {
      var users = JSON.parse(xhr.responseText);
      self.postMessage(users);
    } 
    else {
      self.postMessage([]);
    }
  };

  xhr.send();
};
