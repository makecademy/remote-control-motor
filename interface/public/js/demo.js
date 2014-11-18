// Function to motor direction
$(document).ready(function() {

  $("#1").click(function() {
    $.get('/motor_control/digital/4/1', function() {
      $.get('/motor_control/digital/5/0');
    });
  });

  $("#2").click(function() {
    $.get('/motor_control/digital/4/0', function() {
      $.get('/motor_control/digital/5/1');
    });
  });

  // Function to control motor speed
  $("#motorspeed").mouseup(function(){

    // Get speed
    speed = $("#motorspeed").val(); 
    
    // Send command
    $.get("/motor_control/analog/6/" + speed);  

  });

});