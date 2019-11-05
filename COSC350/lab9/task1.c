/* A simple pipe
 * This task is intended to help your understanding of how pipes work.
 *
 * A. Copy pipe1.c from BLP, page 532-533.
 * B. Compile and run it.
 * C. Reverse the order of the write and read and run the program again. 
 * D. Briefly describe what happened with the reversed order and why the program behaved that way.
 * E. Restore the read and write to their original order before proceeding.
 * F. Modify pipe1.c in the following ways:
 *  a. It's a good idea to define wo global integer constants
 *    1. READ_END=0
 *    2. WRITE_END=1
 *    just to help keep straight which is which in the code. For example, when you refer to the write end of hte pipe p, you would then use p[WRITE_END]. Makes
 *    the code much more readable.
 *  b. Dynamically allocate buffer so it's exactly hte right size for some_data.
 *  c. Copy the string from some_data into buffer
 *  d. Modify the read so its third argument is the exact size of the buffer (rather than the large BUFSIZ)
 */

