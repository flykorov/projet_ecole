<?php
$host = 'localhost';
$dbname = 'voyage';
$user = 'root'; 
$password = ''; 

try {
    $pdo = new PDO("mysql:host=$host;dbname=$dbname", $user, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Décoder les données JSON reçues
    $data = json_decode(file_get_contents("php://input"), true);
    $bagage_id = $data['bagage_id'];
    $nom = $data['nom'];
    $nombre = $data['nombre'];
    $check = $data['check'];

    // Vérifier si un élément avec le même nom et bagage_id existe déjà
    $sql_check = "SELECT id, nombre FROM element WHERE nom = :nom AND bagages_ids = :bagages_ids";
    $stmt_check = $pdo->prepare($sql_check);
    $stmt_check->bindParam(':nom', $nom, PDO::PARAM_STR);
    $stmt_check->bindParam(':bagages_ids', $bagage_id, PDO::PARAM_STR);
    $stmt_check->execute();

    $existing_element = $stmt_check->fetch(PDO::FETCH_ASSOC);

    if ($existing_element) {
        // Si l'élément existe, mettre à jour la quantité
        $new_nombre = $existing_element['nombre'] + $nombre;
        $sql_update = "UPDATE element SET nombre = :nombre WHERE id = :id";
        $stmt_update = $pdo->prepare($sql_update);
        $stmt_update->bindParam(':nombre', $new_nombre, PDO::PARAM_INT);
        $stmt_update->bindParam(':id', $existing_element['id'], PDO::PARAM_INT);

        if ($stmt_update->execute()) {
            echo "Quantité mise à jour pour l'élément existant.";
        } else {
            echo "Erreur lors de la mise à jour de la quantité.";
        }
    } else {
        // Si l'élément n'existe pas, insérer un nouvel élément
        $sql_insert = "INSERT INTO element (nombre, nom, `check`, bagages_ids) VALUES (:nombre, :nom, :check, :bagages_ids)";
        $stmt_insert = $pdo->prepare($sql_insert);
        $stmt_insert->bindParam(':nombre', $nombre, PDO::PARAM_INT);
        $stmt_insert->bindParam(':nom', $nom, PDO::PARAM_STR);
        $stmt_insert->bindParam(':check', $check, PDO::PARAM_INT);
        $stmt_insert->bindParam(':bagages_ids', $bagage_id, PDO::PARAM_STR);

        if ($stmt_insert->execute()) {
            echo "Élément ajouté avec succès au bagage.";
        } else {
            echo "Erreur lors de l'ajout de l'élément.";
        }
    }

} catch (PDOException $e) {
    echo "Erreur de connexion à la base de données: " . $e->getMessage();
}
?>
