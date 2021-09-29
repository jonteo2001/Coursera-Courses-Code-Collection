<?php
require_once "pdo.php";
session_start();

if ( isset($_POST['delete']) && isset($_POST['user_id']) ) {
    $sql = "DELETE FROM users WHERE user_id = :zip";
    $stmt = $pdo->prepare($sql);
    $stmt->execute(array(':zip' => $_POST['user_id']));
    $_SESSION['success'] = 'Record deleted';
    header( 'Location: index.php' ) ;
    return;
}

// Guardian: Make sure that user_id is present
if ( ! isset($_GET['user_id']) ) {
  $_SESSION['error'] = "Missing user_id";
  header('Location: index.php');
  return;
}

$stmt = $pdo->prepare("SELECT name, user_id FROM users where user_id = :xyz");
$stmt->execute(array(":xyz" => $_GET['user_id'])); // Won't blow up cuz its not an error to not find anything!!
$row = $stmt->fetch(PDO::FETCH_ASSOC);
if ( $row === false ) {
    $_SESSION['error'] = 'Bad value for user_id';
    header( 'Location: index.php' ) ;
    return;
}

?>
<!--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-
Now that row is defined, we fall into view: -->
<p>Confirm: Deleting <?= htmlentities($row['name']) ?></p>
<!-- note that html entities are called HERE, it is ONLY called
when we take data OUT of the database. We cannot call HTML Entities twice. -->
<form method="post">
<input type="hidden" name="user_id" value="<?= $row['user_id'] ?>">
<!-- hidden value is the user id -->
<input type="submit" value="Delete" name="delete">
<a href="index.php">Cancel</a>
</form>
