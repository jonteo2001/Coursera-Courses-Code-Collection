<?php
session_start();
require_once "pdo.php";
if ( !isset($_SESSION['name']) ) {
  die('ACCESS DENIED');
}
if (isset($_POST['Cancel']))
{
  header('Location: index.php');
  return;
}
if (isset($_POST['make']) || isset($_POST['year']) || isset($_POST['mileage']) ||
isset($_POST['model']))
{
  //Input Validation when input is entered
  if ( strlen($_POST['make']) < 1 || strlen($_POST['model']) <1 || strlen($_POST['year'])<1
  || strlen($_POST['mileage'])<1  )
  {
    $_SESSION['error2'] = "All fields are required";
    header('Location: add.php');
    return;
  }
  else if (!(is_numeric($_POST['year'])) )
  {
    $_SESSION['error2'] = "Year must be numeric";
    header('Location: add.php');
    return;
  }
  else if( !(is_numeric($_POST['mileage'])) )
  {
    $_SESSION['error2'] = "Mileage must be numeric";
    header('Location: add.php');
    return;
  }
  else
  {
    // This passed the validation. Insert it into database.
    $stmt = $pdo->prepare('INSERT INTO autos
      (make, model, year, mileage) VALUES ( :mk, :mo, :yr, :mi)');
    $stmt->execute(array(
      ':mk' => $_POST['make'],
      ':mo' => $_POST['model'],
      ':yr' => $_POST['year'],// no html entities here!
      ':mi' => $_POST['mileage']),
    );
    $_SESSION['success']  = "Record added";
    header("Location: index.php");
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
  <h1>Tracking Automobiles For</h1>
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
Make: &nbsp;<input type = "text" name = "make"> <br>
Model: &nbsp;<input type = "text" name = "model"> <br>
Year: &nbsp;<input type = "text" name = "year"> <br>
Mileage: &nbsp;<input type = "text" name = "mileage"> <br>
<input type = "submit" name = "Add" value = "Add">
<input type = "submit" name="Cancel" value="Cancel">
</form>
</div>
</body>
</html>
