# 3150-lab7

instructions for use:

- in order to run, first make sure any necessary c/c++ extensions are installed
- in the terminal, run the line: 
g++ -std=c++17 -I./include lab7.cpp lab7test.cpp bigint.cpp -o lab7test -DONLY_INCLUDE_BIGINT_ONCE
- this line will compile the tests and put the results in a file called 'lab7test'
- in order to read the file, next run the following line in the terminal: 
./lab7test


notes on files included:

- doctest.h - for testing
- lab7.h - definitions for all functions needed
- lab7.cpp - implementation of functions listed in header file
- lab7test.cpp - testing and test cases for everything in lab7.cpp and also to test timings
- bigint.h - imported for bigint; includes definitions
- bigint.cpp - imported for bigint; includes declarations