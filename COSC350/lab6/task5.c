/* Write a C program such that receive an input file name as an argument and open the file as inputs. And then create a child process. Input file must open only one time and the file descriptor is shared by parent and child process. Both the parent and the child read a byte at a time from the inpuit file and write output to independent files (parent.txt for parent output, child.txt for child output). The parent process collect numeric characters and child collect non-numeric characters. Without any form of synchronization, parent and child process with create wrong output files.

Modify the previous program and try to synchronize and get correct outputs for each process.

Note)
  - Do not open the input file twice for synchronization.
  - Define your own function to check numeric character.
  - Do not use vfork(), sleep(), wait() or waitpid() for synchronization
  - Check all possible errors for system calls.
  */
