<?php
session_start();
require_once "pdo.php";
if ( !isset($_SESSION['name']) ) {
  die('Not logged in');
}
if (isset($_POST['Cancel']))
{
  header('Location: index.php');
  return;
}
if (isset($_POST['first_name']) || isset($_POST['last_name']) || isset($_POST['email']) ||
isset($_POST['headline'])|| isset($_POST['summary']))
{
  //Input Validation when input is entered
  if ( strlen($_POST['first_name']) < 1 || strlen($_POST['last_name']) <1 || strlen($_POST['email'])<1
  || strlen($_POST['headline'])<1 || strlen($_POST['summary']) < 1 )
  {
    $_SESSION['error2'] = "All fields are required";
    header('Location: add.php');
    return;
  }
  else
  {
    // This passed the validation. Insert it into database.
    $stmt = $pdo->prepare('INSERT INTO Profile (user_id, first_name, last_name,
    email, headline, summary)
    VALUES ( :uid, :fn, :ln, :em, :he, :su)');
    $stmt->execute(array(
      ':uid' => $_SESSION['user_id'],//Mark entry with foreign key
      //user_id of the currently logged in user
      ':fn' => $_POST['first_name'],
      ':ln' => $_POST['last_name'],
      ':em' => $_POST['email'],
      ':he' => $_POST['headline'],
      ':su' => $_POST['summary']
      )
    );
    $_SESSION['success']  = "Profile added";
    header("Location: index.php");
    return;
  }
}
else {}
?>
<!DOCTYPE html>
<html>
<head>
<title>Jonathan Teo Jun Rui 58630f91 - Profile Registry</title>
<?php require_once "bootstrap.php"; ?>
</head>
<body>
<div class="container">
  <h1>Adding Profile for
  <?php
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
First Name: &nbsp;<input type = "text" name = "first_name"> <br>
Last Name: &nbsp;<input type = "text" name = "last_name"> <br>
Email: &nbsp;<input type = "text" name = "email"> <br>
Headline:<br> <input type = "text" name = "headline"> <br>
Summary:<br> <input type = "text" name = "summary"><br>
<input type = "submit" name = "Add" value = "Add">
<input type = "submit" name="Cancel" value="Cancel">
</form>
</div>
</body>
</html>
