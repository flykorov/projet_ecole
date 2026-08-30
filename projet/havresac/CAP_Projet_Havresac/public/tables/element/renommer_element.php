<?php
$host = 'localhost';
$dbname = 'voyage';
$user = 'root';
$password = '';

try {
    $pdo = new PDO("mysql:host=$host;dbname=$dbname", $user, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Lire les données JSON envoyées
    $data = json_decode(file_get_contents("php://input"), true);
    $element_id = $data['element_id'];
    $new_name = $data['new_name'];
    $new_nombre = $data['new_nombre'];

    // Vérification si l'élément existe
    $sql_check = "SELECT id FROM element WHERE id = :id";
    $stmt_check = $pdo->prepare($sql_check);
    $stmt_check->bindParam(':id', $element_id, PDO::PARAM_INT);
    $stmt_check->execute();
    $existing_element = $stmt_check->fetch(PDO::FETCH_ASSOC);

    if ($existing_element) {
        // Mise à jour de l'élément
        $sql_update = "UPDATE element SET nom = :nom, nombre = :nombre WHERE id = :id";
        $stmt_update = $pdo->prepare($sql_update);
        $stmt_update->bindParam(':nom', $new_name, PDO::PARAM_STR);
        $stmt_update->bindParam(':nombre', $new_nombre, PDO::PARAM_INT);
        $stmt_update->bindParam(':id', $element_id, PDO::PARAM_INT);

        if ($stmt_update->execute()) {
            echo "Élément mis à jour avec succès.";
        } else {
            echo "Erreur lors de la mise à jour de l'élément.";
        }
    } else {
        echo "Erreur: Élément introuvable.";
    }

} catch (PDOException $e) {
    echo "Erreur de connexion à la base de données: " . $e->getMessage();
}
?>
