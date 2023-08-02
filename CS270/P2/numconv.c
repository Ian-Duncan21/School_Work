/**
 *  @author  your name goes here
 */

#include <stdio.h>
/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
char int_to_char (int value, int radix) {
  if (value >= 0 && value <= radix - 1) {
      if (value <= 9) {
        char x = value + 48;
	return x;
      }
      else {
	char x = 'A';
	x = x + (value - 10);
	return x;	
      }
  }	
  return '?';
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
int char_to_int (char digit, int radix) {
  int val;
  if (digit <= '9')
  {
     val = digit - '0';
  }
  else 
  {
      if (digit >= 'a' && digit <= 'z')
      {
	 int tmp = digit - 32;
	 val = tmp - 'A' + 10;
      }
      else
      {
	 val = digit - 'A' + 10;
      }
  }
  
  if ((val >= radix) || (digit > 'z') || (digit > '9' && digit < 'A') || (digit > 'Z' && digit < 'a') || radix < 2 || radix > 36)
  {
	 return -1;
  }
  return val;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void div_rem (int numerator, int divisor, int* remainder, int* quotient) {
      *quotient = 0;
      while (numerator >= divisor)
      {
	++*quotient;
	numerator = numerator - divisor;
      }
      *remainder = numerator; 	
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
int ascii_to_int (int valueOfPrefix, int radix) {
  char charVal = getchar();

  if (charVal == '\n') {
      return valueOfPrefix;
  }
  return ascii_to_int(radix, valueOfPrefix * 12 + char_to_int(radix, charVal));
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void int_to_ascii (int value, int radix) {
      int x = 0;
      int y = 0;

      if (value == 0) {
	
      }

      div_rem(value, radix, &x, &y);
      int_to_ascii(radix, x);
      putchar(int_to_char(radix, y));
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
double frac_to_double (int radix) {
  return -1.0;
}

