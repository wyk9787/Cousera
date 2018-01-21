<!DOCTYPE html>
<html>
  <head>
    <title> Garrett Wang -- PHP </title>
  </head>
  <body>
    <h1> Garrett Wang -- PHP </h1>
    <p>
      <?php
        echo 'The SHA256 hashcode for "Garrett Wang" is';
        print hash('sha256', 'Garrett Wang');
      ?>
    </p>
    <pre>
      ASCII ART:

    *************
    **
    **
    **       ****
    **         **
    **         **
    *************

    </pre>
    <a href="check.php">Click here to check the error setting</a>
    <br>
    <a href="fail.php">Click here to cause a traceback</a>
  </body>
</html>
