#!/bin/bash

#PBS -l walltime=00:02:00
#PBS -l nodes=1:ppn=1
#PBS -N matsyshyn_integral
#PBS -t 1-34

cd $PBS_O_WORKDIR

params=`sed -n "${PBS_ARRAYID}p" solv.inp`
./my_integral $params > ~/hpo_lab1/solv_${PBS_ARRAYID}.out