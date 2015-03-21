#! /bin/bash

red='\033[0;31m'    #failed test case
yellow='\033[1;33m' #info
green='\033[0;32m'  #passed test case
NC='\033[0m'        #normal

# run test cases after compiling

lex c--.l
yacc -d -v c--.y

gcc -w lex.yy.c y.tab.c -o c--

for testCase in test/*.c--; do

    echo -e "${yellow}running $testCase"
    echo -e "$(head -1 $testCase) ${NC}" 
    
    ./c-- < $testCase   
    

done
