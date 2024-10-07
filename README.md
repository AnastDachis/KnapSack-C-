# Knapsack Problem

This program solves the knapsack problem using dynamic programming.

## The program is divided into two parts:
- The KnapsackWorks.cpp code is my own implementation of the algorithm, which takes as input a file and .txt
- The generator.c code was given to me by the professor and is not part of my implementation. It is only used to generate the input files with data
about the sack problem.

### Instructions for use
Prerequisites
To run the program, you need to have a C++ compiler installed on your system.

### How to use
Compile the program: You can compile the program with the following command:

g++ -o knapsack KnapsackWorks.cpp

#### Run the program: After compiling, run the program with the following command:

./knapsack
You will then be prompted to enter the name of the input file.

Input file: The program accepts a .txt file as input. The file format should be as follows:
The first line contains the number of objects.
The following lines contain information for each object in groups of 3 lines:
- Item number 
- Item value
- Item weight

#### The last line contains the capacity of the bag.
Example file contents:

* 10
* 1 42 31
* 2 42 42
* 3 18 6
* 4 18 25
* 5 27 14
* 6 7 13
* 7 17 25
* 8 19 41
* 9 44 19
* 10 34 12
* 50

#### Produce output: The program will read the data from the file and return the best possible value that the bag can carry, along with the execution time.

#### Notes
The function max(int ​​a, int b) is used to calculate the maximum value between two options: to include or not to include an object in the bag.
The program exploits the dynamic programming technique to store subproblem results and avoid the recomputation process.
The generator.c code is auxiliary and is used to generate input files, and is not directly related to the implementation of the algorithm.

##### Example execution
$ ./knapsack
Give the file name: problem_10_50_1_1_5.txt

* 1 - 42 - 31
* 2 - 42 - 42
* 3 - 18 - 6
* 4 - 18 - 25
* 5 - 27 - 14
* 6 - 7 - 13
* 7 - 17 - 25
* 8 - 19 - 41
* 9 - 44 - 19
* 10 - 34 - 12


Maximum value: 123
Program execution time: 0.000100 sec

#### Execution time
The program uses the <chrono> library to measure execution time.
