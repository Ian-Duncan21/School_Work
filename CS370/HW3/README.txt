1. Which ends of the pipe denote the read and the write ends of a pipe? (1 point)
    fd[0] for reading
    fd[1] for writing

2. Why do we need to close a file descriptor when reading or writing to a pipe? (1 point)
    Because closing it will close the pipe and all threads in the pipe

3. Name the function used to map files or devices in to memory? (1 point)
    mmap()
    
4. What is the name of the function used to open a shared memory object? What does it return? 
    shm_open()
    shm_open() returns a non-negative integer representing the lowest numbered unused file descriptor. 
    Otherwise, it returns -1 and sets errno to indicate an error.
