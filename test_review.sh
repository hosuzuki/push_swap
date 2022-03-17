#!/bin/bash

./push_swap 42
./push_swap 0 1 2 3
./push_swap 0 1 2 3 4 5 6 7 89
echo "test: 2 OR 3"
ARG="2 1 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 0"; ./push_swap $ARG | wc -l
echo "test: <12"
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 5 2 3 4"; ./push_swap $ARG | wc -l
ARG="3 2 5 1 4"; ./push_swap $ARG | wc -l
ARG="3 5 2 4 1"; ./push_swap $ARG | wc -l
ARG="1 2 3 5 4"; ./push_swap $ARG | wc -l

