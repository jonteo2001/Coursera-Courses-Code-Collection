<?php
  // Note - cannot have any output before this
  session_start(); //created $_SESSION variable.
  if ( ! isset($_SESSION['pizza']) ) {
    //On the first request, pizza is not set. So session is empty.
     echo("<p>Session is empty</p>\n");
     $_SESSION['pizza'] = 0; // $pizza variable comes from the server
  } else if ( $_SESSION['pizza'] < 3 ) {
    $_SESSION['pizza'] = $_SESSION['pizza'] + 1;
     echo("<p>Added one...</p>\n");
     //When you hit refresh, its going to see the pizza => 1
  } else {
    session_destroy(); //empties out $_session
    session_start();//Session ID does not change. 
    echo("<p>Session Restarted</p>\n");
  }
?>
<p><a href="sessfun.php">Click Me!</a></p>
<p>Our Session ID is: <?php echo(session_id()); ?></p>
<pre>
<?php print_r($_SESSION); ?>
</pre>
