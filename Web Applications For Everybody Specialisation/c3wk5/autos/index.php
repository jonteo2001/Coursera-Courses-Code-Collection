<?php
session_start();
require_once "pdo.php";
if (isset($_POST['logout']) ) {
    header('Location: logout.php');
    return;
}

$stmt = $pdo->query("SELECT make, model, year, mileage, autos_id FROM autos");
$rows = $stmt->fetchAll(PDO::FETCH_ASSOC);
?>
<!DOCTYPE html>
<html>
<head>
<title>Jonathan Teo Jun Rui 58630f91 - Automobile Database</title>
<?php require_once "bootstrap.php"; require_once "pdo.php";?>
</head>
<body>
<div class="container">
<h1>Welcome to the Automobiles Database</h1>
<p><strong>Note:</strong> Course 3 Week 5 Assignment
</p>
<?php
if (!isset ($_SESSION['name']))
{
  echo("
  <p>
  <a href='login.php'>Please log in</a>
  </p>
  <p>
  Attempt to
  <a href='add.php'>add data</a> without logging in.
  </p>");
}
else
{
  if (isset($_SESSION['success']) ) {
    echo('<p style="color: green;">'.htmlentities($_SESSION['success'])."</p>\n");
    unset($_SESSION['success']);
  }
  if (isset($_SESSION['error1']))
  {
    echo('<p style="color: red;">'.htmlentities($_SESSION['error1'])."</p>\n");
    unset($_SESSION['error1']);
  }
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
        echo('<a href="edit.php?autos_id='.$row['autos_id'].'">Edit</a> / ');
        //anchor tag
        echo('<a href="delete.php?autos_id='.$row['autos_id'].'">Delete</a>');
        echo "</td></tr>";
      }
      echo "</table>";
    }
  echo ("
  <p><a href = 'add.php'> Add New Entry </a> </p>
  <p><a href = 'logout.php'> Logout </a> </p>
  ");
}

?>
</div>
</body>
</html>
