<?php
require_once "pdo.php";
session_start();
// Guardian: Make sure that user_id is present
if ( !isset($_SESSION['name']) ) {
  die('Not logged in');
}
if (isset($_POST['Cancel']))
{
  header('Location: index.php');
  return;
}
$stmt = $pdo->prepare("SELECT * FROM Profile where profile_id = :profile_id");
$stmt->execute(array(":profile_id" => $_GET['profile_id']));
$row = $stmt->fetch(PDO::FETCH_ASSOC);
if ( $row === false ) {
    $_SESSION['error1'] = 'Could not load profile'; //This code is from delete
    header( 'Location: index.php' ) ; // error variable is a flash
    return;
}
//Validate new input

if (isset($_POST['first_name']) || isset($_POST['last_name']) || isset($_POST['email']) ||
isset($_POST['headline'])|| isset($_POST['summary']))
{
  //Input Validation when input is entered
  if ( strlen($_POST['first_name']) < 1 || strlen($_POST['last_name']) <1 || strlen($_POST['email'])<1
  || strlen($_POST['headline'])<1 || strlen($_POST['summary']) < 1 )
  {
    $_SESSION['error2'] = "All fields are required";
    header('Location: edit.php?profile_id='.$_REQUEST['profile_id']);
    return;
  }
  else
  {
    // This passed the validation. Insert it into database.
    $sql = "UPDATE Profile SET first_name = :fn, last_name = :ln,
    email = :em, headline = :he, summary = :sm WHERE profile_id = :profile_id";
    $stmt = $pdo->prepare($sql);
    $stmt->execute(array(
      //user_id of the currently logged in user
      ':fn' => $_POST['first_name'],
      ':ln' => $_POST['last_name'],
      ':em' => $_POST['email'],
      ':he' => $_POST['headline'],
      ':sm' => $_POST['summary'],
      ':profile_id'=>$_POST['profile_id']
      )
    );
    $_SESSION['success']  = "Profile updated";
    header("Location: index.php");
    return;
  }
}
else {}
//
if ( isset($_SESSION['error3']) ) {
    echo '<p style="color:red">'.$_SESSION['error3']."</p>\n";
    unset($_SESSION['error3']);}
else{
    $fn = htmlentities($row['first_name']);
    $ln = htmlentities($row['last_name']);
    $em = htmlentities($row['email']);
    $hl = htmlentities($row['headline']);
    $sm = htmlentities($row['summary']);
    $profile_id = $row['profile_id']; // no need to put html entities
}
//cuz you know that its always an integer.
?>
<!DOCTYPE html>
<head>
  <title>Jonathan Teo Jun Rui 58630f91 - Autos Database</title>
  <?php require_once 'bootstrap.php'?>
</head>
<h1>Editing Profile for
<?php
  echo (htmlentities($_SESSION['name']));
  echo "</h1>";
 ?>
<form method="post">
  First Name: &nbsp;<input type = "text" name = "first_name" value = "<?= $fn ?>"> <br>
  Last Name: &nbsp;<input type = "text" name = "last_name" value = "<?= $ln ?>"> <br>
  Email: &nbsp;<input type = "text" name = "email" value = "<?= $em ?>"> <br>
  Headline: <br> <input type = "text" name = "headline" value = "<?= $hl ?>"> <br>
  Summary: <br> <input type = "text" name = "summary" value = "<?= $sm ?>"> <br>
  <input type="hidden" name="profile_id" value="<?= $profile_id ?>">
  <input type = "submit" name = "Save" value = "Save">
  <input type = "submit" name="Cancel" value="Cancel">
</form>
