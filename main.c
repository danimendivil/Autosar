#include "Registers.h"
int main( void )
{
    /*enable GPIOA clock*/
    RCC_GPIOA_CLK_EN();
    /*Set pin 5 from port A as output*/
    PORTA->MODER &= ~(2 << (5 << 1));
    
    for( ; ; ) /*infinite loop*/
    {
        /*toggle pin 5 where the led is conected*/
        PORTA->ODR ^= (1 << 5);
        /*Dirty delay*/
        for( unsigned long i=0 ; i<100000 ; i++ );
    }
    return 0;
}