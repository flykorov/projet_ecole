<?php
function getElementsWithLieux() {
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

    // Requête pour récupérer les données de la table element
    $sql = "SELECT * FROM element";
    $result = $conn->query($sql);

    $elements = [];

    // Fonction interne pour récupérer les lieux par ID de bagages
    function getLieuxByBagagesIds($conn, $bagages_ids) {
        $ids = explode(',', $bagages_ids);
        $lieux = [];

        foreach ($ids as $id) {
            $id = trim($id);
            $stmt = $conn->prepare("SELECT lieu FROM voyage WHERE id = ?");
            $stmt->bind_param("i", $id);
            $stmt->execute();
            $stmt->bind_result($lieu);
            
            if ($stmt->fetch()) {
                $lieux[] = $lieu;
            }
            
            $stmt->close();
        }

        return implode(', ', $lieux);
    }

    // Récupération des éléments et ajout des lieux associés
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $row['lieux'] = getLieuxByBagagesIds($conn, $row["bagages_ids"]);
            $elements[] = $row;
        }
    }

    $conn->close();
    return $elements;
}
?>
