/* Pipes across a fork/exec
 * A. Copy pipe3.c from BLP, page 535
 * B. Copy pipe4.c from BLP, pages 536.
 * C. Compile and run the program just to see what it does.
 * D. Modify pipe3.c as follows:
 *  a. Have the parent wait for the child.
 *  b. Close the file descriptor of the write end of the pipe on the parent's side
 *  c. Pass the write end of hte pipe to the child as a command-line argument.
 *  d. Close the file descriptor of the read end of the pipe on the child's side.
 */
