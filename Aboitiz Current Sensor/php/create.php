<?php
$servername = "localhost";
$username = "root";
$password = "root";
$dbname = "aboitiz";
$tablename = "test";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

// sql to create table
$sql = "CREATE TABLE `aboitiz`.`test` ( `ID` INT NOT NULL AUTO_INCREMENT , `TIMES` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP , `VOLTAGE` DOUBLE NOT NULL , `CURRENT` DOUBLE NOT NULL , PRIMARY KEY (`ID`)) ENGINE = InnoDB";

if ($conn->query($sql) === TRUE) {
    echo "Table MyGuests created successfully";
} else {
    echo "Error creating table: " . $conn->error;
}

$conn->close();
?>