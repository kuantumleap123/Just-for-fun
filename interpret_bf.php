<?php
//This program interprets the language "Brainf*ck"

$input = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";

$ptr = 0;
$max_ptr = 0;
$min_ptr = 0;
$memory = array();
$memory[$ptr] = 0;

function next_cell()
{
	global $ptr, $max_ptr, $memory;
	$ptr++;
	if($ptr > $max_ptr)
	{
		$memory[$ptr] = 0;
		$max_ptr = $ptr;
	}
	
}

function prev_cell()
{
	global $ptr, $min_ptr, $memory;
	$ptr--;
	if($ptr < $min_ptr)
	{
		$memory[$ptr] = 0;
		$min_ptr = $ptr;
	}
}

function inc_cell()
{
	global $ptr, $memory;
	$memory[$ptr]++;
}

function dec_cell()
{
	global $ptr, $memory;
	$memory[$ptr]--;
}

function out()
{
	echo(chr($memory[$ptr]));
}

for($i=0;$i<strlen($input);$i++)
{
	if($input[$i] == '>')
	{
		next_cell();
	}
	
	else if($input[$i] == '<')
	{
		prev_cell();
	}
	
	else if($input[$i] == '+')
	{
		inc_cell();
	}
	
	else if($input[$i] == '-')
	{
		dec_cell();
	}
	
	else if($input[$i] == '.')
	{
		out();
	}
	
	else if($input[$i] == '[')
	{
		
	}
}

?>
