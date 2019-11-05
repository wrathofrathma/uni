/* Multiple pipes across a fork/exec
 * In this task, you will write a program that has two-way communication between parent and child.
 * Use Task 2 as a starting point, and add a second pipe to it.
 *
 * A. Copy pipe3.c to twoPipesParent.c
 * B. Copy pipe4.c to twoPipesChild.c
 * C. Modify twoPipesParent.c as follows
 *   a. Add a second pipe that will be used for a message from child to parent.
 *   b. Close the appropriate file descriptors on both pipes
 *   c. Pass both pipes' file descriptors to child in the exec.
 *   d. Send the message "Hi there, Kiddo" to child over one pipe(as in task 2). Print the pid and byte count as in Task 2.
 *   e. Then, read a message from child over the second pipe. Print the pid, byte count, and message text as in Task 2.
 * D. Modify twoPipesChild.c as follows:
 *   a. Grab the file descriptors of both pipes from the argument list.
 *   b. Close the appropriate file descriptors.
 *   c. Read a message from parent over the first pipe (as in Task 2). Print the pid, byte count, and message text as in Task 2.
 *   d. Then, send the message "Hi, Mom" to parent over the second pipe. Print the pid and byte count as in Task 2.
 * E. Print your twoPipesParent.c and twoPipesChild.c to hand in.
 * F. Run the program multiple times.
 */
