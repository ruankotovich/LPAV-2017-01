#!/bin/sh
gcc -std=gnu11 "$1" -O2 -o cheeki -pthread

for threads in 4 16 32 64 128 256 512 1024 2048 4096
do
  printf "%s;" "$threads"
  for length in 32868 65536 131072 262144 524288 1048576 2097152
  do
    ./cheeki "$length" "$threads" "$2"
  done
  echo;
done
