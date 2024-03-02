<?php
$myfile=fopen("status.txt",'w');
    if(isset($_GET['status'])){
    if($_GET['status']=="on"){
        fwrite($myfile,'1');
        echo('LED is on to go back');
        echo('<a href="index.html">click here</a>');
    }elseif($_GET['status']=="off")
    {
        fwrite($myfile,'0');
        echo('LED is off to go back');
        echo('<a href="index.html">click here</a>');
    }
    }
fclose($myfile);
?>