#include "Platform_Types.h"

static inline void Bfx_SetBit_u8u8( uint8 *Data, uint8 BitPn )
{
    *Data |= (0x01u << BitPn);
}

static inline void Bfx_ClrBit_u8( uint8 *Data, uint8 BitPn )
{
    *Data &= ~(0x01u << BitPn);
}

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

static inline uint8 Bfx_GetBits_uint8u8u8_uint8( uint8 Data, uint8 BitStartPn, uint8 BitLn )
{
    uint8 mask = (1U << BitLn) - 1U;
    return (Data>>BitStartPn) &  mask;
}

static inline void Bfx_SetBitMask_uint8_uint8( uint8 *Data, uint8 Mask )
{
    *Data |= Mask;
}

static inline void Bfx_ClrBitMask_uint8_uint8( uint8* Data, uint8 Mask )
{
    *Data &= ~Mask;
}

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

static inline void Bfx_ToggleBits_uint8(uint8* Data) 
{
    *Data = ~(*Data);
}

static inline void Bfx_ShiftBitRt_u8u8(uint8 *Data, uint8 ShiftCnt) 
{
    *Data >>= ShiftCnt;
}

static inline void Bfx_ShiftBitLt_u8u8(uint8 *Data, uint8 ShiftCnt) 
{
    *Data <<= ShiftCnt;
}