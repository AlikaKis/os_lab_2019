#!/bin/bash

exec 1>/home/root/share/laba1/numbers.txt

for i in {1..150}
do
(od -An -td -N1 /dev/urandom)>&1
#/home/root/share/laba1/numbers.txt
done
