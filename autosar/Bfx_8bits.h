#ifndef BFX_8_bits_H__
#define BFX_8_bits_H__
#include "Platform_Types.h"

/**
* @brief   **Bfx_SetBit 8 bits**
*
*    This function shall set the logical status of input data as ’1’ at the requested bit position
*
* @param   Data[in] Input data
* @param   BitPn[in] Bit position
*/
static inline void Bfx_SetBit_u8u8( uint8 *Data, uint8 BitPn )
{
    *Data |= (0x01u << BitPn);
}

/**
* @brief   **Bfx_ClrBit 8 bits**
*
*    This function shall clear the logical status of the input data to ’0’ at the requested bit position.
*
* @param   Data[in] Input data
* @param   BitPn[in] Bit position
*/
static inline void Bfx_ClrBit_u8( uint8 *Data, uint8 BitPn )
{
    *Data &= ~(0x01u << BitPn);
}

/**
* @brief   **Bfx_GetBit 8 bits**
*
*    This function shall return the logical status of the input data for the requested bit position.
*
* @param   Data[in] Input data
* @param   BitPn[in] Bit position
* @retval  boolean Bit Status
*/
static inline boolean Bfx_GetBit_u8_u8( uint8 Data, uint8 BitPn )
{
    boolean result;

    if ( (Data & (0x01u << BitPn)) != 0x00u )
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }
    return result;
}

/**
* @brief   **Bfx_SetBits 8 bits**
*
*    This function shall set the input data as ’1’ or ’0’ as per ’Status’ value starting from ’BitStartPn’
*    for the length ’BitLn’.
*
* @param   Data[in] Input data
* @param   BitStartPn[in] Start bit position
* @param   BitLn[in] Bit field length
* @param   Status[in] Status value
*/
static inline void Bfx_SetBits_uint8_u8u8u8( uint8 *Data, uint8 BitStartPn, uint8 BitLn, uint8 Status )
{
    uint8 mask = (1U << BitLn) - 1U;

    if(Status == 1)
    {
        *Data = (*Data | (mask<<BitStartPn));
    }
    else
    {
        *Data = (*Data & ~(mask << BitStartPn));
    }
}

/**
* @brief   **Bfx_GetBits 8 bits**
*
*    This function shall return the Bits of the input data starting from ’BitStartPn’ for the
*    length of ’BitLn’
*
* @param   Data[in] Input data
* @param   BitStartPn[in] Start bit position
* @param   BitLn[in] Bit field length
*/
static inline uint8 Bfx_GetBits_uint8u8u8_uint8( uint8 Data, uint8 BitStartPn, uint8 BitLn )
{
    uint8 mask = (1U << BitLn) - 1U;
    return (Data>>BitStartPn) &  mask;
}

/**
* @brief   **Bfx_SetBitMask 8 bits**
*
*    This function shall set the data to logical status ’1’ as per the corresponding Mask bits when set
*    to value 1 and remaining bits will retain their original values.
*
* @param   Data[in] Input data
* @param   Mask[in] Mask used to set bits
*/
static inline void Bfx_SetBitMask_uint8_uint8( uint8 *Data, uint8 Mask )
{
    *Data |= Mask;
}

/**
* @brief   **Bfx_ClrBitMask 8 bits**
*
*    This function shall clear the logical status to ’0’ for the input data for all the bit positions as per
*    the mask.
*
* @param   Data[in] Input data
* @param   Mask[in] Mask value
*/
static inline void Bfx_ClrBitMask_uint8_uint8( uint8* Data, uint8 Mask )
{
    *Data &= ~Mask;
}

/**
* @brief   **Bfx_TstBitMask 8 bits**
*
*    This function shall return TRUE, if all bits defined in Mask value are set in the input Data value.
*    In all other cases this function shall return FALSE.
*
* @param   Data[in] Input data
* @param   Mask[in] Maske value
* @retval  boolean Value
*/
static inline boolean Bfx_TstBitMask_uint8_uint8_u8( uint8 Data, uint8 Mask )
{
    boolean result;

    if((Data & Mask) == Mask)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}

/**
* @brief   **Bfx_TstBitLnMask 8 bits**
*
*    This function makes a test on the input data and if at least one bit is set as per the mask, then
*    the function shall return TRUE, otherwise it shall return FALSE.
*
* @param   Data[in] Input data
* @param   Mask[in] Maske value
* @retval  boolean Value
*/
static inline boolean Bfx_TstBitLnMask_uint8_uint8_u8( uint8 Data, uint8 Mask )
{
    boolean result;

    if((Data & Mask) != 0)
    {
        result = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;

}

/**
* @brief   **Bfx_ToggleBits 8 bits**
*
*    This function toggles all the bits of data (1’s Complement Data).
*
* @param   Data[in] Input data
*/
static inline void Bfx_ToggleBits_uint8(uint8* Data) 
{
    *Data = ~(*Data);
}

/**
* @brief   **Bfx_ToggleBitMask 8 bits**
*
*    This function toggles the bits of data when the corresponding bit of the mask is enabled and
*    set to 1.
*
* @param   Data[in] Input data
* @param   Mask[in] Mask value
*/
static inline void Bfx_ToggleBitMask_u8u8(uint8* Data, uint8 Mask) 
{
    *Data ^= Mask;
}

/**
* @brief   **Bfx_ShiftBitRt 8 bits**
*
*    his function shall shift data to the right by ShiftCnt. The most significant bit (left-most bit) is
*    replaced by a ’0’ bit and the least significant bit (right-most bit) is discarded for every single bit
*    shift cycle.
*
* @param   Data[in] Input data
* @param   ShiftCnt[in] Shift right count
*/
static inline void Bfx_ShiftBitRt_u8u8(uint8 *Data, uint8 ShiftCnt) 
{
    *Data >>= ShiftCnt;
}

/**
* @brief   **Bfx_ShiftBitLt 8 bits**
*
*    This function shall shift data to the left by ShiftCnt. The least significant bit (right-most bit) is
*    replaced by a ’0’ bit and the most significant bit (left-most bit) is discarded for every single bit
*    shift cycle.
*
* @param   Data[in] Input data
* @param   ShiftCnt[in] Shift left count
*/
static inline void Bfx_ShiftBitLt_u8u8(uint8 *Data, uint8 ShiftCnt) 
{
    *Data <<= ShiftCnt;
}

/**
* @brief   **Bfx_PutBit 8 bits**
*
*    This function shall update the bit specified by BitPn of input data as ’1’ or ’0’ as per ’Status’
*    value.
*
* @param   Data[in] Input data
* @param   BitPn[in] Bit position
* @param   Status[in] Status value
*/
static inline void Bfx_PutBit_u8u8(uint8_t* Data, uint8_t BitPn, uint8_t Status) 
{
    if (Status != 0U) 
    {
        *Data |= (0x01u << BitPn);
    } else 
    {
        *Data &= ~(0x01u << BitPn);
    }
}

#endif