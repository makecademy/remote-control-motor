// Module
var express = require('express');
var app = express();

// Define port
var port = 3000;

// View engine
app.set('view engine', 'jade');

// Set public folder
app.use(express.static(__dirname + '/public'));

// Serve interface
app.get('/', function(req, res){
  res.render('dashboard');
});

// Rest
var rest = require("arest")(app);

//rest.addDevice('http','arduino.local');
//rest.addDevice('http','bathroom.local');
rest.addDevice('serial','/dev/tty.usbmodem1a12121',115200);

rest.heartBeat(10000);

// Start server
app.listen(port);
console.log("Listening on port " + port);
