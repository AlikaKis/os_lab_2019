#!/bin/bash
#echo There were $# parameters passed

exec 0</home/root/share/os_lab_2019/lab1/src/numbers.txt
count=0
sum=0
average=1
while read param
#for param in "$@"
do
#echo "\$@ Parameter #$count = $param"
count=$(($count+1))
sum=$(($sum+$param))
done
average=$(($sum/$count))
echo "Average= $average"
#echo "\$@ Count = #$count"
echo "Count= $count"