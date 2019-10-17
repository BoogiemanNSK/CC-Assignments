// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.
// //                    "%code top" blocks.
#line 10 "parser.yy" // lalr1.cc:397

   #include "driver.hh"
   #include <vector>
   #include <string>
   #include <iostream> 
   #include <sstream>

   using namespace std;

   class AstNode {
      public:
         vector<AstNode*> children;
         string name;
         
         AstNode(string _name, vector<AstNode*> _children) {
               children = _children;
               name = _name;
         }

         AstNode(string _name){
               children = vector<AstNode*>();
               name = _name;
         }
         
         void print_tree() {
               cout << this->get_ident();
               for (int i = 0; i < children.size(); i++) {
                  cout << " " << children[i]->get_ident();
               }
               cout << endl;
               for (int i = 0; i < children.size(); i++) {
                  children[i] -> print_tree();
               }
         }

         string get_ident() {
               ostringstream buffer;
               buffer << this << "_" << name;
               string res = string(buffer.str());
               return(res);
         }

   };

   typedef AstNode* AstNodePtr;

#line 81 "parser.cc" // lalr1.cc:397


// First part of user declarations.

#line 86 "parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hh"

// User implementation prologue.

#line 100 "parser.cc" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 167 "parser.cc" // lalr1.cc:479

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
      switch (other.type_get ())
    {
      case 90: // primary_expression
      case 91: // postfix_expression
      case 92: // argument_expression_list
      case 93: // unary_expression
      case 94: // unary_operator
      case 95: // cast_expression
      case 96: // multiplicative_expression
      case 97: // additive_expression
      case 98: // shift_expression
      case 99: // relational_expression
      case 100: // equality_expression
      case 101: // and_expression
      case 102: // exclusive_or_expression
      case 103: // inclusive_or_expression
      case 104: // logical_and_expression
      case 105: // logical_or_expression
      case 106: // conditional_expression
      case 107: // assignment_expression
      case 108: // assignment_operator
      case 109: // expression
      case 110: // constant_expression
      case 111: // declaration
      case 112: // declaration_specifiers
      case 113: // storage_class_specifier
      case 114: // init_declarator_list
      case 115: // init_declarator
      case 116: // initializer
      case 117: // initializer_list
      case 118: // designation
      case 119: // designator_list
      case 120: // designator
      case 121: // declarator
      case 122: // pointer
      case 123: // direct_declarator
      case 124: // type_qualifier_list
      case 125: // type_qualifier
      case 126: // parameter_type_list
      case 127: // parameter_list
      case 128: // parameter_declaration
      case 129: // function_specifier
      case 130: // type_specifier
      case 131: // struct_or_union_specifier
      case 132: // struct_or_union
      case 133: // struct_declaration_list
      case 134: // struct_declaration
      case 135: // struct_declarator_list
      case 136: // struct_declarator
      case 137: // specifier_qualifier_list
      case 138: // enum_specifier
      case 139: // enumerator_list
      case 140: // enumerator
      case 141: // type_name
      case 142: // abstract_declarator
      case 143: // direct_abstract_declarator
      case 144: // statement
      case 145: // labeled_statement
      case 146: // compound_statement
      case 147: // block_item_list
      case 148: // block_item
      case 149: // expression_statement
      case 150: // selection_statement
      case 151: // iteration_statement
      case 152: // jump_statement
      case 153: // translation_unit
      case 154: // external_declaration
      case 155: // function_definition
      case 156: // declaration_list
      case 157: // identifier_list
        value.copy< AstNodePtr > (other.value);
        break;

      case 3: // AUTO
      case 4: // BOOL
      case 5: // BREAK
      case 6: // CASE
      case 7: // CHAR
      case 8: // COMPLEX
      case 9: // CONST
      case 10: // CONTINUE
      case 11: // DEFAULT
      case 12: // DO
      case 13: // DOUBLE
      case 14: // ELSE
      case 15: // ENUM
      case 16: // EXTERN
      case 17: // FLOAT
      case 18: // FOR
      case 19: // GOTO
      case 20: // IF
      case 21: // IMAGINARY
      case 22: // INLINE
      case 23: // INT
      case 24: // LONG
      case 25: // REGISTER
      case 26: // RESTRICT
      case 27: // RETURN
      case 28: // SHORT
      case 29: // SIGNED
      case 30: // SIZEOF
      case 31: // STATIC
      case 32: // STRUCT
      case 33: // SWITCH
      case 34: // TYPEDEF
      case 35: // UNION
      case 36: // UNSIGNED
      case 37: // VOID
      case 38: // VOLATILE
      case 39: // WHILE
      case 40: // IDENTIFIER
      case 41: // LITERAL
      case 42: // STRING_LITERAL
      case 43: // ";"
      case 44: // ","
      case 45: // ":"
      case 46: // "("
      case 47: // ")"
      case 48: // "."
      case 49: // "{"
      case 50: // "}"
      case 51: // "["
      case 52: // "]"
      case 53: // "="
      case 54: // "&"
      case 55: // "!"
      case 56: // "~"
      case 57: // "-"
      case 58: // "+"
      case 59: // "*"
      case 60: // "/"
      case 61: // "%"
      case 62: // "<"
      case 63: // ">"
      case 64: // "^"
      case 65: // "|"
      case 66: // "?"
      case 67: // "..."
      case 68: // ">>="
      case 69: // "<<="
      case 70: // "+="
      case 71: // "-="
      case 72: // "*="
      case 73: // "/="
      case 74: // "%="
      case 75: // "&="
      case 76: // "^="
      case 77: // "|="
      case 78: // ">>"
      case 79: // "<<"
      case 80: // "++"
      case 81: // "--"
      case 82: // "->"
      case 83: // "&&"
      case 84: // "||"
      case 85: // "<="
      case 86: // ">="
      case 87: // "=="
      case 88: // "!="
        value.copy< string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value ()
  {
    (void) v;
      switch (this->type_get ())
    {
      case 90: // primary_expression
      case 91: // postfix_expression
      case 92: // argument_expression_list
      case 93: // unary_expression
      case 94: // unary_operator
      case 95: // cast_expression
      case 96: // multiplicative_expression
      case 97: // additive_expression
      case 98: // shift_expression
      case 99: // relational_expression
      case 100: // equality_expression
      case 101: // and_expression
      case 102: // exclusive_or_expression
      case 103: // inclusive_or_expression
      case 104: // logical_and_expression
      case 105: // logical_or_expression
      case 106: // conditional_expression
      case 107: // assignment_expression
      case 108: // assignment_operator
      case 109: // expression
      case 110: // constant_expression
      case 111: // declaration
      case 112: // declaration_specifiers
      case 113: // storage_class_specifier
      case 114: // init_declarator_list
      case 115: // init_declarator
      case 116: // initializer
      case 117: // initializer_list
      case 118: // designation
      case 119: // designator_list
      case 120: // designator
      case 121: // declarator
      case 122: // pointer
      case 123: // direct_declarator
      case 124: // type_qualifier_list
      case 125: // type_qualifier
      case 126: // parameter_type_list
      case 127: // parameter_list
      case 128: // parameter_declaration
      case 129: // function_specifier
      case 130: // type_specifier
      case 131: // struct_or_union_specifier
      case 132: // struct_or_union
      case 133: // struct_declaration_list
      case 134: // struct_declaration
      case 135: // struct_declarator_list
      case 136: // struct_declarator
      case 137: // specifier_qualifier_list
      case 138: // enum_specifier
      case 139: // enumerator_list
      case 140: // enumerator
      case 141: // type_name
      case 142: // abstract_declarator
      case 143: // direct_abstract_declarator
      case 144: // statement
      case 145: // labeled_statement
      case 146: // compound_statement
      case 147: // block_item_list
      case 148: // block_item
      case 149: // expression_statement
      case 150: // selection_statement
      case 151: // iteration_statement
      case 152: // jump_statement
      case 153: // translation_unit
      case 154: // external_declaration
      case 155: // function_definition
      case 156: // declaration_list
      case 157: // identifier_list
        value.copy< AstNodePtr > (v);
        break;

      case 3: // AUTO
      case 4: // BOOL
      case 5: // BREAK
      case 6: // CASE
      case 7: // CHAR
      case 8: // COMPLEX
      case 9: // CONST
      case 10: // CONTINUE
      case 11: // DEFAULT
      case 12: // DO
      case 13: // DOUBLE
      case 14: // ELSE
      case 15: // ENUM
      case 16: // EXTERN
      case 17: // FLOAT
      case 18: // FOR
      case 19: // GOTO
      case 20: // IF
      case 21: // IMAGINARY
      case 22: // INLINE
      case 23: // INT
      case 24: // LONG
      case 25: // REGISTER
      case 26: // RESTRICT
      case 27: // RETURN
      case 28: // SHORT
      case 29: // SIGNED
      case 30: // SIZEOF
      case 31: // STATIC
      case 32: // STRUCT
      case 33: // SWITCH
      case 34: // TYPEDEF
      case 35: // UNION
      case 36: // UNSIGNED
      case 37: // VOID
      case 38: // VOLATILE
      case 39: // WHILE
      case 40: // IDENTIFIER
      case 41: // LITERAL
      case 42: // STRING_LITERAL
      case 43: // ";"
      case 44: // ","
      case 45: // ":"
      case 46: // "("
      case 47: // ")"
      case 48: // "."
      case 49: // "{"
      case 50: // "}"
      case 51: // "["
      case 52: // "]"
      case 53: // "="
      case 54: // "&"
      case 55: // "!"
      case 56: // "~"
      case 57: // "-"
      case 58: // "+"
      case 59: // "*"
      case 60: // "/"
      case 61: // "%"
      case 62: // "<"
      case 63: // ">"
      case 64: // "^"
      case 65: // "|"
      case 66: // "?"
      case 67: // "..."
      case 68: // ">>="
      case 69: // "<<="
      case 70: // "+="
      case 71: // "-="
      case 72: // "*="
      case 73: // "/="
      case 74: // "%="
      case 75: // "&="
      case 76: // "^="
      case 77: // "|="
      case 78: // ">>"
      case 79: // "<<"
      case 80: // "++"
      case 81: // "--"
      case 82: // "->"
      case 83: // "&&"
      case 84: // "||"
      case 85: // "<="
      case 86: // ">="
      case 87: // "=="
      case 88: // "!="
        value.copy< string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstNodePtr v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const string v)
    : Base (t)
    , value (v)
  {}


  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 90: // primary_expression
      case 91: // postfix_expression
      case 92: // argument_expression_list
      case 93: // unary_expression
      case 94: // unary_operator
      case 95: // cast_expression
      case 96: // multiplicative_expression
      case 97: // additive_expression
      case 98: // shift_expression
      case 99: // relational_expression
      case 100: // equality_expression
      case 101: // and_expression
      case 102: // exclusive_or_expression
      case 103: // inclusive_or_expression
      case 104: // logical_and_expression
      case 105: // logical_or_expression
      case 106: // conditional_expression
      case 107: // assignment_expression
      case 108: // assignment_operator
      case 109: // expression
      case 110: // constant_expression
      case 111: // declaration
      case 112: // declaration_specifiers
      case 113: // storage_class_specifier
      case 114: // init_declarator_list
      case 115: // init_declarator
      case 116: // initializer
      case 117: // initializer_list
      case 118: // designation
      case 119: // designator_list
      case 120: // designator
      case 121: // declarator
      case 122: // pointer
      case 123: // direct_declarator
      case 124: // type_qualifier_list
      case 125: // type_qualifier
      case 126: // parameter_type_list
      case 127: // parameter_list
      case 128: // parameter_declaration
      case 129: // function_specifier
      case 130: // type_specifier
      case 131: // struct_or_union_specifier
      case 132: // struct_or_union
      case 133: // struct_declaration_list
      case 134: // struct_declaration
      case 135: // struct_declarator_list
      case 136: // struct_declarator
      case 137: // specifier_qualifier_list
      case 138: // enum_specifier
      case 139: // enumerator_list
      case 140: // enumerator
      case 141: // type_name
      case 142: // abstract_declarator
      case 143: // direct_abstract_declarator
      case 144: // statement
      case 145: // labeled_statement
      case 146: // compound_statement
      case 147: // block_item_list
      case 148: // block_item
      case 149: // expression_statement
      case 150: // selection_statement
      case 151: // iteration_statement
      case 152: // jump_statement
      case 153: // translation_unit
      case 154: // external_declaration
      case 155: // function_definition
      case 156: // declaration_list
      case 157: // identifier_list
        value.template destroy< AstNodePtr > ();
        break;

      case 3: // AUTO
      case 4: // BOOL
      case 5: // BREAK
      case 6: // CASE
      case 7: // CHAR
      case 8: // COMPLEX
      case 9: // CONST
      case 10: // CONTINUE
      case 11: // DEFAULT
      case 12: // DO
      case 13: // DOUBLE
      case 14: // ELSE
      case 15: // ENUM
      case 16: // EXTERN
      case 17: // FLOAT
      case 18: // FOR
      case 19: // GOTO
      case 20: // IF
      case 21: // IMAGINARY
      case 22: // INLINE
      case 23: // INT
      case 24: // LONG
      case 25: // REGISTER
      case 26: // RESTRICT
      case 27: // RETURN
      case 28: // SHORT
      case 29: // SIGNED
      case 30: // SIZEOF
      case 31: // STATIC
      case 32: // STRUCT
      case 33: // SWITCH
      case 34: // TYPEDEF
      case 35: // UNION
      case 36: // UNSIGNED
      case 37: // VOID
      case 38: // VOLATILE
      case 39: // WHILE
      case 40: // IDENTIFIER
      case 41: // LITERAL
      case 42: // STRING_LITERAL
      case 43: // ";"
      case 44: // ","
      case 45: // ":"
      case 46: // "("
      case 47: // ")"
      case 48: // "."
      case 49: // "{"
      case 50: // "}"
      case 51: // "["
      case 52: // "]"
      case 53: // "="
      case 54: // "&"
      case 55: // "!"
      case 56: // "~"
      case 57: // "-"
      case 58: // "+"
      case 59: // "*"
      case 60: // "/"
      case 61: // "%"
      case 62: // "<"
      case 63: // ">"
      case 64: // "^"
      case 65: // "|"
      case 66: // "?"
      case 67: // "..."
      case 68: // ">>="
      case 69: // "<<="
      case 70: // "+="
      case 71: // "-="
      case 72: // "*="
      case 73: // "/="
      case 74: // "%="
      case 75: // "&="
      case 76: // "^="
      case 77: // "|="
      case 78: // ">>"
      case 79: // "<<"
      case 80: // "++"
      case 81: // "--"
      case 82: // "->"
      case 83: // "&&"
      case 84: // "||"
      case 85: // "<="
      case 86: // ">="
      case 87: // "=="
      case 88: // "!="
        value.template destroy< string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 90: // primary_expression
      case 91: // postfix_expression
      case 92: // argument_expression_list
      case 93: // unary_expression
      case 94: // unary_operator
      case 95: // cast_expression
      case 96: // multiplicative_expression
      case 97: // additive_expression
      case 98: // shift_expression
      case 99: // relational_expression
      case 100: // equality_expression
      case 101: // and_expression
      case 102: // exclusive_or_expression
      case 103: // inclusive_or_expression
      case 104: // logical_and_expression
      case 105: // logical_or_expression
      case 106: // conditional_expression
      case 107: // assignment_expression
      case 108: // assignment_operator
      case 109: // expression
      case 110: // constant_expression
      case 111: // declaration
      case 112: // declaration_specifiers
      case 113: // storage_class_specifier
      case 114: // init_declarator_list
      case 115: // init_declarator
      case 116: // initializer
      case 117: // initializer_list
      case 118: // designation
      case 119: // designator_list
      case 120: // designator
      case 121: // declarator
      case 122: // pointer
      case 123: // direct_declarator
      case 124: // type_qualifier_list
      case 125: // type_qualifier
      case 126: // parameter_type_list
      case 127: // parameter_list
      case 128: // parameter_declaration
      case 129: // function_specifier
      case 130: // type_specifier
      case 131: // struct_or_union_specifier
      case 132: // struct_or_union
      case 133: // struct_declaration_list
      case 134: // struct_declaration
      case 135: // struct_declarator_list
      case 136: // struct_declarator
      case 137: // specifier_qualifier_list
      case 138: // enum_specifier
      case 139: // enumerator_list
      case 140: // enumerator
      case 141: // type_name
      case 142: // abstract_declarator
      case 143: // direct_abstract_declarator
      case 144: // statement
      case 145: // labeled_statement
      case 146: // compound_statement
      case 147: // block_item_list
      case 148: // block_item
      case 149: // expression_statement
      case 150: // selection_statement
      case 151: // iteration_statement
      case 152: // jump_statement
      case 153: // translation_unit
      case 154: // external_declaration
      case 155: // function_definition
      case 156: // declaration_list
      case 157: // identifier_list
        value.move< AstNodePtr > (s.value);
        break;

      case 3: // AUTO
      case 4: // BOOL
      case 5: // BREAK
      case 6: // CASE
      case 7: // CHAR
      case 8: // COMPLEX
      case 9: // CONST
      case 10: // CONTINUE
      case 11: // DEFAULT
      case 12: // DO
      case 13: // DOUBLE
      case 14: // ELSE
      case 15: // ENUM
      case 16: // EXTERN
      case 17: // FLOAT
      case 18: // FOR
      case 19: // GOTO
      case 20: // IF
      case 21: // IMAGINARY
      case 22: // INLINE
      case 23: // INT
      case 24: // LONG
      case 25: // REGISTER
      case 26: // RESTRICT
      case 27: // RETURN
      case 28: // SHORT
      case 29: // SIGNED
      case 30: // SIZEOF
      case 31: // STATIC
      case 32: // STRUCT
      case 33: // SWITCH
      case 34: // TYPEDEF
      case 35: // UNION
      case 36: // UNSIGNED
      case 37: // VOID
      case 38: // VOLATILE
      case 39: // WHILE
      case 40: // IDENTIFIER
      case 41: // LITERAL
      case 42: // STRING_LITERAL
      case 43: // ";"
      case 44: // ","
      case 45: // ":"
      case 46: // "("
      case 47: // ")"
      case 48: // "."
      case 49: // "{"
      case 50: // "}"
      case 51: // "["
      case 52: // "]"
      case 53: // "="
      case 54: // "&"
      case 55: // "!"
      case 56: // "~"
      case 57: // "-"
      case 58: // "+"
      case 59: // "*"
      case 60: // "/"
      case 61: // "%"
      case 62: // "<"
      case 63: // ">"
      case 64: // "^"
      case 65: // "|"
      case 66: // "?"
      case 67: // "..."
      case 68: // ">>="
      case 69: // "<<="
      case 70: // "+="
      case 71: // "-="
      case 72: // "*="
      case 73: // "/="
      case 74: // "%="
      case 75: // "&="
      case 76: // "^="
      case 77: // "|="
      case 78: // ">>"
      case 79: // "<<"
      case 80: // "++"
      case 81: // "--"
      case 82: // "->"
      case 83: // "&&"
      case 84: // "||"
      case 85: // "<="
      case 86: // ">="
      case 87: // "=="
      case 88: // "!="
        value.move< string > (s.value);
        break;

      default:
        break;
    }

  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  parser::symbol_type
  parser::make_AUTO (const string& v)
  {
    return symbol_type (token::AUTO, v);
  }

  parser::symbol_type
  parser::make_BOOL (const string& v)
  {
    return symbol_type (token::BOOL, v);
  }

  parser::symbol_type
  parser::make_BREAK (const string& v)
  {
    return symbol_type (token::BREAK, v);
  }

  parser::symbol_type
  parser::make_CASE (const string& v)
  {
    return symbol_type (token::CASE, v);
  }

  parser::symbol_type
  parser::make_CHAR (const string& v)
  {
    return symbol_type (token::CHAR, v);
  }

  parser::symbol_type
  parser::make_COMPLEX (const string& v)
  {
    return symbol_type (token::COMPLEX, v);
  }

  parser::symbol_type
  parser::make_CONST (const string& v)
  {
    return symbol_type (token::CONST, v);
  }

  parser::symbol_type
  parser::make_CONTINUE (const string& v)
  {
    return symbol_type (token::CONTINUE, v);
  }

  parser::symbol_type
  parser::make_DEFAULT (const string& v)
  {
    return symbol_type (token::DEFAULT, v);
  }

  parser::symbol_type
  parser::make_DO (const string& v)
  {
    return symbol_type (token::DO, v);
  }

  parser::symbol_type
  parser::make_DOUBLE (const string& v)
  {
    return symbol_type (token::DOUBLE, v);
  }

  parser::symbol_type
  parser::make_ELSE (const string& v)
  {
    return symbol_type (token::ELSE, v);
  }

  parser::symbol_type
  parser::make_ENUM (const string& v)
  {
    return symbol_type (token::ENUM, v);
  }

  parser::symbol_type
  parser::make_EXTERN (const string& v)
  {
    return symbol_type (token::EXTERN, v);
  }

  parser::symbol_type
  parser::make_FLOAT (const string& v)
  {
    return symbol_type (token::FLOAT, v);
  }

  parser::symbol_type
  parser::make_FOR (const string& v)
  {
    return symbol_type (token::FOR, v);
  }

  parser::symbol_type
  parser::make_GOTO (const string& v)
  {
    return symbol_type (token::GOTO, v);
  }

  parser::symbol_type
  parser::make_IF (const string& v)
  {
    return symbol_type (token::IF, v);
  }

  parser::symbol_type
  parser::make_IMAGINARY (const string& v)
  {
    return symbol_type (token::IMAGINARY, v);
  }

  parser::symbol_type
  parser::make_INLINE (const string& v)
  {
    return symbol_type (token::INLINE, v);
  }

  parser::symbol_type
  parser::make_INT (const string& v)
  {
    return symbol_type (token::INT, v);
  }

  parser::symbol_type
  parser::make_LONG (const string& v)
  {
    return symbol_type (token::LONG, v);
  }

  parser::symbol_type
  parser::make_REGISTER (const string& v)
  {
    return symbol_type (token::REGISTER, v);
  }

  parser::symbol_type
  parser::make_RESTRICT (const string& v)
  {
    return symbol_type (token::RESTRICT, v);
  }

  parser::symbol_type
  parser::make_RETURN (const string& v)
  {
    return symbol_type (token::RETURN, v);
  }

  parser::symbol_type
  parser::make_SHORT (const string& v)
  {
    return symbol_type (token::SHORT, v);
  }

  parser::symbol_type
  parser::make_SIGNED (const string& v)
  {
    return symbol_type (token::SIGNED, v);
  }

  parser::symbol_type
  parser::make_SIZEOF (const string& v)
  {
    return symbol_type (token::SIZEOF, v);
  }

  parser::symbol_type
  parser::make_STATIC (const string& v)
  {
    return symbol_type (token::STATIC, v);
  }

  parser::symbol_type
  parser::make_STRUCT (const string& v)
  {
    return symbol_type (token::STRUCT, v);
  }

  parser::symbol_type
  parser::make_SWITCH (const string& v)
  {
    return symbol_type (token::SWITCH, v);
  }

  parser::symbol_type
  parser::make_TYPEDEF (const string& v)
  {
    return symbol_type (token::TYPEDEF, v);
  }

  parser::symbol_type
  parser::make_UNION (const string& v)
  {
    return symbol_type (token::UNION, v);
  }

  parser::symbol_type
  parser::make_UNSIGNED (const string& v)
  {
    return symbol_type (token::UNSIGNED, v);
  }

  parser::symbol_type
  parser::make_VOID (const string& v)
  {
    return symbol_type (token::VOID, v);
  }

  parser::symbol_type
  parser::make_VOLATILE (const string& v)
  {
    return symbol_type (token::VOLATILE, v);
  }

  parser::symbol_type
  parser::make_WHILE (const string& v)
  {
    return symbol_type (token::WHILE, v);
  }

  parser::symbol_type
  parser::make_IDENTIFIER (const string& v)
  {
    return symbol_type (token::IDENTIFIER, v);
  }

  parser::symbol_type
  parser::make_LITERAL (const string& v)
  {
    return symbol_type (token::LITERAL, v);
  }

  parser::symbol_type
  parser::make_STRING_LITERAL (const string& v)
  {
    return symbol_type (token::STRING_LITERAL, v);
  }

  parser::symbol_type
  parser::make_SEMICOLON (const string& v)
  {
    return symbol_type (token::SEMICOLON, v);
  }

  parser::symbol_type
  parser::make_COMMA (const string& v)
  {
    return symbol_type (token::COMMA, v);
  }

  parser::symbol_type
  parser::make_COLON (const string& v)
  {
    return symbol_type (token::COLON, v);
  }

  parser::symbol_type
  parser::make_LEFT_PAR (const string& v)
  {
    return symbol_type (token::LEFT_PAR, v);
  }

  parser::symbol_type
  parser::make_RIGHT_PAR (const string& v)
  {
    return symbol_type (token::RIGHT_PAR, v);
  }

  parser::symbol_type
  parser::make_DOT (const string& v)
  {
    return symbol_type (token::DOT, v);
  }

  parser::symbol_type
  parser::make_LEFT_CBRACKET (const string& v)
  {
    return symbol_type (token::LEFT_CBRACKET, v);
  }

  parser::symbol_type
  parser::make_RIGHT_CBRACKET (const string& v)
  {
    return symbol_type (token::RIGHT_CBRACKET, v);
  }

  parser::symbol_type
  parser::make_LEFT_BRACKET (const string& v)
  {
    return symbol_type (token::LEFT_BRACKET, v);
  }

  parser::symbol_type
  parser::make_RIGHT_BRACKET (const string& v)
  {
    return symbol_type (token::RIGHT_BRACKET, v);
  }

  parser::symbol_type
  parser::make_ASSIGN_OP (const string& v)
  {
    return symbol_type (token::ASSIGN_OP, v);
  }

  parser::symbol_type
  parser::make_AMP (const string& v)
  {
    return symbol_type (token::AMP, v);
  }

  parser::symbol_type
  parser::make_LOG_NOT_OP (const string& v)
  {
    return symbol_type (token::LOG_NOT_OP, v);
  }

  parser::symbol_type
  parser::make_BIN_NOT_OP (const string& v)
  {
    return symbol_type (token::BIN_NOT_OP, v);
  }

  parser::symbol_type
  parser::make_MINUS (const string& v)
  {
    return symbol_type (token::MINUS, v);
  }

  parser::symbol_type
  parser::make_PLUS (const string& v)
  {
    return symbol_type (token::PLUS, v);
  }

  parser::symbol_type
  parser::make_STAR (const string& v)
  {
    return symbol_type (token::STAR, v);
  }

  parser::symbol_type
  parser::make_SLASH (const string& v)
  {
    return symbol_type (token::SLASH, v);
  }

  parser::symbol_type
  parser::make_MOD_OP (const string& v)
  {
    return symbol_type (token::MOD_OP, v);
  }

  parser::symbol_type
  parser::make_G_OP (const string& v)
  {
    return symbol_type (token::G_OP, v);
  }

  parser::symbol_type
  parser::make_L_OP (const string& v)
  {
    return symbol_type (token::L_OP, v);
  }

  parser::symbol_type
  parser::make_BIN_XOR_OP (const string& v)
  {
    return symbol_type (token::BIN_XOR_OP, v);
  }

  parser::symbol_type
  parser::make_BIN_OR_OP (const string& v)
  {
    return symbol_type (token::BIN_OR_OP, v);
  }

  parser::symbol_type
  parser::make_TERNARY_OP (const string& v)
  {
    return symbol_type (token::TERNARY_OP, v);
  }

  parser::symbol_type
  parser::make_ELLIPSIS (const string& v)
  {
    return symbol_type (token::ELLIPSIS, v);
  }

  parser::symbol_type
  parser::make_RIGHT_ASSIGN (const string& v)
  {
    return symbol_type (token::RIGHT_ASSIGN, v);
  }

  parser::symbol_type
  parser::make_LEFT_ASSIGN (const string& v)
  {
    return symbol_type (token::LEFT_ASSIGN, v);
  }

  parser::symbol_type
  parser::make_ADD_ASSIGN (const string& v)
  {
    return symbol_type (token::ADD_ASSIGN, v);
  }

  parser::symbol_type
  parser::make_SUB_ASSIGN (const string& v)
  {
    return symbol_type (token::SUB_ASSIGN, v);
  }

  parser::symbol_type
  parser::make_MUL_ASSIGN (const string& v)
  {
    return symbol_type (token::MUL_ASSIGN, v);
  }

  parser::symbol_type
  parser::make_DIV_ASSIGN (const string& v)
  {
    return symbol_type (token::DIV_ASSIGN, v);
  }

  parser::symbol_type
  parser::make_MOD_ASSIGN (const string& v)
  {
    return symbol_type (token::MOD_ASSIGN, v);
  }

  parser::symbol_type
  parser::make_AND_ASSIGN (const string& v)
  {
    return symbol_type (token::AND_ASSIGN, v);
  }

  parser::symbol_type
  parser::make_XOR_ASSIGN (const string& v)
  {
    return symbol_type (token::XOR_ASSIGN, v);
  }

  parser::symbol_type
  parser::make_OR_ASSIGN (const string& v)
  {
    return symbol_type (token::OR_ASSIGN, v);
  }

  parser::symbol_type
  parser::make_RIGHT_OP (const string& v)
  {
    return symbol_type (token::RIGHT_OP, v);
  }

  parser::symbol_type
  parser::make_LEFT_OP (const string& v)
  {
    return symbol_type (token::LEFT_OP, v);
  }

  parser::symbol_type
  parser::make_INC_OP (const string& v)
  {
    return symbol_type (token::INC_OP, v);
  }

  parser::symbol_type
  parser::make_DEC_OP (const string& v)
  {
    return symbol_type (token::DEC_OP, v);
  }

  parser::symbol_type
  parser::make_PTR_OP (const string& v)
  {
    return symbol_type (token::PTR_OP, v);
  }

  parser::symbol_type
  parser::make_AND_OP (const string& v)
  {
    return symbol_type (token::AND_OP, v);
  }

  parser::symbol_type
  parser::make_OR_OP (const string& v)
  {
    return symbol_type (token::OR_OP, v);
  }

  parser::symbol_type
  parser::make_LE_OP (const string& v)
  {
    return symbol_type (token::LE_OP, v);
  }

  parser::symbol_type
  parser::make_GE_OP (const string& v)
  {
    return symbol_type (token::GE_OP, v);
  }

  parser::symbol_type
  parser::make_EQ_OP (const string& v)
  {
    return symbol_type (token::EQ_OP, v);
  }

  parser::symbol_type
  parser::make_NE_OP (const string& v)
  {
    return symbol_type (token::NE_OP, v);
  }



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 90: // primary_expression
      case 91: // postfix_expression
      case 92: // argument_expression_list
      case 93: // unary_expression
      case 94: // unary_operator
      case 95: // cast_expression
      case 96: // multiplicative_expression
      case 97: // additive_expression
      case 98: // shift_expression
      case 99: // relational_expression
      case 100: // equality_expression
      case 101: // and_expression
      case 102: // exclusive_or_expression
      case 103: // inclusive_or_expression
      case 104: // logical_and_expression
      case 105: // logical_or_expression
      case 106: // conditional_expression
      case 107: // assignment_expression
      case 108: // assignment_operator
      case 109: // expression
      case 110: // constant_expression
      case 111: // declaration
      case 112: // declaration_specifiers
      case 113: // storage_class_specifier
      case 114: // init_declarator_list
      case 115: // init_declarator
      case 116: // initializer
      case 117: // initializer_list
      case 118: // designation
      case 119: // designator_list
      case 120: // designator
      case 121: // declarator
      case 122: // pointer
      case 123: // direct_declarator
      case 124: // type_qualifier_list
      case 125: // type_qualifier
      case 126: // parameter_type_list
      case 127: // parameter_list
      case 128: // parameter_declaration
      case 129: // function_specifier
      case 130: // type_specifier
      case 131: // struct_or_union_specifier
      case 132: // struct_or_union
      case 133: // struct_declaration_list
      case 134: // struct_declaration
      case 135: // struct_declarator_list
      case 136: // struct_declarator
      case 137: // specifier_qualifier_list
      case 138: // enum_specifier
      case 139: // enumerator_list
      case 140: // enumerator
      case 141: // type_name
      case 142: // abstract_declarator
      case 143: // direct_abstract_declarator
      case 144: // statement
      case 145: // labeled_statement
      case 146: // compound_statement
      case 147: // block_item_list
      case 148: // block_item
      case 149: // expression_statement
      case 150: // selection_statement
      case 151: // iteration_statement
      case 152: // jump_statement
      case 153: // translation_unit
      case 154: // external_declaration
      case 155: // function_definition
      case 156: // declaration_list
      case 157: // identifier_list
        value.move< AstNodePtr > (that.value);
        break;

      case 3: // AUTO
      case 4: // BOOL
      case 5: // BREAK
      case 6: // CASE
      case 7: // CHAR
      case 8: // COMPLEX
      case 9: // CONST
      case 10: // CONTINUE
      case 11: // DEFAULT
      case 12: // DO
      case 13: // DOUBLE
      case 14: // ELSE
      case 15: // ENUM
      case 16: // EXTERN
      case 17: // FLOAT
      case 18: // FOR
      case 19: // GOTO
      case 20: // IF
      case 21: // IMAGINARY
      case 22: // INLINE
      case 23: // INT
      case 24: // LONG
      case 25: // REGISTER
      case 26: // RESTRICT
      case 27: // RETURN
      case 28: // SHORT
      case 29: // SIGNED
      case 30: // SIZEOF
      case 31: // STATIC
      case 32: // STRUCT
      case 33: // SWITCH
      case 34: // TYPEDEF
      case 35: // UNION
      case 36: // UNSIGNED
      case 37: // VOID
      case 38: // VOLATILE
      case 39: // WHILE
      case 40: // IDENTIFIER
      case 41: // LITERAL
      case 42: // STRING_LITERAL
      case 43: // ";"
      case 44: // ","
      case 45: // ":"
      case 46: // "("
      case 47: // ")"
      case 48: // "."
      case 49: // "{"
      case 50: // "}"
      case 51: // "["
      case 52: // "]"
      case 53: // "="
      case 54: // "&"
      case 55: // "!"
      case 56: // "~"
      case 57: // "-"
      case 58: // "+"
      case 59: // "*"
      case 60: // "/"
      case 61: // "%"
      case 62: // "<"
      case 63: // ">"
      case 64: // "^"
      case 65: // "|"
      case 66: // "?"
      case 67: // "..."
      case 68: // ">>="
      case 69: // "<<="
      case 70: // "+="
      case 71: // "-="
      case 72: // "*="
      case 73: // "/="
      case 74: // "%="
      case 75: // "&="
      case 76: // "^="
      case 77: // "|="
      case 78: // ">>"
      case 79: // "<<"
      case 80: // "++"
      case 81: // "--"
      case 82: // "->"
      case 83: // "&&"
      case 84: // "||"
      case 85: // "<="
      case 86: // ">="
      case 87: // "=="
      case 88: // "!="
        value.move< string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 90: // primary_expression
      case 91: // postfix_expression
      case 92: // argument_expression_list
      case 93: // unary_expression
      case 94: // unary_operator
      case 95: // cast_expression
      case 96: // multiplicative_expression
      case 97: // additive_expression
      case 98: // shift_expression
      case 99: // relational_expression
      case 100: // equality_expression
      case 101: // and_expression
      case 102: // exclusive_or_expression
      case 103: // inclusive_or_expression
      case 104: // logical_and_expression
      case 105: // logical_or_expression
      case 106: // conditional_expression
      case 107: // assignment_expression
      case 108: // assignment_operator
      case 109: // expression
      case 110: // constant_expression
      case 111: // declaration
      case 112: // declaration_specifiers
      case 113: // storage_class_specifier
      case 114: // init_declarator_list
      case 115: // init_declarator
      case 116: // initializer
      case 117: // initializer_list
      case 118: // designation
      case 119: // designator_list
      case 120: // designator
      case 121: // declarator
      case 122: // pointer
      case 123: // direct_declarator
      case 124: // type_qualifier_list
      case 125: // type_qualifier
      case 126: // parameter_type_list
      case 127: // parameter_list
      case 128: // parameter_declaration
      case 129: // function_specifier
      case 130: // type_specifier
      case 131: // struct_or_union_specifier
      case 132: // struct_or_union
      case 133: // struct_declaration_list
      case 134: // struct_declaration
      case 135: // struct_declarator_list
      case 136: // struct_declarator
      case 137: // specifier_qualifier_list
      case 138: // enum_specifier
      case 139: // enumerator_list
      case 140: // enumerator
      case 141: // type_name
      case 142: // abstract_declarator
      case 143: // direct_abstract_declarator
      case 144: // statement
      case 145: // labeled_statement
      case 146: // compound_statement
      case 147: // block_item_list
      case 148: // block_item
      case 149: // expression_statement
      case 150: // selection_statement
      case 151: // iteration_statement
      case 152: // jump_statement
      case 153: // translation_unit
      case 154: // external_declaration
      case 155: // function_definition
      case 156: // declaration_list
      case 157: // identifier_list
        value.copy< AstNodePtr > (that.value);
        break;

      case 3: // AUTO
      case 4: // BOOL
      case 5: // BREAK
      case 6: // CASE
      case 7: // CHAR
      case 8: // COMPLEX
      case 9: // CONST
      case 10: // CONTINUE
      case 11: // DEFAULT
      case 12: // DO
      case 13: // DOUBLE
      case 14: // ELSE
      case 15: // ENUM
      case 16: // EXTERN
      case 17: // FLOAT
      case 18: // FOR
      case 19: // GOTO
      case 20: // IF
      case 21: // IMAGINARY
      case 22: // INLINE
      case 23: // INT
      case 24: // LONG
      case 25: // REGISTER
      case 26: // RESTRICT
      case 27: // RETURN
      case 28: // SHORT
      case 29: // SIGNED
      case 30: // SIZEOF
      case 31: // STATIC
      case 32: // STRUCT
      case 33: // SWITCH
      case 34: // TYPEDEF
      case 35: // UNION
      case 36: // UNSIGNED
      case 37: // VOID
      case 38: // VOLATILE
      case 39: // WHILE
      case 40: // IDENTIFIER
      case 41: // LITERAL
      case 42: // STRING_LITERAL
      case 43: // ";"
      case 44: // ","
      case 45: // ":"
      case 46: // "("
      case 47: // ")"
      case 48: // "."
      case 49: // "{"
      case 50: // "}"
      case 51: // "["
      case 52: // "]"
      case 53: // "="
      case 54: // "&"
      case 55: // "!"
      case 56: // "~"
      case 57: // "-"
      case 58: // "+"
      case 59: // "*"
      case 60: // "/"
      case 61: // "%"
      case 62: // "<"
      case 63: // ">"
      case 64: // "^"
      case 65: // "|"
      case 66: // "?"
      case 67: // "..."
      case 68: // ">>="
      case 69: // "<<="
      case 70: // "+="
      case 71: // "-="
      case 72: // "*="
      case 73: // "/="
      case 74: // "%="
      case 75: // "&="
      case 76: // "^="
      case 77: // "|="
      case 78: // ">>"
      case 79: // "<<"
      case 80: // "++"
      case 81: // "--"
      case 82: // "->"
      case 83: // "&&"
      case 84: // "||"
      case 85: // "<="
      case 86: // ">="
      case 87: // "=="
      case 88: // "!="
        value.copy< string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    switch (yytype)
    {
            case 3: // AUTO

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 1925 "parser.cc" // lalr1.cc:636
        break;

      case 4: // BOOL

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 1932 "parser.cc" // lalr1.cc:636
        break;

      case 5: // BREAK

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 1939 "parser.cc" // lalr1.cc:636
        break;

      case 6: // CASE

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 1946 "parser.cc" // lalr1.cc:636
        break;

      case 7: // CHAR

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 1953 "parser.cc" // lalr1.cc:636
        break;

      case 8: // COMPLEX

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 1960 "parser.cc" // lalr1.cc:636
        break;

      case 9: // CONST

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 1967 "parser.cc" // lalr1.cc:636
        break;

      case 10: // CONTINUE

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 1974 "parser.cc" // lalr1.cc:636
        break;

      case 11: // DEFAULT

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 1981 "parser.cc" // lalr1.cc:636
        break;

      case 12: // DO

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 1988 "parser.cc" // lalr1.cc:636
        break;

      case 13: // DOUBLE

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 1995 "parser.cc" // lalr1.cc:636
        break;

      case 14: // ELSE

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2002 "parser.cc" // lalr1.cc:636
        break;

      case 15: // ENUM

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2009 "parser.cc" // lalr1.cc:636
        break;

      case 16: // EXTERN

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2016 "parser.cc" // lalr1.cc:636
        break;

      case 17: // FLOAT

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2023 "parser.cc" // lalr1.cc:636
        break;

      case 18: // FOR

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2030 "parser.cc" // lalr1.cc:636
        break;

      case 19: // GOTO

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2037 "parser.cc" // lalr1.cc:636
        break;

      case 20: // IF

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2044 "parser.cc" // lalr1.cc:636
        break;

      case 21: // IMAGINARY

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2051 "parser.cc" // lalr1.cc:636
        break;

      case 22: // INLINE

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2058 "parser.cc" // lalr1.cc:636
        break;

      case 23: // INT

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2065 "parser.cc" // lalr1.cc:636
        break;

      case 24: // LONG

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2072 "parser.cc" // lalr1.cc:636
        break;

      case 25: // REGISTER

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2079 "parser.cc" // lalr1.cc:636
        break;

      case 26: // RESTRICT

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2086 "parser.cc" // lalr1.cc:636
        break;

      case 27: // RETURN

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2093 "parser.cc" // lalr1.cc:636
        break;

      case 28: // SHORT

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2100 "parser.cc" // lalr1.cc:636
        break;

      case 29: // SIGNED

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2107 "parser.cc" // lalr1.cc:636
        break;

      case 30: // SIZEOF

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2114 "parser.cc" // lalr1.cc:636
        break;

      case 31: // STATIC

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2121 "parser.cc" // lalr1.cc:636
        break;

      case 32: // STRUCT

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2128 "parser.cc" // lalr1.cc:636
        break;

      case 33: // SWITCH

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2135 "parser.cc" // lalr1.cc:636
        break;

      case 34: // TYPEDEF

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2142 "parser.cc" // lalr1.cc:636
        break;

      case 35: // UNION

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2149 "parser.cc" // lalr1.cc:636
        break;

      case 36: // UNSIGNED

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2156 "parser.cc" // lalr1.cc:636
        break;

      case 37: // VOID

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2163 "parser.cc" // lalr1.cc:636
        break;

      case 38: // VOLATILE

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2170 "parser.cc" // lalr1.cc:636
        break;

      case 39: // WHILE

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2177 "parser.cc" // lalr1.cc:636
        break;

      case 40: // IDENTIFIER

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2184 "parser.cc" // lalr1.cc:636
        break;

      case 41: // LITERAL

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2191 "parser.cc" // lalr1.cc:636
        break;

      case 42: // STRING_LITERAL

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2198 "parser.cc" // lalr1.cc:636
        break;

      case 43: // ";"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2205 "parser.cc" // lalr1.cc:636
        break;

      case 44: // ","

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2212 "parser.cc" // lalr1.cc:636
        break;

      case 45: // ":"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2219 "parser.cc" // lalr1.cc:636
        break;

      case 46: // "("

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2226 "parser.cc" // lalr1.cc:636
        break;

      case 47: // ")"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2233 "parser.cc" // lalr1.cc:636
        break;

      case 48: // "."

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2240 "parser.cc" // lalr1.cc:636
        break;

      case 49: // "{"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2247 "parser.cc" // lalr1.cc:636
        break;

      case 50: // "}"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2254 "parser.cc" // lalr1.cc:636
        break;

      case 51: // "["

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2261 "parser.cc" // lalr1.cc:636
        break;

      case 52: // "]"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2268 "parser.cc" // lalr1.cc:636
        break;

      case 53: // "="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2275 "parser.cc" // lalr1.cc:636
        break;

      case 54: // "&"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2282 "parser.cc" // lalr1.cc:636
        break;

      case 55: // "!"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2289 "parser.cc" // lalr1.cc:636
        break;

      case 56: // "~"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2296 "parser.cc" // lalr1.cc:636
        break;

      case 57: // "-"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2303 "parser.cc" // lalr1.cc:636
        break;

      case 58: // "+"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2310 "parser.cc" // lalr1.cc:636
        break;

      case 59: // "*"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2317 "parser.cc" // lalr1.cc:636
        break;

      case 60: // "/"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2324 "parser.cc" // lalr1.cc:636
        break;

      case 61: // "%"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2331 "parser.cc" // lalr1.cc:636
        break;

      case 62: // "<"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2338 "parser.cc" // lalr1.cc:636
        break;

      case 63: // ">"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2345 "parser.cc" // lalr1.cc:636
        break;

      case 64: // "^"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2352 "parser.cc" // lalr1.cc:636
        break;

      case 65: // "|"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2359 "parser.cc" // lalr1.cc:636
        break;

      case 66: // "?"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2366 "parser.cc" // lalr1.cc:636
        break;

      case 67: // "..."

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2373 "parser.cc" // lalr1.cc:636
        break;

      case 68: // ">>="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2380 "parser.cc" // lalr1.cc:636
        break;

      case 69: // "<<="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2387 "parser.cc" // lalr1.cc:636
        break;

      case 70: // "+="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2394 "parser.cc" // lalr1.cc:636
        break;

      case 71: // "-="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2401 "parser.cc" // lalr1.cc:636
        break;

      case 72: // "*="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2408 "parser.cc" // lalr1.cc:636
        break;

      case 73: // "/="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2415 "parser.cc" // lalr1.cc:636
        break;

      case 74: // "%="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2422 "parser.cc" // lalr1.cc:636
        break;

      case 75: // "&="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2429 "parser.cc" // lalr1.cc:636
        break;

      case 76: // "^="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2436 "parser.cc" // lalr1.cc:636
        break;

      case 77: // "|="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2443 "parser.cc" // lalr1.cc:636
        break;

      case 78: // ">>"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2450 "parser.cc" // lalr1.cc:636
        break;

      case 79: // "<<"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2457 "parser.cc" // lalr1.cc:636
        break;

      case 80: // "++"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2464 "parser.cc" // lalr1.cc:636
        break;

      case 81: // "--"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2471 "parser.cc" // lalr1.cc:636
        break;

      case 82: // "->"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2478 "parser.cc" // lalr1.cc:636
        break;

      case 83: // "&&"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2485 "parser.cc" // lalr1.cc:636
        break;

      case 84: // "||"

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2492 "parser.cc" // lalr1.cc:636
        break;

      case 85: // "<="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2499 "parser.cc" // lalr1.cc:636
        break;

      case 86: // ">="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2506 "parser.cc" // lalr1.cc:636
        break;

      case 87: // "=="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2513 "parser.cc" // lalr1.cc:636
        break;

      case 88: // "!="

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< string > (); }
#line 2520 "parser.cc" // lalr1.cc:636
        break;

      case 90: // primary_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2527 "parser.cc" // lalr1.cc:636
        break;

      case 91: // postfix_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2534 "parser.cc" // lalr1.cc:636
        break;

      case 92: // argument_expression_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2541 "parser.cc" // lalr1.cc:636
        break;

      case 93: // unary_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2548 "parser.cc" // lalr1.cc:636
        break;

      case 94: // unary_operator

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2555 "parser.cc" // lalr1.cc:636
        break;

      case 95: // cast_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2562 "parser.cc" // lalr1.cc:636
        break;

      case 96: // multiplicative_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2569 "parser.cc" // lalr1.cc:636
        break;

      case 97: // additive_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2576 "parser.cc" // lalr1.cc:636
        break;

      case 98: // shift_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2583 "parser.cc" // lalr1.cc:636
        break;

      case 99: // relational_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2590 "parser.cc" // lalr1.cc:636
        break;

      case 100: // equality_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2597 "parser.cc" // lalr1.cc:636
        break;

      case 101: // and_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2604 "parser.cc" // lalr1.cc:636
        break;

      case 102: // exclusive_or_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2611 "parser.cc" // lalr1.cc:636
        break;

      case 103: // inclusive_or_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2618 "parser.cc" // lalr1.cc:636
        break;

      case 104: // logical_and_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2625 "parser.cc" // lalr1.cc:636
        break;

      case 105: // logical_or_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2632 "parser.cc" // lalr1.cc:636
        break;

      case 106: // conditional_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2639 "parser.cc" // lalr1.cc:636
        break;

      case 107: // assignment_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2646 "parser.cc" // lalr1.cc:636
        break;

      case 108: // assignment_operator

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2653 "parser.cc" // lalr1.cc:636
        break;

      case 109: // expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2660 "parser.cc" // lalr1.cc:636
        break;

      case 110: // constant_expression

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2667 "parser.cc" // lalr1.cc:636
        break;

      case 111: // declaration

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2674 "parser.cc" // lalr1.cc:636
        break;

      case 112: // declaration_specifiers

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2681 "parser.cc" // lalr1.cc:636
        break;

      case 113: // storage_class_specifier

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2688 "parser.cc" // lalr1.cc:636
        break;

      case 114: // init_declarator_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2695 "parser.cc" // lalr1.cc:636
        break;

      case 115: // init_declarator

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2702 "parser.cc" // lalr1.cc:636
        break;

      case 116: // initializer

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2709 "parser.cc" // lalr1.cc:636
        break;

      case 117: // initializer_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2716 "parser.cc" // lalr1.cc:636
        break;

      case 118: // designation

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2723 "parser.cc" // lalr1.cc:636
        break;

      case 119: // designator_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2730 "parser.cc" // lalr1.cc:636
        break;

      case 120: // designator

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2737 "parser.cc" // lalr1.cc:636
        break;

      case 121: // declarator

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2744 "parser.cc" // lalr1.cc:636
        break;

      case 122: // pointer

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2751 "parser.cc" // lalr1.cc:636
        break;

      case 123: // direct_declarator

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2758 "parser.cc" // lalr1.cc:636
        break;

      case 124: // type_qualifier_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2765 "parser.cc" // lalr1.cc:636
        break;

      case 125: // type_qualifier

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2772 "parser.cc" // lalr1.cc:636
        break;

      case 126: // parameter_type_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2779 "parser.cc" // lalr1.cc:636
        break;

      case 127: // parameter_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2786 "parser.cc" // lalr1.cc:636
        break;

      case 128: // parameter_declaration

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2793 "parser.cc" // lalr1.cc:636
        break;

      case 129: // function_specifier

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2800 "parser.cc" // lalr1.cc:636
        break;

      case 130: // type_specifier

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2807 "parser.cc" // lalr1.cc:636
        break;

      case 131: // struct_or_union_specifier

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2814 "parser.cc" // lalr1.cc:636
        break;

      case 132: // struct_or_union

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2821 "parser.cc" // lalr1.cc:636
        break;

      case 133: // struct_declaration_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2828 "parser.cc" // lalr1.cc:636
        break;

      case 134: // struct_declaration

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2835 "parser.cc" // lalr1.cc:636
        break;

      case 135: // struct_declarator_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2842 "parser.cc" // lalr1.cc:636
        break;

      case 136: // struct_declarator

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2849 "parser.cc" // lalr1.cc:636
        break;

      case 137: // specifier_qualifier_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2856 "parser.cc" // lalr1.cc:636
        break;

      case 138: // enum_specifier

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2863 "parser.cc" // lalr1.cc:636
        break;

      case 139: // enumerator_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2870 "parser.cc" // lalr1.cc:636
        break;

      case 140: // enumerator

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2877 "parser.cc" // lalr1.cc:636
        break;

      case 141: // type_name

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2884 "parser.cc" // lalr1.cc:636
        break;

      case 142: // abstract_declarator

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2891 "parser.cc" // lalr1.cc:636
        break;

      case 143: // direct_abstract_declarator

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2898 "parser.cc" // lalr1.cc:636
        break;

      case 144: // statement

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2905 "parser.cc" // lalr1.cc:636
        break;

      case 145: // labeled_statement

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2912 "parser.cc" // lalr1.cc:636
        break;

      case 146: // compound_statement

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2919 "parser.cc" // lalr1.cc:636
        break;

      case 147: // block_item_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2926 "parser.cc" // lalr1.cc:636
        break;

      case 148: // block_item

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2933 "parser.cc" // lalr1.cc:636
        break;

      case 149: // expression_statement

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2940 "parser.cc" // lalr1.cc:636
        break;

      case 150: // selection_statement

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2947 "parser.cc" // lalr1.cc:636
        break;

      case 151: // iteration_statement

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2954 "parser.cc" // lalr1.cc:636
        break;

      case 152: // jump_statement

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2961 "parser.cc" // lalr1.cc:636
        break;

      case 153: // translation_unit

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2968 "parser.cc" // lalr1.cc:636
        break;

      case 154: // external_declaration

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2975 "parser.cc" // lalr1.cc:636
        break;

      case 155: // function_definition

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2982 "parser.cc" // lalr1.cc:636
        break;

      case 156: // declaration_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2989 "parser.cc" // lalr1.cc:636
        break;

      case 157: // identifier_list

#line 188 "parser.yy" // lalr1.cc:636
        { yyo << yysym.value.template as< AstNodePtr > (); }
#line 2996 "parser.cc" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, drv));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 90: // primary_expression
      case 91: // postfix_expression
      case 92: // argument_expression_list
      case 93: // unary_expression
      case 94: // unary_operator
      case 95: // cast_expression
      case 96: // multiplicative_expression
      case 97: // additive_expression
      case 98: // shift_expression
      case 99: // relational_expression
      case 100: // equality_expression
      case 101: // and_expression
      case 102: // exclusive_or_expression
      case 103: // inclusive_or_expression
      case 104: // logical_and_expression
      case 105: // logical_or_expression
      case 106: // conditional_expression
      case 107: // assignment_expression
      case 108: // assignment_operator
      case 109: // expression
      case 110: // constant_expression
      case 111: // declaration
      case 112: // declaration_specifiers
      case 113: // storage_class_specifier
      case 114: // init_declarator_list
      case 115: // init_declarator
      case 116: // initializer
      case 117: // initializer_list
      case 118: // designation
      case 119: // designator_list
      case 120: // designator
      case 121: // declarator
      case 122: // pointer
      case 123: // direct_declarator
      case 124: // type_qualifier_list
      case 125: // type_qualifier
      case 126: // parameter_type_list
      case 127: // parameter_list
      case 128: // parameter_declaration
      case 129: // function_specifier
      case 130: // type_specifier
      case 131: // struct_or_union_specifier
      case 132: // struct_or_union
      case 133: // struct_declaration_list
      case 134: // struct_declaration
      case 135: // struct_declarator_list
      case 136: // struct_declarator
      case 137: // specifier_qualifier_list
      case 138: // enum_specifier
      case 139: // enumerator_list
      case 140: // enumerator
      case 141: // type_name
      case 142: // abstract_declarator
      case 143: // direct_abstract_declarator
      case 144: // statement
      case 145: // labeled_statement
      case 146: // compound_statement
      case 147: // block_item_list
      case 148: // block_item
      case 149: // expression_statement
      case 150: // selection_statement
      case 151: // iteration_statement
      case 152: // jump_statement
      case 153: // translation_unit
      case 154: // external_declaration
      case 155: // function_definition
      case 156: // declaration_list
      case 157: // identifier_list
        yylhs.value.build< AstNodePtr > ();
        break;

      case 3: // AUTO
      case 4: // BOOL
      case 5: // BREAK
      case 6: // CASE
      case 7: // CHAR
      case 8: // COMPLEX
      case 9: // CONST
      case 10: // CONTINUE
      case 11: // DEFAULT
      case 12: // DO
      case 13: // DOUBLE
      case 14: // ELSE
      case 15: // ENUM
      case 16: // EXTERN
      case 17: // FLOAT
      case 18: // FOR
      case 19: // GOTO
      case 20: // IF
      case 21: // IMAGINARY
      case 22: // INLINE
      case 23: // INT
      case 24: // LONG
      case 25: // REGISTER
      case 26: // RESTRICT
      case 27: // RETURN
      case 28: // SHORT
      case 29: // SIGNED
      case 30: // SIZEOF
      case 31: // STATIC
      case 32: // STRUCT
      case 33: // SWITCH
      case 34: // TYPEDEF
      case 35: // UNION
      case 36: // UNSIGNED
      case 37: // VOID
      case 38: // VOLATILE
      case 39: // WHILE
      case 40: // IDENTIFIER
      case 41: // LITERAL
      case 42: // STRING_LITERAL
      case 43: // ";"
      case 44: // ","
      case 45: // ":"
      case 46: // "("
      case 47: // ")"
      case 48: // "."
      case 49: // "{"
      case 50: // "}"
      case 51: // "["
      case 52: // "]"
      case 53: // "="
      case 54: // "&"
      case 55: // "!"
      case 56: // "~"
      case 57: // "-"
      case 58: // "+"
      case 59: // "*"
      case 60: // "/"
      case 61: // "%"
      case 62: // "<"
      case 63: // ">"
      case 64: // "^"
      case 65: // "|"
      case 66: // "?"
      case 67: // "..."
      case 68: // ">>="
      case 69: // "<<="
      case 70: // "+="
      case 71: // "-="
      case 72: // "*="
      case 73: // "/="
      case 74: // "%="
      case 75: // "&="
      case 76: // "^="
      case 77: // "|="
      case 78: // ">>"
      case 79: // "<<"
      case 80: // "++"
      case 81: // "--"
      case 82: // "->"
      case 83: // "&&"
      case 84: // "||"
      case 85: // "<="
      case 86: // ">="
      case 87: // "=="
      case 88: // "!="
        yylhs.value.build< string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 269 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("primary_expression"), { new AstNode(string("identifier_IDENTIFIER"), {}) });}
#line 3367 "parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 270 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("primary_expression"), { new AstNode(string("literal_LITERAL"), {}) });}
#line 3373 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 271 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("primary_expression"), { new AstNode(string("string_literal_STRING_LITERAL"), {}) });}
#line 3379 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 272 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("primary_expression"), { new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}) });}
#line 3385 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 276 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("postfix_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3391 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 277 "parser.yy" // lalr1.cc:859
    {yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[3].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));yylhs.value.as< AstNodePtr > () = yystack_[3].value.as< AstNodePtr > ();}
#line 3397 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 278 "parser.yy" // lalr1.cc:859
    {yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[3].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));yylhs.value.as< AstNodePtr > () = yystack_[3].value.as< AstNodePtr > ();}
#line 3403 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 279 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3409 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 280 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("identifier_IDENTIFIER"), {}));yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3415 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 281 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("identifier_IDENTIFIER"), {}));yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3421 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 282 "parser.yy" // lalr1.cc:859
    {yystack_[1].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[1].value.as< AstNodePtr > ();}
#line 3427 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 283 "parser.yy" // lalr1.cc:859
    {yystack_[1].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[1].value.as< AstNodePtr > ();}
#line 3433 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 284 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("postfix_expression"), { new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[4].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
#line 3439 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 285 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("postfix_expression"), { new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[5].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_COMMA"), {}),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
#line 3445 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 289 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("argument_expression_list"), { new AstNode(string("identifier_IDENTIFIER"), {}) });}
#line 3451 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 290 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("identifier_IDENTIFIER"), {}));yystack_[0].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_COMMA"), {}));yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 3457 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 294 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("unary_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3463 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 295 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("operators_INC_OP"), {}));yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 3469 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 296 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("operators_DEC_OP"), {}));yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 3475 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 297 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("unary_expression"), { yystack_[1].value.as< AstNodePtr > (),yystack_[0].value.as< AstNodePtr > () });}
#line 3481 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 298 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("keywords_SIZEOF"), {}));yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 3487 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 299 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("unary_expression"), { new AstNode(string("keywords_SIZEOF"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}) });}
#line 3493 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 303 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("unary_operator"), { new AstNode(string("operators_AMP"), {}) });}
#line 3499 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 304 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("unary_operator"), { new AstNode(string("operators_STAR"), {}) });}
#line 3505 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 305 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("unary_operator"), { new AstNode(string("operators_PLUS"), {}) });}
#line 3511 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 306 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("unary_operator"), { new AstNode(string("operators_MINUS"), {}) });}
#line 3517 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 307 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("unary_operator"), { new AstNode(string("operators_BIN_NOT_OP"), {}) });}
#line 3523 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 308 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("unary_operator"), { new AstNode(string("operators_LOG_NOT_OP"), {}) });}
#line 3529 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 312 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("cast_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3535 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 313 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_LEFT_PAR"), {}));yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[0].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 3541 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 317 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("multiplicative_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3547 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 318 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3553 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 319 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3559 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 320 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3565 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 324 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("additive_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3571 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 325 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3577 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 326 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3583 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 330 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("shift_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3589 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 331 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3595 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 332 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3601 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 336 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("relational_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3607 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 337 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3613 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 338 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3619 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 339 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3625 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 340 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3631 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 344 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("equality_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3637 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 345 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3643 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 346 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3649 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 350 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("and_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3655 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 351 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3661 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 355 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("exclusive_or_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3667 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 356 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3673 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 360 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("inclusive_or_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3679 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 361 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3685 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 365 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("logical_and_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3691 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 366 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3697 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 370 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("logical_or_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3703 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 371 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3709 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 375 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("conditional_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3715 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 376 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[4].value.as< AstNodePtr > ());yystack_[0].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("operators_TERNARY_OP"), {}));yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[0].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_COLON"), {}));yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 3721 "parser.cc" // lalr1.cc:859
    break;

  case 62:
#line 380 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("assignment_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3727 "parser.cc" // lalr1.cc:859
    break;

  case 63:
#line 381 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 3733 "parser.cc" // lalr1.cc:859
    break;

  case 64:
#line 385 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("assignment_operator"), { new AstNode(string("operators_ASSIGN_OP"), {}) });}
#line 3739 "parser.cc" // lalr1.cc:859
    break;

  case 65:
#line 386 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("assignment_operator"), { new AstNode(string("operators_MUL_ASSIGN"), {}) });}
#line 3745 "parser.cc" // lalr1.cc:859
    break;

  case 66:
#line 387 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("assignment_operator"), { new AstNode(string("operators_DIV_ASSIGN"), {}) });}
#line 3751 "parser.cc" // lalr1.cc:859
    break;

  case 67:
#line 388 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("assignment_operator"), { new AstNode(string("operators_MOD_ASSIGN"), {}) });}
#line 3757 "parser.cc" // lalr1.cc:859
    break;

  case 68:
#line 389 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("assignment_operator"), { new AstNode(string("operators_ADD_ASSIGN"), {}) });}
#line 3763 "parser.cc" // lalr1.cc:859
    break;

  case 69:
#line 390 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("assignment_operator"), { new AstNode(string("operators_SUB_ASSIGN"), {}) });}
#line 3769 "parser.cc" // lalr1.cc:859
    break;

  case 70:
#line 391 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("assignment_operator"), { new AstNode(string("operators_LEFT_ASSIGN"), {}) });}
#line 3775 "parser.cc" // lalr1.cc:859
    break;

  case 71:
#line 392 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("assignment_operator"), { new AstNode(string("operators_RIGHT_ASSIGN"), {}) });}
#line 3781 "parser.cc" // lalr1.cc:859
    break;

  case 72:
#line 393 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("assignment_operator"), { new AstNode(string("operators_AND_ASSIGN"), {}) });}
#line 3787 "parser.cc" // lalr1.cc:859
    break;

  case 73:
#line 394 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("assignment_operator"), { new AstNode(string("operators_XOR_ASSIGN"), {}) });}
#line 3793 "parser.cc" // lalr1.cc:859
    break;

  case 74:
#line 395 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("assignment_operator"), { new AstNode(string("operators_OR_ASSIGN"), {}) });}
#line 3799 "parser.cc" // lalr1.cc:859
    break;

  case 75:
#line 399 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3805 "parser.cc" // lalr1.cc:859
    break;

  case 76:
#line 400 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3811 "parser.cc" // lalr1.cc:859
    break;

  case 77:
#line 404 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("constant_expression"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3817 "parser.cc" // lalr1.cc:859
    break;

  case 78:
#line 408 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("declaration"), { yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_SEMICOLON"), {}) });}
#line 3823 "parser.cc" // lalr1.cc:859
    break;

  case 79:
#line 409 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("declaration"), { yystack_[2].value.as< AstNodePtr > (),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_SEMICOLON"), {}) });}
#line 3829 "parser.cc" // lalr1.cc:859
    break;

  case 80:
#line 413 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("declaration_specifiers"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3835 "parser.cc" // lalr1.cc:859
    break;

  case 81:
#line 414 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 3841 "parser.cc" // lalr1.cc:859
    break;

  case 82:
#line 415 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("declaration_specifiers"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3847 "parser.cc" // lalr1.cc:859
    break;

  case 83:
#line 416 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 3853 "parser.cc" // lalr1.cc:859
    break;

  case 84:
#line 417 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("declaration_specifiers"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3859 "parser.cc" // lalr1.cc:859
    break;

  case 85:
#line 418 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 3865 "parser.cc" // lalr1.cc:859
    break;

  case 86:
#line 419 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("declaration_specifiers"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3871 "parser.cc" // lalr1.cc:859
    break;

  case 87:
#line 420 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 3877 "parser.cc" // lalr1.cc:859
    break;

  case 88:
#line 424 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("storage_class_specifier"), { new AstNode(string("keywords_EXTERN"), {}) });}
#line 3883 "parser.cc" // lalr1.cc:859
    break;

  case 89:
#line 425 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("storage_class_specifier"), { new AstNode(string("keywords_STATIC"), {}) });}
#line 3889 "parser.cc" // lalr1.cc:859
    break;

  case 90:
#line 426 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("storage_class_specifier"), { new AstNode(string("keywords_AUTO"), {}) });}
#line 3895 "parser.cc" // lalr1.cc:859
    break;

  case 91:
#line 427 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("storage_class_specifier"), { new AstNode(string("keywords_REGISTER"), {}) });}
#line 3901 "parser.cc" // lalr1.cc:859
    break;

  case 92:
#line 431 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("init_declarator_list"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3907 "parser.cc" // lalr1.cc:859
    break;

  case 93:
#line 432 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3913 "parser.cc" // lalr1.cc:859
    break;

  case 94:
#line 436 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("init_declarator"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3919 "parser.cc" // lalr1.cc:859
    break;

  case 95:
#line 437 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("init_declarator"), { yystack_[2].value.as< AstNodePtr > (),new AstNode(string("operators_ASSIGN_OP"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 3925 "parser.cc" // lalr1.cc:859
    break;

  case 96:
#line 441 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("initializer"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3931 "parser.cc" // lalr1.cc:859
    break;

  case 97:
#line 442 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("initializer"), { new AstNode(string("delimeters_LEFT_CBRACKET"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
#line 3937 "parser.cc" // lalr1.cc:859
    break;

  case 98:
#line 443 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("initializer"), { new AstNode(string("delimeters_LEFT_CBRACKET"), {}),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_COMMA"), {}),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
#line 3943 "parser.cc" // lalr1.cc:859
    break;

  case 99:
#line 447 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("initializer_list"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3949 "parser.cc" // lalr1.cc:859
    break;

  case 100:
#line 448 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("initializer_list"), { yystack_[1].value.as< AstNodePtr > (),yystack_[0].value.as< AstNodePtr > () });}
#line 3955 "parser.cc" // lalr1.cc:859
    break;

  case 101:
#line 449 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 3961 "parser.cc" // lalr1.cc:859
    break;

  case 102:
#line 450 "parser.yy" // lalr1.cc:859
    {yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[3].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[3].value.as< AstNodePtr > ();}
#line 3967 "parser.cc" // lalr1.cc:859
    break;

  case 103:
#line 454 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("designation"), { yystack_[1].value.as< AstNodePtr > (),new AstNode(string("operators_ASSIGN_OP"), {}) });}
#line 3973 "parser.cc" // lalr1.cc:859
    break;

  case 104:
#line 458 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("designator_list"), { yystack_[0].value.as< AstNodePtr > () });}
#line 3979 "parser.cc" // lalr1.cc:859
    break;

  case 105:
#line 459 "parser.yy" // lalr1.cc:859
    {yystack_[1].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[1].value.as< AstNodePtr > ();}
#line 3985 "parser.cc" // lalr1.cc:859
    break;

  case 106:
#line 463 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("designator"), { new AstNode(string("delimeters_LEFT_BRACKET"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_BRACKET"), {}) });}
#line 3991 "parser.cc" // lalr1.cc:859
    break;

  case 107:
#line 464 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("designator"), { new AstNode(string("delimeters_DOT"), {}),new AstNode(string("identifier_IDENTIFIER"), {}) });}
#line 3997 "parser.cc" // lalr1.cc:859
    break;

  case 108:
#line 468 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("declarator"), { yystack_[1].value.as< AstNodePtr > (),yystack_[0].value.as< AstNodePtr > () });}
#line 4003 "parser.cc" // lalr1.cc:859
    break;

  case 109:
#line 469 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("declarator"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4009 "parser.cc" // lalr1.cc:859
    break;

  case 110:
#line 473 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("pointer"), { new AstNode(string("operators_STAR"), {}) });}
#line 4015 "parser.cc" // lalr1.cc:859
    break;

  case 111:
#line 474 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("pointer"), { new AstNode(string("operators_STAR"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4021 "parser.cc" // lalr1.cc:859
    break;

  case 112:
#line 475 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("operators_STAR"), {}));yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 4027 "parser.cc" // lalr1.cc:859
    break;

  case 113:
#line 476 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("operators_STAR"), {}));yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 4033 "parser.cc" // lalr1.cc:859
    break;

  case 114:
#line 480 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("direct_declarator"), { new AstNode(string("identifier_IDENTIFIER"), {}) });}
#line 4039 "parser.cc" // lalr1.cc:859
    break;

  case 115:
#line 481 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("direct_declarator"), { new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}) });}
#line 4045 "parser.cc" // lalr1.cc:859
    break;

  case 116:
#line 482 "parser.yy" // lalr1.cc:859
    {yystack_[4].value.as< AstNodePtr > ()->children.push_back(yystack_[4].value.as< AstNodePtr > ());yystack_[4].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[4].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[4].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));yylhs.value.as< AstNodePtr > () = yystack_[4].value.as< AstNodePtr > ();}
#line 4051 "parser.cc" // lalr1.cc:859
    break;

  case 117:
#line 483 "parser.yy" // lalr1.cc:859
    {yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[3].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));yylhs.value.as< AstNodePtr > () = yystack_[3].value.as< AstNodePtr > ();}
#line 4057 "parser.cc" // lalr1.cc:859
    break;

  case 118:
#line 484 "parser.yy" // lalr1.cc:859
    {yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[3].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));yylhs.value.as< AstNodePtr > () = yystack_[3].value.as< AstNodePtr > ();}
#line 4063 "parser.cc" // lalr1.cc:859
    break;

  case 119:
#line 485 "parser.yy" // lalr1.cc:859
    {yystack_[5].value.as< AstNodePtr > ()->children.push_back(yystack_[5].value.as< AstNodePtr > ());yystack_[5].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("keywords_STATIC"), {}));yystack_[5].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[5].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[5].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));yylhs.value.as< AstNodePtr > () = yystack_[5].value.as< AstNodePtr > ();}
#line 4069 "parser.cc" // lalr1.cc:859
    break;

  case 120:
#line 486 "parser.yy" // lalr1.cc:859
    {yystack_[5].value.as< AstNodePtr > ()->children.push_back(yystack_[5].value.as< AstNodePtr > ());yystack_[5].value.as< AstNodePtr > ()->children.push_back(yystack_[3].value.as< AstNodePtr > ());yystack_[5].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("keywords_STATIC"), {}));yystack_[5].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[5].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));yylhs.value.as< AstNodePtr > () = yystack_[5].value.as< AstNodePtr > ();}
#line 4075 "parser.cc" // lalr1.cc:859
    break;

  case 121:
#line 487 "parser.yy" // lalr1.cc:859
    {yystack_[4].value.as< AstNodePtr > ()->children.push_back(yystack_[4].value.as< AstNodePtr > ());yystack_[4].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[4].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("operators_STAR"), {}));yystack_[4].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));yylhs.value.as< AstNodePtr > () = yystack_[4].value.as< AstNodePtr > ();}
#line 4081 "parser.cc" // lalr1.cc:859
    break;

  case 122:
#line 488 "parser.yy" // lalr1.cc:859
    {yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[3].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("operators_STAR"), {}));yystack_[3].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));yylhs.value.as< AstNodePtr > () = yystack_[3].value.as< AstNodePtr > ();}
#line 4087 "parser.cc" // lalr1.cc:859
    break;

  case 123:
#line 489 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 4093 "parser.cc" // lalr1.cc:859
    break;

  case 124:
#line 490 "parser.yy" // lalr1.cc:859
    {yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[3].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));yylhs.value.as< AstNodePtr > () = yystack_[3].value.as< AstNodePtr > ();}
#line 4099 "parser.cc" // lalr1.cc:859
    break;

  case 125:
#line 491 "parser.yy" // lalr1.cc:859
    {yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[3].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));yylhs.value.as< AstNodePtr > () = yystack_[3].value.as< AstNodePtr > ();}
#line 4105 "parser.cc" // lalr1.cc:859
    break;

  case 126:
#line 492 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 4111 "parser.cc" // lalr1.cc:859
    break;

  case 127:
#line 496 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_qualifier_list"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4117 "parser.cc" // lalr1.cc:859
    break;

  case 128:
#line 497 "parser.yy" // lalr1.cc:859
    {yystack_[1].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[1].value.as< AstNodePtr > ();}
#line 4123 "parser.cc" // lalr1.cc:859
    break;

  case 129:
#line 501 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_qualifier"), { new AstNode(string("keywords_CONST"), {}) });}
#line 4129 "parser.cc" // lalr1.cc:859
    break;

  case 130:
#line 502 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_qualifier"), { new AstNode(string("keywords_RESTRICT"), {}) });}
#line 4135 "parser.cc" // lalr1.cc:859
    break;

  case 131:
#line 503 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_qualifier"), { new AstNode(string("keywords_VOLATILE"), {}) });}
#line 4141 "parser.cc" // lalr1.cc:859
    break;

  case 132:
#line 507 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("parameter_type_list"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4147 "parser.cc" // lalr1.cc:859
    break;

  case 133:
#line 508 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("parameter_type_list"), { yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_COMMA"), {}),new AstNode(string("operators_ELLIPSIS"), {}) });}
#line 4153 "parser.cc" // lalr1.cc:859
    break;

  case 134:
#line 512 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("parameter_list"), { yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_SEMICOLON"), {}) });}
#line 4159 "parser.cc" // lalr1.cc:859
    break;

  case 135:
#line 513 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 4165 "parser.cc" // lalr1.cc:859
    break;

  case 136:
#line 517 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("parameter_declaration"), { yystack_[1].value.as< AstNodePtr > (),yystack_[0].value.as< AstNodePtr > () });}
#line 4171 "parser.cc" // lalr1.cc:859
    break;

  case 137:
#line 518 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("parameter_declaration"), { yystack_[1].value.as< AstNodePtr > (),yystack_[0].value.as< AstNodePtr > () });}
#line 4177 "parser.cc" // lalr1.cc:859
    break;

  case 138:
#line 519 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("parameter_declaration"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4183 "parser.cc" // lalr1.cc:859
    break;

  case 139:
#line 523 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("function_specifier"), { new AstNode(string("keywords_INLINE"), {}) });}
#line 4189 "parser.cc" // lalr1.cc:859
    break;

  case 140:
#line 527 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { new AstNode(string("keywords_VOID"), {}) });}
#line 4195 "parser.cc" // lalr1.cc:859
    break;

  case 141:
#line 528 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { new AstNode(string("keywords_CHAR"), {}) });}
#line 4201 "parser.cc" // lalr1.cc:859
    break;

  case 142:
#line 529 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { new AstNode(string("keywords_SHORT"), {}) });}
#line 4207 "parser.cc" // lalr1.cc:859
    break;

  case 143:
#line 530 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { new AstNode(string("keywords_INT"), {}) });}
#line 4213 "parser.cc" // lalr1.cc:859
    break;

  case 144:
#line 531 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { new AstNode(string("keywords_LONG"), {}) });}
#line 4219 "parser.cc" // lalr1.cc:859
    break;

  case 145:
#line 532 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { new AstNode(string("keywords_FLOAT"), {}) });}
#line 4225 "parser.cc" // lalr1.cc:859
    break;

  case 146:
#line 533 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { new AstNode(string("keywords_DOUBLE"), {}) });}
#line 4231 "parser.cc" // lalr1.cc:859
    break;

  case 147:
#line 534 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { new AstNode(string("keywords_SIGNED"), {}) });}
#line 4237 "parser.cc" // lalr1.cc:859
    break;

  case 148:
#line 535 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { new AstNode(string("keywords_UNSIGNED"), {}) });}
#line 4243 "parser.cc" // lalr1.cc:859
    break;

  case 149:
#line 536 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { new AstNode(string("keywords_BOOL"), {}) });}
#line 4249 "parser.cc" // lalr1.cc:859
    break;

  case 150:
#line 537 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { new AstNode(string("keywords_COMPLEX"), {}) });}
#line 4255 "parser.cc" // lalr1.cc:859
    break;

  case 151:
#line 538 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { new AstNode(string("keywords_IMAGINARY"), {}) });}
#line 4261 "parser.cc" // lalr1.cc:859
    break;

  case 152:
#line 539 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4267 "parser.cc" // lalr1.cc:859
    break;

  case 153:
#line 540 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4273 "parser.cc" // lalr1.cc:859
    break;

  case 154:
#line 541 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_specifier"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4279 "parser.cc" // lalr1.cc:859
    break;

  case 155:
#line 545 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("struct_or_union_specifier"), { yystack_[4].value.as< AstNodePtr > (),new AstNode(string("identifier_IDENTIFIER"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
#line 4285 "parser.cc" // lalr1.cc:859
    break;

  case 156:
#line 546 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("struct_or_union_specifier"), { yystack_[3].value.as< AstNodePtr > (),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
#line 4291 "parser.cc" // lalr1.cc:859
    break;

  case 157:
#line 547 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("struct_or_union_specifier"), { yystack_[1].value.as< AstNodePtr > (),new AstNode(string("identifier_IDENTIFIER"), {}) });}
#line 4297 "parser.cc" // lalr1.cc:859
    break;

  case 158:
#line 551 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("struct_or_union"), { new AstNode(string("keywords_STRUCT"), {}) });}
#line 4303 "parser.cc" // lalr1.cc:859
    break;

  case 159:
#line 552 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("struct_or_union"), { new AstNode(string("keywords_UNION"), {}) });}
#line 4309 "parser.cc" // lalr1.cc:859
    break;

  case 160:
#line 556 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("struct_declaration_list"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4315 "parser.cc" // lalr1.cc:859
    break;

  case 161:
#line 557 "parser.yy" // lalr1.cc:859
    {yystack_[1].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[1].value.as< AstNodePtr > ();}
#line 4321 "parser.cc" // lalr1.cc:859
    break;

  case 162:
#line 561 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("struct_declaration"), { yystack_[2].value.as< AstNodePtr > (),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_SEMICOLON"), {}) });}
#line 4327 "parser.cc" // lalr1.cc:859
    break;

  case 163:
#line 565 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("struct_declarator_list"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4333 "parser.cc" // lalr1.cc:859
    break;

  case 164:
#line 566 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 4339 "parser.cc" // lalr1.cc:859
    break;

  case 165:
#line 570 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("struct_declarator"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4345 "parser.cc" // lalr1.cc:859
    break;

  case 166:
#line 571 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("struct_declarator"), { new AstNode(string("delimeters_COLON"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4351 "parser.cc" // lalr1.cc:859
    break;

  case 167:
#line 572 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("struct_declarator"), { yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_COLON"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4357 "parser.cc" // lalr1.cc:859
    break;

  case 168:
#line 576 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 4363 "parser.cc" // lalr1.cc:859
    break;

  case 169:
#line 577 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("specifier_qualifier_list"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4369 "parser.cc" // lalr1.cc:859
    break;

  case 170:
#line 578 "parser.yy" // lalr1.cc:859
    {yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[0].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[0].value.as< AstNodePtr > ();}
#line 4375 "parser.cc" // lalr1.cc:859
    break;

  case 171:
#line 579 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("specifier_qualifier_list"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4381 "parser.cc" // lalr1.cc:859
    break;

  case 172:
#line 583 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("enum_specifier"), { new AstNode(string("keywords_ENUM"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
#line 4387 "parser.cc" // lalr1.cc:859
    break;

  case 173:
#line 584 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("enum_specifier"), { new AstNode(string("keywords_ENUM"), {}),new AstNode(string("identifier_IDENTIFIER"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
#line 4393 "parser.cc" // lalr1.cc:859
    break;

  case 174:
#line 585 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("enum_specifier"), { new AstNode(string("keywords_ENUM"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_COMMA"), {}),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
#line 4399 "parser.cc" // lalr1.cc:859
    break;

  case 175:
#line 586 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("enum_specifier"), { new AstNode(string("keywords_ENUM"), {}),new AstNode(string("identifier_IDENTIFIER"), {}),new AstNode(string("delimeters_LEFT_CBRACKET"), {}),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_COMMA"), {}),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
#line 4405 "parser.cc" // lalr1.cc:859
    break;

  case 176:
#line 587 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("enum_specifier"), { new AstNode(string("keywords_ENUM"), {}),new AstNode(string("identifier_IDENTIFIER"), {}) });}
#line 4411 "parser.cc" // lalr1.cc:859
    break;

  case 177:
#line 591 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("enumerator_list"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4417 "parser.cc" // lalr1.cc:859
    break;

  case 178:
#line 592 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[0].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 4423 "parser.cc" // lalr1.cc:859
    break;

  case 179:
#line 596 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("enumerator"), { new AstNode(string("identifier_IDENTIFIER"), {}) });}
#line 4429 "parser.cc" // lalr1.cc:859
    break;

  case 180:
#line 597 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("enumerator"), { new AstNode(string("identifier_IDENTIFIER"), {}),new AstNode(string("operators_ASSIGN_OP"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4435 "parser.cc" // lalr1.cc:859
    break;

  case 181:
#line 601 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_name"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4441 "parser.cc" // lalr1.cc:859
    break;

  case 182:
#line 602 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("type_name"), { yystack_[1].value.as< AstNodePtr > (),yystack_[0].value.as< AstNodePtr > () });}
#line 4447 "parser.cc" // lalr1.cc:859
    break;

  case 183:
#line 606 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("abstract_declarator"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4453 "parser.cc" // lalr1.cc:859
    break;

  case 184:
#line 607 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("abstract_declarator"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4459 "parser.cc" // lalr1.cc:859
    break;

  case 185:
#line 608 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("abstract_declarator"), { yystack_[1].value.as< AstNodePtr > (),yystack_[0].value.as< AstNodePtr > () });}
#line 4465 "parser.cc" // lalr1.cc:859
    break;

  case 186:
#line 612 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("direct_abstract_declarator"), { new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}) });}
#line 4471 "parser.cc" // lalr1.cc:859
    break;

  case 187:
#line 613 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("direct_abstract_declarator"), { new AstNode(string("delimeters_LEFT_BRACKET"), {}),new AstNode(string("delimeters_RIGHT_BRACKET"), {}) });}
#line 4477 "parser.cc" // lalr1.cc:859
    break;

  case 188:
#line 614 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("direct_abstract_declarator"), { new AstNode(string("delimeters_LEFT_BRACKET"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_BRACKET"), {}) });}
#line 4483 "parser.cc" // lalr1.cc:859
    break;

  case 189:
#line 615 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 4489 "parser.cc" // lalr1.cc:859
    break;

  case 190:
#line 616 "parser.yy" // lalr1.cc:859
    {yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[3].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));yylhs.value.as< AstNodePtr > () = yystack_[3].value.as< AstNodePtr > ();}
#line 4495 "parser.cc" // lalr1.cc:859
    break;

  case 191:
#line 617 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("direct_abstract_declarator"), { new AstNode(string("delimeters_LEFT_BRACKET"), {}),new AstNode(string("operators_STAR"), {}),new AstNode(string("delimeters_RIGHT_BRACKET"), {}) });}
#line 4501 "parser.cc" // lalr1.cc:859
    break;

  case 192:
#line 618 "parser.yy" // lalr1.cc:859
    {yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[3].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("operators_STAR"), {}));yystack_[3].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_BRACKET"), {}));yylhs.value.as< AstNodePtr > () = yystack_[3].value.as< AstNodePtr > ();}
#line 4507 "parser.cc" // lalr1.cc:859
    break;

  case 193:
#line 619 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("direct_abstract_declarator"), { new AstNode(string("delimeters_LEFT_PAR"), {}),new AstNode(string("delimeters_RIGHT_PAR"), {}) });}
#line 4513 "parser.cc" // lalr1.cc:859
    break;

  case 194:
#line 620 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("direct_abstract_declarator"), { new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}) });}
#line 4519 "parser.cc" // lalr1.cc:859
    break;

  case 195:
#line 621 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 4525 "parser.cc" // lalr1.cc:859
    break;

  case 196:
#line 622 "parser.yy" // lalr1.cc:859
    {yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[3].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yystack_[3].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("delimeters_RIGHT_PAR"), {}));yylhs.value.as< AstNodePtr > () = yystack_[3].value.as< AstNodePtr > ();}
#line 4531 "parser.cc" // lalr1.cc:859
    break;

  case 197:
#line 626 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("statement"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4537 "parser.cc" // lalr1.cc:859
    break;

  case 198:
#line 627 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("statement"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4543 "parser.cc" // lalr1.cc:859
    break;

  case 199:
#line 628 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("statement"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4549 "parser.cc" // lalr1.cc:859
    break;

  case 200:
#line 629 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("statement"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4555 "parser.cc" // lalr1.cc:859
    break;

  case 201:
#line 630 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("statement"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4561 "parser.cc" // lalr1.cc:859
    break;

  case 202:
#line 631 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("statement"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4567 "parser.cc" // lalr1.cc:859
    break;

  case 203:
#line 635 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("labeled_statement"), { new AstNode(string("identifier_IDENTIFIER"), {}),new AstNode(string("delimeters_COLON"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4573 "parser.cc" // lalr1.cc:859
    break;

  case 204:
#line 636 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("labeled_statement"), { new AstNode(string("keywords_CASE"), {}),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_COLON"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4579 "parser.cc" // lalr1.cc:859
    break;

  case 205:
#line 637 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("labeled_statement"), { new AstNode(string("keywords_DEFAULT"), {}),new AstNode(string("delimeters_COLON"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4585 "parser.cc" // lalr1.cc:859
    break;

  case 206:
#line 641 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("compound_statement"), { new AstNode(string("delimeters_LEFT_CBRACKET"), {}),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
#line 4591 "parser.cc" // lalr1.cc:859
    break;

  case 207:
#line 642 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("compound_statement"), { new AstNode(string("delimeters_LEFT_CBRACKET"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_CBRACKET"), {}) });}
#line 4597 "parser.cc" // lalr1.cc:859
    break;

  case 208:
#line 646 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("block_item_list"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4603 "parser.cc" // lalr1.cc:859
    break;

  case 209:
#line 647 "parser.yy" // lalr1.cc:859
    {yystack_[1].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[1].value.as< AstNodePtr > ();}
#line 4609 "parser.cc" // lalr1.cc:859
    break;

  case 210:
#line 651 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("block_item"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4615 "parser.cc" // lalr1.cc:859
    break;

  case 211:
#line 652 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("block_item"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4621 "parser.cc" // lalr1.cc:859
    break;

  case 212:
#line 656 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("expression_statement"), { new AstNode(string("delimeters_SEMICOLON"), {}) });}
#line 4627 "parser.cc" // lalr1.cc:859
    break;

  case 213:
#line 657 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("expression_statement"), { yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_SEMICOLON"), {}) });}
#line 4633 "parser.cc" // lalr1.cc:859
    break;

  case 214:
#line 661 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("selection_statement"), { new AstNode(string("keywords_IF"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4639 "parser.cc" // lalr1.cc:859
    break;

  case 215:
#line 662 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("selection_statement"), { new AstNode(string("keywords_IF"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[4].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("keywords_ELSE"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4645 "parser.cc" // lalr1.cc:859
    break;

  case 216:
#line 663 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("selection_statement"), { new AstNode(string("keywords_SWITCH"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4651 "parser.cc" // lalr1.cc:859
    break;

  case 217:
#line 667 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("iteration_statement"), { new AstNode(string("keywords_WHILE"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4657 "parser.cc" // lalr1.cc:859
    break;

  case 218:
#line 668 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("iteration_statement"), { new AstNode(string("keywords_DO"), {}),yystack_[5].value.as< AstNodePtr > (),new AstNode(string("keywords_WHILE"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}),new AstNode(string("delimeters_SEMICOLON"), {}) });}
#line 4663 "parser.cc" // lalr1.cc:859
    break;

  case 219:
#line 669 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("iteration_statement"), { new AstNode(string("keywords_FOR"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[3].value.as< AstNodePtr > (),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4669 "parser.cc" // lalr1.cc:859
    break;

  case 220:
#line 670 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("iteration_statement"), { new AstNode(string("keywords_FOR"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[4].value.as< AstNodePtr > (),yystack_[3].value.as< AstNodePtr > (),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4675 "parser.cc" // lalr1.cc:859
    break;

  case 221:
#line 671 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("iteration_statement"), { new AstNode(string("keywords_FOR"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[3].value.as< AstNodePtr > (),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4681 "parser.cc" // lalr1.cc:859
    break;

  case 222:
#line 672 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("iteration_statement"), { new AstNode(string("keywords_FOR"), {}),new AstNode(string("delimeters_LEFT_PAR"), {}),yystack_[4].value.as< AstNodePtr > (),yystack_[3].value.as< AstNodePtr > (),yystack_[2].value.as< AstNodePtr > (),new AstNode(string("delimeters_RIGHT_PAR"), {}),yystack_[0].value.as< AstNodePtr > () });}
#line 4687 "parser.cc" // lalr1.cc:859
    break;

  case 223:
#line 676 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("jump_statement"), { new AstNode(string("keywords_GOTO"), {}),new AstNode(string("identifier_IDENTIFIER"), {}),new AstNode(string("delimeters_SEMICOLON"), {}) });}
#line 4693 "parser.cc" // lalr1.cc:859
    break;

  case 224:
#line 677 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("jump_statement"), { new AstNode(string("keywords_CONTINUE"), {}),new AstNode(string("delimeters_SEMICOLON"), {}) });}
#line 4699 "parser.cc" // lalr1.cc:859
    break;

  case 225:
#line 678 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("jump_statement"), { new AstNode(string("keywords_BREAK"), {}),new AstNode(string("delimeters_SEMICOLON"), {}) });}
#line 4705 "parser.cc" // lalr1.cc:859
    break;

  case 226:
#line 679 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("jump_statement"), { new AstNode(string("keywords_RETURN"), {}),new AstNode(string("delimeters_SEMICOLON"), {}) });}
#line 4711 "parser.cc" // lalr1.cc:859
    break;

  case 227:
#line 680 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("jump_statement"), { new AstNode(string("keywords_RETURN"), {}),yystack_[1].value.as< AstNodePtr > (),new AstNode(string("delimeters_SEMICOLON"), {}) });}
#line 4717 "parser.cc" // lalr1.cc:859
    break;

  case 228:
#line 684 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("translation_unit"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4723 "parser.cc" // lalr1.cc:859
    break;

  case 229:
#line 685 "parser.yy" // lalr1.cc:859
    {yystack_[1].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[1].value.as< AstNodePtr > ();}
#line 4729 "parser.cc" // lalr1.cc:859
    break;

  case 230:
#line 689 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("external_declaration"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4735 "parser.cc" // lalr1.cc:859
    break;

  case 231:
#line 690 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("external_declaration"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4741 "parser.cc" // lalr1.cc:859
    break;

  case 232:
#line 694 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("function_definition"), { yystack_[3].value.as< AstNodePtr > (),yystack_[2].value.as< AstNodePtr > (),yystack_[1].value.as< AstNodePtr > (),yystack_[0].value.as< AstNodePtr > () });}
#line 4747 "parser.cc" // lalr1.cc:859
    break;

  case 233:
#line 695 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("function_definition"), { yystack_[2].value.as< AstNodePtr > (),yystack_[1].value.as< AstNodePtr > (),yystack_[0].value.as< AstNodePtr > () });}
#line 4753 "parser.cc" // lalr1.cc:859
    break;

  case 234:
#line 699 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("declaration_list"), { yystack_[0].value.as< AstNodePtr > () });}
#line 4759 "parser.cc" // lalr1.cc:859
    break;

  case 235:
#line 700 "parser.yy" // lalr1.cc:859
    {yystack_[1].value.as< AstNodePtr > ()->children.push_back(yystack_[1].value.as< AstNodePtr > ());yylhs.value.as< AstNodePtr > () = yystack_[1].value.as< AstNodePtr > ();}
#line 4765 "parser.cc" // lalr1.cc:859
    break;

  case 236:
#line 704 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< AstNodePtr > () = new AstNode(string("identifier_list"), { new AstNode(string("identifier_IDENTIFIER"), {}) });}
#line 4771 "parser.cc" // lalr1.cc:859
    break;

  case 237:
#line 705 "parser.yy" // lalr1.cc:859
    {yystack_[2].value.as< AstNodePtr > ()->children.push_back(yystack_[2].value.as< AstNodePtr > ());yystack_[2].value.as< AstNodePtr > ()->children.push_back(new AstNode(string("identifier_IDENTIFIER"), {}));yylhs.value.as< AstNodePtr > () = yystack_[2].value.as< AstNodePtr > ();}
#line 4777 "parser.cc" // lalr1.cc:859
    break;


#line 4781 "parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const short int parser::yypact_ninf_ = -321;

  const signed char parser::yytable_ninf_ = -1;

  const short int
  parser::yypact_[] =
  {
    1488,  -321,  -321,  -321,  -321,  -321,  -321,     4,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,   191,  1488,  1488,  1488,  1488,
    -321,    35,   109,  -321,  -321,  1452,  -321,  -321,   -31,    -1,
    -321,  -321,     9,    65,    79,  -321,  1224,   123,    62,  -321,
    -321,   109,  -321,  -321,   109,    -6,  1523,   818,   922,   120,
    -321,   232,  -321,  -321,    -1,     6,   142,  -321,    26,  -321,
      65,  -321,  -321,     9,   343,   206,  -321,   191,  -321,  1263,
      62,  1370,   635,  1523,  1523,  1523,  1298,  -321,   173,  -321,
      -9,    49,    66,    69,   100,  1111,  -321,  -321,  -321,   544,
    -321,  -321,  -321,  -321,  -321,  -321,   110,  1131,  1131,  -321,
      47,   249,  1163,  -321,   234,   253,   309,   144,   240,   140,
     137,    99,   122,    10,  -321,   181,   232,  1411,   954,   158,
    1163,   -21,  -321,  -321,  -321,  -321,  -321,   189,   213,  1163,
     239,   221,   599,   243,   259,   255,   974,   298,   311,   297,
    -321,  -321,  -321,  -321,   347,  -321,  -321,  -321,  -321,   422,
    -321,  -321,  -321,  -321,  -321,   902,  -321,  -321,  -321,  -321,
    -321,  -321,   330,    39,    19,  -321,   344,   357,   679,  1334,
    -321,  -321,  1163,   777,   369,   198,   351,  -321,  -321,  -321,
    -321,   740,  -321,  -321,   544,  -321,   170,   368,  -321,   544,
    -321,  -321,    45,   376,  1163,  -321,  -321,   377,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  1163,
    -321,  -321,  1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,
    1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,
    1163,  -321,  -321,   371,  -321,   367,   370,   -10,  -321,  -321,
    -321,  -321,  -321,  -321,   375,  -321,   599,   382,   483,   393,
    1163,  -321,   360,  1163,  1163,   599,  -321,  1163,  -321,  -321,
     416,  1163,  -321,   227,   206,   192,  -321,  -321,   426,  -321,
     250,  -321,  -321,  1163,  -321,   415,   417,  -321,  -321,  1163,
    -321,   153,  -321,  -321,   423,  -321,  1007,   427,   429,  -321,
     428,  -321,   107,  -321,  -321,  -321,  -321,  -321,   234,   234,
     253,   253,   309,   309,   309,   309,   144,   144,   240,   140,
     137,    99,   361,   122,  -321,  -321,  -321,  -321,   599,  -321,
     436,  1027,  1027,  -321,   223,  -321,   256,   268,  -321,  -321,
    -321,   431,   830,  -321,  -321,  -321,  -321,  -321,   432,   433,
    -321,  -321,  -321,  -321,   439,   902,  -321,   439,   449,  -321,
    -321,  1163,  -321,  1163,  1059,  1079,   599,   599,   599,  -321,
    -321,  -321,   206,  -321,  -321,   235,  -321,  -321,   292,   599,
     294,   599,   296,   479,  -321,  -321,  -321,   866,  -321,   451,
    -321,   599,  -321,   599,   599,  -321,  -321,  -321,  -321,  -321
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    90,   149,   141,   150,   129,   146,     0,    88,   145,
     151,   139,   143,   144,    91,   130,   142,   147,    89,   158,
     159,   148,   140,   131,   231,     0,    80,    84,    86,    82,
     152,     0,   181,   153,   154,     0,   228,   230,   176,     0,
     114,    78,     0,   110,     0,    92,    94,     0,   109,    81,
      85,   170,    87,    83,   168,   157,     0,     0,     0,   183,
     182,   184,     1,   229,     0,   179,     0,   177,     0,   112,
     111,   127,    79,     0,     0,     0,   234,     0,   233,     0,
     108,     0,     0,     0,   171,   169,     0,   160,   181,   193,
     138,     0,   132,     0,     0,     0,     2,     3,     4,     0,
     187,    24,    29,    28,    27,    26,    25,     0,     0,     6,
      18,    30,     0,    32,    36,    39,    42,    47,    50,    52,
      54,    56,    58,    60,    62,     0,   185,     0,     0,     0,
       0,     0,   172,   115,   113,   128,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
     212,   206,    25,    75,     0,   210,   211,   197,   198,     0,
     208,   199,   200,   201,   202,     0,    96,    95,   235,   232,
     236,   126,     0,     0,     0,   123,    25,     0,     0,     0,
     156,   161,     0,     0,   165,   183,     0,   163,   136,   137,
     194,     0,   134,   186,     0,    22,     0,   154,   191,     0,
      19,    20,     0,     0,     0,    12,    13,     0,    64,    71,
      70,    68,    69,    65,    66,    67,    72,    73,    74,     0,
      30,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   195,     0,   189,    25,     0,     0,   173,    77,
     180,   174,   178,   225,     0,   224,     0,     0,     0,     0,
       0,   226,     0,     0,     0,     0,   213,     0,   207,   209,
       0,     0,    99,     0,     0,     0,   104,   124,     0,   125,
       0,   122,   118,     0,   117,    25,     0,   155,   166,     0,
     162,     0,   133,   135,   154,     5,     0,   154,    16,     9,
       0,    10,     0,    11,    63,    33,    34,    35,    38,    37,
      41,    40,    44,    43,    45,    46,    48,    49,    51,    53,
      55,    57,     0,    59,   196,   192,   190,   175,     0,   205,
       0,     0,     0,   223,     0,   227,     0,     0,   203,    76,
     107,     0,     0,    97,   100,   103,   105,   237,     0,     0,
     121,   116,   167,   164,    23,     0,    31,     0,     0,     8,
       7,     0,   204,     0,     0,     0,     0,     0,     0,   106,
      98,   101,     0,   119,   120,     0,    17,    61,     0,     0,
       0,     0,     0,   214,   216,   217,   102,     0,    14,     0,
     221,     0,   219,     0,     0,    15,   218,   222,   220,   215
  };

  const short int
  parser::yypgoto_[] =
  {
    -321,  -321,  -321,   139,   -92,  -321,  -105,   182,   183,   103,
     179,   260,   265,   273,   278,   277,  -321,  -104,   -58,  -321,
     -90,   -93,   -38,   154,  -321,  -321,   454,   -74,   167,  -320,
    -321,   257,   -19,   133,   -35,   -69,   -22,   -76,  -321,   337,
    -321,    16,  -321,  -321,   447,   -82,  -321,   242,    -4,  -321,
     467,  -121,   -88,   -25,   -32,  -140,  -321,   -13,  -321,   384,
    -244,  -321,  -321,  -321,  -321,   499,  -321,  -321,  -321
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,   109,   110,   300,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   153,   219,
     154,   250,    24,    77,    26,    44,    45,   272,   273,   274,
     275,   276,    68,    47,    48,    70,    27,    91,    92,    93,
      28,    29,    30,    31,    86,    87,   186,   187,    32,    33,
      66,    67,    34,    60,    61,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    35,    36,    37,    79,   173
  };

  const unsigned short int
  parser::yytable_[] =
  {
     125,   167,   257,   195,   181,   172,    46,   221,    76,   196,
     252,   197,    80,   178,   332,   200,   201,   166,    64,    65,
     220,    71,   372,    51,   177,    54,   249,   126,     5,   251,
      65,    40,    94,    78,    84,   249,   155,   183,   220,    65,
     327,   168,    58,    83,    38,    15,   254,   220,   135,    40,
      43,   243,    88,    39,   137,    42,   262,    23,   137,   130,
      71,    84,    84,    84,    84,   189,   169,   372,    43,   184,
     246,   188,    85,   133,     5,    55,   239,    84,   249,    88,
      51,    54,    88,   278,    56,   298,   279,   364,   365,   288,
     220,    15,   299,   202,   240,   203,   190,   181,   204,    85,
      85,    85,    85,    23,   196,   280,   294,   166,    81,   196,
     191,   297,   192,    82,   302,    85,   329,   305,   306,   307,
     286,   155,    72,    73,    43,   338,   252,   205,   206,   207,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   193,   220,   322,
      80,   267,    71,   126,    25,    57,   135,    84,    94,   360,
      58,   304,   198,    40,   237,    59,    57,   249,    43,    42,
     334,    58,    84,   336,   337,    88,    69,    84,   341,   220,
      49,    50,    52,    53,    59,   249,   131,    59,   362,    25,
      59,   356,   132,    40,   235,    85,   352,   220,   182,    42,
     344,   236,   247,   134,   220,   238,   229,   230,   248,   339,
      85,    90,    43,    40,   267,    85,   166,   295,   182,   183,
     331,   185,   348,   185,    58,   349,   383,   384,   385,   231,
     232,    40,    43,   241,    41,    90,    95,    42,    40,   390,
     270,   392,    75,   271,   183,   345,    96,    97,    98,    58,
      43,   397,    99,   398,   399,   165,   253,   377,   135,     5,
     101,   102,   103,   104,   105,   152,   256,   267,   371,   220,
     366,   342,   184,   378,   380,   382,    15,   343,   127,   387,
      95,    90,   255,   128,   166,   388,   107,   108,    23,   258,
      96,    97,    98,   222,   223,   224,    99,   166,   386,   259,
     267,   260,   208,   367,   101,   102,   103,   104,   105,   152,
     225,   226,   267,   371,   166,   368,   185,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   233,   234,   166,
     107,   108,   312,   313,   314,   315,   267,    90,   267,   389,
     267,   391,   265,   393,   263,    90,     1,     2,   138,   139,
       3,     4,     5,   140,   141,   142,     6,   264,     7,     8,
       9,   143,   144,   145,    10,    11,    12,    13,    14,    15,
     146,    16,    17,    95,    18,    19,   147,   277,    20,    21,
      22,    23,   148,   149,    97,    98,   150,   227,   228,    99,
     266,   267,    74,   151,   290,   291,   281,   101,   102,   103,
     104,   105,   152,   335,   267,   267,   361,   308,   309,   282,
     310,   311,   316,   317,   289,   296,   301,   303,   324,   325,
     328,   330,   326,   107,   108,     1,     2,   138,   139,     3,
       4,     5,   140,   141,   142,     6,   333,     7,     8,     9,
     143,   144,   145,    10,    11,    12,    13,    14,    15,   146,
      16,    17,    95,    18,    19,   147,   340,    20,    21,    22,
      23,   148,   149,    97,    98,   150,   347,   350,    99,   351,
     354,    74,   268,   358,   357,   359,   101,   102,   103,   104,
     105,   152,   363,   369,   373,   374,     1,     2,   355,   298,
       3,     4,     5,   394,   396,   318,     6,   376,     7,     8,
       9,   319,   107,   108,    10,    11,    12,    13,    14,    15,
     320,    16,    17,    95,    18,    19,   321,   323,    20,    21,
      22,    23,   375,    96,    97,    98,   150,   136,   293,    99,
     179,   129,   346,   353,    63,     0,     0,   101,   102,   103,
     104,   105,   152,   269,     0,     0,     0,     0,     2,     0,
       0,     3,     4,     5,     0,     0,     0,     6,     0,     7,
       0,     9,     0,   107,   108,    10,     0,    12,    13,     0,
      15,     0,    16,    17,    95,     0,    19,     0,     0,    20,
      21,    22,    23,     0,    96,    97,    98,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   152,   138,   139,     0,     0,     0,   140,
     141,   142,     0,     0,     0,     0,     0,   143,   144,   145,
       0,     0,     0,     0,   107,   108,   146,     0,     0,    95,
       0,     0,   147,     0,     0,     0,     0,     0,   148,   149,
      97,    98,   150,     0,     5,    99,     0,     0,    74,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   152,     0,
       0,    15,     0,     0,     0,    95,   174,     0,     0,     0,
       0,     0,     0,    23,     0,    96,    97,    98,     0,   107,
     108,    99,     0,     0,     0,     0,     0,   175,     5,   101,
     102,   103,   104,   105,   176,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,    95,
     283,     0,     0,     0,     0,   107,   108,    23,     0,    96,
      97,    98,     0,     0,     0,    99,     0,     0,     0,     0,
       0,   284,     0,   101,   102,   103,   104,   105,   285,     0,
       0,     0,     0,     1,     2,     0,     0,     3,     4,     5,
       0,     0,     0,     6,     0,     7,     8,     9,     0,   107,
     108,    10,    11,    12,    13,    14,    15,     0,    16,    17,
       0,    18,    19,     0,     0,    20,    21,    22,    23,     0,
       1,     2,     0,     0,     3,     4,     5,     0,     0,     0,
       6,     0,     7,     8,     9,     0,     0,     0,    10,    11,
      12,    13,    14,    15,     0,    16,    17,   292,    18,    19,
       0,     0,    20,    21,    22,    23,     0,    40,     0,     0,
       0,     1,     2,   183,    89,     3,     4,     5,    58,     0,
       0,     6,     0,     7,     8,     9,    43,     0,     0,    10,
      11,    12,    13,    14,    15,     0,    16,    17,     0,    18,
      19,     0,     0,    20,    21,    22,    23,     0,     0,     0,
      95,     0,     0,     0,    57,    89,     0,     0,     0,    58,
      96,    97,    98,     0,     0,     0,    99,    43,   270,   165,
     370,   271,     0,     0,   101,   102,   103,   104,   105,   152,
       0,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     107,   108,    99,     0,   270,   165,   395,   271,     0,     0,
     101,   102,   103,   104,   105,   152,     0,     0,     0,     0,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   107,   108,    99,     0,
     270,   165,    95,   271,     0,     0,   101,   102,   103,   104,
     105,   152,    96,    97,    98,     0,     0,     0,    99,     0,
       0,     0,     0,     0,   100,     0,   101,   102,   103,   104,
     105,   106,   107,   108,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,     0,     0,
      99,     0,   107,   108,    95,     0,   244,     0,   101,   102,
     103,   104,   105,   245,    96,    97,    98,   261,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   152,   107,   108,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,     0,     0,    99,   107,   108,   355,    95,     0,     0,
       0,   101,   102,   103,   104,   105,   152,    96,    97,    98,
     150,     0,     0,    99,     0,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   152,   107,   108,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,     0,     0,    99,   379,   107,   108,    95,
       0,     0,     0,   101,   102,   103,   104,   105,   152,    96,
      97,    98,     0,     0,     0,    99,   381,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   152,   107,
     108,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,     0,     0,   194,     0,   107,
     108,    95,     0,     0,     0,   101,   102,   103,   104,   105,
     152,    96,    97,    98,     0,     0,     0,   199,     0,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     152,   107,   108,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,     0,     0,    99,
       0,   107,   108,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   152,     0,     0,     0,     0,     1,     2,     0,
       0,     3,     4,     5,     0,     0,     0,     6,     0,     7,
       8,     9,     0,   107,   108,    10,    11,    12,    13,    14,
      15,     0,    16,    17,     0,    18,    19,     0,     0,    20,
      21,    22,    23,     0,     0,     0,     1,     2,     0,     0,
       3,     4,     5,    74,     0,     0,     6,    75,     7,     8,
       9,     0,     0,     0,    10,    11,    12,    13,    14,    15,
       0,    16,    17,     0,    18,    19,     0,     0,    20,    21,
      22,    23,     2,     0,     0,     3,     4,     5,     0,     0,
       0,     6,    74,     7,     0,     9,     0,     0,     0,    10,
       0,    12,    13,     0,    15,     0,    16,    17,     0,     0,
      19,     0,     0,    20,    21,    22,    23,     0,     2,     0,
       0,     3,     4,     5,     0,     0,     0,     6,   180,     7,
       0,     9,     0,     0,     0,    10,     0,    12,    13,     0,
      15,     0,    16,    17,     0,     0,    19,     0,     0,    20,
      21,    22,    23,     1,     2,     0,     0,     3,     4,     5,
       0,     0,     0,     6,   287,     7,     8,     9,     0,     0,
       0,    10,    11,    12,    13,    14,    15,     0,    16,    17,
       0,    18,    19,     0,     0,    20,    21,    22,    23,     0,
     170,     0,     0,     0,     1,     2,     0,   171,     3,     4,
       5,     0,     0,     0,     6,     0,     7,     8,     9,     0,
       0,     0,    10,    11,    12,    13,    14,    15,     0,    16,
      17,     0,    18,    19,     0,     0,    20,    21,    22,    23,
       0,     0,    62,     0,     0,     1,     2,     0,   242,     3,
       4,     5,     0,     0,     0,     6,     0,     7,     8,     9,
       0,     0,     0,    10,    11,    12,    13,    14,    15,     0,
      16,    17,     0,    18,    19,     0,     0,    20,    21,    22,
      23,     1,     2,     0,     0,     3,     4,     5,     0,     0,
       0,     6,     0,     7,     8,     9,     0,     0,     0,    10,
      11,    12,    13,    14,    15,     0,    16,    17,     0,    18,
      19,     0,     0,    20,    21,    22,    23,     2,     0,     0,
       3,     4,     5,     0,     0,     0,     6,     0,     7,     0,
       9,     0,     0,     0,    10,     0,    12,    13,     0,    15,
       0,    16,    17,     0,     0,    19,     0,     0,    20,    21,
      22,    23
  };

  const short int
  parser::yycheck_[] =
  {
      58,    75,   142,    95,    86,    81,    25,   112,    46,    99,
     131,    99,    47,    82,   258,   107,   108,    75,    49,    40,
     112,    43,   342,    27,    82,    29,   130,    59,     9,    50,
      40,    40,    57,    46,    56,   139,    74,    46,   130,    40,
      50,    79,    51,    49,    40,    26,   139,   139,    70,    40,
      59,   127,    56,    49,    73,    46,   146,    38,    77,    53,
      82,    83,    84,    85,    86,    90,    79,   387,    59,    88,
     128,    90,    56,    47,     9,    40,    66,    99,   182,    83,
      84,    85,    86,    44,    49,    40,    47,   331,   332,   182,
     182,    26,    47,    46,    84,    48,    47,   179,    51,    83,
      84,    85,    86,    38,   194,   174,   194,   165,    46,   199,
      44,   199,    43,    51,   204,    99,   256,   222,   223,   224,
     178,   159,    43,    44,    59,   265,   247,    80,    81,    82,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    47,   240,   239,
     185,    44,   174,   185,     0,    46,   178,   179,   183,    52,
      51,   219,    52,    40,    65,    32,    46,   271,    59,    46,
     260,    51,   194,   263,   264,   179,    43,   199,   271,   271,
      26,    27,    28,    29,    51,   289,    44,    54,   328,    35,
      57,   296,    50,    40,    54,   179,   289,   289,    45,    46,
     274,    64,    44,    70,   296,    83,    62,    63,    50,   267,
     194,    57,    59,    40,    44,   199,   274,    47,    45,    46,
     258,    88,   280,    90,    51,   283,   366,   367,   368,    85,
      86,    40,    59,    52,    43,    81,    30,    46,    40,   379,
      48,   381,    53,    51,    46,    53,    40,    41,    42,    51,
      59,   391,    46,   393,   394,    49,    43,   361,   280,     9,
      54,    55,    56,    57,    58,    59,    45,    44,   342,   361,
      47,    44,   291,   363,   364,   365,    26,    50,    46,    44,
      30,   127,    43,    51,   342,    50,    80,    81,    38,    46,
      40,    41,    42,    59,    60,    61,    46,   355,   372,    40,
      44,    46,    53,    47,    54,    55,    56,    57,    58,    59,
      57,    58,    44,   387,   372,    47,   183,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    87,    88,   387,
      80,    81,   229,   230,   231,   232,    44,   183,    44,    47,
      44,    47,    45,    47,    46,   191,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    46,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    47,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    78,    79,    46,
      43,    44,    49,    50,    43,    44,    52,    54,    55,    56,
      57,    58,    59,    43,    44,    44,    45,   225,   226,    52,
     227,   228,   233,   234,    45,    47,    40,    40,    47,    52,
      45,    39,    52,    80,    81,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    43,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    40,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    40,    52,    46,    52,
      47,    49,    50,    44,    47,    47,    54,    55,    56,    57,
      58,    59,    46,    52,    52,    52,     3,     4,    49,    40,
       7,     8,     9,    14,    43,   235,    13,   358,    15,    16,
      17,   236,    80,    81,    21,    22,    23,    24,    25,    26,
     237,    28,    29,    30,    31,    32,   238,   240,    35,    36,
      37,    38,   355,    40,    41,    42,    43,    73,   191,    46,
      83,    64,   275,   291,    35,    -1,    -1,    54,    55,    56,
      57,    58,    59,   159,    -1,    -1,    -1,    -1,     4,    -1,
      -1,     7,     8,     9,    -1,    -1,    -1,    13,    -1,    15,
      -1,    17,    -1,    80,    81,    21,    -1,    23,    24,    -1,
      26,    -1,    28,    29,    30,    -1,    32,    -1,    -1,    35,
      36,    37,    38,    -1,    40,    41,    42,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    57,    58,    59,     5,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    -1,    80,    81,    27,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    -1,     9,    46,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    -1,
      -1,    26,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    42,    -1,    80,
      81,    46,    -1,    -1,    -1,    -1,    -1,    52,     9,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    80,    81,    38,    -1,    40,
      41,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,     7,     8,     9,
      -1,    -1,    -1,    13,    -1,    15,    16,    17,    -1,    80,
      81,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    38,    -1,
       3,     4,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,
      13,    -1,    15,    16,    17,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    -1,    28,    29,    67,    31,    32,
      -1,    -1,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      -1,     3,     4,    46,    47,     7,     8,     9,    51,    -1,
      -1,    13,    -1,    15,    16,    17,    59,    -1,    -1,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    -1,    31,
      32,    -1,    -1,    35,    36,    37,    38,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,
      40,    41,    42,    -1,    -1,    -1,    46,    59,    48,    49,
      50,    51,    -1,    -1,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      80,    81,    46,    -1,    48,    49,    50,    51,    -1,    -1,
      54,    55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,    80,    81,    46,    -1,
      48,    49,    30,    51,    -1,    -1,    54,    55,    56,    57,
      58,    59,    40,    41,    42,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,    57,
      58,    59,    80,    81,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,
      46,    -1,    80,    81,    30,    -1,    52,    -1,    54,    55,
      56,    57,    58,    59,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    57,    58,    59,    80,    81,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      -1,    -1,    -1,    46,    80,    81,    49,    30,    -1,    -1,
      -1,    54,    55,    56,    57,    58,    59,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    57,    58,    59,    80,    81,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    -1,    -1,    -1,    46,    47,    80,    81,    30,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    40,
      41,    42,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    80,
      81,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    -1,    46,    -1,    80,
      81,    30,    -1,    -1,    -1,    54,    55,    56,    57,    58,
      59,    40,    41,    42,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,
      59,    80,    81,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,    46,
      -1,    80,    81,    -1,    -1,    -1,    -1,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,     7,     8,     9,    -1,    -1,    -1,    13,    -1,    15,
      16,    17,    -1,    80,    81,    21,    22,    23,    24,    25,
      26,    -1,    28,    29,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    38,    -1,    -1,    -1,     3,     4,    -1,    -1,
       7,     8,     9,    49,    -1,    -1,    13,    53,    15,    16,
      17,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    -1,    31,    32,    -1,    -1,    35,    36,
      37,    38,     4,    -1,    -1,     7,     8,     9,    -1,    -1,
      -1,    13,    49,    15,    -1,    17,    -1,    -1,    -1,    21,
      -1,    23,    24,    -1,    26,    -1,    28,    29,    -1,    -1,
      32,    -1,    -1,    35,    36,    37,    38,    -1,     4,    -1,
      -1,     7,     8,     9,    -1,    -1,    -1,    13,    50,    15,
      -1,    17,    -1,    -1,    -1,    21,    -1,    23,    24,    -1,
      26,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,    35,
      36,    37,    38,     3,     4,    -1,    -1,     7,     8,     9,
      -1,    -1,    -1,    13,    50,    15,    16,    17,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    38,    -1,
      40,    -1,    -1,    -1,     3,     4,    -1,    47,     7,     8,
       9,    -1,    -1,    -1,    13,    -1,    15,    16,    17,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    -1,    31,    32,    -1,    -1,    35,    36,    37,    38,
      -1,    -1,     0,    -1,    -1,     3,     4,    -1,    47,     7,
       8,     9,    -1,    -1,    -1,    13,    -1,    15,    16,    17,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    -1,    31,    32,    -1,    -1,    35,    36,    37,
      38,     3,     4,    -1,    -1,     7,     8,     9,    -1,    -1,
      -1,    13,    -1,    15,    16,    17,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    -1,    31,
      32,    -1,    -1,    35,    36,    37,    38,     4,    -1,    -1,
       7,     8,     9,    -1,    -1,    -1,    13,    -1,    15,    -1,
      17,    -1,    -1,    -1,    21,    -1,    23,    24,    -1,    26,
      -1,    28,    29,    -1,    -1,    32,    -1,    -1,    35,    36,
      37,    38
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     4,     7,     8,     9,    13,    15,    16,    17,
      21,    22,    23,    24,    25,    26,    28,    29,    31,    32,
      35,    36,    37,    38,   111,   112,   113,   125,   129,   130,
     131,   132,   137,   138,   141,   153,   154,   155,    40,    49,
      40,    43,    46,    59,   114,   115,   121,   122,   123,   112,
     112,   137,   112,   112,   137,    40,    49,    46,    51,   122,
     142,   143,     0,   154,    49,    40,   139,   140,   121,   122,
     124,   125,    43,    44,    49,    53,   111,   112,   146,   156,
     123,    46,    51,    49,   125,   130,   133,   134,   137,    47,
     112,   126,   127,   128,   142,    30,    40,    41,    42,    46,
      52,    54,    55,    56,    57,    58,    59,    80,    81,    90,
      91,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   143,    46,    51,   139,
      53,    44,    50,    47,   122,   125,   115,   121,     5,     6,
      10,    11,    12,    18,    19,    20,    27,    33,    39,    40,
      43,    50,    59,   107,   109,   111,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    49,   107,   116,   111,   146,
      40,    47,   126,   157,    31,    52,    59,   107,   124,   133,
      50,   134,    45,    46,   121,   122,   135,   136,   121,   142,
      47,    44,    43,    47,    46,    93,   109,   141,    52,    46,
      93,    93,    46,    48,    51,    80,    81,    82,    53,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,   108,
      93,    95,    59,    60,    61,    57,    58,    78,    79,    62,
      63,    85,    86,    87,    88,    54,    64,    65,    83,    66,
      84,    52,    47,   126,    52,    59,   107,    44,    50,   106,
     110,    50,   140,    43,   110,    43,    45,   144,    46,    40,
      46,    43,   109,    46,    46,    45,    43,    44,    50,   148,
      48,    51,   116,   117,   118,   119,   120,    47,    44,    47,
     124,    52,    52,    31,    52,    59,   107,    50,   110,    45,
      43,    44,    67,   128,   141,    47,    47,   141,    40,    47,
      92,    40,   109,    40,   107,    95,    95,    95,    96,    96,
      97,    97,    98,    98,    98,    98,    99,    99,   100,   101,
     102,   103,   109,   104,    47,    52,    52,    50,    45,   144,
      39,   111,   149,    43,   109,    43,   109,   109,   144,   107,
      40,   110,    44,    50,   116,    53,   120,    40,   107,   107,
      52,    52,   110,   136,    47,    49,    95,    47,    44,    47,
      52,    45,   144,    46,   149,   149,    47,    47,    47,    52,
      50,   116,   118,    52,    52,   117,    92,   106,   109,    47,
     109,    47,   109,   144,   144,   144,   116,    44,    50,    47,
     144,    47,   144,    47,    14,    50,    43,   144,   144,   144
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    89,    90,    90,    90,    90,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    92,    92,    93,    93,
      93,    93,    93,    93,    94,    94,    94,    94,    94,    94,
      95,    95,    96,    96,    96,    96,    97,    97,    97,    98,
      98,    98,    99,    99,    99,    99,    99,   100,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   109,   109,   110,   111,   111,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   117,
     117,   117,   117,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   125,
     125,   125,   126,   126,   127,   127,   128,   128,   128,   129,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   131,   131,   131,   132,   132,
     133,   133,   134,   135,   135,   136,   136,   136,   137,   137,
     137,   137,   138,   138,   138,   138,   138,   139,   139,   140,
     140,   141,   141,   142,   142,   142,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   144,   144,   144,
     144,   144,   144,   145,   145,   145,   146,   146,   147,   147,
     148,   148,   149,   149,   150,   150,   150,   151,   151,   151,
     151,   151,   151,   152,   152,   152,   152,   152,   153,   153,
     154,   154,   155,   155,   156,   156,   157,   157
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     3,     1,     4,     4,     3,
       3,     3,     2,     2,     6,     7,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     3,     4,     1,
       2,     3,     4,     2,     1,     2,     3,     2,     2,     1,
       1,     2,     2,     3,     1,     3,     5,     4,     4,     6,
       6,     5,     4,     3,     4,     4,     3,     1,     2,     1,
       1,     1,     1,     3,     2,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     3,     1,     3,     1,     2,     3,     2,     1,
       2,     1,     4,     5,     5,     6,     2,     1,     3,     1,
       3,     1,     2,     1,     1,     2,     3,     2,     3,     3,
       4,     3,     4,     2,     3,     3,     4,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     3,     1,     2,
       1,     1,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     6,     7,     3,     2,     2,     2,     3,     1,     2,
       1,     1,     4,     3,     1,     2,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "AUTO", "BOOL", "BREAK", "CASE", "CHAR",
  "COMPLEX", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE",
  "ENUM", "EXTERN", "FLOAT", "FOR", "GOTO", "IF", "IMAGINARY", "INLINE",
  "INT", "LONG", "REGISTER", "RESTRICT", "RETURN", "SHORT", "SIGNED",
  "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED",
  "VOID", "VOLATILE", "WHILE", "IDENTIFIER", "LITERAL", "STRING_LITERAL",
  "\";\"", "\",\"", "\":\"", "\"(\"", "\")\"", "\".\"", "\"{\"", "\"}\"",
  "\"[\"", "\"]\"", "\"=\"", "\"&\"", "\"!\"", "\"~\"", "\"-\"", "\"+\"",
  "\"*\"", "\"/\"", "\"%\"", "\"<\"", "\">\"", "\"^\"", "\"|\"", "\"?\"",
  "\"...\"", "\">>=\"", "\"<<=\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"",
  "\"%=\"", "\"&=\"", "\"^=\"", "\"|=\"", "\">>\"", "\"<<\"", "\"++\"",
  "\"--\"", "\"->\"", "\"&&\"", "\"||\"", "\"<=\"", "\">=\"", "\"==\"",
  "\"!=\"", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "storage_class_specifier",
  "init_declarator_list", "init_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "declarator", "pointer", "direct_declarator", "type_qualifier_list",
  "type_qualifier", "parameter_type_list", "parameter_list",
  "parameter_declaration", "function_specifier", "type_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator",
  "specifier_qualifier_list", "enum_specifier", "enumerator_list",
  "enumerator", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", "identifier_list", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,   269,   269,   270,   271,   272,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   289,   290,   294,   295,
     296,   297,   298,   299,   303,   304,   305,   306,   307,   308,
     312,   313,   317,   318,   319,   320,   324,   325,   326,   330,
     331,   332,   336,   337,   338,   339,   340,   344,   345,   346,
     350,   351,   355,   356,   360,   361,   365,   366,   370,   371,
     375,   376,   380,   381,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   399,   400,   404,   408,   409,
     413,   414,   415,   416,   417,   418,   419,   420,   424,   425,
     426,   427,   431,   432,   436,   437,   441,   442,   443,   447,
     448,   449,   450,   454,   458,   459,   463,   464,   468,   469,
     473,   474,   475,   476,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   496,   497,   501,
     502,   503,   507,   508,   512,   513,   517,   518,   519,   523,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   545,   546,   547,   551,   552,
     556,   557,   561,   565,   566,   570,   571,   572,   576,   577,
     578,   579,   583,   584,   585,   586,   587,   591,   592,   596,
     597,   601,   602,   606,   607,   608,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   626,   627,   628,
     629,   630,   631,   635,   636,   637,   641,   642,   646,   647,
     651,   652,   656,   657,   661,   662,   663,   667,   668,   669,
     670,   671,   672,   676,   677,   678,   679,   680,   684,   685,
     689,   690,   694,   695,   699,   700,   704,   705
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88
    };
    const unsigned int user_token_number_max_ = 343;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 5649 "parser.cc" // lalr1.cc:1167
#line 709 "parser.yy" // lalr1.cc:1168


void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
