
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
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
/* "%code top" blocks.  */

/* Line 304 of lalr1.cc  */
#line 3 "syntax.yy"

    #include <vector>
    #include <string>
    #include <iostream> 
    #include "syntax.tab.cc"
    #include "stack.hh"

    using namespace std;

    class Node {
        private:
            string _name;
            string _value;
            vector<Node*> _children;

        public:
            Node(string name, vector<Node*> children) {
                _name = name;
                _value = "";
                _children = children;
            }

            Node(string name, string value) {
                _name = name;
                _value = value;
                _children = vector<Node*>();
            }

            // tab parameter is to show tree structure
            void printTree(int tab) {
                string valString = _value.size() > 0 ? "(" + _value + ")" : "";
                cout << _name + valString << endl;

                for (int i = 0; i < _children.size(); i++) {
                    for (int j = 0; j < tab; j++) { cout << "|\t"; }
                    _children[i]->printTree(tab + 1);
                }
            }
    };



/* Line 304 of lalr1.cc  */
#line 82 "bis_out.cpp"


/* First part of user declarations.  */


/* Line 311 of lalr1.cc  */
#line 89 "bis_out.cpp"


#include "bis_out.hpp"

/* User implementation prologue.  */


/* Line 317 of lalr1.cc  */
#line 98 "bis_out.cpp"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace yy {

/* Line 380 of lalr1.cc  */
#line 167 "bis_out.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {
  }

  parser::~parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
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
#endif

  int
  parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 678 of lalr1.cc  */
#line 220 "syntax.yy"
    { (yyval.Node*) = new Node("PRIMARY_EXPRESSION_NODE", vector<Node*>{ new Node("IDENTIFIER", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 223 "syntax.yy"
    { (yyval.Node*) = new Node("PRIMARY_EXPRESSION_NODE", vector<Node*>{ new Node("LITERAL", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 226 "syntax.yy"
    { (yyval.Node*) = new Node("PRIMARY_EXPRESSION_NODE", vector<Node*>{ new Node("STRING_LITERAL", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 229 "syntax.yy"
    { (yyval.Node*) = new Node("PRIMARY_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (2)].Node*) }); }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 235 "syntax.yy"
    { (yyval.Node*) = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 238 "syntax.yy"
    { (yyval.Node*) = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (1)].Node*), (yysemantic_stack_[(4) - (3)].Node*) }); }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 241 "syntax.yy"
    { (yyval.Node*) = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (1)].Node*), (yysemantic_stack_[(4) - (3)].Node*) }); }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 244 "syntax.yy"
    { (yyval.Node*) = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*) }); }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 247 "syntax.yy"
    { (yyval.Node*) = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("DOT", (yysemantic_stack_[(3) - (2)].std::string)), new Node("IDENTIFIER", (yysemantic_stack_[(3) - (3)].std::string)) }); }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 250 "syntax.yy"
    { (yyval.Node*) = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("PTR_OP", (yysemantic_stack_[(3) - (2)].std::string)), new Node("IDENTIFIER", (yysemantic_stack_[(3) - (3)].std::string)) }); }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 253 "syntax.yy"
    { (yyval.Node*) = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), new Node("INC_OP", (yysemantic_stack_[(2) - (2)].std::string)) }); }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 256 "syntax.yy"
    { (yyval.Node*) = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), new Node("DEC_OP", (yysemantic_stack_[(2) - (2)].std::string)) }); }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 259 "syntax.yy"
    { (yyval.Node*) = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(6) - (2)].Node*), (yysemantic_stack_[(6) - (4)].std::string) }); }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 262 "syntax.yy"
    { (yyval.Node*) = new Node("POSTFIX_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(7) - (2)].Node*), (yysemantic_stack_[(7) - (4)].std::string) }); }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 268 "syntax.yy"
    { (yyval.Node*) = new Node("ARGUMENT_EXPRESSION_LIST", vector<Node*>{ new Node("IDENTIFIER", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 271 "syntax.yy"
    { (yyval.Node*) = new Node("ARGUMENT_EXPRESSION_LIST", vector<Node*>{ new Node("IDENTIFIER", (yysemantic_stack_[(3) - (1)].std::string)) }); }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 277 "syntax.yy"
    { (yyval.Node*) = new Node("UNARY_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 280 "syntax.yy"
    { (yyval.Node*) = new Node("UNARY_EXPRESSION_NODE", vector<Node*>{ new Node("INC_OP", (yysemantic_stack_[(2) - (1)].std::string)), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 283 "syntax.yy"
    { (yyval.Node*) = new Node("UNARY_EXPRESSION_NODE", vector<Node*>{ new Node("DEC_OP", (yysemantic_stack_[(2) - (1)].std::string)), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 286 "syntax.yy"
    { (yyval.Node*) = new Node("UNARY_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 289 "syntax.yy"
    { (yyval.Node*) = new Node("UNARY_EXPRESSION_NODE", vector<Node*>{ new Node("SIZEOF", (yysemantic_stack_[(2) - (1)].std::string)), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 292 "syntax.yy"
    { (yyval.Node*) = new Node("UNARY_EXPRESSION_NODE", vector<Node*>{ new Node("SIZEOF", (yysemantic_stack_[(4) - (1)].std::string)), (yysemantic_stack_[(4) - (3)].Node*) }); }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 298 "syntax.yy"
    { (yyval.Node*) = new Node("UNARY_OPERATOR_NODE", vector<Node*>{ new Node("AMP", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 301 "syntax.yy"
    { (yyval.Node*) = new Node("UNARY_OPERATOR_NODE", vector<Node*>{ new Node("STAR", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 304 "syntax.yy"
    { (yyval.Node*) = new Node("UNARY_OPERATOR_NODE", vector<Node*>{ new Node("PLUS", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 307 "syntax.yy"
    { (yyval.Node*) = new Node("UNARY_OPERATOR_NODE", vector<Node*>{ new Node("MINUS", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 310 "syntax.yy"
    { (yyval.Node*) = new Node("UNARY_OPERATOR_NODE", vector<Node*>{ new Node("BIN_NOT_OP", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 313 "syntax.yy"
    { (yyval.Node*) = new Node("UNARY_OPERATOR_NODE", vector<Node*>{ new Node("LOG_NOT_OP", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 319 "syntax.yy"
    { (yyval.Node*) = new Node("CAST_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 322 "syntax.yy"
    { (yyval.Node*) = new Node("CAST_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (2)].Node*), (yysemantic_stack_[(4) - (4)].Node*) }); }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 328 "syntax.yy"
    { (yyval.Node*) = new Node("MULTIPLICATIVE_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 331 "syntax.yy"
    { (yyval.Node*) = new Node("MULTIPLICATIVE_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("STAR", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 334 "syntax.yy"
    { (yyval.Node*) = new Node("MULTIPLICATIVE_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("SLASH", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 337 "syntax.yy"
    { (yyval.Node*) = new Node("MULTIPLICATIVE_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("MOD_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 343 "syntax.yy"
    { (yyval.Node*) = new Node("ADDITIVE_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 346 "syntax.yy"
    { (yyval.Node*) = new Node("ADDITIVE_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("PLUS", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 349 "syntax.yy"
    { (yyval.Node*) = new Node("ADDITIVE_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("MINUS", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 355 "syntax.yy"
    { (yyval.Node*) = new Node("SHIFT_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 358 "syntax.yy"
    { (yyval.Node*) = new Node("SHIFT_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("LEFT_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 361 "syntax.yy"
    { (yyval.Node*) = new Node("SHIFT_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("RIGHT_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 367 "syntax.yy"
    { (yyval.Node*) = new Node("RELATIONAL_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 370 "syntax.yy"
    { (yyval.Node*) = new Node("RELATIONAL_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("L_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 373 "syntax.yy"
    { (yyval.Node*) = new Node("RELATIONAL_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("G_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 376 "syntax.yy"
    { (yyval.Node*) = new Node("RELATIONAL_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("LE_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 379 "syntax.yy"
    { (yyval.Node*) = new Node("RELATIONAL_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("GE_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 385 "syntax.yy"
    { (yyval.Node*) = new Node("EQUALITY_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 388 "syntax.yy"
    { (yyval.Node*) = new Node("EQUALITY_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("EQ_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 391 "syntax.yy"
    { (yyval.Node*) = new Node("EQUALITY_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("NE_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 397 "syntax.yy"
    { (yyval.Node*) = new Node("AND_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 400 "syntax.yy"
    { (yyval.Node*) = new Node("AND_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("AMP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 406 "syntax.yy"
    { (yyval.Node*) = new Node("EXCLUSIVE_OR_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 409 "syntax.yy"
    { (yyval.Node*) = new Node("EXCLUSIVE_OR_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("BIN_XOR_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 415 "syntax.yy"
    { (yyval.Node*) = new Node("INCLUSIVE_OR_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 418 "syntax.yy"
    { (yyval.Node*) = new Node("INCLUSIVE_OR_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("BIN_OR_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 424 "syntax.yy"
    { (yyval.Node*) = new Node("LOGICAL_AND_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 427 "syntax.yy"
    { (yyval.Node*) = new Node("LOGICAL_AND_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("AND_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 433 "syntax.yy"
    { (yyval.Node*) = new Node("LOGICAL_OR_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 436 "syntax.yy"
    { (yyval.Node*) = new Node("LOGICAL_OR_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("OR_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 442 "syntax.yy"
    { (yyval.Node*) = new Node("CONDITIONAL_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 445 "syntax.yy"
    { (yyval.Node*) = new Node("CONDITIONAL_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(5) - (1)].Node*), new Node("TERNARY_OP", (yysemantic_stack_[(5) - (2)].std::string)), (yysemantic_stack_[(5) - (3)].Node*), (yysemantic_stack_[(5) - (5)].Node*) }); }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 451 "syntax.yy"
    { (yyval.Node*) = new Node("ASSIGNMENT_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 454 "syntax.yy"
    { (yyval.Node*) = new Node("ASSIGNMENT_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), (yysemantic_stack_[(3) - (2)].Node*), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 460 "syntax.yy"
    { (yyval.Node*) = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("ASSIGN_OP", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 463 "syntax.yy"
    { (yyval.Node*) = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("MUL_ASSIGN", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 466 "syntax.yy"
    { (yyval.Node*) = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("DIV_ASSIGN", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 469 "syntax.yy"
    { (yyval.Node*) = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("MOD_ASSIGN", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 472 "syntax.yy"
    { (yyval.Node*) = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("ADD_ASSIGN", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 475 "syntax.yy"
    { (yyval.Node*) = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("SUB_ASSIGN", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 478 "syntax.yy"
    { (yyval.Node*) = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("LEFT_ASSIGN", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 481 "syntax.yy"
    { (yyval.Node*) = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("RIGHT_ASSIGN", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 484 "syntax.yy"
    { (yyval.Node*) = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("AND_ASSIGN", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 487 "syntax.yy"
    { (yyval.Node*) = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("XOR_ASSIGN", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 490 "syntax.yy"
    { (yyval.Node*) = new Node("ASSIGNMENT_OPERATOR_NODE", vector<Node*>{ new Node("OR_ASSIGN", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 496 "syntax.yy"
    { (yyval.Node*) = new Node("EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 499 "syntax.yy"
    { (yyval.Node*) = new Node("EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), (yysemantic_stack_[(3) - (2)].std::string) }); }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 505 "syntax.yy"
    { (yyval.Node*) = new Node("CONSTANT_EXPRESSION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 511 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATION_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*) }); }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 514 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), (yysemantic_stack_[(3) - (2)].Node*) }); }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 520 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 523 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 526 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 529 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 532 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 535 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 538 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 541 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATION_SPECIFIERS_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 547 "syntax.yy"
    { (yyval.Node*) = new Node("STORAGE_CLASS_SPECIFIER_NODE", vector<Node*>{ new Node("EXTERN", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 550 "syntax.yy"
    { (yyval.Node*) = new Node("STORAGE_CLASS_SPECIFIER_NODE", vector<Node*>{ new Node("STATIC", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 553 "syntax.yy"
    { (yyval.Node*) = new Node("STORAGE_CLASS_SPECIFIER_NODE", vector<Node*>{ new Node("AUTO", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 556 "syntax.yy"
    { (yyval.Node*) = new Node("STORAGE_CLASS_SPECIFIER_NODE", vector<Node*>{ new Node("REGISTER", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 562 "syntax.yy"
    { (yyval.Node*) = new Node("INIT_DECLARATOR_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 565 "syntax.yy"
    { (yyval.Node*) = new Node("INIT_DECLARATOR_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 571 "syntax.yy"
    { (yyval.Node*) = new Node("INIT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 574 "syntax.yy"
    { (yyval.Node*) = new Node("INIT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("ASSIGN_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 580 "syntax.yy"
    { (yyval.Node*) = new Node("INITIALIZER_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 583 "syntax.yy"
    { (yyval.Node*) = new Node("INITIALIZER_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (2)].Node*) }); }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 586 "syntax.yy"
    { (yyval.Node*) = new Node("INITIALIZER_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (2)].Node*) }); }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 592 "syntax.yy"
    { (yyval.Node*) = new Node("INITIALIZER_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 595 "syntax.yy"
    { (yyval.Node*) = new Node("INITIALIZER_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 598 "syntax.yy"
    { (yyval.Node*) = new Node("INITIALIZER_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 601 "syntax.yy"
    { (yyval.Node*) = new Node("INITIALIZER_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (1)].Node*), (yysemantic_stack_[(4) - (3)].Node*), (yysemantic_stack_[(4) - (4)].Node*) }); }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 607 "syntax.yy"
    { (yyval.Node*) = new Node("DESIGNATION_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), new Node("ASSIGN_OP", (yysemantic_stack_[(2) - (2)].std::string)) }); }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 613 "syntax.yy"
    { (yyval.Node*) = new Node("DESIGNATOR_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 616 "syntax.yy"
    { (yyval.Node*) = new Node("DESIGNATOR_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 622 "syntax.yy"
    { (yyval.Node*) = new Node("DESIGNATOR_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (2)].Node*) }); }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 625 "syntax.yy"
    { (yyval.Node*) = new Node("DESIGNATOR_NODE", vector<Node*>{ new Node("IDENTIFIER", (yysemantic_stack_[(2) - (2)].std::string)) }); }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 631 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 634 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 640 "syntax.yy"
    { (yyval.Node*) = new Node("POINTER_NODE", vector<Node*>{ new Node("STAR", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 643 "syntax.yy"
    { (yyval.Node*) = new Node("POINTER_NODE", vector<Node*>{ new Node("STAR", (yysemantic_stack_[(2) - (1)].std::string)), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 646 "syntax.yy"
    { (yyval.Node*) = new Node("POINTER_NODE", vector<Node*>{ new Node("STAR", (yysemantic_stack_[(2) - (1)].std::string)), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 649 "syntax.yy"
    { (yyval.Node*) = new Node("POINTER_NODE", vector<Node*>{ new Node("STAR", (yysemantic_stack_[(3) - (1)].std::string)), (yysemantic_stack_[(3) - (2)].Node*), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 655 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ new Node("IDENTIFIER", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 658 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (2)].Node*) }); }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 661 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(5) - (1)].Node*), (yysemantic_stack_[(5) - (3)].Node*), (yysemantic_stack_[(5) - (4)].Node*) }); }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 664 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (1)].Node*), (yysemantic_stack_[(4) - (3)].Node*) }); }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 667 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (1)].Node*), (yysemantic_stack_[(4) - (3)].Node*) }); }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 670 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(6) - (1)].Node*), new Node("STATIC", (yysemantic_stack_[(6) - (3)].std::string)), (yysemantic_stack_[(6) - (4)].Node*), (yysemantic_stack_[(6) - (5)].Node*) }); }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 673 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(6) - (1)].Node*), (yysemantic_stack_[(6) - (3)].Node*), new Node("STATIC", (yysemantic_stack_[(6) - (4)].std::string)), (yysemantic_stack_[(6) - (5)].Node*) }); }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 676 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(5) - (1)].Node*), (yysemantic_stack_[(5) - (3)].Node*), new Node("STAR", (yysemantic_stack_[(5) - (4)].std::string)) }); }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 679 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (1)].Node*), new Node("STAR", (yysemantic_stack_[(4) - (3)].std::string)) }); }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 682 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*) }); }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 685 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (1)].Node*), (yysemantic_stack_[(4) - (3)].Node*) }); }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 688 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (1)].Node*), (yysemantic_stack_[(4) - (3)].Node*) }); }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 691 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*) }); }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 697 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_QUALIFIER_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 700 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_QUALIFIER_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 706 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_QUALIFIER_NODE", vector<Node*>{ new Node("CONST", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 709 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_QUALIFIER_NODE", vector<Node*>{ new Node("RESTRICT", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 712 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_QUALIFIER_NODE", vector<Node*>{ new Node("VOLATILE", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 718 "syntax.yy"
    { (yyval.Node*) = new Node("PARAMETER_TYPE_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 721 "syntax.yy"
    { (yyval.Node*) = new Node("PARAMETER_TYPE_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("ELLIPSIS", (yysemantic_stack_[(3) - (3)].std::string)) }); }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 727 "syntax.yy"
    { (yyval.Node*) = new Node("PARAMETER_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*) }); }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 730 "syntax.yy"
    { (yyval.Node*) = new Node("PARAMETER_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 736 "syntax.yy"
    { (yyval.Node*) = new Node("PARAMETER_DECLARATION_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 739 "syntax.yy"
    { (yyval.Node*) = new Node("PARAMETER_DECLARATION_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 742 "syntax.yy"
    { (yyval.Node*) = new Node("PARAMETER_DECLARATION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 748 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_QUALIFIER_NODE", vector<Node*>{ new Node("INLINE", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 754 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("VOID", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 757 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("CHAR", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 760 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("SHORT", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 763 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("INT", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 766 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("LONG", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 769 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("FLOAT", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 772 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("DOUBLE", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 775 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("SIGNED", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 778 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("UNSIGNED", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 781 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("BOOL", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 784 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("COMPLEX", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 787 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ new Node("IMAGINARY", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 790 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 793 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 796 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_SPECIFIER_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 802 "syntax.yy"
    { (yyval.Node*) = new Node("STRUCT_OR_UNION_SPECIFIER_NODE", vector<Node*>{ (yysemantic_stack_[(5) - (1)].Node*), new Node("IDENTIFIER", (yysemantic_stack_[(5) - (2)].std::string)), (yysemantic_stack_[(5) - (4)].Node*) }); }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 805 "syntax.yy"
    { (yyval.Node*) = new Node("STRUCT_OR_UNION_SPECIFIER_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (1)].Node*), (yysemantic_stack_[(4) - (3)].Node*) }); }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 808 "syntax.yy"
    { (yyval.Node*) = new Node("STRUCT_OR_UNION_SPECIFIER_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), new Node("IDENTIFIER", (yysemantic_stack_[(2) - (2)].std::string)) }); }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 814 "syntax.yy"
    { (yyval.Node*) = new Node("STRUCT_OR_UNION_NODE", vector<Node*>{ new Node("STRUCT", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 817 "syntax.yy"
    { (yyval.Node*) = new Node("STRUCT_OR_UNION_NODE", vector<Node*>{ new Node("UNION", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 823 "syntax.yy"
    { (yyval.Node*) = new Node("STRUCT_DECLARATION_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 826 "syntax.yy"
    { (yyval.Node*) = new Node("STRUCT_DECLARATION_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 832 "syntax.yy"
    { (yyval.Node*) = new Node("STRUCT_DECLARATION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), (yysemantic_stack_[(3) - (2)].Node*) }); }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 838 "syntax.yy"
    { (yyval.Node*) = new Node("STRUCT_DECLARATOR_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 841 "syntax.yy"
    { (yyval.Node*) = new Node("STRUCT_DECLARATOR_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 847 "syntax.yy"
    { (yyval.Node*) = new Node("STRUCT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 850 "syntax.yy"
    { (yyval.Node*) = new Node("STRUCT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 853 "syntax.yy"
    { (yyval.Node*) = new Node("STRUCT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 859 "syntax.yy"
    { (yyval.Node*) = new Node("SPECIFIER_QUALIFIER_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 862 "syntax.yy"
    { (yyval.Node*) = new Node("SPECIFIER_QUALIFIER_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 865 "syntax.yy"
    { (yyval.Node*) = new Node("SPECIFIER_QUALIFIER_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 868 "syntax.yy"
    { (yyval.Node*) = new Node("SPECIFIER_QUALIFIER_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 874 "syntax.yy"
    { (yyval.Node*) = new Node("ENUM_SPECIFIER_NODE", vector<Node*>{ new Node("ENUM", (yysemantic_stack_[(4) - (1)].std::string)), (yysemantic_stack_[(4) - (3)].Node*) }); }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 877 "syntax.yy"
    { (yyval.Node*) = new Node("ENUM_SPECIFIER_NODE", vector<Node*>{ new Node("ENUM", (yysemantic_stack_[(5) - (1)].std::string)), new Node("IDENTIFIER", (yysemantic_stack_[(5) - (2)].std::string)), (yysemantic_stack_[(5) - (4)].Node*) }); }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 880 "syntax.yy"
    { (yyval.Node*) = new Node("ENUM_SPECIFIER_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (2)].Node*) }); }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 883 "syntax.yy"
    { (yyval.Node*) = new Node("ENUM_SPECIFIER_NODE", vector<Node*>{ new Node("ENUM", (yysemantic_stack_[(6) - (1)].std::string)), new Node("IDENTIFIER", (yysemantic_stack_[(6) - (2)].std::string)), (yysemantic_stack_[(6) - (4)].Node*) }); }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 886 "syntax.yy"
    { (yyval.Node*) = new Node("ENUM_SPECIFIER_NODE", vector<Node*>{ new Node("ENUM", (yysemantic_stack_[(2) - (1)].std::string)), new Node("IDENTIFIER", (yysemantic_stack_[(2) - (2)].std::string)) }); }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 892 "syntax.yy"
    { (yyval.Node*) = new Node("ENUMERATOR_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 895 "syntax.yy"
    { (yyval.Node*) = new Node("ENUMERATOR_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 901 "syntax.yy"
    { (yyval.Node*) = new Node("ENUMERATOR_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].std::string) }); }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 904 "syntax.yy"
    { (yyval.Node*) = new Node("ENUMERATOR_NODE", vector<Node*>{ new Node("IDENTIFIER", (yysemantic_stack_[(3) - (1)].std::string)), new Node("ASSIGN_OP", (yysemantic_stack_[(3) - (2)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 910 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_NAME_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 913 "syntax.yy"
    { (yyval.Node*) = new Node("TYPE_NAME_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 919 "syntax.yy"
    { (yyval.Node*) = new Node("ABSTRACT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 922 "syntax.yy"
    { (yyval.Node*) = new Node("ABSTRACT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 925 "syntax.yy"
    { (yyval.Node*) = new Node("ABSTRACT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 931 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (2)].Node*) }); }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 934 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{}); }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 937 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (2)].Node*) }); }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 940 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*) }); }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 943 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (1)].Node*), (yysemantic_stack_[(4) - (3)].Node*) }); }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 946 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ new Node("STAR", (yysemantic_stack_[(3) - (2)].std::string)) }); }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 949 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (1)].Node*), new Node("STAR", (yysemantic_stack_[(4) - (3)].std::string)) }); }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 952 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{}); }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 955 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (2)].Node*) }); }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 958 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*) }); }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 961 "syntax.yy"
    { (yyval.Node*) = new Node("DIRECT_ABSTRACT_DECLARATOR_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (1)].Node*), (yysemantic_stack_[(4) - (3)].Node*) }); }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 967 "syntax.yy"
    { (yyval.Node*) = new Node("STATEMENT_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 970 "syntax.yy"
    { (yyval.Node*) = new Node("STATEMENT_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 973 "syntax.yy"
    { (yyval.Node*) = new Node("STATEMENT_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 976 "syntax.yy"
    { (yyval.Node*) = new Node("STATEMENT_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 979 "syntax.yy"
    { (yyval.Node*) = new Node("STATEMENT_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 982 "syntax.yy"
    { (yyval.Node*) = new Node("STATEMENT_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 988 "syntax.yy"
    { (yyval.Node*) = new Node("LABELED_STATEMENT_NODE", vector<Node*>{ new Node("IDENTIFIER", (yysemantic_stack_[(3) - (1)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 991 "syntax.yy"
    { (yyval.Node*) = new Node("LABELED_STATEMENT_NODE", vector<Node*>{ new Node("CASER", (yysemantic_stack_[(4) - (1)].std::string)), (yysemantic_stack_[(4) - (2)].Node*), (yysemantic_stack_[(4) - (4)].Node*) }); }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 994 "syntax.yy"
    { (yyval.Node*) = new Node("LABELED_STATEMENT_NODE", vector<Node*>{ new Node("DEFAULT", (yysemantic_stack_[(3) - (1)].std::string)), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1000 "syntax.yy"
    { (yyval.Node*) = new Node("COMPOUND_STATEMENT_NODE", vector<Node*>{}); }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1003 "syntax.yy"
    { (yyval.Node*) = new Node("COMPOUND_STATEMENT_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (2)].Node*) }); }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1009 "syntax.yy"
    { (yyval.Node*) = new Node("BLOCK_ITEM_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1012 "syntax.yy"
    { (yyval.Node*) = new Node("BLOCK_ITEM_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1018 "syntax.yy"
    { (yyval.Node*) = new Node("BLOCK_ITEM_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1021 "syntax.yy"
    { (yyval.Node*) = new Node("BLOCK_ITEM_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1027 "syntax.yy"
    { (yyval.Node*) = new Node("EXPRESSION_STATEMENT_NODE", vector<Node*>{}); }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1030 "syntax.yy"
    { (yyval.Node*) = new Node("EXPRESSION_STATEMENT_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*) }); }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1036 "syntax.yy"
    { (yyval.Node*) = new Node("SELECTION_STATEMENT_NODE", vector<Node*>{ new Node("IF", (yysemantic_stack_[(5) - (1)].std::string)), (yysemantic_stack_[(5) - (3)].Node*), (yysemantic_stack_[(5) - (5)].Node*) }); }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1039 "syntax.yy"
    { (yyval.Node*) = new Node("SELECTION_STATEMENT_NODE", vector<Node*>{ new Node("IF", (yysemantic_stack_[(7) - (1)].std::string)), (yysemantic_stack_[(7) - (3)].Node*), (yysemantic_stack_[(7) - (5)].Node*), new Node("ELSE", (yysemantic_stack_[(7) - (6)].std::string)), (yysemantic_stack_[(7) - (7)].Node*) }); }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1042 "syntax.yy"
    { (yyval.Node*) = new Node("SELECTION_STATEMENT_NODE", vector<Node*>{ new Node("SWITCH", (yysemantic_stack_[(5) - (1)].std::string)), (yysemantic_stack_[(5) - (3)].Node*), (yysemantic_stack_[(5) - (5)].Node*) }); }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1048 "syntax.yy"
    { (yyval.Node*) = new Node("ITERATION_STATEMENT_NODE", vector<Node*>{ new Node("WHILE", (yysemantic_stack_[(5) - (1)].std::string)), (yysemantic_stack_[(5) - (3)].Node*), (yysemantic_stack_[(5) - (5)].Node*) }); }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1051 "syntax.yy"
    { (yyval.Node*) = new Node("ITERATION_STATEMENT_NODE", vector<Node*>{ new Node("DO", (yysemantic_stack_[(7) - (1)].std::string)), (yysemantic_stack_[(7) - (2)].Node*), new Node("WHILE", (yysemantic_stack_[(7) - (3)].std::string)), (yysemantic_stack_[(7) - (5)].Node*) }); }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1054 "syntax.yy"
    { (yyval.Node*) = new Node("ITERATION_STATEMENT_NODE", vector<Node*>{ new Node("FOR", (yysemantic_stack_[(6) - (1)].std::string)), (yysemantic_stack_[(6) - (3)].Node*), (yysemantic_stack_[(6) - (4)].Node*), (yysemantic_stack_[(6) - (6)].Node*) }); }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1057 "syntax.yy"
    { (yyval.Node*) = new Node("ITERATION_STATEMENT_NODE", vector<Node*>{ new Node("FOR", (yysemantic_stack_[(7) - (1)].std::string)), (yysemantic_stack_[(7) - (3)].Node*), (yysemantic_stack_[(7) - (4)].Node*), (yysemantic_stack_[(7) - (5)].Node*), (yysemantic_stack_[(7) - (7)].Node*) }); }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1060 "syntax.yy"
    { (yyval.Node*) = new Node("ITERATION_STATEMENT_NODE", vector<Node*>{ new Node("FOR", (yysemantic_stack_[(6) - (1)].std::string)), (yysemantic_stack_[(6) - (3)].Node*), (yysemantic_stack_[(6) - (4)].Node*), (yysemantic_stack_[(6) - (6)].Node*) }); }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1063 "syntax.yy"
    { (yyval.Node*) = new Node("ITERATION_STATEMENT_NODE", vector<Node*>{ new Node("FOR", (yysemantic_stack_[(7) - (1)].std::string)), (yysemantic_stack_[(7) - (3)].Node*), (yysemantic_stack_[(7) - (4)].Node*), (yysemantic_stack_[(7) - (5)].Node*), (yysemantic_stack_[(7) - (7)].Node*) }); }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1069 "syntax.yy"
    { (yyval.Node*) = new Node("JUMP_STATEMENT_NODE", vector<Node*>{ new Node("GOTO", (yysemantic_stack_[(3) - (1)].std::string)), new Node("IDENTIFIER", (yysemantic_stack_[(3) - (2)].std::string)) }); }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1072 "syntax.yy"
    { (yyval.Node*) = new Node("JUMP_STATEMENT_NODE", vector<Node*>{ new Node("CONTINUE", (yysemantic_stack_[(2) - (1)].std::string)) }); }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1075 "syntax.yy"
    { (yyval.Node*) = new Node("JUMP_STATEMENT_NODE", vector<Node*>{ new Node("BREAK", (yysemantic_stack_[(2) - (1)].std::string)) }); }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1078 "syntax.yy"
    { (yyval.Node*) = new Node("JUMP_STATEMENT_NODE", vector<Node*>{ new Node("RETURN", (yysemantic_stack_[(2) - (1)].std::string)) }); }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1081 "syntax.yy"
    { (yyval.Node*) = new Node("JUMP_STATEMENT_NODE", vector<Node*>{ new Node("RETURN", (yysemantic_stack_[(3) - (1)].std::string)), (yysemantic_stack_[(3) - (2)].Node*) }); }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1087 "syntax.yy"
    { (yyval.Node*) = new Node("TRANSLATION_UNIT_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1090 "syntax.yy"
    { (yyval.Node*) = new Node("TRANSLATION_UNIT_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1096 "syntax.yy"
    { (yyval.Node*) = new Node("EXTERNAL_DECLARATION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1099 "syntax.yy"
    { (yyval.Node*) = new Node("EXTERNAL_DECLARATION_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1105 "syntax.yy"
    { (yyval.Node*) = new Node("FUNCTION_DEFINITION_NODE", vector<Node*>{ (yysemantic_stack_[(4) - (1)].Node*), (yysemantic_stack_[(4) - (2)].Node*), (yysemantic_stack_[(4) - (3)].Node*), (yysemantic_stack_[(4) - (4)].Node*) }); }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1108 "syntax.yy"
    { (yyval.Node*) = new Node("FUNCTION_DEFINITION_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), (yysemantic_stack_[(3) - (2)].Node*), (yysemantic_stack_[(3) - (3)].Node*) }); }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1114 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATION_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(1) - (1)].Node*) }); }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1117 "syntax.yy"
    { (yyval.Node*) = new Node("DECLARATION_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*) }); }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1123 "syntax.yy"
    { (yyval.Node*) = new Node("IDENTIFIER_LIST_NODE", vector<Node*>{ new Node("IDENTIFIER", (yysemantic_stack_[(1) - (1)].std::string)) }); }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 1126 "syntax.yy"
    { (yyval.Node*) = new Node("IDENTIFIER_LIST_NODE", vector<Node*>{ (yysemantic_stack_[(3) - (1)].Node*), new Node("IDENTIFIER", (yysemantic_stack_[(3) - (3)].std::string)) }); }
    break;



/* Line 678 of lalr1.cc  */
#line 2108 "bis_out.cpp"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
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
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (int yystate)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int parser::yypact_ninf_ = -337;
  const short int
  parser::yypact_[] =
  {
      1496,  -337,  -337,  -337,  -337,  -337,  -337,   -19,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,    40,  -337,    83,  1496,  1496,  1496,
    1496,  -337,    32,    31,  -337,  -337,  1375,  -337,  -337,    35,
      40,    38,    51,  -337,  -337,  -337,    20,    29,   155,  -337,
    1336,    28,   110,  -337,  -337,    31,  -337,  -337,    31,    73,
    1644,   966,   270,   168,  -337,   193,  -337,  -337,    40,   109,
    1223,   -13,   113,  -337,    29,  -337,  -337,    20,   368,  1034,
    -337,    83,  -337,  1533,   110,  1412,   739,  1644,  1644,  1644,
    1568,  -337,    53,  -337,    99,   141,   108,   163,   165,  1243,
    -337,  -337,  -337,   648,  -337,  -337,  -337,  -337,  -337,  -337,
     176,  1275,  1275,  -337,    82,   264,  1223,  -337,   216,   224,
     212,    24,   259,   167,   177,   170,   175,   -22,  -337,   194,
     193,  1459,  1066,   139,    40,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,   209,   223,  1223,   240,
     225,   703,   260,   273,   275,  1086,   285,   297,   102,  -337,
    -337,  -337,   309,  -337,  -337,  -337,  -337,   447,  -337,  -337,
    -337,  -337,  -337,  1014,  -337,  -337,  -337,  -337,  -337,  -337,
     257,    90,    37,  -337,   318,   330,   783,  1606,  -337,  -337,
    1223,   917,   357,    92,   311,  -337,  -337,  -337,  -337,   880,
    -337,  -337,   648,  -337,   146,   316,  -337,   648,  -337,  -337,
     -12,   372,  1223,  -337,  -337,   373,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  1223,  -337,  1223,
    1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,
    1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  -337,  -337,
     369,  -337,   363,   367,    11,  -337,  -337,   375,  -337,   703,
     376,   526,   389,   587,   386,  1223,  -337,   313,  1223,  1223,
     703,  -337,  1223,  -337,  -337,   390,  1223,  -337,   142,  1034,
     189,  -337,  -337,   391,  -337,   819,  -337,  -337,  1223,  -337,
     380,   381,  -337,  -337,  1223,  -337,   -20,  -337,  -337,   387,
    -337,  1119,   388,   392,  -337,   393,  -337,   105,  -337,  -337,
    -337,  -337,  -337,   216,   216,   224,   224,   212,   212,   212,
     212,    24,    24,   259,   167,   177,   170,   314,   175,  -337,
    -337,  -337,  -337,   703,  -337,   395,  1139,  1139,  -337,   171,
    -337,   220,   227,  -337,  -337,  -337,   385,   238,  -337,  -337,
    -337,  -337,  -337,   394,   409,  -337,  -337,  -337,  -337,   396,
    1014,  -337,   396,   398,  -337,  -337,  1223,  -337,  1223,  1171,
    1191,   703,   703,   703,  -337,  -337,  -337,  1034,  -337,  -337,
     147,  -337,  -337,   258,   703,   276,   703,   298,   425,  -337,
    -337,  -337,   978,  -337,   399,  -337,   703,  -337,   703,   703,
    -337,  -337,  -337,  -337,  -337
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  parser::yydefact_[] =
  {
         0,    90,   149,   141,   150,   129,   146,     0,    88,   145,
     151,   139,   143,   144,    91,   130,   142,   147,    89,   158,
     159,   148,   140,   131,     0,   231,     0,    80,    84,    86,
      82,   152,     0,   181,   153,   154,     0,   228,   230,   176,
       0,   179,     0,   177,   114,    78,     0,   110,     0,    92,
      94,     0,   109,    81,    85,   170,    87,    83,   168,   157,
       0,     0,     0,   183,   182,   184,     1,   229,     0,     0,
       0,     0,     0,   112,   111,   127,    79,     0,     0,     0,
     234,     0,   233,     0,   108,     0,     0,     0,   171,   169,
       0,   160,   181,   193,   138,     0,   132,     0,     0,     0,
       2,     3,     4,     0,   187,    24,    29,    28,    27,    26,
      25,     0,     0,     6,    18,    30,     0,    32,    36,    39,
      42,    47,    50,    52,    54,    56,    58,    60,    62,     0,
     185,     0,     0,     0,     0,   172,    25,    30,    77,   180,
     174,   178,   115,   113,   128,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,   212,
     206,    75,     0,   210,   211,   197,   198,     0,   208,   199,
     200,   201,   202,     0,    96,    95,   235,   232,   236,   126,
       0,     0,     0,   123,    25,     0,     0,     0,   156,   161,
       0,     0,   165,   183,     0,   163,   136,   137,   194,     0,
     134,   186,     0,    22,     0,   154,   191,     0,    19,    20,
       0,     0,     0,    12,    13,     0,    64,    71,    70,    68,
      69,    65,    66,    67,    72,    73,    74,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   188,   195,
       0,   189,    25,     0,     0,   173,   225,     0,   224,     0,
       2,     0,     0,     0,     0,     0,   226,     0,     0,     0,
       0,   213,     0,   207,   209,     0,     0,    99,     0,     0,
       0,   104,   124,     0,   125,     0,   122,   118,     0,   117,
      25,     0,   155,   166,     0,   162,     0,   133,   135,   154,
       5,     0,   154,    16,     9,     0,    10,     0,    11,    63,
      33,    34,    35,    38,    37,    41,    40,    44,    43,    45,
      46,    48,    49,    51,    53,    55,    57,     0,    59,   196,
     192,   190,   175,     0,   205,     0,     0,     0,   223,     0,
     227,     0,     0,   203,    76,   107,     0,     0,    97,   100,
     103,   105,   237,     0,     0,   121,   116,   167,   164,    23,
       0,    31,     0,     0,     8,     7,     0,   204,     0,     0,
       0,     0,     0,     0,   106,    98,   101,     0,   119,   120,
       0,    17,    61,     0,     0,     0,     0,     0,   214,   216,
     217,   102,     0,    14,     0,   221,     0,   219,     0,     0,
      15,   218,   222,   220,   215
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
      -337,  -337,  -337,    80,   -63,  -337,  -114,   129,   131,    17,
     127,   202,   248,   237,   247,   251,  -337,   -65,   -62,  -337,
     -61,  -140,     9,     4,  -337,  -337,   417,   -78,   135,  -336,
    -337,   219,   -23,   169,   -45,   -64,   162,   -67,  -337,   301,
    -337,    18,  -337,  -337,   420,   -74,  -337,   213,    13,  -337,
     -11,   -58,   -88,   -47,   -53,  -139,  -337,   -31,  -337,   341,
    -240,  -337,  -337,  -337,  -337,   474,  -337,  -337,  -337
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
  {
        -1,   113,   114,   305,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   161,   227,
     162,   139,   163,    81,    27,    48,    49,   277,   278,   279,
     280,   281,    72,    51,    52,    74,    28,    95,    96,    97,
      29,    30,    31,    32,    90,    91,   194,   195,    33,    34,
      42,    43,    35,    64,    65,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    36,    37,    38,    83,   181
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char parser::yytable_ninf_ = -1;
  const unsigned short int
  parser::yytable_[] =
  {
       129,   175,   228,    50,    26,   138,    84,   137,   257,    25,
     130,   377,   262,   141,    98,   205,   189,   174,   180,    82,
      44,    39,   186,   337,   185,   190,    46,    41,   303,    69,
      40,    53,    54,    56,    57,   304,   203,   140,     5,    47,
      26,    55,   204,    58,   246,    25,     5,   197,   208,   209,
     293,    41,   177,   137,   146,    15,   377,   133,   146,    80,
      44,   332,   247,    15,   250,    94,    46,    23,    44,   192,
     253,   196,    59,    92,    46,    23,   141,    61,    89,    47,
      41,    60,    62,   138,    68,   137,   236,   237,    47,    94,
      47,    70,   176,    44,   267,    71,   369,   370,   190,   191,
      92,    55,    58,    92,    62,    89,    89,    89,    89,   238,
     239,   174,    47,   189,   299,   310,   311,   312,   285,   302,
     334,    89,    87,    44,   291,   138,    45,   137,   210,    46,
     211,   343,    44,   212,   283,    94,   346,   284,   191,    44,
     130,   204,    47,    62,    98,   191,   204,   270,    84,   272,
      62,   307,   199,   134,   357,    70,    85,   365,    47,   135,
     142,    86,   213,   214,   215,   309,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   254,   137,   327,   347,   361,   198,   255,
     272,   392,   348,   300,   367,    94,   141,   393,    76,    77,
      92,   349,    63,    94,   339,    89,   200,   341,   342,    75,
     344,   138,   201,   137,    61,   272,    73,   174,   371,    62,
      89,   242,    88,   353,    63,    89,   354,    63,   206,   138,
      63,   137,   388,   389,   390,   244,   144,   275,   137,   131,
     276,   243,   350,   143,   132,   395,   248,   397,    75,    88,
      88,    88,    88,   317,   318,   319,   320,   402,   245,   403,
     404,   193,    79,   193,   272,    88,   256,   372,    99,   376,
     259,   272,   336,   192,   373,   229,   230,   231,   100,   101,
     102,   232,   233,   258,   103,   174,   275,   173,   375,   276,
     234,   235,   105,   106,   107,   108,   109,   136,   174,   391,
      99,   382,   272,   137,   282,   394,   263,   383,   385,   387,
     100,   101,   102,   264,   376,   174,   103,   216,   111,   112,
     272,   265,   104,   396,   105,   106,   107,   108,   109,   110,
     174,   268,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   272,   269,    75,   398,   240,   241,   144,    88,
     111,   112,   271,   272,   295,   296,   340,   272,   272,   366,
     193,   313,   314,   301,    88,   315,   316,   321,   322,    88,
     286,     1,     2,   147,   148,     3,     4,     5,   149,   150,
     151,     6,   287,     7,     8,     9,   152,   153,   154,    10,
      11,    12,    13,    14,    15,   155,    16,    17,    99,    18,
      19,   156,   294,    20,    21,    22,    23,   157,   158,   101,
     102,   159,   306,   308,   103,   330,   329,    78,   160,   331,
     333,   270,   105,   106,   107,   108,   109,   136,   335,   338,
     345,   352,   355,   356,   359,   362,   363,   374,   303,   399,
     364,   368,   401,   381,   323,   360,   378,   144,   111,   112,
       1,     2,   147,   148,     3,     4,     5,   149,   150,   151,
       6,   379,     7,     8,     9,   152,   153,   154,    10,    11,
      12,    13,    14,    15,   155,    16,    17,    99,    18,    19,
     156,   325,    20,    21,    22,    23,   157,   260,   101,   102,
     159,   324,   326,   103,   145,   380,    78,   273,   328,   351,
     298,   105,   106,   107,   108,   109,   136,   187,   274,   358,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   111,   112,     1,
       2,   147,   148,     3,     4,     5,   149,   150,   151,     6,
       0,     7,     8,     9,   152,   153,   154,    10,    11,    12,
      13,    14,    15,   155,    16,    17,    99,    18,    19,   156,
       0,    20,    21,    22,    23,   157,   260,   101,   102,   159,
       0,     0,   103,     0,     0,    78,   160,     0,     0,     0,
     105,   106,   107,   108,   109,   136,     0,     0,     0,     0,
       1,     2,     0,     0,     3,     4,     5,     0,     0,     0,
       6,     0,     7,     8,     9,     0,   111,   112,    10,    11,
      12,    13,    14,    15,     0,    16,    17,    99,    18,    19,
       0,     0,    20,    21,    22,    23,     0,   100,   101,   102,
     159,     0,     0,   103,     0,     0,    24,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   136,     0,     0,     0,
       0,     0,     2,     0,     0,     3,     4,     5,     0,     0,
       0,     6,     0,     7,     0,     9,     0,   111,   112,    10,
       0,    12,    13,     0,    15,     0,    16,    17,    99,     0,
      19,     0,     0,    20,    21,    22,    23,     0,   100,   101,
     102,     0,     0,     0,   103,     0,     0,    24,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   136,   147,   148,
       0,     0,     0,   149,   150,   151,     0,     0,     0,     0,
       0,   152,   153,   154,     0,     0,     0,     0,   111,   112,
     155,     0,     0,    99,     0,     0,   156,     0,     0,     0,
       0,     0,   157,   260,   101,   102,   159,     0,     5,   103,
       0,     0,   261,     0,     0,     0,     0,   105,   106,   107,
     108,   109,   136,     0,     0,    15,     0,     0,     0,    99,
     182,     0,     0,     0,     0,     0,     0,    23,     0,   100,
     101,   102,     0,   111,   112,   103,     0,     0,     0,     0,
       0,   183,     5,   105,   106,   107,   108,   109,   184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,    99,   288,     0,     0,     0,     0,   111,
     112,    23,     0,   100,   101,   102,     0,     0,     5,   103,
       0,     0,     0,     0,     0,   289,     0,   105,   106,   107,
     108,   109,   290,     0,     0,    15,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,    23,     0,   100,
     101,   102,     0,   111,   112,   103,     0,     0,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   136,     0,
       0,     0,     0,     1,     2,     0,     0,     3,     4,     5,
       0,     0,     0,     6,     0,     7,     8,     9,     0,   111,
     112,    10,    11,    12,    13,    14,    15,     0,    16,    17,
       0,    18,    19,     0,     0,    20,    21,    22,    23,     0,
       1,     2,     0,     0,     3,     4,     5,     0,     0,    24,
       6,     0,     7,     8,     9,     0,     0,     0,    10,    11,
      12,    13,    14,    15,     0,    16,    17,   297,    18,    19,
       0,     0,    20,    21,    22,    23,     0,    44,     0,     0,
       0,     0,     0,   191,    93,     0,    24,     0,    62,     1,
       2,     0,     0,     3,     4,     5,    47,     0,     0,     6,
       0,     7,     8,     9,     0,     0,     0,    10,    11,    12,
      13,    14,    15,     0,    16,    17,     0,    18,    19,     0,
       0,    20,    21,    22,    23,     0,     0,     0,    99,     0,
       0,     0,    61,    93,     0,    24,     0,    62,   100,   101,
     102,     0,     0,     0,   103,    47,   275,   173,   400,   276,
       0,     0,   105,   106,   107,   108,   109,   136,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   111,   112,
     103,     0,   275,   173,    99,   276,     0,     0,   105,   106,
     107,   108,   109,   136,   100,   101,   102,     0,     0,     0,
     103,     0,     0,   173,     0,     0,     0,     0,   105,   106,
     107,   108,   109,   136,   111,   112,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
       0,     0,   103,     0,   111,   112,    99,     0,   251,     0,
     105,   106,   107,   108,   109,   252,   100,   101,   102,   266,
       0,     0,   103,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,   108,   109,   136,   111,   112,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,     0,     0,   103,   111,   112,   360,    99,
       0,     0,     0,   105,   106,   107,   108,   109,   136,   100,
     101,   102,   159,     0,     0,   103,     0,     0,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   136,   111,
     112,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,     0,     0,   103,   384,   111,
     112,    99,     0,     0,     0,   105,   106,   107,   108,   109,
     136,   100,   101,   102,     0,     0,     0,   103,   386,     0,
       0,     0,     0,     0,     0,   105,   106,   107,   108,   109,
     136,   111,   112,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,     0,     0,   103,
       0,   111,   112,    99,     0,     0,     0,   105,   106,   107,
     108,   109,   136,   100,   101,   102,     0,     0,     0,   202,
       0,     0,     0,     0,     0,     0,     0,   105,   106,   107,
     108,   109,   136,   111,   112,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,     0,     0,
       0,   207,     0,   111,   112,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   136,     0,     0,     0,     0,     1,
       2,     0,     0,     3,     4,     5,     0,     0,     0,     6,
       0,     7,     8,     9,     0,   111,   112,    10,    11,    12,
      13,    14,    15,     0,    16,    17,     0,    18,    19,     0,
       0,    20,    21,    22,    23,    66,     0,     0,     1,     2,
       0,     0,     3,     4,     5,    78,     0,     0,     6,    79,
       7,     8,     9,     0,     0,     0,    10,    11,    12,    13,
      14,    15,     0,    16,    17,     0,    18,    19,     0,     0,
      20,    21,    22,    23,     0,     1,     2,     0,     0,     3,
       4,     5,     0,     0,    24,     6,     0,     7,     8,     9,
       0,     0,     0,    10,    11,    12,    13,    14,    15,     0,
      16,    17,     0,    18,    19,     0,     0,    20,    21,    22,
      23,     0,   178,     0,     0,     0,     0,     0,     0,   179,
       0,    24,     1,     2,     0,     0,     3,     4,     5,     0,
       0,     0,     6,     0,     7,     8,     9,     0,     0,     0,
      10,    11,    12,    13,    14,    15,     0,    16,    17,     0,
      18,    19,     0,     0,    20,    21,    22,    23,     0,     1,
       2,     0,     0,     3,     4,     5,   249,     0,    24,     6,
       0,     7,     8,     9,     0,     0,     0,    10,    11,    12,
      13,    14,    15,     0,    16,    17,     0,    18,    19,     0,
       0,    20,    21,    22,    23,     0,     1,     2,     0,     0,
       3,     4,     5,     0,     0,    24,     6,     0,     7,     8,
       9,     0,     0,     0,    10,    11,    12,    13,    14,    15,
       0,    16,    17,     0,    18,    19,     0,     0,    20,    21,
      22,    23,     2,     0,     0,     3,     4,     5,     0,     0,
       0,     6,    78,     7,     0,     9,     0,     0,     0,    10,
       0,    12,    13,     0,    15,     0,    16,    17,     0,     0,
      19,     0,     0,    20,    21,    22,    23,     0,     0,     0,
       2,     0,     0,     3,     4,     5,     0,    24,   188,     6,
       0,     7,     0,     9,     0,     0,     0,    10,     0,    12,
      13,     0,    15,     0,    16,    17,     0,     0,    19,     0,
       0,    20,    21,    22,    23,     0,     0,     0,     2,     0,
       0,     3,     4,     5,     0,    24,   292,     6,     0,     7,
       0,     9,     0,     0,     0,    10,     0,    12,    13,     0,
      15,     0,    16,    17,     0,     0,    19,     0,     0,    20,
      21,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
        62,    79,   116,    26,     0,    70,    51,    70,   148,     0,
      63,   347,   151,    71,    61,   103,    90,    79,    85,    50,
      40,    40,    86,   263,    86,    45,    46,    40,    40,    40,
      49,    27,    28,    29,    30,    47,    99,    50,     9,    59,
      36,    28,   103,    30,    66,    36,     9,    94,   111,   112,
     190,    40,    83,   116,    77,    26,   392,    68,    81,    50,
      40,    50,    84,    26,   131,    61,    46,    38,    40,    92,
     132,    94,    40,    60,    46,    38,   134,    46,    60,    59,
      40,    49,    51,   148,    49,   148,    62,    63,    59,    85,
      59,    53,    83,    40,   155,    44,   336,   337,    45,    46,
      87,    88,    89,    90,    51,    87,    88,    89,    90,    85,
      86,   173,    59,   187,   202,   229,   230,   231,   182,   207,
     259,   103,    49,    40,   186,   190,    43,   190,    46,    46,
      48,   270,    40,    51,    44,   131,   276,    47,    46,    40,
     193,   202,    59,    51,   191,    46,   207,    45,   193,    44,
      51,   212,    44,    44,   294,    53,    46,    52,    59,    50,
      47,    51,    80,    81,    82,   227,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    44,   247,   246,    44,   301,    47,    50,
      44,    44,    50,    47,   333,   191,   254,    50,    43,    44,
     187,   279,    33,   199,   265,   187,    43,   268,   269,    47,
     272,   276,    47,   276,    46,    44,    47,   279,    47,    51,
     202,    54,    60,   285,    55,   207,   288,    58,    52,   294,
      61,   294,   371,   372,   373,    65,    74,    48,   301,    46,
      51,    64,    53,    74,    51,   384,    52,   386,    86,    87,
      88,    89,    90,   236,   237,   238,   239,   396,    83,   398,
     399,    92,    53,    94,    44,   103,    43,    47,    30,   347,
      45,    44,   263,   296,    47,    59,    60,    61,    40,    41,
      42,    57,    58,    43,    46,   347,    48,    49,    50,    51,
      78,    79,    54,    55,    56,    57,    58,    59,   360,   377,
      30,   366,    44,   366,    47,    47,    46,   368,   369,   370,
      40,    41,    42,    40,   392,   377,    46,    53,    80,    81,
      44,    46,    52,    47,    54,    55,    56,    57,    58,    59,
     392,    46,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    44,    46,   182,    47,    87,    88,   186,   187,
      80,    81,    43,    44,    43,    44,    43,    44,    44,    45,
     191,   232,   233,    47,   202,   234,   235,   240,   241,   207,
      52,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    52,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    45,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    40,    40,    46,    52,    47,    49,    50,    52,
      45,    45,    54,    55,    56,    57,    58,    59,    39,    43,
      40,    40,    52,    52,    47,    47,    44,    52,    40,    14,
      47,    46,    43,   363,   242,    49,    52,   285,    80,    81,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    52,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,   244,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   243,   245,    46,    77,   360,    49,    50,   247,   280,
     199,    54,    55,    56,    57,    58,    59,    87,   167,   296,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,
      13,    -1,    15,    16,    17,    -1,    80,    81,    21,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      -1,    -1,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,     4,    -1,    -1,     7,     8,     9,    -1,    -1,
      -1,    13,    -1,    15,    -1,    17,    -1,    80,    81,    21,
      -1,    23,    24,    -1,    26,    -1,    28,    29,    30,    -1,
      32,    -1,    -1,    35,    36,    37,    38,    -1,    40,    41,
      42,    -1,    -1,    -1,    46,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    58,    59,     5,     6,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    -1,    -1,    -1,    -1,    80,    81,
      27,    -1,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    -1,     9,    46,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    54,    55,    56,
      57,    58,    59,    -1,    -1,    26,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    -1,    80,    81,    46,    -1,    -1,    -1,    -1,
      -1,    52,     9,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    80,
      81,    38,    -1,    40,    41,    42,    -1,    -1,     9,    46,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    56,
      57,    58,    59,    -1,    -1,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    -1,    80,    81,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,     7,     8,     9,
      -1,    -1,    -1,    13,    -1,    15,    16,    17,    -1,    80,
      81,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    38,    -1,
       3,     4,    -1,    -1,     7,     8,     9,    -1,    -1,    49,
      13,    -1,    15,    16,    17,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    -1,    28,    29,    67,    31,    32,
      -1,    -1,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    49,    -1,    51,     3,
       4,    -1,    -1,     7,     8,     9,    59,    -1,    -1,    13,
      -1,    15,    16,    17,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,    -1,    31,    32,    -1,
      -1,    35,    36,    37,    38,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    46,    47,    -1,    49,    -1,    51,    40,    41,
      42,    -1,    -1,    -1,    46,    59,    48,    49,    50,    51,
      -1,    -1,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,    80,    81,
      46,    -1,    48,    49,    30,    51,    -1,    -1,    54,    55,
      56,    57,    58,    59,    40,    41,    42,    -1,    -1,    -1,
      46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    54,    55,
      56,    57,    58,    59,    80,    81,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,    -1,    46,    -1,    80,    81,    30,    -1,    52,    -1,
      54,    55,    56,    57,    58,    59,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    59,    80,    81,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    -1,    -1,    -1,    46,    80,    81,    49,    30,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    59,    80,
      81,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    -1,    46,    47,    80,
      81,    30,    -1,    -1,    -1,    54,    55,    56,    57,    58,
      59,    40,    41,    42,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,
      59,    80,    81,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,    46,
      -1,    80,    81,    30,    -1,    -1,    -1,    54,    55,    56,
      57,    58,    59,    40,    41,    42,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,
      57,    58,    59,    80,    81,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      -1,    46,    -1,    80,    81,    -1,    -1,    -1,    -1,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,    13,
      -1,    15,    16,    17,    -1,    80,    81,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,    -1,    31,    32,    -1,
      -1,    35,    36,    37,    38,     0,    -1,    -1,     3,     4,
      -1,    -1,     7,     8,     9,    49,    -1,    -1,    13,    53,
      15,    16,    17,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    -1,    28,    29,    -1,    31,    32,    -1,    -1,
      35,    36,    37,    38,    -1,     3,     4,    -1,    -1,     7,
       8,     9,    -1,    -1,    49,    13,    -1,    15,    16,    17,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    -1,
      28,    29,    -1,    31,    32,    -1,    -1,    35,    36,    37,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    49,     3,     4,    -1,    -1,     7,     8,     9,    -1,
      -1,    -1,    13,    -1,    15,    16,    17,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    -1,    28,    29,    -1,
      31,    32,    -1,    -1,    35,    36,    37,    38,    -1,     3,
       4,    -1,    -1,     7,     8,     9,    47,    -1,    49,    13,
      -1,    15,    16,    17,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,    -1,    31,    32,    -1,
      -1,    35,    36,    37,    38,    -1,     3,     4,    -1,    -1,
       7,     8,     9,    -1,    -1,    49,    13,    -1,    15,    16,
      17,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    -1,    31,    32,    -1,    -1,    35,    36,
      37,    38,     4,    -1,    -1,     7,     8,     9,    -1,    -1,
      -1,    13,    49,    15,    -1,    17,    -1,    -1,    -1,    21,
      -1,    23,    24,    -1,    26,    -1,    28,    29,    -1,    -1,
      32,    -1,    -1,    35,    36,    37,    38,    -1,    -1,    -1,
       4,    -1,    -1,     7,     8,     9,    -1,    49,    50,    13,
      -1,    15,    -1,    17,    -1,    -1,    -1,    21,    -1,    23,
      24,    -1,    26,    -1,    28,    29,    -1,    -1,    32,    -1,
      -1,    35,    36,    37,    38,    -1,    -1,    -1,     4,    -1,
      -1,     7,     8,     9,    -1,    49,    50,    13,    -1,    15,
      -1,    17,    -1,    -1,    -1,    21,    -1,    23,    24,    -1,
      26,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,     3,     4,     7,     8,     9,    13,    15,    16,    17,
      21,    22,    23,    24,    25,    26,    28,    29,    31,    32,
      35,    36,    37,    38,    49,   111,   112,   113,   125,   129,
     130,   131,   132,   137,   138,   141,   153,   154,   155,    40,
      49,    40,   139,   140,    40,    43,    46,    59,   114,   115,
     121,   122,   123,   112,   112,   137,   112,   112,   137,    40,
      49,    46,    51,   122,   142,   143,     0,   154,    49,   139,
      53,    44,   121,   122,   124,   125,    43,    44,    49,    53,
     111,   112,   146,   156,   123,    46,    51,    49,   125,   130,
     133,   134,   137,    47,   112,   126,   127,   128,   142,    30,
      40,    41,    42,    46,    52,    54,    55,    56,    57,    58,
      59,    80,    81,    90,    91,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     143,    46,    51,   139,    44,    50,    59,    93,   106,   110,
      50,   140,    47,   122,   125,   115,   121,     5,     6,    10,
      11,    12,    18,    19,    20,    27,    33,    39,    40,    43,
      50,   107,   109,   111,   144,   145,   146,   147,   148,   149,
     150,   151,   152,    49,   107,   116,   111,   146,    40,    47,
     126,   157,    31,    52,    59,   107,   124,   133,    50,   134,
      45,    46,   121,   122,   135,   136,   121,   142,    47,    44,
      43,    47,    46,    93,   109,   141,    52,    46,    93,    93,
      46,    48,    51,    80,    81,    82,    53,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,   108,    95,    59,
      60,    61,    57,    58,    78,    79,    62,    63,    85,    86,
      87,    88,    54,    64,    65,    83,    66,    84,    52,    47,
     126,    52,    59,   107,    44,    50,    43,   110,    43,    45,
      40,    49,   144,    46,    40,    46,    43,   109,    46,    46,
      45,    43,    44,    50,   148,    48,    51,   116,   117,   118,
     119,   120,    47,    44,    47,   124,    52,    52,    31,    52,
      59,   107,    50,   110,    45,    43,    44,    67,   128,   141,
      47,    47,   141,    40,    47,    92,    40,   109,    40,   107,
      95,    95,    95,    96,    96,    97,    97,    98,    98,    98,
      98,    99,    99,   100,   101,   102,   103,   109,   104,    47,
      52,    52,    50,    45,   144,    39,   111,   149,    43,   109,
      43,   109,   109,   144,   107,    40,   110,    44,    50,   116,
      53,   120,    40,   107,   107,    52,    52,   110,   136,    47,
      49,    95,    47,    44,    47,    52,    45,   144,    46,   149,
     149,    47,    47,    47,    52,    50,   116,   118,    52,    52,
     117,    92,   106,   109,    47,   109,    47,   109,   144,   144,
     144,   116,    44,    50,    47,   144,    47,   144,    47,    14,
      50,    43,   144,   144,   144
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
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

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
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
       2,     1,     4,     5,     4,     6,     2,     1,     3,     1,
       3,     1,     2,     1,     1,     2,     3,     2,     3,     3,
       4,     3,     4,     2,     3,     3,     4,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     3,     1,     2,
       1,     1,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     6,     7,     3,     2,     2,     2,     3,     1,     2,
       1,     1,     4,     3,     1,     2,     1,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
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
  "function_definition", "declaration_list", "identifier_list", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
       153,     0,    -1,    40,    -1,    41,    -1,    42,    -1,    46,
     109,    47,    -1,    90,    -1,    91,    51,   109,    52,    -1,
      91,    46,    92,    47,    -1,    91,    46,    47,    -1,    91,
      48,    40,    -1,    91,    82,    40,    -1,    91,    80,    -1,
      91,    81,    -1,    46,   141,    47,    49,   117,    50,    -1,
      46,   141,    47,    49,   117,    44,    50,    -1,    40,    -1,
      40,    44,    92,    -1,    91,    -1,    80,    93,    -1,    81,
      93,    -1,    94,    95,    -1,    30,    93,    -1,    30,    46,
     141,    47,    -1,    54,    -1,    59,    -1,    58,    -1,    57,
      -1,    56,    -1,    55,    -1,    93,    -1,    46,   141,    47,
      95,    -1,    95,    -1,    96,    59,    95,    -1,    96,    60,
      95,    -1,    96,    61,    95,    -1,    96,    -1,    97,    58,
      96,    -1,    97,    57,    96,    -1,    97,    -1,    98,    79,
      97,    -1,    98,    78,    97,    -1,    98,    -1,    99,    63,
      98,    -1,    99,    62,    98,    -1,    99,    85,    98,    -1,
      99,    86,    98,    -1,    99,    -1,   100,    87,    99,    -1,
     100,    88,    99,    -1,   100,    -1,   101,    54,   100,    -1,
     101,    -1,   102,    64,   101,    -1,   102,    -1,   103,    65,
     102,    -1,   103,    -1,   104,    83,   103,    -1,   104,    -1,
     105,    84,   104,    -1,   105,    -1,   105,    66,   109,    45,
     106,    -1,   106,    -1,    93,   108,   107,    -1,    53,    -1,
      72,    -1,    73,    -1,    74,    -1,    70,    -1,    71,    -1,
      69,    -1,    68,    -1,    75,    -1,    76,    -1,    77,    -1,
     107,    -1,   109,    44,   107,    -1,   106,    -1,   112,    43,
      -1,   112,   114,    43,    -1,   113,    -1,   113,   112,    -1,
     130,    -1,   130,   112,    -1,   125,    -1,   125,   112,    -1,
     129,    -1,   129,   112,    -1,    16,    -1,    31,    -1,     3,
      -1,    25,    -1,   115,    -1,   114,    44,   115,    -1,   121,
      -1,   121,    53,   116,    -1,   107,    -1,    49,   117,    50,
      -1,    49,   117,    44,    50,    -1,   116,    -1,   118,   116,
      -1,   117,    44,   116,    -1,   117,    44,   118,   116,    -1,
     119,    53,    -1,   120,    -1,   119,   120,    -1,    51,   110,
      52,    -1,    48,    40,    -1,   122,   123,    -1,   123,    -1,
      59,    -1,    59,   124,    -1,    59,   122,    -1,    59,   124,
     122,    -1,    40,    -1,    46,   121,    47,    -1,   123,    51,
     124,   107,    52,    -1,   123,    51,   124,    52,    -1,   123,
      51,   107,    52,    -1,   123,    51,    31,   124,   107,    52,
      -1,   123,    51,   124,    31,   107,    52,    -1,   123,    51,
     124,    59,    52,    -1,   123,    51,    59,    52,    -1,   123,
      51,    52,    -1,   123,    46,   126,    47,    -1,   123,    46,
     157,    47,    -1,   123,    46,    47,    -1,   125,    -1,   124,
     125,    -1,     9,    -1,    26,    -1,    38,    -1,   127,    -1,
     127,    44,    67,    -1,   128,    43,    -1,   127,    44,   128,
      -1,   112,   121,    -1,   112,   142,    -1,   112,    -1,    22,
      -1,    37,    -1,     7,    -1,    28,    -1,    23,    -1,    24,
      -1,    17,    -1,    13,    -1,    29,    -1,    36,    -1,     4,
      -1,     8,    -1,    21,    -1,   131,    -1,   138,    -1,   141,
      -1,   132,    40,    49,   133,    50,    -1,   132,    49,   133,
      50,    -1,   132,    40,    -1,    32,    -1,    35,    -1,   134,
      -1,   133,   134,    -1,   137,   135,    43,    -1,   136,    -1,
     135,    44,   136,    -1,   121,    -1,    45,   110,    -1,   121,
      45,   110,    -1,   130,   137,    -1,   130,    -1,   125,   137,
      -1,   125,    -1,    15,    49,   139,    50,    -1,    15,    40,
      49,   139,    50,    -1,    49,   139,    44,    50,    -1,    15,
      40,    49,   139,    44,    50,    -1,    15,    40,    -1,   140,
      -1,   139,    44,   140,    -1,    40,    -1,    40,    53,   110,
      -1,   137,    -1,   137,   142,    -1,   122,    -1,   143,    -1,
     122,   143,    -1,    46,   142,    47,    -1,    51,    52,    -1,
      51,   107,    52,    -1,   143,    51,    52,    -1,   143,    51,
     107,    52,    -1,    51,    59,    52,    -1,   143,    51,    59,
      52,    -1,    46,    47,    -1,    46,   126,    47,    -1,   143,
      46,    47,    -1,   143,    46,   126,    47,    -1,   145,    -1,
     146,    -1,   149,    -1,   150,    -1,   151,    -1,   152,    -1,
      40,    45,   144,    -1,     6,   110,    45,   144,    -1,    11,
      45,   144,    -1,    49,    50,    -1,    49,   147,    50,    -1,
     148,    -1,   147,   148,    -1,   111,    -1,   144,    -1,    43,
      -1,   109,    43,    -1,    20,    46,   109,    47,   144,    -1,
      20,    46,   109,    47,   144,    14,   144,    -1,    33,    46,
     109,    47,   144,    -1,    39,    46,   109,    47,   144,    -1,
      12,   144,    39,    46,   109,    47,    43,    -1,    18,    46,
     149,   149,    47,   144,    -1,    18,    46,   149,   149,   109,
      47,   144,    -1,    18,    46,   111,   149,    47,   144,    -1,
      18,    46,   111,   149,   109,    47,   144,    -1,    19,    40,
      43,    -1,    10,    43,    -1,     5,    43,    -1,    27,    43,
      -1,    27,   109,    43,    -1,   154,    -1,   153,   154,    -1,
     155,    -1,   111,    -1,   112,   121,   156,   146,    -1,   112,
     121,   146,    -1,   111,    -1,   156,   111,    -1,    40,    -1,
     157,    44,    40,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  parser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    13,    15,    20,    25,
      29,    33,    37,    40,    43,    50,    58,    60,    64,    66,
      69,    72,    75,    78,    83,    85,    87,    89,    91,    93,
      95,    97,   102,   104,   108,   112,   116,   118,   122,   126,
     128,   132,   136,   138,   142,   146,   150,   154,   156,   160,
     164,   166,   170,   172,   176,   178,   182,   184,   188,   190,
     194,   196,   202,   204,   208,   210,   212,   214,   216,   218,
     220,   222,   224,   226,   228,   230,   232,   236,   238,   241,
     245,   247,   250,   252,   255,   257,   260,   262,   265,   267,
     269,   271,   273,   275,   279,   281,   285,   287,   291,   296,
     298,   301,   305,   310,   313,   315,   318,   322,   325,   328,
     330,   332,   335,   338,   342,   344,   348,   354,   359,   364,
     371,   378,   384,   389,   393,   398,   403,   407,   409,   412,
     414,   416,   418,   420,   424,   427,   431,   434,   437,   439,
     441,   443,   445,   447,   449,   451,   453,   455,   457,   459,
     461,   463,   465,   467,   469,   471,   477,   482,   485,   487,
     489,   491,   494,   498,   500,   504,   506,   509,   513,   516,
     518,   521,   523,   528,   534,   539,   546,   549,   551,   555,
     557,   561,   563,   566,   568,   570,   573,   577,   580,   584,
     588,   593,   597,   602,   605,   609,   613,   618,   620,   622,
     624,   626,   628,   630,   634,   639,   643,   646,   650,   652,
     655,   657,   659,   661,   664,   670,   678,   684,   690,   698,
     705,   713,   720,   728,   732,   735,   738,   741,   745,   747,
     750,   752,   754,   759,   763,   765,   768,   770
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   219,   219,   222,   225,   228,   234,   237,   240,   243,
     246,   249,   252,   255,   258,   261,   267,   270,   276,   279,
     282,   285,   288,   291,   297,   300,   303,   306,   309,   312,
     318,   321,   327,   330,   333,   336,   342,   345,   348,   354,
     357,   360,   366,   369,   372,   375,   378,   384,   387,   390,
     396,   399,   405,   408,   414,   417,   423,   426,   432,   435,
     441,   444,   450,   453,   459,   462,   465,   468,   471,   474,
     477,   480,   483,   486,   489,   495,   498,   504,   510,   513,
     519,   522,   525,   528,   531,   534,   537,   540,   546,   549,
     552,   555,   561,   564,   570,   573,   579,   582,   585,   591,
     594,   597,   600,   606,   612,   615,   621,   624,   630,   633,
     639,   642,   645,   648,   654,   657,   660,   663,   666,   669,
     672,   675,   678,   681,   684,   687,   690,   696,   699,   705,
     708,   711,   717,   720,   726,   729,   735,   738,   741,   747,
     753,   756,   759,   762,   765,   768,   771,   774,   777,   780,
     783,   786,   789,   792,   795,   801,   804,   807,   813,   816,
     822,   825,   831,   837,   840,   846,   849,   852,   858,   861,
     864,   867,   873,   876,   879,   882,   885,   891,   894,   900,
     903,   909,   912,   918,   921,   924,   930,   933,   936,   939,
     942,   945,   948,   951,   954,   957,   960,   966,   969,   972,
     975,   978,   981,   987,   990,   993,   999,  1002,  1008,  1011,
    1017,  1020,  1026,  1029,  1035,  1038,  1041,  1047,  1050,  1053,
    1056,  1059,  1062,  1068,  1071,  1074,  1077,  1080,  1086,  1089,
    1095,  1098,  1104,  1107,  1113,  1116,  1122,  1125
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
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
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 1693;
  const int parser::yynnts_ = 69;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 66;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 89;

  const unsigned int parser::yyuser_token_number_max_ = 343;
  const parser::token_number_type parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yy

/* Line 1054 of lalr1.cc  */
#line 3205 "bis_out.cpp"


/* Line 1056 of lalr1.cc  */
#line 1130 "syntax.yy"


// Epilogue

namespace yy

int main () {
    yy::parser parse;
    return parse ();
}
