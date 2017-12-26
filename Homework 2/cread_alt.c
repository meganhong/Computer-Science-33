//
//  3.c
//  homework 2
//
//  Created by Megan on 10/16/17.
//  Copyright © 2017 Megan. All rights reserved.
//

#include <stdio.h>

long cread_alt(long *xp)
{
    long result = 0;
    return *(xp ? xp : &result);
}

//compiled useing -O2
