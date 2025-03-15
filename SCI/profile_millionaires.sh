#!/bin/bash

cd build_profile
mkdir profile_data

./bin/relu-OT r=1 a=2 b=3
gprof ./bin/relu-OT gmon.out > profile_data/small_small_prof.txt

./bin/relu-OT r=1 a=5 b=18000000000000000000 # almost the max for uint64_t
gprof ./bin/relu-OT gmon.out > profile_data/small_big_prof.txt

./bin/relu-OT r=1 a=16000000000000000000 b=54
gprof ./bin/relu-OT gmon.out > profile_data/big_small_prof.txt

./bin/relu-OT r=1 a=16043230000130000780 b=1200610003700000055
gprof ./bin/relu-OT gmon.out > profile_data/big_big_prof.txt

./bin/relu-OT r=1 a=4193213593 b=6002221524
gprof ./bin/relu-OT gmon.out > profile_data/med_med_prof.txt

