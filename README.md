# get_next_line

## About

> *The aim of this project is to make you code a function that returns a line, read from a file descriptor.*
>
> This project will not only allow you to add a very convenient function to your collection, but it will also allow you to learn a highly interesting new concept in C programming: static variables.

| **Function name**    | get_next_line                                                |
| -------------------- | ------------------------------------------------------------ |
| **Prototype**        | char *get_next_line(int fd);                                 |
| **Turn in files**    | get_next_line.c, get_next_line_utils.c, get_next_line.h      |
| **Parameters**       | File descriptor to read from                                 |
| **Return value**     | Read line:  correct behavior NULL: nothing else to read or an error occurred |
| **External functs.** | read, malloc, free                                           |
| **Description**      | Write a function which returns a line read from a file descriptor |



## Usage

To test the function, compile with main.c.

```c
gcc main.c get_next_line.c
./a.out some_lines.txt
```

## Test Tools Links

- [**gnlTester (2019+)** by Tripouille](https://github.com/Tripouille/gnlTester)
- [**gnl-war-machine-v2021** by PavelICS](https://github.com/PavelICS/gnl-war-machine-v2019)