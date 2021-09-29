<?php
require_once "pdo.php";
// Demand a GET parameter
if ( ! isset($_GET['name']) || strlen($_GET['name']) < 1  ) {
    die('Name parameter missing');
}

// If the user requested logout go back to index.php
if ( isset($_POST['logout']) ) {
    header('Location: index.php');
    return;
}
//Input Validation when input is entered.
$failure = false;
if (strlen($_POST['make']) < 1){$failure = "Make is required";}
else if (!(is_numeric($_POST['year']) || !(is_numeric($_POST['mileage']))))
{$failure = "Mileage and year must be numeric";}
else
{
  // This passed the validation. Insert it into database.
  $stmt = $pdo->prepare('INSERT INTO autos
    (make, year, mileage) VALUES ( :mk, :yr, :mi)');
  $stmt->execute(array(
    ':mk' => $_POST['make'],
    ':yr' => $_POST['year'],
    ':mi' => $_POST['mileage']),
  );
  $failure = "Record inserted";
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
  if ( isset($_REQUEST['name']) ) {
      echo "\n<h1>";
      echo htmlentities($_REQUEST['name']);
      echo "</h1>\n";
  }
  // Note triple not equals and think how badly double
  // not equals would work here...
  if ($failure === "Record inserted"){
      echo ('<p style= "color: green;">'.htmlentities($failure)."</p>\n");
  }
  else if ( $failure !== false ) {
      // Look closely at the use of single and double quotes
      echo('<p style="color: red;">'.htmlentities($failure)."</p>\n");
  }
  ?>
<form method="post">
<label for = "make"> Make: </label>
<input type = "text" name = "make"> <br>
<label for = "year"> Year: </label>
<input type = "text" name = "year"> <br>
<label for = "mileage"> Mileage: </label>
<input type = "text" name = "mileage"> <br>
<input type = "submit" name = "Add" value = "Add">
<input type="submit" name="logout" value="Logout">
</form>
<h2> Automobiles </h2>
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
?>
</div>
</body>
</html>
