<?php
$servername = "localhost";
$username = "root";
$password = "root";
$db_name = "aboitiz";
$tablename = "test";


$link = mysqli_connect($servername, $username, $password, $db_name);

if (!$link) {
    die("Connection failed: " . mysqli_connect_error());
}

if ($result = mysqli_query($link,"SELECT ID,TIMES,VOLTAGE,CURRENT FROM $tablename")){
  while ($row = mysqli_fetch_row($result)){
    $row_json = json_encode($row);
    echo $row_json;
  }
  mysqli_free_result($result);
}

mysqli_close($con);
?>
