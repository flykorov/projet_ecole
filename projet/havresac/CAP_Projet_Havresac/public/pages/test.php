<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Gestion des Bagages et Éléments</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css">
    <link href="https://fonts.googleapis.com/css2?family=Jua&display=swap" rel="stylesheet">
    <style>
        /* Appliquer la police de caractères seulement aux éléments ciblés */
        .content {
            font-family: 'Jua', sans-serif;
            display: flex;
            justify-content: center;
            flex-direction: column;
            height: 100vh;
            margin: 0;
            color: black;
        }

        button {
            color: black;
            border: none;
            padding: 10px 20px;
            text-align: center;
            display: inline-block;
            font-size: 16px;
            cursor: pointer;
            margin: 10px;
        }

        button:hover {
            background-color: #B3713F;
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
    </style>
</head>
<body>

<div class="content">
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
                echo "<li style='margin-left: " . ($niveau * 20) . "px;'>"; // L'indentation augmente de 20px par niveau
                echo "<strong>" . htmlspecialchars($bagage['nom']) . "</strong>";

                // Afficher les lieux des voyages associés
                $voyage_ids = explode(',', $bagage['voyages_ids']);
                $lieux = [];
                foreach ($voyage_ids as $voyage_id) {
                    $voyage_id = trim($voyage_id);
                    if (isset($voyages_assoc[$voyage_id])) {
                        $lieux[] = $voyages_assoc[$voyage_id];
                    }
                }
                echo " - Voyages: " . (count($lieux) > 0 ? implode(', ', $lieux) : "Aucun voyage associé");

                // Boutons pour ajouter un élément ou un sous-bagage
                echo " <button onclick=\"ajouterElement(" . $bagage['id'] . ")\"><i class='fas fa-plus'></i></button>";
                echo " <button onclick=\"supprimerBagage(" . $bagage['id'] . ")\"><i class='fas fa-trash'></i></button>";
                echo " <input type='checkbox' onchange=\"toggleCheckBagage(" . $bagage['id'] . ", this.checked)\" " . ($bagage['check'] ? 'checked' : '') . "> Prêt";

                // Afficher les éléments associés
                if (isset($bagages_elements[$bagage['id']])) {
                    echo "<ul>";
                    foreach ($bagages_elements[$bagage['id']] as $element) {
                        echo "<li style='margin-left: " . (($niveau + 1) * 20) . "px;'>" . htmlspecialchars($element['nombre'] . "x " . $element['nom']);
                        echo " - Prêt: <input type='checkbox' onchange=\"toggleCheckElement(" . $element['id'] . ", this.checked)\" " . ($element['check'] ? 'checked' : '') . "> ";
                        echo " <button onclick=\"supprimerElement(" . $element['id'] . ")\"><i class='fas fa-trash'></i></button>";
                        echo "</li>";
                    }
                    echo "</ul>";
                }

                // Affichage récursif des sous-bagages avec un niveau d'indentation supplémentaire
                afficherBagages($bagages_assoc, $bagages_elements, $voyages_assoc, $bagage['id'], $niveau + 1);
                echo "</li>";
            }
            echo "</ul>";
        }
    }

    // Bouton "Ajouter un bagage"
    echo "<button onclick=\"ajouterBagage()\">Nouveau Bagage</button>";

    // Appel de la fonction pour afficher tous les bagages à partir de la racine
    afficherBagages($bagages_assoc, $bagages_elements, $voyages_assoc);
    ?>

    <script>
    // Fonction pour ajouter un bagage
    function ajouterBagage() {
    const nom = prompt("Nom du bagage :");

    // Afficher une boîte de dialogue pour sélectionner les voyages
    const voyages = <?php echo json_encode($voyages); ?>; // Liste des voyages depuis PHP
    let voyages_ids = [];
    const voyageSelectionne = prompt("Sélectionnez les voyages à associer (séparez les IDs par des virgules) :\n" + voyages.map(v => `${v.id}: ${v.lieu}`).join("\n"));

    if (voyageSelectionne) {
        voyages_ids = voyageSelectionne.split(',').map(id => id.trim());
    }

    if (nom) {
        fetch("../tables/bagage/ajouter_bagage.php", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify({ nom: nom, voyages_ids: voyages_ids.join(',') })
        }).then(response => response.text())
          .then(data => {

              location.reload();
          });
    }
}
    // Fonction pour ajouter un élément ou un sous-bagage
    function ajouterElement(bagageId) {
        const choix = prompt("Voulez-vous ajouter un élément (E) ou un sous-bagage (S) ?");

        if (choix === "E" || choix === "e") {
            const nom = prompt("Nom de l'élément :");
            const nombre = prompt("Nombre d'éléments :");

            if (nom && nombre) {
                fetch("../tables/element/ajouter_element.php", {
                    method: "POST",
                    headers: {
                        "Content-Type": "application/json"
                    },
                    body: JSON.stringify({ bagage_id: bagageId, nom: nom, nombre: parseInt(nombre), check: 0 })
                }).then(response => response.text())
                  .then(data => {
                      location.reload();
                  });
            }
        } else if (choix === "S" || choix === "s") {
            const nom = prompt("Nom du sous-bagage :");

            if (nom) {
                fetch("../tables/bagage/ajouter_bagage.php", {
                    method: "POST",
                    headers: {
                        "Content-Type": "application/json"
                    },
                    body: JSON.stringify({ nom: nom, parent_id: bagageId, voyages_ids: "" })
                }).then(response => response.text())
                  .then(data => {
                      location.reload();
                  });
            }
        }
    }

    // Fonction pour supprimer un bagage
    function supprimerBagage(id) {
        if (confirm("Voulez-vous vraiment supprimer ce bagage ?")) {
            fetch("../tables/bagage/supprimer_bagage.php", {
                method: "POST",
                headers: {
                    "Content-Type": "application/json"
                },
                body: JSON.stringify({ bagage_id: id })
            }).then(response => response.text())
              .then(data => {
                  location.reload();
              });
        }
    }

    // Fonction pour supprimer un élément
    function supprimerElement(id) {
        if (confirm("Voulez-vous vraiment supprimer cet élément ?")) {
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
        }
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
    </script>
</div>

</body>
</html>
