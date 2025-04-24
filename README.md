# COP4533 Kruskal's MST Project
Created by Lydia Chung and Lauren Nunag.

This project implements Kruskal’s Algorithm to compute the Minimum Spanning Tree (MST).The program reads input from a file, then processes the graph edges using a greedy approach with a Disjoint Set Union (DSU) structure, and then outputs the total weight of the MST along with the selected edges. 

## How to Run
```
$ make
$ ./kruskals.o
or
$ ./kruskals.o testcases/inputN.txt
```
The output is printed on `stdout` and in `testcases/output.txt`. If no input file path is provided, the algorithm defaults to running an example test case stored at `testcases/input.txt`. There are inputs of various sizes provided in the `testcases` folder; replace `N` with a value between 1 and 7 to use any of the inputs I generated with the `test_case_gen.py` script.

## Input Format and Testcase Generation 
Input is read from `input.txt` in the format below, where `V` and `E` are the number of vertices and edges in the graph. In the next `E` lines, each line describes edge `i` with three values: `u_i`, `v_i`, and `w_i`, which are the source, destination, and weight of edge `i` respectively.
```
V E  
u_1 v_1 w_1  
u_2 v_2 w_2  
…  
u_V v_V w_V
```
Testcases can be generated with the `test_case_gen.py` script. The values of `V` and `E` can be changed or randomized as seen fit, and the edge weights are randomized to an integer between 1 and 10000. The input file name can also be changed as desired in the file.

## Directory Structure
```
├── kruskals.cpp            // main implementation code
├── Makefile                // makefile to compile code
├── README.md               // this file
├── report.pdf              // report document
├── test_case_gen.py        // test case generation script
└── testcases               // all testcases we generated and used
    ├── input.txt
    ├── ...
    └── output.txt          // output file for results
```
