<?php
session_start(); // Démarrer la session
header("Content-Security-Policy: default-src 'self'; style-src 'self' 'https://fonts.googleapis.com'; font-src 'self' 'https://fonts.gstatic.com'; script-src 'self'; img-src 'self' 'https://www.thalesgroup.com';");
include 'db.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    try {
        $date_debut = $_POST['date_debut'];
        $date_fin = $_POST['date_fin'];
        $lieu = $_POST['lieu'];
        $etat = 'Préparation';
        $bagages_ids = isset($_POST['bagages_ids']) ? $_POST['bagages_ids'] : [];

        // Insérer le nouveau voyage
        $stmt = $pdo->prepare("INSERT INTO voyage (date_debut, date_fin, lieu, etat) VALUES (?, ?, ?, ?)");
        if ($stmt->execute([$date_debut, $date_fin, $lieu, $etat])) {
            // Récupérer l'ID du voyage inséré
            $voyageId = $pdo->lastInsertId();

            // Mettre à jour la colonne voyages_ids pour chaque bagage sélectionné
            $selectStmt = $pdo->prepare("SELECT voyages_ids FROM bagage WHERE id = ?");
            $updateStmt = $pdo->prepare("UPDATE bagage SET voyages_ids = ? WHERE id = ?");

            foreach ($bagages_ids as $bagageId) {
                // Charger les valeurs actuelles de voyages_ids
                $selectStmt->execute([$bagageId]);
                $currentIds = $selectStmt->fetchColumn();

                // Convertir la liste actuelle en tableau
                $currentIdsArray = $currentIds ? explode(',', $currentIds) : [];

                // Ajouter l'ID du voyage sans duplicata
                if (!in_array($voyageId, $currentIdsArray)) {
                    $currentIdsArray[] = $voyageId;
                }

                // Reconstruire la liste en chaîne de caractères
                $newIdsString = implode(',', $currentIdsArray);

                // Mettre à jour la base de données
                $updateStmt->execute([$newIdsString, $bagageId]);
            }

            // Notification de succès
            $_SESSION['notification'] = "Voyage ajouté avec succès.";
            header("Location: ../../pages/visualiser_voyage.php?id=" . $voyageId);
        } else {
            throw new Exception("Erreur lors de l'ajout du voyage.");
        }
    } catch (Exception $e) {
        // Gestion des erreurs
        $_SESSION['notification'] = "Erreur : " . $e->getMessage();
        header("Location: ../../index.php");
    }
    exit();
}
?>

