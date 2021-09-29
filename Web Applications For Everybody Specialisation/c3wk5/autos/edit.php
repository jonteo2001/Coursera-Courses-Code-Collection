<?php
require_once "pdo.php";
session_start();
// Guardian: Make sure that user_id is present
if ( ! isset($_GET['autos_id']) ) {
  $_SESSION['error'] = "Missing autos_id"; //error variable is a flash
  header('Location: index.php');
  return;
}
$stmt = $pdo->prepare("SELECT * FROM autos where autos_id = :autos_id");
$stmt->execute(array(":autos_id" => $_GET['autos_id']));
$row = $stmt->fetch(PDO::FETCH_ASSOC);
if ( $row === false ) {
    $_SESSION['error'] = 'Bad value for autos_id'; //This code is from delete
    header( 'Location: index.php' ) ; // error variable is a flash
    return;
}
if (isset($_POST['Cancel']))
{
  header('Location: index.php');
  return;
}
//Validate new input
if ( isset($_POST['make']) && isset($_POST['model']) //enter with get req
     && isset($_POST['year']) && isset($_POST['mileage']) )
{
     if ( strlen($_POST['make']) < 1 || strlen($_POST['model']) <1 || strlen($_POST['year'])<1
     || strlen($_POST['mileage'])<1  )
     {
       $_SESSION['error3'] = "All fields are required";
       header("Location: edit.php?autos_id=".$_REQUEST['autos_id']);
       return;
     }
     else if (!(is_numeric($_POST['year'])) )
     {
       $_SESSION['error3'] = "Year must be numeric";
       header("Location: edit.php?autos_id=".$_REQUEST['autos_id']);
       return;
     }
     else if( !(is_numeric($_POST['mileage'])) )
     {
       $_SESSION['error3'] = "Mileage must be numeric";
       header("Location: edit.php?autos_id=".$_REQUEST['autos_id']);
       return;
     }
     else
     {
       // This passed the validation. Insert it into database.
       $sql = "UPDATE autos SET make = :mk,
               model = :mo, year = :yr, mileage = :mi
               WHERE autos_id = :autos_id"; // column = placeholder.
       $stmt = $pdo->prepare($sql); //use prepared statements! Avoid SQL injections!
       $stmt->execute(array(
           ':mk' => $_POST['make'],
           ':mo' => $_POST['model'],
           ':yr' => $_POST['year'],
           ':mi' => $_POST['mileage'],
           ':autos_id' => $_POST['autos_id']));//hidden field
       $_SESSION['success'] = 'Record edited'; // flash message
       header( 'Location: index.php' ) ; //get request to index.php
       return; // browser does a GET request to index.php.
     }
}
if ( isset($_SESSION['error3']) ) {
    echo '<p style="color:red">'.$_SESSION['error3']."</p>\n";
    unset($_SESSION['error3']);}
else{
    $mk = htmlentities($row['make']);
    $mo = htmlentities($row['model']);
    $yr = htmlentities($row['year']);
    $mi = htmlentities($row['mileage']);
    $autos_id = $row['autos_id']; // no need to put html entities
}
//cuz you know that its always an integer.
?>
<!DOCTYPE html>
<head>
  <title>Jonathan Teo Jun Rui 58630f91 - Autos Database</title>
  <?php require_once 'bootstrap.php'?>
</head>
<h1>Editing Automobile</h1>
<form method="post">
  Make: &nbsp;<input type = "text" name = "make" value = "<?= $mk ?>"> <br>
  Model: &nbsp;<input type = "text" name = "model" value = "<?= $mo ?>"> <br>
  Year: &nbsp;<input type = "text" name = "year" value = "<?= $yr ?>"> <br>
  Mileage: &nbsp;<input type = "text" name = "mileage" value = "<?= $mi ?>"> <br>
  <input type="hidden" name="autos_id" value="<?= $autos_id ?>">
  <input type = "submit" name = "Save" value = "Save">
  <input type = "submit" name="Cancel" value="Cancel">
</form>
