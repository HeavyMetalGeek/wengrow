#!/bin/bash

mkdir -p bin
g++ -o ${PWD}/bin/ch09_test ch09_e4.cpp
g++ -o ${PWD}/bin/queue_safe_test queue_safe.cpp
g++ -o ${PWD}/bin/queue_unsafe_test queue_unsafe.cpp
