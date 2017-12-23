//
//  343.c
//  HOMEWORK 1
//
//  Created by Megan on 10/4/17.
//  Copyright © 2017 Megan. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y)
{
    int sum = x + y;
    int w = sizeof(int) << 3;
    
    int shift = w - 1;
    int m_x = x >> shift; // most significant bit of x
    int m_y = y >> shift; // most significant bit of y
    int m_sum = sum >> shift; // most significant bit of sum
    
    int pos_overflow = m_sum & ~m_x & ~m_y;
    int neg_overflow = ~m_sum & m_x & m_y;
    int no_overflow = ~(neg_overflow|pos_overflow);
    
    int result = (pos_overflow & INT_MAX)|(neg_overflow & INT_MIN)|(no_overflow & sum);
    return result;
}