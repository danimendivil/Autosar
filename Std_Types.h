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

