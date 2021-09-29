<?php
require_once "pdo.php";
require_once "util.php";
session_start();
// Guardian: Make sure that user_id is present
if ( !isset($_SESSION['name']) ) {
  die('ACCESS DENIED');
}
if (isset($_POST['Cancel']))
{
  header('Location: index.php');
  return;
}
//Prepare profile from database
$stmt = $pdo->prepare("SELECT * FROM Profile WHERE profile_id = :profile_id");
$stmt->execute(array(":profile_id" => $_GET['profile_id']));
$row = $stmt->fetch(PDO::FETCH_ASSOC);
if ( $row === false ) {
    $_SESSION['error1'] = 'Could not load profile'; //This code is from delete
    header( 'Location: index.php' ) ; // error variable is a flash
    return;
}
//Validate new input
if (isset($_POST['Save']))
{
  //Input Validation when input is entered
    $msg = validateProfile();
    if (is_string($msg)) //If you got a string it is an error!
    {
      $_SESSION['error2'] = $msg;
      header('Location: edit.php?profile_id='.$_REQUEST['profile_id']);
      return;
    }
    //Validate position entries if present
    $msg = validatePos();
    if(is_string($msg))
    {
      $_SESSION['error2']=$msg;
      header('Location: edit.php?profile_id='.$_REQUEST['profile_id']);
      return;
    }
    // This passed the validation. Insert it into database.
    $sql = "UPDATE Profile SET first_name = :fn, last_name = :ln,
    email = :em, headline = :he, summary = :sm WHERE profile_id = :profile_id";
    $stmt = $pdo->prepare($sql);
    $stmt->execute(array(//user_id of the currently logged in user
      ':fn' => $_POST['first_name'],
      ':ln' => $_POST['last_name'],
      ':em' => $_POST['email'],
      ':he' => $_POST['headline'],
      ':sm' => $_POST['summary'],
      ':profile_id' => $_POST['profile_id']
      )
    );

    // Clear out the old position entries
    $stmt = $pdo->prepare('DELETE FROM Position WHERE profile_id=:profile_id');
    $stmt->execute(array( ':profile_id' => $_REQUEST['profile_id']));

    // Insert the position entries
    $rank = 1;
    for($i=1; $i<=9; $i++) {
      if ( ! isset($_POST['year'.$i]) ) {continue;}
      if ( ! isset($_POST['desc'.$i]) ) {continue;}
      $year = $_POST['year'.$i];
      $desc = $_POST['desc'.$i];
      $stmt = $pdo->prepare('INSERT INTO Position
        (profile_id, rank, year, description)
        VALUES ( :profile_id, :rank, :year, :desc)');

      $stmt->execute(array(
      ':profile_id' => $_REQUEST['profile_id'],
      ':rank' => $rank,
      ':year' => $year,
      ':desc' => $desc)
      );

      $rank++;
    }
    $_SESSION['success']  = "Profile updated";
    header("Location: index.php");
    return;
}
else {}
//
if(!isset($_SESSION['error3']))//No error, row found so go find this
{
    $fn = htmlentities($row['first_name']);
    $ln = htmlentities($row['last_name']);
    $em = htmlentities($row['email']);
    $hl = htmlentities($row['headline']);
    $sm = htmlentities($row['summary']);
    $profile_id = $row['profile_id']; // no need to put html entities
    //Load up the position rows
    $positions = loadPos($pdo, $_REQUEST['profile_id']);
}
else {}
//cuz you know that its always an integer.
?>
<!DOCTYPE html>
<head>
  <title>Jonathan Teo Jun Rui 58630f91 - Profile Registry</title>
  <?php require_once "head.php" ?>
</head>
<h1>Editing Profile for
<?php
  echo (htmlentities($_SESSION['name']));
  echo "</h1>";
 ?>
 <?php
 flashMessages();
 ?>
<form method="post">
  First Name: &nbsp;<input type = "text" name = "first_name" value = "<?= $fn ?>"> <br>
  Last Name: &nbsp;<input type = "text" name = "last_name" value = "<?= $ln ?>"> <br>
  Email: &nbsp;<input type = "text" name = "email" value = "<?= $em ?>"> <br>
  Headline: <br> <input type = "text" name = "headline" value = "<?= $hl ?>"> <br>
  <p> Summary:<br> <textarea name = "summary" rows = "8" cols = "80"><?= $sm ?></textarea></p> <br>
  <input type="hidden" name="profile_id" value="<?= $profile_id ?>">
  <!-- Adding position fields -->
  <p> Position: <input type = "submit" id = "addPos" value = "+">
    <div id = "position_fields">
    </div>
  </p>
  <input type = "submit" name = "Save" value = "Save">
  <input type = "submit" name="Cancel" value="Cancel">
</form>
<script>
    countPos = 0;
    // http://stackoverflow.com/questions/17650776/add-remove-html-inside-div-using-javascript
    $(document).ready(function () {
        window.console && console.log('Document ready called');
        $('#addPos').click(function (event) {
            // http://api.jquery.com/event.preventdefault/
            event.preventDefault();
            if (countPos >= 9) {
                alert("Maximum of nine position entries exceeded");
                return;
            }
            countPos++;
            window.console && console.log("Adding position " + countPos);
            $('#position_fields').append(
                '<div id="position' + countPos + '"> \
    <p>Year: <input type="text" name="year' + countPos + '" value="" /> \
    <input type="button" value="-" \
        onclick="$(\'#position' + countPos + '\').remove();return false;"></p> \
    <textarea name="desc' + countPos + '" rows="8" cols="80"></textarea>\
    </div>');
        });
    });
</script>
</div>
</html>
