#ifndef STD_TYPES_H__
#define STD_TYPES_H__

#include "Platform_Types.h"

/**
 * @brief  This type can be used as standard API return type which is shared between the RTE
 *         and the BSW modules. range: E_OK and E_NOT_OK
 *
 * @reqs   SWS_Std_00005
 */
typedef uint8 Std_ReturnType;

/**
 * @brief  is a standard data structure used to store version information about
 *         AUTOSAR software modules
 *
 * @reqs   SWS_Std_00015
 */
typedef struct 
{
    uint16 vendorID;             /*!< Vendor ID of the software component*/
    uint16 moduleID;             /*!< Module ID of the software component*/
    uint8 sw_major_version;      /*!< Major version number of the software component*/
    uint8 sw_minor_version;      /*!< Minor version number of the software component*/
    uint8 sw_patch_version;      /*!< Patch version number of the software component*/
    
} Std_VersionInfoType;

/**
 * @brief  The type of the Std_TransformerError.
 *
 * @reqs   SWS_Std_00022
 */
typedef uint8 Std_TransformerErrorCode;     /*!< Type of error*/

/**
 * @brief  The Std_TransformerClass represents the transformer class in which the error oc-
 *         curred.
 *
 * @reqs   SWS_Std_00023, SWS_Std_00024
 */
typedef uint8 Std_TransformerClass;         /*!< Class in wich an error ocurred*/

/**
 * @brief  The data type Std_TransformerError is a struct which contains the error code and the
 *         transformer class to which the error belongs.
 *
 * @reqs   SWS_Std_00021
 */
typedef struct 
{
    Std_TransformerErrorCode errorCode;                /*!< Represent the error*/
    Std_TransformerClass transformerClass;             /*!< Represent where the error ocurred*/

} Std_TransformerError;

/**
 * @brief  The Std_TransformerForward represents a forwarded transformer status in the context
 *         of a certain transformer chain. The specific meaning of the values of 
 *         Std_TransformerForward are always to be seen for the specific transformer 
 *         chain for which the data type represents the transformer status.
 *
 * @reqs   SWS_Std_00029
 */
typedef uint8 Std_TransformerForwardCode;         /*!< data type represents the transformer status.*/

/**
 * @brief  The data type Std_TransformerForward is a struct which contains the forwarded status
 *         and the transformer class to which the forwarded status applies.
 *
 * @reqs   SWS_Std_00027
 */
typedef struct 
{
    Std_TransformerForwardCode errorCode;                /*!< data type represents the transformer status.*/
    Std_TransformerClass transformerClass;             /*!< Represent where the error ocurred*/

} Std_TransformerForward;

/**
 * @brief  The Std_MessageTypeType shall be used ot encode the different
 *         types of messages exchanged in AUTOSAR. 
 *
 * @reqs   SWS_Std_91001
 */
typedef uint8 Std_MessageTypeType;

/**
 * @brief  The Std_MessageResultType shall be used ot encode the different types of results 
 *         for response messages. Currently this encoding is limited to the distinction 
 *         between OK and ERROR responses.
 *
 * @reqs   SWS_Std_91002
 */
typedef uint8 Std_MessageResultType;        /*!< This type is used to encode different types of results for response messages*/

/**
 * @brief  Type for the function pointer to extract the relevant protocol header fields of the message and
 *         the type of the message result of a transformer. At the time being, this is limited to the types
 *         used for C/S communication (i.e., REQUEST and RESPONSE and OK and ERROR).
 *
 * @reqs   SWS_Std_91003
 */
typedef Std_ReturnType (*Std_ExtractProtocolHeaderFieldsType) (
const uint8* buffer,                    /*!< Buffer allocated by the RTE, where the transformed data has to be stored by the transformer*/
uint32 bufferLength,                    /*!< Length of the buffer*/
Std_MessageTypeType* messageType,       /*!< Canonical representation of the message type (extracted from the transformers protocol header).*/
Std_MessageResultType* messageResult    /*!< Canonical representation of the message result type (extracted from the transformers protocol header).*/
);

/**
 * @name    Safety Transformer Error Codes
 * @reqs    SRS_Xfrm_00002
 *
 * Symbols to specify transformers error codes
 * 
 */
/**@{*/
#define E_OK                      0x00u               /*!< No specific error to be injected */
#define E_SAFETY_INVALID_REP      0x01u               /*!< Repeat the last used sequence number */
#define E_SAFETY_INVALID_CRC      0x02u               /*!< Generate a deliberately wrong CRC */
#define E_SAFETY_INVALID_SEQ      0x03u               /*!< Use a wrong sequence number */
/**@}*/

/**
 * @name    E_OK, E_NOT_OK
 * @reqs    SWS_Std_00006
 *
 * Symbols to specify if an error has ocurred or not
 * 
 */
/**@{*/
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK 0x00u                /*!< There is no error */
typedef unsigned char StatusType; /* OSEK compliance */
#endif
#define E_NOT_OK 0x01u             /*!< Error has ocurred */
/**@}*/

/**
 * @name    STD_HIGH, STD_LOW
 * @reqs    SWS_Std_00007
 *
 * Symbols to specify The physical state 
 * 
 */
/**@{*/
#define STD_HIGH 0x01u      /*!< Physical state 5V or 3.3V */
#define STD_LOW 0x00u       /*!< Physical state 0V */
/**@}*/

/**
 * @name    STD_ACTIVE, STD_IDLE
 * @reqs    SWS_Std_00013
 *
 * Symbols to specify The logical state 
 * 
 */
/**@{*/
#define STD_ACTIVE 0x01u        /*!< Logical state active */
#define STD_IDLE 0x00u          /*!< Logical state idle */
/**@}*/

/**
 * @name    STD_ON, STD_OFF
 * @reqs    SWS_Std_00010
 *
 * Symbols to specify the state 
 * 
 */
/**@{*/
#define STD_ON 0x01u            /*!< State on */
#define STD_OFF 0x00u           /*!< State off */
/**@}*/

/**
 * @name    NULL_PTR
 * @reqs    SWS_Std_00031
 *
 * Symbols to specify a null ptr
 * 
 */
/**@{*/
#define NULL_PTR ((void *)0)            /*!< Null ptr define */
/**@}*/

/**
 * @name    STD_TRANSFORMER
 * @reqs    SWS_Std_00026
 *
 * Symbols to specify possible values to Std_TransformerClass
 * 
 */
/**@{*/
#define STD_TRANSFORMER_UNSPECIFIED     0x00u               /*!< Transformer of a unspecified transformer class */
#define STD_TRANSFORMER_SERIALIZER      0x01u               /*!< Transformer of a serializer class */
#define STD_TRANSFORMER_SAFETY          0x02u               /*!< Transformer of a safety class */
#define STD_TRANSFORMER_SECURITY        0x03u               /*!< Transformer of a security class. */
#define STD_TRANSFORMER_CUSTOM          0xFFu               /*!< Transformer of a custom class not standardized by AUTOSAR. */
/**@}*/

/**
 * @name    Std_MessageTypeType range
 * @reqs    SWS_Std_00017
 *
 * Symbols to specify possible values to Std_MessageTypeType
 * 
 */
/**@{*/
#define STD_MESSAGETYPE_REQUEST       0x00u               /*!< Message type for a request message */
#define STD_MESSAGETYPE_RESPONSE      0x01u               /*!< Message type for a response message */
/**@}*/

/**
 * @name    Std_MessageResultType range
 * @reqs    SWS_Std_00017
 *
 * Symbols to specify possible values to Std_MessageResultType
 * 
 */
/**@{*/
#define STD_MESSAGERESULT_OK         0x00u               /*!< STD_MESSAGERESULT_OK */
#define STD_MESSAGERESULT_ERROR      0x01u               /*!< Messageresult for an ERROR response */
/**@}*/

#endif