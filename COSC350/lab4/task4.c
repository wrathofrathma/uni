/* Write your own mv named MyMv
 * By using bash command mv, you can move a file from current directory to another directory. Write your own mv called MyMv by using system calls link() and unlink(). Your program receives two arguments: File name and path to a directory where the file need to move, or file name and path to directory with a file name.
 * If the second argument is a directory, move a file to the directory. If the second argument is not a directory, move file to directory as a file name.
EX)
Move a file foo to under directory ~/separk/cosc350
 * ./MyMv foo ~/separk/cosc350
Move a file foo to under directory ~/separk/cosc350 named abc if there is no directory named abc.
 * ./MyMv foo ~/separk/cosc350/abc
Move a file foo to under directory ~/separk/cosc350 named foo if there is no directory named foo.
 * ./MyMv foo ~/separk/cosc350/foo
 */

