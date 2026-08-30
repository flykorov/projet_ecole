let compteur = {
	j1: 0,
	ordi: 0,
	egalite: 0,
};

function jouer(choix) {
	const ordi = Math.floor(Math.random() * 3);

	let ordiString;
	if (ordi === 0) {
		ordiString = 'r';
	} else if (ordi === 1) {
		ordiString = 'p';
	} else {
		ordiString = 'c';
	}

	let j1 = choix;
	let j2 = ordiString;

	let resultat;

	if(j1==j2) {
		resultat = "egalite";
		compteur.egalite += 1;
	}else {



		switch(j1) {
			case 'r':
				switch(j2) {
					case 'c':
						resultat = "joueur";
						compteur.j1 +=1;
						break;
					case 'p':
						resultat = "ordi";
						compteur.ordi += 1;
						break;
				}
				break;
			case 'p':
				switch(j2) {
					case 'c':
						resultat = "ordi";
						compteur.ordi += 1;
						break;
					case 'r':
						resultat = "joueur";
						compteur.j1 +=1;
						break;
				}
				break;
			case 'c':
				switch(j2) {
					case 'r':
						resultat = "ordi";
						compteur.ordi += 1;
						break;
					case 'p':
						resultat = "joueur";
						compteur.j1 +=1;
						break;
					default:
				}
				break;
			}
		}

	document.getElementById("resultat").innerHTML = "resultat : " + resultat;
	document.getElementById("j1").innerHTML = "joueur : " + compteur.j1;
	document.getElementById("j2").innerHTML = "ordi : " + compteur.ordi;
	document.getElementById("egalite").innerHTML = "egalite : " + compteur.egalite;

}