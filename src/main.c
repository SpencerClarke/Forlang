#include "parser.tab.h"
#include "interpreter.h"
#include "ast.h"
#include <stdio.h>

int main(void)
{
	struct Program_Body_Node *root;

	if(yyparse((void **)&root))
	{
		fprintf(stderr, "main: parser failure\n");
		exit(3);
	}
	
	exec_program(root);
	program_body_node_destroy(root);
	
	return 0;
}
