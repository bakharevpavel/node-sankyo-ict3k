const ict3k = require('./build/Release/sankyo-ict3k.node');
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