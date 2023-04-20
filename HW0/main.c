/* This program does arithmetic operations on fractional numbers */
/* Furkan Taşkın 200104004072*/

#include <stdio.h>
#include "util.h"


int main() {

    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A fractional number: 13/7 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;

    /*Getting 2 numbers from user and print them with help of function*/
    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    /*This code block is making operations by calling functions from util.h and printing the results*/
    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n\n");


      int nume1,denum1,nume2,denum2,nume3,denum3; /* Variables for numerator and denominator*/

      /*Getting numbers one by one from user */
      printf("Please enter the numerator of 1st number:");
      scanf("%d",&nume1);
      printf("Please enter the denominator of 1st number:");
      scanf("%d",&denum1 );
      printf("Please enter the numerator of 2nd number:");
      scanf("%d",&nume2);
      printf("Please enter the denominator of 2nd number:");
      scanf("%d",&denum2);
      printf("\n");

      /*In the following, making operations on numbers that got from user and print them*/
      fraction_add(nume1,denum1,nume2,denum2,&nume3,&denum3);
      printf("Addition= ");
      fraction_print(nume3,denum3);
      printf("\n");

      fraction_sub(nume1,denum1,nume2,denum2,&nume3,&denum3);
      printf("Substraction= ");
      fraction_print(nume3,denum3);
      printf("\n");

      fraction_mul(nume1, denum1, nume2, denum2, &nume3, &denum3);
      printf("Multiplication= ");
      fraction_print(nume3, denum3);
      printf("\n");

      fraction_div(nume1, denum1, nume2, denum2, &nume3, &denum3);
      printf("Division= ");
      fraction_print(nume3, denum3);
      printf("\n");

    return(0);
}
