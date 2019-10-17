// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file parser.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_PARSER_HH_INCLUDED
# define YY_YY_PARSER_HH_INCLUDED
// //                    "%code requires" blocks.
#line 3 "parser.yy" // lalr1.cc:377

   #include <string>
   class driver;

#line 49 "parser.hh" // lalr1.cc:377


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"


#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif


namespace yy {
#line 126 "parser.hh" // lalr1.cc:377



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {}

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;
  };


  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // primary_expression
      // postfix_expression
      // argument_expression_list
      // unary_expression
      // unary_operator
      // cast_expression
      // multiplicative_expression
      // additive_expression
      // shift_expression
      // relational_expression
      // equality_expression
      // and_expression
      // exclusive_or_expression
      // inclusive_or_expression
      // logical_and_expression
      // logical_or_expression
      // conditional_expression
      // assignment_expression
      // assignment_operator
      // expression
      // constant_expression
      // declaration
      // declaration_specifiers
      // storage_class_specifier
      // init_declarator_list
      // init_declarator
      // initializer
      // initializer_list
      // designation
      // designator_list
      // designator
      // declarator
      // pointer
      // direct_declarator
      // type_qualifier_list
      // type_qualifier
      // parameter_type_list
      // parameter_list
      // parameter_declaration
      // function_specifier
      // type_specifier
      // struct_or_union_specifier
      // struct_or_union
      // struct_declaration_list
      // struct_declaration
      // struct_declarator_list
      // struct_declarator
      // specifier_qualifier_list
      // enum_specifier
      // enumerator_list
      // enumerator
      // type_name
      // abstract_declarator
      // direct_abstract_declarator
      // statement
      // labeled_statement
      // compound_statement
      // block_item_list
      // block_item
      // expression_statement
      // selection_statement
      // iteration_statement
      // jump_statement
      // translation_unit
      // external_declaration
      // function_definition
      // declaration_list
      // identifier_list
      char dummy1[sizeof(AstNodePtr)];

      // AUTO
      // BOOL
      // BREAK
      // CASE
      // CHAR
      // COMPLEX
      // CONST
      // CONTINUE
      // DEFAULT
      // DO
      // DOUBLE
      // ELSE
      // ENUM
      // EXTERN
      // FLOAT
      // FOR
      // GOTO
      // IF
      // IMAGINARY
      // INLINE
      // INT
      // LONG
      // REGISTER
      // RESTRICT
      // RETURN
      // SHORT
      // SIGNED
      // SIZEOF
      // STATIC
      // STRUCT
      // SWITCH
      // TYPEDEF
      // UNION
      // UNSIGNED
      // VOID
      // VOLATILE
      // WHILE
      // IDENTIFIER
      // LITERAL
      // STRING_LITERAL
      // ";"
      // ","
      // ":"
      // "("
      // ")"
      // "."
      // "{"
      // "}"
      // "["
      // "]"
      // "="
      // "&"
      // "!"
      // "~"
      // "-"
      // "+"
      // "*"
      // "/"
      // "%"
      // "<"
      // ">"
      // "^"
      // "|"
      // "?"
      // "..."
      // ">>="
      // "<<="
      // "+="
      // "-="
      // "*="
      // "/="
      // "%="
      // "&="
      // "^="
      // "|="
      // ">>"
      // "<<"
      // "++"
      // "--"
      // "->"
      // "&&"
      // "||"
      // "<="
      // ">="
      // "=="
      // "!="
      char dummy2[sizeof(string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m);
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        AUTO = 258,
        BOOL = 259,
        BREAK = 260,
        CASE = 261,
        CHAR = 262,
        COMPLEX = 263,
        CONST = 264,
        CONTINUE = 265,
        DEFAULT = 266,
        DO = 267,
        DOUBLE = 268,
        ELSE = 269,
        ENUM = 270,
        EXTERN = 271,
        FLOAT = 272,
        FOR = 273,
        GOTO = 274,
        IF = 275,
        IMAGINARY = 276,
        INLINE = 277,
        INT = 278,
        LONG = 279,
        REGISTER = 280,
        RESTRICT = 281,
        RETURN = 282,
        SHORT = 283,
        SIGNED = 284,
        SIZEOF = 285,
        STATIC = 286,
        STRUCT = 287,
        SWITCH = 288,
        TYPEDEF = 289,
        UNION = 290,
        UNSIGNED = 291,
        VOID = 292,
        VOLATILE = 293,
        WHILE = 294,
        IDENTIFIER = 295,
        LITERAL = 296,
        STRING_LITERAL = 297,
        SEMICOLON = 298,
        COMMA = 299,
        COLON = 300,
        LEFT_PAR = 301,
        RIGHT_PAR = 302,
        DOT = 303,
        LEFT_CBRACKET = 304,
        RIGHT_CBRACKET = 305,
        LEFT_BRACKET = 306,
        RIGHT_BRACKET = 307,
        ASSIGN_OP = 308,
        AMP = 309,
        LOG_NOT_OP = 310,
        BIN_NOT_OP = 311,
        MINUS = 312,
        PLUS = 313,
        STAR = 314,
        SLASH = 315,
        MOD_OP = 316,
        G_OP = 317,
        L_OP = 318,
        BIN_XOR_OP = 319,
        BIN_OR_OP = 320,
        TERNARY_OP = 321,
        ELLIPSIS = 322,
        RIGHT_ASSIGN = 323,
        LEFT_ASSIGN = 324,
        ADD_ASSIGN = 325,
        SUB_ASSIGN = 326,
        MUL_ASSIGN = 327,
        DIV_ASSIGN = 328,
        MOD_ASSIGN = 329,
        AND_ASSIGN = 330,
        XOR_ASSIGN = 331,
        OR_ASSIGN = 332,
        RIGHT_OP = 333,
        LEFT_OP = 334,
        INC_OP = 335,
        DEC_OP = 336,
        PTR_OP = 337,
        AND_OP = 338,
        OR_OP = 339,
        LE_OP = 340,
        GE_OP = 341,
        EQ_OP = 342,
        NE_OP = 343
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t);

  basic_symbol (typename Base::kind_type t, const AstNodePtr v);

  basic_symbol (typename Base::kind_type t, const string v);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_AUTO (const string& v);

    static inline
    symbol_type
    make_BOOL (const string& v);

    static inline
    symbol_type
    make_BREAK (const string& v);

    static inline
    symbol_type
    make_CASE (const string& v);

    static inline
    symbol_type
    make_CHAR (const string& v);

    static inline
    symbol_type
    make_COMPLEX (const string& v);

    static inline
    symbol_type
    make_CONST (const string& v);

    static inline
    symbol_type
    make_CONTINUE (const string& v);

    static inline
    symbol_type
    make_DEFAULT (const string& v);

    static inline
    symbol_type
    make_DO (const string& v);

    static inline
    symbol_type
    make_DOUBLE (const string& v);

    static inline
    symbol_type
    make_ELSE (const string& v);

    static inline
    symbol_type
    make_ENUM (const string& v);

    static inline
    symbol_type
    make_EXTERN (const string& v);

    static inline
    symbol_type
    make_FLOAT (const string& v);

    static inline
    symbol_type
    make_FOR (const string& v);

    static inline
    symbol_type
    make_GOTO (const string& v);

    static inline
    symbol_type
    make_IF (const string& v);

    static inline
    symbol_type
    make_IMAGINARY (const string& v);

    static inline
    symbol_type
    make_INLINE (const string& v);

    static inline
    symbol_type
    make_INT (const string& v);

    static inline
    symbol_type
    make_LONG (const string& v);

    static inline
    symbol_type
    make_REGISTER (const string& v);

    static inline
    symbol_type
    make_RESTRICT (const string& v);

    static inline
    symbol_type
    make_RETURN (const string& v);

    static inline
    symbol_type
    make_SHORT (const string& v);

    static inline
    symbol_type
    make_SIGNED (const string& v);

    static inline
    symbol_type
    make_SIZEOF (const string& v);

    static inline
    symbol_type
    make_STATIC (const string& v);

    static inline
    symbol_type
    make_STRUCT (const string& v);

    static inline
    symbol_type
    make_SWITCH (const string& v);

    static inline
    symbol_type
    make_TYPEDEF (const string& v);

    static inline
    symbol_type
    make_UNION (const string& v);

    static inline
    symbol_type
    make_UNSIGNED (const string& v);

    static inline
    symbol_type
    make_VOID (const string& v);

    static inline
    symbol_type
    make_VOLATILE (const string& v);

    static inline
    symbol_type
    make_WHILE (const string& v);

    static inline
    symbol_type
    make_IDENTIFIER (const string& v);

    static inline
    symbol_type
    make_LITERAL (const string& v);

    static inline
    symbol_type
    make_STRING_LITERAL (const string& v);

    static inline
    symbol_type
    make_SEMICOLON (const string& v);

    static inline
    symbol_type
    make_COMMA (const string& v);

    static inline
    symbol_type
    make_COLON (const string& v);

    static inline
    symbol_type
    make_LEFT_PAR (const string& v);

    static inline
    symbol_type
    make_RIGHT_PAR (const string& v);

    static inline
    symbol_type
    make_DOT (const string& v);

    static inline
    symbol_type
    make_LEFT_CBRACKET (const string& v);

    static inline
    symbol_type
    make_RIGHT_CBRACKET (const string& v);

    static inline
    symbol_type
    make_LEFT_BRACKET (const string& v);

    static inline
    symbol_type
    make_RIGHT_BRACKET (const string& v);

    static inline
    symbol_type
    make_ASSIGN_OP (const string& v);

    static inline
    symbol_type
    make_AMP (const string& v);

    static inline
    symbol_type
    make_LOG_NOT_OP (const string& v);

    static inline
    symbol_type
    make_BIN_NOT_OP (const string& v);

    static inline
    symbol_type
    make_MINUS (const string& v);

    static inline
    symbol_type
    make_PLUS (const string& v);

    static inline
    symbol_type
    make_STAR (const string& v);

    static inline
    symbol_type
    make_SLASH (const string& v);

    static inline
    symbol_type
    make_MOD_OP (const string& v);

    static inline
    symbol_type
    make_G_OP (const string& v);

    static inline
    symbol_type
    make_L_OP (const string& v);

    static inline
    symbol_type
    make_BIN_XOR_OP (const string& v);

    static inline
    symbol_type
    make_BIN_OR_OP (const string& v);

    static inline
    symbol_type
    make_TERNARY_OP (const string& v);

    static inline
    symbol_type
    make_ELLIPSIS (const string& v);

    static inline
    symbol_type
    make_RIGHT_ASSIGN (const string& v);

    static inline
    symbol_type
    make_LEFT_ASSIGN (const string& v);

    static inline
    symbol_type
    make_ADD_ASSIGN (const string& v);

    static inline
    symbol_type
    make_SUB_ASSIGN (const string& v);

    static inline
    symbol_type
    make_MUL_ASSIGN (const string& v);

    static inline
    symbol_type
    make_DIV_ASSIGN (const string& v);

    static inline
    symbol_type
    make_MOD_ASSIGN (const string& v);

    static inline
    symbol_type
    make_AND_ASSIGN (const string& v);

    static inline
    symbol_type
    make_XOR_ASSIGN (const string& v);

    static inline
    symbol_type
    make_OR_ASSIGN (const string& v);

    static inline
    symbol_type
    make_RIGHT_OP (const string& v);

    static inline
    symbol_type
    make_LEFT_OP (const string& v);

    static inline
    symbol_type
    make_INC_OP (const string& v);

    static inline
    symbol_type
    make_DEC_OP (const string& v);

    static inline
    symbol_type
    make_PTR_OP (const string& v);

    static inline
    symbol_type
    make_AND_OP (const string& v);

    static inline
    symbol_type
    make_OR_OP (const string& v);

    static inline
    symbol_type
    make_LE_OP (const string& v);

    static inline
    symbol_type
    make_GE_OP (const string& v);

    static inline
    symbol_type
    make_EQ_OP (const string& v);

    static inline
    symbol_type
    make_NE_OP (const string& v);


    /// Build a parser object.
    parser (driver& drv_yyarg);
    virtual ~parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short int yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (int t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const unsigned short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


#if YYDEBUG
    /// For a symbol, its name in clear.
    static const char* const yytname_[];

  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 1561,     ///< Last index in yytable_.
      yynnts_ = 69,  ///< Number of nonterminal symbols.
      yyfinal_ = 62, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 89  ///< Number of tokens.
    };


    // User arguments.
    driver& drv;
  };



} // yy
#line 1200 "parser.hh" // lalr1.cc:377




#endif // !YY_YY_PARSER_HH_INCLUDED
