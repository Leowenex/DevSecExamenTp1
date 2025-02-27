<?php
$userName = $_POST["user"];
if (!preg_match('/^[a-zA-Z0-9_-]+$/', $userName)) {
   die("Nom d'utilisateur invalide.");
}
$command = 'ls -l /home/' . escapeshellarg($userName);
system($command);
?>
