
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
        public:
            vector<Node*> children;
            Node* parent;
            string name;
            
            Node(vector<Node*> _children, Node* _parent) {
                children = _children;
                parent = _parent;
            }
            
            Node() {
                children = vector<Node*>(1);
                parent = NULL;
            }

            void print_tree() {
                cout << this << "_" << name;
                for (int i = 0; i < children.size(); i++) {
                    cout << " " << children[i] << "_" << children[i]->print();
                }
                cout << endl;
            }

            virtual string print() = 0;
    };

    class PrimaryExpressionNode : public Node {
        public:
            string print() {
                return("PrimaryExpressionNode");
            }

            PrimaryExpressionNode(Node* expr) {
                children = {expr};
            }
    };

    class IdentifierNode : public Node {
        public:
            string ident;

            string print() {
                return("IDENT(" + ident + ")");
            }

            IdentifierNode(string _ident) {
                ident = _ident;
            }
    };

    class NumericLiteralNode : public Node {
        public:
            string num;

            string print() {
                return("NUMLITERAL(" + num + ")");
            }

            NumericLiteralNode(string _num) {
                num = _num;
            }
    };

    class StrLiteralNode : public Node {
        public:
            string val;

            string print() {
                return("STRLITERAL(" + val + ")");
            }

            StrLiteralNode(string _val) {
                val = _val;
            }
    };

    class CastExpressionNode : public Node {
        public:
            Node* node;
            string typeName;

            string print() {
                string prefix = typeName.size() > 0 ? typeName + "_CAST(" : "";
                string suffix = typeName.size() > 0 ? ")" : "";
                return(prefix + node->print() + suffix);
            }

            CastExpressionNode(Node* node) {
                CastExpressionNode::node = node;
                CastExpressionNode::typeName = "";
            }
            
            CastExpressionNode(string typeName, Node* node) {
                CastExpressionNode::node = node;
                CastExpressionNode::typeName = typeName;
            }
    };

    class BinaryExpressionNode : public Node {
        public:
            vector<string> ops;
            string _exprType;

            string print() {
                string res = _exprType + "(" + children[0]->print();
                for (int i = 0; i < ops.size(); i++) {
                    res += (" " + ops[i] + " ");
                    res += children[i + 1]->print();
                }
                res += ")";
                return res;
            }

            BinaryExpressionNode(Node* node) {
                children = vector<Node*>{node};
                ops = vector<string>();
            }

            BinaryExpressionNode(Node* node, Node* n2) {
                children = vector<Node*>{node,n2};
                ops = vector<string>();
            }
    };

    class OperatorNode : public Node {
        public:
            string _sign;

             string print() {
                return("OPERATOR(" + _sign + ")");
            } 

            OperatorNode(string sign) {
                _sign = sign;
            }
    };

    class KeywordNode : public Node {
        public:
            string _sign;

            string print() {
                return("Keyword(" + _sign + ")");
            } 

            KeywordNode(string sign) {
                _sign = sign;
            }
    };

    class PostfixExpressionNode : public Node {
        public:
            string print() {
                return("PostfixExpressionNode");
            }

            PostfixExpressionNode(Node* n1) {
                children = vector<Node*>{n1};
            }

            PostfixExpressionNode(Node* n1, Node* n2) {
                children = vector<Node*>{n1, n2};
            }
    };

    class ArgumentExpressionListNode: public Node {
        public:
            string print() {
                return("ArgumentExpressionList");
            }

            ArgumentExpressionListNode(Node* n1) {
                children = vector<Node*>{n1};
            }
    };

    class ExpressionNode: public Node {
        public:
            string print(){
                return("ExpressionNode");
            }

         ExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class UnaryExpressionNode : public Node{
        public:
            string print(){
                return("UnaryExpressionNode");
            }

          UnaryExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class  UnaryOperatorNode: public Node{
        public:
            string print(){
                return("UnaryOperatorNode");
            }

          UnaryOperatorNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    


    class ConditionalExpressionNode: public Node{
        public:

            string print(){
                return("ConditionalExpressionNode");
            }
        ConditionalExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
         ConditionalExpressionNode(Node* n1,Node* n2,Node* n3){
            children = vector<Node*>{n1,n2,n3};

        }
    };
    class AssignmentExpressionNode: public Node{
        public:

            string print(){
                return("AssignmentExpressionNode");
            }
        AssignmentExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
        AssignmentExpressionNode(Node* n1,Node* n2,Node* n3){
            children = vector<Node*>{n1,n2,n3};

        }
    };
    class ConstantExpressionNode: public Node{
        public:
            string print(){
                return("ConstantExpressionNode");
            }

         ConstantExpressionNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class DeclarationNode: public Node{
            public:
            string print(){
                return("DeclarationNode");
            }

         DeclarationNode(Node* n1){
            children = vector<Node*>{n1};

        }
        DeclarationNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class DeclarationSpecifiersNode: public Node{
            public:
            string print(){
                return("DeclarationSpecifiersNode");
            }

         DeclarationSpecifiersNode(Node* n1){
            children = vector<Node*>{n1};

        }
        DeclarationSpecifiersNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class FunctionSpecifierNode:public Node{
            public:
            string print(){
                return("FunctionSpecifierNode");
            }

        FunctionSpecifierNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };
    
    class TypeSpecifierNode:public Node{
            public:
            string print(){
                return("TypeSpecifierNode");
            }

        TypeSpecifierNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class StructOrUnionSpecifierNode: public Node{
            public:
            string print(){
                return("StructOrUnionSpecifierNode");
            }

        StructOrUnionSpecifierNode(Node* n1,Node* n2, Node* n3){
            children = vector<Node*>{n1,n2,n3};

        }
        StructOrUnionSpecifierNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class  StructDeclarationListNode: public Node{
            public:
            string print(){
                return("StructDeclarationListNode");
            }

        StructDeclarationListNode(Node* n1){
            children = vector<Node*>{n1};

        }
         StructDeclarationListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class  StructDeclarationNode: public Node{
            public:
            string print(){
                return("StructDeclarationNode");
            }

        StructDeclarationNode(Node* n1){
            children = vector<Node*>{n1};

        }
         StructDeclarationNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class StructDeclaratorListNode: public Node{
            public:
            string print(){
                return("StructDeclaratorListNode");
            }

        StructDeclaratorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
         StructDeclaratorListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

        class StructDeclaratorNode: public Node{
            public:
            string print(){
                return("StructDeclaratorNode");
            }

        StructDeclaratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
         StructDeclaratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };


    class SpecifierQualifierListNode : public Node {
    public:
        string print() {
            return("SpecifierQualifierListNode");
        }

        SpecifierQualifierListNode(Node* n1) {
            children = vector<Node*>{n1};
        }

        SpecifierQualifierListNode(Node* n1,Node* n2) {
            children = vector<Node*>{n1, n2};
        }
    };

    class EnumSpecifierNode : public Node {
    public:
        string print() {
            return("EnumSpecifierNode");
        }

        EnumSpecifierNode(Node* n1, Node* n2, Node* n3) {
            children = vector<Node*>{n1, n2, n3};
        }

        EnumSpecifierNode(Node* n1, Node* n2) {
            children = vector<Node*>{n1, n2};
        }
    };

    class EnumeratorNode: public Node {
    public:
        string print() {
            return("EnumeratorNode");
        }

         EnumeratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
        EnumeratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class TypeNameNode: public Node {
        public:
            string print(){
                return("TypeNameNode");
            }

         TypeNameNode(Node* n1){
            children = vector<Node*>{n1};

        }
        TypeNameNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class AbstractDeclaratorNode :  public Node {
        public:
            string print(){
                return("AbstractDeclaratorNode");
            }

        AbstractDeclaratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
        AbstractDeclaratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class DirectAbstractDeclaratorNode : public Node {
        public:
            string print() {
                return("DirectAbstractDeclaratorNode");
            }

            DirectAbstractDeclaratorNode(Node* n1) {
                children = vector<Node*>{n1};
            }

            DirectAbstractDeclaratorNode(Node* n1,Node* n2) {
                children = vector<Node*>{n1, n2};
            }
    };

    class  EnumeratorListNode :public Node {
        public:
            string print(){
                return("EnumeratorListNode");
            }

        EnumeratorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class InitDeclaratorListNode: public Node{
            public:
            string print(){
                return("InitDeclaratorListNode");
            }

        InitDeclaratorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
        InitDeclaratorListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class StorageClassSpecifierNode: public Node{
        public:
            string print(){
                return("StorageClassSpecifierNode");
            }

         StorageClassSpecifierNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class InitDeclaratorNode :public Node{
        public:
            string print(){
                return("InitDeclaratorNode");
            }

        InitDeclaratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
        InitDeclaratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class InitializerNode : public Node{
        public:
            string print(){
                return("InitializerNode");
            }

         InitializerNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class InitializerListNode : public Node{
        public:
            string print(){
                return("InitializerListNode");
            }

         InitializerListNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class DesignatorNode: public Node{
        public:
            string print(){
                return("DesignatorNode");
            }

         DesignatorNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class DesignatorListNode: public Node{
        public:
            string print(){
                return("DesignatorNode");
            }

         DesignatorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
     DesignatorListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1,n2};

        }
    };

    class DesignationNode: public Node{
        public:
            string print(){
                return("DesignationNode");
            }

         DesignationNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class DeclaratorNode: public Node{
        public:
            string print(){
                return("DeclaratorNode");
            }

         DeclaratorNode(Node* n1){
            children = vector<Node*>{n1};

        }
        DeclaratorNode(Node* n1,Node* n2){
            children = vector<Node*>{n1, n2};

        }
    };

    class PointerNode : public Node
    {
        public:
            string print(){
                return("PointerNode");
            }

        PointerNode(Node* n1){
            children = vector<Node*>{n1};

        }
        PointerNode(Node* n1,Node* n2){
            children = vector<Node*>{n1, n2};

        }
        PointerNode(){
        }
    };

    class DirectDeclaratorListNode: public Node
    {
        public:
            string print(){
                return("DirectDeclaratorList");
            }

       DirectDeclaratorListNode(Node* n1){
            children = vector<Node*>{n1};

        }
       DirectDeclaratorListNode(Node* n1,Node* n2){
            children = vector<Node*>{n1, n2};

        }
       DirectDeclaratorListNode(){
        }
    };


    class TypeQualifierListNode :  public Node{
        public:
            string print(){
                return("TypeQualifieListNode");
            }

         TypeQualifierListNode(){

        }
    };

    class TypeQualifierNode : public Node{
        public:
            string print(){
                return("TypeQualifierNode");
            }

        TypeQualifierNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class ParameterClassList:public Node{
        public:
            string print(){
                return(" ParameterClassList");
            }

         ParameterClassList(Node* n2, Node* n1){
            children = vector<Node*>{n2,n1};

        }
        ParameterClassList(Node* n2){
            children = vector<Node*>{n2};

        }
    };

    class  ParameterListNode : public Node{
        public:
            string print(){
                return("ParameterListNode");
            }

       ParameterListNode(Node* n1){
            children = vector<Node*>{n1};

        }
    };

    class ParameterDeclarationNode : public Node{
        public:
            string print(){
                return("ParameterDeclarationList");
            }

       ParameterDeclarationNode(Node* n1){
            children = vector<Node*>{n1};

        }
       ParameterDeclarationNode(Node* n1,Node* n2){
            children = vector<Node*>{n1, n2};

        }

    };



/* Line 304 of lalr1.cc  */
#line 782 "bis_out.cpp"


/* First part of user declarations.  */


/* Line 311 of lalr1.cc  */
#line 789 "bis_out.cpp"


#include "bis_out.hpp"

/* User implementation prologue.  */


/* Line 317 of lalr1.cc  */
#line 798 "bis_out.cpp"

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
#line 867 "bis_out.cpp"
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
#line 951 "syntax.yy"
    { (yyval.Node*) = new PrimaryExpressionNode(new IdentifierNode("ab")); }
    break;

  case 3:

/* Line 678 of lalr1.cc  */
#line 952 "syntax.yy"
    { (yyval.Node*) = new PrimaryExpressionNode(new NumericLiteralNode("1")); }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 953 "syntax.yy"
    { (yyval.Node*) = new PrimaryExpressionNode(new StrLiteralNode("String")); }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 954 "syntax.yy"
    { (yyval.Node*) = new PrimaryExpressionNode(NULL); }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 958 "syntax.yy"
    { (yyval.Node*) = new PostfixExpressionNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 959 "syntax.yy"
    {(yysemantic_stack_[(4) - (1)].Node*)->children.push_back((yysemantic_stack_[(4) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(4) - (1)].Node*) ;}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 961 "syntax.yy"
    {(yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*);}
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 962 "syntax.yy"
    {(yysemantic_stack_[(3) - (1)].Node*)->children.push_back(new IdentifierNode((yysemantic_stack_[(3) - (3)].std::string))); (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*) ;}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 963 "syntax.yy"
    {(yysemantic_stack_[(3) - (1)].Node*) -> children.push_pack(new OperatorNode( (yysemantic_stack_[(3) - (2)].std::string) ));(yysemantic_stack_[(3) - (1)].Node*)->children.push_back(new IdentifierNode((yysemantic_stack_[(3) - (3)].std::string))); (yyval.Node*)=(yysemantic_stack_[(3) - (1)].Node*);}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 964 "syntax.yy"
    {(yysemantic_stack_[(2) - (1)].Node*) -> children.push_pack(new OperatorNode((yysemantic_stack_[(2) - (2)].std::string))); (yyval.Node*)=(yysemantic_stack_[(2) - (1)].Node*);}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 965 "syntax.yy"
    {(yysemantic_stack_[(2) - (1)].Node*) -> children.push_pack(new OperatorNode((yysemantic_stack_[(2) - (2)].std::string))); (yyval.Node*)=(yysemantic_stack_[(2) - (1)].Node*);}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 966 "syntax.yy"
    { (yyval.Node*) = new PostfixExpressionNode((yysemantic_stack_[(6) - (2)].Node*),(yysemantic_stack_[(6) - (5)].Node*));}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 967 "syntax.yy"
    {(yyval.Node*)= new PostfixExpressionNode((yysemantic_stack_[(7) - (2)].Node*),(yysemantic_stack_[(7) - (5)].Node*));}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 971 "syntax.yy"
    {(yyval.Node*) = new ArgumentExpressionList(new IdentifierNode((yysemantic_stack_[(1) - (1)].std::string)));}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 972 "syntax.yy"
    {(yysemantic_stack_[(3) - (3)].Node*)->children.push_back(new IdentifierNode((yysemantic_stack_[(3) - (1)].std::string))); (yyval.Node*)=(yysemantic_stack_[(3) - (3)].Node*);}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 976 "syntax.yy"
    {(yyval.Node*) = new UnaryExpressionNode(new PostfixExpressionNode((yysemantic_stack_[(1) - (1)].Node*)));}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 977 "syntax.yy"
    {(yysemantic_stack_[(2) - (2)].Node*) -> children.push_pack(new OperatorNode((yysemantic_stack_[(2) - (1)].std::string))); (yyval.Node*)=(yysemantic_stack_[(2) - (2)].Node*);}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 978 "syntax.yy"
    {(yysemantic_stack_[(2) - (2)].Node*) -> children.push_pack((new OperatorNode((yysemantic_stack_[(2) - (1)].std::string))); (yyval.Node*)=(yysemantic_stack_[(2) - (2)].Node*);}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 979 "syntax.yy"
    {(yysemantic_stack_[(2) - (1)].Node*) ->children.push_back(new CastExpressionNode((yysemantic_stack_[(2) - (2)].Node*))); (yyval.Node*) = (yysemantic_stack_[(2) - (1)].Node*);}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 980 "syntax.yy"
    {(yysemantic_stack_[(2) - (2)].Node*) -> children.push_pack(new OperatorNode((yysemantic_stack_[(2) - (1)].std::string))); (yyval.Node*)=(yysemantic_stack_[(2) - (2)].Node*);}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 981 "syntax.yy"
    {(yyval.Node*) = new UnaryExpressionNode("(new OperatorNode($1)", (yysemantic_stack_[(4) - (3)].Node*));}
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 985 "syntax.yy"
    {(yyval.Node*) = new UnaryOperatorNode(new OperatorNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 986 "syntax.yy"
    {(yyval.Node*) = new UnaryOperatorNode(new OperatorNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 987 "syntax.yy"
    {(yyval.Node*) = new UnaryOperatorNode(new OperatorNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 988 "syntax.yy"
    {(yyval.Node*) = new UnaryOperatorNode(new OperatorNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 989 "syntax.yy"
    {(yyval.Node*) = new UnaryOperatorNode(new OperatorNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 990 "syntax.yy"
    {(yyval.Node*) = new UnaryOperatorNode(new OperatorNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 994 "syntax.yy"
    { (yyval.Node*) = new CastExpressionNode((yysemantic_stack_[(1) - (1)].Node*)) }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 995 "syntax.yy"
    { (yyval.Node*) = new CastExpressionNode((yysemantic_stack_[(4) - (2)].Node*), (yysemantic_stack_[(4) - (4)].Node*)); }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 999 "syntax.yy"
    { (yyval.Node*) = new BinaryExpressionNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 1000 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1001 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1002 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1006 "syntax.yy"
    { (yyval.Node*) = new BinaryExpressionNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1007 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1008 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1012 "syntax.yy"
    { (yyval.Node*) = new BinaryExpressionNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1013 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1014 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1018 "syntax.yy"
    { (yyval.Node*) = new BinaryExpressionNode((yysemantic_stack_[(1) - (1)].Node*)) ;}
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1019 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1020 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1021 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back(new OperatorNode((yysemantic_stack_[(3) - (2)].std::string))); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1022 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back(new OperatorNode((yysemantic_stack_[(3) - (2)].std::string)));(yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1026 "syntax.yy"
    { (yyval.Node*) = new BinaryExpressionNode((yysemantic_stack_[(1) - (1)].Node*)) ;}
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1027 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back(new OperatorNode((yysemantic_stack_[(3) - (2)].std::string))); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1028 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back(new OperatorNode((yysemantic_stack_[(3) - (2)].std::string))); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1032 "syntax.yy"
    { (yyval.Node*) = new BinaryExpressionNode((yysemantic_stack_[(1) - (1)].Node*)) ;}
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1033 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1037 "syntax.yy"
    { (yyval.Node*) = new BinaryExpressionNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1038 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1042 "syntax.yy"
    { (yyval.Node*) = new BinaryExpressionNode((yysemantic_stack_[(1) - (1)].Node*)) ;}
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1043 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1047 "syntax.yy"
    { (yyval.Node*) = new BinaryExpressionNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1048 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*));(yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back(new OperatorNode((yysemantic_stack_[(3) - (2)].std::string))); (yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1052 "syntax.yy"
    { (yyval.Node*) = new BinaryExpressionNode((yysemantic_stack_[(1) - (1)].Node*)) ;}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1053 "syntax.yy"
    { (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*)->children.push_back(new OperatorNode((yysemantic_stack_[(3) - (2)].std::string)));(yysemantic_stack_[(3) - (1)].Node*)->ops.push_back((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1057 "syntax.yy"
    { (yyval.Node*) = new ConditionalExpressionNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1058 "syntax.yy"
    { (yyval.Node*) = new ConditionalExpressionNode((yysemantic_stack_[(5) - (1)].Node*),(yysemantic_stack_[(5) - (3)].Node*),(yysemantic_stack_[(5) - (5)].Node*)); }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1062 "syntax.yy"
    { (yyval.Node*) = new AssignmentExpressionNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1063 "syntax.yy"
    { (yyval.Node*) = AssignmentExpressionNode((yysemantic_stack_[(3) - (1)].Node*),(yysemantic_stack_[(3) - (2)].Node*),(yysemantic_stack_[(3) - (3)].Node*)); }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1067 "syntax.yy"
    { (yyval.Node*) = new OperatorNode("=") }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1068 "syntax.yy"
    { (yyval.Node*) = new OperatorNode("*=") }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1069 "syntax.yy"
    { (yyval.Node*) = new OperatorNode("/=") }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1070 "syntax.yy"
    { (yyval.Node*) = new OperatorNode("%=") }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1071 "syntax.yy"
    { (yyval.Node*) = new OperatorNode("+=") }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1072 "syntax.yy"
    { (yyval.Node*) = new OperatorNode("-=") }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1073 "syntax.yy"
    { (yyval.Node*) = new OperatorNode("<=") }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1074 "syntax.yy"
    { (yyval.Node*) = new OperatorNode(">=") }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1075 "syntax.yy"
    { (yyval.Node*) = new OperatorNode("&=") }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1076 "syntax.yy"
    { (yyval.Node*) = new OperatorNode("^=") }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1077 "syntax.yy"
    { (yyval.Node*) = new OperatorNode("|=") }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1081 "syntax.yy"
    {(yyval.Node*) = new ExpressionNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1082 "syntax.yy"
    {(yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*) ;}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1087 "syntax.yy"
    {(yyval.Node*) = new ConstantExpressionNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1091 "syntax.yy"
    {(yyval.Node*) = new DeclarationNode((yysemantic_stack_[(2) - (1)].Node*));}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1092 "syntax.yy"
    { (yyval.Node*) = new DeclarationNode((yysemantic_stack_[(3) - (1)].Node*),(yysemantic_stack_[(3) - (2)].Node*));}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1096 "syntax.yy"
    {(yyval.Node*) = new DeclarationSpecifierNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1097 "syntax.yy"
    {(yyval.Node*) = new DeclarationSpecifierNode((yysemantic_stack_[(2) - (1)].Node*), (yysemantic_stack_[(2) - (2)].Node*));}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1098 "syntax.yy"
    {(yyval.Node*) = new DeclarationSpecifierNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1099 "syntax.yy"
    { (yyval.Node*) = new DeclarationSpecifierNode((yysemantic_stack_[(2) - (1)].Node*),(yysemantic_stack_[(2) - (2)].Node*)); }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1100 "syntax.yy"
    {(yyval.Node*) = new TypeQualifierNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1101 "syntax.yy"
    { (yyval.Node*) = new DeclarationSpecifierNode((yysemantic_stack_[(2) - (1)].Node*),(yysemantic_stack_[(2) - (2)].Node*)); }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1102 "syntax.yy"
    { (yyval.Node*) = new DeclarationSpecifierNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1103 "syntax.yy"
    { (yyval.Node*) = new DeclarationSpecifierNode((yysemantic_stack_[(2) - (1)].Node*),(yysemantic_stack_[(2) - (2)].Node*)); }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1106 "syntax.yy"
    { (yyval.Node*) = new StorageClassSpecifierNode(new KeywordNode((yysemantic_stack_[(1) - (1)].std::string))); }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1107 "syntax.yy"
    { (yyval.Node*) = new StorageClassSpecifierNode(new KeywordNode((yysemantic_stack_[(1) - (1)].std::string))); }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1108 "syntax.yy"
    { (yyval.Node*) = new StorageClassSpecifierNode(new KeywordNode((yysemantic_stack_[(1) - (1)].std::string))); }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1109 "syntax.yy"
    { (yyval.Node*) = new StorageClassSpecifierNode(new KeywordNode((yysemantic_stack_[(1) - (1)].std::string))); }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1113 "syntax.yy"
    {(yyval.Node*) = new InitDeclaratorListNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1114 "syntax.yy"
    {(yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*) ;}
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1118 "syntax.yy"
    {(yyval.Node*) = new  InitDeclaratorNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1119 "syntax.yy"
    {(yyval.Node*) = new  InitDeclaratorNode((yysemantic_stack_[(3) - (1)].Node*), (yysemantic_stack_[(3) - (3)].Node*));}
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1123 "syntax.yy"
    {(yyval.Node*) = new  InitalizerNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1124 "syntax.yy"
    {(yyval.Node*) = new  InitalizerNode((yysemantic_stack_[(3) - (2)].Node*));}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1125 "syntax.yy"
    {(yyval.Node*) = new  InitalizerNode((yysemantic_stack_[(4) - (2)].Node*));}
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1129 "syntax.yy"
    {(yyval.Node*) = new  InitalizerListNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1130 "syntax.yy"
    {(yyval.Node*) = new  InitalizerListNode((yysemantic_stack_[(2) - (1)].Node*));}
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1131 "syntax.yy"
    {(yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*) ;}
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1132 "syntax.yy"
    {(yysemantic_stack_[(4) - (1)].Node*)->children.push_back((yysemantic_stack_[(4) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(4) - (1)].Node*) ;}
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1136 "syntax.yy"
    {(yyval.Node*) = new DesignationNode((yysemantic_stack_[(2) - (1)].Node*));}
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1140 "syntax.yy"
    {(yyval.Node*) = new DesignatorListNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1141 "syntax.yy"
    {(yysemantic_stack_[(2) - (1)].Node*)->children.push_back((yysemantic_stack_[(2) - (2)].Node*)); (yyval.Node*) = (yysemantic_stack_[(2) - (1)].Node*) ;}
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1145 "syntax.yy"
    { (yyval.Node*) = new DesignatorNode((yysemantic_stack_[(3) - (2)].Node*));}
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1146 "syntax.yy"
    { (yyval.Node*) = new DesignatorNode(new IdentifierNode((yysemantic_stack_[(2) - (2)].std::string)));}
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1150 "syntax.yy"
    {(yyval.Node*) = new DeclaratorNode((yysemantic_stack_[(2) - (1)].Node*),(yysemantic_stack_[(2) - (2)].Node*));}
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1151 "syntax.yy"
    {(yyval.Node*) = new DeclaratorNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1155 "syntax.yy"
    {(yyval.Node*) = new PointerNode();}
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1156 "syntax.yy"
    {(yyval.Node*) = new PointerNode((yysemantic_stack_[(2) - (2)].Node*));}
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1157 "syntax.yy"
    {(yyval.Node*) = new PointerNode((yysemantic_stack_[(2) - (2)].Node*));}
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1158 "syntax.yy"
    {(yysemantic_stack_[(3) - (3)].Node*)->children.push_back((yysemantic_stack_[(3) - (2)].Node*)); (yyval.Node*) = (yysemantic_stack_[(3) - (3)].Node*) ;}
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1162 "syntax.yy"
    {(yyval.Node*) = new DirectDeclaratorNode(new IdentifierNode((yysemantic_stack_[(1) - (1)].std::string)));}
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1163 "syntax.yy"
    {(yyval.Node*) = new DirectDeclaratorNode((yysemantic_stack_[(3) - (2)].Node*));}
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1164 "syntax.yy"
    {(yysemantic_stack_[(5) - (1)].Node*)->children.push_back((yysemantic_stack_[(5) - (3)].Node*));(yysemantic_stack_[(5) - (1)].Node*)->children.push_back((yysemantic_stack_[(5) - (4)].Node*)); (yyval.Node*) = (yysemantic_stack_[(5) - (1)].Node*) ;}
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1165 "syntax.yy"
    {(yysemantic_stack_[(4) - (1)].Node*)->children.push_back((yysemantic_stack_[(4) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(4) - (1)].Node*) ;}
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1166 "syntax.yy"
    {(yysemantic_stack_[(4) - (1)].Node*)->children.push_back((yysemantic_stack_[(4) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(4) - (1)].Node*) ;}
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1167 "syntax.yy"
    {(yysemantic_stack_[(6) - (1)].Node*)->children.push_back("static"); (yysemantic_stack_[(6) - (1)].Node*)->children.push_back((yysemantic_stack_[(6) - (4)].Node*));(yysemantic_stack_[(6) - (1)].Node*)->children.push_back((yysemantic_stack_[(6) - (5)].Node*)); (yyval.Node*) = (yysemantic_stack_[(6) - (1)].Node*) ;}
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1168 "syntax.yy"
    {(yysemantic_stack_[(6) - (1)].Node*)->children.push_back((yysemantic_stack_[(6) - (3)].Node*)); (yysemantic_stack_[(6) - (1)].Node*)->children.push_back("static");(yysemantic_stack_[(6) - (1)].Node*)->children.push_back((yysemantic_stack_[(6) - (5)].Node*)); (yyval.Node*) = (yysemantic_stack_[(6) - (1)].Node*) ;}
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1169 "syntax.yy"
    {(yysemantic_stack_[(5) - (1)].Node*)->children.push_back((yysemantic_stack_[(5) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(5) - (1)].Node*) ;}
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1170 "syntax.yy"
    {(yyval.Node*) = (yysemantic_stack_[(4) - (1)].Node*);}
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1171 "syntax.yy"
    {(yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*);}
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1172 "syntax.yy"
    {(yysemantic_stack_[(4) - (1)].Node*)->children.push_back((yysemantic_stack_[(4) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(4) - (1)].Node*) ;}
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1173 "syntax.yy"
    {(yysemantic_stack_[(4) - (1)].Node*)->children.push_back((yysemantic_stack_[(4) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(4) - (1)].Node*) ;}
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1174 "syntax.yy"
    {(yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*) ;}
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1178 "syntax.yy"
    {(yyval.Node*) = new TypeQualifierListNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1179 "syntax.yy"
    {(yysemantic_stack_[(2) - (1)].Node*)->children.push_back((yysemantic_stack_[(2) - (2)].Node*)); (yyval.Node*) = (yysemantic_stack_[(2) - (1)].Node*) ;}
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1183 "syntax.yy"
    {(yyval.Node*) = new TypeQualifierNode(new KeywordNode((yysemantic_stack_[(1) - (1)].std::string)));}
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1184 "syntax.yy"
    {(yyval.Node*) = new TypeQualifierNode(new KeywordNode((yysemantic_stack_[(1) - (1)].std::string)));}
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1185 "syntax.yy"
    {(yyval.Node*) = new TypeQualifierNode(new KeywordNode((yysemantic_stack_[(1) - (1)].std::string)));}
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1188 "syntax.yy"
    {(yyval.Node*) = new ParameterTypeList((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1189 "syntax.yy"
    {(yyval.Node*) = new ParameterTypeList((yysemantic_stack_[(3) - (1)].Node*), new KeywordNode((yysemantic_stack_[(3) - (3)].std::string)));}
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1193 "syntax.yy"
    {(yyval.Node*) = new ParameterListNode((yysemantic_stack_[(2) - (1)].Node*));}
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1194 "syntax.yy"
    {(yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*) ;}
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1198 "syntax.yy"
    {(yyval.Node*) = new ParameterDeclarationNode((yysemantic_stack_[(2) - (1)].Node*));}
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1199 "syntax.yy"
    {(yyval.Node*) = new ParameterDeclarationNode((yysemantic_stack_[(2) - (1)].Node*),(yysemantic_stack_[(2) - (2)].Node*));}
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1200 "syntax.yy"
    {(yyval.Node*) = new ParameterDeclarationNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1203 "syntax.yy"
    {(yyval.Node*) = new FunctionSpecifierNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1206 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1207 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1208 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1209 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1210 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1211 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1212 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1213 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1214 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1215 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1216 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1217 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1218 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1219 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1220 "syntax.yy"
    {(yyval.Node*) = new TypeSpecifierNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1224 "syntax.yy"
    {(yyval.Node*) = new StructOrUnionSpecifierNode((yysemantic_stack_[(5) - (1)].Node*), new IdentifierNode((yysemantic_stack_[(5) - (2)].std::string)),(yysemantic_stack_[(5) - (4)].Node*));}
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1225 "syntax.yy"
    {(yyval.Node*) = new StructOrUnionSpecifierNode((yysemantic_stack_[(4) - (1)].Node*), (yysemantic_stack_[(4) - (3)].Node*));}
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1226 "syntax.yy"
    {(yyval.Node*) = new StructOrUnionSpecifierNode((yysemantic_stack_[(2) - (1)].Node*), new IdentifierNode((yysemantic_stack_[(2) - (2)].std::string)));}
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1230 "syntax.yy"
    {(yyval.Node*) = new KeywordNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1231 "syntax.yy"
    {(yyval.Node*) = new KeywordNode((yysemantic_stack_[(1) - (1)].std::string));}
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1235 "syntax.yy"
    {(yyval.Node*) = new StructDeclarationListNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1236 "syntax.yy"
    {(yysemantic_stack_[(2) - (1)].Node*)->children.push_back((yysemantic_stack_[(2) - (2)].Node*)); (yyval.Node*) = (yysemantic_stack_[(2) - (1)].Node*) ;}
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1240 "syntax.yy"
    {(yyval.Node*) = new StructDeclarationNode((yysemantic_stack_[(3) - (1)].Node*),(yysemantic_stack_[(3) - (2)].Node*));}
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1244 "syntax.yy"
    {(yyval.Node*) = new StructDeclaratorListNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 1245 "syntax.yy"
    {(yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (2)].std::string)); (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*) ;}
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 1249 "syntax.yy"
    { (yyval.Node*) = new StructDeclaratorNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 1250 "syntax.yy"
    { (yyval.Node*) = new StructDeclaratorNode((yysemantic_stack_[(2) - (2)].Node*));}
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 1251 "syntax.yy"
    {{ (yyval.Node*) = new StructDeclaratorNode((yysemantic_stack_[(3) - (1)].Node*),(yysemantic_stack_[(3) - (3)].Node*));}}
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 1255 "syntax.yy"
    {(yysemantic_stack_[(2) - (2)].Node*)->children.push_back((yysemantic_stack_[(2) - (1)].Node*)); (yyval.Node*) = (yysemantic_stack_[(2) - (2)].Node*) ;}
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 1256 "syntax.yy"
    {(yyval.Node*) = new SpecifierQualifierListNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 1257 "syntax.yy"
    {(yysemantic_stack_[(2) - (2)].Node*)->children.push_back((yysemantic_stack_[(2) - (1)].Node*)); (yyval.Node*) = (yysemantic_stack_[(2) - (2)].Node*) ;}
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 1258 "syntax.yy"
    {(yyval.Node*) = new SpecifierQualifierListNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 1263 "syntax.yy"
    {(yyval.Node*) = new EnumSpecifierNode(new KeywordNode((yysemantic_stack_[(4) - (1)].std::string)), (yysemantic_stack_[(4) - (3)].Node*));}
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 1264 "syntax.yy"
    {(yyval.Node*) = new EnumSpecifierNode(new KeywordNode((yysemantic_stack_[(5) - (1)].std::string)),new IdentifierNode((yysemantic_stack_[(5) - (2)].std::string)), (yysemantic_stack_[(5) - (3)].std::string));}
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 1265 "syntax.yy"
    {(yyval.Node*) = new EnumSpecifierNode(new KeywordNode((yysemantic_stack_[(5) - (1)].std::string)), (yysemantic_stack_[(5) - (3)].Node*));}
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 1266 "syntax.yy"
    {(yyval.Node*) = new EnumSpecifierNode(new KeywordNode((yysemantic_stack_[(6) - (1)].std::string)),new IdentifierNode((yysemantic_stack_[(6) - (2)].std::string)), (yysemantic_stack_[(6) - (3)].std::string));}
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1267 "syntax.yy"
    {(yyval.Node*) = new EnumSpecifierNode(new KeywordNode((yysemantic_stack_[(2) - (1)].std::string)),new IdentifierNode((yysemantic_stack_[(2) - (2)].std::string)));}
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 1271 "syntax.yy"
    {(yyval.Node*) = new EnumeratorListNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 1272 "syntax.yy"
    {{(yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].Node*)); (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*) ;}}
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 1276 "syntax.yy"
    {(yyval.Node*) = new EnumeratorNode(new IdentifierNode((yysemantic_stack_[(1) - (1)].std::string)));}
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 1277 "syntax.yy"
    {(yyval.Node*) = new EnumeratorNode(new IdentifierNode((yysemantic_stack_[(3) - (1)].std::string)),(yysemantic_stack_[(3) - (3)].Node*));}
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 1281 "syntax.yy"
    {(yyval.Node*) = new TypeNameNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 1282 "syntax.yy"
    {(yyval.Node*) = new TypeNameNode((yysemantic_stack_[(2) - (1)].Node*),(yysemantic_stack_[(2) - (2)].Node*));}
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 1286 "syntax.yy"
    {(yyval.Node*) = new AbstractDeclaratorNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 1287 "syntax.yy"
    {(yyval.Node*) = new AbstractDeclaratorNode((yysemantic_stack_[(1) - (1)].Node*));}
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 1288 "syntax.yy"
    {(yyval.Node*) = new AbstractDeclaratorNode((yysemantic_stack_[(2) - (1)].Node*),(yysemantic_stack_[(2) - (2)].Node*));}
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 1292 "syntax.yy"
    { (yyval.Node*) = new DirectAbstractDeclaratorNode((yysemantic_stack_[(3) - (2)].Node*)); }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 1293 "syntax.yy"
    { (yyval.Node*) = new DirectAbstractDeclaratorNode(); }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 1294 "syntax.yy"
    { (yyval.Node*) = new DirectAbstractDeclaratorNode((yysemantic_stack_[(3) - (2)].Node*)); }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 1295 "syntax.yy"
    { (yysemantic_stack_[(3) - (1)].Node*)->children.push_back(new DirectAbstractDeclaratorNode()); }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 1296 "syntax.yy"
    { (yysemantic_stack_[(4) - (1)].Node*)->children.push_back(new DirectAbstractDeclaratorNode((yysemantic_stack_[(4) - (3)].Node*))); }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 1297 "syntax.yy"
    { (yyval.Node*) = new DirectAbstractDeclaratorNode(); }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 1298 "syntax.yy"
    { (yysemantic_stack_[(4) - (1)].Node*)->children.push_back(new DirectAbstractDeclaratorNode()); }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 1299 "syntax.yy"
    { (yyval.Node*) = new DirectAbstractDeclaratorNode(); }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 1300 "syntax.yy"
    { (yyval.Node*) = new DirectAbstractDeclaratorNode((yysemantic_stack_[(3) - (2)].Node*)); }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 1301 "syntax.yy"
    { (yysemantic_stack_[(3) - (1)].Node*)->children.push_back(new DirectAbstractDeclaratorNode()); }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 1302 "syntax.yy"
    { (yysemantic_stack_[(4) - (1)].Node*)->children.push_back(new DirectAbstractDeclaratorNode((yysemantic_stack_[(4) - (3)].Node*))); }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 1306 "syntax.yy"
    { (yyval.Node*) = new StatementNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 1307 "syntax.yy"
    { (yyval.Node*) = new StatementNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 1308 "syntax.yy"
    { (yyval.Node*) = new StatementNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 1309 "syntax.yy"
    { (yyval.Node*) = new StatementNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 1310 "syntax.yy"
    { (yyval.Node*) = new StatementNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 1311 "syntax.yy"
    { (yyval.Node*) = new StatementNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 1315 "syntax.yy"
    { (yyval.Node*) = new LabeledStatementNode((yysemantic_stack_[(3) - (3)].Node*)); }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 1316 "syntax.yy"
    { (yyval.Node*) = new LabeledStatementNode((yysemantic_stack_[(4) - (2)].Node*), (yysemantic_stack_[(4) - (4)].Node*)); }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 1317 "syntax.yy"
    { (yyval.Node*) = new LabeledStatementNode((yysemantic_stack_[(3) - (3)].Node*)); }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 1321 "syntax.yy"
    { (yyval.Node*) = new CompoundStatementNode(); }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 1322 "syntax.yy"
    { (yyval.Node*) = new CompoundStatementNode((yysemantic_stack_[(3) - (2)].Node*)); }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 1326 "syntax.yy"
    { (yyval.Node*) = new BlockItemList((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 1327 "syntax.yy"
    { (yysemantic_stack_[(2) - (1)].Node*)->children.push_back((yysemantic_stack_[(2) - (2)].Node*)); (yyval.Node*) = (yysemantic_stack_[(2) - (1)].Node*); }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 1331 "syntax.yy"
    { (yyval.Node*) = new BlockItemNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 1332 "syntax.yy"
    { (yyval.Node*) = new BlockItemNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 1336 "syntax.yy"
    { (yyval.Node*) = new ExpressionStatementNode(); }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 1337 "syntax.yy"
    { (yyval.Node*) = new ExpressionStatementNode((yysemantic_stack_[(2) - (1)].Node*)); }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 1341 "syntax.yy"
    { (yyval.Node*) = new SelectionStatementNode((yysemantic_stack_[(5) - (3)].Node*), (yysemantic_stack_[(5) - (5)].Node*)); }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 1342 "syntax.yy"
    { (yyval.Node*) = new SelectionStatementNode((yysemantic_stack_[(7) - (3)].Node*), (yysemantic_stack_[(7) - (5)].Node*), (yysemantic_stack_[(7) - (7)].Node*)); }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 1343 "syntax.yy"
    { (yyval.Node*) = new SelectionStatementNode((yysemantic_stack_[(5) - (3)].Node*), (yysemantic_stack_[(5) - (5)].Node*)); }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 1347 "syntax.yy"
    { (yyval.Node*) = new IterationStatementNode((yysemantic_stack_[(5) - (3)].Node*), (yysemantic_stack_[(5) - (5)].Node*)); }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 1348 "syntax.yy"
    { (yyval.Node*) = new IterationStatementNode((yysemantic_stack_[(7) - (2)].Node*), (yysemantic_stack_[(7) - (5)].Node*)); }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 1349 "syntax.yy"
    { (yyval.Node*) = new IterationStatementNode((yysemantic_stack_[(6) - (3)].Node*), (yysemantic_stack_[(6) - (4)].Node*), (yysemantic_stack_[(6) - (6)].Node*)); }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 1350 "syntax.yy"
    { (yyval.Node*) = new IterationStatementNode((yysemantic_stack_[(7) - (3)].Node*), (yysemantic_stack_[(7) - (4)].Node*), (yysemantic_stack_[(7) - (5)].Node*), (yysemantic_stack_[(7) - (6)].std::string)); }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 1351 "syntax.yy"
    { (yyval.Node*) = new IterationStatementNode((yysemantic_stack_[(6) - (3)].Node*), (yysemantic_stack_[(6) - (4)].Node*), (yysemantic_stack_[(6) - (6)].Node*)); }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 1352 "syntax.yy"
    { (yyval.Node*) = new IterationStatementNode((yysemantic_stack_[(7) - (3)].Node*), (yysemantic_stack_[(7) - (4)].Node*), (yysemantic_stack_[(7) - (5)].Node*), (yysemantic_stack_[(7) - (6)].std::string)); }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 1356 "syntax.yy"
    { (yyval.Node*) = new JumpStatementNode((yysemantic_stack_[(3) - (2)].std::string)); }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 1357 "syntax.yy"
    { (yyval.Node*) = new JumpStatementNode(); }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 1358 "syntax.yy"
    { (yyval.Node*) = new JumpStatementNode(); }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 1359 "syntax.yy"
    { (yyval.Node*) = new JumpStatementNode(); }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 1360 "syntax.yy"
    { (yyval.Node*) = new JumpStatementNode((yysemantic_stack_[(3) - (2)].Node*)); }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 1364 "syntax.yy"
    { (yyval.Node*) = new TranslationUnitNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 1365 "syntax.yy"
    { (yysemantic_stack_[(2) - (1)].Node*)->children.push_back((yysemantic_stack_[(2) - (2)].Node*)); (yyval.Node*) = (yysemantic_stack_[(2) - (1)].Node*); }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 1369 "syntax.yy"
    { (yyval.Node*) = new ExternalDeclarationNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 1370 "syntax.yy"
    { (yyval.Node*) = new ExternalDeclarationNode((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 1374 "syntax.yy"
    { (yyval.Node*) = new FunctionDeclarationNode((yysemantic_stack_[(4) - (1)].Node*), (yysemantic_stack_[(4) - (2)].Node*), (yysemantic_stack_[(4) - (3)].Node*), (yysemantic_stack_[(4) - (4)].Node*)); }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 1375 "syntax.yy"
    { (yyval.Node*) = new FunctionDeclarationNode((yysemantic_stack_[(3) - (1)].Node*), (yysemantic_stack_[(3) - (2)].Node*), (yysemantic_stack_[(3) - (3)].Node*)); }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 1379 "syntax.yy"
    { (yyval.Node*) = new DeclarationList((yysemantic_stack_[(1) - (1)].Node*)); }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 1380 "syntax.yy"
    { (yysemantic_stack_[(2) - (1)].Node*)->children.push_back((yysemantic_stack_[(2) - (2)].Node*)); (yyval.Node*) = (yysemantic_stack_[(2) - (1)].Node*); }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 1384 "syntax.yy"
    { (yyval.Node*) = new IdentifierList((yysemantic_stack_[(1) - (1)].std::string)); }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 1385 "syntax.yy"
    { (yysemantic_stack_[(3) - (1)].Node*)->children.push_back((yysemantic_stack_[(3) - (3)].std::string)); (yyval.Node*) = (yysemantic_stack_[(3) - (1)].Node*); }
    break;



/* Line 678 of lalr1.cc  */
#line 2801 "bis_out.cpp"
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
  const short int parser::yypact_ninf_ = -321;
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

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
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

  /* YYPGOTO[NTERM-NUM].  */
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

  /* YYDEFGOTO[NTERM-NUM].  */
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

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char parser::yytable_ninf_ = -1;
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

  /* YYCHECK.  */
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

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
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
       2,     1,     4,     5,     5,     6,     2,     1,     3,     1,
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
      49,   139,    50,    -1,    15,    49,   139,    44,    50,    -1,
      15,    40,    49,   139,    44,    50,    -1,    15,    40,    -1,
     140,    -1,   139,    44,   140,    -1,    40,    -1,    40,    53,
     110,    -1,   137,    -1,   137,   142,    -1,   122,    -1,   143,
      -1,   122,   143,    -1,    46,   142,    47,    -1,    51,    52,
      -1,    51,   107,    52,    -1,   143,    51,    52,    -1,   143,
      51,   107,    52,    -1,    51,    59,    52,    -1,   143,    51,
      59,    52,    -1,    46,    47,    -1,    46,   126,    47,    -1,
     143,    46,    47,    -1,   143,    46,   126,    47,    -1,   145,
      -1,   146,    -1,   149,    -1,   150,    -1,   151,    -1,   152,
      -1,    40,    45,   144,    -1,     6,   110,    45,   144,    -1,
      11,    45,   144,    -1,    49,    50,    -1,    49,   147,    50,
      -1,   148,    -1,   147,   148,    -1,   111,    -1,   144,    -1,
      43,    -1,   109,    43,    -1,    20,    46,   109,    47,   144,
      -1,    20,    46,   109,    47,   144,    14,   144,    -1,    33,
      46,   109,    47,   144,    -1,    39,    46,   109,    47,   144,
      -1,    12,   144,    39,    46,   109,    47,    43,    -1,    18,
      46,   149,   149,    47,   144,    -1,    18,    46,   149,   149,
     109,    47,   144,    -1,    18,    46,   111,   149,    47,   144,
      -1,    18,    46,   111,   149,   109,    47,   144,    -1,    19,
      40,    43,    -1,    10,    43,    -1,     5,    43,    -1,    27,
      43,    -1,    27,   109,    43,    -1,   154,    -1,   153,   154,
      -1,   155,    -1,   111,    -1,   112,   121,   156,   146,    -1,
     112,   121,   146,    -1,   111,    -1,   156,   111,    -1,    40,
      -1,   157,    44,    40,    -1
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
     518,   521,   523,   528,   534,   540,   547,   550,   552,   556,
     558,   562,   564,   567,   569,   571,   574,   578,   581,   585,
     589,   594,   598,   603,   606,   610,   614,   619,   621,   623,
     625,   627,   629,   631,   635,   640,   644,   647,   651,   653,
     656,   658,   660,   662,   665,   671,   679,   685,   691,   699,
     706,   714,   721,   729,   733,   736,   739,   742,   746,   748,
     751,   753,   755,   760,   764,   766,   769,   771
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   951,   951,   952,   953,   954,   958,   959,   960,   961,
     962,   963,   964,   965,   966,   967,   971,   972,   976,   977,
     978,   979,   980,   981,   985,   986,   987,   988,   989,   990,
     994,   995,   999,  1000,  1001,  1002,  1006,  1007,  1008,  1012,
    1013,  1014,  1018,  1019,  1020,  1021,  1022,  1026,  1027,  1028,
    1032,  1033,  1037,  1038,  1042,  1043,  1047,  1048,  1052,  1053,
    1057,  1058,  1062,  1063,  1067,  1068,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1081,  1082,  1087,  1091,  1092,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1106,  1107,
    1108,  1109,  1113,  1114,  1118,  1119,  1123,  1124,  1125,  1129,
    1130,  1131,  1132,  1136,  1140,  1141,  1145,  1146,  1150,  1151,
    1155,  1156,  1157,  1158,  1162,  1163,  1164,  1165,  1166,  1167,
    1168,  1169,  1170,  1171,  1172,  1173,  1174,  1178,  1179,  1183,
    1184,  1185,  1188,  1189,  1193,  1194,  1198,  1199,  1200,  1203,
    1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,
    1216,  1217,  1218,  1219,  1220,  1224,  1225,  1226,  1230,  1231,
    1235,  1236,  1240,  1244,  1245,  1249,  1250,  1251,  1255,  1256,
    1257,  1258,  1263,  1264,  1265,  1266,  1267,  1271,  1272,  1276,
    1277,  1281,  1282,  1286,  1287,  1288,  1292,  1293,  1294,  1295,
    1296,  1297,  1298,  1299,  1300,  1301,  1302,  1306,  1307,  1308,
    1309,  1310,  1311,  1315,  1316,  1317,  1321,  1322,  1326,  1327,
    1331,  1332,  1336,  1337,  1341,  1342,  1343,  1347,  1348,  1349,
    1350,  1351,  1352,  1356,  1357,  1358,  1359,  1360,  1364,  1365,
    1369,  1370,  1374,  1375,  1379,  1380,  1384,  1385
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
  const int parser::yylast_ = 1561;
  const int parser::yynnts_ = 69;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 62;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 89;

  const unsigned int parser::yyuser_token_number_max_ = 343;
  const parser::token_number_type parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // yy

/* Line 1054 of lalr1.cc  */
#line 3869 "bis_out.cpp"


/* Line 1056 of lalr1.cc  */
#line 1388 "syntax.yy"


// Epilogue

namespace yy

int main ()
{
  yy::parser parse;
  return parse ();
}
