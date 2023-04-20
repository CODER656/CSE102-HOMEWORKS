/*Furkan TAŞKIN 200104004072 Homework 1*/

#include "stdio.h"
#include "util.h"

int main() {

 char identity_number[11],identity_number2[12];
 int password,x,y,z,n,f_I,a,b,c,d,password2;
 float cash_amount;

 /*getting values from user*/
 printf("\nEnter the first integer:");
 scanf("%d",&x);
 printf("Enter the second integer:");
 scanf("%d",&y);
 printf("Enter the divisor:");
 scanf("%d",&z);

 if(x>y) /*checking eligibility status*/
 {
   printf("There is not any integer between X and Y can be divided by Z\n"); /*printing error message*/
   return -1;
 }

 f_I=find_divisible(x,y,z);

 printf("\nEnter the number how many next:"); /*getting a number for how many next number will be displayed*/
 scanf("%d",&n);

 a=find_nth_divisible(n,f_I,z);
 if (a>y)  /*checking boundary condition*/
 {
   printf("No possible to find %dth divisible between %d and %d divided by %d\n",n+1,x,y,z);
   return -999;
 }
 else
   printf("The %d. integer between %d and %d divided by %d is %d\n",n+1,x,y,z,a);

  /*getting id and password for creating an account*/
  printf("\n         Hi there! Let's create an account for you.\n");
  printf("         Please enter your identity number:");
  scanf("%s",identity_number);


  a=validate_identity_number(identity_number); /*checking identity number true or not*/
  if(a!=-33)
    return 0;

  printf("         Please enter your password:");
  scanf("%d",&password);

  b=create_customer(identity_number,password);/*checking password true or not*/
   if (b==-34) {
     printf("         Invalid password!\n");
     return 0;
  }

  printf("\n         You need to log in now.\n\n");
  printf("         Please enter your identity number:");
  scanf("%s",identity_number2);


  d=validate_identity_number(identity_number2); /*checking identity number true or not*/
  if(d!=-33)
    return 0;

  printf("         Please enter your password:");
  scanf("%d",&password2);
  c=check_login(identity_number2,password2);
  if (c==-35)
    return 0;


  printf("         Please enter your withdraw amount:");
  scanf("%f",&cash_amount);

  /* calling the function for calculate how much money is withdrawable*/
  withdrawable_amount(cash_amount);
  return 0;
}
