//
//  fpwr8.c
//  fpwr8
//
//  Created by Megan on 11/6/17.
//  Copyright © 2017 Megan. All rights reserved.
//

#include <stdio.h>

static float u2f(unsigned u) { return *(float*) &u; }

float fpwr8(int x)
{
    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;
    
    if(x < -49)
    {
        /* Too small. Return 0.0 */
        exp = 0;
        frac = 0;
    }
    else if(x < -42)
    {
        /* Denormalized result */
        exp = 0;
        frac = 1 << (149 + x*3);
    }
    else if(x < 43)
    {
        /* Normalized result */
        exp = (x * 3) + 127;
        frac = 0;
    }
    else
    {
        /* Too big. Return + infinity */
        exp = 255;
        frac = 0;
    }
    
    /* Pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /* Return as float */
    return u2f(u);
}