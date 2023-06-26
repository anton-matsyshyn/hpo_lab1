#!/bin/bash

#PBS -l walltime=00:02:00
#PBS -l nodes=1:ppn=1
#PBS -N matsyshyn_integral
#PBS -t 1-340

cd $PBS_O_WORKDIR

params=`sed -n "${PBS_ARRAYID}p" solv_10.inp`
./my_integral $params > ~/hpo_lab1/solv_${PBS_ARRAYID}_10.out