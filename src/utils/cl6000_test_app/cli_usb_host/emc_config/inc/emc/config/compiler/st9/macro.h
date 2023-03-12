/** @file */
#ifndef EMC_CONFIG_COMPILER_ST9_macro_H
#define EMC_CONFIG_COMPILER_ST9_macro_H

/************************************************************************
   ; Macro definitions
   ;***********************************************************************/
#define Enable_Interrupts() asm ("ei")         /**< Insert an instruction to enable interrupts */
#define Disable_Interrupts() asm ("di")        /**< Insert an instruction to disable interrupts */
#define NOP asm ("nop")                        /**< Insert a noop instruction */
#define SAVE_PAGE asm ("push R234")            /**< Push the page register */
#define RESTORE_PAGE asm ("pop R234")          /**< Pop the page register */
#define PUSHR(x) asm ("push %0" ::"R" (x));    /**< Push the specified value */
#define PUSHr(x) asm ("push %0" ::"r" (x));    /**< Push the specified byte register variable */
#define PUSHRR(x) asm ("pushw %0" ::"RR" (x)); /**< Push the specified value */
#define PUSHrr(x) asm ("pushw %0" ::"rr" (x)); /**< Push the specified word16 register variable */
#define POPR(x) asm ("pop %0" ::"R" (x));      /**< Pop the specified value */
#define POPr(x) asm ("pop %0" ::"r" (x));      /**< Pop the specified byte register variable */
#define POPRR(x) asm ("popw %0" ::"RR" (x));   /**< Pop the specified value */
#define POPrr(x) asm ("popw %0" ::"rr" (x));   /**< Pop the specified word16 register variable */

#define ValBit(VAR, Place) ((VAR) & (1 << (Place)))  /**< Return the bit at @p Place from @p VAR */
#define SetBit(VAR, Place) ((VAR) |= (1 << (Place))) /**< Set the bit at @p Place in @p VAR */
/** Unset the bit at @p Place in the byte @p VAR */
#define ClrBit(VAR, Place) ((VAR) &= ((1 << (Place)) ^ 255))

/** Push a byte register after copying the parameter into it */
#define PUSH(x) ({ unsigned char __ch;                 \
                   asm ("ld %0,%1" : "=r" (__ch) : "g" ((unsigned char)x)); \
                   asm ("push %0" ::"r" (__ch)); })
/** Pop a byte value and return it */
#define POP() ({ unsigned char __ch;           \
                 asm ("pop %0" : "=r" (__ch) :);                \
                 __ch; })
/** Push a word16 register after copying the parameter into it */
#define PUSHW(x) ({ unsigned short __W;                  \
                    asm ("ldw %0,%1" : "=rr" (__W) : "g" ((unsigned short)x)); \
                    asm ("pushw %0" ::"rr" (__W)); })
/** Pop a word16 value and return it */
#define POPW() ({ unsigned short __W;          \
                  asm ("popw %0" : "=rr" (__W) :);               \
                  __W; })

/** This macro will set the page pointer register to an input */
#define set_page(page_nr) asm ("spp %0" ::"i" (page_nr))

#endif /* EMC_CONFIG_COMPILER_ST9_macro_H */
