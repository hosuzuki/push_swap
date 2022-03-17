#!/bin/bash

echo "1: alphabet"
ARG="1 3 one 9 5"; ./checker $ARG 
echo "2: mark"
ARG="1 3 5 7 9 *"; ./checker $ARG 
ARG="1 3 5 7 9 -"; ./checker $ARG 
echo "3: over INT_MAX"
ARG="1 3 9 5 80 38 277 2147483648"; ./checker $ARG 
echo "4: over INT_MIN"
ARG="1 3 -20 209 9 5 -2147483649"; ./checker $ARG 
echo "5: duplicates"
ARG="1 3 9 5 0 1"; ./checker $ARG 
ARG="1 3 9 5 0 480 288 17 3990 30399 84 3"; ./checker $ARG 
echo "6: \"\""
ARG="1 3 9 5 0 \"\" 8"; ./checker $ARG 
