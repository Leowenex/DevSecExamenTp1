<?php
function createUserDir($username) {
if (!preg_match('/^[a-zA-Z0-9_-]+$/', $username)) {
   return false;
}
$path = '/home/' . $username;
if (!mkdir($path, 0700)) {
   return false;
}
if (!chown($path, $username)) {
   rmdir($path);
   return false;
}
   return true;
}
?>
