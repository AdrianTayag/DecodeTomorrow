<?php

//CREATE TABLE `aboitiz`.`test` ( `ID` INT NOT NULL AUTO_INCREMENT , `TIMES` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP , `VOLTAGE` DOUBLE NOT NULL , `CURRENT` DOUBLE NOT NULL , PRIMARY KEY (`ID`)) ENGINE = InnoDB;

$servername = "localhost";
$username = "root";
$password = "root";
$dbname = "aboitiz";
$tablename = "test";

/* Attempt to connect to MySQL database */
$link = mysqli_connect($servername, $username, $password,$dbname);
 
// Check connection
if($link === false){
    die("ERROR: Could not connect. " . mysqli_connect_error());
}

date_default_timezone_set("Asia/Singapore");

$stmt = mysqli_prepare($link, "INSERT INTO test (VOLTAGE, CURRENT) VALUES (?,?)");
echo "prepare";
if($stmt === FALSE){ die(mysqli_error($link));}
mysqli_stmt_bind_param($stmt, 'dd',$voltage,$current);

$voltage = $_GET['voltage'];
$current = $_GET['current'];

$result = mysqli_stmt_execute($stmt);
echo "exec";
if(!$result)
	die("Invalid query: " . mysqli_error($link));

echo "success";
mysqli_stmt_close($stmt);
mysqli_close($link);
?>
