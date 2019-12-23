/**
 * reg.c
 * 
 * A set of routines to handle the allocation of registers in the Cminus Compiler
 * 
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <util/general.h>
#include <util/string_utils.h>
#include <util/symtab.h>
#include <codegen/symfields.h>
#include <string.h>
#include "reg.h"
#include "types.h"

/**
 * The assembly language names of the Mips registers
 */
char* integerRegisterNames[] = {"$s0","$s1","$s2","$s3","$s4","$s5","$s6","$s7","$t0","$t1",
		  		"$t2","$t3","$t4","$t5","$t6","$t7","$t8","$t9"};

char* floatRegisterNames[] = {"$f20","$f22","$f24","$f26","$f28","$f30",
		  "$f2","$f4","$f6","$f8","$f10","$f14","$f16","$f18"};

static bool *allocatedIntegerRegisters; /**< vector of bools indicated whether register is allocated or not */
static bool *allocatedFloatRegisters; /**< vector of bools indicated whether register is allocated or not */

/**
 * Initialize the allocated registers vector
 */
void initRegisters() {
	
	allocatedIntegerRegisters = (bool*)malloc(sizeof(bool)*NUM_INTEGER_REGISTERS);
	allocatedFloatRegisters = (bool*)malloc(sizeof(bool)*NUM_FLOAT_REGISTERS);
}

bool isAllocatedIntegerRegister(int reg) {
	return allocatedIntegerRegisters[reg];
}

bool isAllocatedFloatRegister(int reg) {
	return allocatedFloatRegisters[reg];
}

/**
 * Return the next free register, return -1 if none available (shouldn't happen in the simple examples)
 *
 * @param registers the vector indicating which registers are allocated.
 * @return see above
 */
static int getFreeRegister(bool *allocRegisters, int numRegisters) {
	int i;
	
	for (i = 0; i < numRegisters; i++) 
		if (!allocRegisters[i])
			return i;
 	
	return -1;
}

/**
 * Allocate a free  register. Set the allocated vector entry to true. Fail if none available
 *
 * @return the register that has been allocated
 */
static int allocateRegister(bool *allocatedRegisters,int numRegisters) {
	
	int reg = getFreeRegister(allocatedRegisters,numRegisters);
	
	if (reg != -1)
		allocatedRegisters[reg] = true;
	else {
		fprintf(stderr,"Register allocation error\n");
		exit(-1);
	}
	
	return reg;
}

/**
 * Allocate a free integer register.
 *
 * @return the register that has been allocated
 */
int allocateIntegerRegister() {
	return allocateRegister(allocatedIntegerRegisters,NUM_INTEGER_REGISTERS);
}

/**
 * Allocate a free floating-point register.
 *
 * @return the register that has been allocated
 */
int allocateFloatRegister() {
	return allocateRegister(allocatedFloatRegisters,NUM_FLOAT_REGISTERS);
}

/**
 * Free the space for the allocated vector.
 */
void cleanupRegisters() {
	free(allocatedIntegerRegisters);
	free(allocatedFloatRegisters);
}

/**
 * Free a register by setting is entry in the allocated vector to false.
 *
 * @param reg the register to free
 */
static void freeRegister(bool *allocatedRegisters, int reg, int size) {
	if (reg >= 0 && reg < size)
		allocatedRegisters[reg] = false;
	else
		fprintf(stderr,"Error trying to free invalid register #%d\n",reg);
}

/**
 * Free an integer register by setting is entry in the allocated vector to false.
 *
 * @param reg the register to free
 */
void freeIntegerRegister(int reg) {
	freeRegister(allocatedIntegerRegisters,reg,NUM_INTEGER_REGISTERS);
}

/**
 * Free a floating-point register by setting is entry in the allocated vector to false.
 *
 * @param reg the register to free
 */
void freeFloatRegister(int reg) {
	freeRegister(allocatedFloatRegisters,reg,NUM_FLOAT_REGISTERS);
}

/**
 * Free a register by setting is entry in the allocated vector to false.
 *
 * @param reg the register to free
 * @param type the data type of the register
 */
void freeRegisterByType(int reg, int type) {
	if (type == INTEGER_TYPE)
		freeRegister(allocatedIntegerRegisters,reg,NUM_INTEGER_REGISTERS);
	else
		freeRegister(allocatedFloatRegisters,reg,NUM_FLOAT_REGISTERS);
}

/**
 * Return the Mips assembler name for a register.
 *
 * @param reg a mips register number
 * @return see above
 */
char* getIntegerRegisterName(int reg) {
	return integerRegisterNames[reg];
}


/**
 * Return the Mips assembler name for a register.
 *
 * @param reg a mips register number
 * @return see above
 */
char* getFloatRegisterName(int reg) {
	return floatRegisterNames[reg];
}
/**
 * Get the symbol table index of a free integer register
 *
 * @param symtab a symbol table
 * @return the symbol table index of a free integer register
 */
int getFreeIntegerRegisterIndex(SymTable symtab) {
	int reg = allocateIntegerRegister();
	char* symReg = getIntegerRegisterName(reg);
	int regIndex;

	if ((regIndex = SymQueryIndex(symtab,symReg)) == SYM_INVALID_INDEX) {
		regIndex = SymIndex(symtab,symReg);
		SymPutFieldByIndex(symtab,regIndex,SYMTAB_REGISTER_INDEX_FIELD,(Generic)reg);
		SymPutFieldByIndex(symtab,regIndex,SYMTAB_TYPE_INDEX_FIELD,
				(Generic)SymQueryIndex(symtab,SYMTAB_INTEGER_TYPE_STRING));
	}

	return regIndex;

}

/**
 * Get the symbol table index of a free floating-point register
 *
 * @param symtab a symbol table
 * @return the symbol table index of a free floating-point register
 */
int getFreeFloatRegisterIndex(SymTable symtab) {
	int reg = allocateFloatRegister();
	char* symReg = getFloatRegisterName(reg);
	int regIndex;

	if ((regIndex = SymQueryIndex(symtab,symReg)) == SYM_INVALID_INDEX) {
		regIndex = SymIndex(symtab,symReg);
		SymPutFieldByIndex(symtab,regIndex,SYMTAB_REGISTER_INDEX_FIELD,(Generic)reg);
		SymPutFieldByIndex(symtab,regIndex,SYMTAB_TYPE_INDEX_FIELD,
				(Generic)SymQueryIndex(symtab,SYMTAB_FLOAT_TYPE_STRING));
	}

	return regIndex;

}
