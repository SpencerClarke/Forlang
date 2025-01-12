#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "symbol_table.h"
#include "ast.h"

void exec_program(struct Program_Body_Node *root); /* Executes the entire program */

#endif
