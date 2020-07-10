<?php
// open T.txt input file
$file = fopen("T.txt","r");
// create new ~T.txt temp outpu file file
$output = fopen("~T.txt","w");

while (!feof($file)){
    // read line from input file
    $line = fgets($file);
    
    // replace int with float
    $line = str_replace("int", "float", $line);

    // write new line to ouput file
    fputs($output, $line);
}

// close output file
fclose($output);
// close input file
fclose($file);

// delete input file
unlink("T.txt");

// rename output file "~T.txt" to "T.txt"
rename("~T.txt", "T.txt");

?>