%{
    %language "c++"
%}

// Tokens

// Keywords
%token AUTO
%token BOOL
%token BREAK
%token CASE
%token CHAR
%token COMPLEX
%token CONST
%token CONTINUE
%token DEFAULT
%token DO
%token DOUBLE
%token ELSE
%token ENUM
%token EXTERN
%token FLOAT
%token FOR
%token GOTO
%token IF
%token IMAGINARY
%token INLINE
%token INT
%token LONG
%token REGISTER
%token RESTRICT
%token RETURN
%token SHORT
%token SIGNED
%token SIZEOF
%token STATIC
%token STRUCT
%token SWITCH
%token TYPEDEF
%token UNION
%token UNSIGNED
%token VOID
%token VOLATILE
%token WHILE

%token IDENTIFIER

LITERAL // Integer literal

STRING_LITERAL  // String literal

// // Delimeters
// %token ;
// %token ,
// %token :
// %token (
// %token )
// %token .
// %token {
// %token }
// %token [
// %token ]

// // Operators
// %token =
// %token ?
// %token -
// %token +
// %token *
// %token /
// %token %
// %token <
// %token >
// %token ^
// %token &
// %token !
// %token ~
// %token |

%token ELLIPSIS
%token RIGHT_ASSIGN
%token LEFT_ASSIGN
%token ADD_ASSIGN
%token SUB_ASSIGN
%token MUL_ASSIGN
%token DIV_ASSIGN
%token MOD_ASSIGN
%token AND_ASSIGN
%token XOR_ASSIGN
%token OR_ASSIGN
%token RIGHT_OP
%token LEFT_OP
%token INC_OP
%token DEC_OP
%token PTR_OP
%token AND_OP
%token OR_OP
%token LE_OP
%token GE_OP
%token EQ_OP
%token NE_OP

%start primary_expression

// Grammar
%%

primary_expression:
      IDENTIFIER
    | LITERAL
    | STRING_LITERAL
    | '(' expression ')'
;

postfix_expression:
      primary_expression
    | postfix_expression '[' expression ']'
    | postfix_expression '(' argument_expression_list ')'
    | postfix_expression '(' ')'
    | postfix_expression '.' IDENTIFIER
    | postfix_expression PTR_OP IDENTIFIER
    | postfix_expression INC_OP
    | postfix_expression DEC_OP
    | '(' type_name ')' '{' initializer_list '}'
    | '(' type_name ')' '{' initializer_list , '}'
;

argument_expression_list:
      IDENTIFIER
    | IDENTIFIER ',' argument_expression_list
;

unary_expression:
      postfix_expression
    | INC_OP unary_expression
    | DEC_OP unary_expression
    | unary_operator cast_expression
    | SIZEOF unary_expression
    | SIZEOF '(' type_name ')'
;

unary_operator:
    '&' | '*' | '+' | '-' | '˜' | '!'
;

cast_expression:
      unary_expression
    | ( type_name ) cast_expression
;

multiplicative_expression:
      cast_expression
    | multiplicative_expression '*' cast_expression
    | multiplicative_expression '/' cast_expression
    | multiplicative_expression '%' cast_expression
;

additive_expression:
      multiplicative_expression
    | additive_expression '+' multiplicative_expression
    | additive_expression '-' multiplicative_expression
;

shift_expression:
      additive_expression
    | shift_expression LEFT_OP additive_expression
    | shift_expression RIGHT_OP additive_expression
;

relational_expression:
      shift_expression
    | relational_expression '<' shift_expression
    | relational_expression '>' shift_expression
    | relational_expression LE_OP shift_expression
    | relational_expression GE_OP shift_expression
;

equality_expression:
      relational_expression
    | equality_expression EQ_OP relational_expression
    | equality_expression NE_OP relational_expression
;

and_expression:
      equality_expression
    | and_expression '&' equality_expression
;

exclusive_or_expression:
      and_expression
    | exclusive_or_expression 'ˆ' and_expression
;

inclusive_or_expression:
      exclusive_or_expression
    | inclusive_or_expression '|' exclusive_or_expression
;

logical_and_expression:
      inclusive_or_expression
    | logical_and_expression AND_OP inclusive_or_expression
;

logical_or_expression:
      logical_and_expression
    | logical_or_expression OR_OP logical_and_expression
;

conditional_expression:
      logical_or_expression
    | logical_or_expression '?' expression ':' conditional_expression
;

assignment_expression:
      conditional_expression
    | unary_expression assignment_operator assignment_expression
;

assignment_operator:
      '=' | MUL_ASSIGN | DIV_ASSIGN | MOD_ASSIGN | ADD_ASSIGN | SUB_ASSIGN 
    | LEFT_ASSIGN | RIGHT_ASSIGN | AND_ASSIGN | XOR_ASSIGN | OR_ASSIGN
;

expression:
      assignment_expression
    | expression ',' assignment_expression
;

conditional_expression:
    conditional_expression
;


%%

// Epilogue