#!/bin/bash
string1=$(pwd)
echo "Current path"
echo $string1
TZ='Europe/Moscow'
date "+DATE: %D%nTIME: %T"
echo "Content of PATH"
echo $PATH
