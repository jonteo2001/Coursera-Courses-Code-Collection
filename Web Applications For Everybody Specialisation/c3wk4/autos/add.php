<?php
session_start();
require_once "pdo.php";
if ( !isset($_SESSION['name']) ) {
  die('Not logged in');
}
if (isset($_POST['Cancel']))
{
  header('Location: view.php');
  return;
}
if (isset($_POST['make']) || isset($_POST['year']) || isset($_POST['mileage']))
{
  //Input Validation when input is entered.
  //$failure = false;
  if (strlen($_POST['make']) < 1)
  {
    $_SESSION['error2'] = "Make is required";
    header('Location: add.php');
    return;
  }
  else if (!(is_numeric($_POST['year'])) || !(is_numeric($_POST['mileage'])))
  {
    $_SESSION['error2'] = "Mileage and year must be numeric";
    header('Location: add.php');
    return;
  }
  else
  {
    // This passed the validation. Insert it into database.
    $stmt = $pdo->prepare('INSERT INTO autos
      (make, year, mileage) VALUES ( :mk, :yr, :mi)');
    $stmt->execute(array(
      ':mk' => $_POST['make'],
      ':yr' => $_POST['year'],// no html entities here!
      ':mi' => $_POST['mileage']),
    );
    $_SESSION['success']  = "Record inserted";
    header("Location: view.php");
    return;
  }
}
else {}
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
  // Note triple not equals and think how badly double
  // not equals would work here...
  //Some styling for error msgs
  if (isset ($_SESSION['error2'])) {
      echo('<p style="color: red;">'.htmlentities($_SESSION['error2'])."</p>\n");
      unset($_SESSION['error2']);
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
<input type = "submit" name="Cancel" value="Cancel">
</form>
</div>
</body>
</html>
