<?php
session_start(); // Démarrer la session
header("Content-Security-Policy: default-src 'self'; style-src 'self' 'https://fonts.googleapis.com'; font-src 'self' 'https://fonts.gstatic.com'; script-src 'self'; img-src 'self' 'https://www.thalesgroup.com';");
include 'db.php';

if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['id'])) {
    $id = $_POST['id'];

    // Préparez la requête pour supprimer le voyage
    $stmt = $pdo->prepare("DELETE FROM voyage WHERE id = ?");
    if ($stmt->execute([$id])) {
        $_SESSION['notification'] = "Le voyage a été supprimé avec succès.";
    } else {
        $_SESSION['notification'] = "Erreur lors de la suppression du voyage.";
    }

    header("Location: ../../index.php"); // Rediriger vers la page d'accueil
    exit();
} else {
    $_SESSION['notification'] = "ID de voyage non fourni.";
    header("Location: ../../index.php");
    exit();
}
?>
