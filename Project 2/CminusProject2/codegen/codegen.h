#ifndef CODEGEN_H_
#define CODEGEN_H_

#include <util/symtab.h>
#include <codegen/types.h>

#define SYSCALL_PRINT_INTEGER "1"	/**< The syscall code for printing an integer */
#define SYSCALL_PRINT_FLOAT "2"	/**< The syscall code for printing a float */
#define SYSCALL_PRINT_STRING "4"	/**< The syscall code for printing a string */
#define SYSCALL_READ_INTEGER "5"	/**< The syscall code for reading an integer */
#define SYSCALL_READ_FLOAT "6"	/**< The syscall code for reading a float */
#define SYSCALL_EXIT "10"			/**< The syscall code for exiting the interpreter */

EXTERN(void, emitDataPrologue, (DList dataList));
EXTERN(void, emitInstructions,(DList list));
int emitLoadVariableAddress(DList instList, SymTable symtab, char* variableName);
char* makeDataVariableDeclaration(DList dataList, SymTable symtab, int variableIndex);
void emitAssignVariable(DList instList, SymTable symtab, int variableName, int value);
void emitProcedurePrologue(DList instList, SymTable symtab, int index);
void writeNewLine(DList);



#endif /*CODEGEN_H_*/

