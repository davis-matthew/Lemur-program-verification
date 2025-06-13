#!/usr/bin/env bash

name=$1
bname=$(basename $name)

echo $name
echo $bname

working_dir=data_out
mkdir $working_dir

rm -rf $working_dir/$bname || true

timeout 1500 ./run.sh "$name".yml --learn -v all --per-instance-timeout 30 -w $working_dir
