#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <util/string_utils.h>
#include <util/symtab.h>
#include <util/dlink.h>
#include "reg.h"
#include "codegen.h"
#include "symfields.h"
#include "types.h"



static offset = 0;

//prints data section
static void printDataDeclaration(DNode decl) {
	printf("\t%s\n",(char*)dlinkNodeAtom(decl));
}

//adds data section
void emitDataPrologue(DList dataList) {
	printf(".data\n");	
    printf("\t.newl: .asciiz \"\\n\"\n");	                                              
	dlinkApply(dataList,(DLinkApplyFunc)printDataDeclaration);
}

//prints instructions
static void printInstruction(DNode inst) {
	printf("%s\n",(char*)dlinkNodeAtom(inst));
}

//prints .txt section
void emitInstructions(DList instList) {
    printf(".text\n");
	dlinkApply(instList,(DLinkApplyFunc)printInstruction);
}

//adds a string to the .data section
static char* makeDataDeclaration(DList dataList, SymTable symtab, int stringIndex) {
	static int stringNum = 0;
	char* string = (char*)SymGetFieldByIndex(symtab,stringIndex,SYM_NAME_FIELD);
	char* strLabel = (char*)malloc(sizeof(char)*100);
	snprintf(strLabel,100,".string_const%d",stringNum++);

	char* strChars = substr(string,1,strlen(string)-2); 
	char* decl = nssave(4,strLabel,": .asciiz \"",strChars,"\"");
	dlinkAppend(dataList,dlinkNodeAlloc(decl));

	return strLabel;
}

//loads the address of a string constant from data section
int emitLoadStringConstantAddress(DList instList, DList dataList, SymTable symtab, int stringIndex) {
	char *strLabel = makeDataDeclaration(dataList,symtab,stringIndex);
	int regIndex = getFreeIntegerRegisterIndex(symtab);
	char* regName = (char*)SymGetFieldByIndex(symtab,regIndex,SYM_NAME_FIELD);

	char* inst = nssave(4,"\tla ", regName, ", ", strLabel);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	return regIndex;
}

//loads an int const into a reg
int emitLoadIntegerConstant(DList instList, SymTable symtab, int intIndex) {
	int regIndex = getFreeIntegerRegisterIndex(symtab);
	char* regName = (char*)SymGetFieldByIndex(symtab,regIndex,SYM_NAME_FIELD);
	char* msg = nssave(2 , "\t#Load immediate to ", regName);
    dlinkAppend(instList,dlinkNodeAlloc(msg));
	char *intName = SymGetFieldByIndex(symtab,intIndex,SYM_NAME_FIELD);
	char *inst = nssave(4,"\tli ", regName, ", ", intName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	return regIndex;
}

//adds a variable to the data section
char* makeDataVariableDeclaration(DList dataList, SymTable symtab, int variableIndex) {
	char* string = (char*)SymGetFieldByIndex(symtab,variableIndex,SYM_NAME_FIELD);
	char* strLabel = (char*)malloc(sizeof(char)*15);
	sprintf(strLabel,"0");
	char* decl = nssave(3,string,": .word ",strLabel);
	dlinkAppend(dataList,dlinkNodeAlloc(decl));
	return string;
}

//loads the address of a variable in the data section
int emitLoadVariableAddress(DList instList, SymTable symtab, char* variableName) {
	int regIndex = getFreeIntegerRegisterIndex(symtab);
	char* regName = (char*)SymGetFieldByIndex(symtab, regIndex, SYM_NAME_FIELD);
	char* inst = nssave(4,"\tla ", regName, ", ", variableName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return regIndex;
}

//sets the value of a variable in the data section
void emitAssignVariable(DList instList, SymTable symtab, int variableIndex, int valueRegIndex){
    
    char* valueStr = SymGetFieldByIndex(symtab, valueRegIndex, SYM_NAME_FIELD);
    char* variableName = SymGetFieldByIndex(symtab, variableIndex, SYM_NAME_FIELD);
    char* msg = nssave(4 , "\t#Assign variable ", variableName, " = ", valueStr);
    dlinkAppend(instList,dlinkNodeAlloc(msg));
    char* inst = nssave(5,"\tsw ", valueStr, ", 0(", variableName, ")");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
    freeIntegerRegister(SymGetFieldByIndex(symtab, variableIndex, SYMTAB_REGISTER_INDEX_FIELD));
    freeIntegerRegister(SymGetFieldByIndex(symtab, valueRegIndex, SYMTAB_REGISTER_INDEX_FIELD));
}

//adds the procedure decelaration to the text section
void emitProcedurePrologue(DList instList,SymTable symtab, int index) {
	char *name = (char*)SymGetFieldByIndex(symtab,index,SYM_NAME_FIELD); 

	char* inst = nssave(2, "\t.globl ", name);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

    inst = nssave(2, name, ":\tnop");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}

//adds a write call to the text section
void emitWriteSysCall(DList instList, SymTable symtab, int regIndex, int sysCode){
    char* str = (char*) malloc(sizeof(char) * 100);

    char* msg = nssave(2 , "\t#Print variable ", SymGetFieldByIndex(symtab, regIndex, SYM_NAME_FIELD));
    dlinkAppend(instList,dlinkNodeAlloc(msg));
    
    sprintf(str, "%d", sysCode);

    int reg = getFreeIntegerRegisterIndex(symtab);

    char* inst = nssave(2, "\tli $v0, ", str);
    dlinkAppend(instList, dlinkNodeAlloc(inst));
    sprintf(str, "%s", SymGetFieldByIndex(symtab, regIndex, SYM_NAME_FIELD));
    if (sysCode == 4){
    
        inst = nssave(3 , "\tla $a0, 0(", str, ")");
        dlinkAppend(instList, dlinkNodeAlloc(inst));
    }else if (sysCode == 1){

        inst = nssave(2 , "\tmove $a0, ", nssave(1, SymGetFieldByIndex(symtab, regIndex, SYM_NAME_FIELD)));
        dlinkAppend(instList, dlinkNodeAlloc(inst));    
        
    }
    
    inst = nssave(1, "\tsyscall");
    dlinkAppend(instList, dlinkNodeAlloc(inst));
    freeIntegerRegister(SymGetFieldByIndex(symtab, reg, SYMTAB_REGISTER_INDEX_FIELD));
    freeIntegerRegister(SymGetFieldByIndex(symtab, regIndex, SYMTAB_REGISTER_INDEX_FIELD));

    free(str);

    writeNewLine(instList);
}


//adds a multi/div operation to the text section
int emitMultiDivExpression(DList instList, SymTable symtab, int regIndex1, int regIndex2, char* expr){
    char* msg = nssave(4 , "\t#Mult/Div variable ", SymGetFieldByIndex(symtab, regIndex1, SYM_NAME_FIELD), " and ", SymGetFieldByIndex(symtab, regIndex2, SYM_NAME_FIELD));
    dlinkAppend(instList,dlinkNodeAlloc(msg));

    int outputReg = getFreeIntegerRegisterIndex(symtab);
    char* outputRegStr = nssave(1, SymGetFieldByIndex(symtab, outputReg, SYM_NAME_FIELD));

    char* reg1Str = nssave(1, SymGetFieldByIndex(symtab, regIndex1, SYM_NAME_FIELD));
    char* reg2Str = nssave(1, SymGetFieldByIndex(symtab, regIndex2, SYM_NAME_FIELD));


    if (strcmp(expr, "MULT") == 0){
        char* inst = nssave(4, "\tmult ", reg1Str, ", ", reg2Str);
        dlinkAppend(instList,dlinkNodeAlloc(inst));
    }else {
        char* inst = nssave(4, "\tdiv ", reg1Str, ", ", reg2Str);
        dlinkAppend(instList,dlinkNodeAlloc(inst));
    }

    char* inst = nssave(2, "\tmflo ", outputRegStr);
    dlinkAppend(instList,dlinkNodeAlloc(inst));



    freeIntegerRegister(SymGetFieldByIndex(symtab, regIndex1, SYMTAB_REGISTER_INDEX_FIELD));
    freeIntegerRegister(SymGetFieldByIndex(symtab, regIndex2, SYMTAB_REGISTER_INDEX_FIELD));
    return outputReg;
    
}

//adds an add/sub operation to the text section
int emitAddMinusExpression(DList instList, SymTable symtab, int reg1Index, int reg2Index, char* operator){
    char* msg = nssave(4 , "\t#Add/Sub variable ", SymGetFieldByIndex(symtab, reg1Index, SYM_NAME_FIELD), " and ", SymGetFieldByIndex(symtab, reg2Index, SYM_NAME_FIELD));
    dlinkAppend(instList,dlinkNodeAlloc(msg));

    int regOutput = getFreeIntegerRegisterIndex(symtab);

    char* reg1Str = nssave(1, SymGetFieldByIndex(symtab, reg1Index, SYM_NAME_FIELD));
    char* reg2Str = nssave(1, SymGetFieldByIndex(symtab, reg2Index, SYM_NAME_FIELD));
    char* regOutStr = nssave(1, SymGetFieldByIndex(symtab, regOutput, SYM_NAME_FIELD));

    if (strcmp(operator, "ADD") == 0){
        char* inst = nssave(6, "\tadd ", regOutStr, ", ", reg1Str, ", ", reg2Str);
        dlinkAppend(instList,dlinkNodeAlloc(inst));
    }else {
        char* inst = nssave(6, "\tsub ", regOutStr, ", ", reg1Str, ", ", reg2Str);
        dlinkAppend(instList,dlinkNodeAlloc(inst));
    }

    freeIntegerRegister(SymGetFieldByIndex(symtab, reg1Index, SYMTAB_REGISTER_INDEX_FIELD));
    freeIntegerRegister(SymGetFieldByIndex(symtab, reg2Index, SYMTAB_REGISTER_INDEX_FIELD));


    return regOutput;
}

//adds a comparator operator to the text section
int emitCompOperator(DList instList, SymTable symtab, int reg1Index, int reg2Index, char* op){
    static int compNumber = 0;
    char* msg = nssave(4 , "\t#Compare variable ", SymGetFieldByIndex(symtab, reg1Index, SYM_NAME_FIELD), " and ", SymGetFieldByIndex(symtab, reg2Index, SYM_NAME_FIELD));
    dlinkAppend(instList,dlinkNodeAlloc(msg));


    char* reg1Str = nssave(1, SymGetFieldByIndex(symtab, reg1Index, SYM_NAME_FIELD));
    char* reg2Str = nssave(1, SymGetFieldByIndex(symtab, reg2Index, SYM_NAME_FIELD));
    
    int regOutput = getFreeIntegerRegisterIndex(symtab);
    char* regOutputStr = nssave(1, SymGetFieldByIndex(symtab, regOutput, SYM_NAME_FIELD));
    

    
    if (strcmp(op, "==") == 0){  
        char lable[20];
        sprintf(lable, "compBranch%d", compNumber);
        char* inst = nssave(3, "\tmove ", regOutputStr, ", $zero");
        dlinkAppend(instList,dlinkNodeAlloc(inst));
        inst = nssave(6, "\tbgt ", reg1Str, ", ", reg2Str, ", ", lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst));  
        inst = nssave(6, "\tbgt ", reg2Str, ", ", reg1Str, ", ", lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        char* num = nssave(1, "1");
        inst = nssave(4, "\tli ", regOutputStr, ", ", num);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        sprintf(lable, "compBranch%d: nop", compNumber);
        inst = nssave(1, lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
    }else if (strcmp(op, "!=") == 0){
        char lable[20];
        sprintf(lable, "compBranch%d", compNumber);
        char* num = nssave(1, "1");
        char* inst = nssave(4, "\tli ", regOutputStr, ", ", num);
        dlinkAppend(instList,dlinkNodeAlloc(inst));
        inst = nssave(6, "\tbgt ", reg1Str, ", ", reg2Str, ", ", lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst));  
        inst = nssave(6, "\tbgt ", reg2Str, ", ", reg1Str, ", ", lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        num = nssave(1, "0");
        inst = nssave(4, "\tli ", regOutputStr, ", ", num);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        sprintf(lable, "compBranch%d: nop", compNumber);
        inst = nssave(1, lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
    }else if(strcmp(op, "<=") == 0){
        char lable[20];
        sprintf(lable, "compBranch%d", compNumber);
        char* num = nssave(1, "0");
        char* inst = nssave(4, "\tli ", regOutputStr, ", ", num);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        inst = nssave(6, "\tbgt ", reg1Str, ", ", reg2Str, ", ", lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        num = nssave(1, "1");
        inst = nssave(4, "\tli ", regOutputStr, ", ", num);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        sprintf(lable, "compBranch%d: nop", compNumber);
        inst = nssave(1, lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst));

    }else if (strcmp(op, "<") == 0){
        char lable[20];
        sprintf(lable, "compBranch%d", compNumber);
        char* num = nssave(1, "0");
        char* inst = nssave(4, "\tli ", regOutputStr, ", ", num);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        inst = nssave(6, "\tbge ", reg1Str, ", ", reg2Str, ", ", lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        num = nssave(1, "1");
        inst = nssave(4, "\tli ", regOutputStr, ", ", num);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        sprintf(lable, "compBranch%d: nop", compNumber);
        inst = nssave(1, lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
    }else if(strcmp(op, ">=") == 0){
        char lable[20];
        sprintf(lable, "compBranch%d", compNumber);
        char* num = nssave(1, "1");
        char* inst = nssave(4, "\tli ", regOutputStr, ", ", num);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        inst = nssave(6, "\tbge ", reg1Str, ", ", reg2Str, ", ", lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        num = nssave(1, "0");
        inst = nssave(4, "\tli ", regOutputStr, ", ", num);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        sprintf(lable, "compBranch%d: nop", compNumber);
        inst = nssave(1, lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst));

    }else if (strcmp(op, ">") == 0){
        char lable[20];
        sprintf(lable, "compBranch%d", compNumber);
        char* num = nssave(1, "1");
        char* inst = nssave(4, "\tli ", regOutputStr, ", ", num);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        inst = nssave(6, "\tbgt ", reg1Str, ", ", reg2Str, ", ", lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        num = nssave(1, "0");
        inst = nssave(4, "\tli ", regOutputStr, ", ", num);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
        sprintf(lable, "compBranch%d: nop", compNumber);
        inst = nssave(1, lable);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
    }

    compNumber++;
    freeIntegerRegister(SymGetFieldByIndex(symtab, reg1Index, SYMTAB_REGISTER_INDEX_FIELD));
    freeIntegerRegister(SymGetFieldByIndex(symtab, reg2Index, SYMTAB_REGISTER_INDEX_FIELD));

    return regOutput;
}

//adds a bitwise operation to the text section
int emitBitwiseExpression(DList instList, SymTable symtab, int reg1Index, int reg2Index, char* op){
    static int compNumber = 0;
    char* msg = nssave(4 , "\t#Bitwise variable ", SymGetFieldByIndex(symtab, reg1Index, SYM_NAME_FIELD), " and ", SymGetFieldByIndex(symtab, reg2Index, SYM_NAME_FIELD));
    dlinkAppend(instList,dlinkNodeAlloc(msg));


    char* reg1Str = nssave(1, SymGetFieldByIndex(symtab, reg1Index, SYM_NAME_FIELD));
    char* reg2Str = nssave(1, SymGetFieldByIndex(symtab, reg2Index, SYM_NAME_FIELD));
    
    int regOutput = getFreeIntegerRegisterIndex(symtab);
    char* regOutputStr = nssave(1, SymGetFieldByIndex(symtab, regOutput, SYM_NAME_FIELD));

    if (strcmp(op, "OR") == 0){
        char* inst = nssave(6, "\tor ", regOutputStr, ", ", reg1Str, ", ", reg2Str);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
    }else if (strcmp(op, "AND") == 0){
        char* inst = nssave(6, "\tand ", regOutputStr, ", ", reg1Str, ", ", reg2Str);
        dlinkAppend(instList,dlinkNodeAlloc(inst)); 
    }else if (strcmp(op, "NOT") == 0){

        char* inst = nssave(5, "\tsltu  ", regOutputStr, ", $zero", ", ", reg2Str);
        dlinkAppend(instList,dlinkNodeAlloc(inst));
        char* num = nssave(1, "1"); 
        inst = nssave(6, "\txori  ", regOutputStr, ", ", regOutputStr,  ", ", num);
        dlinkAppend(instList,dlinkNodeAlloc(inst));
    }

    freeIntegerRegister(SymGetFieldByIndex(symtab, reg1Index, SYMTAB_REGISTER_INDEX_FIELD));
    freeIntegerRegister(SymGetFieldByIndex(symtab, reg2Index, SYMTAB_REGISTER_INDEX_FIELD));
    return regOutput;

}

//adds a syscall read to the text section
void emitReadSysCall(DList instList, SymTable symtab, int regIndex){
    char* msg = nssave(2 , "\t#Read into variable ", SymGetFieldByIndex(symtab, regIndex, SYM_NAME_FIELD));
    dlinkAppend(instList,dlinkNodeAlloc(msg));
    char* inst = nssave(2, "\tli $v0, ", nssave(1, "5"));
    dlinkAppend(instList, dlinkNodeAlloc(inst));

    inst = nssave(1, "\tsyscall");
    dlinkAppend(instList, dlinkNodeAlloc(inst));

    emitAssignVariable(instList, symtab, regIndex, SymIndex(symtab, "$v0"));
}

//loads the value from an address and stores it into a reg
int emitLoadValueFromAddress(DList instList, SymTable symtab, int regIndexOfAddress){
    char* msg = nssave(2 , "\t#Get value from address in reg ", SymGetFieldByIndex(symtab, regIndexOfAddress, SYM_NAME_FIELD));
    dlinkAppend(instList,dlinkNodeAlloc(msg));
    char* regAddName = nssave(1, (char*) SymGetFieldByIndex(symtab, regIndexOfAddress, SYM_NAME_FIELD));
    int regIndex = getFreeIntegerRegisterIndex(symtab);
    char *regname = nssave(1, (char*) SymGetFieldByIndex(symtab, regIndex, SYM_NAME_FIELD));

    char* inst = nssave(5, "\tlw ", regname, ", 0(", regAddName, ")");
    dlinkAppend(instList, dlinkNodeAlloc(inst));
    freeIntegerRegister((int) SymGetFieldByIndex(symtab, regIndexOfAddress, SYMTAB_REGISTER_INDEX_FIELD));
    return regIndex;
}

//syscall to print a new line
void writeNewLine(DList instList){
    char* msg = nssave(1 , "\t#Print newline");
    dlinkAppend(instList,dlinkNodeAlloc(msg));

    char* inst = nssave(1, "\tli $v0, 4");
    dlinkAppend(instList, dlinkNodeAlloc(inst));
    inst = nssave(1 , "\tla $a0, .newl");
    dlinkAppend(instList, dlinkNodeAlloc(inst));
    inst = nssave(1, "\tsyscall");
    dlinkAppend(instList, dlinkNodeAlloc(inst));
}
