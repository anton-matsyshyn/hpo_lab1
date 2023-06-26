#!/bin/bash

#PBS -l walltime=00:02:00
#PBS -l nodes=1:ppn=1
#PBS -N matsyshyn_grand_total

cd $PBS_O_WORKDIR

cat ./solv_{1..34}.out | awk 'BEGIN{x=0}{x+=$0}END{print x}' > solv_gt.out