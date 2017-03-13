/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /*relative easy*/
  return ~( (~x) | (~y) );
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
  /*left shift n by 3 to get n*8, and right shift x by that amount*/
  return ( x >> ( n << 3 ) ) & 0xff;
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
  /*generate 0b0...01...1 (# of 0 = n) and & with the shifted x*/
  int y;
  x = x >> n;
  y = ~0 << (32 + ~n);		// using (33 + ~n) won't work for n=0
  y = y << 1;
  return x & ~y;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /*using Hamming weight*/
  int one2two, two2four, four2eight, eight2sixteen, sixteen2thirtytwo;
  
  one2two = (0x55 << 8) + 0x55;
  one2two = (one2two << 16) + one2two;		// 0b01010101010101010101010101010101
  two2four = (0x33 << 8) + 0x33;
  two2four = (two2four << 16) + two2four;	// 0b00110011001100110011001100110011
  four2eight = (0x0f << 8) + 0x0f;
  four2eight = (four2eight << 16) + four2eight;	// 0b00001111000011110000111100001111
  eight2sixteen =(0xff << 16) + 0xff;		// 0b00000000111111110000000011111111
  sixteen2thirtytwo = (0xff << 8) + 0xff;	// 0b00000000000000001111111111111111
  
  x = (x & one2two) + ( (x >> 1) & one2two);
  x = (x & two2four) + ( (x >> 2) & two2four);
  x = (x & four2eight) + ( (x >> 4) & four2eight);
  x = (x & eight2sixteen) + ( (x >> 8) & eight2sixteen);
  x = (x & sixteen2thirtytwo) + ( (x >> 16) & sixteen2thirtytwo);
  
  return x;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  /*highest bit of (~x + 1)|x) is 0 only for x=0*/
  return (((~x + 1)|x)>>31) + 1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (~0 >> 31) << 31;
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
  /*change negative x to abs(x) - 1, and then shift (n-1), see rest is 0 or not*/
  int signX, posiX;
  signX = x >> 31;
  posiX = x^signX;
  return !(posiX >> (n + ~0));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  /*make x positive first, then return the divided value with extra minus sign*/
  //int signX, posiX, posiDiv;
  //signX = x >> 31;
  //posiX = (x^signX) + (signX & 0x1);
  //posiDiv = posiX >> n;
  //posiDiv = posiDiv & ~((~0 << (32 + ~n)) << 1);		// logic shift
  //return (posiDiv & (~signX)) + ((~posiDiv + 1) & signX);
  //too many operators

  /*direct right shift x and add 1 if x is negative and 
   *			have nonzero bits within the shifted range
   */
  return (x >> n) + ( (x >> 31)& (!!(~(~0 << n) & x)) );
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /*this is straight forward*/
  return ~x + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  /*first bit of (~x+1)|x is 0 only for x=0*/
  return (( x|( ~(~x+1)|x ) )>>31) + 1;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /*if x and y have different sign bit, return sign bit of x
   *else return sign bit of x - y - 1
   */
  int tmp1, tmp2, ans1, ans2;
  tmp1 = (x >> 31);
  tmp2 = tmp1^(y >> 31);
  ans1 = (tmp1 & tmp2) & 0x1;
  ans2 = ((x + ~y) >> 31) & (~tmp2) & 0x1;
  return ans1 + ans2;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  /*repeatly check the higher half bits with 1 present or not
   * if true, enter it and repeat. If not, enter the lower half bits
   */
  int tmp, tmpHigh, ind, halfLen, isOne;

  ind = 0;
  halfLen = 16;
  tmp = x;
  tmpHigh = tmp >> halfLen;
  isOne = !tmpHigh + ~0;		// 11...1 for tmpHigh with at least one bit 1
  tmp = (tmp >> (halfLen & isOne)) & ((0xff << 8) + 0xff);
  ind = ind + (halfLen & isOne);

  halfLen = 8;
  tmpHigh = tmp >> halfLen;
  isOne = !tmpHigh + ~0;
  tmp = (tmp >> (halfLen & isOne)) & 0xff;
  ind = ind + (halfLen & isOne);

  halfLen = 4;
  tmpHigh = tmp >> halfLen;
  isOne = !tmpHigh + ~0;
  tmp = (tmp >> (halfLen & isOne)) & 0xf;
  ind = ind + (halfLen & isOne);

  halfLen = 2;
  tmpHigh = tmp >> halfLen;
  isOne = !tmpHigh + ~0;
  tmp = (tmp >> (halfLen & isOne)) & 3;
  ind = ind + (halfLen & isOne);

  halfLen = 1;
  tmpHigh = tmp >> halfLen;
  isOne = !tmpHigh + ~0;
  //tmp = (tmp >> (halfLen & isOne)) & 1;
  ind = ind + (halfLen & isOne);

  return ind;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  /*get exp and frac first and then judge*/
  int exp;
  
  exp = (uf >> 23) & 0xff;

  if (!((exp + 1) & 0xff))		// exp == 0b11111111
    if (!!(uf << 9))
      return uf;

  return (1 << 31)^uf;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  /*convert to positive value first, then find exp,
   * convert frac and consider about the rounding
   */
  int sign, exp, frac, round;

  round = 0;
  sign = (x >> 31) & 1;
  if (x == 0)
    return x;
  if (x == 0x80000000){
    exp = 158;
    frac = 0;
  }
  else {
    if (sign)
      x = -x;
    exp = 0;
    while (x >> exp)
      exp = exp + 1;
    exp = exp - 1;
    frac = ((x^(1 << exp)) << (31 - exp));
    x = frac & 0xff;		// bits to throw
    frac = frac >> 8;
    round = x > 128 || ((x == 128) && (frac & 1));
    exp = exp + 127;
    frac = frac + round;
    if (frac >> 23) {
      frac = frac & 0x7fffff;
      exp = exp + 1;
    }
  }
  
  return (sign << 31) + (exp << 23) + frac;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  /*get exp and frac first and then judge*/
  int sign, exp, frac;
  
  sign = (uf >> 31) & 1;
  exp = (uf >> 23) & 0xff;
  frac = uf & ((0x7f << 16) + (0xff << 8) + 0xff);

  if (!((exp + 1) & 0xff))	// exp == 0b11111111
    return uf;

  if (!exp) {			// exp == 0b00000000
    frac = frac << 1;
  }
  else 
    exp = exp + 1;
  return (sign << 31) + (exp << 23) + frac;
}








