class Game {
	constructor(taille) {
		this.time = 20
		this.temps_restant = this.time
		this.vie = 3;
		this.bonne_reponse = 0;
		this.mauvaise_reponse = 0;
		this.verif = [[0, 0], [0, 0]];
		this.indice = 0;
		this.taille = taille;
		this.jeu = [];
		this.matthis = [];
		this.fin = false;
		this.perdu = false;
		this.nb_image = 50;
		for(var i=0; i<taille*2; i++) {
			this.jeu.push(-1);
			this.matthis.push(0);
		}
	}

	matthisA0() {
		for(var i=0; i<this.taille*2; i++) {
			this.matthis[i]=0;
		}
		this.verif[0][0]=0;
		this.verif[1][0]=0;
		this.verif[0][1]=0;
		this.verif[1][1]=0;
		for(var i=0; i<3; i++) {
			document.getElementsByTagName("img").item(i).setAttribute("src", "image/coeur.jpeg");

		}
		this.vie = 3;
		this.bonne_reponse = 0;
		this.mauvaise_reponse = 0;
	}

	init() {
		const list = document.getElementById("game");

		while(list.firstChild) {
			list.removeChild(list.firstChild);
		}
		this.shuffle();

		var ul = document.getElementById("game");

		for(var i=0; i<this.taille*2; i++) {
			var li = document.createElement("li");
			li.setAttribute("class", "flex-item");
			var img = document.createElement("img");

			img.setAttribute("id", "item"+i);
			img.setAttribute("onclick", "game.showCase("+i+")");
			img.setAttribute("class", "image");
			img.setAttribute("width", "100%");
			img.setAttribute("height", "100%");
			li.appendChild(img);

			ul.appendChild(li);
		}
	}

	shuffle() {
		for(let i=0; i<this.taille*2; i=i+2) {
			var a = Math.floor(Math.random() * this.nb_image);
			while(this.jeu.includes(a)) {
				a = Math.floor(Math.random() * this.nb_image);
			}
			this.jeu[i]=a;
			this.jeu[i+1]=a;
		}

		for(let i=this.taille*2-1; i>0; i--) {
			let a = Math.floor(Math.random() * (i));
			[this.jeu[i], this.jeu[a]] = [this.jeu[a], this.jeu[i]];
		}


	}

	play() {

		for(var i=0; i<this.taille*2; i++) {
			var x = document.getElementsByTagName("img").item(i+3);
			x.setAttribute("src", lien[this.jeu[i]]);
		}
	}

	hidden() {

		for(var i=0; i<this.taille*2; i++) {
			var x = document.getElementsByTagName("img").item(i+3);
			x.setAttribute("src", "image/pourquoi.jpeg");
		}
	}

	victoire() {
		for(var i=0; i<this.taille*2; i++) {
			if(this.matthis[i]==0)
				return false;
		}
		return true;
	}

	defaite() {
		if(this.vie == 0)
			return true;
		return false;
	}

	verifier(i) {
		this.verif[0][this.indice]=lien[this.jeu[i]];
		this.verif[1][this.indice]=i;
		this.indice++;
		if(this.indice == 2) {
			if(this.verif[0][0] != this.verif[0][1]) {
				document.getElementById("i"+this.vie).setAttribute("src", "");
				this.vie--;
				this.mauvaise_reponse++;
				if(this.vie!=0) {
					setTimeout(() => {
						let cache = document.getElementsByTagName("img").item(this.verif[1][0]+3);
						cache.setAttribute("src", "image/pourquoi.jpeg");
						cache.setAttribute("onclick", "game.showCase("+this.verif[1][0]+")");
						cache = document.getElementsByTagName("img").item(this.verif[1][1]+3);
						cache.setAttribute("src", "image/pourquoi.jpeg");
						cache.setAttribute("onclick", "game.showCase("+this.verif[1][1]+")");
					}, 1000);
				}
				
				
			}else {
				let laisser = document.getElementsByTagName("img").item(this.verif[1][0]+3);
				laisser.removeAttribute("onclick");
				laisser = document.getElementsByTagName("img").item(this.verif[1][1]+3);
				laisser.removeAttribute("onclick");
				this.matthis[this.verif[1][0]] = 1;
				this.matthis[this.verif[1][1]] = 1;
				this.bonne_reponse++;
			}
		}

		document.getElementById("mauvaise").innerText="mauvaise reponse "+this.mauvaise_reponse;
		document.getElementById("bonne").innerText="bonne reponse "+this.bonne_reponse;

		this.indice %= 2;
		this.fin = this.victoire();
		this.perdu = this.defaite();
	}

	fin_du_jeu() {
		const list = document.getElementById("game");

		while(list.firstChild) {
			list.removeChild(list.firstChild);
		}

		if(this.fin)
			document.querySelector(".rectangle3").style.display = "block";
		else
			document.querySelector(".rectangle4").style.display = "block";



	}

	showCase(id) {
		const image = document.getElementById("item"+id);
		image.setAttribute("src", lien[this.jeu[id]]);
		image.setAttribute("onclick", "game.hiddenCase("+id+")");
		this.verifier(id);
		if(this.fin || this.perdu) {
			this.fin_du_jeu();
		}

	}

	hiddenCase(id) {
		const image = document.getElementById("item"+id);
		image.setAttribute("src", "image/pourquoi.jpeg");
		image.setAttribute("onclick", "game.showCase("+id+")");
	}

	timer() {
		const tim = document.getElementById("timer2");
		this.idInter = setInterval(() => {
			tim.innerText = this.temps_restant-1;
			if(this.temps_restant != 0)
				this.temps_restant--;
			else {
				clearInterval(this.idInter);
				tim.innerText = "";
			}
		}, 1000);
	}

}

const game = new Game(10);
let idHidden;

function initialisation() {
	game.init();
	game.timer();
	game.play();
	idHidden = setTimeout(() => {game.hidden()}, 1000 * game.time);
}

function restartv2() {
	document.querySelector(".rectangle3").style.display = "none";
	document.querySelector(".rectangle4").style.display = "none";
	game.matthisA0();
	clearInterval(game.idInter);
	clearInterval(idHidden);
	game.temps_restant = game.time;
	initialisation();
}

function restart() {
	game.init();
	game.timer();
}

function play() {
	game.play();
}

function cacher() {
	game.hidden();
}

function showButtons() {
	var size = 0;
	var t = 0;
	var size = document.getElementById("size").value;
	var t = document.getElementById("timer").value;

	if(size!=0 && t!=0) {
		game.taille = size;
		game.time = t;
		game.temps_restant = t;
		document.querySelector(".config").style.display = "none";
		document.querySelector(".rectangle2").style.display = "none";
		document.querySelector(".top-buttons").style.display = "block";
		document.querySelector(".keur").style.display = "block";
		initialisation();
	}
}

function init() {
	game.init();
}


let lien = [
	"image/0.jpeg",
	"image/1.jpeg",
	"image/2.jpeg",
	"image/3.jpeg",
	"image/4.jpeg",
	"image/5.jpeg",
	"image/6.jpeg",
	"image/7.jpeg",
	"image/8.jpeg",
	"image/9.jpeg",
	"image/10.jpeg",
	"image/11.jpeg",
	"image/12.jpeg",
	"image/13.jpeg",
	"image/14.jpeg",
	"image/15.jpeg",
	"image/16.jpeg",
	"image/17.jpeg",
	"image/18.jpeg",
	"image/19.jpeg",
	"image/20.jpeg",
	"image/21.jpeg",
	"image/22.jpeg",
	"image/23.jpeg",
	"image/24.jpeg",
	"image/25.jpeg",
	"image/26.jpeg",
	"image/27.jpeg",
	"image/28.jpeg",
	"image/29.jpeg",
	"image/30.jpeg",
	"image/31.jpeg",
	"image/32.jpeg",
	"image/33.jpeg",
	"image/34.jpeg",
	"image/35.jpeg",
	"image/36.jpeg",
	"image/37.jpeg",
	"image/38.jpeg",
	"image/39.jpeg",
	"image/40.jpeg",
	"image/41.jpeg",
	"image/42.jpeg",
	"image/43.jpeg",
	"image/44.jpeg",
	"image/45.jpeg",
	"image/46.jpeg",
	"image/47.jpeg",
	"image/48.jpeg",
	"image/49.jpeg",
	"image/50.jpeg",
]

let tab =
[
	"0",
	"1",
	"2",
	"3",
	"4",
	"5",
	"6",
	"7",
	"8",
	"9",
	"10",
	"11",
	"12",
	"13",
	"14",
	"15",
	"16",
	"17",
	"18",
	"19",
	"20",
	"21",
	"22",
	"23",
	"24",
	"25",
	"26",
	"27",
	"28",
	"29",
	"30",
	"31",
	"32",
	"33",
	"34",
	"35",
	"36",
	"37",
	"38",
	"39",
	"40",
	"41",
	"42",
	"43",
	"44",
	"45",
	"46",
	"47",
	"48",
	"49",
	"50"
]