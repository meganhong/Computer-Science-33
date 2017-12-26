//
//  2.c
//  HOMEWORK 1
//
//  Created by Megan on 10/4/17.
//  Copyright © 2017 Megan. All rights reserved.
//

#include <stdio.h>

int int_shifts_are_arithmetic()
{
    return(-1 >> 1) == -1;
}

int main()
{
    int x = int_shifts_are_arithmetic();
    printf("%d", x);
}
