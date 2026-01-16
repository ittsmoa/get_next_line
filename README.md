# get_next_line

## Project Description
**get_next_line** is a project developed as part of the **42 curriculum**.  
The objective of this project is to implement a function that reads a file descriptor line by line, returning one line at each call, including the newline character if it exists.

This project focuses on file handling, buffer management, static variables, and memory allocation in C.

---

## Project Objectives
- Understand how file descriptors work in C  
- Learn how to read from files incrementally  
- Manage memory efficiently without leaks  
- Use static variables to preserve data between function calls  
- Handle edge cases such as end-of-file and varying buffer sizes  

---

## Function Prototype
```c
char *get_next_line(int fd);

--

## Algorithm Overview

The function reads data from a file descriptor using a fixed-size buffer defined by BUFFER_SIZE.
A static variable is used to store leftover data between calls, allowing the function to return exactly one line per function call.

General Workflow

Read data from the file descriptor into a temporary buffer

Append the buffer content to a static storage variable

Check if the static storage contains a newline character (\n)

If a newline is found, extract and return the line up to and including the newline

Save the remaining data in the static variable for the next call

If end-of-file is reached, return the remaining data as the last line

If no data is left, return NULL

This approach ensures that the function works correctly even when a line spans multiple reads.

---

**Error Handling**

Returns NULL if the file descriptor is invalid

Returns NULL on read errors

Correctly handles empty files and end-of-file conditions

**Allowed Functions**

read

malloc

free

**Coding Rules**

Written in C

Follows the 42 Norm

No global variables

No memory leaks

Testing

The project was tested with:

Different BUFFER_SIZE values

Files with and without newline characters

Empty files and large files

Multiple consecutive calls

References

Linux manual pages (man read)

42 School official subject documentation