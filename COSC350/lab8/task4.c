/* Interprocess communication using popen() and pclose()
 * popen() create a child and pipe. A parent process asks two arguments from commandline: a shell command and a file name. And thensend to child by using popen. Child process will implement the command with file as an input then sent to parent. Parent simply display output from the child on standard output.
 * ex) 
 * ./task4 cat Task4.c
 * ./task4 sort Task4.c
 * ./Task4 cat Task4.c | grep main
 */
