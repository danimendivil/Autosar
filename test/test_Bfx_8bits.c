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
 * The test validates if the mask with value 0x0F is correctly set to a variable of value 0xF0,to pass the test
 * data should have a value of 0xFF
 */
void test__BBfx_SetBitMask_uint8_uint8_byte0x0F( void )
{
    uint8 Data = 0xF0;
    Bfx_SetBitMask_uint8_uint8( &Data, 0x0F );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0xFF, "Maske was not set right" );
}

/**
 * @brief   **Test set mask 0x0A**
 *
 * The test validates if the mask with value 0x0A is correctly set to a variable of value 0xF0,to pass the test
 * data should have a value of 0xFA
 */
void test__BBfx_SetBitMask_uint8_uint8_byte0xA0( void )
{
    uint8 Data = 0xF0;
    Bfx_SetBitMask_uint8_uint8( &Data, 0x0A );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0xFA, "Maske was not set right" );
}