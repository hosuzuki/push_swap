#!/bin/bash

echo "test1"
ARG="1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 1 89 -20"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 1 30 38 90"; ./push_swap $ARG | ./checker_Mac $ARG


echo "ERROR test"
#ARG="1 4 98 03 4"; ./push_swap $ARG | ./checker_Mac $ARG
#ARG="5 3 2 9 7 10 100 20 -30"; ./push_swap $ARG | ./checker_Mac $ARG

