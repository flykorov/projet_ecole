<?php
$host = 'localhost';
$dbname = 'voyage';
$user = 'root';
$password = '';

try {
    // Connexion à la base de données
    $pdo = new PDO("mysql:host=$host;dbname=$dbname", $user, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Récupération des données envoyées en JSON
    $data = json_decode(file_get_contents("php://input"), true);
    
    // Vérification des données reçues
    if (isset($data['bagage_id']) && isset($data['check'])) {
        $bagage_id = $data['bagage_id'];
        $check = $data['check'] ? 1 : 0;  // 1 pour coché, 0 pour décoché
        
        // Préparer la requête de mise à jour
        $stmt = $pdo->prepare("UPDATE bagage SET `check` = ? WHERE id = ?");
        $stmt->execute([$check, $bagage_id]);

        echo "État du bagage mis à jour avec succès.";
    } else {
        echo "Erreur: Données manquantes.";
    }

} catch (PDOException $e) {
    // Gestion des erreurs
    echo "Erreur de mise à jour du bagage: " . $e->getMessage();
}
?>