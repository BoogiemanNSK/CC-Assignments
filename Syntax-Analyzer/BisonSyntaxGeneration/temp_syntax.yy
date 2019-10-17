
primary_expression:
      IDENTIFIER            { $$ = new PrimaryExpressionNode(new IdentifierNode("ab")); }
    | LITERAL               { $$ = new PrimaryExpressionNode(new NumericLiteralNode("1")); }
    | STRING_LITERAL        { $$ = new PrimaryExpressionNode(new StrLiteralNode("String")); }
    | LEFT_PAR expression RIGHT_PAR    { $$ = new PrimaryExpressionNode(NULL); }
;

postfix_expression:
      primary_expression { $$ = new PostfixExpressionNode($1);}
    | postfix_expression LEFT_BRACKET expression RIGHT_BRACKET {$1->children.push_back($3); $$ = $1 ;}
    | postfix_expression LEFT_PAR argument_expression_list RIGHT_PAR
    | postfix_expression LEFT_PAR RIGHT_PAR{$$ = $1;}
    | postfix_expression DOT IDENTIFIER {$1->children.push_back(new IdentifierNode($3)); $$ = $1 ;}
    | postfix_expression PTR_OP IDENTIFIER {$1 -> children.push_pack(new OperatorNode( $2 ));$1->children.push_back(new IdentifierNode($3)); $$=$1;}
    | postfix_expression INC_OP {$1 -> children.push_pack(new OperatorNode($2)); $$=$1;}
    | postfix_expression DEC_OP {$1 -> children.push_pack(new OperatorNode($2)); $$=$1;}
    | LEFT_PAR type_name RIGHT_PAR LEFT_CBRACKET initializer_list RIGHT_CBRACKET { $$ = new PostfixExpressionNode($2,$5);}
    | LEFT_PAR type_name RIGHT_PAR LEFT_CBRACKET initializer_list COMMA RIGHT_CBRACKET {$$= new PostfixExpressionNode($2,$5);}
;

argument_expression_list:
      IDENTIFIER{$$ = new ArgumentExpressionList(new IdentifierNode($1));}
    | IDENTIFIER COMMA argument_expression_list {$3->children.push_back(new IdentifierNode($1)); $$=$3;}
;

unary_expression:
      postfix_expression {$$ = new UnaryExpressionNode(new PostfixExpressionNode($1));}
    | INC_OP unary_expression {$2 -> children.push_pack(new OperatorNode($1)); $$=$2;}
    | DEC_OP unary_expression {$2 -> children.push_pack((new OperatorNode($1)); $$=$2;}
    | unary_operator cast_expression {$1 ->children.push_back(new CastExpressionNode($2)); $$ = $1;}
    | SIZEOF unary_expression {$2 -> children.push_pack(new OperatorNode($1)); $$=$2;}
    | SIZEOF LEFT_PAR type_name RIGHT_PAR {$$ = new UnaryExpressionNode("(new OperatorNode($1)", $3);}
;

unary_operator:
      AMP{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | STAR{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | PLUS{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | MINUS{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | BIN_NOT_OP{$$ = new UnaryOperatorNode(new OperatorNode($1);}
    | LOG_NOT_OP{$$ = new UnaryOperatorNode(new OperatorNode($1);}
;

cast_expression:
      unary_expression { $$ = new CastExpressionNode($1) }
    | LEFT_PAR type_name RIGHT_PAR cast_expression { $$ = new CastExpressionNode($2, $4); }
;

multiplicative_expression:
      cast_expression { $$ = new BinaryExpressionNode($1); }
    | multiplicative_expression STAR cast_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | multiplicative_expression SLASH cast_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | multiplicative_expression MOD_OP cast_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

additive_expression:
      multiplicative_expression { $$ = new BinaryExpressionNode($1); }
    | additive_expression PLUS multiplicative_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | additive_expression MINUS multiplicative_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

shift_expression:
      additive_expression { $$ = new BinaryExpressionNode($1); }
    | shift_expression LEFT_OP additive_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | shift_expression RIGHT_OP additive_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

relational_expression:
      shift_expression { $$ = new BinaryExpressionNode($1) ;}
    | relational_expression L_OP shift_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | relational_expression G_OP shift_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
    | relational_expression LE_OP shift_expression { $$ = $1->children.push_back($3); $$ = $1->children.push_back(new OperatorNode($2)); $1->ops.push_back($2); }
    | relational_expression GE_OP shift_expression { $$ = $1->children.push_back($3); $$ = $1->children.push_back(new OperatorNode($2));$1->ops.push_back($2); }
;

equality_expression:
      relational_expression { $$ = new BinaryExpressionNode($1) ;}
    | equality_expression EQ_OP relational_expression { $$ = $1->children.push_back($3); $$ = $1->children.push_back(new OperatorNode($2)); $1->ops.push_back($2); }
    | equality_expression NE_OP relational_expression { $$ = $1->children.push_back($3); $$ = $1->children.push_back(new OperatorNode($2)); $1->ops.push_back($2); }
;

and_expression:
      equality_expression { $$ = new BinaryExpressionNode($1) ;}
    | and_expression AMP equality_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

exclusive_or_expression:
      and_expression { $$ = new BinaryExpressionNode($1); }
    | exclusive_or_expression BIN_XOR_OP and_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

inclusive_or_expression:
      exclusive_or_expression { $$ = new BinaryExpressionNode($1) ;}
    | inclusive_or_expression BIN_OR_OP exclusive_or_expression { $$ = $1->children.push_back($3); $1->ops.push_back($2); }
;

logical_and_expression:
      inclusive_or_expression { $$ = new BinaryExpressionNode($1); }
    | logical_and_expression AND_OP inclusive_or_expression { $$ = $1->children.push_back($3);$$ = $1->children.push_back(new OperatorNode($2)); $1->ops.push_back($2); }
;

logical_or_expression: 
      logical_and_expression { $$ = new BinaryExpressionNode($1) ;}
    | logical_or_expression OR_OP logical_and_expression { $$ = $1->children.push_back($3); $$ = $1->children.push_back(new OperatorNode($2));$1->ops.push_back($2); }
;

conditional_expression:
      logical_or_expression { $$ = new ConditionalExpressionNode($1); }
    | logical_or_expression TERNARY_OP expression COLON conditional_expression { $$ = new ConditionalExpressionNode($1,$3,$5); }
;

assignment_expression:
      conditional_expression { $$ = new AssignmentExpressionNode($1); }
    | unary_expression assignment_operator assignment_expression { $$ = AssignmentExpressionNode($1,$2,$3); }
;

assignment_operator:
      ASSIGN_OP { $$ = new OperatorNode("=") } 
    | MUL_ASSIGN { $$ = new OperatorNode("*=") }
    | DIV_ASSIGN { $$ = new OperatorNode("/=") }
    | MOD_ASSIGN { $$ = new OperatorNode("%=") }
    | ADD_ASSIGN { $$ = new OperatorNode("+=") }
    | SUB_ASSIGN { $$ = new OperatorNode("-=") }
    | LEFT_ASSIGN { $$ = new OperatorNode("<=") }
    | RIGHT_ASSIGN { $$ = new OperatorNode(">=") }
    | AND_ASSIGN { $$ = new OperatorNode("&=") }
    | XOR_ASSIGN { $$ = new OperatorNode("^=") }
    | OR_ASSIGN { $$ = new OperatorNode("|=") }
;

expression:
      assignment_expression {$$ = new ExpressionNode($1);}
    | expression COMMA assignment_expression {$1->children.push_back($3); $$ = $1 ;}
;


constant_expression:
    conditional_expression {$$ = new ConstantExpressionNode($1);}
;

declaration:
    declaration_specifiers SEMICOLON {$$ = new DeclarationNode($1);}|
	declaration_specifiers init_declarator_list SEMICOLON { $$ = new DeclarationNode($1,$2);}
;

declaration_specifiers: 
    storage_class_specifier {$$ = new DeclarationSpecifierNode($1); }|
	storage_class_specifier declaration_specifiers {$$ = new DeclarationSpecifierNode($1, $2);}|
	type_specifier {$$ = new DeclarationSpecifierNode($1); } |
	type_specifier declaration_specifiers { $$ = new DeclarationSpecifierNode($1,$2); }|
	type_qualifier {$$ = new TypeQualifierNode($1);} |
	type_qualifier declaration_specifiers { $$ = new DeclarationSpecifierNode($1,$2); } |
    function_specifier { $$ = new DeclarationSpecifierNode($1); } |
	function_specifier declaration_specifiers { $$ = new DeclarationSpecifierNode($1,$2); }
;
storage_class_specifier:
	EXTERN  { $$ = new StorageClassSpecifierNode(new KeywordNode($1)); } |
	STATIC { $$ = new StorageClassSpecifierNode(new KeywordNode($1)); }  |
	AUTO { $$ = new StorageClassSpecifierNode(new KeywordNode($1)); } |
	REGISTER { $$ = new StorageClassSpecifierNode(new KeywordNode($1)); } 
;

init_declarator_list:
	init_declarator{$$ = new InitDeclaratorListNode($1);} |   
	init_declarator_list COMMA init_declarator{$1->children.push_back($3); $$ = $1 ;}
;

init_declarator:
	declarator {$$ = new  InitDeclaratorNode($1);}|
	declarator ASSIGN_OP initializer {$$ = new  InitDeclaratorNode($1, $3);}
;

initializer:
	assignment_expression {$$ = new  InitalizerNode($1);} |
	LEFT_CBRACKET initializer_list RIGHT_CBRACKET {$$ = new  InitalizerNode($2);}|
	LEFT_CBRACKET initializer_list COMMA RIGHT_CBRACKET {$$ = new  InitalizerNode($2);}
;

initializer_list:
	initializer  {$$ = new  InitalizerListNode($1);}|
	designation initializer   {$$ = new  InitalizerListNode($1);} |
	initializer_list COMMA initializer {$1->children.push_back($3); $$ = $1 ;} |
	initializer_list COMMA designation initializer{$1->children.push_back($3); $$ = $1 ;}
;

designation:
	designator_list ASSIGN_OP {$$ = new DesignationNode($1);}
;

designator_list:
	designator {$$ = new DesignatorListNode($1);}|
	designator_list designator{$1->children.push_back($2); $$ = $1 ;}
;

designator:
	LEFT_BRACKET constant_expression RIGHT_BRACKET  { $$ = new DesignatorNode($2);}|
	DOT IDENTIFIER{ $$ = new DesignatorNode(new IdentifierNode($2));}
;

declarator: 
    pointer direct_declarator {$$ = new DeclaratorNode($1,$2);}|
	direct_declarator {$$ = new DeclaratorNode($1);}
;

pointer:
	STAR {$$ = new PointerNode();}|
	STAR type_qualifier_list {$$ = new PointerNode($2);}|
	STAR pointer {$$ = new PointerNode($2);}|
	STAR type_qualifier_list pointer {$3->children.push_back($2); $$ = $3 ;}
;

direct_declarator: 
    IDENTIFIER {$$ = new DirectDeclaratorNode(new IdentifierNode($1));}|
	LEFT_PAR declarator RIGHT_PAR{$$ = new DirectDeclaratorNode($2);} |
	direct_declarator LEFT_BRACKET type_qualifier_list assignment_expression RIGHT_BRACKET{$1->children.push_back($3);$1->children.push_back($4); $$ = $1 ;} |
	direct_declarator LEFT_BRACKET type_qualifier_list RIGHT_BRACKET {$1->children.push_back($3); $$ = $1 ;}|
	direct_declarator LEFT_BRACKET assignment_expression RIGHT_BRACKET {$1->children.push_back($3); $$ = $1 ;}|
	direct_declarator LEFT_BRACKET STATIC type_qualifier_list assignment_expression RIGHT_BRACKET{$1->children.push_back("static"); $1->children.push_back($4);$1->children.push_back($5); $$ = $1 ;} |
	direct_declarator LEFT_BRACKET type_qualifier_list STATIC assignment_expression RIGHT_BRACKET{$1->children.push_back($3); $1->children.push_back("static");$1->children.push_back($5); $$ = $1 ;} |
	direct_declarator LEFT_BRACKET type_qualifier_list STAR RIGHT_BRACKET {$1->children.push_back($3); $$ = $1 ;}|
	direct_declarator LEFT_BRACKET STAR RIGHT_BRACKET {$$ = $1;} |
	direct_declarator LEFT_BRACKET RIGHT_BRACKET {$$ = $1;}|
	direct_declarator LEFT_PAR parameter_type_list RIGHT_PAR {$1->children.push_back($3); $$ = $1 ;}|
	direct_declarator LEFT_PAR identifier_list RIGHT_PAR {$1->children.push_back($3); $$ = $1 ;}|
	direct_declarator LEFT_PAR RIGHT_PAR{$$ = $1 ;}
;

type_qualifier_list:
    type_qualifier {$$ = new TypeQualifierListNode($1);} |
	type_qualifier_list type_qualifier{$1->children.push_back($2); $$ = $1 ;}
;

type_qualifier:
	CONST {$$ = new TypeQualifierNode(new KeywordNode($1));}|
	RESTRICT  {$$ = new TypeQualifierNode(new KeywordNode($1));}|
	VOLATILE {$$ = new TypeQualifierNode(new KeywordNode($1));}
;
parameter_type_list: 
    parameter_list {$$ = new ParameterTypeList($1);}|
	parameter_list COMMA ELLIPSIS{$$ = new ParameterTypeList($1, new KeywordNode($3));}
;

parameter_list:
	parameter_declaration SEMICOLON {$$ = new ParameterListNode($1);}|
	parameter_list COMMA parameter_declaration{$1->children.push_back($3); $$ = $1 ;}
;

parameter_declaration:
	declaration_specifiers declarator {$$ = new ParameterDeclarationNode($1);}|
	declaration_specifiers abstract_declarator {$$ = new ParameterDeclarationNode($1,$2);} |
	declaration_specifiers{$$ = new ParameterDeclarationNode($1);}
;
function_specifier: 
    INLINE{$$ = new FunctionSpecifierNode($1);}
;
type_specifier:
	VOID {$$ = new TypeSpecifierNode($1);}|
	CHAR{$$ = new TypeSpecifierNode($1);} |
	SHORT {$$ = new TypeSpecifierNode($1);}|
	INT {$$ = new TypeSpecifierNode($1);}|
	LONG{$$ = new TypeSpecifierNode($1);} |
	FLOAT{$$ = new TypeSpecifierNode($1);} |
	DOUBLE{$$ = new TypeSpecifierNode($1);} |
	SIGNED {$$ = new TypeSpecifierNode($1);}|
	UNSIGNED {$$ = new TypeSpecifierNode($1);}|
	BOOL{$$ = new TypeSpecifierNode($1);} |
	COMPLEX {$$ = new TypeSpecifierNode($1);}|
	IMAGINARY {$$ = new TypeSpecifierNode($1);}|
	struct_or_union_specifier {$$ = new TypeSpecifierNode($1);} |
	enum_specifier{$$ = new TypeSpecifierNode($1);} |
	type_name{$$ = new TypeSpecifierNode($1);}
;

struct_or_union_specifier:
	struct_or_union IDENTIFIER LEFT_CBRACKET struct_declaration_list RIGHT_CBRACKET {$$ = new StructOrUnionSpecifierNode($1, new IdentifierNode($2),$4);}|
	struct_or_union LEFT_CBRACKET struct_declaration_list RIGHT_CBRACKET {$$ = new StructOrUnionSpecifierNode($1, $3);}|
	struct_or_union IDENTIFIER {$$ = new StructOrUnionSpecifierNode($1, new IdentifierNode($2));}
;

struct_or_union:
	STRUCT {$$ = new KeywordNode($1);}|
	UNION{$$ = new KeywordNode($1);}
;

struct_declaration_list:
	struct_declaration{$$ = new StructDeclarationListNode($1);}|
	struct_declaration_list struct_declaration {$1->children.push_back($2); $$ = $1 ;}
;

struct_declaration:
	specifier_qualifier_list struct_declarator_list SEMICOLON{$$ = new StructDeclarationNode($1,$2);}
;

struct_declarator_list:
	struct_declarator {$$ = new StructDeclaratorListNode($1);}|
	struct_declarator_list COMMA struct_declarator {$1->children.push_back($2); $$ = $1 ;}
;

struct_declarator:
	declarator{ $$ = new StructDeclaratorNode($1);} |
	COLON constant_expression { $$ = new StructDeclaratorNode($2);}|
	declarator COLON constant_expression{{ $$ = new StructDeclaratorNode($1,$3);}}
;

specifier_qualifier_list:
	type_specifier specifier_qualifier_list {$2->children.push_back($1); $$ = $2 ;} |
	type_specifier{$$ = new SpecifierQualifierListNode($1);}|
	type_qualifier specifier_qualifier_list {$2->children.push_back($1); $$ = $2 ;}|
	type_qualifier{$$ = new SpecifierQualifierListNode($1);}
;


enum_specifier: 
    ENUM LEFT_CBRACKET enumerator_list RIGHT_CBRACKET {$$ = new EnumSpecifierNode(new KeywordNode($1), $3);}|
	ENUM IDENTIFIER LEFT_CBRACKET enumerator_list RIGHT_CBRACKET  {$$ = new EnumSpecifierNode(new KeywordNode($1),new IdentifierNode($2), $3);}|
	ENUM LEFT_CBRACKET enumerator_list COMMA RIGHT_CBRACKET  {$$ = new EnumSpecifierNode(new KeywordNode($1), $3);}|
	ENUM IDENTIFIER LEFT_CBRACKET enumerator_list COMMA RIGHT_CBRACKET {$$ = new EnumSpecifierNode(new KeywordNode($1),new IdentifierNode($2), $3);} |
	ENUM IDENTIFIER {$$ = new EnumSpecifierNode(new KeywordNode($1),new IdentifierNode($2));}
;

enumerator_list:
	enumerator {$$ = new EnumeratorListNode($1);}|
	enumerator_list COMMA enumerator{{$1->children.push_back($3); $$ = $1 ;}}
;

enumerator: 
    IDENTIFIER {$$ = new EnumeratorNode(new IdentifierNode($1));}|
	IDENTIFIER ASSIGN_OP constant_expression{$$ = new EnumeratorNode(new IdentifierNode($1),$3);}
;

type_name:
	specifier_qualifier_list {$$ = new TypeNameNode($1);}| 
    specifier_qualifier_list abstract_declarator{$$ = new TypeNameNode($1,$2);}
;

abstract_declarator:
	pointer {$$ = new AbstractDeclaratorNode($1);} |
	direct_abstract_declarator {$$ = new AbstractDeclaratorNode($1);}|
	pointer direct_abstract_declarator {$$ = new AbstractDeclaratorNode($1,$2);}
;

direct_abstract_declarator:
	LEFT_PAR abstract_declarator RIGHT_PAR { $$ = new DirectAbstractDeclaratorNode($2); } |
	LEFT_BRACKET RIGHT_BRACKET { $$ = new DirectAbstractDeclaratorNode(); }|
	LEFT_BRACKET assignment_expression RIGHT_BRACKET { $$ = new DirectAbstractDeclaratorNode($2); } |
	direct_abstract_declarator LEFT_BRACKET RIGHT_BRACKET { $1->children.push_back(new DirectAbstractDeclaratorNode()); } |
	direct_abstract_declarator LEFT_BRACKET assignment_expression RIGHT_BRACKET { $1->children.push_back(new DirectAbstractDeclaratorNode($3)); } |
	LEFT_BRACKET STAR RIGHT_BRACKET { $$ = new DirectAbstractDeclaratorNode(); } |
	direct_abstract_declarator LEFT_BRACKET STAR RIGHT_BRACKET { $1->children.push_back(new DirectAbstractDeclaratorNode()); } |
	LEFT_PAR RIGHT_PAR { $$ = new DirectAbstractDeclaratorNode(); } |
	LEFT_PAR parameter_type_list RIGHT_PAR { $$ = new DirectAbstractDeclaratorNode($2); } |
	direct_abstract_declarator LEFT_PAR RIGHT_PAR { $1->children.push_back(new DirectAbstractDeclaratorNode()); } |
	direct_abstract_declarator LEFT_PAR parameter_type_list RIGHT_PAR { $1->children.push_back(new DirectAbstractDeclaratorNode($3)); }
;

statement:
	labeled_statement { $$ = new StatementNode($1); } |
	compound_statement { $$ = new StatementNode($1); } |
	expression_statement { $$ = new StatementNode($1); } |
	selection_statement { $$ = new StatementNode($1); } | 
	iteration_statement { $$ = new StatementNode($1); } |
	jump_statement { $$ = new StatementNode($1); }
;

labeled_statement:
	IDENTIFIER COLON statement { $$ = new LabeledStatementNode($3); } |
	CASE constant_expression COLON statement { $$ = new LabeledStatementNode($2, $4); } |
	DEFAULT COLON statement { $$ = new LabeledStatementNode($3); }
;

compound_statement:
	LEFT_CBRACKET RIGHT_CBRACKET { $$ = new CompoundStatementNode(); } |
	LEFT_CBRACKET block_item_list RIGHT_CBRACKET { $$ = new CompoundStatementNode($2); }
;

block_item_list:
	block_item { $$ = new BlockItemList($1); } |
	block_item_list block_item { $1->children.push_back($2); $$ = $1; }
;

block_item:
	declaration { $$ = new BlockItemNode($1); } |
	statement { $$ = new BlockItemNode($1); }
;

expression_statement:
	SEMICOLON { $$ = new ExpressionStatementNode(); } |
	expression SEMICOLON { $$ = new ExpressionStatementNode($1); }
;

selection_statement:
	IF LEFT_PAR expression RIGHT_PAR statement { $$ = new SelectionStatementNode($3, $5); } |
    IF LEFT_PAR expression RIGHT_PAR statement ELSE statement { $$ = new SelectionStatementNode($3, $5, $7); } |
	SWITCH LEFT_PAR expression RIGHT_PAR statement { $$ = new SelectionStatementNode($3, $5); }
;

iteration_statement:
	WHILE LEFT_PAR expression RIGHT_PAR statement { $$ = new IterationStatementNode($3, $5); } |
	DO statement WHILE LEFT_PAR expression RIGHT_PAR SEMICOLON { $$ = new IterationStatementNode($2, $5); } |
	FOR LEFT_PAR expression_statement expression_statement RIGHT_PAR statement { $$ = new IterationStatementNode($3, $4, $6); } |
	FOR LEFT_PAR expression_statement expression_statement expression RIGHT_PAR statement { $$ = new IterationStatementNode($3, $4, $5, $6); } |
	FOR LEFT_PAR declaration expression_statement RIGHT_PAR statement { $$ = new IterationStatementNode($3, $4, $6); } |
	FOR LEFT_PAR declaration expression_statement expression RIGHT_PAR statement { $$ = new IterationStatementNode($3, $4, $5, $6); }
;

jump_statement: 
	GOTO IDENTIFIER SEMICOLON { $$ = new JumpStatementNode($2); } |
	CONTINUE SEMICOLON { $$ = new JumpStatementNode(); } |
	BREAK SEMICOLON { $$ = new JumpStatementNode(); } | 
	RETURN SEMICOLON { $$ = new JumpStatementNode(); } |
    RETURN expression SEMICOLON { $$ = new JumpStatementNode($2); }
;

translation_unit:
	external_declaration { $$ = new TranslationUnitNode($1); } |
	translation_unit external_declaration { $1->children.push_back($2); $$ = $1; }
;

external_declaration:
	function_definition { $$ = new ExternalDeclarationNode($1); } |
	declaration { $$ = new ExternalDeclarationNode($1); }
;

function_definition:
	declaration_specifiers declarator declaration_list compound_statement { $$ = new FunctionDeclarationNode($1, $2, $3, $4); } |
	declaration_specifiers declarator compound_statement { $$ = new FunctionDeclarationNode($1, $2, $3); }
;

declaration_list: 
    declaration { $$ = new DeclarationList($1); }
  | declaration_list declaration { $1->children.push_back($2); $$ = $1; }
;

identifier_list:
    IDENTIFIER { $$ = new IdentifierList($1); }
  | identifier_list COMMA IDENTIFIER { $1->children.push_back($3); $$ = $1; }
;
