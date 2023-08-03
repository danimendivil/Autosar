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
 * @brief  is a standard data structure used to store version information about
 *         AUTOSAR software modules
 *
 * @reqs   SWS_Std_00021
 */
typedef struct 
{
    Std_TransformerErrorCode errorCode;                /*!< Represent the error*/
    Std_TransformerClass transformerClass;             /*!< Represent where the error ocurred*/
} Std_VersionInfoType;