**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

I - Idle - process sleeping for a while
R - Running - process is excuting
S - Sleeping - process waiting for a resource to become available to start running again, like user input
T - Stopped - a process that has been stopped
U - Uniterruptible wait
Z - Zombie - a dead process

**2. What is a zombie process?**

A process that is no longer running but hasn't be closed.

**3. How does a zombie process get created? How does one get destroyed?**

When a child process is finished executing but it's parent hasn't accepted it's exit code.  It is usually destroyed by a parent process using the wait command to read it's exit status.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

The main benefit is speed because you are writing code closer to the metal, the overhead of an interpreter is removed.