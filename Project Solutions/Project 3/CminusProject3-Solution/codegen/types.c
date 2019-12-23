/*
 * types.c
 *
 *  Created on: Jul 13, 2009
 *      Author: carr
 */

#include <string.h>
#include <codegen/types.h>
#include <util/symtab.h>
#include <codegen/symfields.h>

/**
 * Return the basic type value for an entity stored in the symbol table
 *
 * @param symtab a symbol table
 * @param symIndex a symbol table index
 * @return see above
 */
int getTypeByIndex(SymTable symtab, int symIndex) {
	int typeIndex = (int)SymGetFieldByIndex(symtab,symIndex,SYMTAB_TYPE_INDEX_FIELD);
	return (int)SymGetFieldByIndex(symtab,typeIndex,SYMTAB_BASIC_TYPE_FIELD);
}
/**
 * Return the basic type of the memory location pointed to by a register.
 *
 * @param symtab a symbol table
 * @param symIndex a symbol table index
 * @return see above
 */
int getMemoryTypeByIndex(SymTable symtab, int symIndex) {
	int typeIndex =(int)SymGetFieldByIndex(symtab,symIndex,SYMTAB_INDIRECT_TYPE_FIELD);
	return (int)SymGetFieldByIndex(symtab,typeIndex,SYMTAB_BASIC_TYPE_FIELD);
}

/**
 * Return true if a type is an array, false otherwise.
 *
 * @param symtab a symbol table
 * @param typeIndex a symbol table index for a type
 * @return see above
 */
bool isArrayType(SymTable symtab, int typeIndex) {
	char *typeString = SymGetFieldByIndex(symtab,typeIndex,SYM_NAME_FIELD);

	return (bool)(strchr(typeString,'[') != NULL);
}
