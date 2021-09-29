<?php
// Note - cannot have any output before setcookie
if ( ! isset($_COOKIE['cap']) ) {
    setcookie('cap', '36', time()+3600);
}//Remember the key is unique, the value may not be unique.
?>
<pre>
<?php print_r($_COOKIE); ?>
</pre>
<p><a href="cookie.php">Click Me!</a> or press Refresh</p>
