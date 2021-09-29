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

$stmt = $pdo->query("SELECT make, model, year, mileage FROM autos");
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
  <?php
    if (count($rows) == 0){echo "No rows found";}
    else{
      echo "<table style = 'width:60%; border:1px solid black;'>
      <tr><th style = 'border:1px solid black;'>Make</th>
      <th style = 'border:1px solid black;'>Model</th>
      <th style = 'border:1px solid black;'>Year</th>
      <th style = 'border:1px solid black;'>Mileage</th>
      <th style = 'border:1px solid black;'>Action </th></tr>";
      foreach( $rows as $row)
      {
        echo "<tr><td style = 'border:1px solid black;'>";
        echo ($row['make']);
        echo "</td><td style = 'border:1px solid black;'>";
        echo ($row['model']);
        echo "</td><td style = 'border:1px solid black;'>";
        echo ($row['year']);
        echo "</td><td style = 'border:1px solid black;'>";
        echo ($row['mileage']);
        echo "</td><td style = 'border:1px solid black;'>";
        echo ("<p><a href = 'edit.php'> Edit </a> / <a href = 'delete.php'> Delete</a></p>");
        echo "</td></tr>";
      }
      echo "</table>";
    }
  ?>
  <p><a href = 'add.php'> Add New Entry </a> </p>
  <p><a href = 'logout.php'> Logout </a> </p>
  </div>
  </body>
  </html>
