#!/bin/bash

./Build/tool < main.cpp > gen.cpp
g++ -o main gen.cpp -Wall -std=c++11
