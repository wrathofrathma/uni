/* sigprocmask
 * Write a complete C program that demonstrates how you can block and unblock signals. Your program will have two loops, each of which will simply print the integers from 1 to 5 at 1 second intervals. During the first loop, SIGINT and SIGQUIT are blocked. During the second loop, only SIGINT is blocked. 
 * While the program is running, you can try ^C and/or ^\ to see if they are blocked as expected.
 * The signal SIGINT is usually bound to ^C by the terminal driver. The SIGINT signal terminates the program by default.
 * The signal SIGQUIT is usually bound to ^\ by the terminal driver. The signal SIGQUIT by default causes the program to terminate and creates a core file.
 */
