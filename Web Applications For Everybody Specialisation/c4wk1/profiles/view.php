<?php
session_start();
require_once "pdo.php";

// Guardian: Make sure that user_id is present
if ( ! isset($_GET['profile_id']) ) {
  $_SESSION['error1'] = "Missing profile_id";
  header('Location: index.php');
  return;
}

$stmt = $pdo->prepare("SELECT first_name, last_name, email, headline, summary FROM Profile where profile_id = :profile_id");
$stmt->execute(array(":profile_id" => $_GET['profile_id'])); // Won't blow up cuz its not an error to not find anything!!
$row = $stmt->fetch(PDO::FETCH_ASSOC);
if ( $row === false ) {
    $_SESSION['error'] = 'Could not load profile';
    header( 'Location: index.php' ) ;
    return;
}
$fn = htmlentities($row['first_name']);
$ln = htmlentities($row['last_name']);
$em = htmlentities($row['email']);
$hl = htmlentities($row['headline']);
$sm = htmlentities($row['summary']);
//Program falls into the view only when row can be found.
?>
<!DOCTYPE html>
<html>
<head>
<title>Jonathan Teo Jun Rui 58630f91 - Autos Database</title>
<?php require_once "bootstrap.php"; ?>
</head>
<body>
<div class="container">
  <h1>Profile Information</h1>
  <?php
        echo "<p>First Name: ";
        echo ($fn);
        echo "</p><p> Last Name: ";
        echo ($ln);
        echo "</p><p> Email: ";
        echo ($em);
        echo "</p><p> Headline: <br>";
        echo ($hl);
        echo "</p><p> Summary: <br> ";
        echo ($sm);
        echo ("</p><p><a href = 'index.php'> Done </a></p>");
        echo "</p>";
  ?>
  </div>
  </body>
  </html>
