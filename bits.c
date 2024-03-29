/* 
 * CS:APP Data Lab 
 * 
 * <Hüseyin Burak Baysal - hbaysal16>
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
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
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
   <https://www.gnu.org/licenses/>.  */
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
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	/* performs bitwise ^(xor) operator using only bitwise &(and) and bitwise ~(not) operators.*/
	int a = x&y;
	int b = ~x & ~y;
  	return ~a & ~b;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
	/* swaps the specified 2 bytes of given integer.*/
	int f;
	n = n<<3;
	m = m<<3;
	f = (x>>n&0xff) ^ (x>>m&0xff);
	x = ((f<<n) | (f<<m)) ^ x;
	return x;
}
/* 
 * isLowerCaseLetter - return 1 if 0x61 <= x <= 0x7A (ASCII codes for characters 'a' to 'z')
 *   Example: isLowerCaseLetter(0x65) = 1.
 *            isLowerCaseLetter(0x60) = 0.
 *            isLowerCaseLetter(0x81) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isLowerCaseLetter(int x) {
	/* Checks whether given char in ASCII code is lowercase or not.*/
	int a = (x >> 5) ^ 0x3; 		/* checks if given number greater than or equal to 0x60, if so return 0*/
	int b = ((0x1f & x) + 0x5) & 0xe0; 	/* checks whether given number less than or equal to 0x7a, if so return 0*/
	int c = !(x ^ 0x60); 			/* checks whether given number is 0x60, if not return 0*/
	return !(a|b|c); 			/* if all conditions above are satisfied, return 1*/
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
	/* Counts the number of 1's in binary representation of an integer.*/
	int a = 1 | (1<<8) | (1<<16) | (1<<24); //00000001000000010000000100000001
	int b = 0x0F; //000000000000000000000000000001111
	int c = (x&a) + ((x>>1)&a) + ((x>>2)&a) + ((x>>3)&a) + ((x>>4)&a) + ((x>>5)&a) + ((x>>6)&a) + ((x>>7)&a); // checks every byte of given number
	int d = (c&b) + ((c>>8)&b) + ((c>>16)&b) + ((c>>24)&b); // check 4-bit by 4-bit and summation is the result.
	return d;
}
/* 
 * divpwr4 - Compute x/(4^n), for 0 <= n <= 15
 *  Round toward zero
 *   Examples: divpwr4(15,1) = 3, divpwr4(-33,2) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 17
 *   Rating: 2
 */
int divpwr4(int x, int n) {
	/* Computes the x/(4^n) equation using bit shifting. Results rounded towards 0 */
	int s = x>>31; // Check whether x is negative or positive
	int c = (((s&1)<<n)<<n)+s; // If negative c returns 
	x += c;
	x = (x>>n)>>n; // Divide by 4^n
	return x;
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {
	/* Takes an input x and multiplies it by 3/4 using binary operators.*/
	int c;
	x += (x<<1); // Multiplication by 3.
	c = (x>>31)&3; // Check whether x is negative or positive.
	x = (x+c)>>2; // Division by 4.
	return x;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
	/* Calculates the minimum required number of bits to represent x in 2's complement.*/
	int s16, s8, s4, s2, s1, s0;
	int i = x>>31;
	x = (i&~x) | (~i&x); // There is no difference between negative or positive number thus avoid negativity in x.
	/* Search and find bit by bit the most significant bit. */
	s16 = !!(x>>16)<<4;
	x = x>>s16;
	s8 = !!(x>>8)<<3;
	x = x>>s8;
	s4 = !!(x>>4)<<2;
	x = x>>s4;
	s2 = !!(x>>2)<<1;
	x = x>>s2;
	s1 = !!(x>>1);
	x = x>>s1;
	s0 = x;
	return s16+s8+s4+s2+s1+s0+1;
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
	/* Return the negative equilavent bit-level representation of given float.*/
	/* If (uf=NaN) return uf.*/
	unsigned e = uf & 0x7fffffff;
	if(e >= 0x7f800001){
		return uf;
	}
	else
		return uf ^ (1<<31); /* Change the first bit of the number. */

}


/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
	unsigned s = uf & 0x80000000;
	unsigned e = uf & 0x7F800000;
	unsigned l = (uf&3) == 3;
	if(e == 0x7F800000){
		return uf;
	}
	else if(e<=0x00800000) {
		return s|(((uf^s)+l)>>1); 
	}
	else{
		return uf-0x00800000;
	}
}
