<?php
require_once "pdo.php";
session_start();
if (!isset($_SESSION['name']))
{
  die("ACCESS DENIED");
}
if (isset($_POST['Cancel']))
{
  header('Location: index.php');
  return;
}
if ( isset($_POST['delete']) && isset($_POST['profile_id']) ) {
    $sql = "DELETE FROM Profile WHERE profile_id = :profile_id";
    $stmt = $pdo->prepare($sql);
    $stmt->execute(array(':profile_id' => $_POST['profile_id']));
    $_SESSION['success'] = 'Record deleted';
    header( 'Location: index.php' ) ;
    return;
}

// Guardian: Make sure that user_id is present
if ( ! isset($_GET['profile_id']) ) {
  $_SESSION['error'] = "Missing profile_id";
  header('Location: index.php');
  return;
}

$stmt = $pdo->prepare("SELECT first_name, last_name, profile_id FROM Profile where profile_id = :profile_id");
$stmt->execute(array(":profile_id" => $_GET['profile_id'])); // Won't blow up cuz its not an error to not find anything!!
$row = $stmt->fetch(PDO::FETCH_ASSOC);
if ( $row === false ) {
    $_SESSION['error1'] = 'Could not load profile';
    header( 'Location: index.php' ) ;
    return;
}

?>
<!--\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-
Now that row is defined, we fall into view: -->
<p>Confirm: Deleting
  <?php
    $fn = htmlentities($row['first_name']);
    $ln = htmlentities($row['last_name']);
    echo("<p>First Name: ".$fn."</p>");
    echo("<p>Last Name: ".$ln."</p>");
  ?>
</p>
<!-- note that html entities are called HERE, it is ONLY called
when we take data OUT of the database. We cannot call HTML Entities twice. -->
<form method="post">
<input type="hidden" name="profile_id" value="<?= $row['profile_id'] ?>">
<!-- hidden value is the user id -->
<input type="submit" value="Delete" name="delete">
<input type="submit" value="Cancel" name="cancel">
</form>
