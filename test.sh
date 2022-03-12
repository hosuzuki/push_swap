#!/bin/bash

echo "test1"
ARG="5 3 2 9 7 10"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="5 3 2 9 7 10 100 20 -30"; ./push_swap $ARG | ./checker_Mac $ARG

