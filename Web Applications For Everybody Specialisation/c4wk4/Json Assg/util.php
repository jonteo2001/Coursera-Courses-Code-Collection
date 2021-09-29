<?php
require_once "pdo.php";
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
            return "Year must be numeric";
        }
    }
    return true;
}

function validateEdu()
{
for ($i = 1; $i <= 9; $i++) {
    if (!isset($_POST['edu_year' . $i])) continue;
    if (!isset($_POST['edu_school' . $i])) continue;

    $edu_year = $_POST['edu_year' . $i];
    $edu_name = $_POST['edu_school' . $i];

    if (strlen($edu_year) == 0 || strlen($edu_name) == 0) {
        return "All fields are required";
    }

    if (!is_numeric($edu_year)) {
        return "Year must be numeric";
    }
  }#end for
  return true;
}
/*Note what fetchAll() does:
$profiles = array();
while (row = stmt->fetch(PDO::FETCH_ASSOC))
{
  $profiles[] = $row;
}
*/
function insertPositions($pdo, $profile_id)
{
  //Insert position entries
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
    ':profile_id' => $profile_id,
    ':rank' => $rank,
    ':year' => $year,
    ':desc' => $desc)
    );
    $rank++;
  }
}
function insertEducations($pdo, $profile_id)
{
  $rank = 1;
  for($i = 1; $i <=9; $i++)
  {
    if (!isset ($_POST['edu_year'.$i])) continue;
    if (!isset ($_POST['edu_school'.$i])) continue;
    $year = $_POST ['edu_year'.$i];
    $school = $_POST ['edu_school'.$i];

    //Look up school if it is there
    $institution_id = false;
    $stmt = $pdo->prepare('SELECT institution_id FROM Institution WHERE name = :name');
    $stmt->execute (array(':name' =>$school));
    $row = $stmt->fetch(PDO::FETCH_ASSOC);
    if($row!== false){$institution_id = $row['institution_id'];}
    //Row is not false means you found a match
    //In the case that there was no match, insert it
    if ($institution_id === false)
    {
      $stmt = $pdo->prepare('INSERT INTO Institution (name) VALUES (:name)');
      $stmt->execute(array(':name' => $school));
      $institution_id = $pdo->lastInsertId();
    }
    //Only after inserting the new school, then insert the entry into DB
    $stmt = $pdo->prepare('INSERT INTO Education (profile_id, rank, year, institution_id)
    VALUES (:profile_id, :rank, :year, :iid)');
    $stmt->execute(array(
      ':profile_id'=> $profile_id,
      ':rank' => $rank,
      ':year' => $year,
      ':iid' => $institution_id)
    );
    $rank++;
  }
}
function loadPos($pdo, $profile_id)
{
  $stmt = $pdo->prepare('SELECT * FROM Position
  WHERE profile_id = :profile_id ORDER BY rank');
  $stmt->execute(array(':profile_id' => $profile_id));
  $positions = $stmt->fetchAll(PDO::FETCH_ASSOC);
  return $positions;
}
function loadEdu($pdo, $profile_id)
{
  $stmt = $pdo->prepare('SELECT year, name FROM Education JOIN Institution ON
    Education.institution_id = Institution.institution_id
    WHERE profile_id = :profile_id ORDER BY rank');
  $stmt->execute(array(':profile_id' => $profile_id));
  $educations = $stmt->fetchAll(PDO::FETCH_ASSOC);
  return $educations;
}
