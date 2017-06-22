#!/bin/sh
gcc -std=gnu11 "$1" -O2 -o cheeki -pthread

for length in 32868 65536 131072 262144 524288 1048576 2097152
do
  ./cheeki "$length" "$2"
done
