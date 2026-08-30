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

    // Commencer une transaction pour garantir la cohérence
    $pdo->beginTransaction();

    // Supprimer les éléments associés au bagage
    $sql_delete_elements = "DELETE FROM element WHERE bagages_ids = :bagage_id";
    $stmt_delete_elements = $pdo->prepare($sql_delete_elements);
    $stmt_delete_elements->bindParam(':bagage_id', $bagage_id, PDO::PARAM_INT);

    if (!$stmt_delete_elements->execute()) {
        throw new Exception("Erreur lors de la suppression des éléments du bagage.");
    }

    // Supprimer le bagage
    $sql_delete_bagage = "DELETE FROM bagage WHERE id = :bagage_id";
    $stmt_delete_bagage = $pdo->prepare($sql_delete_bagage);
    $stmt_delete_bagage->bindParam(':bagage_id', $bagage_id, PDO::PARAM_INT);

    if (!$stmt_delete_bagage->execute()) {
        throw new Exception("Erreur lors de la suppression du bagage.");
    }

    // Valider la transaction
    $pdo->commit();

    echo "Bagage et ses éléments supprimés avec succès.";

} catch (Exception $e) {
    // Annuler la transaction en cas d'erreur
    $pdo->rollBack();
    echo "Erreur : " . $e->getMessage();
}
?>
