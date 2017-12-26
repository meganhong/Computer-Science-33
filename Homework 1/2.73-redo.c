//
//  2.c
//  HOMEWORK 1
//
//  Created by Megan on 10/5/17.
//  Copyright © 2017 Megan. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
int saturating_add(int x, int y)
{
    int sum = x + y;
    int overflow = __builtin_add_overflow_p(x,y,(int)0);
    overflow = ~(overflow - 1);
    
    int w = sizeof(int) << 3;
    int shift = w - 1;
    
    int m_x = x >> shift;
    int m_y = y >> shift;
    int m_sum = sum >> shift;
    
    int pos_overflow = m_sum & ~m_x & ~m_y;
    int neg_overflow = ~m_sum & m_x & m_y;
    int no_overflow = ~overflow;
    
    int result = (pos_overflow & INT_MAX)|(neg_overflow & INT_MIN)|(no_overflow & sum);
    
    return result;
}


int main(void){

return saturating_add(INT_MAX, 1);
}
