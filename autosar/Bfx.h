#ifndef BFX_H__
#define BFX_H__

#include "Platform_Types.h"
static inline void Bfx_SetBit_uint8u8( uint8 *Data, uint8 BitPn )
static inline void Bfx_ClrBit_uint8u8( uint8* Data, uint8 BitPn )
static inline boolean Bfx_GetBit_uint8u8_u8( uint8 Data, uint8 BitPn )
static inline void Bfx_SetBits_uint8u8u8u8( uint8* Data, uint8 BitStartPn, uint8 BitLn, uint8 Status )
static inline uint8 Bfx_GetBits_uint8u8u8_uint8( uint8 Data, uint8 BitStartPn, uint8 BitLn )
static inline void Bfx_SetBitMask_uint8uint8( uint8* Data, uint8 Mask )
static inline void Bfx_ClrBitMask_uint8uint8( uint8* Data, uint8 Mask )
static inline boolean Bfx_TstBitMask_uint8uint8_u8( uint8 Data, uint8 Mask )
static inline boolean Bfx_TstBitLnMask_uint8uint8_u8( uint8 Data, uint8 Mask )
static inline void Bfx_ToggleBits_uint8( uint8* Data )
static inline void Bfx_ToggleBitMask_uint8uint8( uint8* Data, uint8 Mask )
static inline void Bfx_ShiftBitRt_uint8u8( uint8* Data, uint8 ShiftCnt )
static inline void Bfx_ShiftBitLt_uint8u8( uint8* Data, uint8 ShiftCnt )
static inline void Bfx_PutBit_uint8u8u8( uint8* Data, uint8 BitPn, boolean Status )

#endif