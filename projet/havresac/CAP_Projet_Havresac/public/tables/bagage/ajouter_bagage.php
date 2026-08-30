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
    if (isset($data['nom'])) {
        $nom = $data['nom'];
        $parent_id = $data['parent_id'] ?? null; // ID du bagage parent, s'il existe
        $voyages_ids = "";

        if ($parent_id) {
            // Si le bagage a un parent, récupérer les voyages_ids du parent
            $stmt = $pdo->prepare("SELECT voyages_ids FROM bagage WHERE id = ?");
            $stmt->execute([$parent_id]);
            $parent_bagage = $stmt->fetch(PDO::FETCH_ASSOC);
            
            if ($parent_bagage) {
                $voyages_ids = $parent_bagage['voyages_ids'];
            }
        } else {
            // Si pas de parent, récupérer les voyages_ids depuis la requête
            $voyages_ids = $data['voyages_ids'] ?? "";
        }

        // Préparer la requête d'insertion
        $stmt = $pdo->prepare("INSERT INTO bagage (nom, voyages_ids, parent_id) VALUES (?, ?, ?)");
        $stmt->execute([$nom, $voyages_ids, $parent_id]);

        // Récupérer le dernier bagage inséré
        $bagage_id = $pdo->lastInsertId();
        $stmt = $pdo->prepare("SELECT * FROM bagage WHERE id = ?");
        $stmt->execute([$bagage_id]);
        $bagage = $stmt->fetch(PDO::FETCH_ASSOC);

        // Réponse JSON avec le bagage ajouté
        echo json_encode($bagage);

    } else {
        echo json_encode(["error" => "Données manquantes"]);
    }

} catch (PDOException $e) {
    // Gestion des erreurs
    echo json_encode(["error" => "Erreur d'ajout de bagage: " . $e->getMessage()]);
}
?>
