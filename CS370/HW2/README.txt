1. What is the return value for the fork() in a child process?
    The return value for fork in a child process is 0.

2. Give a reason for the fork() to fail?
    Fork will fail with too many child processes.

3. How many of the least significant bits of the status does WEXITSTATUS return?
    8 bits.

4. Which header file must be included to use the WEXITSTATUS.
    #include <sys/wait.h>
    
5. In this program, are we doing a sequential processing or a concurrent processing with respect to
the child processes? Sequential processing is when only one of the child processes is running at
one time, and concurrent processing is when more than one child process can be running at the
same time. 
    This program runs each child process sequentially.

6. Is it possible to have any anomalies in the output from child process and the output from parent
process. Provide a reason for that possible situation. (2 points)
    If you forget to empty a buffer or close a file this is possible.

OUTPUT: (I used the input.txt I created to test for this output)
[Generator] [3114712]: Waiting for the child process 3114712
[Lucas] [3114713]: The sum of the first 3 numbers of the Lucas series is 6
[Lucas] [3114713]: The nth number in the lucas series is 3
[Generator] [3114712]: The child process 3114713 returned 6
[HexagonalSeries] [3114714]: The sum of first 6 hexagonal numbers is:161
[HexagonalSeries] [3114714]: The nth number in the Hexagonal series is 6
[Generator] [3114712]: The child process 3114714 returned 6
[HarmonicSeries] [3114715]: The sum of the first 6 numbers of the harmonic series is 2.450000
[Generator] [3114712]: The child process 3114715 returned 2
[Generator] [3114712]: The lucas child process returned 6
[Generator] [3114712]: The Hexagonal child process returned 6
[Generator] [3114712]: The sum of the first n Harmonic numbers is 2
[Lucas] [3114716]: The sum of the first 10 numbers of the Lucas series is 198
[Lucas] [3114716]: The nth number in the lucas series is 10
[Generator] [3114712]: The child process 3114716 returned 10
[HexagonalSeries] [3114717]: The sum of first 10 hexagonal numbers is:715
[HexagonalSeries] [3114717]: The nth number in the Hexagonal series is 10
[Generator] [3114712]: The child process 3114717 returned 10
[HarmonicSeries] [3114718]: The sum of the first 10 numbers of the harmonic series is 2.928968
[Generator] [3114712]: The child process 3114718 returned 2
[Generator] [3114712]: The lucas child process returned 10
[Generator] [3114712]: The Hexagonal child process returned 10
[Generator] [3114712]: The sum of the first n Harmonic numbers is 2
