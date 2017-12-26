//
//  bits.c
//  lab 1
//
//  Created by Megan on 10/9/17.
//  Copyright © 2017 Megan. All rights reserved.
//

#include "bits.h"
#include <limits.h>

/*
 * CS:APP Data Lab
 *
 * Megan Hong 904752365
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

Replace the "return" statement in each function with one
or more lines of C code that implements the function. Your code
must conform to the following style:

int Funct(arg1, arg2, ...) {
    /* brief description of how your implementation works */
    int var1 = Expr1;
    ...
    int varM = ExprM;
    
    varJ = ExprJ;
    ...
    varN = ExprN;
    return ExprR;
}

Each "Expr" is an expression using ONLY the following:
1. Integer constants 0 through 255 (0xFF), inclusive. You are
not allowed to use big constants such as 0xffffffff.
2. Function arguments and local variables (no global variables).
3. Unary integer operations ! ~
4. Binary integer operations & ^ | + << >>

Some of the problems restrict the set of allowed operators even further.
Each "Expr" may consist of multiple operators. You are not restricted to
one operator per line.

You are expressly forbidden to:
1. Use any control constructs such as if, do, while, for, switch, etc.
2. Define or use any macros.
3. Define any additional functions in this file.
4. Call any functions.
5. Use any other operations, such as &&, ||, -, or ?:
6. Use any form of casting.
7. Use any data type other than int.  This implies that you
cannot use arrays, structs, or unions.


You may assume that your machine:
1. Uses 2s complement, 32-bit representations of integers.
2. Performs right shifts arithmetically.
3. Has unpredictable behavior when shifting an integer by more
than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
/*
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 */
int pow2plus1(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    return (1 << x) + 1;
}

/*
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 */
int pow2plus4(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    int result = (1 << x);
    result += 4;
    return result;
}

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
1. Define or use any macros.
2. Define any additional functions in this file.
3. Call any functions.
4. Use any form of casting.
5. Use any data type other than int or unsigned.  This means that you
cannot use arrays, structs, or unions.
6. Use any floating point data types, operations, or constants.


NOTES:
1. Use the dlc (data lab checker) compiler (described in the handout) to
check the legality of your solutions.
2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
that you are allowed to use for your implementation of the function.
The max operator count is checked by dlc. Note that '=' is not
counted; you may use as many of these as you want without penalty.
3. Use the btest test harness to check your functions for correctness.
4. Use the BDD checker to formally verify your functions
5. The maximum number of ops for each function is given in the
header comment for each function. If there are any inconsistencies
between the maximum ops in the writeup and in this file, consider
this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
    
    // check both positive and negative
    
    int a = x >> 31; // shifts 31 bits to determine sign, if 1, then number is not 0
    int b = (~x + 1) >> 31; // change sign to see if number is negative
    
    return (a | b) + 1; // adds 1 to return 0 if x is a number and 1 if x is 0
    
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    int temp = (85 << 8) | 85;
    int mask = (temp << 16) | temp; // 01010...0101
    int count = (x & mask) + ((x >> 1) & mask); // combine pairs of bits, yields 0, 1, or 2
    
    temp = (51 << 8) | 51;
    mask = (temp << 16) | temp; // 00110011...
    count = (count & mask) + ((count >> 2) & mask);
    
    temp = (15 << 8) | 15;
    mask = (temp << 16) | temp; // 00001111...
    count = (count & mask) + ((count >> 4) & mask);
    
    mask = 255 << 16 | 255;
    count = (count & mask) + ((count >> 8) & mask); // 0000000011111111...
    
    mask = 255 << 8 | 255;
    count = (count & mask) + ((count >> 16) & mask); // 16 0's and 16 1's
    
    return count;
}

/*
 * bitOr - x|y using only ~ and &
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
    return ~(~x & ~y);
}
/*
 * bitRepeat - repeat x's low-order n bits until word is full.
 *   Can assume that 1 <= n <= 32.
 *   Examples: bitRepeat(1, 1) = -1
 *             bitRepeat(7, 4) = 0x77777777
 *             bitRepeat(0x13f, 8) = 0x3f3f3f3f
 *             bitRepeat(0xfffe02, 9) = 0x10080402
 *             bitRepeat(-559038737, 31) = -559038737
 *             bitRepeat(-559038737, 32) = -559038737
 *   Legal ops: int and unsigned ! ~ & ^ | + - * / % << >>
 *             (This is more general than the usual integer coding rules.)
 *   Max ops: 40
 *   Rating: 4
 */
int bitRepeat(int x, int n) {
    //    int checkOverflow = !!(n ^ 32) - 1; // returns -1 if n is 32 and 0 if otherwise
    //    int result = (~(-1 << n)) & x; // gets rid of any excess numbers
    //    int mask = -1 << 5; // mask for all the n's (biggest is 16, which is 10000)
    //
    //    result = result << n | result;
    //    int n2 = n*2;
    //    result = ((result << n2) & ~(!(n2 & mask)-1)) | result;
    //
    //    int n4 = n*4;
    //    result = ((result << n4) & ~(!(n4 & mask)-1)) | result;
    //
    //    int n8 = n*8;
    //    result = ((result << n8) & ~(!(n8 & mask)-1)) | result;
    //
    //    int n16 = n*16;
    //    result = ((result << n16) & ~(!(n16 & mask)-1)) | result;
    //
    //    return (x & checkOverflow) | (result & ~checkOverflow);
    
    int checkOverflow = n % 32; // returns 0 if n is 32
    int result = (~(-1 << n)+ ((!checkOverflow << 31) >> 31)) & x; // gets rid of any excess numbers
    
    result = result << checkOverflow | result;
    
    int n2 = n*2;
    checkOverflow = ~((31 - n2) >> 31);
    result = (result << (n2 & checkOverflow)) | result;
    
    int n4 = n*4;
    checkOverflow = ~((31 - n4) >> 31);
    result = (result << (n4 & checkOverflow)) | result;
    
    int n8 = n*8;
    checkOverflow = ~((31 - n8) >> 31);
    result = (result << (n8 & checkOverflow)) | result;
    
    int n16 = n*16;
    checkOverflow = ~((31 - n16) >> 31);
    result = (result << (n16 & checkOverflow)) | result;
    
    return ((x & !checkOverflow) | result);
    
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    int shift = 33 + ~n;
    
    int z = x << shift;
    z = z >> shift;
    
    return !(x ^ z); // if xOr is 0, x fits in n-bit, if 1, otherwise
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    int shift = n << 3;
    int y = x >> shift;
    int z = 255;
    return y & z;
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */

int isLessOrEqual(int x, int y) {
    int signY = !((y >> 31) & 1); // 1 if y is positive
    int signX = (x >> 31) & 1; // 1 if x is negative
    int checkSigns = (signX ^ signY); // 1 if they are the same signs, 0 if they are different
    int result = ((y + (~x + 1)) >> 31) & 1; // sign of result
    int ifTMin = !(x ^ (1 << 31));
    return ((signY & signX) | (checkSigns & !result) | ifTMin);
}

/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    int ifZero = !x;
    x = x >> 31; // shifts 31 to the right to find out sign
    return !(x & 1) & !ifZero;
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
    int mask;
    x = x >> n;
    mask = ~(((1 << 31) >> n) << 1);
    return x & mask;
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    return 1 << 31;
}

int main(void){
    int x = bitRepeat(INT_MAX, 1);
    printf( "%i \n", x);
    

}
