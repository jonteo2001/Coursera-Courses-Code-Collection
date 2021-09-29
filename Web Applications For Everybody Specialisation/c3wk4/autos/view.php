<?php
session_start();
require_once "pdo.php";
if (!isset ($_SESSION['name']))
{
  die ('Not logged in');
}
if (isset($_POST['logout']) ) {
    header('Location: logout.php');
    return;
}

$stmt = $pdo->query("SELECT make, year, mileage FROM autos");
$rows = $stmt->fetchAll(PDO::FETCH_ASSOC);
?>
<!DOCTYPE html>
<html>
<head>
<title>Jonathan Teo Jun Rui 58630f91 - Autos Database</title>
<?php require_once "bootstrap.php"; ?>
</head>
<body>
<div class="container">
  <h1>Tracking Autos For</h1>
  <?php
      echo "\n<h1>";
      echo htmlentities($_SESSION['name']);//calls htmlentities when we pull data out of DB
      echo "</h1>\n";
  ?>
  <?php
    if (isset($_SESSION['success']) ) {
      echo('<p style="color: green;">'.htmlentities($_SESSION['success'])."</p>\n");
      unset($_SESSION['success']);
    }
  ?>
  <h2>Automobiles</h2>
  <?php
    echo "<ul>";
    foreach( $rows as $row)
    {
      echo "<li>";
      echo ($row['year']);
      echo " ";
      echo ($row['make']);
      echo " / ";
      echo ($row['mileage']);
    }
    echo "</ul>"
  ?>
  <p> <a href = 'add.php'> Add New </a> |
  <a href = 'logout.php'> Logout </a> </p>
  </div>
  </body>
  </html>
