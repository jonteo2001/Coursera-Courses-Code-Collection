<?php
require_once "pdo.php";
//remember you are not supposed to delete a get request
//If i delete a user id that doesn't exist, it is NOT an error.
if ( isset($_POST['user_id']) ) {
    $sql = "DELETE FROM users WHERE user_id = :zip";
    echo "<pre>\n$sql\n</pre>\n";
    $stmt = $pdo->prepare($sql);
    $stmt->execute(array(':zip' => $_POST['user_id']));
}
?>
<p>Delete A User</p>
<form method="post">
<p>ID to Delete:
<input type="text" name="user_id"></p>
<p><input type="submit" value="Delete"/></p>
</form>
