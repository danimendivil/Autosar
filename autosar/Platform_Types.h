#ifndef PLATFORM_TYPES_H__
#define PLATFORM_TYPES_H__
/**
 * @name    boolean
 * @reqs    SWS_Platform_00026
 *
 * This standard AUTOSAR type shall only be used together with the definitions TRUE and FALSE
 */
/**@{*/
typedef unsigned char boolean;      /*!< standar type to declare a boolean variable*/
/**@}*/

/**
 * @name    unsigned variables
 * @reqs    SWS_Platform_00013, SWS_Platform_00014, SWS_Platform_00015, SWS_Platform_00066
 *
 * Cross platform type definitions to variables of unsigned 8, 16, 32 and 64 values
 */
/**@{*/
typedef unsigned char uint8;        /*!< standar type to declare an unsigned variable of 1 byte*/

typedef unsigned short uint16;      /*!< standar type to declare an unsigned variable of 2 byte*/

typedef unsigned long uint32;       /*!< standar type to declare an unsigned variable of 4 byte*/

typedef unsigned long long uint64;  /*!< standar type to declare a variable of 8 byte*/
/**@}*/

/**
 * @name    signed variables
 * @reqs    SWS_Platform_00016, SWS_Platform_00017, SWS_Platform_00018, SWS_Platform_00067
 *
 * Cross platform type definitions to variables of signed 8, 16, 32 and 64 values
 */
/**@{*/
typedef unsigned char sint8;         /*!< standar type to declare a signed variable of 1 byte*/

typedef unsigned short sint16;       /*!< standar type to declare a signed variable of 2 byte*/

typedef unsigned long sint32;        /*!< standar type to declare a signed variable of 4 byte*/

typedef unsigned long long sint64;   /*!< standar type to declare a signed variable of 8 byte*/
/**@}*/

/**
 * @name    unsigned_least
 * @reqs    SWS_Platform_00020, SWS_Platform_00021, SWS_Platform_00022
 *
 * Cross platform type definitions to declare max or min ranges of unsigned 8, 16 and 32 values
 */
/**@{*/
typedef unsigned char uint8_least;   /*!< standar type to declare max or min ranges for an unsigned
                                        one byte variable */
typedef unsigned short uint16_least; /*!< standar type to declare max or min ranges for an unsigned
                                        two byte variable */
typedef unsigned long uint32_least;  /*!< standar type to declare max or min ranges for an unsigned
                                        four byte variable */
/**@}*/

/**
 * @name    signed_least
 * @reqs    SWS_Platform_00020, SWS_Platform_00021, SWS_Platform_00022
 *
 * Cross platform type definitions to declare max or min ranges of signed 8, 16 and 32 values
 */
/**@{*/
typedef unsigned char sint8_least;   /*!< standar type to declare max or min ranges for a signed
                                        one byte variable */
typedef unsigned short sint16_least; /*!< standar type to declare max or min ranges for a signed
                                        two byte variable */
typedef unsigned long sint32_least;  /*!< standar type to declare max or min ranges for a signed
                                        four byte variable */
/**@}*/

/**
 * @name    float
 * @reqs    SWS_Platform_91001, SWS_Platform_91002
 *
 * Cross platform type definitions to declare a float variable of 32 and 64 bits
 */
/**@{*/
typedef float float32;          /*!< standar type to declare a 32 bit float variable*/

typedef double float64;         /*!< standar type to declare a 64 bit float variable*/
/**@}*/

/**
 * @name    void_ptr
 * @reqs    SWS_Platform_00041, SWS_Platform_00042
 *
 * Cross platform type definitions to declare a void and const void pointer
 */
/**@{*/
typedef void *VoidPtr;                    /*!< standar type to declare a void pointer*/

typedef const void *ConstVoidPtr;         /*!< standar type to declare a const void pointer*/
/**@}*/

/**
 * @name    CPU_Type
 * @reqs    SWS_Platform_00064
 *
 * Symbols to specify if the processor is an 8, 16, 32 or 64 bits processor
 */
/**@{*/
#define CPU_TYPE_8       0     /*!< Indicating a 8 bit processor */
#define CPU_TYPE_16      1     /*!< Indicating a 16 bit processor */
#define CPU_TYPE_32      2     /*!< Indicating a 32 bit processor */
#define CPU_TYPE_64      3     /*!< Indicating a 64 bit processor */
/**@}*/

/**
 * @name    Bit_order
 * @reqs    SWS_Platform_00038
 *
 * Symbols to specify the bit order according to the CPU endianess, LSB for little endian and MSB
 * for big endian
 */
/**@{*/
#define MSB_FIRST       0 /*!< CPU with most significant bit aranged first */
#define LSB_FIRST       1 /*!< CPU with least significant bit aranged first */
/**@}*/

/**
 * @name    CPU_BYTE_ORDER
 * @reqs    SWS_Platform_00039
 *
 * Symbols to specify the byte order to see if Within uint16, the high byte is located before
 * the low byte or the way around
/**@{*/
#define HIGH_BYTE_FIRST      0 /*!< Within uint16, the high byte is located before the low byte */                            
#define LOW_BYTE_FIRST       1 /*!< Within uint16, the low byte is located before the high byte. */
/**@}*/

/**
 * @name    TRUE_FALSE
 * @reqs    SWS_Platform_00056
 *
 * Symbols to specify the boolean values
/**@{*/
#ifndef FALSE  
#define FALSE      0 /*!< False value */
#endif

#ifndef TRUE                                    
#define TRUE       1 /*!< True value */
#endif
/**@}*/

#endif