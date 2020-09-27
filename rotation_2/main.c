#include <msp430g2553.h>
#include <stdio.h>


unsigned long int seed = 1; // global variable
unsigned long int lcg_res = 0; // global variable

/*
** linear congruential generator
*/

unsigned long int ft_random()
{
    unsigned long int a = 1103515245;
    unsigned long int m = 32768;
    int c = 12345;

    seed = ((seed * a + c) / 65536) % m;
    return (seed);
}

/*
* main.c
*/
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;
    unsigned int count;
    //unsigned int i,j;

    P1OUT = 0;
    P1DIR = BIT0^BIT6;
    //P1DIR = 1;

    for (;;)
    {
        lcg_res = ft_random() % 9;
        if (lcg_res == 8)
        {
            P1OUT ^= BIT0;
            for (count = 0; count < 60000; count++); // timer
            P1OUT = 0;
        }
        else if (lcg_res == 7 || lcg_res == 6)
        {
            P1OUT ^= BIT6;
            for (count = 0; count < 60000; count++); // timer
            P1OUT = 0;
        }
        else
        {
                P1OUT = 0;
                for (count = 0; count < 60000; count++); //timer
                P1OUT = 0;
        }
    }

}
