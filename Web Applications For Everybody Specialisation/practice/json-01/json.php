<?php
  sleep(2);
  header('Content-Type: application/json; charset=utf-8');
  $stuff = array('first' => 'first thing', 'second' => 'second thing');
  json_encode($stuff);
  echo ("This is the output of json_encode: \n");
  echo(json_encode($stuff));
  //echo just to print it out, but you don't have to echo it.
//This php code creates an array that maps first to first thing and
//second to second thing
