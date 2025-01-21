# Project Overview

This is an implementation of an interpreter for a small subset of a Fortran-like programming language that I wrote last semester as a school project and am saving here. It includes a lexer written in Flex, a parser written in Bison which generates an AST, and an interpreter and symbol table written in pure C. It includes if statements, print statements, loops, and variable declaration and assignment.
# Build instructions

To create the executable, simply use the Makefile on a machine that has make, gcc, bison, and flex installed.

I tested this on the following versions of these software tools, across several environments I had my hands on including a Raspberry Pi 3 Model B+ running Debian GNU/Linux 12 (bookworm), a headless machine running Ubuntu Server 22.04.5 , WSL Ubuntu 22.04, an Arch 6.12.1-arch1-1 VM, and a Cygwin environment.
- bison (GNU Bison) 3.8, bison (GNU Bison) 3.8.2
- gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0, gcc (Debian 12.2.0-14) 12.2.0, gcc (GCC) 14.2.1 20240910
- flex 2.6.4
- GNU Make 4.3, GNU Make 4.4.1

```bash
make clean #Removes the executable as well as all build artifacts
make #Builds the executable as ./bin/toylang
```

The generated executable created as `./bin/forlang` reads the program directly through stdin, so in order to run a program stored as a file it is necessary to use input redirection (e.g. `./bin/toylang < ./tests/test_cases/program.txt`)

The Makefile can also be used to execute the test cases I've created.
```bash
make run-tests #Prints the output of the test case
make run-tests-compare-files #Compares the test case output with expected output
```
