symbolTableNode* primary_expression_identifier(char* lexeme, int &errCode, string& errStr);

node* struct_declaration(node* specifier_qualifier_list, node* struct_declarator_list);

node* declaration_list(node* declaration_list, node* declaration);

node* parameter_declaration(node* declaration_specifiers, node* declarator);

node* struct_or_union_specifier(node* struct_or_union);