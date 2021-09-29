<?php
function flashMessages(){
  if (isset($_SESSION['success']) ) {
    echo('<p style="color: green;">'.htmlentities($_SESSION['success'])."</p>\n");
    unset($_SESSION['success']);
  }
  if (isset($_SESSION['error1']))
  {
  echo('<p style="color: red;">'.htmlentities($_SESSION['error1'])."</p>\n");
  unset($_SESSION['error1']);
  }
  if (isset ($_SESSION['error2'])) {
    echo('<p style="color: red;">'.htmlentities($_SESSION['error2'])."</p>\n");
    unset($_SESSION['error2']);
  }
  if ( isset($_SESSION['error3']) ) {
    echo '<p style="color:red;">'.htmlentities($_SESSION['error3'])."</p>\n";
    unset($_SESSION['error3']);}
  }
//A bit fo utility code
function validateProfile()
{
  window.console && console.log("Profile is validating!");
  if ( strlen($_POST['first_name']) < 1 || strlen($_POST['last_name']) <1 || strlen($_POST['email'])<1
  || strlen($_POST['headline'])<1 || strlen($_POST['summary']) < 1 )
  {
    return "All fields are required";
  }
  if (strpos($_POST['email'], '@')=== false)
  {
    return "Email address must contain @";
  }
  console.log("Profile is validated!");
  return true;
}
function validatePos()
{
    for ($i = 1; $i <= 9; $i++) {
        if (!isset($_POST['year' . $i])) continue;
        if (!isset($_POST['desc' . $i])) continue;

        $year = $_POST['year' . $i];
        $desc = $_POST['desc' . $i];

        if (strlen($year) == 0 || strlen($desc) == 0) {
            return "All fields are required";
        }

        if (!is_numeric($year)) {
            return "Position year must be numeric";
        }
    }
    return true;
}
function loadPos($pdo, $profile_id)
{
  $stmt = $pdo->prepare('SELECT * FROM Position
  WHERE profile_id = :profile_id ORDER BY rank');
  $stmt->execute(array(':profile_id' => $profile_id));
  $positions = array();
  while ($row = $stmt->fetch(PDO::FETCH_ASSOC))
  {
    $positions[]=$row;
  }
  return $positions;
}
