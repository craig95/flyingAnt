<!DOCTYPE html>
<html>

<style>
p.small {
    line-height: 0%;
    text-align:center;
}

</style>
<head>
<meta http-equiv="refresh" content="1">
</head>
<body>

<h1 style="text-align:center">Battelground!</h1>


<p class="small">
<?php
$count = 0;

$myfile = fopen("Source/TempMap.txt", "r") or die("Unable to open file!");
(int ) $readIn = fgets($myfile);
(int) $mapSizeX = $readIn;
while(!feof($myfile)) {

switch (fgetc($myfile)) {

    case '#':
        echo'<img src="wall.png "height="25" width="18">';
        break;
    case ' ':
        echo'<img src="grey-block.png "height="25" width="18">';
        break;


    case ']':
    	echo'<img src="grey-block.png "height="25" width="18">';
    	break;
    case '[':
    	echo'<img src="grey-block.png "height="25" width="18">';
    	break;


    case 'M':
      echo'<img src="character.png "height="25" width="18">';
      break;
    case 'S':
      echo '<img src="character.png "height="25" width="18">';
      break;
    case 'T':
      echo '<img src="character.png "height="25" width="18">';
      break;


    case 'G':
      echo '<img src="monster.png "height="25" width="18">';
      break;
    case 'O':
      echo '<img src="monster.png "height="25" width="18">';
      break;
    case 'E':
      echo '<img src="monster.png "height="25" width="18">';
      break;


    /*default:
      echo'<img src="grey-block.png "height="25" width="18">';
      break;*/
}

$count += 1;
if ($count==$mapSizeX+1){
	echo "<br>";
	$count =0;
}
}

?>

</p>
</body>
</html>
