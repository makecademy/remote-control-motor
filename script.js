window.onload = function(){
	button = document.getElementById('submitButton');
	button.onClick = sendCommand;
}

function sendCommand(){
	speed = document.getElementById("speedText").value;

	form = document.getElementById("speedForm");
	form.method = "GET";
	form.action = "remote_control.php";
	form.submit();
}