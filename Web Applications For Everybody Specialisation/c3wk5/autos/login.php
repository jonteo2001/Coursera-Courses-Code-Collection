<?php // Do not put any HTML above this line
session_start();
require_once "pdo.php";
if ( isset($_POST['cancel'] ) ) {
    // Redirect the browser to index.php
    header("Location: index.php");
    return;
}

$salt = 'XyZzy12*_';
$stored_hash = '1a52e17fa899cf40fb04cfc42e6352f1';

// Check to see if we have some POST data, if we do process it
if ( isset($_POST['email']) || isset($_POST['pass']) )
{
    if (strlen($_POST['email']) < 1 || strlen($_POST['pass'])<1)
    {
      $_SESSION['error1'] = "User name and password are required.";
      header('Location: login.php');
      return;
    }
    else
    {
        $check = hash('md5', $salt.$_POST['pass']);
        if ( $check == $stored_hash )
        {
          //Redirect browser to add.php
          $_SESSION['name'] = $_POST['email'];
          //error_log ("Login success ". $_POST['who']);
          header('Location: index.php');
          return;
        }
        else
        {
          $_SESSION['error1'] = "Incorrect password";
          header("Location: login.php");
          return;
        }
    }
}
else{}//When there is no input the php code will exit in this empty else loop.
// Fall through into the View
?>
<!DOCTYPE html>
<html>
<head>
<?php require_once "bootstrap.php"; ?>
<title>Jonathan Teo Jun Rui 58630f91 - Automobiles Database</title>
</head>
<body>
<div class="container">
<h1>Please Log In</h1>
<?php
// Note triple not equals and think how badly double
// not equals would work here...
if ( isset($_SESSION['error1']) ) {
  echo('<p style="color: red;">'.htmlentities($_SESSION['error1'])."</p>\n");
  unset($_SESSION['error1']);
}

?>
<form method="POST">
<label for="email">User Name</label>
<input type="text" name="email"><br/>
<label for="pass">Password</label>
<input type="text" name="pass"><br/>
<input type="submit" value="Log In">
<a href = "index.php">Cancel </a>
</form>
<p>
For a password hint, view source and find a password hint
in the HTML comments.
<!-- Hint: The password is the four character sound a cat
makes (all lower case) followed by 123. -->
</p>
</div>
</body>
