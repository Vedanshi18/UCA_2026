function clickMe() {
    alert("Button clicked");
}
//event on mouse click travels form html then body then div then button
//as soon as 'released' alert is shown, event travels back to body
//event is implemented when we release not on click
//First event from body to button is called capturing phase and then event from button to body is called bubbling phase
//React optimises this 
