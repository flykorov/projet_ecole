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
    if (isset($data['element_id'])) {
        $element_id = $data['element_id'];

        // Préparer la requête de suppression
        $stmt = $pdo->prepare("DELETE FROM element WHERE id = ?");
        $stmt->execute([$element_id]);

        echo "Élément supprimé avec succès.";
    } else {
        echo "Erreur: ID de l'élément manquant.";
    }

} catch (PDOException $e) {
    // Gestion des erreurs
    echo "Erreur de suppression de l'élément: " . $e->getMessage();
}
?>
