/*
 * types.h
 *
 *  Created on: Jul 13, 2009
 *      Author: carr
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <util/general.h>
#include <util/symtab.h>
#include <codegen/symfields.h>

#define INTEGER_SIZE 4	/**< The number of bytes for an integer */
#define FLOAT_SIZE 4	/**< The number of bytes for a single-precision float */
#define VOID_SIZE 4 	/**< The number of bytes for a void value */

#define INTEGER_TYPE 0 /**< an integer */
#define FLOAT_TYPE 1   /**< a single-precision float */
#define ERROR_TYPE 2
#define VOID_TYPE 3
#define NUM_TYPES 4

EXTERN(bool, isArrayType, (SymTable symtab, int typeIndex));
EXTERN(int, getTypeByIndex, (SymTable symtab, int symIndex));
EXTERN(int, getMemoryTypeByIndex, (SymTable symtab, int symIndex));

#endif /* TYPES_H_ */
