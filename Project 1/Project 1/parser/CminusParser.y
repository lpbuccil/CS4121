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
#include <unistd.h>

#define SYMTABLE_SIZE 100
#define SYMTAB_VALUE_FIELD "value"

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,Cminus_error,(const char*));

EXTERN(int,Cminus_lex,(void));

char *fileName;

SymTable symtab;

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

%union{
	char* name;
	int symIndex;
	int ivalue;
	char* svalue;
}

%type <symIndex> Variable
%type <name> IDENTIFIER 
%type <svalue> StringConstant STRING
%type <ivalue> INTCON Expr SimpleExpr AddExpr MulExpr Constant Factor ReturnStatement

/***********************PRODUCTIONS****************************/
%%
Program		: Procedures 
		{
			//printf("<Program> -> <Procedures>\n");
		}
	  	| DeclList Procedures
		{
			//printf("<Program> -> <DeclList> <Procedures>\n");
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
			//printf("<ProcedureHead> -> <FunctionDecl> <DeclList>\n");
		}
	      | FunctionDecl
		{
			//printf("<ProcedureHead> -> <FunctionDecl>\n");
		}
              ;

FunctionDecl :  Type IDENTIFIER LPAREN RPAREN LBRACE 
		{
			//printf("<FunctionDecl> ->  <Type> <IDENTIFIER> <LP> <RP> <LBR>\n"); 
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
		}		
	   	| DeclList Type IdentifierList SEMICOLON
	 	{
			//printf("<DeclList> -> <DeclList> <Type> <IdentifierList> <SC>\n");
	 	}
          	;


IdentifierList 	: VarDecl  
		{
			//printf("<IdentifierList> -> <VarDecl>\n");
			
		}
						
                | IdentifierList COMMA VarDecl
		{
			//printf("<IdentifierList> -> <IdentifierList> <CM> <VarDecl>\n");
		}
                ;

VarDecl 	: IDENTIFIER
		{ 
			//printf("<VarDecl> -> <IDENTIFIER>\n");
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
			//store the value in symtable at the index given by variable
			SymPutFieldByIndex(symtab, $1, SYMTAB_VALUE_FIELD, (Generic) $3);
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
			//read in a value and store it into the symtable from the variables index
			char temp[100];
			memset(temp, 0, sizeof(temp));
			read(0, temp, sizeof(temp));
			SymPutFieldByIndex(symtab, $3, SYMTAB_VALUE_FIELD, (Generic) atoi(temp));
		}
                | WRITE LPAREN Expr RPAREN SEMICOLON
		{
			//printf("<IOStatement> -> <WRITE> <LP> <Expr> <RP> <SC>\n");
			printf("%d\n", $3);
		}
                | WRITE LPAREN StringConstant RPAREN SEMICOLON         
		{
			//printf("<IOStatement> -> <WRITE> <LP> <StringConstant> <RP> <SC>\n");
			printf("%s\n", $3);
		}
                ;

ReturnStatement : RETURN Expr SEMICOLON
		{
			//printf("<ReturnStatement> -> <RETURN> <Expr> <SC>\n");
			$$ = $2;
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
			//printf("<Expr> -> <SimpleExpr>\n");
			$$ = $1;
		}
                | Expr OR SimpleExpr 
		{
			//printf("<Expr> -> <Expr> <OR> <SimpleExpr> \n");
			$$ = ($1 | $3);
		}
                | Expr AND SimpleExpr 
		{
			//printf("<Expr> -> <Expr> <AND> <SimpleExpr> \n");
			$$ = ($1 && $3);
		}
                | NOT SimpleExpr 
		{
			//printf("<Expr> -> <NOT> <SimpleExpr> \n");
			$$ = (!$2);
		}
                ;

SimpleExpr	: AddExpr
		{
			//printf("<SimpleExpr> -> <AddExpr>\n");
			$$ = $1;
		}
                | SimpleExpr EQ AddExpr
		{
			//printf("<SimpleExpr> -> <SimpleExpr> <EQ> <AddExpr> \n");
			$$ = ($1 == $3);
		}
                | SimpleExpr NE AddExpr
		{
			//printf("<SimpleExpr> -> <SimpleExpr> <NE> <AddExpr> \n");
			$$ = ($1 != $3);
		}
                | SimpleExpr LE AddExpr
		{
			//printf("<SimpleExpr> -> <SimpleExpr> <LE> <AddExpr> \n");
			$$ = ($1 <= $3);
		}
                | SimpleExpr LT AddExpr
		{
			//printf("<SimpleExpr> -> <SimpleExpr> <LT> <AddExpr> \n");
			$$ = ($1 < $3);
		}
                | SimpleExpr GE AddExpr
		{
			//printf("<SimpleExpr> -> <SimpleExpr> <GE> <AddExpr> \n");
			$$ = ($1 >= $3);
		}
                | SimpleExpr GT AddExpr
		{
			//printf("<SimpleExpr> -> <SimpleExpr> <GT> <AddExpr> \n");
			$$ = ($1 > $3);
		}
                ;

AddExpr		:  MulExpr            
		{
			//printf("<AddExpr> -> <MulExpr>\n");
			$$ = $1;
		}
                |  AddExpr PLUS MulExpr
		{
			//printf("<AddExpr> -> <AddExpr> <PLUS> <MulExpr> \n");
			//printf("%d + %d\n", $1, $3);
			$$ = $1 + $3;
		}
                |  AddExpr MINUS MulExpr
		{
			//printf("<AddExpr> -> <AddExpr> <MINUS> <MulExpr> \n");
			$$ = $1 - $3;
		}
                ;

MulExpr		:  Factor
		{
			//printf("<MulExpr> -> <Factor>\n");
			$$ = $1;
		}
                |  MulExpr TIMES Factor
		{
			//printf("<MulExpr> -> <MulExpr> <TIMES> <Factor> \n");
			//printf("%d * %d\n", $1, $3);
			$$ = $1 * $3;
		}
                |  MulExpr DIVIDE Factor
		{
			//printf("<MulExpr> -> <MulExpr> <DIVIDE> <Factor> \n");
			//printf("%d / %d\n", $1, $3);
			$$ = $1 / $3;
		}		
                ;
				
Factor          : Variable
		{ 
			//gets the int value from the symtable given the index from variable
			$$ = (int) SymGetFieldByIndex(symtab, $1, SYMTAB_VALUE_FIELD);
		}
                | Constant
		{ 
			//since it is a constant, we have not save it to the symtable and we can just pass by value
			$$ = $1;
		}
                | IDENTIFIER LPAREN RPAREN
       		{	
			//printf("<Factor> -> <IDENTIFIER> <LP> <RP>\n");
		}
         	| LPAREN Expr RPAREN
		{
			//printf("<Factor> -> <LP> <Expr> <RP>\n");
			$$ = $2;
		}
                ;  

Variable        : IDENTIFIER
		{
			//Gets the index of the Identifier
			int index = SymIndex(symtab, $1);
			$$ = index;
		}
                | IDENTIFIER LBRACKET Expr RBRACKET    
               	{
			//printf("<Variable> -> <IDENTIFIER> <LBK> <Expr> <RBK>\n");
               	}
                ;			       

StringConstant 	: STRING
		{ 
			//returns the string
			$$ = $1;
		}
                ;

Constant        : INTCON
		{ 
			//returns the value of the integer constant
			$$ = $1;
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

	/*initalize symtab and symtab field*/
    symtab = SymInit(SYMTABLE_SIZE);
	SymInitField(symtab, SYMTAB_VALUE_FIELD, (Generic) - 1, NULL);

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

}

static void finalize() {

    fclose(Cminus_in);
    fclose(stdout);
	/*remove symtab*/
	SymKillField(symtab, SYMTAB_VALUE_FIELD);
	SymKill(symtab);
    

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
