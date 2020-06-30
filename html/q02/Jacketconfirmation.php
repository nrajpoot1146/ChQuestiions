<?php

$yourName = "Programmed by: {your full name goes here}"; //put your name here;
echo("<h1>Comapny Spring Retreat</h1>");
echo("<h3>Jacket Order: Confirmation</h3>");
echo("<h3>For you, we will order a jacket in ".$_POST['color']." and size ".$_POST['size']." for a ".$_POST['gender']." employee.</h3>"); //show this message to user
echo("<h2 style='position: fixed; bottom: 0; top: auto; width:100%; text-align:center;' >$yourName</h2>");//footer message