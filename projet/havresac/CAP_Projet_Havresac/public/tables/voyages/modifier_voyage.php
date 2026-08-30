<?php
session_start(); // Démarrer la session
header("Content-Security-Policy: default-src 'self'; style-src 'self' 'https://fonts.googleapis.com'; font-src 'self' 'https://fonts.gstatic.com'; script-src 'self'; img-src 'self' 'https://www.thalesgroup.com';");
include 'db.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (isset($_POST['action']) && $_POST['action'] === 'update') {
        $id = $_POST['id']; // Assurez-vous d'avoir l'ID du voyage à modifier

        // Récupérer l'état actuel et les dates du voyage
        $stmt = $pdo->prepare("SELECT etat, date_debut, date_fin FROM voyage WHERE id = ?");
        $stmt->execute([$id]);
        $voyage = $stmt->fetch(PDO::FETCH_ASSOC);
        
        if ($voyage) {
            $etatActuel = $_POST['etat'];
            $date_debut = $_POST['date_debut'];
            $date_fin = $_POST['date_fin'];
            $lieu = $_POST['lieu'];

            // Déterminer le nouvel état basé sur les dates
            $nouvelEtat = $etatActuel; // Valeur par défaut

            // Vérifier les conditions pour mettre à jour l'état
            if (strtotime($date_debut) <= time() && strtotime($date_fin) >= time()) {
                $nouvelEtat = 'En cours'; // En cours si la date de début est passée et la date de fin est dans le futur
            } elseif (strtotime($date_fin) < time()) {
                $nouvelEtat = 'Terminé'; // Terminé si la date de fin est déjà passée
            } elseif($nouvelEtat==''){
                $nouvelEtat = 'Préparation';
            }

            // Mettre à jour le voyage avec les nouvelles informations
            $stmt = $pdo->prepare("UPDATE voyage SET date_debut = ?, date_fin = ?, lieu = ?, etat = ? WHERE id = ?");
            if ($stmt->execute([$date_debut, $date_fin, $lieu, $nouvelEtat, $id])) {
                $_SESSION['notification'] = "Le voyage a été modifié avec succès.";
            } else {
                $_SESSION['notification'] = "Erreur lors de la modification du voyage.";
            }

            header("Location: ../../pages/visualiser_voyage.php?id=$id");
            exit();
        } else {
            $_SESSION['notification'] = "Voyage non trouvé.";
            header("Location: ../../pages/visualiser_voyage.php?id=$id");
            exit();
        }
    } else {
        $_SESSION['notification'] = "Action non valide.";
        header("Location: ../../pages/visualiser_voyage.php?id=$id");
        exit();
    }
} else {
    $_SESSION['notification'] = "Méthode de requête non valide.";
    header("Location: ../../pages/visualiser_voyage.php?id=$id");
    exit();
}
?>
