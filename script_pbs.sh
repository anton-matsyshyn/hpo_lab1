#!/bin/bash

#PBS -l walltime=00:02:00
#PBS -l nodes=1:ppn=1
#PBS -N matsyshyn_integral

limits=$(cat src.txt)

integral=$(./my_integral $limits)
echo $integral > result.txt