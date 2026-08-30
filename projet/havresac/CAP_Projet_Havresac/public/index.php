<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Havresac</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css" />
    <link href="https://fonts.googleapis.com/css2?family=Jua&display=swap" rel="stylesheet">
    <style>
            /* Appliquer un style de barre de défilement */
    /* Cible la scrollbar */
    ::-webkit-scrollbar {
      width: 12px; /* Largeur de la barre de défilement */
      height: 12px; /* Hauteur de la barre de défilement (pour les défilements horizontaux) */
    }

    /* Cible le "pouce" de la scrollbar (partie mobile) */
    ::-webkit-scrollbar-thumb {
      background-color: #A0EBFF; /* Couleur du pouce */
      border-radius: 10px; /* Arrondir les bords du pouce */
    }

    /* Cible la piste de la scrollbar (arrière-plan) */
    ::-webkit-scrollbar-track {
      background: #03558D; /* Couleur de la piste */
      border-radius: 10px; /* Arrondir les bords de la piste */
    }

    /* Appliquer le style à un div défilant */
    .scrollable {
      width: 300px;
      height: 300px;
      overflow: scroll;
      border: 1px solid #ccc;
    }
    .voyage-row {
        background-color: #00558C; /* Fond par défaut */
        cursor: pointer;
        border-top: 2px solid white;
        border-bottom: 2px solid white;
    }

    .voyage-row:hover {
        background-color: #2A4469; /* Change la couleur de fond lors du survol */
    }
    /* Style par défaut pour le bouton */

    .Ecran_MesVoyages {
        cursor: pointer;
        width: 278px;
        height: 38px;
        left: 952px;
        top: 36px;
        position: absolute;
        background: #1F1635;
        box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
        transition: background-color 0.3s, transform 0.3s; /* Ajoute des transitions fluides */
    }

    .Ecran_MesVoyages:hover {
        background: #4A3D62; /* Change la couleur de fond lors du survol */
        transform: scale(1.05); /* Légèrement agrandi lors du survol */
    }
    </style>
</head>
<header style="position: fixed; background-color: #00558C; padding: 5px 10px; color: white; top: 0; left: calc((100vw - 1500px) / 2); right: 0; display: flex; justify-content: center; align-items: center; z-index: 1000; height: 111px; width: 1500px; box-sizing: border-box; font-size: 25px;">
    <div style="text-align: center;">
        <h1 style="font-family: 'Jua', sans-serif; margin: 0; font-size: 50px;">BIENVENUE DANS HAVRESAC</h1>
    </div>
</header>

<body style="background-color: #A0EBFF;">
<div class="Index" style="position: fixed; left:  calc((100vw - 1500px) / 2); top: 111px; width: 1500px; height: 1000px; background: url('Images/index.png') no-repeat center center; background-size: cover; justify-content: center; align-items: center;">
    <div class="ToitDuBatiment" style="width: 1500px; height: 25px; left: 0px; top: 0px; position: absolute; background: #46728B"></div>
    <img class="Image_Ecran_MesBagages" style="width: 361px; height: 63px; left: 228px; top: 137px; position: absolute" src="Images/Image_Ecran_MesBagages.png" />
    <div class="BarreSup_Ecran_MesBagages" style="width: 361px; height: 15px; left: 228px; top: 122px; position: absolute; background: #1F1635"></div>
    <div class="Cache_Misere_MesBagages" style="width: 323px; height: 36px; left: 244px; top: 143px; position: absolute; background: #03558D; border-radius: 10px"></div>
    <div class="BoutonBagages">
        <button type ="submit" style="cursor: pointer;font-size: 20px; width: 270px; height: 30px; left: 280px; top: 148px; position: absolute; text-align: center; color: white; font-size: 24px; font-family: Jua; font-weight: 400; box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25); background: #03558D; border-radius: 10px; word-wrap: break-word"onclick="window.location.href='pages/creer-bagage.php'">Mes bagages
    </div>
    <div class="Cable1_MesBagages" style="width: 5px; height: 103px; left: 275px; top: 25px; position: absolute; background: #1F1635"></div>
    <div class="Cable2_MesBagages" style="width: 5px; height: 103px; left: 532px; top: 25px; position: absolute; background: #1F1635"></div>
    <div class="Cable1_MesVoyages" style="width: 3px; height: 15px; left: 1004px; top: 69px; position: absolute; background: #1F1635"></div>
    <div class="Cable2_MesVoyages" style="width: 3px; height: 15px; left: 1189px; top: 69px; position: absolute; background: #1F1635"></div>
    <div class="Ecran_MesVoyages" onclick="window.location.href='pages/creer-voyage.php'" style="cursor: pointer;width: 278px; height: 38px; left: 952px; top: 36px; position: absolute; background: #1F1635; box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25)"></div>
    <div class="MesVoyages"  onclick="window.location.href='pages/creer-voyage.php'" style="cursor: pointer; left: 1024px; top: 40px; position: absolute; text-align: center; color: white; font-size: 24px; font-family: Jua; font-weight: 400; word-wrap: break-word">Mes voyages</div>
    
    <div class="BoutonVoyage">
        <button type="submit" style="cursor: pointer;font-size: 20px; width: 24px; height: 24px; left: 1171px; top: 43px; position: absolute; display: flex; justify-content: center; text-align: center; align-items: center; background: #ffffff; color: black; font-family: 'Jua', sans-serif; border-radius: 50%;" onclick="window.location.href='pages/creer-voyage.php'"><i class="fas fa-plus"></i></button>
    </div>
    
    <?php
include 'tables/voyages/db.php'; // Inclusion du fichier de connexion
if (isset($_SESSION['notification'])) {
    echo "<div class='notification'>" . $_SESSION['notification'] . "</div>";
    unset($_SESSION['notification']);
}

// Mise à jour de l'état des voyages en fonction des dates
try {
    $stmt = $pdo->query("SELECT id, date_debut, date_fin, etat FROM voyage");
    $voyages = $stmt->fetchAll(PDO::FETCH_ASSOC);
    $today = date('Y-m-d'); // Obtenir la date d'aujourd'hui

    foreach ($voyages as $voyage) {
        $etat = $voyage['etat']; // Conserver l'état actuel

        // Vérifier l'état uniquement si c'est "En cours" ou "Terminé"
        if ($etat === 'En cours' || $etat === 'Terminé') {
            // Mettre à jour l'état en fonction des dates
            if ($voyage['date_debut'] <= $today && $voyage['date_fin'] >= $today) {
                $etat = 'En cours';
            } elseif ($voyage['date_fin'] < $today) {
                $etat = 'Terminé';
            }
            
            // Mettre à jour l'état du voyage si nécessaire
            $updateStmt = $pdo->prepare("UPDATE voyage SET etat = ? WHERE id = ?");
            $updateStmt->execute([$etat, $voyage['id']]);
        }
    }
} catch (PDOException $e) {
    echo "Erreur: " . $e->getMessage();
}

try {
    $sql = "SELECT * FROM voyage ORDER BY etat ASC";
    $stmt = $pdo->query($sql);

    if ($stmt->rowCount() > 0) {
        // Conteneur avec barre de défilement
        echo "<div style='max-height: 300px; overflow-y: auto; position: absolute; left: 850px; top: 110px; width: 470px;'>";
        echo "<table style='font-size: 20px; width: 100%; border-collapse: collapse; font-family: Jua;'>"; // Ajout de style pour le tableau
        echo "<tr style='background-color: #00558C; color: white;'><th>Lieu</th><th>Date de debut</th><th>Etat</th></tr>"; // Modification des couleurs de l'en-tête
    
        while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
            $etatColor = '';
            if ($row["etat"] === 'Terminé') {
                $etatColor = 'red'; // Rouge pour "Terminé"
            } elseif ($row["etat"] === 'Planifié') {
                $etatColor = '#90ee90'; // Vert pour "Planifié"
            } elseif ($row["etat"] === 'Préparation') {
                $etatColor = 'yellow'; // Jaune pour "Préparation"
            } elseif ($row["etat"] === 'En cours') {
                $etatColor = '#B58BF0'; // Bleu pour "En cours"
            }
            echo "<tr class='voyage-row' onclick=\"window.location.href='pages/visualiser_voyage.php?id=" . htmlspecialchars($row['id']) . "'\">";
            echo "<td style='padding: 8px; color: white; font-family: Jua;'>" . strtoupper(str_replace('é', 'E', htmlspecialchars($row["lieu"]))) . "</td>";
            echo "<td style='padding: 8px; color: white; font-family: Jua;'>" . strtoupper(str_replace('é', 'E', htmlspecialchars($row["date_debut"]))) . "</td>";
            echo "<td style='padding: 8px; color: $etatColor; font-family: Jua;'>" . strtoupper(str_replace('é', 'E', htmlspecialchars($row["etat"]))) . "</td>";
            echo "</tr>";
        }
    
        echo "</table>";
        echo "</div>"; // Fin du conteneur
    }
} catch (PDOException $e) {
    echo "Erreur: " . $e->getMessage();
}

?>

</div>
</body>
</html>
