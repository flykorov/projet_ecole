<template>

	<div class="rectangle2">
		<div class="texte">Configuration</div>
		<div class="config">
			<input type ="text" id="size" name="size" placeholder="nombre de carte" value=""/>
			<input type ="text" id="timer" name="timer" placeholder="temps memorisation" value=""/>
			<input type="text" id="timer4" name="timer4" placeholder="temps jeu" value="">
			<input type="text" id="heart" name="heart" placeholder="nombre de coeur" value=""/>
			<button class="btn" id="submit" v-on:click="showBut">Play</button>
		</div>
	</div>

	<div id="keurs" class="keur" style="display: none;"></div>

	<div id=textTimer1></div>
	<div id="timer2"></div>
	<div id="textTimer2"></div>
	<div id="timer3"></div>
	<div id="bonne"></div>
	<div id="mauvaise"></div>

	<div class="top-buttons" style="display: none;">
		<button class="btn" id="btn2" v-on:click="restart">Restart</button>
	</div>
	
	<ul id="gaming" class="flex-container" ref="jeuImage">
		<GameCard v-for="(imageId, index) in jeu" v-bind:key="index" v-bind:image-id="imageId" v-bind:card-id="index" @image-cliked="showCa"/>
	</ul>

	<div class="rectangle3" style="display: none;">
		<div class="texte">ez win</div>
	</div>

	<div class="rectangle4" style="display: none;">
		<div class="texte">noob</div>
	</div>
</template>

<script>
import GameCard from './GameCard.vue'

export default {
	name: 'GamePlay',
	components: {
		GameCard
	},
	data() {
		return {
			temps_jeu: 10,
			temps_jeu_restant: 10,
			time: 20,
			temps_restant: this.time,
			vie: 3,
			vie_restant: 3,
			bonne_reponse: 0,
			mauvaise_reponse: 0,
			verif:[[-1, -1], [-1, -1]],
			indice: 0,
			taille: 10,
			jeu: [],
			matthis: [],
			fin: false,
			perdu: false,
			nb_image: 50,
			idHidden: 0,
			lien: [
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
			],
		}
	},
	methods: {

		init_tab() {
			for(let i=0; i<this.taille*2; i++) {
				this.jeu.push(-1)
				this.matthis.push(0)
			}
		},

		matthisA0() {

			this.jeu = []
			this.matthis = []

			this.verif[0][0]=-1
			this.verif[1][0]=-1
			this.verif[0][1]=-1
			this.verif[1][1]=-1
			for(let i=0; i<parseInt(this.vie); i++) {
				document.getElementsByTagName("img").item(i).setAttribute("src", "image/coeur.jpeg")
			}
			this.vie_restant = this.vie
			this.bonne_reponse = 0
			this.mauvaise_reponse = 0

			
		},

		shuffle() {
			this.init_tab()
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
		},

		play() {

			for(let i=0; i<this.taille*2; i++) {
				var x = document.getElementsByTagName("img").item(i+parseInt(this.vie))
				x.setAttribute("src", this.lien[this.jeu[i]])
			}
		},

		hidden() {
			for(let i=0; i<this.taille*2; i++) {
				var x = document.getElementsByTagName("img").item(i+parseInt(this.vie));
				x.setAttribute("src", "image/pourquoi.jpeg");
			}
		},

		victoire() {
			for(var i=0; i<this.taille*2; i++) {
				if(this.matthis[i]==0)
					return false;
				}
			return true;
		},

		defaite() {
			if(this.vie_restant == 0 || this.temps_jeu_restant == 0)
				return true;
			return false;
		},

		verifier(i) {
			this.verif[0][this.indice]=this.lien[this.jeu[i]];
			this.verif[1][this.indice]=i;
			this.indice++;
			if(this.indice == 2) {
				if(this.verif[0][0] != this.verif[0][1]) {
					document.getElementById("i"+this.vie_restant).setAttribute("src", "");

					this.vie_restant--;
					this.mauvaise_reponse++;

					if(this.vie_restant!=0) {
						setTimeout(() => {
							let cache = document.getElementsByTagName("img").item(this.verif[1][0]+parseInt(this.vie));
							cache.setAttribute("src", "image/pourquoi.jpeg");
							// cache.setAttribute("onclick", "game.showCase("+this.verif[1][0]+")");
							cache = document.getElementsByTagName("img").item(this.verif[1][1]+parseInt(this.vie));
							cache.setAttribute("src", "image/pourquoi.jpeg");
							// cache.setAttribute("onclick", "game.showCase("+this.verif[1][1]+")");
						}, 1000);
					}
					setTimeout(() => {
						this.verif[0][0] = -1;
						this.verif[1][0] = -1;
						this.verif[1][0] = -1;
						this.verif[1][1] = -1;
					}, 1001)
					
				}else {
					// let laisser = document.getElementsByTagName("img").item(this.verif[1][0]+3);
					// // laisser.removeAttribute("onclick");
					// laisser = document.getElementsByTagName("img").item(this.verif[1][1]+3);
					// // laisser.removeAttribute("onclick");
					this.matthis[this.verif[1][0]] = 1;
					this.matthis[this.verif[1][1]] = 1;
					this.bonne_reponse++;
					this.verif[0][0] = -1;
					this.verif[1][0] = -1;
					this.verif[1][0] = -1;
					this.verif[1][1] = -1;
				}
			}

			document.getElementById("mauvaise").innerText="mauvaise reponse "+this.mauvaise_reponse;
			document.getElementById("bonne").innerText="bonne reponse "+this.bonne_reponse;

			this.indice %= 2;
			this.fin = this.victoire();
			this.perdu = this.defaite();
		},

		fin_du_jeu() {
			document.getElementById("gaming").style.display = "none";

			// while(list.firstChild) {
			// 	list.removeChild(list.firstChild);
			// }

			if(this.fin)
				document.querySelector(".rectangle3").style.display = "block";
			else
				document.querySelector(".rectangle4").style.display = "block";
		},

		showCa(id) {
			const image = document.getElementById("card"+id)
			if(this.matthis[id]==0) {
				if(this.verif[1][0]!=id) {
					image.setAttribute("src", this.lien[this.jeu[id]])
					this.verifier(id)
					if(this.fin || this.perdu) {
						this.fin_du_jeu()
					}
				}else {
					this.verif[1][0]=0
					this.indice--
					image.setAttribute("src", "image/pourquoi.jpeg")
				}
			}
		},

		hiddenCa() {
			for(let i=0; i<this.taille*2; i++){
				const image = document.getElementById("card"+this.jeu[i]);
				image.setAttribute("src", "image/pourquoi.jpeg");
			}

			
			// image.addEventListener("click", () => this.showCa(id));
			// image.setAttribute("v-on:click", `showCa(${id})`);
		},

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
		},

		timerjeu() {
			const tim = document.getElementById("timer3");
			this.idTimerJeu = setInterval(() => {
				tim.innerText = this.temps_jeu_restant-1;
				if(this.temps_jeu_restant != 0)
					this.temps_jeu_restant--;
				else {
					clearInterval(this.idTimerJeu);
					tim.innerText = "";
				}
			}, 1000);
		},


		initialisation() {
			document.getElementById("gaming").style.display = "flex";
			document.getElementById("textTimer1").innerText="debut du jeu dans :"
			document.getElementById("textTimer2").innerText="temps restant :"

			document.getElementById("mauvaise").innerText="mauvaise reponse "+this.mauvaise_reponse
			document.getElementById("bonne").innerText="bonne reponse "+this.bonne_reponse
			//this.init()

			this.shuffle()
			
			this.timer()

			//this.play()
			//this.idHidden = setTimeout(() => {this.play()}, 1000 * this.time)


			this.idHidden = setTimeout(() => {
				this.hidden()
				this.timerjeu()
			}, 1000 * this.time)
			// this.idHidden = setTimeout(() => {this.jeu = []}, 2000 * this.time)
			
		},

		restart() {
			document.querySelector(".rectangle3").style.display = "none";
			document.querySelector(".rectangle4").style.display = "none";
			this.matthisA0();
			clearInterval(this.idInter);
			clearInterval(this.idHidden);
			clearInterval(this.idTimerJeu);
			this.temps_restant = this.time;
			this.temps_jeu_restant = this.temps_jeu;
			this.initialisation();
		},

		showBut() {
			var size = 0;
			var t = 0;
			var c = 0;
			var tplay = 0;
			size = document.getElementById("size").value;
			t = document.getElementById("timer").value;
			c = document.getElementById("heart").value;
			tplay = document.getElementById("timer4").value;

			if(size>0 && t>0 && c>0 && tplay>0) {
				this.taille = size;
				this.time = t;
				this.temps_restant = t;
				this.temps_jeu = tplay;
				this.temps_jeu_restant = tplay;
				this.vie = c;
				this.vie_restant = c;
				const k = document.getElementById("keurs")
				for(let i=0; i<c; i++) {
					var img = document.createElement("img");
					let r = i+1;
					img.setAttribute("id", "i"+r);
					img.setAttribute("class", "image");
					img.setAttribute("src", "image/coeur.jpeg");
					k.appendChild(img);
				}
				document.querySelector(".config").style.display = "none";
				document.querySelector(".rectangle2").style.display = "none";
				document.querySelector(".top-buttons").style.display = "block";
				document.querySelector(".keur").style.display = "flex";
				this.initialisation();
			}
		},
	}
}
</script>