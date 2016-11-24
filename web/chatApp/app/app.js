// app.js

var express = require('express'),
  mongoose = require('mongoose'),
  app = express(),
  server = require('http').Server(app),
  io = require('socket.io')(server),
  path = require('path'),
  cookieParser = require('cookie-parser'),
  bodyParser = require('body-parser');

var routes = require('./routes');

var app = express();

mongoose.connect("mongodb://localhost:27017/chatApp");

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

app.use(bodyParser.json());
app.use(bodyParser.urlencoded());
app.use(cookieParser());
app.use(express.static(path.join(__dirname, '/public')));  // tell express where to serve static files from

app.get('/', routes.index);


// create a schema for chat
var ChatSchema = mongoose.Schema({
	created: Date,
	content: String,
	username: String,
	room: String
});

// create a model from the chat schema
var chat = mongoose.model('Chat', ChatSchema);

// allow CORS
app.all('*', function(req, res, next) {
	res.header("Access-Control-Allow-Origin", "*");
	res.header("Access-Control-Allow-Methods", 'GET,PUT,POST,DELETE,OPTIONS');
	res.header("Access-Control-Allow-Headers", 'Content-type,Accept,X-Access-Token,X-Key');
	if(req.method=='OPTIONS') {
		res.status(200).end();
	} else {
		next();
	}
});


// =======================================Routes========================================
// route for our index file
app.get('/', function(req, res) {
	// send the index.html in our public directory
	res.sendfile('index.html');
});

// This route is simply run only on first launch just to generate some chat history
app.post('/setup', function(req, res) {
	// Array of chat data. Each object properties must match the schema object properties
	var chatData = [{
		created: new Date(),
		content: 'Hola',
		username: 'Amigo',
		room: 'MEAN'
	},{
			created: new Date(),
			content: 'Hello',
			username: 'Obama',
			room: 'laravel'
		}, {
			created: new Date(),
			content: 'Ait',
			username: 'Putin',
			room: 'Socket.io'
		}];
		// Loop through each of the chat data and insert into the db
		for( var c = 0; c < chatData.length ; c++){
			// Create an instance of the chat model
			var newChat = new Chat(chatData[c]);
			// Call save to insert the chat
			newChat.save(function(err, savedChat){
				console.log(savedChat);
			});
		}

		//send a response so that the server wouldn't get stuck
		res.send('created');
});

// This route produces a list of chat as filtered by 'room' query
app.get('/msg', function(req, res) {
	// find
	Chat.find({
		'room': req.query.room.toLowerCase()
	}).exec(function(err, msgs) {
		// send
		res.json(msgs);
	});
});

// ===========================================END ROUTES========================================================
// ==============================================Socket==========================================================
// Listen for connection
io.on('connection', function(socket) {
	// Globals
	var defaultRoom = 'general';
	var rooms = ['general', 'angular', 'socket.io', 'express', 'node', 'mongo', 'php', 'laravel'];

	// Emit the rooms array
	socket.emit('setup', {
		rooms: rooms
	});

	// Listens for new user
	socket.on('new user', function(data) {
		data.room = defaultRoom;

		// New user joins the default room
		socket.join(defaultRoom);

		// Tell all those in the room that a new user joined 
		io.in(defaultRoom).emit('user joined', data);
	});

	// Listen for switch rooms
	socket.on('switch room', function(data) {
		// Handles joining and leaving rooms
		// console.log(data);
		socket.leave(data.oldRoom);
		socket.join(data.newRoom);
		io.in(data.oldRoom).emit('user left', data);
		io.in(data.newRoom).emit('user joined', data);
	});

	// Listens for a new chat message
	socket.on('new message', function(data) {
		// Create message
		var newMsg = new Chat({
			username: data.username,
			content: data.message,
			room: data.room.toLowerCase(),
			created: new Date()
		});
		// Save it to database
		newMsg.save(function(err, msg){
			// send messages to those connected in the room
			io.in(msg.room).emit('message Created', msg);
		});
	});
});
//==========================================END SOCKET====================================================





app.set('port', process.env.PORT || 3000);

var server = app.listen(app.get('port'), function() {
	// log a message to console!
	console.log('Magic Mike at ' + port);
});

module.exports = app;
