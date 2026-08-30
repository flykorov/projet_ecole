<?php
$host = 'localhost';
$dbname = 'voyage';
$user = 'root';
$password = '';

try {
    // Connexion à la base de données
    $pdo = new PDO("mysql:host=$host;dbname=$dbname", $user, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Lire les données JSON envoyées
    $data = json_decode(file_get_contents('php://input'), true);

    // Vérification si les données sont présentes
    if (isset($data['bagage_id']) && isset($data['new_name'])) {
        $bagage_id = $data['bagage_id'];
        $new_name = $data['new_name'];

        // Préparer la requête de mise à jour
        $stmt = $pdo->prepare("UPDATE bagage SET nom = ? WHERE id = ?");
        $stmt->execute([$new_name, $bagage_id]);

        echo "Nom du bagage mis à jour avec succès.";
    } else {
        echo "Erreur: Données manquantes.";
    }

} catch (PDOException $e) {
    // Gestion des erreurs
    echo "Erreur de mise à jour du nom du bagage: " . $e->getMessage();
}

?>
