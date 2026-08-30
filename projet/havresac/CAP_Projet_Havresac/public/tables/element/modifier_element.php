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
    if (isset($data['element_id']) && isset($data['check'])) {
        $element_id = $data['element_id'];
        $check = $data['check'] ? 1 : 0;  // 1 pour coché, 0 pour décoché
        
        // Préparer la requête de mise à jour
        $stmt = $pdo->prepare("UPDATE element SET `check` = ? WHERE id = ?");
        $stmt->execute([$check, $element_id]);

        echo "État de l'élément mis à jour avec succès.";
    } else {
        echo "Erreur: Données manquantes.";
    }

} catch (PDOException $e) {
    // Gestion des erreurs
    echo "Erreur de mise à jour de l'élément: " . $e->getMessage();
}
?>
