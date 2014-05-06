<?php

// Get commands
$command = $_GET['command'];

// Includes
include "php_serial.class.php";

// Get configuration data
$serial_port = "/dev/cu.usbmodem1a12121";

try {
	$serial = new phpSerial;
	$serial->deviceSet($serial_port);
	$serial->confBaudRate(9600);
	$serial->confParity("none");
	$serial->confCharacterLength(8);
	$serial->confStopBits(1);

	$h = popen('nohup sleep 5 < '. $serial_port . ' &', 'r');
	pclose($h);
	exec('stty -F '. $serial_port .' -hupcl');
	usleep(100000);

	// Open
    $serial->deviceOpen();

    // Send dummy command to clear previous commands
    $serial->sendMessage("dummy" . "\r");
    $dummy = $serial->readPort();

    // Send command
    $serial->sendMessage($command . "\r");
    $answer = $serial->readPort();

    // If empty, retry
    if ($answer == "") {
      sleep(1);
      $serial->sendMessage($command . "\r");
      $answer = $answer . $serial->readPort();  
    }

    $serial->deviceClose();

	// Return JSON
	if ($answer == "") {echo "{\"connected\": false}";}
	else {echo $answer;}
}
catch (Exception $e) {
	echo "{\"connected\": false}";
}


?>