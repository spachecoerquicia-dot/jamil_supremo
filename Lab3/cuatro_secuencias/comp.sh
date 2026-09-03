#!/bin/bash

make clean
make
sudo lm4flash gcc/cuatro_secuencias.bin
