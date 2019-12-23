#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/string_utils.h>
#include <util/symtab.h>
#include <util/dlink.h>
#include "reg.h"
#include "codegen.h"
#include "symfields.h"
#include "types.h"

extern int globalOffset;

EXTERN(void,Cminus_error,(char*));



/**
 * Print a data declaration to stdout. This function is called by dlinkApply only.
 *
 * @param decl a DNode containing a data declaration
 */
static void printDataDeclaration(DNode decl) {
	printf("%s\n",(char*)dlinkNodeAtom(decl));
}


/**
 * Print an assembly instruction to stdout. This function is only called by dlinkApply.
 *
 * @param inst a DNode containing an assembly instruction.
 */
static void printInstruction(DNode inst) {
	printf("%s\n",(char*)dlinkNodeAtom(inst));
}


/**
 * Print the assembly prologue that includes the data section, a declaration of main and an allocation of stack space
 * for the main routine.
 *
 * @param dataList a list of data declarations (strings and floats)
 * @param frameSize The number of bytes need for local variables declared in main
 */
void emitDataPrologue(DList dataList) {
	
	printf("\t.data\n");
	printf(".newline: .asciiz \"\\n\"\n");
	dlinkApply(dataList,(DLinkApplyFunc)printDataDeclaration);
	printf("\t.text\n");
}


/**
 * Add a .asciiz declaration for a string constant.
 *
 * @param dataList a DList of data declarations
 * @param symtab a symbol table
 * @param stringIndex the symbol table index of a string constant
 * @return
 */
static char* makeDataDeclaration(DList dataList, SymTable symtab, int stringIndex) {
	static int stringNum = 0;
	char* string = (char*)SymGetFieldByIndex(symtab,stringIndex,SYM_NAME_FIELD);
	char* strLabel = (char*)malloc(sizeof(char)*15);

	snprintf(strLabel,14,".string%d",stringNum++);

	char* strChars = substr(string,1,strlen(string)-2); /**< the string constant w/o quotes */
	char* decl = nssave(4,strLabel,": .asciiz \"",strChars,"\"");
	dlinkAppend(dataList,dlinkNodeAlloc(decl));

	free(strChars);

	return strLabel;
}



/**
 * Print all of the assembly instructions for the main routine to stdout.
 *
 * @param instList a DList of assembly instructions.
 */
void emitInstructions(DList instList) {
	
	dlinkApply(instList,(DLinkApplyFunc)printInstruction);
}




void emitExit(DList instList) {

	char *inst = nssave(2,"\tli $v0, ",SYSCALL_EXIT);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tsyscall");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}


/**
 * Emit the assembly prologue for a procedure
 *
 */
void emitProcedurePrologue(DList instList,SymTable symtab, int index, int frameSize ) {

	char *name = (char*)SymGetFieldByIndex(symtab,index,SYM_NAME_FIELD); 
    char frameStr[10];

	char* inst = nssave(2,"\t.globl ",name);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = nssave(2,name,":\tnop");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	

	inst = ssave("\tmove\t$fp,$sp");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	if (frameSize != 0) {
		sprintf(frameStr,"%d",frameSize);
		inst = nssave(2,"\tadd $sp, $sp, ",frameStr);
		dlinkAppend(instList,dlinkNodeAlloc(inst));
	}

	
	
	 globalOffset = frameSize;
}


/**
 * Add an instruction that performance an assignment.
 *
 * @param instList a DList of assembly instructions
 * @param symtab a symbol table
 * @param lhsRegIndex the symbol table index of the register for the l-value address
 * @param rhsRegIndex the symbol table index of the register for the r-value
 */
void emitAssignment(DList instList,SymTable symtab,int lhsRegIndex, int rhsRegIndex) {


	char *inst;
	
	
	inst = nssave(5,"\tsw ",
						(char*)SymGetFieldByIndex(symtab,rhsRegIndex,SYM_NAME_FIELD),", 0(",
						(char*)SymGetFieldByIndex(symtab,lhsRegIndex,SYM_NAME_FIELD),")");
	
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister((int)SymGetFieldByIndex(symtab,rhsRegIndex,SYMTAB_REGISTER_INDEX_FIELD) );
	freeIntegerRegister((int)SymGetFieldByIndex(symtab,lhsRegIndex,SYMTAB_REGISTER_INDEX_FIELD));
}

/**
 * Add the instructions needed to read a variable using the read system call.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param addrIndex the symbol table index of the register holding the address that is to be read into
 */
void emitReadVariable(DList instList, SymTable symtab, int addrIndex) {

	

	char* inst;

	
	inst = nssave(2,"\tli $v0, ", SYSCALL_READ_INTEGER);
	

	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\tsyscall");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	
	inst = nssave(3,"\tsw $v0, 0(",
				(char*)SymGetFieldByIndex(symtab,addrIndex,SYM_NAME_FIELD),")");
	

	dlinkAppend(instList,dlinkNodeAlloc(inst));
	freeIntegerRegister((int)SymGetFieldByIndex(symtab,addrIndex,SYMTAB_REGISTER_INDEX_FIELD));

}



/**
 * Add the instructions needed to write a value using the print system call.
 *
 * @param instList a Dlist of instructions
 * @param symtab a symbol table
 * @param regIndex the symbol table index of the register to be printed (must be addres if string)
 * @param syscallService the system call print service to use
 */
void emitWriteExpression(DList instList,SymTable symtab, int regIndex, char* syscallService) {

	
	
	char *inst;

	
		inst = nssave(2,"\tmove $a0, ",
			          (char*)SymGetFieldByIndex(symtab,regIndex,SYM_NAME_FIELD));
	
	
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	freeIntegerRegister((int)SymGetFieldByIndex(symtab,regIndex,SYMTAB_REGISTER_INDEX_FIELD) );
	
	inst = nssave(2,"\tli $v0, ",syscallService);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	
	inst = ssave("\tsyscall");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	
	inst = nssave(2,"\tli $v0, ",SYSCALL_PRINT_STRING);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	
	inst = ssave("\tla, $a0, .newline");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	
	inst = ssave("\tsyscall");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	
}



/**
 * Add an instruction that performs a binary computation.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param typeTable the type table for the expression being emitted
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @param opcode the opcode of the mips assembly instruction
 * @return
 */
static int emitBinaryExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand, char* opcode) {

	

	int regIndex;

	
	regIndex = getFreeIntegerRegisterIndex(symtab);
	

	char* regName = (char*)SymGetFieldByIndex(symtab,regIndex,SYM_NAME_FIELD);
	char* leftName = (char*)SymGetFieldByIndex(symtab,leftOperand,SYM_NAME_FIELD);
	char* rightName = (char*)SymGetFieldByIndex(symtab,rightOperand,SYM_NAME_FIELD);

	char* inst = nssave(8,"\t",opcode," ",regName,", ",leftName,", ",rightName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister((int)SymGetFieldByIndex(symtab,leftOperand,SYMTAB_REGISTER_INDEX_FIELD));
	freeIntegerRegister((int)SymGetFieldByIndex(symtab,rightOperand,SYMTAB_REGISTER_INDEX_FIELD));

	return regIndex;
}

/**
 * Add an or instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitOrExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	
	return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"or");
}

/**
 * Add an and instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitAndExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	
	return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"and");
}

/**
 * Add a not instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param operand the symbol table index of the register holding the operand
 * @return the symbol table index for the result register
 */
int emitNotExpression(DList instList, SymTable symtab, int operand) {
	
	int regIndex = getFreeIntegerRegisterIndex(symtab);
	char* regName = (char*)SymGetFieldByIndex(symtab,regIndex,SYM_NAME_FIELD);
	char* opName = (char*)SymGetFieldByIndex(symtab,operand,SYM_NAME_FIELD);

	char* inst = nssave(5,"\txori ",regName,", ",opName,", 1");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister((int)SymGetFieldByIndex(symtab,operand,SYMTAB_REGISTER_INDEX_FIELD));

	return regIndex;
}



/**
 * Add an equal instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitEqualExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	
		return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"seq");
	
}
/**
 * Add a not-equal instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */

int emitNotEqualExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	
		return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"sne");
	
}

/**
 * Add an less-or-equal instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitLessEqualExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	
		return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"sle");
	
}



/**
 * Add a less-than instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitLessThanExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	
		return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"slt");
	
}

/**
 * Add a greater-equal instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitGreaterEqualExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	
	
		return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"sge");
	
}

/**
 * Add a greater-than instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitGreaterThanExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	
	
		return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"sgt");
	
}


/**
 * Add an add instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitAddExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	
		return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"add");
	

}

/**
 * Add a subtract instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitSubtractExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	
		return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"sub");
	
}

/**
 * Add a multiply instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitMultiplyExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	
		return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"mul");
	
}

/**
 * Add a divide instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitDivideExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	
		return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"div");
	
}

/**
 * Add an instruction to load a variable from memory.
 *
 * @param instList a Dlist of instructions
 * @param symtab a symbol table
 * @param regIndex the symbol table index for the address of a variable
 * @return the symbol table index of the result register
 */
int emitLoadVariable(DList instList, SymTable symtab, int regIndex) {

	int newRegIndex;
	
	
	
	newRegIndex = getFreeIntegerRegisterIndex(symtab);
	

	char* newRegName = (char*)SymGetFieldByIndex(symtab,newRegIndex,SYM_NAME_FIELD);

	char* regName = (char*)SymGetFieldByIndex(symtab,regIndex,SYM_NAME_FIELD);

	char *inst;
	
	
	inst = nssave(5,"\tlw ",newRegName,", 0(",regName,")");

	
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister((int)SymGetFieldByIndex(symtab,regIndex,SYMTAB_REGISTER_INDEX_FIELD));

	return newRegIndex;

}



/**
 * Add an instruction to load an integer constant
 *
 * @param instList a Dlist of instructions
 * @param symtab a symbol table
 * @param intIndex the symbol table index for an integer constant
 * @return the symbol table index of the result register
 */
int emitLoadIntegerConstant(DList instList, SymTable symtab, int intIndex) {
	int regIndex = getFreeIntegerRegisterIndex(symtab);
	char* regName = (char*)SymGetFieldByIndex(symtab,regIndex,SYM_NAME_FIELD);
	
	char *intName = SymGetFieldByIndex(symtab,intIndex,SYM_NAME_FIELD);
	
	char *inst = nssave(4,"\tli ",regName, ", ", intName);
	
	DNode node = dlinkNodeAlloc(inst);
	
	dlinkAppend(instList,node);
	
	return regIndex;
			                
}



/**
 * Add an instruction to compute the address of a variable.
 *
 * @param instList a Dlist of instructions
 * @param varSymtab a symbol table for the variable
 * @param regSymtab a symbol table for the registers
 * @param varIndex the symbol table index for a variable
 * @return the symbol table index of the result register
 */
int emitComputeVariableAddress(DList instList, SymTable symtab, int varIndex) {
	

	int regIndex = getFreeIntegerRegisterIndex(symtab);
	
	char* regName = (char*)SymGetFieldByIndex(symtab,regIndex,SYM_NAME_FIELD);

	int offset = (int)SymGetFieldByIndex(symtab,varIndex,SYMTAB_OFFSET_FIELD);
	char offsetStr[10];

	snprintf(offsetStr,9,"%d",offset);

	char *inst;
	if (offset < 0)
			inst = nssave(4,"\tadd ",regName,", $fp, ",offsetStr);
	else
			inst = nssave(4,"\tadd ",regName,", $gp, ",offsetStr);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	
	return regIndex;
	

}


/**
 * Add an instruction to load the address of a string constant
 *
 * @param instList a Dlist of instructions
 * @param dataList a Dlist of data declarations
 * @param symtab a symbol table
 * @param stringIndex the symbol table index for a string constant
 * @return the symbol table index of the result register
 */
int emitLoadStringConstantAddress(DList instList, DList dataList, SymTable symtab, int stringIndex) {
	char *strLabel = makeDataDeclaration(dataList,symtab,stringIndex);

	int regIndex = getFreeIntegerRegisterIndex(symtab);
	char* regName = (char*)SymGetFieldByIndex(symtab,regIndex,SYM_NAME_FIELD);

	char* inst = nssave(4,"\tla ",regName, ", ",strLabel);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	free(strLabel);

	return regIndex;
}




/**
 * Add an identifier to the symbol table and store its offset in the activation record.
 * This function is called by dlinkApply1.
 *
 * @param node a node on a linked list containing the symbol table index of a variable
 * 		  delcared in a program
 * @param data a structure containing the symbol table index of the type of the variable,
 * 		  the symbol table, and the current offset in the activation record.
 */
void addIdToSymtab(DNode node, AddIdStructPtr data) {

	int symIndex = (int)dlinkNodeAtom(node);
	
	int  size = 4;
	
	data->offset += size*data->offsetDirection;
	SymPutFieldByIndex(data->symtab,symIndex,SYMTAB_OFFSET_FIELD,(Generic)data->offset);
	
}

