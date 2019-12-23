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
#define SYMTAB_VALUE_FIELD     "value"

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,Cminus_error,(const char*));

EXTERN(int,Cminus_lex,(void));



char *fileName;

SymTable symtab;
SymtabStack symstack;

int globalOffset = 0;
static int functionOffset;

static DList instList;
static DList dataList;

extern int Cminus_lineno;

extern FILE *Cminus_in;
%}

%name-prefix="Cminus_"
%defines

%start Program

%token AND
%token ELSE
%token EXIT
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
%type <symIndex> MulExpr Factor Variable StringConstant Constant VarDecl FunctionDecl ProcedureHead ReturnStatement
%type <offset> DeclList
%type <name> IDENTIFIER STRING INTCON 



/***********************PRODUCTIONS****************************/
%%
   Program		: Procedures 
		{
			//printf("<Program> -> <Procedures>\n");
			emitDataPrologue(dataList);
			emitInstructions(instList);
		}
	  	| DeclList Procedures
		{
			//printf("<Program> -> <DeclList> <Procedures>\n");
			globalOffset = $1;
			emitDataPrologue(dataList);
			emitInstructions(instList);
		}
          ;

Procedures 	: ProcedureDecl Procedures
		{
			//printf("<Procedures> -> <ProcedureDecl> <Procedures>\n");
		}
	   	|
		{
			//printf("<Procedures> -> epsilon\n");
		}
	   	;

ProcedureDecl : ProcedureHead ProcedureBody
		{
			//printf("<ProcedureDecl> -> <ProcedureHead> <ProcedureBody>\n");
		}
              ;

ProcedureHead : FunctionDecl DeclList 
		{
			emitProcedurePrologue(instList,symtab,$1);
			
		}
	      | FunctionDecl
		{
			//printf("<ProcedureHead> -> <FunctionDecl>\n");
			emitProcedurePrologue(instList, symtab,$1);
			$$ = $1;
		}
              ;

FunctionDecl :  Type IDENTIFIER LPAREN RPAREN LBRACE 
		{
			//printf("<FunctionDecl> ->  <Type> <IDENTIFIER> <LP> <RP> <LBR>\n"); 
			$$ = SymIndex(symtab,$2);
		}
	      	;

ProcedureBody : StatementList RBRACE
		{
			//printf("<ProcedureBody> -> <StatementList> <RBR>\n");
		}
	      ;


DeclList 	: Type IdentifierList  SEMICOLON 
		{
			//printf("<DeclList> -> <Type> <IdentifierList> <SC>\n");
			$$ = $2;
		}		
	   	| DeclList Type IdentifierList SEMICOLON
	 	{
			//printf("<DeclList> -> <DeclList> <Type> <IdentifierList> <SC>\n");
	 	}
          	;


IdentifierList 	: VarDecl  
		{	
			//printf("<IdentifierList> -> <VarDecl>\n");
			$$ = $1;
		}
						
                | IdentifierList COMMA VarDecl
		{
		}
                ;

VarDecl 	: IDENTIFIER
		{ 
			//printf("<VarDecl> -> <IDENTIFIER> \n");
			int symIndex = SymIndex(symtab,$1);
			makeDataVariableDeclaration(dataList,symtab,symIndex);
		}
		| IDENTIFIER LBRACKET INTCON RBRACKET
                {
			//printf("<VarDecl> -> <IDENTIFIER> <LBK> <INTCON> <RBK>\n");
		}
		;

Type     	: INTEGER 
		{ 
			//printf("<Type> -> <INTEGER>\n");
		}
                ;

Statement 	: Assignment
		{ 
			//printf("<Statement> -> <Assignment>\n");
		}
                | IfStatement
		{ 
			//printf("<Statement> -> <IfStatement>\n");
		}
		| WhileStatement
		{ 
			//printf("<Statement> -> <WhileStatement>\n");
		}
                | IOStatement 
		{ 
			//printf("<Statement> -> <IOStatement>\n");
		}
		| ReturnStatement
		{ 
			//printf("<Statement> -> <ReturnStatement>\n");
		}
		| ExitStatement	
		{ 
			//printf("<Statement> -> <ExitStatement>\n");
		}
		| CompoundStatement
		{ 
			//printf("<Statement> -> <CompoundStatement>\n");
		}
                ;

Assignment      : Variable ASSIGN Expr SEMICOLON
		{
			//printf("<Assignment> -> <Variable> <ASSIGN> <Expr> <SEMICOLON>\n");
			emitAssignVariable(instList, symtab, $1, $3);
			
			
		}
                ;
				
IfStatement	: IF TestAndThen ELSE CompoundStatement
		{
			//printf("<IfStatement> -> <IF> <TestAndThen> <ELSE> <CompoundStatement>\n");
		}
		| IF TestAndThen
		{
			//printf("<IfStatement> -> <IF> <TestAndThen>\n");
		}
		;
		
				
TestAndThen	: Test CompoundStatement
		{
			//printf("<TestAndThen> -> <Test> <CompoundStatement>\n");
		}
		;
				
Test		: LPAREN Expr RPAREN
		{
			//printf("<Test> -> <LP> <Expr> <RP>\n");
		}
		;
	

WhileStatement  : WhileToken WhileExpr Statement
		{
			//printf("<WhileStatement> -> <WhileToken> <WhileExpr> <Statement>\n");
		}
                ;
                
WhileExpr	: LPAREN Expr RPAREN
		{
			//printf("<WhileExpr> -> <LP> <Expr> <RP>\n");
		}
		;
				
WhileToken	: WHILE
		{
			//printf("<WhileToken> -> <WHILE>\n");
		}
		;


IOStatement     : READ LPAREN Variable RPAREN SEMICOLON
		{
		  	emitReadSysCall(instList, symtab, $3);
			 ////printf("Read variable\n");
		}
                | WRITE LPAREN Expr RPAREN SEMICOLON
		{
			emitWriteSysCall(instList, symtab, $3, 1);
			//printf("Print expr\n");
		}
                | WRITE LPAREN StringConstant RPAREN SEMICOLON         
		{
		  	emitWriteSysCall(instList, symtab, $3, 4);
		}
                ;

ReturnStatement : RETURN Expr SEMICOLON
		{
			//printf("<ReturnStatement> -> <RETURN> <Expr> <SC>\n");
		}
                ;

ExitStatement 	: EXIT SEMICOLON
		{
			//printf("<ExitStatement> -> <EXIT> <SC>\n");
		}
		;

CompoundStatement : LBRACE StatementList RBRACE
		{
			//printf("<CompoundStatement> -> <LBR> <StatementList> <RBR>\n");
		}
                ;

StatementList   : Statement
		{		
			//printf("<StatementList> -> <Statement>\n");
		}
                | StatementList Statement
		{		
			//printf("<StatementList> -> <StatementList> <Statement>\n");
		}
                ;

Expr            : SimpleExpr
		{
			$$ = $1;
			//printf("<Expr> -> <SimpleExpr>\n");
		}
                | Expr OR SimpleExpr 
		{
		        $$ = emitBitwiseExpression(instList, symtab, $1, $3, "OR");
			//printf("<Expr> -> <Expr> <OR> <SimpleExpr> \n");
		}
                | Expr AND SimpleExpr 
		{
			$$ = emitBitwiseExpression(instList, symtab, $1, $3, "AND");
			//printf("<Expr> -> <Expr> <AND> <SimpleExpr> \n");
		}
                | NOT SimpleExpr 
		{
			$$ = emitBitwiseExpression(instList, symtab, $2, $2, "NOT");
			//printf("<Expr> -> <NOT> <SimpleExpr> \n");
		}
                ;

SimpleExpr	: AddExpr
		{
			$$ = $1;
			//printf("<SimpleExpr> -> <AddExpr>\n");
		}
                | SimpleExpr EQ AddExpr
		{
			$$ = emitCompOperator(instList, symtab, $1, $3, "==");
		        //$$ = ($1 == $3);
			//printf("<SimpleExpr> -> <SimpleExpr> <EQ> <AddExpr> \n");
		}
                | SimpleExpr NE AddExpr
		{
		        $$ = emitCompOperator(instList, symtab, $1, $3, "!=");
			//printf("<SimpleExpr> -> <SimpleExpr> <NE> <AddExpr> \n");
		}
                | SimpleExpr LE AddExpr
		{
		        $$ = emitCompOperator(instList, symtab, $1, $3, "<=");
			//printf("<SimpleExpr> -> <SimpleExpr> <LE> <AddExpr> \n");
		}
                | SimpleExpr LT AddExpr
		{
		        $$ = emitCompOperator(instList, symtab, $1, $3, "<");
			//printf("<SimpleExpr> -> <SimpleExpr> <LT> <AddExpr> \n");
		}
                | SimpleExpr GE AddExpr
		{
		        $$ = emitCompOperator(instList, symtab, $1, $3, ">=");
			//printf("<SimpleExpr> -> <SimpleExpr> <GE> <AddExpr> \n");
		}
                | SimpleExpr GT AddExpr
		{
			//printf("<SimpleExpr> -> <SimpleExpr> <GT> <AddExpr> \n");
		        $$ = emitCompOperator(instList, symtab, $1, $3, ">");
		}
                ;

AddExpr		:  MulExpr            
		{
			$$ = $1;
			//printf("<AddExpr> -> <MulExpr>\n");
		}
                |  AddExpr PLUS MulExpr
		{
			$$ = emitAddMinusExpression(instList, symtab, $1, $3, "ADD");
			//printf("<AddExpr> -> <AddExpr> <PLUS> <MulExpr> \n");
		}
                |  AddExpr MINUS MulExpr
		{
			$$ = emitAddMinusExpression(instList, symtab, $1, $3, "MINUS");
			//printf("<AddExpr> -> <AddExpr> <MINUS> <MulExpr> \n");
		}
                ;

MulExpr		:  Factor
		{
			$$ = $1;
			//printf("<MulExpr> -> <Factor>\n");
		}
                |  MulExpr TIMES Factor
		{
			$$ = emitMultiDivExpression(instList, symtab, $1, $3, "MULT");
			//$$ = $1 * $3;
			//printf("<MulExpr> -> <MulExpr> <TIMES> <Factor> \n");
		}
                |  MulExpr DIVIDE Factor
		{
			$$ = emitMultiDivExpression(instList, symtab, $1, $3, "DIV");
			//printf("<MulExpr> -> <MulExpr> <DIVIDE> <Factor> \n");
		}		
                ;
				
Factor          : Variable
		{ 
			$$ = emitLoadValueFromAddress(instList, symtab, $1);
			//printf("<Factor> -> <Variable>\n");
		}
                | Constant
		{ 
			$$ = $1;
			//printf("<Factor> -> <Constant>\n");
		}
                | IDENTIFIER LPAREN RPAREN
       		{	
			printf("<Factor> -> <IDENTIFIER> <LP> <RP>\n");
		}
         	| LPAREN Expr RPAREN
		{
			$$ = $2;
			//printf("<Factor> -> <LP> <Expr> <RP>\n");
		}
                ;  

Variable        : IDENTIFIER
		{
			$$ = emitLoadVariableAddress(instList, symtab, $1);
		}
                | IDENTIFIER LBRACKET Expr RBRACKET    
               	{
			printf("<Variable> -> <IDENTIFIER> <LBK> <Expr> <RBK>\n");
               	}
                ;			       

StringConstant 	: STRING
		{ 
		      	int symIndex = SymIndex(symtab,$1);
			$$ = emitLoadStringConstantAddress(instList,dataList,symtab,symIndex);
		}
                ;

Constant        : INTCON
		{ 
			int symIndex = SymIndex(symtab,$1);
			$$ = emitLoadIntegerConstant(instList,symtab,symIndex);
		}
                ;

%%


/********************C ROUTINES *********************************/

void Cminus_error(const char *s)
{
  fprintf(stderr,"%s: line %d: %s\n",fileName,Cminus_lineno,s);
}

int Cminus_wrap() {
	return 1;
}

static void initialize(char* inputFileName) {

	Cminus_in = fopen(inputFileName,"r");
        if (Cminus_in == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
          exit(-1);
        }

	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);
	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w",stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
        }

	 symtab = SymInit(SYMTABLE_SIZE);
	 SymInitField(symtab,SYMTAB_VALUE_FIELD,(Generic)-1,NULL);
	 initRegisters();
	 symstack = symtabStackInit();

	 instList = dlinkListAlloc(NULL);
	 dataList = dlinkListAlloc(NULL);
}

static void finalize() {

    SymKillField(symtab,SYMTAB_VALUE_FIELD);
    SymKill(symtab);
    cleanupRegisters();
    dlinkFreeNodesAndAtoms(instList);
    dlinkFreeNodesAndAtoms(dataList);
    fclose(Cminus_in);
    fclose(stdout);

}

int main(int argc, char** argv)

{	
	fileName = argv[1];
	initialize(fileName);
	
        Cminus_parse();
  
  	finalize();
  
  	return 0;
}

int getValue(int index)
{
  return (int)SymGetFieldByIndex(symtab, index, SYMTAB_VALUE_FIELD); 
}

int setValue(int index, int value)
{
  SymPutFieldByIndex(symtab, index, SYMTAB_VALUE_FIELD, (Generic)value); 
}
/******************END OF C ROUTINES**********************/
