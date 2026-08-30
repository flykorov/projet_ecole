//import * as tf from 'https://cdn.jsdelivr.net/npm/@tensorflow/tfjs';
//import {loadGraphModel} from 'http://localhost:8080/node_modules/@tensorflow/tfjs'
//const fetch = require('node-fetch');
//global.fetch = fetch;


var res_url = {
	".": 0,
	"-": 0,
	"_": 0,
	"/": 0,
	"?": 0,
	"=": 0,
	"@": 0,
	"&": 0,
	"!": 0,
	" ": 0,
	"~": 0,
	",": 0,
	"+": 0,
	"*": 0,
	"#": 0,
	"$": 0,
	"%": 0
};

var domaine = {
	".": 0,
	"-": 0,
	"_": 0,
	"/": 0,
	"?": 0,
	"=": 0,
	"@": 0,
	"&": 0,
	"!": 0,
	" ": 0,
	"~": 0,
	",": 0,
	"+": 0,
	"*": 0,
	"#": 0,
	"$": 0,
	"%": 0
};

var directory = {
	".": 0,
	"-": 0,
	"_": 0,
	"/": 0,
	"?": 0,
	"=": 0,
	"@": 0,
	"&": 0,
	"!": 0,
	" ": 0,
	"~": 0,
	",": 0,
	"+": 0,
	"*": 0,
	"#": 0,
	"$": 0,
	"%": 0
};

var file = {
	".": 0,
	"-": 0,
	"_": 0,
	"/": 0,
	"?": 0,
	"=": 0,
	"@": 0,
	"&": 0,
	"!": 0,
	" ": 0,
	"~": 0,
	",": 0,
	"+": 0,
	"*": 0,
	"#": 0,
	"$": 0,
	"%": 0
};


var params = {
	".": 0,
	"-": 0,
	"_": 0,
	"/": 0,
	"?": 0,
	"=": 0,
	"@": 0,
	"&": 0,
	"!": 0,
	" ": 0,
	"~": 0,
	",": 0,
	"+": 0,
	"*": 0,
	"#": 0,
	"$": 0,
	"%": 0
};

function put_0(dico) {
	for(let i=0; i<char.length; i++) {
		dico[char[i]] = 0;
	}
}

var char = [".", "-", "_", "/", "?", "=", "@", "&", "!", " ", "~", ",", "+", "*", "#", "$", "%"];

var url = "https://nodejs.org/en";

function obtenirurl(){
    var textareaElement = document.getElementById("monTexte");
    var contenuTextarea = textareaElement.value;
    // console.log(contenuTextarea);
    url=contenuTextarea;
	runModel();
    
}

function compterOcc(phrase, dico) {
	length = phrase.length
	for(let i=0; i<length; i++) {
		for(let j=0; j<char.length; j++) {
			if(char[j] == phrase[i]) {
				dico[char[j]]++;
			}
		}
	}
}


function merge(taille, res, dico) {
	for(let j=0; j<char.length; j++) {
		res.push(dico[char[j]]);
	}

	if(taille == 0) {
		res.push(-1);
	}else
	{
		res.push(taille);
	}
}

var URL_ = {
	domaine:undefined,
	directory:undefined,
	file:undefined,
	params:undefined

};

function decouper(url, p) {
	// console.log(url);
	let domaine, directory = '', file, params;
	url = url.split('://');

	url = url[1].split('/');
	domaine = url[0];

	if(p.pathname.length > 0 && p.pathname != '/') {
		for(let i=1; i<url.length-1; i++) {
			directory += '/' + url[i];
		}

		url = url[url.length-1];

		url = url.split('?');

		file = '/' + url[0] + '?';

		if(p.search.length > 0) {
			params = url[1];
		}
	}

	// console.log(domaine, directory, file, params);
	URL_.domaine = domaine;
	URL_.directory = directory;
	URL_.file = file;
	URL_.params = params;

}



async function runModel() {
	put_0(params);
	put_0(res_url);
	put_0(domaine);
	put_0(directory);
	put_0(file);
	var parsedURL = new URL(url);

	var res = [];

	// console.log(parsedURL);

	decouper(url, parsedURL);

	// console.log(URL_);


	if(URL_.domaine != undefined) {
		compterOcc(URL_.domaine, domaine);
	} else
	{
		for(let i=0; i<char.length; i++) {
			domaine[char[i]]=-1;
		}
	}

	if(URL_.directory != undefined) {
		compterOcc(URL_.directory, directory);
	} else
	{
		for(let i=0; i<char.length; i++) {
			directory[char[i]]=-1;
		}
	}

	if(url.length != 0) {
		compterOcc(url, res_url);
	} else
	{
		for(let i=0; i<char.length; i++) {
			res_url[char[i]]=-1;
		}
	}

	if(URL_.file != undefined) {
		compterOcc(URL_.file, params);
	} else
	{
		for(let i=0; i<char.length; i++) {
			file[char[i]]=-1;
		}
	}

	if(URL_.params != undefined) {
		compterOcc(URL_.params, params);
	} else
	{
		for(let i=0; i<char.length; i++) {
			params[char[i]]=-1;
		}
	}



	if(url.length != 0) {
		merge(url.length, res, res_url);
	}else {
		merge(0, res, res_url);
	}

	if(URL_.domaine != undefined) {
		merge(URL_.domaine.length, res, domaine);
	}else {
		merge(0, res, domaine);
	}

	if(URL_.directory != undefined) {
		merge(URL_.directory.length, res, directory);
	}else {
		merge(0, res, directory);
	}

	if(URL_.file != undefined) {
		merge(URL_.file.length, res, file);
	}else {
		merge(0, res, file);
	}

	if(URL_.params != undefined) {
		merge(URL_.params.length, res, params);
	}else {
		merge(0, res, params);
	}


	res_fin = [];

	res_fin.push(res);
	var per = 0.4;

	var resultat;

	const requestOptions = {
	  method: 'POST',
	  headers: { 'Content-Type': 'application/json' },
	  body: JSON.stringify(res_fin) // Convertir la matrice en JSON et l'envoyer dans le corps de la requête
	};

	await fetch('http://localhost:3000/execute', requestOptions)
    .then(response => response.text())
    .then(data => {
    	resultat = data
    	//console.log(data)
    	}
    )
    .catch(error => console.error('Error:', error));


	// console.log(resultat);
	
	per = resultat.match(/\d+\.\d+/)[0];


	//model.predict(res_fin);
	// console.log(res_fin);
	// console.log(per);
	var zoneDeDepotElement = document.getElementById("zoneDeDepot");
	if(per>0.7){
        
        zoneDeDepotElement.innerHTML = "Phising detected : " + (per *100).toFixed(2) + " %";
        zoneDeDepotElement.style.backgroundColor = "red";

    }
    else if(per>0.4){
        zoneDeDepotElement.innerHTML = "Suspicion of phising detected : " + (per *100).toFixed(2) + " %";;
        zoneDeDepotElement.style.backgroundColor = "orange";
    }
    else{
        zoneDeDepotElement.innerHTML = "No phising detected : " + (per *100).toFixed(2) + " %";;
        zoneDeDepotElement.style.backgroundColor = "green";
    }

}
