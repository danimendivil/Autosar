#include "unity.h"
#include "Bfx_8bits.h"

/*this function is required by Ceedling to run any code before the test cases*/
void setUp( void )
{
}

/*this function is required by Ceedling to run any code after the test cases*/
void tearDown( void )
{
}

/**
 * @brief   **Test set bit 2**
 *
 * The test validates if bit 2 is set over a varible with value 0x00, to pass the test data should have
 * a value of 0x04.
 */
void test__Bfx_SetBit_u8u8__bit2( void )
{
    uint8 Data = 0u;
    Bfx_SetBit_u8u8( &Data, 2u );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x04, "Bit 2 was not set as supposed to be" );
}

/**
 * @brief   **Test set bit 7**
 *
 * The test validates if bit 7 is set over a varible with value 0x00, to pass data tested should have
 * a value of 0x80.
 */
void test__Bfx_SetBit_u8u8__bit7( void )
{
    uint8 Data = 0u;
    Bfx_SetBit_u8u8( &Data, 7u );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x80, "Bit 7 was not set as supposed to be" );
}

/**
 * @brief   **Test clear bit 1**
 *
 * The test validates if bit 1 is cleared over a varible with value 0b10001010, to pass the test data should have
 * a value of 0b10001000.
 */
void test__Bfx_ClrBit_u8_bit1( void )
{
    uint8 Data = 0b10001010;
    Bfx_ClrBit_u8( &Data, 1 );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0b10001000, "Bit 1 was not cleared" );
}

/**
 * @brief   **Test clear bit 3**
 *
 * The test validates if bit 1 is cleared over a varible with value 0b11001010, to pass the test data should have
 * a value of 0b11000010.
 */
void test__Bfx_ClrBit_u8_bit3( void )
{
    uint8 Data = 0b11001010;
    Bfx_ClrBit_u8( &Data, 3 );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0b11000010, "Bit 3 was not cleared" );
}

/**
 * @brief   **Test get bit 3**
 *
 * The test validates if bit 3 is TRUE over a varible with value 0b11001010, to pass the test data should have
 * a value of TRUE.
 */
void test__Bfx_GetBit_u8_u8_bit3( void )
{
    uint8 Data = 0b11001010;
    Data = Bfx_GetBit_u8_u8( Data, 3 );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, TRUE, "Bit 3 was not true" );
}

/**
 * @brief   **Test get bit 4**
 *
 * The test validates if bit 4 is FALSE over a varible with value 0b11001010, to pass the test data should have
 * a value of FALSE.
 */
void test__Bfx_GetBit_u8_u8_bit4( void )
{
    uint8 Data = 0b11001010;
    Data = Bfx_GetBit_u8_u8( Data, 4 );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, FALSE, "Bit 3 was not true" );
}

/**
 * @brief   **Test set bits 0,4**
 *
 * The test validates if bits on position 0 to 3 are set to 1 on a variable witn value of 0x00, to pass the test data 
 * should have a value of 0x0F
 */
void test__Bfx_SetBits_uint8_u8u8u8_bit0_bit3( void )
{
    uint8 Data = 0x00u;
    Bfx_SetBits_uint8_u8u8u8( &Data, 0, 4, 1 );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x0Fu, "Value is not correct" );
}

/**
 * @brief   **Test set bits 6,7**
 *
 * The test validates if bits on position 6 to 7 are set to 0 on a variable witn value of 0xF0, to pass the test data 
 * should have a value of 0x30
 */
void test__Bfx_SetBits_uint8_u8u8u8_bit6_bit7( void )
{
    uint8 Data = 0xF0u;
    Bfx_SetBits_uint8_u8u8u8( &Data, 6, 2, 0 );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x30, "Value is not correct" );
}

/**
 * @brief   **Test set bits 6,7**
 *
 * The test validates if the return value of get bits is correctly on a variable witn value of 0xF0, to pass the test
 * data should have a value of 0x03.
 */
void test__Bfx_GetBits_uint8u8u8_uint8_bit6_bit7( void )
{
    uint8 Data = 0xF0u;
    Data=Bfx_GetBits_uint8u8u8_uint8( 0xF0u, 6, 2 );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x03, "Value is not correct" );
}

/**
 * @brief   **Test set bits 4,7**
 *
 * The test validates if the return value of get bits is correctly on a variable witn value of 0xF0, to pass the test
 * data should have a value of 0x0F.
 */
void test__Bfx_GetBits_uint8u8u8_uint8_bit4_bit7( void )
{
    uint8 Data = 0xF0u;
    Data=Bfx_GetBits_uint8u8u8_uint8( 0xF0u, 4, 4 );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x0F, "Value is not correct" );
}

/**
 * @brief   **Test set mask 0x0F**
 *
 * The test validates if the mask with value 0x0F correctly sets the ones to a variable of value 0xF0,to pass the test
 * data should have a value of 0xFF
 */
void test__BBfx_SetBitMask_uint8_uint8_byte0x0F( void )
{
    uint8 Data = 0xF0;
    Bfx_SetBitMask_uint8_uint8( &Data, 0x0F );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0xFF, "Mask was not set right" );
}

/**
 * @brief   **Test set mask 0x0A**
 *
 * The test validates if the mask with value 0x0A correctly sets the ones to a variable of value 0xF0,to pass the test
 * data should have a value of 0xFA
 */
void test__BBfx_SetBitMask_uint8_uint8_byte0xA0( void )
{
    uint8 Data = 0xF0;
    Bfx_SetBitMask_uint8_uint8( &Data, 0x0A );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0xFA, "Mask was not set right" );
}

/**
 * @brief   **Test clear mask 0x05**
 *
 * The test validates if the mask with value 0x05 correctly sets the zeros to a variable of value 0xFF,to pass the test
 * data should have a value of 0xFA
 */
void test__Bfx_ClrBitMask_uint8_uint8_byte0x05( void )
{
    uint8 Data = 0xFF;
    Bfx_ClrBitMask_uint8_uint8( &Data, 0x05);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0xFA, "Mask was not set right" );
}

/**
 * @brief   **Test clear mask 0x05**
 *
 * The test validates if the mask with value 0xAA correctly sets the zeros to a variable of value 0xFF,to pass the test
 * data should have a value of 0x55
 */
void test__Bfx_ClrBitMask_uint8_uint8_byte0xAA( void )
{
    uint8 Data = 0xFF;
    Bfx_ClrBitMask_uint8_uint8( &Data, 0xAA);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x55, "Mask was not set right" );
}

/**
 * @brief   **Test clearbit mask 0x05**
 *
 * The test validates if the mask with value 0xAA has the same bits sets to one of a variable with value 0xFF,to pass the test
 * data should have a value of TRUE
 */
void test__Bfx_TstBitMask_uint8_uint8_u8_byte0xAA( void )
{
    uint8 Data = 0xFF;
    Data=Bfx_TstBitMask_uint8_uint8_u8( Data, 0xAA );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, TRUE, "Function is not checking the bits correctly" );
}

/**
 * @brief   **Test TstBit mask 0x05**
 *
 * The test validates if the mask with value 0xAA has the same bits sets to one of a variable with value 0x7F,to pass the test
 * data should have a value of FALSE
 */
void test__Bfx_TstBitMask_uint8_uint8_u8_byte0x7F( void )
{
    uint8 Data = 0x7F;
    Data=Bfx_TstBitMask_uint8_uint8_u8( Data, 0xAA );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, FALSE, "Function is not checking the bits correctly" );
}

/**
 * @brief   **Test TstBitLnMask mask 0x10**
 *
 * The test validates if the mask with value 0x10 has at least one bit set to one of a variable with value 0x92,to pass the test
 * data should have a value of TRUE
 */
void test__Bfx_TstBitLnMask_uint8_uint8_u8_byte0x10( void )
{
    uint8 Data = 0x92;
    Data=Bfx_TstBitLnMask_uint8_uint8_u8( Data, 0x10 );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, TRUE, "Function is not checking the bits correctly" );
}

/**
 * @brief   **Test TstBitLnMask mask 0x0F**
 *
 * The test validates if the mask with value 0x0F has at least one bit set to one of a variable with value 0xF0,to pass the test
 * data should have a value of FALSE
 */
void test__Bfx_TstBitLnMask_uint8_uint8_u8_byte0x0F( void )
{
    uint8 Data = 0xF0;
    Data=Bfx_TstBitLnMask_uint8_uint8_u8( Data, 0x0F );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, FALSE, "Function is not checking the bits correctly" );
}

/**
 * @brief   **Test Bfx_ToggleBits mask 0xFF**
 *
 * The test validates if the data with value 0xFF is toggled right, to pass the test Data 
 * should have a value of 0
 */
void test__Bfx_ToggleBits_uint8_byte0xFF( void )
{
    uint8 Data = 0xFF;
    Bfx_ToggleBits_uint8(&Data) ;
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0, "Function is not toggling the bits correctly" );
}

/**
 * @brief   **Test Bfx_ToggleBits mask 0xAA**
 *
 * The test validates if the data with value 0xAA is toggled right, to pass the test Data 
 * should have a value of 0x55
 */
void test__Bfx_ToggleBits_uint8_byte0xAA( void )
{
    uint8 Data = 0xAA;
    Bfx_ToggleBits_uint8(&Data) ;
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x55, "Function is not toggling the bits correctly" );
}

/**
 * @brief   **Test ToggleBitMask 0xAA**
 *
 * The test validates if the data with value 0xFF is toggled right acording to the mask 0xAA, to pass the test Data 
 * should have a value of 0x55
 */
void test__Bfx_ToggleBitMask_u8u8_byte0xAA( void )
{
    uint8 Data = 0xFF;
    Bfx_ToggleBitMask_u8u8(&Data, 0xAA);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x55, "Function is not toggling the bits correctly" );
}

/**
 * @brief   **Test ToggleBitMask 0x0A**
 *
 * The test validates if the data with value 0xFF is toggled right acording to the mask 0x0A, to pass the test Data 
 * should have a value of 0xF5
 */
void test__Bfx_ToggleBitMask_u8u8_byte0x0A( void )
{
    uint8 Data = 0xFF;
    Bfx_ToggleBitMask_u8u8(&Data, 0x0A);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0xF5, "Function is not toggling the bits correctly" );
}

/**
 * @brief   **Test ShiftBitRt 0xFF **
 *
 * The test validates if the data with value 0xFF is shift correcty to the right to pass the test
 * should have a value of 0x0F
 */
void test__Bfx_ShiftBitRt_u8u8_byte0xFF( void )
{
    uint8 Data = 0xFF;
    Bfx_ShiftBitRt_u8u8(&Data, 4);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x0F, "Data was not shift to the right" );
}

/**
 * @brief   **Test ShiftBitRt 0xA0 **
 *
 * The test validates if the data with value 0xA0 is shift correcty to the right to pass the test
 * should have a value of 0x0A
 */
void test__Bfx_ShiftBitRt_u8u8_byte0xA0( void )
{
    uint8 Data = 0xA0;
    Bfx_ShiftBitRt_u8u8(&Data, 4);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x0A, "Data was not shift to the right" );
}

/**
 * @brief   **Test ShiftBitRt 0xAA **
 *
 * The test validates if the data with value 0xAA is shift correcty to the left to pass the test
 * should have a value of 0xA0
 */
void test__Bfx_ShiftBitLt_u8u8_byte0xA0( void )
{
    uint8 Data = 0xAA;
    Bfx_ShiftBitLt_u8u8(&Data, 4);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0xA0, "Data was not shift to the left" );
}

/**
 * @brief   **Test ShiftBitRt 0x50**
 *
 * The test validates if the data with value 0xAA is shift correcty to the left to pass the test
 * should have a value of 0x40
 */
void test__Bfx_ShiftBitLt_u8u8_byte0x50( void )
{
    uint8 Data = 0x50;
    Bfx_ShiftBitLt_u8u8(&Data, 2);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x40, "Data was not shift to the left" );
}

/**
 * @brief   **Test PutBit 0x00**
 *
 * The test validates if the data with value 0x00 is change correcty acording to bitpin and status to pass the test
 * should have a value of 0x80
 */
void test__Bfx_PutBit_u8u8_bit7( void )
{
    uint8 Data = 0x00;
    Bfx_PutBit_u8u8(&Data, 7, 1);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x80, "Data was not set properly" );
}

/**
 * @brief   **Test PutBit 0xFF**
 *
 * The test validates if the data with value 0x00 is change correcty acording to bitpin and status to pass the test
 * should have a value of 0xF7
 */
void test__Bfx_PutBit_u8u8_bit3( void )
{
    uint8 Data = 0xFF;
    Bfx_PutBit_u8u8(&Data, 3, 0);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0xF7, "Data was not set properly" );
}
