#!/bin/bash

clang++ -Wall -I./ -c operators/operatorcreator.cpp -o operators/operatorcreator.o 
clang++ -Wall -I./ -c operators/add.cpp -o operators/add.o 
clang++ -Wall -I./ -c operators/minus.cpp -o operators/minus.o 
clang++ -Wall -I./ -c operators/multiply.cpp -o operators/multiply.o 
clang++ -Wall -I./ -c operators/divide.cpp -o operators/divide.o 

clang++ -Wall -I./ -c validator.cpp -o validator.o 
clang++ -Wall -I./ -c translator.cpp -o translator.o 
clang++ -Wall -I./ -c calculator.cpp -o calculator.o 

clang++ -Wall -I./ -c main.cpp
clang++ main.o operators/operatorcreator.o operators/add.o operators/minus.o operators/multiply.o operators/divide.o validator.o translator.o calculator.o -o calculator
./calculator
