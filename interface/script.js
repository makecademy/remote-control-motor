// Variables
var speed = 0;

// Function to control motor direction
function buttonClick(clicked_id){

    // Forward
    if (clicked_id == "1"){
        $.get( "serial.php", {
        command: "/digital/4/1"} );  

        $.get( "serial.php", {
        command: "/digital/5/0"} ); 
    } 

    // Reverse
    if (clicked_id == "2"){
        $.get( "serial.php", {
        command: "/digital/4/0"} );  

        $.get( "serial.php", {
        command: "/digital/5/1"} );  
    } 
}

// Function to control motor speed
function sliderClick(){

    // Get speed
    speed = $("#motor1").val(); 
    
    // Send command
    $.get( "serial.php", {command: "/analog/6/" + speed});  
}