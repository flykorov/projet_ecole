<?php
// Inclusion du fichier de connexion à la base de données
include '../tables/voyages/db.php';

// Récupérer l'ID du voyage via l'URL et le valider
if (isset($_GET['id']) && is_numeric($_GET['id'])) {
    $voyageId = intval($_GET['id']);
} else {
    die("ID du voyage non fourni ou invalide.");
}

// Requête pour récupérer les détails du voyage
try {
    $sql = "SELECT * FROM voyage WHERE id = :id";
    $stmt = $pdo->prepare($sql);
    $stmt->bindParam(':id', $voyageId, PDO::PARAM_INT);
    $stmt->execute();

    // Vérifier si un voyage a été trouvé
    if ($stmt->rowCount() > 0) {
        $voyage = $stmt->fetch(PDO::FETCH_ASSOC);
    } else {
        die("Voyage non trouvé.");
    }
} catch (PDOException $e) {
    die("Erreur lors de la récupération des détails : " . htmlspecialchars($e->getMessage()));
}

// Configuration pour l'API Google Places
$apiKey = "AIzaSyBfdNd_Dm200zsfLHHWO1DF8sdIeapleDg";
$city = htmlspecialchars($voyage['lieu']);
$type = "tourist_attraction";

// Requête API Google Places (décommenter pour la démonstration)
/*$url = "https://maps.googleapis.com/maps/api/place/textsearch/json?query=$type+in+$city&key=$apiKey";
$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
$response = curl_exec($ch);
curl_close($ch);

$data = json_decode($response, true);*/

// Récupérer les bagages associés au voyage
$sql_bagages = "SELECT * FROM bagage WHERE FIND_IN_SET(:voyage_id, voyages_ids)";
$stmt_bagages = $pdo->prepare($sql_bagages);
$stmt_bagages->execute(['voyage_id' => $voyageId]);
$bagages = $stmt_bagages->fetchAll(PDO::FETCH_ASSOC);

// Organiser les bagages par parent_id
$bagages_assoc = [];
foreach ($bagages as $bagage) {
    $parent_id = $bagage['parent_id'] ?: 'root';
    $bagages_assoc[$parent_id][] = $bagage;
}

// Récupérer les éléments
$sql_elements = "SELECT * FROM element";
$elements = $pdo->query($sql_elements)->fetchAll(PDO::FETCH_ASSOC);
$bagages_elements = [];
foreach ($elements as $element) {
    $bagage_ids = explode(',', $element['bagages_ids']);
    foreach ($bagage_ids as $bagage_id) {
        $bagages_elements[trim($bagage_id)][] = $element;
    }
}

// Récupérer les informations sur les voyages
$sql_voyages = "SELECT * FROM voyage";
$voyages = $pdo->query($sql_voyages)->fetchAll(PDO::FETCH_ASSOC);

$voyages_assoc = [];
foreach ($voyages as $voyage_item) {
    $voyages_assoc[$voyage_item['id']] = htmlspecialchars($voyage_item['lieu']);
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Détails du Voyage</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css" />
    <link href="https://fonts.googleapis.com/css2?family=Jua&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="../style.css">
    <script>
        function toggleEditForm() {
            const detailsDiv = document.getElementById('details-section');
            const editFormDiv = document.getElementById('edit-form-section');
            if (editFormDiv.style.display === 'none' || editFormDiv.style.display === '') {
                detailsDiv.style.display = 'none';  // Masquer les détails
                editFormDiv.style.display = 'block';  // Afficher le formulaire de modification
            }
        }

    </script>
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
        <h1 style="font-family: 'Jua', sans-serif; margin: 0;font-size: 50px;">MON VOYAGE</h1>
    </div>
    
    <div style="flex: 1;">
    </div>
</header>

<body class="visualisation" style="background-color: #5CBDE8;">

    <div class="Panneau" style="left: calc((100vw - 1500px) / 2);"> 
        <div id="details-section">
        
            <!-- <img style="width: 100%; height: 100%;" src="../Images/visualiser_voyage.png"> -->
            <div class="rectangle-creation" style="width: 120px; height: 15px; left: 72.7%; top: 32.5%; position: absolute; background: #572D07"></div>

            <div class="rectangle-creation" style="width: 120px; height: 15px; left: 72.7%; top: 42.5%; position: absolute; background: #572D07"></div>

            <div class="rectangle-creation" style="width: 120px; height: 15px; left: 72.7%; top: 52.5%; position: absolute; background: #572D07"></div>

            <div class="print-creation">
                <p style="top: 25%;">LIEU : <?php echo htmlspecialchars($voyage['lieu']); ?></p>
                <p style="top: 33%;">DEPART : <?php echo htmlspecialchars($voyage['date_debut']); ?></p>
                <p style="top: 38%;">RETOUR : <?php echo htmlspecialchars($voyage['date_fin']); ?></p>
                
                <div class="rectangle-creation" style="width: 15px; height: 70px; left: 42%; top: 71%; position: absolute; background: #572D07"></div>
                <div class="rectangle-creation" style="width: 15px; height: 70px; left: 56%; top: 71%; position: absolute; background: #572D07"></div>
                
                <div class="rectangle-preparation" style="width: 300px; height:50px; position: absolute; left: 39%; top: 76%; background-color: #F7DEA8; border-radius: 10px; border: 6px solid #C15821;"></div>
                <p style="top: 74.5%;">ETAT : <?php echo str_replace('é', 'e', htmlspecialchars($voyage["etat"])); ?></p>

                <p style="top: 46%;">BAGAGES : </p>
                
                
        
                </div>
            <div class="bouton-creation">
                <!--<form action="../tables/voyages/supprimer_voyage.php" method="POST" style="display:inline;">
                    <input type="hidden" name="id" value="<?php echo htmlspecialchars($voyage['id']); ?>">
                    <button style="border: 6px solid #C15821;" type="submit" class="bouton-supprimer" onclick="return confirm('Êtes-vous sûr de vouloir supprimer ce voyage ?');">SUPPRIMER</button>
                </form>-->
                <button onclick="ouvrirPopup_checklist()" type="submit" style="top: 47%; left:50%;border: 6px solid #C15821; padding: 10px 50px;">CHECKLIST</button>
                <button onclick="supprimerVoyage(<?php echo htmlspecialchars($voyage['id']); ?>)" style="border: 6px solid #C15821;" class="bouton-supprimer">SUPPRIMER</button>
                <button style="top: 50%; left: 75%; border: 6px solid #C15821;" onclick="openPopup()">POINT D'INTERET</button>
                
                <button style="border: 6px solid #C15821;" class="bouton-modifier" onclick="toggleEditForm()">MODIFIER</button>
            </div>
        </div>

        <div id="edit-form-section" style="display:none; margin-top: 20px;">
                
                <div class="input-creation">
                <form action="../tables/voyages/modifier_voyage.php" method="POST">
                    <input type="hidden" name="id" value="<?php echo htmlspecialchars($voyage['id']); ?>">
                    <input type="hidden" name="action" value="update"> 

                    <!-- Champ caché pour l'action -->
                    <label style="top: 28%;">LIEU :</label>
                    <input style="top: 27%;" type="text" name="lieu" value="<?php echo htmlspecialchars($voyage['lieu']); ?>" required><br>

                    <label style="top: 36%;">DEPART :</label>
                    <input style="top: 35%;" type="date" name="date_debut" value="<?php echo htmlspecialchars($voyage['date_debut']); ?>" required><br>

                    <label style="top: 41%;">RETOUR :</label>
                    <input style="top: 40%;" type="date" name="date_fin" value="<?php echo htmlspecialchars($voyage['date_fin']); ?>" required><br>

                    
                    <div class="rectangle-creation" style="width: 15px; height: 70px; left: 42%; top: 71%; position: absolute; background: #572D07"></div>
                    <div class="rectangle-creation" style="width: 15px; height: 70px; left: 56%; top: 71%; position: absolute; background: #572D07"></div>
                    
                    <div class="rectangle-preparation" style="width: 300px; height:50px; position: absolute; left: 39%; top: 76%; background-color: #F7DEA8; border-radius: 10px; border: 6px solid #C15821;"></div>

                    <label style="top: 77.5%;">ETAT :</label>
                    <?php
                        if ($voyage['etat'] == 'En cours' || $voyage['etat'] == 'Terminé') {
                            // Afficher l'état sous forme de texte
                            echo '<div class="print-creation">';
                            echo '<div class="rectangle-preparation" style="width: 300px; height:50px; position: absolute; left: 39%; top: 76%; background-color: #F7DEA8; border-radius: 10px; border: 6px solid #C15821;"></div>';
                            echo '<p style="top: 74.5%;">ETAT : ' . str_replace('é', 'e', htmlspecialchars($voyage["etat"])) . '</p>';
                            echo '</div>';
                        } else {
                            // Afficher le select pour les autres états
                            echo '<select style="top: 77%;" name="etat" required>';
                            echo '<option value="Préparation" ' . ($voyage['etat'] == 'Préparation' ? 'selected' : '') . '>Preparation</option>';
                            echo '<option value="Planifié" ' . ($voyage['etat'] == 'Planifié' ? 'selected' : '') . '>Planifie</option>';
                            echo '</select><br>';
                        }
                    ?>

                    <!-- Bouton "Valider" pour soumettre la modification -->


                    <div class="rectangle-creation" style="width: 120px; height: 15px; left: 72.7%; top: 32.5%; position: absolute; background: #572D07"></div>
                    <div class="bouton-creation">
                        <button class="bouton-valider" type="submit">VALIDER</button>
                    </div>
                </form>
                <div class="bouton-creation">
                    <button style="left: 40%; top: 47%; border: 6px solid #C15821;" onclick="filterBagage(<?php echo htmlspecialchars($voyage['id']); ?>)">Gerer mes bagages</button>
                </div>
            </div>
        </div>
    </div>
    

    <div id="modalSupprimerVoyage" style="display:none; position:fixed; transform: translate(-50%, -50%); z-index:1; top: 50%; left: 50%; width:100%; height:100%; overflow:auto; font-family: Jua; background-color:rgba(0, 0, 0, 0.4);">
        <div style="background-color:white; margin:15% auto; padding:20px; border:1px solid #888; width:30%; border-radius:8px;">
            <h2 style="margin-top:0; font-size: 30px;">Confirmer la suppression</h2>
            <p style = "font-size: 20px">Etes-vous sur de vouloir supprimer ce voyage ? </p>
            <div style="display: flex; justify-content: flex-end; gap: 10px;">
                <button id="confirmSupprimerVoyage" style="background-color:#452725; color:white; padding:8px 12px; border:none; border-radius:4px; cursor:pointer;">Supprimer</button>
                <button id="cancelSupprimerVoyage" style="background-color:#B3713F; color:white; padding:8px 12px; border:none; border-radius:4px; cursor:pointer;">Annuler</button> 
            </div>
        </div>
    </div>

    <div id="popup-overlay" style="display: none; position: fixed; top: 0; left: 0; width: 100%; height: 100%; background: rgba(0, 0, 0, 0.5); z-index: 1000;"></div>
    <div id="custom-popup" style="display: none; position: fixed; top: 50%; left: 50%; border: 10px solid #C25821; transform: translate(-50%, -50%); width: 500px; background: #F7DEA8; border-radius: 10px; padding: 20px; box-shadow: 0 0px 10px rgba(0, 0, 0, 0.5); z-index: 1000;">
        <button style="position: fixed; bottom: 20px ; right: 20px ; padding: 20px px; background: #C15821; color: white; border: none; border-radius: 4px; cursor: pointer;" onclick="fermerPopup()">Fermer</button>

        <h2 style="font-family: 'Jua', sans-serif; font-size: 35px;margin: 0 0 10px;">Point d'interet</h2>
        <p style="font-family: 'Jua'; font-size: 20px;"><?php if (!empty($data['results'])) {
                $count = 0; // Initialisation du compteur
                foreach ($data['results'] as $place) {
                    // Limiter à 5 résultats
                    if ($count >= 5) {
                        break;
                    }

                    $placeName = $place['name']; // Nom du lieu
                    $placeId = $place['place_id']; // Identifiant unique du lieu
                    $mapLink = "https://www.google.com/maps/place/?q=place_id:$placeId"; // URL Google Maps

                    // Afficher uniquement le nom cliquable
                    echo "<a style='color: #007BFF;' href='$mapLink' target='_blank' >$placeName</a><br>";

                    $count++;
                }
            } else {
                echo "Aucun resultat trouver";
        
            }
            ?>
        </p>
    </div>

    
    <div id="popup-bagages" style="display: none; position: fixed; top: 50%; left: 50%; border: 10px solid #C15821; transform: translate(-50%, -50%); width: 50%; height: 50%; background: #f7dea8; font-family: Jua; border-radius: 10px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.5); overflow: auto; z-index: 1000;">
        <?php afficherBagages($bagages_assoc, $bagages_elements, $voyages_assoc); ?>
        <button style="position: fixed; bottom: 20px ; right: 20px ; padding: 20px px; background: #C15821; color: white; border: none; border-radius: 4px; cursor: pointer;" onclick="fermerPopup_checklist()">Fermer</button>
    </div>
    <div id="overlay-check" style="display: none; position: fixed; top: 0; left: 0; width: 100%; height: 100%; background: rgba(0, 0, 0, 0.5); z-index: 999;" onclick="fermerPopup_checklist()"></div>


    <?php
     function afficherBagages($bagages_assoc, $bagages_elements, $voyages_assoc, $parent_id = 'root', $niveau = 0) {
        if (isset($bagages_assoc[$parent_id])) {
            echo "<ul>";
            foreach ($bagages_assoc[$parent_id] as $bagage) {
                // Indentation basée sur le niveau
                #echo "<div class='rectangle-marron' style='width: 975px; background-color: #DCBDA4; border-radius: 10px'>";
                echo "<div class='rectangle-marron2' style=' margin-left:" . (($niveau) * 20) . "px;width:".(975 - ($niveau)*20)."px; background-color: #f7dea8; font-size: 30px ; border-radius: 10px'>";
                echo "<li style='margin-left:10px;'>"; // L'indentation augmente de 20px par niveau
                echo "<strong style= 'color: #C15821'>" . htmlspecialchars($bagage['nom']) . "</strong>";


                echo "<span style='position: absolute; left: 875px; color: #C15821'>";
                echo " <input type='checkbox' onchange=\"toggleCheckBagage(" . $bagage['id'] . ", this.checked)\" " . ($bagage['check'] ? 'checked' : '') . "> Pret";
            

                #echo " <button onclick=\"supprimerBagage(" . $bagage['id'] . ")\"><i class='fas fa-trash'></i></button>";
                echo "</span>";
        
                echo "<div id='bagage-" . $bagage['id'] . "' style='display: block;'>";


                // Afficher les éléments associés
                if (isset($bagages_elements[$bagage['id']])) {
                    echo "<ul>";
                    foreach ($bagages_elements[$bagage['id']] as $element) {
                        echo "<div class='rectangle-marron2' style=' margin-left;" . (($niveau + 1) * 20) . "px;width:".(975 - ($niveau)*20)." px; background-color: #f7dea8; font-size: 20px;border-radius: 10px'>";
                        echo "<li style='margin-left: 10px; color: #C15821; font-size: 25px'>" . htmlspecialchars($element['nombre'] . "x " . $element['nom']);
                        echo "<span style='position: absolute; left: 921px;'>";
                        echo "<input type='checkbox' onchange=\"toggleCheckElement(" . $element['id'] . ", this.checked)\" " . ($element['check'] ? 'checked' : '') . "> Pret";
                        echo "</span>";
                        echo "</li>";
                        echo "</div>";

                    }
                    echo "</ul>";
                }

                // Affichage récursif des sous-bagages avec un niveau d'indentation supplémentaire
                afficherBagages($bagages_assoc, $bagages_elements, $voyages_assoc, $bagage['id'], $niveau + 1);
                echo "</li>";
                echo "</div>";
            }
            echo "</ul>";
        }
    }
    ?>

    <script>
        function supprimerVoyage(id) {
        // Récupérer les éléments nécessaires
        const modal = document.getElementById("modalSupprimerVoyage");
        const confirmButton = document.getElementById("confirmSupprimerVoyage");
        const cancelButton = document.getElementById("cancelSupprimerVoyage");

        // Afficher le modal
        modal.style.display = "block";

        confirmButton.onclick = () => {
            const formData = new FormData();
            formData.append('id', id);
            fetch("../tables/voyages/supprimer_voyage.php", {
                method: "POST",
                body: formData
            }).then(response => response.text())
            .then(data => {
                window.location.href = "../../public/index.php";
            });
            // Fermer le modal après suppression
            modal.style.display = "none";
        };

        // Gestion du bouton "Annuler"
        cancelButton.onclick = () => {
            modal.style.display = "none";
        };
    }


    function openPopup(title, callback) {
        document.getElementById('custom-popup').style.display = 'block';
        document.getElementById('popup-overlay').style.display = 'block';
        const closeModal2 = document.getElementById("closeModal2");
        // closeModal2.onclick = () => {
        //     document.getElementById('custom-popup').style.display = "none";
        //     document.getElementById('popup-overlay').style.display = "none";
        // };

    }

    function fermerPopup() {
        document.getElementById('custom-popup').style.display = "none";
        document.getElementById('popup-overlay').style.display = "none";
    }

    function filterBagage(id) {
        window.location.href = `creer-bagage.php?voyage_filter=${id}`;
    } 



    // Fonction pour changer l'état d'un élément
    function toggleCheckElement(id, checked) {
        fetch("../tables/element/modifier_element.php", {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify({ element_id: id, check: checked ? 1 : 0 }),
        })
            .then((response) => response.text())
            .then((data) => {
                // Stocker l'indicateur dans le stockage local
                localStorage.setItem("ouvrirPopup", "true");
                location.reload(); // Recharger la page
            });
    }

    // Fonction pour changer l'état d'un bagage
    function toggleCheckBagage(id, checked) {
        fetch("../tables/bagage/modifier_bagage.php", {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify({ bagage_id: id, check: checked ? 1 : 0 }),
        })
            .then((response) => response.text())
            .then((data) => {
                // Stocker l'indicateur dans le stockage local
                localStorage.setItem("ouvrirPopup", "true");
                location.reload(); // Recharger la page
            });
    }
    function ouvrirPopup_checklist() {
            document.getElementById('popup-bagages').style.display = 'block';
            document.getElementById('overlay-check').style.display = 'block';
        }

    function fermerPopup_checklist() {
        document.getElementById('popup-bagages').style.display = 'none';
        document.getElementById('overlay-check').style.display = 'none';
    }

    if (localStorage.getItem("ouvrirPopup") === "true") {
            ouvrirPopup_checklist(); // Ouvrir la popup
            localStorage.removeItem("ouvrirPopup"); // Supprimer l'indicateur après usage
        }
    </script>

</body>
</html>

