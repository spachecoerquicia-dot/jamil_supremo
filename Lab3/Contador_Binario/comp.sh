#!/bin/bash

make clean
make
sudo lm4flash gcc/Contador_Binario.bin
