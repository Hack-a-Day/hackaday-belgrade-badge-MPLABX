#include "HaD_Badge.h"

// HIGH VECTOR

//#pragma code high_vector=0x1800
void interrupt_at_high_vector (void) @ 0x0
{
    asm( "goto 0x1008" );
}

// LOW VECTOR

//#pragma code low_vector=0x1806
void interrupt_at_low_vector(void) @ 0x6
{
    asm( "goto 0x1008" );
}


void main(void) @ 0xC {
    Buffer[4] = 0xFF;
    
    while (1) {
                // Add your application code
    }
}
/**
 End of File
 */