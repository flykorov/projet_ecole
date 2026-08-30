<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Mes Bagages</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css" />
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.4/css/all.min.css">
    <link href="https://fonts.googleapis.com/css2?family=Jua&display=swap" rel="stylesheet">
    <style>
        /* Appliquer la police de caractères seulement aux éléments ciblés */
        .Cache_Misere{
            font-family: 'Jua', sans-serif;
            display: flex;
            margin: 0;
            color: black;
            font-size: 27px;
        }

        button {
            color: black;
            border: none;
            padding: 5px 10px;
            text-align: center;
            font-size: 16px;
            cursor: pointer;
            margin: 0;
            background-color: #DCBDA4;
        }

        button:hover {
            background-color: #B3713F;
        }
        .btn-bagage-2:hover {
            background-color: white;
        }

       ul {
            list-style-type: none;
            padding: 0;
        }

        li {
            margin: 10px 0;
        }

        i {
            margin-right: 5px;
        }

        input[type="checkbox"] {
            margin-left: 10px;
        }
        .dropdown {
            position: relative; /* Nécessaire pour le positionnement du dropdown */
        }

        /* Style du menu déroulant */
        .dropdown-menu {
            position: absolute; /* Positionner le menu par rapport au bouton */
            top: 100%; /* Placer le menu juste en dessous du bouton */
            left: 0;
            z-index: 1050; /* Assurez-vous que le menu est au-dessus des autres éléments */
            display: none; /* Masquer le menu par défaut */
            
        }

        /* Afficher le menu au survol ou au clic */
        .dropdown:hover .dropdown-menu, 
        .dropdown-menu.show {
            display: block;
        }

        /* Optionnel : ajouter un peu de style pour la lisibilité */
        .dropdown-menu .dropdown-item {
            padding: 10px;
            cursor: pointer;
            color: white;
            background-color: #452725;
        }
        .dropdown-menu .dropdown-item:hover {
            background-color: #B3713F;
        }
        .d-flex {
            display: flex; /* Utilise Flexbox pour aligner les éléments sur une ligne */
            align-items: center; /* Centre verticalement les éléments */
        }

        .mr-2 {
            margin-right: 0.5rem; /* Espacement entre les deux boutons */
        }

        .btn {
            margin: 0; /* Assurez-vous qu'il n'y a pas de marges par défaut */
        }
               /* Appliquer un style de barre de défilement */
    /* Cible la scrollbar */
    ::-webkit-scrollbar {
      width: 12px; /* Largeur de la barre de défilement */
      height: 12px; /* Hauteur de la barre de défilement (pour les défilements horizontaux) */
    }

    /* Cible le "pouce" de la scrollbar (partie mobile) */
    ::-webkit-scrollbar-thumb {
      background-color: #B3713F; /* Couleur du pouce */
      border-radius: 10px; /* Arrondir les bords du pouce */
    }

    /* Cible la piste de la scrollbar (arrière-plan) */
    ::-webkit-scrollbar-track {
      background: #DCBDA4; /* Couleur de la piste */
      border-radius: 10px; /* Arrondir les bords de la piste */
    }

    /* Appliquer le style à un div défilant */
    .scrollable {
      width: 300px;
      height: 300px;
      overflow: scroll;
      border: 1px solid #ccc;
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
        <h1 style="font-family: 'Jua', sans-serif; margin: 0;font-size: 50px;">MES BAGAGES</h1>
    </div>
    
    <div style="flex: 1;">
    </div>
</header>

<body style="background-color: #92D0CD">

<div class="Bagages" style="width: 1500px; height: 1000px; left: calc((100vw - 1500px) / 2); top : 111px; position: fixed; background: url('../Images/valise_bagages.jpg') no-repeat center center; background-size: cover;">
    <!--<div id="app-root" class="voyage"> !-->
        <!-- <form action="../tables/voyages/ajouter_voyage.php" method="POST"> !-->
        <div id="filtre_voyages" onclick="ouvrirFiltreVoyages()" style="font-size: 36px; width: 154px; height: 64px; position: absolute; left: 935px; top: 132px; display: flex; justify-content: center; align-items: center; background: #452725; color: #B3713F; font-family: 'Jua', sans-serif; border-radius: 10px; cursor: pointer;">
            Voyages
        </div>
        <div class="BoutonBagages">
            <button class="btn-bagage-2" type ="submit" style="cursor: pointer;font-size: 32px; width: 314px; height: 67px; left: 260px; top: 128px; position: absolute; text-align: center; color: #B3713F; font-family: Jua; font-weight: 400; box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25); background: #452725; border-radius: 10px; word-wrap: break-word" onclick="ajouterBagage()">NOUVEAU BAGAGE</button>
        </div>
        <div class="Cache_Misere" style="max-height: 650px; overflow-y: auto;width: 999px; height: 650px; left: 255px; top: 240px; position: absolute; background: #E9D8C8; border-radius: 10px;">
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
    $sql_bagages = "SELECT * FROM bagage";
    $bagages = $pdo->query($sql_bagages)->fetchAll(PDO::FETCH_ASSOC);

    // Organiser les bagages par parent_id
    $bagages_assoc = [];
    foreach ($bagages as $bagage) {
        $parent_id = $bagage['parent_id'] ?? null;
        if ($parent_id) {
            $bagages_assoc[$parent_id][] = $bagage;
        } else {
            $bagages_assoc['root'][] = $bagage;
        }
    }

    // Récupérer les voyages
    $sql_voyages = "SELECT * FROM voyage";
    $voyages = $pdo->query($sql_voyages)->fetchAll(PDO::FETCH_ASSOC);
    $voyages_assoc = [];
    foreach ($voyages as $voyage) {
        $voyages_assoc[$voyage['id']] = $voyage['lieu'];
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

    // Fonction pour afficher les bagages et sous-bagages avec indentation
    function afficherBagages($bagages_assoc, $bagages_elements, $voyages_assoc, $parent_id = 'root', $niveau = 0) {
        if (isset($bagages_assoc[$parent_id])) {
            echo "<ul>";
            foreach ($bagages_assoc[$parent_id] as $bagage) {
                // Indentation basée sur le niveau
                #echo "<div class='rectangle-marron' style='width: 975px; background-color: #DCBDA4; border-radius: 10px'>";
                echo "<div class='rectangle-marron2' style=' margin-left:" . (($niveau) * 20) . "px;width:".(975 - ($niveau)*20)."px; background-color: #DCBDA4; border-radius: 10px'>";
                echo "<li style='margin-left:10px;'>"; // L'indentation augmente de 20px par niveau
                echo "<strong>" . htmlspecialchars($bagage['nom']) . "</strong>";
                echo "<button class='btn btn-modif' onclick=\"modifierBagage(" . $bagage['id'] . ", '" . $bagage['nom'] . "')\"><i class='fas fa-edit'></i></button>";
                echo "<button onclick=\"toggleDetails('bagage-" . $bagage['id'] . "')\" style='background: none; border: none; cursor: pointer;'>";
                echo "<i class='fas fa-chevron-down' id='icon-bagage-" . $bagage['id'] . "'></i>";
                echo "</button> ";
                
                // Afficher les lieux des voyages associés
                $voyage_ids = explode(',', $bagage['voyages_ids']);
                $lieux = [];
                foreach ($voyage_ids as $voyage_id) {
                    $voyage_id = trim($voyage_id);
                    if (isset($voyages_assoc[$voyage_id])) {
                        $lieux[] = $voyages_assoc[$voyage_id];
                    }
                }
                echo "<span style='position: absolute; left: 700px; max-width: 150px; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; display: inline-block;' title='" . htmlspecialchars(implode(', ', $lieux)) . "'>";

                if (count($lieux) > 0) {
                    $initiales = array_map(function($lieu) {
                    return strtoupper(substr($lieu, 0, 3)); // Prend les 3 premières lettres en majuscules
                    }, $lieux);
                    echo implode(', ', $initiales); // Affiche les initiales séparées par des virgules
                } else {
                    echo "/";
                }
                echo "</span>";



                // Boutons pour ajouter un élément ou un sous-bagage
                echo "<span style='position: absolute; left: 875px;'>";
                #echo " <input type='checkbox' onchange=\"toggleCheckBagage(" . $bagage['id'] . ", this.checked)\" " . ($bagage['check'] ? 'checked' : '') . "> Prêt";
                #echo " <button onclick=\"ajouterElement(" . $bagage['id'] . ")\"><i class='fas fa-plus'></i></button>";
                
                echo "
                <div class='d-flex align-items-center'>
                    <div class='dropdown mr-2'>
                        <button class='btn btn-primary dropdown-toggle' type='button' id='dropdownMenuButton' data-toggle='dropdown' aria-haspopup='true' aria-expanded='false'>
                            <i class='fas fa-plus'></i>
                        </button>
                        <div class='dropdown-menu' aria-labelledby='dropdownMenuButton'>
                            <button class='dropdown-item' onclick='ajouterElement(" . $bagage['id'] . ")'>Elément</button>
                            <button class='dropdown-item' onclick='ajouterSousBagage(" . $bagage['id'] . ")'>Sous-bagage</button>
                        </div>
                    </div>
                    <button class='btn btn-danger' onclick=\"supprimerBagage(" . $bagage['id'] . ")\"><i class='fas fa-trash'></i></button>
                </div></div>";


                #echo " <button onclick=\"supprimerBagage(" . $bagage['id'] . ")\"><i class='fas fa-trash'></i></button>";
                echo "</span>";
        
                echo "<div id='bagage-" . $bagage['id'] . "' style='display: block;'>";


                // Afficher les éléments associés
                if (isset($bagages_elements[$bagage['id']])) {
                    echo "<ul>";
                    foreach ($bagages_elements[$bagage['id']] as $element) {
                        echo "<div class='rectangle-marron2' style=' margin-left:" . (($niveau + 1) * 20) . "px;width:".(975 - ($niveau)*20)." px; background-color: #DCBDA4; border-radius: 10px'>";
                        echo "<li style='margin-left: 10px;'>" . htmlspecialchars($element['nombre'] . "x " . $element['nom']);
                        echo "<button class='btn btn-modif' onclick=\"modifierElement(" . $element['id'] . ", '" . $element['nom'] . "', " . $element['nombre'] . ")\"><i class='fas fa-edit'></i></button>";
                        echo "<span style='position: absolute; left: 921px;'>";
                        #echo "<input type='checkbox' onchange=\"toggleCheckElement(" . $element['id'] . ", this.checked)\" " . ($element['check'] ? 'checked' : '') . "> Prêt";
                        echo " <button onclick=\"supprimerElement(" . $element['id'] . ")\"><i class='fas fa-trash'></i></button>";
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

    if (isset($_GET['voyage_filter']) && $_GET['voyage_filter'] !== '') {
        $voyage_filter = $_GET['voyage_filter'];
    
        // Filtrer les bagages associés au voyage sélectionné
        foreach ($bagages_assoc as $parent_id => $bagages) {
            $bagages_assoc[$parent_id] = array_filter($bagages, function ($bagage) use ($voyage_filter) {
                $voyage_ids = explode(',', $bagage['voyages_ids']);
                return in_array($voyage_filter, array_map('trim', $voyage_ids));
            });
    
            // Supprimer les entrées vides
            if (empty($bagages_assoc[$parent_id])) {
                unset($bagages_assoc[$parent_id]);
            }
        }
    }



    // Appel de la fonction pour afficher tous les bagages à partir de la racine
    afficherBagages($bagages_assoc, $bagages_elements, $voyages_assoc);
?>

<script>

    function ajouterBagage() {
            // Ouvre la modale
            document.getElementById('modalAjouterBagage').style.display = 'block';
            document.getElementById('popup-overlay').style.display = 'block';

            // Gestion de la soumission du formulaire
            const form = document.getElementById('formAjouterBagage');
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
                        .then(response => response.text())
                        .then(data => {
                            // Fermer la modale et recharger la page
                            fermerModalBagage();
                            location.reload();
                        });
                }
            };
        }
    
    // Fonction pour fermer la modale
    function fermerModalBagage() {
        document.getElementById('modalAjouterBagage').style.display = 'none';
        document.getElementById('formAjouterBagage').reset(); // Réinitialise le formulaire
        document.getElementById('popup-overlay').style.display = 'none';
    }

    // Fonction pour supprimer un bagage
    function supprimerBagage(id) {
    // Récupérer les éléments nécessaires
        const modal = document.getElementById("modalSupprimerBagage");
        const confirmButton = document.getElementById("confirmSupprimer");
        /*const closeModal3 = document.getElementById("closeModal3");
        closeModal3.onclick = () => {
            modal.style.display = "none";
        };*/
        const cancelButton = document.getElementById("cancelSupprimer");

        // Afficher le modal
        modal.style.display = "block";
        // Gestion du bouton "Supprimer"
        confirmButton.onclick = () => {
            fetch("../tables/bagage/supprimer_bagage.php", {
                method: "POST",
                headers: {
                    "Content-Type": "application/json"
                },
                body: JSON.stringify({ bagage_id: id })
            })
                .then((response) => response.text())
                .then((data) => {
                    // Rafraîchir la page après suppression
                    location.reload();
                })
                .catch((error) => {
                    console.error("Erreur :", error);
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
        document.getElementById('popup-title').innerText = title;
        document.getElementById('custom-popup').style.display = 'block';
        document.getElementById('popup-overlay').style.display = 'block';
        /*const closeModal2 = document.getElementById("closeModal2");
        closeModal2.onclick = () => {
            document.getElementById('custom-popup').style.display = "none";
            document.getElementById('popup-overlay').style.display = "none";
        };*/

        // Réinitialisation des champs
        document.getElementById('popup-input-1').value = '';
        document.getElementById('popup-input-2').value = 1;

        // Gestion des boutons
        document.getElementById('popup-confirm').onclick = () => {
            const value1 = document.getElementById('popup-input-1').value.trim();
            const value2 = document.getElementById('popup-input-2').value.trim();

            if (value1 && value2) {
                callback(value1, value2);
                closePopup();
            } else {
                alert("Veuillez remplir tous les champs !");
            }
        };

        document.getElementById('popup-cancel').onclick = closePopup;
    }

    function closePopup() {
        document.getElementById('custom-popup').style.display = 'none';
        document.getElementById('popup-overlay').style.display = 'none';
    }


    function ajouterElement(bagageId) {
        openPopup("Ajoutez un element :", (nom, nombre) => {
            fetch("../tables/element/ajouter_element.php", {
                method: "POST",
                headers: {
                    "Content-Type": "application/json"
                },
                body: JSON.stringify({
                    bagage_id: bagageId,
                    nom: nom,
                    nombre: parseInt(nombre, 10),
                    check: 0
                })
            }).then(response => response.text())
            .then(data => {
                location.reload();
            });
        });
    };



    // Fonction pour supprimer un élément
    function supprimerElement(id) {
        // Récupérer les éléments nécessaires
        const modal = document.getElementById("modalSupprimerElement");
        const confirmButton = document.getElementById("confirmSupprimer2");
        /*const closeModal3 = document.getElementById("closeModal3");
        closeModal3.onclick = () => {
            modal.style.display = "none";
        };*/
        const cancelButton = document.getElementById("cancelSupprimerElement");

        // Afficher le modal
        modal.style.display = "block";
        confirmButton.onclick = () => {
            fetch("../tables/element/supprimer_element.php", {
                method: "POST",
                headers: {
                   "Content-Type": "application/json"
                },
                body: JSON.stringify({ element_id: id })
            }).then(response => response.text())
            .then(data => {
                location.reload();
            });
            // Fermer le modal après suppression
            modal.style.display = "none";
        };

        // Gestion du bouton "Annuler"
        cancelButton.onclick = () => {
            modal.style.display = "none";
        };
    }

    function ajouterSousBagage(bagageId) {
        // Afficher le modal
        const modal = document.getElementById("modalSousBagage");
        const parentBagageIdField = document.getElementById("parentBagageId");
        modal.style.display = "block";
        // Passer l'ID du bagage parent au champ caché
        parentBagageIdField.value = bagageId;

        /*// Gérer la fermeture du modal
        const closeModal = document.getElementById("closeModal");
        closeModal.onclick = () => {
            modal.style.display = "none";
        };*/
        const cancelButton = document.getElementById("cancelSupprimer2");
        // Gérer l'envoi du formulaire
        const form = document.getElementById("formSousBagage");
        form.onsubmit = (event) => {
            event.preventDefault(); // Empêche le rechargement de la page

            const nom = document.getElementById("nomSousBagage").value;
            const parent_id = document.getElementById("parentBagageId").value;

            if (nom) {
                fetch("../tables/bagage/ajouter_bagage.php", {
                    method: "POST",
                    headers: {
                        "Content-Type": "application/json"
                    },
                    body: JSON.stringify({ nom: nom, parent_id: parent_id, voyages_ids: "" })
                })
                    .then((response) => response.text())
                    .then((data) => {
                        // Rafraîchir la page après l'ajout
                        location.reload();
                    })
                    .catch((error) => {
                        console.error("Erreur :", error);
                    });
            }

            // Fermer le modal après soumission
            modal.style.display = "none";
        };
        cancelButton.onclick = () => {
            modal.style.display = "none";
        };
    }   

    // Fonction pour changer l'état de l'élément (prêt ou non)
    function toggleCheckElement(id, checked) {
        fetch("../tables/element/modifier_element.php", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify({ element_id: id, check: checked ? 1 : 0 })
        }).then(response => response.text())
          .then(data => {
              location.reload();
          });
    }

    // Fonction pour changer l'état du bagage (prêt ou non)
    function toggleCheckBagage(id, checked) {
        fetch("../tables/bagage/modifier_bagage.php", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify({ bagage_id: id, check: checked ? 1 : 0 })
        }).then(response => response.text())
          .then(data => {
              location.reload();
          });
    }

    function toggleDetails(id) {
        const details = document.getElementById(id);
        const icon = document.getElementById('icon-' + id);
        if (details.style.display === 'none') {
            details.style.display = 'block';
            icon.classList.remove('fa-chevron-down');
            icon.classList.add('fa-chevron-up');
        } else {
            details.style.display = 'none';
            icon.classList.remove('fa-chevron-up');
            icon.classList.add('fa-chevron-down');
        }
    }
    function ouvrirFiltreVoyages() {
        document.getElementById('modalFiltreVoyages').style.display = 'flex';
    }

    function fermerFiltreVoyages() {
        document.getElementById('modalFiltreVoyages').style.display = 'none';
    }
    function modifierBagage(id,old_nom) {
        const modal = document.getElementById("modalModifierBagage");
        modal.style.display = "block";

        const confirmButton = document.getElementById("confirmModifierBagage");
        const cancelButton = document.getElementById("cancelModifierBagage");

        // Récupérer et remplir le champ avec l'ID et d'autres informations du bagage
        document.getElementById('popup-input-id-renommer-bagage').value = id;
        document.getElementById('popup-input-nom-renommer-bagage').value = old_nom;

        // Afficher le modal
        modal.style.display = "block";

        confirmButton.onclick = () => {
            // Récupérer les données du formulaire
            const nomBagage = document.getElementById('popup-input-nom-renommer-bagage').value;
            
            // Vérifier si le nom du bagage est vide
            if (!nomBagage) {
                return;
            }

            const formData = {
                bagage_id: id,  // ID du bagage
                new_name: nomBagage  // Nouveau nom du bagage
            };

            fetch('../tables/bagage/renommer_bagage.php', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'  // Spécifier que nous envoyons des données JSON
                },
                body: JSON.stringify({ bagage_id: id, new_name: nomBagage })  // Convertir l'objet JavaScript en JSON
            })
            .then(response => response.text())
            .then(data => {
                location.reload();  // Recharger la page après modification
            })
            .catch(error => {
                console.error('Erreur:', error);
            });

            // Fermer le modal après modification
            modal.style.display = "none";
        };

        cancelButton.onclick = () => {
            modal.style.display = "none";
        };
    }
    function modifierElement(id, old_nom,old_nombre) {
        const modal = document.getElementById("modalModifierElement");
        modal.style.display = "block";

        const confirmButton = document.getElementById("confirmModifierElement");
        const cancelButton = document.getElementById("cancelModifierElement");

        // Récupérer et remplir le champ avec l'ID et d'autres informations de l'élément
        document.getElementById('popup-input-id-modifier-element').value = id;
        document.getElementById('popup-input-nom-modifier-element').value = old_nom;
        document.getElementById('popup-input-nombre-modifier-element').value = old_nombre;

        // Afficher le modal
        modal.style.display = "block";

        confirmButton.onclick = () => {
            // Récupérer les données du formulaire
            const nomElement = document.getElementById('popup-input-nom-modifier-element').value;
            const nombreElement = document.getElementById('popup-input-nombre-modifier-element').value;

            // Vérifier si le nom ou le nombre de l'élément sont vides

            const formData = {
                element_id: id,  // ID de l'élément
                new_name: nomElement,  // Nouveau nom de l'élément
                new_nombre: parseInt(nombreElement, 10)  // Nouveau nombre de l'élément
            };

            fetch('../tables/element/renommer_element.php', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'  // Spécifier que nous envoyons des données JSON
                },
                body: JSON.stringify(formData)  // Convertir l'objet JavaScript en JSON
            })
            .then(response => response.text())
            .then(data => {
                location.reload();  // Recharger la page après modification
            })
            .catch(error => {
                console.error('Erreur:', error);
            });

            // Fermer le modal après modification
            modal.style.display = "none";
        };

        cancelButton.onclick = () => {
            modal.style.display = "none";
        };
    }


    </script>
    
</div> 
</div>
<!-- Popup pour ajouter un bagage -->
<div id="modalAjouterBagage" style="display: none; position: fixed; top: 50%; left: 50%; transform: translate(-50%, -50%); background-color: white;font-family: Jua; padding: 30px; border-radius: 10px; box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.2); z-index: 2000;">
    <h2 style="font-family: 'Jua', sans-serif; margin-bottom: 20px;font-size: 35px;">Ajouter un Bagage</h2>
    <form id="formAjouterBagage">
        <label for="nomBagage" style="display: flex; margin-bottom: 10px;font-size: 30px;">Nom du bagage :</label>
        <input type="text" id="nomBagage" name="nomBagage" style="width: 100%; padding: 8px; margin-bottom: 20px;font-size: 20px;" required />
        <label for="voyagesBagage" style="display: flex; margin-bottom: 10px;font-size: 30px; ">Selectionnez les voyages :</label>
        <div id="voyagesBagage" style="display: flex; flex-wrap: wrap;flex-direction: column; gap: 10px; overflow-y: auto; max-height: 200px; max-width: 400px">
            <?php foreach ($voyages as $voyage): ?>
                <label style="font-size: 20px;">
                    <input type="checkbox" name="voyages[]" value="<?= $voyage['id']; ?>" style="margin-right: 10px;">
                    <?= htmlspecialchars($voyage['lieu']); ?>
                </label>
            <?php endforeach; ?>
        </div>
        <div style="text-align: right;">
            <button type="submit" style="background-color: #452725; color: white; border: none; padding: 10px 20px; cursor: pointer;border-radius: 4px;">Ajouter</button>
            <button type="button" onclick="fermerModalBagage()" style="background-color: #B3713F; color: white; border: none; padding: 10px 20px; margin-right: 10px; cursor: pointer;border-radius: 4px;">Annuler</button>
        </div>
    </form>
</div>

<!-- Popup pour ajouter élément-->
<div id="popup-overlay" style="display: none; position: fixed; top: 0; left: 0; width: 100%; height: 100%; background: rgba(0, 0, 0, 0.5); z-index: 1000;font-family: Jua;"></div>
    <div id="custom-popup" style="display: none; position: fixed; top: 50%; left: 50%; transform: translate(-50%, -50%);font-family: Jua;  width: 400px; background: #fff; padding: 20px; box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2); z-index: 1001; border-radius: 8px;">
        <!--<span id="closeModal2" style="color:#aaa; float:right; font-size:28px; font-weight:bold; cursor:pointer;">&times;</span>-->
            <h2 id="popup-title" style="margin: 0 0 10px;font-size: 35px;">Ajouter un element</h2>
            <label for="popup-input-1" style="display: block; margin-bottom: 5px; font-size: 30px;">Nom de l'element:</label>
            <input id="popup-input-1" type="text" style="width: 80%; padding: 8px; margin-bottom: 15px; border: 1px solid #ccc; border-radius: 4px;font-size: 20px;" />
            <label for="popup-input-2" style="display: block; margin-bottom: 5px;font-size: 30px;">Nombre d'elements:</label>
            <input id="popup-input-2" type="number" value='1' style="width: 80%; padding: 8px; margin-bottom: 15px; border: 1px solid #ccc; border-radius: 4px;font-size: 20px;" />
            <div style="text-align: right;">
                <button id="popup-confirm" style="padding: 8px 12px; background: #452725; color: white; border: none; border-radius: 4px; cursor: pointer;">Confirmer</button>
                <button id="popup-cancel" style="margin-right: 10px; padding: 8px 12px; background: #B3713F; color: white; border: none; border-radius: 4px; cursor: pointer;">Annuler</button>
            </div>
    </div>

    <!-- Popup pour ajouter un sous-bagage -->
    <div id="modalSousBagage" style="display:none; position:fixed;;z-index:1; top: 0%; left: 0%; width:100%; height:100%; overflow:auto; font-family: Jua; background-color:rgba(0, 0, 0, 0.4);">
        <div style="background-color:white; margin:15% auto; padding:20px; border:1px solid #888; width:15%; border-radius:8px;text-align:center;">
        <!--<span id="closeModal" style="color:#aaa; float:right; font-size:28px; font-weight:bold; cursor:pointer;">&times;</span>-->
            <h2 style="margin-top:0;font-size: 35px;">Ajouter un sous-bagage</h2>
            <form id="formSousBagage">
                <label for="nomSousBagage" style="display:block; margin-bottom:10px; font-weight:bold;font-size: 30px;">Nom du sous-bagage :</label>
                <input type="text" id="nomSousBagage" name="nom" required style="font-size: 20px;width:80%; padding:8px; margin-bottom:20px; border:1px solid #ccc; border-radius:4px;">
                <input type="hidden" id="parentBagageId" name="parent_id">
                <div style="text-align: right;">
                    <button id="popup-confirm" style="padding: 8px 12px; background: #452725; color: white; border: none; border-radius: 4px; cursor: pointer;">Confirmer</button>
                    <button id="cancelSupprimer2" style="margin-right: 10px; padding: 8px 12px; background: #B3713F; color: white; border: none; border-radius: 4px; cursor: pointer;">Annuler</button>
                </div>
            </form>
        </div>
    </div> 

    <!-- Modal pour confirmer la suppression -->
    <div id="modalSupprimerBagage" style="display:none; position:fixed; top: 50%; left: 50%; transform: translate(-50%, -50%); z-index:1; width:100%; height:100%; overflow:auto; font-family: Jua; background-color:rgba(0, 0, 0, 0.4);">
        <div style="background-color:white; margin:15% auto; padding:20px; border:1px solid #888; width:30%; border-radius:8px;">
        <!--<span id="closeModal3" style="color:#aaa; float:right; font-size:28px; font-weight:bold; cursor:pointer;">&times;</span>-->
            <h2 style="margin-top:0; font-size: 30px;">Confirmer la suppression</h2>
            <p style = "font-size: 20px">Etes-vous sûr de vouloir supprimer ce bagage ? </p>
            <div style="text-align: right;">
                <button id="confirmSupprimer" style="background-color:#452725; color:white; padding:8px 12px; border:none; border-radius:4px; cursor:pointer;">Supprimer</button> 
                <button id="cancelSupprimer" style="background-color:#B3713F; color:white; padding:8px 12px; border:none; border-radius:4px; cursor:pointer;">Annuler</button>
            </div>
        </div>
    </div>
    
    <div id="modalSupprimerElement" style="display:none; position:fixed; transform: translate(-50%, -50%); z-index:1; top: 50%; left: 50%; width:100%; height:100%; overflow:auto; font-family: Jua; background-color:rgba(0, 0, 0, 0.4);">
        <div style="background-color:white; margin:15% auto; padding:20px; border:1px solid #888; width:30%; border-radius:8px;">
        <!--<span id="closeModal3" style="color:#aaa; float:right; font-size:28px; font-weight:bold; cursor:pointer;">&times;</span>-->
            <h2 style="margin-top:0; font-size: 30px;">Confirmer la suppression</h2>
            <p style = "font-size: 20px">Etes-vous sur de vouloir supprimer cet element ? </p>
            <div style="text-align: right;">
                <button id="cancelSupprimerElement" style="background-color:#B3713F; color:white; padding:8px 12px; border:none; border-radius:4px; cursor:pointer;">Annuler</button>
                <button id="confirmSupprimer2" style="background-color:#452725; color:white; padding:8px 12px; border:none; border-radius:4px; cursor:pointer;">Supprimer</button> 
            </div>
        </div>
    </div>

     <!-- Popup pour filtrer les voyages -->
    <div id="modalFiltreVoyages" style="display: none; position: fixed; top: 0; left: 0; width: 100%; height: 100%; background: rgba(0, 0, 0, 0.5); z-index: 1000; justify-content: center; align-items: center;font-family: Jua;">
        <div style="background: #fff; padding: 20px; border-radius: 10px; width: 300px; text-align: center; position: relative;">
        <button onclick="fermerFiltreVoyages()" style="position: absolute; top: 10px; right: 10px; background: none; border: none; font-size: 20px; font-weight: bold; cursor: pointer;">&times;</button>
            <h2 style="font-size: 30px;">Filtrer par voyage</h2>
            <form method="GET" action="">
                <select id="voyage_filter" name="voyage_filter" style="font-size: 20px;">
                    <option value="">-- Tous les voyages --</option>
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
                        $sql_bagages = "SELECT * FROM bagage";
                        $bagages = $pdo->query($sql_bagages)->fetchAll(PDO::FETCH_ASSOC);
                    
                        // Organiser les bagages par parent_id
                        $bagages_assoc = [];
                        foreach ($bagages as $bagage) {
                            $parent_id = $bagage['parent_id'] ?? null;
                            if ($parent_id) {
                                $bagages_assoc[$parent_id][] = $bagage;
                            } else {
                                $bagages_assoc['root'][] = $bagage;
                            }
                        }
                    
                        // Récupérer les voyages
                        $sql_voyages = "SELECT * FROM voyage";
                        $voyages = $pdo->query($sql_voyages)->fetchAll(PDO::FETCH_ASSOC);
                        $voyages_assoc = [];
                        foreach ($voyages as $voyage) {
                            $voyages_assoc[$voyage['id']] = $voyage['lieu'];
                        }
                    
                    
                        foreach ($voyages_assoc as $id => $lieu): ?>
                        <option value="<?= htmlspecialchars($id) ?>" <?= isset($_GET['voyage_filter']) && $_GET['voyage_filter'] == $id ? 'selected' : '' ?>>
                            <?= htmlspecialchars($lieu) ?>
                        </option>
                    <?php endforeach; ?>
                </select>
                <button type="submit" style="padding: 8px 12px; background: #452725; color: white; border: none; border-radius: 4px; cursor: pointer;margin-top: 20px;">Appliquer</button>
            </form>
        </div>
    </div>
        <<!-- Modal pour modifier un bagage -->
        <div id="modalModifierBagage" style="display:none; position:fixed;;z-index:1; top: 0%; left: 0%; width:100%; height:100%; overflow:auto; font-family: Jua; background-color:rgba(0, 0, 0, 0.4);">
        <div style="background-color:white; margin:15% auto; padding:20px; border:1px solid #888; width:15%; border-radius:8px;text-align:center;;">
            <h2 style="margin-top: 0; font-size: 35px;">Renommer le bagage</h2>
            <div>
                <label for="nomModifierBagage" style="display:block; margin-bottom:10px; font-weight:bold;font-size: 30px;">Nom du bagage:</label>
                <input type="text" id="popup-input-nom-renommer-bagage" style="font-size: 20px" />
                <input type="hidden" id="popup-input-id-renommer-bagage" /> <!-- Champ caché pour l'ID -->
            </div>
            <div style="text-align: right;">
                <button id="confirmModifierBagage" style="padding: 8px 12px; background: #452725; color: white; border: none; border-radius: 4px; cursor: pointer; margin-top: 20px;">Confirmer</button>
                <button id="cancelModifierBagage" style="background-color:#B3713F; color:white; padding:8px 12px; border:none; border-radius:4px; cursor:pointer;">Annuler</button>
            </div>
        </div>
    </div>
    <!-- Modal pour modifier un élément -->
    <div id="modalModifierElement" style="display:none; position:fixed;;z-index:1; top: 0%; left: 0%; width:100%; height:100%; overflow:auto; font-family: Jua; background-color:rgba(0, 0, 0, 0.4);">
        <div style="background-color:white; margin:15% auto; padding:20px; border:1px solid #888; width:15%; border-radius:8px;text-align:center;">
            <h2 style="margin-top: 0; font-size: 35px;">Modifier l'element</h2>
            <div>
                <label for="nomModifierElement" style="display:block;font-weight:bold;font-size: 30px;">Nom de l'element :</label>
                <input type="text" id="popup-input-nom-modifier-element" placeholder="Nom de l'élément" style="font-size: 20px;margin-top: 10px;" />
                <label for="nombreModifierElement" style="display:block;  font-weight:bold;font-size: 30px;">Nombre d'element :</label>
                <input type="number" id="popup-input-nombre-modifier-element" placeholder="Nombre" style="font-size: 20px; margin-top: 10px;" />
                <input type="hidden" id="popup-input-id-modifier-element" /> <!-- Champ caché pour l'ID -->
            </div>
            <div style="text-align: right;">
                <button id="confirmModifierElement" style="padding: 8px 12px; background: #452725; color: white; border: none; border-radius: 4px; cursor: pointer; margin-top: 20px;">Confirmer</button>
                <button id="cancelModifierElement" style="background-color:#B3713F; color:white; padding:8px 12px; border:none; border-radius:4px; cursor:pointer;">Annuler</button>
            </div>
        </div>
    </div>


</body>
</html>