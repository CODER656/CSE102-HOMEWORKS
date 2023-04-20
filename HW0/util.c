/*This file has the functions themselves. Neccessary arithmetic operations are done here*/
#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
   printf("%d//%d", numerator, denominator); /*printing the fractional numbers using numerator and denominator values*/
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;     /* calculating numerator according to basic arithmetic on fractional number adding(multiply the other denominator and numerator then add)*/
    *d3 = d1*d2;             /* just multiply denominators for equalization */
    fraction_simplify(n3, d3);  /* calling the simplify function*/
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;     /* calculating numerator according to basic arithmetic on fractional number adding(multiply the other denominator and numerator then substract)*/
    *d3 = d1*d2;             /* just multiply denominators for equalization */
  fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*n2;          /* just multiply numerators*/
    *d3 = d1*d2;          /* just multiply denominators*/
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2;         /*turn down the second number then multiply(rule)*/
    *d3 = n2*d1;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {

  int remainder,gcd,temp1,temp2;
  temp1=(*d); /* assigning value to temporary variable for storing original value*/
  temp2=(*n); /* assigning value to temporary variable for storing original value*/

     /* Gcd algorithm stands on taking modula continually*/
     while((*n)!= 0 && (*d)!=0 )  /*making sure of numbers won't go down zero*/
     {
       remainder = (*n)%(*d);     /* finding the remainder from division of two numbers*/
       (*n) = (*d);               /* swapping*/
       (*d) = remainder;          /*remainder value assigned on second number so in next iteration will be taking second number's modula with remainder*/
       gcd=(*n);                  /*gcd is now first number */
     }
    /*divide numbers with greatest common divisor for simplification*/
      *n=temp2/gcd;
      *d=temp1/gcd;
} /* end fraction_div */
