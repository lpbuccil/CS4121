#ifndef REG_H_
#define REG_H_

#define NUM_INTEGER_REGISTERS 18 /**< the number of Mips integer registers that may be allocated */
#define NUM_FLOAT_REGISTERS 14 /**< the number of Mips floating-point registers that may be allocated */
#define CALLER_SAVED_INDEX  8
#define FLOAT_CALLER_SAVED_INDEX 6
#define NUM_CALLEE_SAVED_REGISTERS 8
#define NUM_FLOAT_CALLEE_SAVED_REGISTERS 6
#define NUM_CALLER_SAVED_REGISTERS 10
#define NUM_FLOAT_CALLER_SAVED_REGISTERS 8

EXTERN(void, initRegisters, (void));
EXTERN(void, cleanupRegisters,(void));
EXTERN(int, allocateIntegerRegister,(void));
EXTERN(void, freeIntegerRegister,(int reg));
EXTERN(char*, getIntegerRegisterName,(int reg));
EXTERN(int, allocateFloatRegister,(void));
EXTERN(void, freeFloatRegister,(int reg));
EXTERN(char*, getFloatRegisterName,(int reg));
EXTERN(void, freeRegisterByType,(int reg, int type));
EXTERN(int, getFreeIntegerRegisterIndex, (SymTable symtab));
EXTERN(int, getFreeFloatRegisterIndex, (SymTable symtab));
EXTERN(bool, isAllocatedIntegerRegister,(int reg));
EXTERN(bool, isAllocatedFloatRegister,(int reg));
#endif /*REG_H_*/
