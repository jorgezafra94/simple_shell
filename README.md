<p align="center"> <img width="335" height="105" src="https://www.holbertonschool.com/holberton-logo.png"></p>

## Simple_Shell

This project is a collaboration between Diego López and Jorge Zafra, actual students of Software Engineering at Holberton School. It consists of developing and making our own UNIX command interpreter (Shell).

The "Simple_shell" is a program that can be compiled and launched from the command line, where its main function is to execute commands read from the standard input. It contains some of the basic features and functions found in the various shell programs like Kernel commands and builtin commands.

## Quick Start

1. Git clone this respository to your local directory.

       $ git clone https://github.com/diegolopezq95/simple_shell.git
  
2. Compile the program.

       $ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
       
3. Now execute the shell.
      
       $ ./hsh
       
## Builtin Commands

This shell supports the next builtin commands:

    cd - change directory

    env - list the current environment variables

    exit - exit the shell
  
## Manual

To see the manual run:

    $ man ./man_1_simple_shell  

## Files

Brief description of every file in this repository.
	
| File | Description |
| ------------- | ------------- |
| _atoi.c | function that gets sign and numbers of string |
| _calloc.c | function that allocates memory for an array |
| _change.c | functions that change the OLDPWD and PWD environment variables |
| _display_help.c | functions that reads all builtins text files and prints it to POSIX stdout |
| _envir.c | functions to print the environment variables and create a copy of env |
| _errors.c | functions with the error message for each builtin |
| _forky.c | program that creates process and execute |
| _gethome.c | funtion to get the environment variable HOME |
| _getline.c | functions to read what the user writes |
| _iscd.c | functions to change the current directory of the process. |
| _isexit.c | functions that finds if line input is exit therefore process termination |
| _ishelp.c | functions to print the help of each builtin |
| _noargv.c | function to give shell form without filename as input |
| _realloc.c | function to change the size and copy the content |
| _realloc2.c | function to change the size and copy the content special case |
| _signal.c | function to handle SIGINT signal |
| _str_concat.c | function to create an array using malloc |
| _strlen.c | function that returns the length of a string |
| _strtoky.c | functions to cut a string into tokens depending of the delimit|
| _writerr.c | functions to print the error for each builtin |
| _yesargv.c | function to give shell form with filename as input |
| checkbin.c | functions to check if commands exist in the path |
| free_grid.c | function to free a matrix |
| man_1_simple_shell | manual of simple_shell |
| parsing.c | functions that create an array of pointers depending of the delimit characters |
| shell.h | header file with all thr function prototypes |
| startshell.c | main function that stars the shell (shell skeleton) |

## Examples


## Authors

Diego Lopez and Jorge Zafra.
## End
