#!/bin/bash

clang++ -Wall -I./ -c operators/operatorcreator.cpp -o operators/operatorcreator.o 
clang++ -Wall -I./ -c operators/add.cpp -o operators/add.o 
clang++ -Wall -I./ -c operators/minus.cpp -o operators/minus.o 

clang++ -Wall -I./ -c validator.cpp -o validator.o 
clang++ -Wall -I./ -c translator.cpp -o translator.o 

clang++ -Wall -I./ -c main.cpp
clang++ main.o operators/operatorcreator.o operators/add.o operators/minus.o validator.o translator.o -o calculator
./calculator
