# push_swap
complete school project  
122/125
## Subject
At the beginning you have two stacks: ___a___ - contains a random number of either positive or negative integer numbers without
any duplicates, and ___b___ - empty. The goal is to sort in ascending order numbers into ___stack a___. At the end ___stack b___ should be empty.  
This project consists of two parts:
1. **checker**  
   This programm takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.
2. **push_swap**  
   This one calculates and displays on the standard output the smallest progam using Push_swap instruction language that sorts integer arguments received.

#### Push_swap instruction language or restrictions
Each operation (exсept push) can be applied to ___stack a, stack b, or both stacks concurrently___  
- swap opetations - swap the first two elements at the top  
**sa  sb  ss**
- push operations - take the first element at the top of one stack and put it at the top of another  
**pa  pb**
- rotate operations - shift up all elements of stack by 1 (the first element becomes the last one)  
**ra  rb  rr**
- reverse rotate - shift down all elements of stack by 1 (the last element becomes the first one)  
**rra  rrb  rrr**

## Algorithms
If stack lenght is equal or less then 5 elements then insertion sort is implemented, else - quick sort.
The simplest analogy for my implementation is two jars with colored water. To get a right mix every time half of the water from a jar tranfuses (= dividing into parts in quick sort) to another and the mixes (= sorting this half) 
## Usage
    make
    ARG="8 -5 0 4 6 12 -25 47 10 15 -7"
    ./push_swap $ARG > commands
    ./checker $ARG < commands
## Examples
