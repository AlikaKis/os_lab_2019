#!/bin/bash

exec 0>/home/root/share/os_lab_2019/lab1/src/numbers.txt
for i in {1..150}
do
(od -An -td -N1 /dev/urandom)>&0
done
