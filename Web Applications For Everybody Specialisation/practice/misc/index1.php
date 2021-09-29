<h1> Hello from my first web page with PHP!! </h1>
<p>
<?php
  echo "Hi there. \n ";
  $answer = 6*7;
  echo "The answer is $answer, what ";
  echo "was the question again?\n";
  ?>
</p>
<p> Yay another paragraph.. </p>
<hr>
<p>
  Trying the ternary operator <br>
  <?php
    $www = 123;
    $msg = $www > 100 ? "Large" : "Small";
    echo "First: $msg \n";
    $msg = ($www % 2 == 0)? "Even" : "Odd";
    echo "Second: $msg \n";
    $msg = ($www % 2) ? "Odd": "Even";
    echo "Third: $msg \n";
    ?>
  </p>
  <hr>
  <p> Array within arrays  </p>
  <p>
    <?php
    $products = array (
      'paper' => array(
        'copier' => "Copier & Multipurpose",
        'inkjet' => "Inkjet Printer",
        'laser' => "Laser Printer"),
      'pens' => array(
        'ball' => "ball point",
        'hilite' => "highlighters",
        'marker' => "markers"),
      'misc' => array(
        'tape' => "Sticky Tape",
        'glue' => "Adhesives"),
    );
    echo $products["pens"]["marker"];
    // products sub pens sub markers
    ?>
  </p>
