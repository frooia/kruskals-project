# COP4533 Kruskals Project
Lydia Chung and Lauren Nunag

# Input 
Input is read from “input.txt” in the format below, where V and E are the number of vertices and edges in the graph. In the next E lines, each line describes edge i with three values: u_i, v_i, and w_i, which are the source, destination, and weight of edge i respectively.

V E
u_1 v_1 w_1  
u_2 v_2 w_2  
…  
u_V v_V w_V


# How to Run
```
make
./kruskals.o
```
The output is printed on stdout and in testcases/output.txt.

# Directory Structure
```
├── kruskals.cpp            // main implementation code
├── Makefile                // makefile to compile code
├── README.md               // this file
└── testcases               // all testcases we generated and used
    ├── input.txt
    └── output.txt
```
