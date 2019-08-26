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
| _errors.c | functions to print the error for each builtin |
| _forky.c | program that creates process and execute |
| _gethome.c | funtion to get the environment variable HOME |
| _getline.c | functions to read what the user writes |
| _iscd.c | functions to change the current directory of the process. |
| _isexit.c |  |
| _ishelp.c | |
| _noargv.c | |
| _realloc.c | |
| _realloc2.c | |
| _signal.c | |
| _str_concat.c | |
| _strlen.c | |
| _strtoky.c | |
| _writerr.c | |
| _yesargv.c | |
| checkbin.c | |
| free_grid.c | |
| man_1_simple_shell | |
| parsing.c | |
| shell.h | |
| startshell.c | |

## Examples


## Authors

Diego Lopez and Jorge Zafra.
## End
