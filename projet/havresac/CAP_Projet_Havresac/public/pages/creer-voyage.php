<?php
    $host = 'localhost';
    $dbname = 'voyage';
    $user = 'root';
    $password = '';

    try {
        $pdo = new PDO("mysql:host=$host;dbname=$dbname", $user, $password);
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    } catch (PDOException $e) {
        die("Erreur de connexion à la base de données: " . $e->getMessage());
    }

    // Récupérer les bagages
    $sql_bagages = "SELECT * FROM bagage WHERE parent_id IS NULL";
    $bagages = $pdo->query($sql_bagages)->fetchAll(PDO::FETCH_ASSOC);

    // Récupérer les voyages
    $sql_voyages = "SELECT * FROM voyage";
    $voyages = $pdo->query($sql_voyages)->fetchAll(PDO::FETCH_ASSOC);
    $voyages_assoc = [];
    foreach ($voyages as $voyage) {
        $voyages_assoc[$voyage['id']] = $voyage['lieu'];
    }

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Création de Voyage</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css" />
    <link href="https://fonts.googleapis.com/css2?family=Jua&display=swap" rel="stylesheet">
    <style>
        /* Cible la scrollbar */
    ::-webkit-scrollbar {
      width: 12px; /* Largeur de la barre de défilement */
      height: 12px; /* Hauteur de la barre de défilement (pour les défilements horizontaux) */
    }

    /* Cible le "pouce" de la scrollbar (partie mobile) */
    ::-webkit-scrollbar-thumb {
      background-color: #5276A6; /* Couleur du pouce */
      border-radius: 10px; /* Arrondir les bords du pouce */
    }

    /* Cible la piste de la scrollbar (arrière-plan) */
    ::-webkit-scrollbar-track {
      background: #F6F2E6; /* Couleur de la piste */
      border-radius: 10px; /* Arrondir les bords de la piste */
    }

    /* Appliquer le style à un div défilant */
    .scrollable {
      width: 300px;
      height: 300px;
      overflow: scroll;
    }
    </style>
</head>
<header style="background-color: #00558C;
    padding: 5px 10px;
    position: fixed;
    color: white;
    top: 0;
    left: calc((100vw - 1500px) / 2);
    right: 0;
    display: flex;
    justify-content: space-between;
    align-items: center;
    z-index: 1000;
    height: 111px;
    width: 1500px;
    box-sizing: border-box;
    font-size : 25;">  <!-- Ajouté pour inclure padding dans la largeur -->
    
    <div class="button-container" style="flex: 1; display: flex; justify-content: flex-start;">
    <button id="btn-accueil" onclick="window.location.href='../index.php'" style="font-family: 'Jua', sans-serif; background-color: transparent; border: none; color: white; cursor: pointer;margin-left: 50px;">
    <i class="fas fa-arrow-left" style=" font-size: 30px;"></i>
    </button>
</div>
    
    <div style="flex: 1; text-align: center;">
        <h1 style="font-family: 'Jua', sans-serif; margin: 0;font-size: 50px;">CREATION DE VOYAGE</h1>
    </div>
    
    <div style="flex: 1;">
    </div>
</header>

<body style="background-color: #FFFFFF;">
<div class="CreationBagage" style="width: 1500px; height: 1000px; left:calc((100vw - 1500px) / 2); position: fixed; background: url('../Images/creation-voyage.png') no-repeat center center; background-size: cover;">
    <div id="app-root" class="voyage">
    <form id="ajouterVoyage" action="../tables/voyages/ajouter_voyage.php" method="POST" onsubmit="return validateDates()">
        <label style="font-size: 40px; width: 200px; height: 40px; left: 723px; top:250px; position: absolute; background: #F6F2E6; color: black; font-family: 'Jua', sans-serif; justify-content: center; align-items: center; text-align: center;">DATES</label>

        <label for="date_debut" style="font-size: 40px; width: 200px; height: 40px; left: 600px; top:350px; position: absolute; background: #F6F2E6; color: black; font-family: 'Jua', sans-serif; justify-content: center; align-items: center; text-align: center;">DEBUT</label>
        <input type="date" id="date_debut" name="date_debut" min="<?= date('Y-m-d'); ?>" required style="font-size: 25px; width: 200px; height: 40px; left: 600px; top:425px; position: absolute; background: #EEE5C9; color: black; font-family: 'Jua', sans-serif; justify-content: center; align-items: center; text-align: center;" oninput="clearError()">
        <div id="error_date_debut" style="font-size: 18px; color: white; height: 30px; background-color: #f44336; margin-top: 5px; width: 432px; border-radius: 5px; position: absolute; top: 465px; left: 600px; display: none; justify-content: center; align-items: center; z-index: 1000;">
            <i class="fas fa-exclamation-triangle" style="margin-right: 10px;"></i> La date de début est supérieure à la date de fin!
        </div>
        <br><br>

        <label for="date_fin" style="font-size: 40px; width: 200px; height: 40px; left: 830px; top:350px; position: absolute; background: #F6F2E6; color: black; font-family: 'Jua', sans-serif; justify-content: center; align-items: center; text-align: center;">FIN</label>
        <input type="date" id="date_fin" name="date_fin" min="<?= date('Y-m-d'); ?>" required style="font-size: 25px; width: 200px; height: 40px; left: 830px; top:425px; position: absolute; background: #EEE5C9; color: black; font-family: 'Jua', sans-serif; justify-content: center; align-items: center; text-align: center;">
        <br><br>

        <label for="lieu" style="font-size: 40px; width: 350px; height: 90px; left: 20px; top: 425px; position: absolute; background: #2A4469; color: white; font-family: 'Jua', sans-serif; justify-content: center; align-items: center; text-align: center;">DESTINATION</label>
        <input type="text" id="lieu" name="lieu" required style="font-size: 24px; width: 350px; height: 90px; left: 20px; top: 520px; position: absolute; background: #2A4469; color: white; font-family: 'Jua', sans-serif; justify-content: center; align-items: center; text-align: center;">
        <br><br>

        <label for="BagagesVoyage" style="font-size: 40px; width: 200px; height: 40px; left: 723px; top:500px; position: absolute; background: #F6F2E6; color: black; font-family: 'Jua', sans-serif; justify-content: center; align-items: center; text-align: center;">BAGAGES</label>
        <button type="button" onclick="ajouterBagage()" style="font-size: 25px; width: 50px; height: 40px; left: 930px; top: 505px; position: absolute; background: #F6F2E6; color: black; font-family: 'Jua', sans-serif; border-radius: 10px; box-shadow: 0px 4px 15px rgba(0, 0, 0, 0.3);"><i class='fas fa-plus'></i></button>
        <div id="BagagesVoyage" style="width: 300px; height: 240px;font-size: 30px; max-width: 300px; max-height: 240px; left: 663px; top: 550px; position: absolute; background: #EEE5C9; color: black; overflow-y: auto; padding: 10px; font-family: 'Jua', sans-serif; justify-content: center; align-items: center; text-align: left; border: 2px solid black; border-radius: 10px;">
            <?php foreach ($bagages as $bagage): ?>
                <div>
                    <label>
                        <input type="checkbox" id="bagage-<?= $bagage['id'] ?>" name="bagages_ids[]" value="<?= htmlspecialchars($bagage['id']); ?>">
                        <?= htmlspecialchars($bagage['nom']); ?>
                    </label>
                </div>
            <?php endforeach; ?>
        </div>
        <button type="submit" style="font-size: 40px; width: 100px; height: 100px; left: 1100px; top: 650px; position: absolute; background: #EEE5C9; color: black; font-family: 'Jua', sans-serif; border-radius: 50%;box-shadow: 0px 4px 15px rgba(0, 0, 0, 0.3);"><i class="fas fa-check"></i></button>
        </form>
    </form>
    </div>

    <script>
    // Fonction pour valider les dates
    function validateDates() {
        const dateDebut = document.getElementById("date_debut").value;
        const dateFin = document.getElementById("date_fin").value;
        const errorMessage = document.getElementById("error_date_debut");
        errorMessage.style.display = "none";

        // Vérification si la date de début est après la date de fin
        if (new Date(dateDebut) > new Date(dateFin)) {
            errorMessage.style.display = "flex"; // Affichage du message d'erreur
            return false; // Empêche la soumission du formulaire
        }
        return true; // Permet la soumission du formulaire
    }

    // Fonction pour effacer le message d'erreur quand une date est modifiée
    function clearError() {
        const errorMessage = document.getElementById("error_date_debut");
        errorMessage.style.display = "none";
    }

    // Fonction pour ouvrir la modale
    function ajouterBagage() {
        document.getElementById('modalAjouterBagage').style.display = 'block';
        document.getElementById('popup-overlay').style.display = 'block';
    }

    // Fonction pour fermer la modale
    function fermerModalBagage() {
        document.getElementById('modalAjouterBagage').style.display = 'none';
        document.getElementById('popup-overlay').style.display = 'none';
    }

    // Gérer la soumission du formulaire
    document.addEventListener("DOMContentLoaded", function() {
        const form = document.getElementById('formAjouterBagage');
        if (form) {
            form.onsubmit = function (event) {
                event.preventDefault(); // Empêche le rechargement de la page

                const nom = document.getElementById('nomBagage').value;
                const voyagesCheckboxes = document.querySelectorAll('input[name="voyages[]"]:checked');
                const voyages_ids = Array.from(voyagesCheckboxes).map(checkbox => checkbox.value);

                if (nom) {
                    fetch("../tables/bagage/ajouter_bagage.php", {
                        method: "POST",
                        headers: {
                            "Content-Type": "application/json"
                        },
                        body: JSON.stringify({ nom: nom, voyages_ids: voyages_ids.join(',') })
                    })
                    .then(response => response.json()) // Assurez-vous que la réponse est au format JSON
                    .then(data => {
                        // Vérifier s'il y a une erreur ou un succès dans la réponse
                        if (data.error) {
                            alert("Erreur: " + data.error); // Gérer l'erreur si nécessaire
                        } else {
                            // Fermer la modale et mettre à jour la liste des bagages
                            fermerModalBagage();
                            mettreAJourListeBagages(data); // Mise à jour de la liste des bagages avec les nouvelles données
                        }
                    });
                }
            };
        }
    });

    // Mettre à jour la liste des bagages après l'ajout
    function mettreAJourListeBagages(data) {
        const bagagesVoyageDiv = document.getElementById('BagagesVoyage');
        
        // Ajoutez le nouveau bagage à la liste (vous pouvez ajuster selon le format des données reçues)
        const nouveauBagageDiv = document.createElement('div');
        nouveauBagageDiv.innerHTML = `
            <label>
                <input type="checkbox" id="bagage-${data.id}" name="bagages_ids[]" value="${data.id}"  checked>
                ${data.nom}
            </label>
        `;
        document.getElementById('nomBagage').value = "";
        // Ajouter le nouveau bagage dans le div des bagages
        bagagesVoyageDiv.appendChild(nouveauBagageDiv);
    }
</script>

</div>
</div>


<!-- Modale Ajouter Bagage -->
<div id="popup-overlay" style="display: none; position: fixed; top: 0; left: 0; width: 100vw; height: 100vh; background: rgba(0, 0, 0, 0.5); z-index: 1000;"></div>

<div id="modalAjouterBagage" style="display: none; position: fixed; top: 50%; left: 50%; transform: translate(-50%, -50%); width: 400px; padding: 20px; background-color: white; border-radius: 10px; box-shadow: 0px 4px 15px rgba(0, 0, 0, 0.3); z-index: 1001;">
    <h2 style="font-family: 'Jua', sans-serif;font-size: 35px; ">Ajouter un Bagage</h2>
    <form id="formAjouterBagage">
        <label for="nomBagage" style="font-size: 30px; font-family: 'Jua', sans-serif;">Nom du Bagage</label>
        <input type="text" id="nomBagage" name="nomBagage" required style="font-size: 20px; width: 100%; margin-bottom: 20px; padding: 5px; font-family: 'Jua', sans-serif;">

        <button type="submit" style="font-size: 20px; width: 100%; background: #F6F2E6; color: black; font-family: 'Jua', sans-serif; border-radius: 10px;">Ajouter</button>
    </form>
    <button onclick="fermerModalBagage()" style="margin-top: 20px; font-size: 20px; width: 100%; background: #F6F2E6; color: black; font-family: 'Jua', sans-serif; border-radius: 10px;">Fermer</button>
</div>
</body>
</html>