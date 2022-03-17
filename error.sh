#!/bin/bash

echo "1: alphabet"
ARG="1 3 one 9 5"; ./push_swap $ARG 
echo "2: mark"
ARG="1 3 5 7 9 *"; ./push_swap $ARG 
ARG="1 3 5 7 9 -"; ./push_swap $ARG 

echo "3: equal to INT_MAX"
ARG="2147483647"; ./push_swap $ARG | wc -l
ARG="1 2147483647"; ./push_swap $ARG | wc -l
ARG="1 3 2147483647"; ./push_swap $ARG | wc -l
ARG="1 3 9 5 2147483647"; ./push_swap $ARG | wc -l
ARG="1 3 9 5 2147483647 20 128 -28 3888 1029 1002 3880"; ./push_swap $ARG | wc -l
echo "4: over INT_MAX"
ARG="1 3 9 5 80 38 277 2147483648"; ./push_swap $ARG 
echo "5: equal to INT_MIN"
ARG="-2147483648"; ./push_swap $ARG | wc -l
ARG="1 -2147483648"; ./push_swap $ARG | wc -l
ARG="1 3 -2147483648"; ./push_swap $ARG | wc -l
ARG="1 3 9 5 -2147483648"; ./push_swap $ARG | wc -l
ARG="1 3 9 5 2100 388 477 -8 -12 -2147483648"; ./push_swap $ARG | wc -l
echo "6: over INT_MIN"
ARG="1 3 -20 209 9 5 -2147483649"; ./push_swap $ARG 
echo "7: duplicates"
ARG="1 3 9 5 0 1"; ./push_swap $ARG 
ARG="1 3 9 5 0 480 288 17 3990 30399 84 3"; ./push_swap $ARG 
echo "8: \"\""
ARG="1 3 9 5 0 \"\" 8"; ./push_swap $ARG 
