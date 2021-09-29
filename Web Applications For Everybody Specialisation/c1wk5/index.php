<!DOCTYPE html>
<html lang = "en">
<head>
  <meta charset = "utf-8"/>
  <title> Jonathan Teo PHP </title>
</head>
<body>
  <h1> Jonathan Teo PHP </h1>
    <pre>
        #######
              #
              #
              #
        #     #
        #######
    </pre>
    <p>
      <?php
        print hash('sha256', 'Jonathan Teo');
        $stuff = array('course' => 'PHP-Intro', 'topic' => 'Arrays');
        echo isset($stuff['section']);
      ?>  
    </p>
</body>
</html>
