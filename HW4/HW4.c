/*Furkan Taşkın 200104004072 CSE102 Homework 4*/

#include <stdio.h>

int convert_neg(int a);

int main()
{

  int select,a,b,c,flag=0,number,x,y,temp;

  FILE *fp,*graph;
  fp=fopen("coefficients.txt","a+"); /*opening the file for reading and writing*/

  if (fp==NULL)
  {
    printf("File couldn't opened\n");
    return 0;
  }

  while (select!=3 && flag!=1) /*indicating that loop where to end*/
  {
      /*Menu for selecting which operation should perform*/
      printf("\nSelect an operation...\n");
      printf("0 -> Enter the coefficients.\n");
      printf("1 -> Draw the graph.\n");
      printf("2 -> Print the graph into a .txt file.\n");
      printf("3 -> Exit\n\n");
      printf("Choice: ");
      scanf("%d",&select);

      switch (select)
      {
        case 0:
           /*Getting coefficients from user according to the formula*/
           printf("Please enter the coefficient for the following equation x=a*(y*y) + b*y +c\n");
           printf("a: ");
           scanf("%d",&a);
           printf("b: ");
           scanf("%d",&b);
           printf("c: ");
           scanf("%d",&c);

           /*writing coefficients into a file*/
           fprintf(fp, "%d\n",a);
           fprintf(fp, "%d\n",b);
           fprintf(fp, "%d\n",c);

           printf("coefficients.txt file has been created\n");
        break;



        case 1:

           while (!feof(fp))/*reading coefficients until end of the file*/
           {
              fscanf(fp,"%d %d %d",&a,&b,&c);
           }

           printf("Coefficients has been read from coefficients.txt file.\n");
           printf("Printing the graph of x = %d*(y*y) + %d*y + %d\n",a,b,c);

          for ( y = 16; y >= -15; y--) /*Y axis. Starting from 16 and decreasing*/
          {
             for (x = -55; x <= 56; x++) /*X axis. Starting from -55 and increasing*/
              {
                if (x== (a*(y*y) +b*y +c) ) /*checking the formula fits or not*/
                {
                  printf("\033[0;31m#\033[0m"); /*if so print hashtag with red color*/
                  x=x+1;  /*since i wrote a character add one to it*/
                }
                else
                {
                 if (x==-3)/*just 3 before the y-axis */
                 {

                    if (convert_neg(y)%5==0) /*first checking negativity and converting to positive then take modula of 5 because y axis increases by five*/
                    {
                        if ((y>=10 && y<=15) || (y>=-9 && y<=-1)) /*similar conditions becasue both has 2 characters */
                        {
                            printf("\033[0;32m%d\033[0m",y); /*print the y coordinate */
                            x=x+2; /*increment by two because 2 character written*/
                        }
                        else if (y>=1 && y<=9)/*checking another interval*/
                        {
                           printf("\033[0;32m%d\033[0m",y);
                           x=x+1;
                        }

                        else if (y>=-15 && y<=-10)
                        {
                           printf("\033[0;32m%d\033[0m",y);
                           x=x+3;  /*3 characters wrote*/
                        }
                    }
                }

               if (y==-1)/*for writing x values like -50,-40 vs just 1 under x axis*/
                    {
                       if (convert_neg(x)%10==0)/*taking modula by 10 because c axis incrementing by 10*/
                       {
                        /*same process going on for x axis just like y axis */
                          if (x>=-50 && x<=-10)
                          {
                             printf("\033[0;32m%d\033[0m",x);
                             x=x+3;
                          }
                          else if (x>=-9 && x<=-1)
                          {
                             printf("\033[0;32m%d\033[0m",x);
                              x=x+2;
                          }
                          else if ((x>=1 && x<=9) || (x>=10 && x<=55))
                          {
                             printf("\033[0;32m%d\033[0m",x);
                             x=x+1;
                          }
                       }
                       if (x==-2)/*special condition for 0*/
                       {
                          printf("\033[0;32m0\033[0m");
                          x=x+1;
                       }
                    }

                 }
                 if (x==0)/*printing y axis*/
                 {
                    if (y==16)
                      printf("^");
                    else
                      printf("|");
                  }
                 else if (y==0)/*printng x axis*/
                 {
                    if (x==56)
                       printf(">");
                    else
                       printf("-");
                  }
                 else
                    printf(" ");/*if nothing holds print space*/

              }
              printf("\n");/*new line for when row finished to switch to a new line*/
            }

        break;


      case 2:

        graph=fopen("graph.txt","w");/*opening the file*/
        if (graph==NULL)
        {
          printf("File couldn't opened\n");
          return 0;
        }

        while (!feof(fp)) /*reading coefficients*/
        {
           fscanf(fp,"%d %d %d",&a,&b,&c);
        }

        /*same process is going on without numbers and color*/
        for ( y = 15; y >= -15; y--)
        {
           for (x = -55; x <= 55; x++)
            {
              if (x== (a*(y*y) +b*y +c) )
              {
                fprintf(graph,"#");
                x=x+1;
              }

               if (x==0)
                  fprintf(graph,"|");
               else if (y==0)
                  fprintf(graph,"-");
               else
                  fprintf(graph," ");

            }
            fprintf(graph,"\n");
          }

          printf("Coefficients has been read from coefficients.txt file.\n");
          printf("The graph of x = %d*(y*y) + %d*y + %d has been written to the graph.txt file\n",a,b,c);

        fclose(graph);
        break;

        case 3:
          flag=1;
        break;

        default:
         printf("Please enter valid input\n");
         break;
      }
  }

fclose(fp);
return 0;
}

int convert_neg(int a)/*function for converting negatif*/
{
   if (a<0) /*if number is negatif*/
   {
       a=a*(-1); /*multiply by -1 to find positive*/
   }
  return a;
}
