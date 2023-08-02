README
======

A. This package includes the following files. In your own readme file, modify the information as needed.

|-- Description PDF of the assignment
|-- README.txt [This file]


B. Use your designed makefile 
To compile the code and build the executable using the command 

systemprompt>  make

To remove the  executable files use

systemprompt>  make clean

To run the program use (assuming seed is 3) 

systemprompt> ./Starter 3

which will run the program and generate the outputs.


C. Answer the following questions (1 point each, select/type the right answer).

  1. What is the main difference between Malloc() and Calloc()?
    Malloc requires one argument wheras Calloc requires 2. 
  2. What is the main advantage of using dynamic memory allocation? 
    You will not use as much memory if you allocate dynamically.
  3. What happens if you attempt to free the memory already freed?
    This will cause an error and the program will stop. 
  4. What is the purpose of the headerfile Executor.h, and why is Starter.h not necessary? 
    Executor h is used as a map from executor to starter. 
  5. Describe the * and & operators in the context of pointers and references?
    * is pointer which means it points to the adress of a value whereas & adress of a value
  
