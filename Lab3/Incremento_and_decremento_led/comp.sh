#!/bin/bash

make clean
make
sudo lm4flash gcc/Incremento_and_decremento_led.bin
