<?php
session_start();
require_once "pdo.php";
require_once "util.php";

if ( !isset($_SESSION['name']) ) {
  die('ACCESS DENIED');
}
if (isset($_POST['Cancel']))
{
  header('Location: index.php');
  return;
}
//validate profile input
if (isset($_POST['Add']))
{
  //Input Validation when input is entered
    $msg = validateProfile();
    if (is_string($msg)) //If you got a string it is an error!
    {
      $_SESSION['error2'] = $msg;
      header('Location: add.php');
      return;
    }
    //Validate position entries if present
    $msg = validatePos();
    if(is_string($msg))
    {
      $_SESSION['error2']= $msg;
      header('Location: add.php');
      return;
    }
    // This passed the validation. Insert it into database.
    $stmt = $pdo->prepare('INSERT INTO Profile (user_id, first_name, last_name,
    email, headline, summary) VALUES ( :uid, :fn, :ln, :em, :he, :su)');
    $stmt->execute(array(
      ':uid' => $_SESSION['user_id'],//Mark entry with foreign key
      //user_id of the currently logged in user
      ':fn' => $_POST['first_name'],
      ':ln' => $_POST['last_name'],
      ':em' => $_POST['email'],
      ':he' => $_POST['headline'],
      ':su' => $_POST['summary']
      )
    );//Insert operation complete. now obtain profile_id
    $profile_id = $pdo->lastInsertId();
    //Insert the position entries
    $rank = 1;
    for ($i = 1; $i <= 9; $i++)
    {
      if(!isset($_POST['year'.$i])){continue;}
      if(!isset($_POST['desc'.$i])){continue;}
      $year = $_POST['year'.$i];
      $desc = $_POST['desc'.$i];
      $stmt = $pdo->prepare('INSERT INTO Position (profile_id, rank, year, description)
        VALUES ( :profile_id, :rank, :year, :desc)');
      $stmt->execute(array(
        ':profile_id' => $profile_id, //set a foreign key
        ':rank' => $rank,
        ':year' => $year,
        ':desc' => $desc)
      );
      $rank++; //They will show up in the following order in the view.php screen.
    }
    $_SESSION['success']  = "Profile added";
    header("Location: index.php");
    return;
}
else{}
?>
<!DOCTYPE html>
<html>
<head>
  <title>Jonathan Teo Jun Rui 58630f91 - Profile Registry</title>
  <?php require_once "head.php"?>
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
  flashMessages();
  ?>
<form method="post">
First Name: &nbsp;<input type = "text" name = "first_name"> <br>
Last Name: &nbsp;<input type = "text" name = "last_name"> <br>
Email: &nbsp;<input type = "text" name = "email"> <br>
Headline:<br> <input type = "text" name = "headline"> <br>
<p> Summary:<br> <textarea name = "summary" rows = "8" cols = "80"></textarea></p>
<!-- Adding position fields -->
<p> Position: <input type = "submit" id = "addPos" value = "+">
  <div id = "position_fields">
  </div>
</p>
<p>
<input type = "submit" name = "Add" value = "Add">
<input type = "submit" name="Cancel" value="Cancel">
</p>
</form>
<script>
  countPos = 0;
  $(document).ready(function()
  {
    window.console && console.log("Document ready called");
    $('#addPos').click(function(event) //register event when we click on the plus
      {//http://api.jquery.com/event.preventdefault/
        event.preventDefault();
        if(countPos >= 9)//remember variables are global
        {
          alert("Maximum of nine position entries exceeded");
          return;
        }
        countPos++; //Adding 1 each time.
        window.console && console.log("Adding position "+countPos);
        $('#position_fields').append(
          '<div id = "position'+countPos+'"> \
          <p>Year: <input type= "text" name = "year'+countPos+'" value = "" /> \
          <input type = "button" value = "-" \
            onclick = "$(\'#position'+countPos+'\').remove(); return false;"></p> \
            <textarea name = "desc'+countPos+'" rows = "8" cols= "80"></textarea>\
            </div>');
            //The onclick minus button has the countPos variable such that when you
            //click the minus button, the div with ID position 1 disappears.
      });
  });
</script>
</div>
</body>
</html>
