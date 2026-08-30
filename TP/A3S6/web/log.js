function logMessage(funcName, severity, message) {
	return `$(funcName) - $(severity) - $(message)`;
}

function lauch(spacecraft) {
	return `Starting launch for ${spacecraft.name} from ${spacecraft.base}`;
}

const spacecraft3 = {
	name: "Ariane6",
	version: "6",
	height: 63,
	base: "Kourou",
	launch: function() {
		console.log(`Starting launch for ${this.name} from ${this.base}`);
	}
};

// 0 papier
// 1 cizo
// 2 caillou

function pierfeuilcizo(j1, j2) {

	if(j1==j2) {
		console.log("egalite");
	}

	switch(j1) {
		case 'r':
			switch(j2) {
				case 'c':
					console.log("j1 gagne");
					break;
				case 'p':
					console.log("j2 gagne");
					break;
				default:
					console.log("j2 a pas mis de bon argument");
			}
			break;
		case 'p':
			switch(j2) {
				case 'c':
					console.log("j2 gagne");
					break;
				case 'r':
					console.log("j1 gagne");
					break;
				default:
					console.log("j2 a pas mis de bon argument");
			}
			break;
		case 'c':
			switch(j2) {
				case 'r':
					console.log("j2 gagne");
					break;
				case 'p':
					console.log("j1 gagne");
					break;
				default:
					console.log("j2 a pas mis de bon argument");

			}
			break;
		default:
			console.log("j1 a pas mis de bon argument");
	}
}