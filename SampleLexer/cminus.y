%{
#include <stdio.h>
#include <stdlib.h>

int yyerror(char * s);
extern int yylex(void);
%}

%token IF 
%token ELSE
%token RETURN
%token INT
%token VOID
%token WHILE
%token ID
%token NUM
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

%% 

program: declaration_list 
	   ;
	   
declaration_list: declaration declaration_list 
                | declaration 
				;
				
selection_stmt : IF LEFT_PRNTS expression RIGHT_PRNTS statement
			   | IF LEFT_PRNTS expression RIGHT_PRNTS statement ELSE statement 
			   ;
			   
iteration_stmt : WHILE LEFT_PRNTS expression RIGHT_PRNTS statement 
				;
				
declaration : var_declaration
            | fun_declaration
            ;
			
var_declaration : type_specifier ID SEMICOLON
				| type_specifier ID LEFT_BRACKET NUM RIGHT_BRACKET SEMICOLON
                ;

type_specifier : INT 
				| VOID
				;
				
fun_declaration : type_specifier ID LEFT_PRNTS params RIGHT_PRNTS compound_stmt
                ;
				
params : params_list
	   | VOID
	   ;
	   
params_list : params_list COMMA param
			| param
			;
			
param : type_specifier ID
	  | type_specifier ID LEFT_BRACKET RIGHT_BRACKET
	  ;
	  
compound_stmt : LEFT_BRACE local_declarations statement_list RIGHT_BRACE
			  ;

local_declarations : 
				   |local_declarations var_declaration
				   ;
				   
statement_list : 
			   | statement_list statement
			   ;

statement : expression_stmt
		  | compound_stmt
		  | selection_stmt
		  | iteration_stmt
		  | return_stmt
		  ;
		  
expression_stmt : expression SEMICOLON
				| SEMICOLON
				;
			   

return_stmt : RETURN SEMICOLON
			| RETURN expression SEMICOLON
			;
			
expression : var EQUAL expression 
		   | simple_expression 
		   ;
		   
var : ID 
	| ID LEFT_BRACKET expression RIGHT_BRACKET 
	;
	
simple_expression : additive_expression relop additive_expression
				  | additive_expression
				  ;
				
relop : LESS_OR_EQUAL 
	  | LESS 
	  | GREATER 
	  | GREATER_OR_EQUAL 
	  | EQUAL 
	  | NOT_EQUAL 
	  ;

additive_expression : additive_expression addop term 
					| term
					;
					
addop : ADD 
	  | SUBSTRACT 
	  ;
	  
term : term mulop factor
	 | factor
	 ;
	 
mulop : MULTIPLY
	  | DIVIDE
	  ;
	  
factor : LEFT_PRNTS expression RIGHT_PRNTS
	   | var
	   | call 
	   | NUM 
	   ;
	   
call : ID LEFT_PRNTS args RIGHT_PRNTS 
	 ;
	 
args :
	 | args_list 
	 ;
	 
args_list : args_list COMMA expression
		  | expression
		  ;
	  
%%


int yyerror(char * s) 
/* yacc error handler */
{    
	printf ( "%s\n", s); 
	return 0;
}  