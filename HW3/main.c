/*Furkan Taşkın 200104004072*/
#include <stdio.h>
#include <math.h>


int sum (int n1, int n2, int flag);
int multi (int n1, int n2, int flag);
int isprime (int a);
void write_file (int number);
void print_file ();
void sort_file ();
int find_digit(int inp_number);
int count_numbers();
void find_min();
void find_and_replace_space(int min1,int min2,int min3);
void copy_temp_to_results();
int check_sign(int number1,int number2);


int main()
 {

   int select,flag,N;
   int operator,n1,n2,ret_val,sign=0;

   printf("Select operation:\n");
   printf("1.Calculate sum/multiplication between two numbers\n");
   printf("2.Calculate prime numbers\n");
   printf("3.Show number sequence in file\n");
   printf("4.Sort number sequence in file\n");
   scanf("%d",&select);

   switch (select)
   {
     case 1:

          printf("Please enter '0' for sum, '1' for multiplication\n");
          scanf("%d",&operator);

          switch (operator)
         {
              case 0:
                printf("Please enter '0' to work on even numbers,'1' to work on odd numbers\n");
                scanf("%d",&flag);

                 switch (flag)
                 {
                    case 0:
                       printf("Number 1:");
                       scanf("%d",&n1);
                       printf("Number 2:");
                       scanf("%d",&n2);
                       sign=check_sign(n1,n2); /*checking for negativity*/
                       if (n1>=n2)
                          printf("First number must be less than second number.\n");

                       if(sign==1)
                         return 0;
                       else{
                         ret_val=sum(n1,n2,flag);
                         write_file(ret_val);/*writing to results.txt*/
                       }
                       break;

                    case 1:
                       printf("Number 1:");
                       scanf("%d",&n1);
                       printf("Number 2:");
                       scanf("%d",&n2);
                       sign=check_sign(n1,n2);
                       if (n1>=n2)
                          printf("First number must be less than second number.\n");


                       if(sign==1)
                         return 0;
                       else{
                       ret_val=sum(n1,n2,flag);
                       write_file(ret_val);
                       }
                       break;
                 }

            break;

            case 1:
              printf("Please enter '0' to work on even numbers,'1' to work on odd numbers\n");
              scanf("%d",&flag);

              switch (flag)
              {
                 case 0:
                    printf("Number 1:");
                    scanf("%d",&n1);
                    printf("Number 2:");
                    scanf("%d",&n2);
                    sign=check_sign(n1,n2);
                    if (n1>=n2)
                       printf("First number must be less than second number.\n");


                    if( sign==1)
                      return 0;
                    else{
                    ret_val=multi(n1,n2,flag);
                    write_file(ret_val);
                    }
                    break;

                 case 1:
                    printf("Number 1:");
                    scanf("%d",&n1);
                    printf("Number 2:");
                    scanf("%d",&n2);
                    sign=check_sign(n1,n2);
                    if (n1>=n2)
                       printf("First number must be less than second number.\n");


                    if( sign==1)
                      return 0;
                    else{
                    ret_val=multi(n1,n2,flag);
                    write_file(ret_val);
                    }
                    break;
              }
              break;
          }
break;


   case 2: ;
      int result,i;
      printf("Please enter an integer:");
      scanf("%d",&N);
      if (N<0 || N==0 || N==1)/*checking boundary conditions*/
      {
         printf("Please enter a valid number\n");
         return 0;
      }

      for (i = 2 ; i < N; ++i) /*checking primality until N*/
      {
         // flag will be equal to 1 if i is prime
        result = isprime(i);

        if (result == 1)
          printf("%d is prime number.\n", i);
        else
          printf("%d is not a prime number,it is divisible by %d\n",i,result);
      }


   break;


   case 3:
      print_file();
      break;

   case 4:
      sort_file();
      break;

 }

  return 0;
}
  /*checks negativity and boundary conditions*/
  int check_sign(int number1,int number2)
  {
      if(number1<0 || number1==0 || number2<0 || number2==0)
      {
         printf("Please enter positive numbers\n");
         return 1;
      }
      else
        return 0;

  }


   int sum (int n1, int n2, int flag)
   {
     int sum=0;
     if (flag==0)/*getting the flag for decide work on odd or even numbers*/
     {
        for (n1+1; n1 < n2 ; n1++)/*first number to second number*/
        {
           if (n1%2==0)  /*if number is even */
           {
             sum=sum+n1; /*add*/
             if(n1==(n2-1) || n1==(n2-2)) /*1 or 2 space before the end*/
                printf("%d = ",n1); /*if so print equality sign*/
             else
                printf("%d + ",n1); /*else do it in normal way*/
            }
        }
        printf("%d\n",sum);  /*print the result*/
     }

     else if(flag==1)
     {
       for (n1+1; n1 < n2 ; n1++)
       {
          if(n1%2!=0)/*if number is odd*/
          {
             sum=sum + n1;
             if(n1==(n2-1) || n1==(n2-2))
                printf("%d = ",n1);
             else
                printf("%d + ",n1);
          }
       }
       printf("%d\n",sum);
     }

     return sum;
   }



   int multi (int n1, int n2, int flag)
   {
     int mul=1;
     if (flag==0)/*getting the flag for decide work on odd or even numbers*/
     {
       for (n1+1; n1 < n2 ; n1++)
       {
          if (n1%2==0)/*if number is even*/
          {
            mul=mul*n1; /*multiply*/
            if(n1==(n2-1) || n1==(n2-2))
               printf("%d = ",n1);
            else
               printf("%d * ",n1);
           }
       }
       printf("%d\n",mul);
     }

     else if(flag==1)
     {
       for (n1+1; n1 < n2 ; n1++)
       {
          if(n1%2!=0)
          {
             mul=mul * n1;
             if(n1==(n2-1) || n1==(n2-2))
                printf("%d = ",n1);
             else
                printf("%d * ",n1);
          }
       }
       printf("%d\n",mul);
     }

return mul;
   }


int isprime (int a)
{
      int b=sqrt(a);/*taking square root according to formula*/
      int j,lcd,flag_prime = 1;

      for (j = 2; j <= b ; ++j) /*loop 2 to until b*/
      {
         if (a % j == 0) /*checks divisibility for least common divisor*/
         {
            lcd=j;  /*if so index is lcd*/
            flag_prime = 0; /*change flag*/
            return lcd;
            break;
         }

      }

      return flag_prime;

 }


 void write_file (int number)
 {
   FILE *fp;
   fp = fopen("results.txt", "w");
   fprintf(fp, "%d ", number);
   fclose(fp);

 }


 void print_file ()
 {
   int number;
   FILE *fp;
   fp = fopen("results.txt", "r+");
   printf("Result:\n");
   while (fscanf(fp, "%d", &number) == 1)
   {
       printf("%d ",number);

   }
  fclose(fp);
 }

 void sort_file ()
{
  FILE *temp;
  temp=fopen("temp.txt","r+");

   int counter=0,min1,min2,min3,j,dig_min1,dig_min2,dig_min3,sum_of_digits;
   counter=count_numbers();/*counting how many numbers in the results.txt*/
   /*we took numbers three by three so loop works counter/3 */
   for ( j = 1; j <= counter/3; j++)
   {

       find_min(); /*this function finds minumum three number and write temp.txt*/

       fscanf(temp,"%d%d%d",&min1,&min2,&min3);/*getting 3 minunum numbers*/

       /*finding number of digits and summing*/
       dig_min1=find_digit(min1);
       dig_min2=find_digit(min2);
       dig_min3=find_digit(min3);
       sum_of_digits=dig_min1+dig_min2+dig_min3;

       /*setting cursor for next read. It goes number of digits and plus three because we have spaces
        finally multiply by how many times file read*/
       fseek(temp,(sum_of_digits+3)*j,SEEK_SET);

       find_and_replace_space(min1,min2,min3);
   }
   /*copying final results to results txt and print it*/
   copy_temp_to_results();
   print_file();

fclose(temp);
}


  int find_digit(int inp_number)/*simple digit number finding*/
 {
     int counter=0;

     while (inp_number!=0)
     {
        inp_number/=10; /*divide by three until reach 0*/
        counter++;
     }

     return counter;
 }

 int count_numbers(){/*counting numbers int the file for running loop*/
    FILE *fp;
    fp=fopen("results.txt","r");
    int number,count_number=0;

     while (fscanf(fp, "%d", &number) == 1)
     {
         count_number++;
     }
     return count_number;

fclose(fp);
}

/*IT ONLY WORK IF THERE IS 3 Multiples of 3 and 3*/
void find_min()
{
   int min1=2147483647,min2=2147483647,min3=2147483647;/*an integer can take this number at most*/
   int number,counter=0,int_max=2147483647;

  FILE *fp;
  fp = fopen("results.txt", "r+");
  FILE *temp;
  temp = fopen("temp.txt", "a+");

  while(fscanf(fp, "%d", &number) == 1)
  {
     /*Transferring numbers to each other*/
     if(number<min1)
     {
        min3=min2;
        min2=min1;
        min1=number;
     }
     else if (number < min2 )
     {
        min3=min2;
        min2=number;
     }
     else if (number < min3)
     {
        min3=number;
     }
   }

fprintf(temp, "%d %d %d ", min1,min2,min3);

  fclose(fp);
  fclose(temp);
}


void find_and_replace_space(int min1,int min2,int min3)
{
  int number2,cursor1,cursor2,cursor3,dig_min1,dig_min2,dig_min3,i;
  FILE *fp2;
  fp2=fopen("results.txt", "r+");

  while(fscanf(fp2, "%d", &number2) == 1 )/*reading file*/
  {
     if (number2==min1)
     {
        cursor1=ftell(fp2); /*finding the cursor's position*/
     }
     if (number2==min2)
     {
        cursor2=ftell(fp2);
     }
     if (number2==min3)
     {
        cursor3=ftell(fp2);
     }
  }
  /*finding how many digit mininum number have*/
  dig_min1=find_digit(min1);
  dig_min2=find_digit(min2);
  dig_min3=find_digit(min3);


  /*setting cursor. It sets it by going back
   as much as the number of digits just before the min numbers.*/
  fseek(fp2,cursor1-dig_min1,SEEK_SET);
  for ( i = 0; i < dig_min1; i++)
  {
   fprintf(fp2, " ");/*and print space on it(overwrite)*/
  }

  fseek(fp2,cursor2-dig_min2,SEEK_SET);
  for ( i = 0; i < dig_min2; i++)
  {
   fprintf(fp2, " ");
  }

  fseek(fp2,cursor3-dig_min3,SEEK_SET);
  for ( i = 0; i < dig_min3; i++)
  {
    fprintf(fp2, " ");
  }

  fclose(fp2);

}

void copy_temp_to_results()
{
  int number;
  FILE *temp,*fp;
  temp=fopen("temp.txt","a+");
  fp=fopen("results.txt","w+");


  while(fscanf(temp,"%d",&number)==1)
  {
      fprintf(fp, "%d ",number);
  }

  fclose(temp);
  fclose(fp);
  remove("temp.txt");
}
