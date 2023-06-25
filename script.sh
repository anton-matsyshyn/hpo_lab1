#!/bin/bash

limits = $(cat src.txt)

integral = $(./my_integral $limits)
echo $integral > result.txt