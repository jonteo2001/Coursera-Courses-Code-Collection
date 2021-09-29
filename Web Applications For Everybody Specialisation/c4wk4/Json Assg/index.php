<?php
session_start();
require_once "pdo.php";
require_once "util.php";
if (isset($_POST['logout']) ) {
    header('Location: logout.php');
    return;
}

$stmt = $pdo->query("SELECT first_name, last_name, headline,profile_id FROM Profile");
$rows = $stmt->fetchAll(PDO::FETCH_ASSOC);
?>
<!DOCTYPE html>
<html>
<head>
<title>Jonathan Teo Jun Rui 58630f91 - Profile Registry</title>
<?php require_once "bootstrap.php"; require_once "pdo.php";?>
</head>
<body>
<div class="container">
<h1>Jonathan Teo's Resume Registry</h1>
<?php
if (isset($_SESSION['name']))
{
  echo("<p><a href = 'logout.php'> Logout </a> </p>");
}
?>
<p><strong>Note:</strong> Course 4 Week 4 Assignment
</p>
<?php
if (!isset ($_SESSION['name']))
{
  echo("
  <p>
  <a href='login.php'>Please log in</a>
  </p>
  ");
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
}
//Below code runs irregardless whether there is a session[name] variable.
if (count($rows) == 0){echo "No rows found";}
else{
    echo "<table style = 'width:60%; border:1px solid black;'>
    <tr><th style = 'border:1px solid black;'>Name</th>
    <th style = 'border:1px solid black;'>Headline</th>";
    if (isset($_SESSION['name']))
    {
      echo "<th style = 'border:1px solid black;'>Action</th></tr>";
    }
    else{ echo "</tr>";}
    foreach( $rows as $row)
    {
      $fn = htmlentities($row['first_name']);
      $ln = htmlentities($row['last_name']);
      $nam = "$fn"." "."$ln";
      echo "<tr><td style = 'border:1px solid black;'>";
      echo('<a href="view.php?profile_id='.$row['profile_id'].'">'."$nam".'</a>');
      echo "</td><td style = 'border:1px solid black;'>";
      echo (htmlentities($row['headline']));
      if(isset($_SESSION['name']))
      {
        echo "</td><td style = 'border:1px solid black;'>";
        echo('<a href="edit.php?profile_id='.$row['profile_id'].'">Edit</a> ');
        //anchor tag
        echo('<a href="delete.php?profile_id='.$row['profile_id'].'">Delete</a>');
        echo "</td></tr>";
      }
      else
      {
        echo "</td></tr>";
      }
    }
      echo "</table>";
    }
  if (isset($_SESSION['name']))
  {
    echo ("
    <p><a href = 'add.php'> Add New Entry </a> </p>
    ");
  }



?>
</div>
</body>
</html>
