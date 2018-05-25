<?php
//This is a program dedicated to lazy people who do not have calculators
//Program accepts a string input of basic arithmetic operators, parse input and evaluate

$input = "5*6/9-8/5-3*9/77*56+346-78";
$num_space = 0;		$num_op = 0;	$useless_char = 0;
$x = "";	$index = 0;	$ans = "";

//number of spaces
for($i=0;$i<strlen($input);$i++)
{
	if($input[$i] == " ")
	{
		$num_space++;
	}
	
	elseif(($input[$i] == "+") || ($input[$i] == "-") || ($input[$i] == "*") || ($input[$i] == "/"))
	{
		$num_op++;
	}
	
	elseif((ord($input[$i])<ord("0")) || (ord($input[$i])>ord("9")))
	{
		$useless_char++;
	}
}

$div_zero = strpos($input,"/0");

//any space?
if($num_space != 0)
{
	echo("NO SPACES!");
}

//division by zero?
elseif($div_zero != null)
{
	echo("NO DIVISION BY ZERO!");
}

//start with operator
elseif(($input[0] == "+") || ($input[0] == "-") || ($input[0] == "*") || ($input[0] == "/"))
{
	echo("DO NOT START WITH AN OPERATOR!");
}

//end with operator
elseif(($input[strlen($input)-1] == "+") || ($input[strlen($input)-1] == "-") || ($input[strlen($input)-1] == "*") || ($input[strlen($input)-1] == "/"))
{
	echo("DO NOT END WITH AN OPERATOR!");
}

elseif($useless_char != 0)
{
	echo("INPUT NO OTHER THAN NUMBERS AND THE FOUR BASIC OPERATORS!");
}

/*elseif(($num_op != 1) && ($num_op != 2))
{
	echo("ONLY 1-2 OPERATORS!");
}*/

//assign covert operation into the array
else
{
	for($i=0;$i<strlen($input);$i++)
	{
		//not the last number
		if((ord($input[$i])>=ord("0")) && (ord($input[$i])<=ord("9")) && ($i != strlen($input)-1))
		{
			$x = $x.$input[$i];
		}
		
		//last number!
		elseif((ord($input[$i])>=ord("0")) && (ord($input[$i])<=ord("9")) && ($i == strlen($input)-1))
		{
			$x = $x.$input[$i];
			$oper[$index] = $x;
		}

		//operator!
		else
		{
			$oper[$index] = $x;
			$index++;
			$oper[$index] = $input[$i];
			$index++;
			$x = "";
		}
	}//end loop

	$num_op_and_number = sizeof($oper);
	if($num_op_and_number < 2*$num_op+1)
	{
		echo("EXTRA OPERATORS IN EXPRESSION!");
	}
	
	else
	{
		//do * and / first
		for($i=0;$i<=$num_op*2;$i++)
		{
			if($oper[$i] == "*")
			{
				$a = $oper[$i-1];
				$b = $oper[$i+1];
				$sub_result = $a*$b;
				$oper[$i+1] = $sub_result;
				$oper[$i-1] = "";
				$oper[$i] = "";
				$i = $i+1;
			}
			
			elseif($oper[$i] == "/")
			{
				$a = $oper[$i-1];
				$b = $oper[$i+1];
				$sub_result = $a/$b;
				$oper[$i+1] = $sub_result;
				$oper[$i-1] = "";
				$oper[$i] = "";
				$i = $i+1;
			}
		}
	
		//do + and - now
		for($i=0;$i<=$num_op*2;$i++)
		{
			if($oper[$i] == "+")
			{
				$temp1 = $i+1;
				while($oper[$temp1] == "")
				{
					$temp1++;
				}
				$b = $oper[$temp1];
				
				$temp2 = $i-1;
				while($oper[$temp2] == "")
				{
					$temp2--;
				}
				$a = $oper[$temp2];
				
				$sub_result = $a+$b;
				$oper[$temp1] = $sub_result;
				$oper[$temp2] = "";
				$oper[$i] = "";
				$i = $i+1;
			}
		
			elseif($oper[$i] == "-")
			{
				$temp1 = $i+1;
				while($oper[$temp1] == "")
				{
					$temp1++;
				}
				$b = $oper[$temp1];
				
				$temp2 = $i-1;
				while($oper[$temp2] == "")
				{
					$temp2--;
				}
				$a = $oper[$temp2];
			
				$sub_result = $a-$b;
				$oper[$temp1] = $sub_result;
				$oper[$temp2] = "";
				$oper[$i] = "";
				$i = $i+1;
			}
		}
	
		//get the answer hidden in the array
		for($i=0;$i<=$num_op*2;$i++)
		{
			$ans = $ans.$oper[$i];
		}
		
		echo($ans);
	}
}
?>
