#include "headers/allInclude.h"  

int main(int ac, char **av) {
	// insert_into_sets();
	int val;
    FILE    *fd;
    if (ac >= 2)
    {
        if (!(fd = fopen(av[1], "r")))
        {
            perror(" Error: ");
            return (-1);
        }
        yyset_in(fd);
        
        // Make the first symbol table with global scope
		gSymTable = new symbolTable();
		if(!gSymTable) {
			printf("ERROR: Cannot allocate global symbol table\n");
			return 1;
		}
		gSymTable->scope = gScope++;
		gSymTable->parent = nullptr;
		
        yyparse();
		root = makeNode(strdup("ROOT"), strdup("root"), 0 ,root,  (node*) NULL,  (node*) NULL, (node*) NULL);
		char * fileName = strdup("graph.dot");
		if(ac == 3) fileName = av[2];

		generateDot(root,fileName);

		// printSymbolTable(gSymTable);
		printSymbolTableJSON(gSymTable,0);

        fclose(fd);
    }
    else
        printf("Usage: a.out input_filename [optional]ouput.dot \n");

	return 0; 
}