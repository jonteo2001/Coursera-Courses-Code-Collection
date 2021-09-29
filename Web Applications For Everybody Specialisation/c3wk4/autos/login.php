<?php // Do not put any HTML above this line
session_start();
require_once "pdo.php";
if ( isset($_POST['cancel'] ) ) {
    // Redirect the browser to index.php
    header("Location: index.php");
    return;
}

$salt = 'XyZzy12*_';
$stored_hash = '1a52e17fa899cf40fb04cfc42e6352f1';  // Pw is meow123

//$failure = false;  // If we have no POST data

// Check to see if we have some POST data, if we do process it
if ( isset($_POST['email']) && isset($_POST['pass']) )
{
    if (!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL))
    {//Validate @ for email
      $_SESSION['error'] = "Email must have an at-sign (@)";
      header("Location: login.php");
      return;
    }
    else if ( strlen($_POST['email']) < 1 || strlen($_POST['pass']) < 1 )
    {
      $_SESSION['error'] = "User name and password are required";
      //error_log ("Login fail. ". $_POST['who']." $check");
      header("Location: login.php");
      return;
    }
    else
    {
        $check = hash('md5', $salt.$_POST['pass']);
        if ( $check == $stored_hash )
        {
          //Redirect browser to view.php
          $_SESSION['name'] = $_POST['email'];
          //error_log ("Login success ". $_POST['who']);
          header('Location: view.php');
          return;
        }
        else
        {
          $_SESSION['error'] = "Incorrect password";
          header("Location: login.php");
          return;
        }
    }
}
// Fall through into the View
?>
<!DOCTYPE html>
<html>
<head>
<?php require_once "bootstrap.php"; ?>
<title>Jonathan Teo Jun Rui 58630f91 - Rock Paper Scissors</title>
</head>
<body>
<div class="container">
<h1>Please Log In</h1>
<?php
// Note triple not equals and think how badly double
// not equals would work here...
if ( isset($_SESSION['error']) ) {
  echo('<p style="color: red;">'.htmlentities($_SESSION['error'])."</p>\n");
  unset($_SESSION['error']);
}

?>
<form method="POST">
<label for="email">User Name</label>
<input type="text" name="email" id="email"><br/>
<label for="id_1723">Password</label>
<input type="text" name="pass" id="id_1723"><br/>
<input type="submit" value="Log In">
<input type="submit" name="cancel" value="Cancel">
</form>
<p>
For a password hint, view source and find a password hint
in the HTML comments.
<!-- Hint: The password is the four character sound a cat
makes (all lower case) followed by 123. -->
</p>
</div>
</body>
