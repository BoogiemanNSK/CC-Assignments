/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 5 "syntax.yy" /* yacc.c:316  */

    #include <vector>
    #include <string>
    #include <iostream>

    using namespace std;

    class Node {
        public:
            vector<Node*> children;
            Node* parent;
            string name;
            
            Node(vector<Node*> _children, Node* _parent){
                children = _children;
                parent = _parent;
            }
            
            Node(){
                children = vector<Node*>(1);
                parent = NULL;
            }

            void print_tree(){
                cout << name;
                for (int i = 0;i<children.size();i++){
                    cout << " " << children[i]->print();
                }
            }

            virtual string print() = 0;
    };

    class PrimaryExpressionNode : public Node {
        public:
            string print(){
                return("PrimaryExpressionNode");
            }

            PrimaryExpressionNode(Node* expr){
                children = {expr};
            }
    };

    
    class IdentifierNode : public Node{
        public:
            string ident;

            string print(){
                return("IDENT(" + ident + ")");
            };

            IdentifierNode(string _ident){
                ident = _ident;
            }
    };

    class NumericLiteralNode : public Node{
        public:
            string num;

            string print(){
                return("NUMLITERAL(" + num + ")");
            };

            NumericLiteralNode(string _num){
                num = _num;
            }
    };


    class StrLiteralNode : public Node{
        public:
            string val;

            string print(){
                return("STRLITERAL(" + val + ")");
            }

            StrLiteralNode(string _val){
                val = _val;
            }
    };

#line 149 "syntax.tab.cc" /* yacc.c:316  */



/* Copy the first part of user declarations.  */
#line 1 "syntax.yy" /* yacc.c:339  */

    %language "c++"

#line 158 "syntax.tab.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
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
    ELLIPSIS = 298,
    RIGHT_ASSIGN = 299,
    LEFT_ASSIGN = 300,
    ADD_ASSIGN = 301,
    SUB_ASSIGN = 302,
    MUL_ASSIGN = 303,
    DIV_ASSIGN = 304,
    MOD_ASSIGN = 305,
    AND_ASSIGN = 306,
    XOR_ASSIGN = 307,
    OR_ASSIGN = 308,
    RIGHT_OP = 309,
    LEFT_OP = 310,
    INC_OP = 311,
    DEC_OP = 312,
    PTR_OP = 313,
    AND_OP = 314,
    OR_OP = 315,
    LE_OP = 316,
    GE_OP = 317,
    EQ_OP = 318,
    NE_OP = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 271 "syntax.tab.cc" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  194
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  301

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,     2,     2,    80,    73,     2,
      65,    66,    74,    75,    72,    76,    69,    79,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    85,    87,
      81,    86,    82,    84,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    67,     2,    68,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    83,    71,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    77,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   196,   196,   197,   198,   199,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   216,   217,   221,   222,
     223,   224,   225,   226,   230,   231,   232,   233,   234,   235,
     239,   240,   244,   245,   246,   247,   251,   252,   253,   257,
     258,   259,   263,   264,   265,   266,   267,   271,   272,   273,
     277,   278,   282,   283,   287,   288,   292,   293,   297,   298,
     302,   303,   307,   308,   312,   312,   312,   312,   312,   312,
     313,   313,   313,   313,   313,   317,   318,   322,   326,   335,
     336,   337,   338,   339,   340,   341,   342,   345,   346,   347,
     348,   348,   361,   362,   363,   367,   368,   369,   370,   374,
     378,   379,   383,   384,   388,   389,   393,   394,   395,   396,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   416,   417,   421,   422,   423,   426,   427,
     431,   432,   436,   437,   438,   441,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   462,   463,   464,   468,   469,   473,   474,   478,   482,
     483,   487,   488,   489,   493,   494,   495,   496,   501,   502,
     503,   504,   505,   509,   510,   514,   515,   519,   520,   524,
     525,   526,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   622,   623
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BOOL", "BREAK", "CASE", "CHAR",
  "COMPLEX", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE",
  "ENUM", "EXTERN", "FLOAT", "FOR", "GOTO", "IF", "IMAGINARY", "INLINE",
  "INT", "LONG", "REGISTER", "RESTRICT", "RETURN", "SHORT", "SIGNED",
  "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED",
  "VOID", "VOLATILE", "WHILE", "IDENTIFIER", "LITERAL", "STRING_LITERAL",
  "ELLIPSIS", "RIGHT_ASSIGN", "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "RIGHT_OP", "LEFT_OP", "INC_OP", "DEC_OP", "PTR_OP",
  "AND_OP", "OR_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "'('", "')'",
  "'['", "']'", "'.'", "'{'", "'}'", "','", "'&'", "'*'", "'+'", "'-'",
  "'\\313'", "'!'", "'/'", "'%'", "'<'", "'>'", "'|'", "'?'", "':'", "'='",
  "';'", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration_specifiers",
  "storage_class_specifier", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "declarator", "pointer",
  "direct_declarator", "type_qualifier_list", "type_qualifier",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "function_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator",
  "specifier_qualifier_list", "enum_specifier", "enumerator_list",
  "enumerator", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "identifier_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,    40,    41,    91,    93,    46,
     123,   125,    44,    38,    42,    43,    45,   203,    33,    47,
      37,    60,    62,   124,    63,    58,    61,    59
};
# endif

#define YYPACT_NINF -211

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-211)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     130,  -211,  -211,  -211,   892,    24,   920,   948,   948,   214,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,   141,   139,   892,
    -211,    82,    14,   104,    93,   140,   -32,    -7,    36,   106,
      66,  -211,  -211,   128,  -211,   214,  -211,   214,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,    41,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  1096,  1096,
    -211,    46,   -31,  -211,    58,  -211,  -211,   137,    65,   892,
     153,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,   892,  -211,  -211,   892,   892,   892,   892,   892,
     892,   892,   892,   892,   892,   892,   892,   892,   892,   892,
     892,   892,   892,   892,  -211,   892,    75,   116,   149,   186,
     -31,  -211,   -31,   158,  1096,   337,   756,     0,   -30,  -211,
      71,   785,  -211,   162,  -211,   164,   143,  -211,  -211,  -211,
    -211,  -211,    82,    82,    14,    14,   104,   104,   104,   104,
      93,    93,   140,   -32,    -7,    36,   106,    88,  -211,   166,
     166,   186,   159,   142,  -211,  1096,   515,  -211,   -21,  -211,
    -211,  -211,  -211,  -211,  -211,    68,  1061,  1061,   173,   189,
    -211,  1061,  1061,   203,  -211,   210,   212,  -211,     0,  -211,
      71,   628,   824,   715,  -211,   242,  -211,  -211,   892,   145,
     892,  -211,    -8,   552,  -211,  -211,  -211,   290,   892,   198,
      78,   101,    57,  -211,  -211,  -211,  -211,  -211,  -211,  1024,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,   219,  -211,
     218,   227,   892,   256,   715,  -211,  -211,   161,   853,   -44,
    -211,  -211,  -211,  -211,    20,  -211,  -211,  -211,  -211,  -211,
     234,  -211,   892,   101,   589,   358,    35,  -211,  -211,  -211,
    -211,  -211,  -211,   233,  -211,   176,  -211,   631,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,   236,   135,   108,  -211,
     240,   241,   399,   -20,   -13,  -211,  -211,  -211,   673,  -211,
    -211,   853,  -211,  -211,   264,   440,  -211,  -211,   892,  -211,
     249,   252,  -211,  -211,  -211,   255,   261,  -211,  -211,  -211,
    -211
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     3,     4,     0,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,     6,    18,    30,     0,
      32,    36,    39,    42,    47,    50,    52,    54,    56,    58,
      60,    62,    75,     0,     1,     0,    22,     0,    19,    20,
     145,   137,   146,   125,   142,     0,   141,   147,   139,   140,
     126,   138,   143,   154,   155,   144,   136,   127,   167,   165,
     148,     0,   177,   149,   150,    12,    13,     0,     0,     0,
       0,    71,    70,    68,    69,    65,    66,    67,    72,    73,
      74,    64,     0,    30,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,   150,   150,   172,     0,
     166,   150,   164,   153,     0,    91,     0,   106,   179,   178,
     180,     0,    11,    16,     9,     0,     0,    10,    63,    33,
      34,    35,    37,    38,    41,    40,    45,    46,    43,    44,
      48,    49,    51,    53,    55,    57,    59,     0,    76,    23,
       0,     0,   175,     0,   173,     0,     0,   156,   177,    89,
      87,   135,    90,    88,   189,   134,    79,    83,     0,   128,
     130,    85,    81,     0,   183,    25,     0,   108,   107,   123,
     181,    91,     0,     0,    31,     0,     8,     7,     0,     0,
       0,   168,     0,     0,   152,   157,   110,    91,     0,   161,
     179,   105,     0,   159,   132,   133,    80,    84,   190,    91,
      86,    82,   182,   187,   184,   109,   124,   191,     0,   185,
      25,     0,     0,     0,     0,    92,    95,     0,     0,     0,
     100,    17,    61,   169,     0,    77,   176,   170,   174,   151,
       0,   162,     0,   104,    91,     0,     0,   158,   129,   131,
     192,   188,   186,     0,   103,     0,    14,     0,    96,    99,
     101,   171,   111,   163,   193,   122,     0,     0,     0,   119,
      25,     0,     0,     0,     0,   160,   102,    93,     0,    15,
      97,     0,   120,   121,     0,     0,   118,   114,     0,   113,
      25,     0,    94,    98,   194,     0,     0,   117,   112,   115,
     116
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -211,   310,  -211,   146,    -4,  -211,    11,   171,   182,   172,
     179,   226,   235,   232,   237,   231,  -211,  -140,   -76,  -211,
     -48,   -95,    91,  -211,  -210,   111,  -129,  -211,   107,  -158,
    -109,  -187,   -92,  -105,  -167,  -211,   133,  -211,   -87,  -211,
    -211,   184,  -134,  -211,    97,   -42,  -211,   196,  -177,    86,
    -114,  -107,  -211
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,   125,    83,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    82,
      33,   236,   165,   166,   226,   227,   228,   229,   230,   199,
     118,   201,   178,    58,   168,   169,   170,   171,    59,    60,
      61,   156,   157,   202,   203,    62,    63,   153,   154,   111,
     119,   120,   267
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      18,   173,    36,    38,    39,    18,   128,   204,   177,    43,
     167,   180,   179,   243,   218,   238,   110,   112,   258,   196,
     196,   126,   195,   222,    34,   223,    50,   196,   172,   148,
      84,    18,   152,    18,   115,   115,   116,   116,    57,   240,
     176,    98,   259,   117,   197,   273,   116,   280,   232,   200,
     235,   205,   273,   117,   117,   147,   200,   238,   235,   195,
     152,   167,   167,   237,   198,    18,   167,   167,   280,   215,
      99,   293,   158,   216,   117,   196,   167,   266,    18,   172,
     172,   108,   235,   173,   172,   172,   113,   243,   200,    88,
      89,   261,   167,   180,   172,    64,   129,   130,   131,    18,
     273,    18,   235,   241,   167,   123,   221,   225,   196,   117,
     172,   109,    18,   158,   158,   240,   114,    43,   196,   100,
     198,   106,   172,   107,   121,   110,   102,   253,   281,   246,
     112,   124,   184,   197,    50,   116,   181,   274,   182,   167,
     179,   149,   117,   197,   247,   116,    57,   263,   225,   281,
     103,   158,   225,   272,    92,    93,    85,   172,    90,    91,
     105,    86,    87,   179,   274,   101,   244,   216,   245,   271,
       1,     2,     3,   188,    94,    95,   285,   122,    18,    18,
     216,   225,   150,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   127,   104,     4,   291,    65,    66,    67,
     105,   283,   225,    96,    97,   225,    68,   284,    69,   295,
      70,   187,   296,   191,   192,   105,   233,   234,    40,   151,
      18,    41,    42,    43,    18,    81,   152,    44,   155,    45,
     186,    46,   256,   257,   185,    47,   183,    48,    49,   208,
      50,    18,    51,    52,     6,   190,    53,   277,   278,    54,
      55,    56,    57,    18,     1,     2,     3,   206,   207,   132,
     133,   209,   210,   211,   136,   137,   138,   139,    18,   212,
       7,     8,   134,   135,    18,   140,   141,    18,   213,     9,
     214,    18,   123,   242,    18,   250,   251,    10,    11,    12,
      13,    14,    15,   159,    40,   252,   254,    41,    42,    43,
     262,   276,   282,    44,   294,    45,   160,    46,   286,   287,
       5,    47,   161,    48,    49,   162,    50,   297,    51,    52,
     298,   163,    53,   299,   142,    54,    55,    56,    57,   300,
     196,   231,   144,   146,   143,   255,   260,     0,   145,   193,
     159,    40,   249,   275,    41,    42,    43,   189,     0,     0,
      44,     0,    45,   160,    46,   197,   164,   116,    47,   161,
      48,    49,   162,    50,   117,    51,    52,    43,   163,    53,
       0,     0,    54,    55,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,     0,     6,   268,
       0,     0,     0,     0,     0,     0,    57,     0,     1,     2,
       3,     0,   115,   164,   116,     0,     0,     0,    43,     0,
       0,   117,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    50,   269,     0,     0,     6,
     288,    10,   270,    12,    13,    14,    15,    57,     0,     1,
       2,     3,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     9,     0,    50,   289,     0,     0,
       6,     0,    10,   290,    12,    13,    14,    15,    57,     0,
       1,     2,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,    40,
       0,     0,    41,    42,    43,     0,     0,     0,    44,     0,
      45,     0,    46,     0,     0,     0,    47,     0,    48,    49,
       0,    50,     0,    51,    52,     0,     0,    53,     0,     0,
      54,    55,    56,    57,     0,     0,    40,     0,     0,    41,
      42,    43,     0,     0,     0,    44,     0,    45,     0,    46,
       0,     0,     0,    47,     0,    48,    49,     0,    50,     0,
      51,    52,     0,     0,    53,     0,   194,    54,    55,    56,
      57,     0,   159,    40,     0,     0,    41,    42,    43,     0,
       0,     0,    44,     0,    45,   160,    46,     0,     0,     0,
      47,   161,    48,    49,   162,    50,     0,    51,    52,     0,
     163,    53,     0,   239,    54,    55,    56,    57,     0,   264,
       0,   159,    40,     0,     0,    41,    42,    43,     0,     0,
       0,    44,     0,    45,   160,    46,     0,     0,     0,    47,
     161,    48,    49,   162,    50,   265,    51,    52,     0,   163,
      53,     6,     0,    54,    55,    56,    57,     0,     0,     0,
       0,     1,     2,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,   217,     0,     9,     0,   222,     0,
     223,   224,   279,     6,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     1,     2,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     9,     0,
     222,     0,   223,   224,   292,     6,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     1,     2,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       9,     0,   222,     0,   223,   224,     6,     0,    10,    11,
      12,    13,    14,    15,     0,     0,     1,     2,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     6,     0,     0,     0,     0,
       0,     9,     0,     0,   174,     1,     2,     3,     0,    10,
     175,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       9,     0,     0,     0,     6,   183,     0,     0,    10,    11,
      12,    13,    14,    15,     1,     2,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     6,     0,     0,     0,     0,     0,     9,
       0,     0,   219,     1,     2,     3,     0,    10,   220,    12,
      13,    14,    15,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     9,     0,
       0,     0,     6,   224,     0,     0,    10,    11,    12,    13,
      14,    15,     1,     2,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       6,     0,     0,     0,     0,     0,     0,     9,     0,     0,
       1,     2,     3,     0,     0,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     7,     8,     6,     0,
       0,     0,     0,     0,     0,    35,     0,     0,     1,     2,
       3,     0,     0,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,    14,    15,   159,    40,     0,
       0,    41,    42,    43,     0,     0,     0,    44,     0,    45,
     160,    46,     0,     0,     0,    47,   161,    48,    49,   162,
      50,     0,    51,    52,     0,   163,    53,     0,     0,    54,
      55,    56,    57,     0,   159,    40,     0,   248,    41,    42,
      43,     0,     0,     0,    44,     0,    45,   160,    46,     0,
       0,     0,    47,   161,    48,    49,   162,    50,     0,    51,
      52,     0,   163,    53,     0,     0,    54,    55,    56,    57,
      40,     0,     0,    41,    42,    43,     0,     0,     0,    44,
       0,    45,     0,    46,     0,     0,     0,    47,     0,    48,
      49,     0,    50,     0,    51,    52,     0,     0,    53,     0,
       0,    54,    55,    56,    57
};

static const yytype_int16 yycheck[] =
{
       4,   115,     6,     7,     8,     9,    82,   165,   117,     9,
     115,   118,   117,   200,   181,   192,    58,    59,   228,    40,
      40,    69,   156,    67,     0,    69,    26,    40,   115,   105,
      19,    35,    40,    37,    65,    65,    67,    67,    38,   197,
     116,    73,    86,    74,    65,    65,    67,   257,   188,   158,
     190,   165,    65,    74,    74,   103,   165,   234,   198,   193,
      40,   166,   167,    71,    85,    69,   171,   172,   278,   178,
      77,   281,   114,   178,    74,    40,   181,   244,    82,   166,
     167,    40,   222,   197,   171,   172,    40,   274,   197,    75,
      76,    71,   197,   200,   181,     9,    85,    86,    87,   103,
      65,   105,   242,   198,   209,    40,   182,   183,    40,    74,
     197,    70,   116,   155,   156,   273,    70,     9,    40,    83,
      85,    35,   209,    37,    66,   167,    60,   222,   257,    72,
     172,    66,   121,    65,    26,    67,    65,   246,    67,   244,
     245,    66,    74,    65,    87,    67,    38,   242,   224,   278,
      84,   193,   228,   245,    61,    62,    74,   244,    54,    55,
      72,    79,    80,   268,   273,    59,    65,   272,    67,   245,
      40,    41,    42,    85,    81,    82,   268,    40,   182,   183,
     285,   257,    66,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    40,    66,    65,   272,    56,    57,    58,
      72,    66,   278,    63,    64,   281,    65,    72,    67,   285,
      69,    68,   288,    71,    72,    72,    71,    72,     4,    70,
     224,     7,     8,     9,   228,    86,    40,    13,    70,    15,
      66,    17,    71,    72,    72,    21,    70,    23,    24,    66,
      26,   245,    28,    29,    30,    86,    32,    71,    72,    35,
      36,    37,    38,   257,    40,    41,    42,   166,   167,    88,
      89,    72,   171,   172,    92,    93,    94,    95,   272,    66,
      56,    57,    90,    91,   278,    96,    97,   281,    68,    65,
      68,   285,    40,    85,   288,    66,    68,    73,    74,    75,
      76,    77,    78,     3,     4,    68,    40,     7,     8,     9,
      66,    68,    66,    13,    40,    15,    16,    17,    68,    68,
       0,    21,    22,    23,    24,    25,    26,    68,    28,    29,
      68,    31,    32,    68,    98,    35,    36,    37,    38,    68,
      40,   185,   100,   102,    99,   224,   229,    -1,   101,   155,
       3,     4,   209,   246,     7,     8,     9,   151,    -1,    -1,
      13,    -1,    15,    16,    17,    65,    66,    67,    21,    22,
      23,    24,    25,    26,    74,    28,    29,     9,    31,    32,
      -1,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,
      42,    -1,    65,    66,    67,    -1,    -1,    -1,     9,    -1,
      -1,    74,    -1,    -1,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    26,    68,    -1,    -1,    30,
      31,    73,    74,    75,    76,    77,    78,    38,    -1,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    26,    68,    -1,    -1,
      30,    -1,    73,    74,    75,    76,    77,    78,    38,    -1,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,     4,
      -1,    -1,     7,     8,     9,    -1,    -1,    -1,    13,    -1,
      15,    -1,    17,    -1,    -1,    -1,    21,    -1,    23,    24,
      -1,    26,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,    37,    38,    -1,    -1,     4,    -1,    -1,     7,
       8,     9,    -1,    -1,    -1,    13,    -1,    15,    -1,    17,
      -1,    -1,    -1,    21,    -1,    23,    24,    -1,    26,    -1,
      28,    29,    -1,    -1,    32,    -1,    71,    35,    36,    37,
      38,    -1,     3,     4,    -1,    -1,     7,     8,     9,    -1,
      -1,    -1,    13,    -1,    15,    16,    17,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    -1,
      31,    32,    -1,    71,    35,    36,    37,    38,    -1,    40,
      -1,     3,     4,    -1,    -1,     7,     8,     9,    -1,    -1,
      -1,    13,    -1,    15,    16,    17,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    66,    28,    29,    -1,    31,
      32,    30,    -1,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    65,    -1,    67,    -1,
      69,    70,    71,    30,    73,    74,    75,    76,    77,    78,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      67,    -1,    69,    70,    71,    30,    73,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    67,    -1,    69,    70,    30,    -1,    73,    74,
      75,    76,    77,    78,    -1,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    68,    40,    41,    42,    -1,    73,
      74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    30,    70,    -1,    -1,    73,    74,
      75,    76,    77,    78,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    -1,    30,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    40,    41,    42,    -1,    73,    74,    75,
      76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    30,    70,    -1,    -1,    73,    74,    75,    76,
      77,    78,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      40,    41,    42,    -1,    -1,    73,    74,    75,    76,    77,
      78,    -1,    -1,    -1,    -1,    -1,    56,    57,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    40,    41,
      42,    -1,    -1,    73,    74,    75,    76,    77,    78,    -1,
      -1,    -1,    -1,    -1,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,     3,     4,    -1,
      -1,     7,     8,     9,    -1,    -1,    -1,    13,    -1,    15,
      16,    17,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    -1,    28,    29,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    38,    -1,     3,     4,    -1,    43,     7,     8,
       9,    -1,    -1,    -1,    13,    -1,    15,    16,    17,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    -1,    28,
      29,    -1,    31,    32,    -1,    -1,    35,    36,    37,    38,
       4,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,    13,
      -1,    15,    -1,    17,    -1,    -1,    -1,    21,    -1,    23,
      24,    -1,    26,    -1,    28,    29,    -1,    -1,    32,    -1,
      -1,    35,    36,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,    42,    65,    89,    30,    56,    57,    65,
      73,    74,    75,    76,    77,    78,    89,    90,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   108,     0,    65,    92,    65,    92,    92,
       4,     7,     8,     9,    13,    15,    17,    21,    23,    24,
      26,    28,    29,    32,    35,    36,    37,    38,   121,   126,
     127,   128,   133,   134,   137,    56,    57,    58,    65,    67,
      69,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    86,   107,    92,    94,    74,    79,    80,    75,    76,
      54,    55,    61,    62,    81,    82,    63,    64,    73,    77,
      83,    59,    60,    84,    66,    72,   137,   137,    40,    70,
     133,   137,   133,    40,    70,    65,    67,    74,   118,   138,
     139,    66,    40,    40,    66,    91,   108,    40,   106,    94,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      98,    98,    99,   100,   101,   102,   103,   108,   106,    66,
      66,    70,    40,   135,   136,    70,   129,   130,   133,     3,
      16,    22,    25,    31,    66,   110,   111,   121,   122,   123,
     124,   125,   126,   138,    68,    74,   106,   118,   120,   121,
     139,    65,    67,    70,    94,    72,    66,    68,    85,   135,
      86,    71,    72,   129,    71,   130,    40,    65,    85,   117,
     118,   119,   131,   132,   117,   138,   110,   110,    66,    72,
     110,   110,    66,    68,    68,   118,   121,    66,   122,    68,
      74,   106,    67,    69,    70,   106,   112,   113,   114,   115,
     116,    91,   105,    71,    72,   105,   109,    71,   136,    71,
     117,   109,    85,   119,    65,    67,    72,    87,    43,   124,
      66,    68,    68,   109,    40,   113,    71,    72,   112,    86,
     116,    71,    66,   109,    40,    66,   122,   140,    31,    68,
      74,   106,   120,    65,   118,   132,    68,    71,    72,    71,
     112,   114,    66,    66,    72,   120,    68,    68,    31,    68,
      74,   106,    71,   112,    40,   106,   106,    68,    68,    68,
      68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    89,    89,    89,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    91,    91,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95,    95,    95,    96,    96,    96,    97,
      97,    97,    98,    98,    98,    98,    98,    99,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   108,   108,   105,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   111,
     111,   111,   112,   112,   112,   113,   113,   113,   113,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   118,   118,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   120,   120,   121,   121,   121,   122,   122,
     123,   123,   124,   124,   124,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   127,   127,   127,   128,   128,   129,   129,   130,   131,
     131,   132,   132,   132,   133,   133,   133,   133,   134,   134,
     134,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     138,   138,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   140,   140
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     4,     3,
       3,     3,     2,     2,     6,     7,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     1,     1,
       1,     0,     1,     3,     4,     1,     2,     3,     4,     2,
       1,     2,     3,     2,     2,     1,     1,     2,     2,     3,
       1,     3,     5,     4,     4,     6,     6,     5,     4,     3,
       4,     4,     3,     1,     2,     1,     1,     1,     1,     3,
       1,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     4,     2,     1,     1,     1,     2,     3,     1,
       3,     1,     2,     3,     2,     1,     2,     1,     4,     5,
       5,     6,     2,     1,     3,     1,     3,     1,     2,     1,
       1,     2,     3,     2,     3,     3,     4,     3,     4,     2,
       3,     3,     4,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 196 "syntax.yy" /* yacc.c:1646  */
    { (yyval) = &PrimaryExpressionNode(&IdentifierNode("ab")) }
#line 1761 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 197 "syntax.yy" /* yacc.c:1646  */
    { (yyval) = &PrimaryExpressionNode(&NumericLiteralNode("1")) }
#line 1767 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 198 "syntax.yy" /* yacc.c:1646  */
    { (yyval) = &PrimaryExpressionNode(&StrLiteralNode("String")) }
#line 1773 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 199 "syntax.yy" /* yacc.c:1646  */
    { (yyval) = &PrimaryExpressionNode(NULL) }
#line 1779 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 216 "syntax.yy" /* yacc.c:1646  */
    {(yyval) = vector<string>(){(yyvsp[0])}}
#line 1785 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 217 "syntax.yy" /* yacc.c:1646  */
    {(yyvsp[0]).push_back((yyvsp[-2]));(yyval) = (yyvsp[0])}
#line 1791 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 221 "syntax.yy" /* yacc.c:1646  */
    { (yyval) =  }
#line 1797 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 222 "syntax.yy" /* yacc.c:1646  */
    { (yyval) =  }
#line 1803 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 223 "syntax.yy" /* yacc.c:1646  */
    { (yyval) =  }
#line 1809 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 224 "syntax.yy" /* yacc.c:1646  */
    { (yyval) =  }
#line 1815 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 225 "syntax.yy" /* yacc.c:1646  */
    { (yyval) =  }
#line 1821 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 226 "syntax.yy" /* yacc.c:1646  */
    { (yyval) =  }
#line 1827 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 230 "syntax.yy" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0])}
#line 1833 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 231 "syntax.yy" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0])}
#line 1839 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 232 "syntax.yy" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0])}
#line 1845 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 233 "syntax.yy" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0])}
#line 1851 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 234 "syntax.yy" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0])}
#line 1857 "syntax.tab.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 235 "syntax.yy" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0])}
#line 1863 "syntax.tab.cc" /* yacc.c:1646  */
    break;


#line 1867 "syntax.tab.cc" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 626 "syntax.yy" /* yacc.c:1906  */


// Epilogue
