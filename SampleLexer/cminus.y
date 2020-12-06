%{
#include <stdio.h>
#include <stdlib.h>
#include "AST.h"

ASTNode* astRoot = NULL;
int yyerror(char * s);
extern int yylex(void);
%}

%union{
     char* name;            
     int value;                
     struct ASTNode* node;      
 }

%token IF 
%token ELSE
%token RETURN
%token INT
%token VOID
%token WHILE

%token <name>ID
%token <value>NUM

%token LESS_OR_EQUAL
%token GREATER_OR_EQUAL
%token EQUAL
%token NOT_EQUAL
%token LEFT_PRNTS
%token RIGHT_PRNTS
%token LEFT_BRACKET
%token RIGHT_BRACKET
%token LEFT_BRACE
%token RIGHT_BRACE
%token ADD
%token SUBSTRACT
%token MULTIPLY
%token DIVIDE
%token MOD
%token LESS
%token GREATER
%token ASSIGN
%token SEMICOLON
%token COMMA

%type <node> program 
%type <node> declaration_list
%type <node> declaration
%type <node> var_declaration
%type <node> type_specifier
%type <node> fun_declaration 
%type <node> params
%type <node> params_list
%type <node> param
%type <node> compound_stmt
%type <node> local_declarations
%type <node> statement_list
%type <node> statement
%type <node> expression_stmt
%type <node> selection_stmt
%type <node> iteration_stmt
%type <node> return_stmt
%type <node> expression
%type <node> var
%type <node> simple_expression
%type <node> additive_expression
%type <node> term
%type <node> factor
%type <node> call
%type <node> args 
%type <node> args_list

%type <node> relop addop mulop

%start program
%% 

program: declaration_list			{astRoot = createProgramUnitNode($1); $$ = astRoot;}
	   ;
	   
declaration_list: declaration declaration_list			{
															addLinkToList($$, $1);
															$$ = $2;
														}
                | declaration							{addLinkToList($$, $1);}
				;
				
selection_stmt : IF LEFT_PRNTS expression RIGHT_PRNTS statement							{ $$ = createIfStatement($3, $5, NULL);}
			   | IF LEFT_PRNTS expression RIGHT_PRNTS statement ELSE statement			{ $$ = createIfStatement($3, $5, $7);}
			   ;
			   
iteration_stmt : WHILE LEFT_PRNTS expression RIGHT_PRNTS statement			{$$ = createWhileStatement($3);}
				;
				
declaration : var_declaration			{$$ = createDeclarationNode($1);}
            | fun_declaration			{$$ = createDeclarationNode($1);}
            ;
			
var_declaration : type_specifier ID SEMICOLON									{$$ = createVarDeclaration($1, $2, 0);}
				| type_specifier ID LEFT_BRACKET NUM RIGHT_BRACKET SEMICOLON	{$$ = createVarDeclaration($1, $2, $4);}
                ;

type_specifier : INT			{$$ = createTypeSpecifier("INT");}		
				| VOID			{$$ = createTypeSpecifier("VOID");}
				;
				
fun_declaration : type_specifier ID LEFT_PRNTS params RIGHT_PRNTS compound_stmt			{$$ = createFunctionDeclarationNode($1, $2, $4, $6);}
                ;
				
params : params_list			{$$ = createParametersDeclarationNode($1);}
	   | VOID					{$$ = createParametersDeclarationNode(NULL);}
	   ;
	   
params_list : params_list COMMA param			{
													$$ = $1;
													addLinkToList($$, $3);
												}
			| param								{$$ = createListNode("ParametersList", $1);}
			;
			
param : type_specifier ID									{ $$ = createVarDeclaration($1, $2, 0);}
	  | type_specifier ID LEFT_BRACKET RIGHT_BRACKET		{ $$ = createVarDeclaration($1, $2, 0);}
	  ;
	  
compound_stmt : LEFT_BRACE local_declarations statement_list RIGHT_BRACE		{$$ = createCompoundStatement($2, $3);}
			  ;

local_declarations :													{$$ = NULL;}
				   |local_declarations var_declaration					{
																			$$ = $1;
																			addLinkToList($$, $2); 
																		}	
				   ;
				   
statement_list :														{$$ = NULL;}
			   | statement_list statement								{
																			$$ = $1;
																			addLinkToList($$, $2);
																		}	
			   ;

statement : expression_stmt					{$$ = createStatementNode($1);}
		  | compound_stmt					{$$ = createStatementNode($1);}
		  | selection_stmt					{$$ = createStatementNode($1);}
		  | iteration_stmt					{$$ = createStatementNode($1);}
		  | return_stmt						{$$ = createStatementNode($1);}
		  ;
		  
expression_stmt : expression SEMICOLON			{$$ = createExpressionStatement($1);}
				| SEMICOLON						{$$ = createExpressionStatement(NULL);}
				;
			   

return_stmt : RETURN SEMICOLON					{$$ = createReturnStatement(NULL);}
			| RETURN expression SEMICOLON		{$$ = createReturnStatement($2);}
			;
			
expression : var ASSIGN expression			{
												addLinkToList($$, $1);
												$$ = $3;
											}
		   | simple_expression				{$$ = createExpressionNode($1);}
		   ;
		   
var : ID											{$$ = createVarNode($1, NULL);}
	| ID LEFT_BRACKET expression RIGHT_BRACKET		{$$ = createVarNode($1, $3);}
	;
	
simple_expression : additive_expression relop additive_expression		{$$ = createSimpleExpresion($1,$2,$3);}
				  | additive_expression									{$$ = $1;}
				  ;
				
relop : LESS_OR_EQUAL				{$$ = LESS_OR_EQUAL;}
	  | LESS						{$$ = LESS;}
	  | GREATER						{$$ = GREATER;}
	  | GREATER_OR_EQUAL			{$$ = GREATER_OR_EQUAL;}
	  | EQUAL						{$$ = EQUAL;}
	  | NOT_EQUAL					{$$ = NOT_EQUAL;}
	  ;

additive_expression : additive_expression addop term				{$$ = createAdditiveExpression($1,$2,$3);}
					| term											{$$ = $1;}
					;
					
addop : ADD							{$$ = ADD;}
	  | SUBSTRACT					{$$ = SUBSTRACT;}
	  ;
	  
term : term mulop factor			{$$ = createTerm($1,$2,$3);}
	 | factor						{$$ = $1;}
	 ;
	 
mulop : MULTIPLY					{$$ = MULTIPLY;}
	  | DIVIDE						{$$ = DIVIDE;}
	  ;
	  
factor : LEFT_PRNTS expression RIGHT_PRNTS			{$$ = $2;}
	   | var										{$$ = $1;}
	   | call										{$$ = $1;}
	   | NUM										{$$ = createNumNode($1);}
	   ;
	   
call : ID LEFT_PRNTS args RIGHT_PRNTS				{$$ = createCall($1, $3);}
	 ;
	 
args :								{$$ = NULL;}	
	 | args_list					{$$ = $1;}
	 ;
	 
args_list : args_list COMMA expression				{$$ = createArgumentList($1, $3);}
		  | expression								{$$ = $1;}
		  ;
	  
%%


int yyerror(char * s) 
/* yacc error handler */
{    
	printf ( "%s\n", s); 
	return 0;
}  