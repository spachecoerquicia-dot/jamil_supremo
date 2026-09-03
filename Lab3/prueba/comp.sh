#!/bin/bash

make clean
make
sudo lm4flash gcc/prueba.bin
