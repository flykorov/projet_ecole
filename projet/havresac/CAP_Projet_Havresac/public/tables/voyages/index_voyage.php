<?php
// Configuration de la connexion à la base de données
$servername = "localhost";
$username = "root"; 
$password = ""; 
$dbname = "voyage"; 
// Création de la connexion
$conn = new mysqli($servername, $username, $password, $dbname);

// Vérification de la connexion
if ($conn->connect_error) {
    die("Échec de la connexion : " . $conn->connect_error);
}

// Requête pour récupérer les données de la table voyage
$sql = "SELECT * FROM voyage";
$result = $conn->query($sql);
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Liste des Voyages</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            line-height: 1.6;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
        }
        th {
            background-color: #f4f4f4;
        }
    </style>
</head>
<body>
    <h1>Liste des Voyages</h1>
    
    <?php
    // Vérifier si des résultats ont été retournés
    if ($result->num_rows > 0) {
        // Afficher les données dans un tableau
        echo "<table>";
        echo "<tr><th>ID</th><th>Date de Début</th><th>Date de Fin</th><th>Lieu</th><th>État</th></tr>";
        
        // Sortie des données de chaque ligne
        while ($row = $result->fetch_assoc()) {
            echo "<tr>";
            echo "<td>" . $row["id"] . "</td>";
            echo "<td>" . $row["date_debut"] . "</td>";
            echo "<td>" . $row["date_fin"] . "</td>";
            echo "<td>" . $row["lieu"] . "</td>";
            echo "<td>" . $row["etat"] . "</td>";
            echo "</tr>";
        }
        
        echo "</table>";
    } else {
        echo "Aucun voyage trouvé.";
    }

    // Fermer la connexion
    $conn->close();
    ?>
</body>
</html>
