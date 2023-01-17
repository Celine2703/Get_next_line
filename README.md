# Get_next_line 42

This project is a function able to read files line by line by using static variables.

• Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
• Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
• Make sure that your function works as expected both when reading a file and when
reading from the standard input.
• Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.

Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n (n has to be an integer)
It will define the buffer size for read()

NB : It can replace the scanf function that can be hard to secure (the inputs for example are hard to secure).

This project doesn't contain a Makefile so you have to compile all the files to use the "get_next_line" function :
gcc get_next_line.c get_next_line_utils.c get_next_line.h

BONUS PART

• Develop get_next_line() using only one static variable.
• Your get_next_line() can manage multiple file descriptors at the same time.
For example, if you can read from the file descriptors 3, 4 and 5, you should be
able to read from a different fd per call without losing the reading thread of each
file descriptor or returning a line from another fd.
It means that you should be able to call get_next_line() to read from fd 3, then
fd 4, then 5, then once again 3, once again 4, and so forth.

This project doesn't contain a Makefile so you have to compile all the files to use the "get_next_line" bonus function :
gcc get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.h
