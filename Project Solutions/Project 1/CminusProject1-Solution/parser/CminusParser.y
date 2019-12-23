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

#define SYMTABLE_SIZE 100
#define SYMTAB_VALUE_FIELD     "value"

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
			//printf("<VarDecl> -> <IDENTIFIER\n");
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
			setValue($1, $3);
			//printf("<Assignment> -> <Variable> <ASSIGN> <Expr> <SC>\n");
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
		  int t;
		  scanf("%d", &t);
                  setValue($3, t); 
		     //printf("<IOStatement> -> <READ> <LP> <Variable> <RP> <SC>\n");
		}
                | WRITE LPAREN Expr RPAREN SEMICOLON
		{
			printf("%d\n", $3);
			//printf("<IOStatement> -> <WRITE> <LP> <Expr> <RP> <SC>\n");
		}
                | WRITE LPAREN StringConstant RPAREN SEMICOLON         
		{
		  printf("%s\n", (char *)SymGetFieldByIndex(symtab,$3, SYM_NAME_FIELD));
			//printf("<IOStatement> -> <WRITE> <LP> <StringConstant> <RP> <SC>\n");
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
		        $$ = $1 | $3;
			//printf("<Expr> -> <Expr> <OR> <SimpleExpr> \n");
		}
                | Expr AND SimpleExpr 
		{
			$$ = $1 & $3;
			//printf("<Expr> -> <Expr> <AND> <SimpleExpr> \n");
		}
                | NOT SimpleExpr 
		{
			$$ = $2 ^ 1;
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
		        $$ = ($1 == $3);
			//printf("<SimpleExpr> -> <SimpleExpr> <EQ> <AddExpr> \n");
		}
                | SimpleExpr NE AddExpr
		{
		        $$ = ($1 != $3);
			//printf("<SimpleExpr> -> <SimpleExpr> <NE> <AddExpr> \n");
		}
                | SimpleExpr LE AddExpr
		{
		        $$ = ($1 <= $3);
			//printf("<SimpleExpr> -> <SimpleExpr> <LE> <AddExpr> \n");
		}
                | SimpleExpr LT AddExpr
		{
		        $$ = ($1 < $3);
			//printf("<SimpleExpr> -> <SimpleExpr> <LT> <AddExpr> \n");
		}
                | SimpleExpr GE AddExpr
		{
		        $$ = ($1 >= $3);
			//printf("<SimpleExpr> -> <SimpleExpr> <GE> <AddExpr> \n");
		}
                | SimpleExpr GT AddExpr
		{
			//printf("<SimpleExpr> -> <SimpleExpr> <GT> <AddExpr> \n");
		        $$ = ($1 > $3);
		}
                ;

AddExpr		:  MulExpr            
		{
			$$ = $1;
			//printf("<AddExpr> -> <MulExpr>\n");
		}
                |  AddExpr PLUS MulExpr
		{
			$$ = $1 + $3;
			//printf("<AddExpr> -> <AddExpr> <PLUS> <MulExpr> \n");
		}
                |  AddExpr MINUS MulExpr
		{
			$$ = $1 - $3;
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
			$$ = $1 * $3;
			//printf("<MulExpr> -> <MulExpr> <TIMES> <Factor> \n");
		}
                |  MulExpr DIVIDE Factor
		{
			$$ = $1 / $3;
			//printf("<MulExpr> -> <MulExpr> <DIVIDE> <Factor> \n");
		}		
                ;
				
Factor          : Variable
		{ 
			$$ = getValue($1);
			//printf("<Factor> -> <Variable>\n");
		}
                | Constant
		{ 
			$$ = $1;
			//printf("<Factor> -> <Constant>\n");
		}
                | IDENTIFIER LPAREN RPAREN
       		{	
			//printf("<Factor> -> <IDENTIFIER> <LP> <RP>\n");
		}
         	| LPAREN Expr RPAREN
		{
			$$ = $2;
			//printf("<Factor> -> <LP> <Expr> <RP>\n");
		}
                ;  

Variable        : IDENTIFIER
		{
			$$ = $1;
			//printf("<Variable> -> <IDENTIFIER>\n");
		}
                | IDENTIFIER LBRACKET Expr RBRACKET    
               	{
			//printf("<Variable> -> <IDENTIFIER> <LBK> <Expr> <RBK>\n");
               	}
                ;			       

StringConstant 	: STRING
		{ 
		       $$ = $1;
			//printf("<StringConstant> -> <STRING>\n");
		}
                ;

Constant        : INTCON
		{ 
			$$ = $1;
			//printf("<Constant> -> <INTCON>\n");
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
}

static void finalize() {

    SymKillField(symtab,SYMTAB_VALUE_FIELD);
    SymKill(symtab);
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
