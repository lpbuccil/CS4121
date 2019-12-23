/*******************************************************/
/*                     Cminus Parser                   */
/*                                                     */
/*******************************************************/

/*********************DEFINITIONS***********************/
%{
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <util/general.h>
#include <util/symtab.h>
#include <util/symtab_stack.h>
#include <util/dlink.h>
#include <util/string_utils.h>
#include <codegen/symfields.h>
#include <codegen/types.h>
#include <codegen/codegen.h>
#include <codegen/reg.h>

#define SYMTABLE_SIZE 100

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,Cminus_error,(char*));

EXTERN(int,Cminus_lex,(void));

SymTable symtab;

static DList instList;
static DList dataList;

char *fileName;

static int functionOffset;
int globalOffset = 0;
static char* functionName;

extern union YYSTYPE yylval;

extern int Cminus_lineno;

%}

%name-prefix="Cminus_"
%defines

%start Program

%token AND
%token ELSE
%token EXIT
%token FLOAT
%token FOR
%token IF 		
%token INTEGER 
%token NOT 		
%token OR 		
%token READ
%token WHILE
%token WRITE
%token LBRACE
%token RBRACE
%token LE
%token LT
%token GE
%token GT
%token EQ
%token NE
%token ASSIGN
%token COMMA
%token SEMICOLON
%token LBRACKET
%token RBRACKET
%token LPAREN
%token RPAREN
%token PLUS
%token TIMES
%token IDENTIFIER
%token DIVIDE
%token RETURN
%token STRING	
%token INTCON
%token FLOATCON
%token MINUS

%left OR
%left AND
%left NOT
%left LT LE GT GE NE EQ
%left PLUS MINUS
%left TIMES DIVDE

%union {
	char*	name;
	int     symIndex;
	DList	idList;
	int 	offset;
}

%type <idList> IdentifierList
%type <symIndex> Expr SimpleExpr AddExpr
%type <symIndex> MulExpr Factor Variable StringConstant Constant VarDecl FunctionDecl ProcedureHead
%type <offset> DeclList
%type <name> IDENTIFIER STRING FLOATCON INTCON 

/***********************PRODUCTIONS****************************/
%%
Program		: Procedures 
		{
			emitDataPrologue(dataList);
			emitInstructions(instList);
		}
	  	| DeclList Procedures
		{
			globalOffset = $1;
			emitDataPrologue(dataList);
			emitInstructions(instList);
		}
          ;

Procedures 	: ProcedureDecl Procedures
	   	|
	   	;

ProcedureDecl : ProcedureHead ProcedureBody
               {
			emitExit(instList);
               }
	      ;

ProcedureHead : FunctionDecl DeclList 
		{
			emitProcedurePrologue(instList,symtab,$1,$2);
			functionOffset = $2;
			$$ = $1;
		}
	      | FunctionDecl
		{
			emitProcedurePrologue(instList,symtab,$1,0);
			functionOffset = 0;
			$$ = $1;
		}
              ;

FunctionDecl :  Type IDENTIFIER LPAREN RPAREN LBRACE 
		{
			$$ = SymIndex(symtab,$2);
		}
	      	;

ProcedureBody : StatementList RBRACE
	      ;


DeclList 	: Type IdentifierList  SEMICOLON 
		{
			AddIdStructPtr data = (AddIdStructPtr)malloc(sizeof(AddIdStruct));
			data->offset = 0;
			data->offsetDirection = 1;
			data->symtab = symtab;
			dlinkApply1($2,(DLinkApply1Func)addIdToSymtab,(Generic)data);
			$$ = data->offset;
			dlinkFreeNodes($2);
			
			free(data);
		}		
	   	| DeclList Type IdentifierList SEMICOLON
	 	{
			AddIdStructPtr data = (AddIdStructPtr)malloc(sizeof(AddIdStruct));
			data->offset = $1;
			data->offsetDirection = 1;
			data->symtab = symtab;
			dlinkApply1($3,(DLinkApply1Func)addIdToSymtab,(Generic)data);
			$$ = data->offset;
			dlinkFreeNodes($3);
			free(data);
	 	}
          	;


IdentifierList 	: VarDecl  
		{
			$$ = dlinkListAlloc(NULL);
			dlinkAppend($$,dlinkNodeAlloc((Generic)$1));
			
			
			
		}
						
                | IdentifierList COMMA VarDecl
		{
			dlinkAppend($1,dlinkNodeAlloc((Generic)$3));
			
			$$ = $1;
		}
                ;

VarDecl 	: IDENTIFIER
		{ 
			$$ = SymIndex(symtab,$1);
		}
		| IDENTIFIER LBRACKET INTCON RBRACKET
		{
			$$ = SYM_INVALID_INDEX;
		}
		;

Type     	: INTEGER 
                | FLOAT   
                ;

Statement 	: Assignment
                | IfStatement
		| WhileStatement
                | IOStatement 
		| ReturnStatement
		| ExitStatement	
		| CompoundStatement
                ;

Assignment      : Variable ASSIGN Expr SEMICOLON
		{
			emitAssignment(instList,symtab,$1,$3);
		}
                ;
				
IfStatement	: IF TestAndThen ELSE CompoundStatement
		| IF TestAndThen
		;
		
				
TestAndThen	: Test CompoundStatement
		;
				
Test		: LPAREN Expr RPAREN
		;
	

WhileStatement  : WhileToken WhileExpr Statement
                ;
                
WhileExpr	: LPAREN Expr RPAREN
		;
				
WhileToken	: WHILE
		;


IOStatement     : READ LPAREN Variable RPAREN SEMICOLON
		{
			emitReadVariable(instList,symtab,$3);
		}
                | WRITE LPAREN Expr RPAREN SEMICOLON
		{
			emitWriteExpression(instList,symtab,$3,SYSCALL_PRINT_INTEGER);
		}
                | WRITE LPAREN StringConstant RPAREN SEMICOLON         
		{
			emitWriteExpression(instList,symtab,$3,SYSCALL_PRINT_STRING);
		}
                ;

ReturnStatement : RETURN Expr SEMICOLON
                ;

ExitStatement 	: EXIT SEMICOLON
		{
			emitExit(instList);
		}
		;

CompoundStatement : LBRACE StatementList RBRACE
                ;

StatementList   : Statement
		
                | StatementList Statement
		
                ;

Expr            : SimpleExpr
		{
			$$ = $1; 
		}
                | Expr OR SimpleExpr 
		{
			$$ = emitOrExpression(instList,symtab,$1,$3);
		}
                | Expr AND SimpleExpr 
		{
			$$ = emitAndExpression(instList,symtab,$1,$3);
		}
                | NOT SimpleExpr 
		{
			$$ = emitNotExpression(instList,symtab,$2);
		}
                ;

SimpleExpr	: AddExpr
		{
			$$ = $1; 
		}
                | SimpleExpr EQ AddExpr
		{
			$$ = emitEqualExpression(instList,symtab,$1,$3);
		}
                | SimpleExpr NE AddExpr
		{
			$$ = emitNotEqualExpression(instList,symtab,$1,$3);
		}
                | SimpleExpr LE AddExpr
		{
			$$ = emitLessEqualExpression(instList,symtab,$1,$3);
		}
                | SimpleExpr LT AddExpr
		{
			$$ = emitLessThanExpression(instList,symtab,$1,$3);
		}
                | SimpleExpr GE AddExpr
		{
			$$ = emitGreaterEqualExpression(instList,symtab,$1,$3);
		}
                | SimpleExpr GT AddExpr
		{
			$$ = emitGreaterThanExpression(instList,symtab,$1,$3);
		}
                ;

AddExpr		:  MulExpr            
		{
			$$ = $1; 
		}
                |  AddExpr PLUS MulExpr
		{
			$$ = emitAddExpression(instList,symtab,$1,$3);
		}
                |  AddExpr MINUS MulExpr
		{
			$$ = emitSubtractExpression(instList,symtab,$1,$3);
		}
                ;

MulExpr		:  Factor
		{
			$$ = $1; 
		}
                |  MulExpr TIMES Factor
		{
			$$ = emitMultiplyExpression(instList,symtab,$1,$3);
		}
                |  MulExpr DIVIDE Factor
		{
			$$ = emitDivideExpression(instList,symtab,$1,$3);
		}		
                ;
				
Factor          : Variable
		{ 
			$$ = emitLoadVariable(instList,symtab,$1);
		}
                | Constant
		{ 
			$$ = $1;
		}
                | IDENTIFIER LPAREN RPAREN
		{
			$$ = SYM_INVALID_INDEX;
		}
         	| LPAREN Expr RPAREN
		{
			$$ = $2;
		}
                ;  

Variable        : IDENTIFIER
		{
			int symIndex = SymQueryIndex(symtab,$1);
			$$ = emitComputeVariableAddress(instList,symtab,symIndex);
			int offset = (int)SymGetFieldByIndex(symtab,symIndex,SYMTAB_OFFSET_FIELD);
	
			
		}
                | IDENTIFIER LBRACKET Expr RBRACKET    
		{
			$$ = SYM_INVALID_INDEX;
		}
                ;			       

StringConstant 	: STRING
		{ 
			int symIndex = SymIndex(symtab,$1);
			$$ = emitLoadStringConstantAddress(instList,dataList,symtab,symIndex); 
		}
                ;

Constant        :  INTCON
		{ 
			int symIndex = SymIndex(symtab,$1);
			$$ = emitLoadIntegerConstant(instList,symtab,symIndex); 
		}
                ;

%%


/********************C ROUTINES *********************************/

void Cminus_error(char *s)
{
  fprintf(stderr,"%s: line %d: %s\n",fileName,Cminus_lineno,s);
}

int Cminus_wrap() {
	return 1;
}

static void initSymTable() {

	symtab = SymInit(SYMTABLE_SIZE); 

	SymInitField(symtab,SYMTAB_OFFSET_FIELD,(Generic)-1,NULL);
	SymInitField(symtab,SYMTAB_REGISTER_INDEX_FIELD,(Generic)-1,NULL);
}

static void deleteSymTable() {
    SymKillField(symtab,SYMTAB_REGISTER_INDEX_FIELD);
    SymKillField(symtab,SYMTAB_OFFSET_FIELD);
    SymKill(symtab);

}

static void initialize(char* inputFileName) {

	stdin = freopen(inputFileName,"r", stdin);
        if (stdin == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
          exit(-1);
        }

	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);
	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w", stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
       } 

	initSymTable();
	
	initRegisters();
	
	instList = dlinkListAlloc(NULL);
	dataList = dlinkListAlloc(NULL);

}

static void finalize() {

    fclose(stdin);
    /*fclose(stdout);*/
    
    deleteSymTable();
 
    cleanupRegisters();
    
    dlinkFreeNodesAndAtoms(instList);
    dlinkFreeNodesAndAtoms(dataList);

}

int main(int argc, char** argv)

{	
	fileName = argv[1];
	initialize(fileName);
	
        Cminus_parse();
  
  	finalize();
  
  	return 0;
}
/******************END OF C ROUTINES**********************/
