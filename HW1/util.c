/*Furkan Taşkın 200104004072*/

#include "stdio.h"
#include "util.h"

int find_divisible(int x, int y, int z){
int i;

   if (x<y)  /*determining is it computable or not*/
   {
      for (i = x; i < y; i++) /*starting from bottom and ending in upper limit*/
      {
        if(i%z==0)  /*checking if numbers between in that range is divisible or not*/
        {
          printf("The first integer between %d and %d divided by %d is %d.",x,y,z,i); /*if so,print*/
          break;  /*for printing only one time*/
        }
      }
   }
   return i;  /*return value of the function is first number that can divisible by z*/
}

int find_nth_divisible(int n, int f_I, int z){
     int a;
     f_I=f_I+n*z;   /* adding next value multiplied by divisor*/
     a=f_I;
     return a;
}

int validate_identity_number(char identity_number[])
{
   int lenght=0,i,result=0,eleventh=0,j,integer_array[11],ret_val=-33;

   for (i=0; i<11; i++)
   {
     if(identity_number[i]!='\0') /*searching for last value on the array*/
      lenght++;  /*incrementing the lenght every time when null value not found*/
   }

   for (int i = 0; i < 11; i++){
     integer_array[i] = identity_number[i]-'0';  /*converting char array to int array by decrementing zero's ascii number*/
  }

  /*formula for calculating 10th digit of the identity number*/
  result=((integer_array[0]+integer_array[2]+integer_array[4]+integer_array[6]+integer_array[8])*7)-(integer_array[1]+integer_array[3]+integer_array[5]+integer_array[7]);
  result=result%10;

  for ( j = 0; j <10; j++)
  {
    eleventh=eleventh+integer_array[j]; /*adding first 10 digit to obtain 11th digit */
  }
  eleventh=eleventh%10; /*according to formula of identity number*/

    if(lenght!=11 )   /*checking lenght*/
      printf("         Invalid identity number!\n");
    else if(*integer_array>='0' && *integer_array<='9')  /*checking if it is digit or not*/
      printf("         Invalid identity number!\n");
    else if(identity_number[0]=='0')                     /*identity number's first digit can not be zero*/
      printf("         Invalid identity number!\n");
    else if(integer_array[9]!=result)                    /*checking 10th digit */
      printf("         Invalid identity number!\n");
    else  if(integer_array[10]!=eleventh)               /*checking 11th digit */
      printf("         Invalid identity number!\n");
    else
     return ret_val;  /*returning a value for checking all contitions are met*/
}

int create_customer(char identity_number[], int password){

FILE * fp;
fp=fopen("customeraccount.txt","w");  /*opening the file for database purpose*/

  if(password<1000 || password>9999){ /*password needs to be 4 digit*/
    return -34;
  }
  else{
   fprintf(fp,"%s,%d",identity_number,password);  /*printing id and password to file*/
   printf("         Account is created.\n" );
  }

fclose(fp);
}

int check_login(char identity_number[],int password){  /*function for checking id and password is right or not*/
  int i,password2,d,password3;
  char identity_number3[12];
  FILE * fp;
  fp=fopen("customeraccount.txt","r");


  fgets(identity_number3,12,fp);  /*getting data from file for comparing */
  fscanf(fp,"%d",&password3);

  for (i=0; i<11; i++) {
    if(identity_number3[i]==identity_number[i] && password2==password3)
      { /*comparing two data*/
        printf("\n         Successful login\n");
        break;
        }
      else
      {
        printf("\n         Try again\n");
        return -35;
        break;
      }

  }
  fclose(fp);
}

int withdrawable_amount(float cash_amount){

int division,withdrawable;

  division=cash_amount/10;  /*divide by 10,it is stored in int */
  withdrawable=division*10; /*divide by 10*/
  printf("         Withdrawable amount is:%d\n",withdrawable);

}
