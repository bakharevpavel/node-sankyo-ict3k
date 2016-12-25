# sankyo-ict3k

Sankyo ICT3K5 library wrapper for Node.js. Should work with their ICT3K5/ICT3k7 card readers.

## Installation

```sh

$ npm install sankyo-ict3k

```

## Methods

### .connect(object, callback)

Establishes connection with the card reader. Object containing port, baud rate fields should be passed to the method. Callback (optional) is executed after finishing connection attempt. Result of the operation is passed to the callback as an argument.

```js

	// object example
	{
		port: "COM4",
		baudRate: 115200
	}

```

### .exec(object, callback)

Sends command to the connected device. Accepts object as an argument. Object contains command, parameter and data (optional) fields. Executes callback (optional) after finishing a command and passes result as an argument.

```js

	// object example
	{
    	command: 0x30,
    	parameter: 0x30,
    	data: [0x33, 0x32, 0x34, 0x31, 0x30, 0x30, 0x31, 0x30, 0x30, 0x30]
	}

```
### .disconnect()

Disconnects from the device.

## Example usage

```js

const ict3k = require('sankyo-cardreader');
ict3k.connect({port: "COM4", baudRate: 115200}, function(res) { // connect do the device
	console.log(res);
	ict3k.exec({
    	command: 0x30,
    	parameter: 0x30,
    	data: [0x33, 0x32, 0x34, 0x31, 0x30, 0x30, 0x31, 0x30, 0x30, 0x30]	// init connection
	},function(res) {
		console.log(res);
		ict3k.exec({ // set color green
    	    command: 0x35,
    	    parameter: 0x31,
		}, function() {
			ict3k.exec({ // set color red
    		    command: 0x35,
    		    parameter: 0x32,
			}, function(res) {
				console.log(res);
				ict3k.disconnect(); // disconnect device
			});
		});
	});
});

```

## License

This is only a wrapper for Sankyo's publicly distributed ICT3K_6240 library. All rights for the library belong to Sankyo company and other respective owners.