**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
***** Main state codes

- R: runnable, waiting for CPU to process or currently being processed
- S: interruptible sleep, waiting for event before resuming
- D: uninterruptible sleep, cannot be terminated/woken up
- Z: zombie, terminated but waiting for status to be read
- T: stopped, but not terminated
- X: dead (shouldn't be seen)

**2. What is a zombie process?**
- A zombie process is one that has been fully executed/exited, but its parent process has not yet read its exit status. Once the child's exit status has been read from the wait() call, the zombie can rest peacefully.


**3. How does a zombie process get created? How does one get destroyed?**
- A zombie process is created when a child process has completed execution, but its exit status has not yet been "reaped" from the process table (ps a). It is destroyed once its parent process reads the zombie process' exit status from the wait() call. The kill command cannot terminate a zombie process.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
- The main benefit from working in a compiled language is the faster execution speed because they are compiled into machine code. Because of this, the developer can control memory and CPU usage.